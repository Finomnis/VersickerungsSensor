#include "PageElement.hpp"

namespace Pages
{
    void PageElement::redraw_if_necessary(Adafruit_SSD1306 &display)
    {
        if (recursive_check_dependencies_changed())
        {
            redraw(display);
        }
    }

    void PageElement::redraw(Adafruit_SSD1306 &display)
    {
        display.clearDisplay();
        recursive_render(display);
        display.display();
    }

    void PageElement::execute_activate_handlers(Adafruit_SSD1306 &display)
    {
        recursive_on_activate(display);
    }

    bool PageElement::recursive_check_dependencies_changed()
    {
        bool self_invalid = check_dependencies_changed();
        bool siblings_invalid = false;
        bool children_invalid = false;

        if (next_sibling != nullptr)
        {
            siblings_invalid = next_sibling->recursive_check_dependencies_changed();
        }

        if (first_child != nullptr)
        {
            children_invalid = first_child->recursive_check_dependencies_changed();
        }

        return self_invalid || siblings_invalid || children_invalid;
    }

    void PageElement::recursive_render(Adafruit_SSD1306 &display)
    {
        render(display);

        if (first_child != nullptr)
        {
            first_child->recursive_render(display);
        }

        if (next_sibling != nullptr)
        {
            next_sibling->recursive_render(display);
        }
    }

    void PageElement::recursive_on_activate(Adafruit_SSD1306 &display)
    {
        on_activate(display);

        if (first_child != nullptr)
        {
            first_child->recursive_on_activate(display);
        }

        if (next_sibling != nullptr)
        {
            next_sibling->recursive_on_activate(display);
        }
    }

    void PageElement::add_child(PageElement &child)
    {
        child.next_sibling = first_child;
        first_child = &child;
    }
}
