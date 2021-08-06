#pragma once

#include "PageElement.hpp"

#include "Elements/Header.hpp"

namespace Pages
{
    class MainPage : public PageElement
    {
    public:
        MainPage(bool recording);

    protected:
        bool check_dependencies_changed() override { return false; };
        void render(Adafruit_SSD1306 &display) override{};

    private:
        Elements::Header header;
    };
}
