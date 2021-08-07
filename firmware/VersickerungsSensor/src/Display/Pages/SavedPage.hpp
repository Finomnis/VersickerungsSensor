#pragma once

#include "PageElement.hpp"

#include "Elements/Header.hpp"

namespace Pages
{
    class SavedPage : public PageElement
    {
    public:
        SavedPage();

    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;

    private:
        Elements::Header header;
    };
}
