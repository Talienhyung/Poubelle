#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 300), "Morpion");

    sf::RectangleShape grid[3][3]; // Crée une grille de 3x3 cases

    // Remplissez la grille avec des cases vides
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j].setSize(sf::Vector2f(100, 100)); // Taille d'une case
            grid[i][j].setOutlineThickness(2); // Épaisseur de la bordure
            grid[i][j].setOutlineColor(sf::Color::Black); // Couleur de la bordure
            grid[i][j].setPosition(i * 100, j * 100); // Position de la case
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Lorsque vous cliquez avec le bouton gauche de la souris
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Vérifiez quelle case a été cliquée
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (grid[i][j].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                                // Placez une croix dans la case si elle est vide
                                if (grid[i][j].getFillColor() == sf::Color::White) {
                                    grid[i][j].setFillColor(sf::Color::Red); // Couleur de la croix
                                }
                            }
                        }
                    }
                }
            }
        }

        window.clear();

        // Dessinez la grille et autres éléments ici
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                window.draw(grid[i][j]);
            }
        }

        window.display();
    }

    return 0;
}

