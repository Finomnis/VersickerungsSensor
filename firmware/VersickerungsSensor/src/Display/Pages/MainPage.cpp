#include "MainPage.hpp"

namespace Pages
{
    MainPage::MainPage(bool recording)
        : header{recording}
    {
        add_child(header);
    }
}
