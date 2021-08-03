#include "PageElement.hpp"

namespace Pages
{
    void PageElement::redraw_if_necessary(Adafruit_SSD1306 &display)
    {
        if (recursive_check_dependencies())
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

    bool PageElement::recursive_check_dependencies()
    {
        bool self_invalid = check_dependencies();
        bool siblings_invalid = false;
        bool children_invalid = false;

        if (next_sibling != nullptr)
        {
            siblings_invalid = next_sibling->recursive_check_dependencies();
        }

        if (first_child != nullptr)
        {
            children_invalid = first_child->recursive_check_dependencies();
        }

        return self_invalid || siblings_invalid || children_invalid;
    }

    void PageElement::recursive_render(Adafruit_SSD1306 &display)
    {
        if (first_child != nullptr)
        {
            first_child->recursive_render(display);
        }

        if (next_sibling != nullptr)
        {
            next_sibling->recursive_render(display);
        }

        render(display);
    }
}
