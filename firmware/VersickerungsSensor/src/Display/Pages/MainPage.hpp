#pragma once

#include "PageElement.hpp"

#include "Elements/Header.hpp"
#include "Elements/Mixins/FilteredDistanceMixin.hpp"

namespace Pages
{
    class MainPage : public PageElement,
                     private Elements::Mixins::FilteredDistanceMixin
    {
    public:
        MainPage(bool recording);

    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;

    private:
        Elements::Header header;
    };
}
