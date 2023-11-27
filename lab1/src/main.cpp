#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#define pi 3.1415926536

using namespace sf; 


void draw_line(int x1, int y1, int x2, int y2, RenderWindow& window) {
    Vertex line[] = {
        Vertex(Vector2f(x1, y1)),
        Vertex(Vector2f(x2, y2))
    };

    window.draw(line, 2, Lines);
}

void square(int n, int x0, int y0, int a, double f, double delta, RenderWindow& window) {
    if (n == 0) { 
        return; 
    }

    double alp = int(a * cos(delta));
    double bet = int(a * sin(delta));
    
    int x1, x2, x3, y1, y2, y3;
    

    x1 = (int)(x0 + a * cos(f));      y1 = (int)(y0 - a * sin(f));
    x2 = (int)(x1 - a * sin(f));      y2 = (int)(y1 - a * cos(f));
    x3 = (int)(x0 - a * sin(f));      y3 = (int)(y0 - a * cos(f));

    int x4 = (int)(x3 + alp * cos(f + delta));  
    int y4 = (int)(y3 - alp * sin(f + delta));


    draw_line(x0, y0, x1, y1, window);
    draw_line(x1, y1, x2, y2, window);
    draw_line(x2, y2, x3, y3, window);
    draw_line(x3, y3, x0, y0, window);

    n--;
    square(n, x3, y3, alp, f + delta, delta, window);
    square(n, x4, y4, bet, f + delta - pi / 2, delta, window);
}


int main() {
    int depth;
    std::cout << "Depth: ";
    std::cin >> depth;

    RenderWindow window(VideoMode(1920, 1080), "Lab №1");
    int x0 = 860, y0 = 850, a = 200;
    double f = 0, delta = pi / 4;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(10, 10, 10, 0));

        square(depth, x0, y0, a, f, delta, window);

        window.display();
    }

    return 0;
}
