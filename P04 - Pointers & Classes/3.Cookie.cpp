#include <iostream>

class Cookie {
private:
    std::string color;

public:
    Cookie(std::string clr) {
        this->color = clr;
    }

    std::string get_color() {
        return color;
    }

    void set_color(std::string color) {
        this->color = color;
    }
};

void perkalian(int a) {
    for (int i = 0; i < a; i++) {
        std::cout << i * a << std::endl;
    }
}

int main() {
    std::cout << std::endl;

    Cookie *cookie1 = new Cookie("Green");
    Cookie *cookie2 = new Cookie("Blue");

    cookie1->set_color("Yellow");

    std::cout << "C1: " << cookie1->get_color() << std::endl;
    std::cout << "C2: " << cookie2->get_color() << std::endl;

    for (int i = 0; i < 100; i++) {
        std::cout << i << std::endl;
    }

    perkalian(5);

    

    std::cout << std::endl;
    return 0;
}
