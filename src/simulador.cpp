#include <gtkmm/application.h>
#include <iostream>
#include <string>
#include "JanelaPrincipal.h"

using namespace std;
using namespace Gtk;

int main(int argc, char *argv[])
{

    auto app = Application::create(argc, argv, "org.gtkmm.example");

    JanelaPrincipal window;

    return app->run(window);
}
