#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include "string.h"
#include "JanelaPrincipal.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    JanelaPrincipal window;
    return app->run(window);
}
