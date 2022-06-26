#include <array>
#include <cstdio>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum
{
    WIDHT = 300,
    HEIGHT = 300,
};
/*!
 * The class responsible for the operation of the game
 * It contains all the logic of the game
 * Drawing using SFML
 */

class Game
{
public:
    sf::RenderWindow *window;
    sf::ContextSettings settings;
    sf::Event event;
    std::array<sf::VertexArray, 4> grid;
    std::array<int, 9> game;
    bool state = false;




/*!
 * Window creation function
 */

    int initWindow()
    {

        settings.antialiasingLevel = 8;
        this->window = new sf::RenderWindow(sf::VideoMode(WIDHT, HEIGHT), "tic-tac-toe");
        this->window->setFramerateLimit(60);
        this->game = {6, 6, 6, 6, 6, 6, 6, 6, 6};
        this->grid = this->makeGrid();
        return 0;
    }
/*!
 * The function responsible for pressing the keys
 */
    int pollEvents()
    {

        sf::Vector2i position = sf::Mouse::getPosition(*(this->window));

        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab))
                this->window->close();
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab)){return true;}

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (position.x < 100)
                {

                    if (position.y < 100)
                    {
                        this->changeState(0);
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        this->changeState(3);
                    }
                    else
                    {
                        this->changeState(6);
                    }
                    return 1;
                }
                else if (position.x > 100 && position.x < 200)
                {

                    if (position.y < 100)
                    {
                        this->changeState(1);
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        this->changeState(4);
                    }
                    else
                    {
                        this->changeState(7);
                    }
                    return 2;
                }
                else if (position.x > 200)
                {

                    if (position.y < 100)
                    {
                        this->changeState(2);
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        this->changeState(5);
                    }
                    else
                    {
                        this->changeState(8);
                    }
                    return 3;
                }
            }
        }
    }
/*!
 * The function responsible for the state of the cell, either 0 or 1 (0 or X)
 */
    int changeState(int numberOfCell)
    {
        if (this->game[numberOfCell] == 0 || this->game[numberOfCell] == 1)
        {
            std::printf("the move was made in cell #");
            return 0;
        }

        else
        {
            if (this->state == false)
            {

                this->game[numberOfCell] = 0;
                this->state = !this->state;
            }
            else
            {

                this->game[numberOfCell] = 1;
                this->state = !this->state;
            }
        }

        std::printf("%d - %d\n", numberOfCell, this->game[numberOfCell]);
        return 1;
    }

    /*!
 * Creates a coordinate for drawing
 */
    void update()
    {
        this->pollEvents();
    }
/*!
 * Drawing 0
 * @param x_0
 * @param y_0
 * @return
 */
    sf::CircleShape makeO(float x_0, float y_0)
    {
        sf::CircleShape o;

        o.setPosition(x_0, y_0);
        o.setRadius(30);
        o.setFillColor(sf::Color::Black);
        o.setOutlineColor(sf::Color::Yellow);
        o.setOutlineThickness(1);
        o.setOrigin(30, 30);

        return o;
    }
/*!
 * Drawing X
 * @param x_0
 * @param y_0
 * @return
 */
    std::array<sf::VertexArray, 2> makeX(float x_0, float y_0)
    {

        sf::VertexArray first(sf::LineStrip, 2);
        first[0].position = sf::Vector2f(x_0 - 25, y_0 - 25);
        first[0].color = sf::Color::Blue;
        first[1].position = sf::Vector2f(x_0 + 25, y_0 + 25);
        first[1].color = sf::Color::Blue;

        sf::VertexArray second(sf::LineStrip, 2);
        second[0].position = sf::Vector2f(x_0 + 25, y_0 - 25);
        second[0].color = sf::Color::Red;
        second[1].position = sf::Vector2f(x_0 - 25, y_0 + 25);
        second[1].color = sf::Color::Red;


        std::array<sf::VertexArray, 2> x = {first, second};
        return x;
    }
/*!
 * Drawing a grid for the game
 * @return
 */
    std::array<sf::VertexArray, 4> makeGrid()
    {
        sf::VertexArray first(sf::LineStrip, 2);
        first[0].position = sf::Vector2f(0, 100);
        first[1].position = sf::Vector2f(300, 100);

        sf::VertexArray second(sf::LineStrip, 2);
        second[0].position = sf::Vector2f(0, 200);
        second[1].position = sf::Vector2f(300, 200);

        sf::VertexArray third(sf::LineStrip, 2);
        third[0].position = sf::Vector2f(100, 0);
        third[1].position = sf::Vector2f(100, 300);

        sf::VertexArray fourth(sf::LineStrip, 2);
        fourth[0].position = sf::Vector2f(200, 0);
        fourth[1].position = sf::Vector2f(200, 300);

        std::array<sf::VertexArray, 4> grid = {first, second, third, fourth};

        return grid;
    }
/*!
 * In case of clicking and drawing X
 * @param numberOfCell
 * @return
 */
    std::array<sf::VertexArray, 2> drawX(int numberOfCell)
    {
        switch (numberOfCell)
        {
            case 0:
                return this->makeX(50, 50);
                break;

            case 1:
                return this->makeX(150, 50);
                break;

            case 2:
                return this->makeX(250, 50);
                break;

            case 3:
                return this->makeX(50, 150);
                break;

            case 4:
                return this->makeX(150, 150);
                break;

            case 5:
                return this->makeX(250, 150);
                break;

            case 6:
                return this->makeX(50, 250);
                break;

            case 7:
                return this->makeX(150, 250);
                break;

            case 8:
                return this->makeX(250, 250);
                break;

            default:
                throw std::runtime_error("wrong cell");
                break;
        }
    }
/*!
 * In case of clicking and drawing 0
 * @param numberOfCell
 * @return
 */
    sf::CircleShape drawO(int numberOfCell)
    {
        switch (numberOfCell)
        {
            case 0:
                return this->makeO(50, 50);
                break;
            case 1:
                return this->makeO(150, 50);
                break;
            case 2:
                return this->makeO(250, 50);
                break;
            case 3:
                return this->makeO(50, 150);
                break;
            case 4:
                return this->makeO(150, 150);
                break;
            case 5:
                return this->makeO(250, 150);
                break;
            case 6:
                return this->makeO(50, 250);
                break;
            case 7:
                return this->makeO(150, 250);
                break;
            case 8:
                return this->makeO(250, 250);
                break;

            default:
                throw std::runtime_error("wrong cell");
                break;
        }
    }
/*!
 * The function calls drawX and drawY thereby drawing X and Y in the playing field
 */
    void render()
    {
        this->window->clear();

        for (int i = 0; i < (int)this->game.size(); i++)
        {
            if (this->game[i] == 0)
            {
                this->window->draw(this->drawO(i));
            }
            else if (this->game[i] == 1)
            {
                for (int j = 0; j < (int)this->drawX(0).size(); j++)
                {
                    this->window->draw(this->drawX(i)[j]);
                }
            }
        }
        for (int i = 0; i < (int)this->grid.size(); ++i)
        {
            this->window->draw(this->grid[i]);
        }

        this->window->display();
    }

public:
    /*!
     * The cycle of the game
     */
    int run()
    {
        while (this->window->isOpen())
        {
            this->update();
            this->render();

        }
        return 0;
    }

    /*!
     * Calling the window opening function
     */
    Game()
    {
        this->initWindow();
    }

    /*!
     * Calling the window closing function
     */
    ~Game()
    {
        delete this->window;
    }
};
