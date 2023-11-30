#include <gtkmm.h>
#include <iostream>
// Sendo compilado por MINGW64 pela linha de comando g++ Main.cpp $(pkg-config gtkmm-3.0 --cflags --libs)

Gtk::Window *pWindow;
Gtk::Entry *num1, *num2, *result;
Gtk::Button *btn_soma;

void on_btn_soma_clicked(){
    std::string a = num1->get_text();
    std::string b = num2->get_text();

    int x = std::stoi(a);
    int y = std::stoi(b);

    result->set_text(std::to_string(x + y));
}

int main(int argc, char** argv){
    Gtk::Main create(argc, argv, "org.gtkmm.example");  
    auto refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file("soma.glade");
    refBuilder->get_widget("window", pWindow);

    if(pWindow){
        refBuilder->get_widget("num1", num1);
        refBuilder->get_widget("num2", num2);
        refBuilder->get_widget("btn_soma", btn_soma);
        refBuilder->get_widget("result", result);
    }

    if(btn_soma){
        btn_soma->signal_clicked().connect(sigc::ptr_fun(on_btn_soma_clicked));
    }
    
    Gtk::Main::run(*pWindow);

    delete(pWindow);
    return 0;
}