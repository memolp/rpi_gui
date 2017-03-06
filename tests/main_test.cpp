#include "../include/navit.h"
#include "compositor.h"
#include "button.h"
#include "layout.h"
#include "label.h"
#include "scroll.h"
#include "slider.h"
#include "tab_widget.h"
#include "file_chooser.h"

int main(int argn, char** args)
{
    Widget* parent = COMPOSITOR->create_new_window();
    parent->backgroung_gradient_enable(true);

    Tab_widget* tab = new Tab_widget(100, 200, 300, 300, "tab", parent);
    Scroll* scroll = new Scroll(0, 0, 300, 500, "Radio tab", parent);

    Layout* layout = new Layout(0, 0, 350, 500, "Child", scroll, LAYOUT_VERTICAL);
    Slider* sld = new Slider(0, 0, 60, 60, "Slider", layout);
    Label* lbl = new Label(0, 0, 60, 60, "Label test", layout);
    Button* button = new Button(0, 0, 60, 40, "Button #1", layout);
    Button* button2 = new Button(0, 0, 60, 40, "Button #2", layout);
    Button* button3 = new Button(0, 0, 60, 40, "Button #3", layout);

    Navit* navit = new Navit(10,10,500, 400, "navit", parent);

    Label* lbl2 = new Label(0, 0, 100, 80, "MP3 & Music content", parent);
    lbl2->bg_color(FColor(0,0,.6,1.));

    button->image("icon-111-search.svg");
    button2->image("icon-111-search.svg");
    button3->image("icon-111-search.svg");
    layout->bg_color(FColor(.1, .2, .3, 1.0));
    scroll->bg_color(FColor(.8, .8, .8, 1.0));

    tab->add_tab(scroll);
    tab->add_tab(lbl2);

    File_chooser* fc = new File_chooser(0, 0, 300, 400, "", parent);
    tab->add_tab(fc);

    return COMPOSITOR->run();
}
