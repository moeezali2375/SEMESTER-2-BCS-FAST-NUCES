#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
ofstream fout("top5.txt");
ifstream fin("leaderboard.txt");
class timer
{

private:
    sf::Font font;
    sf::Text text;
    long t;
    long tim;

public:
    timer()
    {
        if (!font.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/Fonts/digits.ttf"))
            cout << "error " << endl;
        text.setFont(font);
        text.setString("#4");
        text.setPosition(60, 45);
        text.setCharacterSize(45);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        t = time(0);
    }
    long timers(sf::RenderWindow &window, bool et)
    {
        sf::RectangleShape shape(sf::Vector2f(50.0f, 40.0f));
        shape.setFillColor(sf::Color::White);
        shape.move(sf::Vector2f(0, 100));
        if (!et)
            tim = time(0) - t;
        else
            return tim;
        string xc = to_string(tim);
        text.setString(xc);
        window.draw(shape);
        window.draw(text);
    }
};

bool tile_checker(int x, int y, int r, int c, int w)
{

    int flag0 = 0;
    int flag1 = 0;
    for (int j = 0; j < c; j++)
    {
        if (x >= j * (w + 10) + 50 && x <= j * (w + 10) + 50 + w)
        {
            flag1 = 1;
        }
    }
    for (int i = 0; i < r; i++)
    {
        if (y >= i * (w + 10) + 100 && y <= i * (w + 10) + 100 + w)
            flag0 = 1;
    }
    if (flag1 == 1 && flag0 == 1)
    {
        return true;
    }
    return false;
}

void reveal(int i, int j, int tiles[][100], int grid[][100], int r, int c)
{
    if (tiles[i][j] == -1 && grid[i][j] != 100 && i >= 0 && i < r && j >= 0 && j < c)
    {
        tiles[i][j] = grid[i][j];
        if (grid[i][j] == 0)
        {
            //       tiles[i][j] = grid[i][j];
            reveal(i, j - 1, tiles, grid, r, c);
            reveal(i, j + 1, tiles, grid, r, c);
            reveal(i - 1, j - 1, tiles, grid, r, c);
            reveal(i + 1, j - 1, tiles, grid, r, c);
            reveal(i + 1, j + 1, tiles, grid, r, c);
            reveal(i - 1, j + 1, tiles, grid, r, c);
            reveal(i - 1, j, tiles, grid, r, c);
            reveal(i + 1, j, tiles, grid, r, c);
        }
    }
}

int grid_updater(int grid[][100], int tiles[][100], int x, int y, int r, int c)
{

    int w = 29;
    if (grid[y][x] != 0)
    {
        tiles[y][x] = grid[y][x];
        if (grid[y][x] == 100)
        {
            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    tiles[j][i] = grid[j][i];
                }
            }
            return 1;
        }
    }
    else if (grid[y][x] == 0)
        reveal(y, x, tiles, grid, r, c);
    return 0;
}

void flag_grid_updater(int grid[][100], int tiles[][100], int x, int y, int r, int c, int &mines)
{

    int w = 29;
    if (tiles[y][x] == -1)
    {
        tiles[y][x] = -2;
        mines--;
    }
    else if (tiles[y][x] == -2)
    {
        tiles[y][x] = -1;
        mines++;
    }
}

void display_tiles(int tiles[][100], int r, int c, int w, RenderWindow &window)
{
    Texture t;
    Sprite s(t);
    Texture num0, num1, num2, num3, num4, num5, num6, num7, num8, mine, flag;
    num0.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/0.png");
    num1.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/1.png");
    num2.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/2.png");
    num3.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/3.png");
    num4.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/4.png");
    num5.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/5.png");
    num6.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/6.png");
    num7.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/7.png");
    num8.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/8.png");
    mine.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/mine.png");
    flag.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/flag.png");
    Sprite n0(num0), n1(num1), n2(num2), n3(num3), n4(num4), n5(num5), n6(num6), n7(num7), n8(num8), mi(mine), fl(flag);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (tiles[i][j] == -2)
            {
                fl.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(fl);
            }
            if (tiles[i][j] == -1)
            {
                s.setTextureRect(IntRect(0, 0, w, w));
                s.setColor(Color::Black);
                s.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(s);
            }
            if (tiles[i][j] == 0)
            {
                n0.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n0);
            }
            if (tiles[i][j] == 1)
            {
                n1.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n1);
            }
            if (tiles[i][j] == 2)
            {
                n2.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n2);
            }
            if (tiles[i][j] == 3)
            {
                n3.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n3);
            }
            if (tiles[i][j] == 4)
            {
                n4.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n4);
            }
            if (tiles[i][j] == 5)
            {
                n5.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n5);
            }
            if (tiles[i][j] == 6)
            {
                n6.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n6);
            }
            if (tiles[i][j] == 7)
            {
                n7.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n7);
            }
            if (tiles[i][j] == 8)
            {
                n8.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(n8);
            }
            if (tiles[i][j] == 100)
            {
                mi.setPosition(j * (w + 10) + 50, i * (w + 10) + 100);
                window.draw(mi);
            }
        }
    }
}

int tiles_remaining(int tiles[][100], int r, int c)
{
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (tiles[i][j] == -2 || tiles[i][j] == -1)
            {
                count++;
            }
        }
    }
    return count;
}

void console(int grid[][100], int r, int c, int w, string s, int mines)
{
    int win_losee = 0;
    long int success;
    bool high_score = 0;
    sf::RenderWindow window(sf::VideoMode(1440, 858), s, sf::Style::Close | sf::Style::Resize);
    if (win_losee == 0)
    {
        int win_lose = 0;
        timer time;
        Font headings;
        headings.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/Fonts/digits.ttf");
        int tiles_left = mines;
        bool sound_control = 0;
        bool check = 0;
        bool check2 = 0;
        sf::SoundBuffer buffer;
        buffer.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/audio/lal aye.wav");
        if (!buffer.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/audio/lal aye.wav"))
        {
            std::cout << "LAAL aye";
        }
        sf::Sound sound;
        sound.setBuffer(buffer);
        // ASAL KAAM
        int tiles[100][100];
        w = 29;
        // TILES GENERATOR
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                tiles[i][j] = -1;
            }
        }
        // RENDER_WINDOW
        // WINDOW_DISPLAY

        while (window.isOpen())
        {
            if (win_lose == 0)
            {
                window.clear(Color::Color::White);
                Text time_title("TIME", headings, 50);
                Text mines_title("MINES", headings, 50);
                Text mines_remaining(to_string(mines), headings, 40);
                time_title.setPosition(40, 0);
                mines_title.setPosition(1100, 0);
                mines_remaining.setPosition(1100, 50);
                time_title.setColor(Color::Black);
                mines_title.setColor(Color::Black);
                mines_remaining.setColor(Color::Red);
                window.draw(time_title);
                window.draw(mines_title);
                window.draw(mines_remaining);
                Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        break;
                    }
                    if (sound_control == 1)
                    {
                        sound.play();
                        sound_control = 0;
                        check = 1;
                        win_losee = 2;
                    }
                    if (tiles_remaining(tiles, r, c) == tiles_left)
                    {
                        win_lose = 1;
                    }
                }
                display_tiles(tiles, r, c, w, window);
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                if (tile_checker(mouse_position.x, mouse_position.y, r, c, w) == 1)
                {
                    Texture t;
                    Sprite s(t);
                    int x = (mouse_position.x - 50) / (w + 10);
                    int y = (mouse_position.y - 100) / (w + 10);
                    s.setTextureRect(IntRect(0, 0, w, w));
                    s.setColor(Color::Cyan);
                    s.setPosition(x * (w + 10) + 50, y * (w + 10) + 100);
                    window.draw(s);
                }
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    sf::Vector2i left = sf::Mouse::getPosition(window);
                    int x = (left.x - 50) / (w + 10);
                    int y = (left.y - 100) / (w + 10);
                    if (x >= 0 && x < c && y >= 0 && y < r)
                    {
                        if (tiles[y][x] == -2)
                            ;
                        else if (tiles[y][x] == -1)
                            grid_updater(grid, tiles, x, y, r, c);
                        if (grid_updater(grid, tiles, x, y, r, c) == 1)
                        {
                            sound_control = 1;
                        }
                    }
                }
                if (Mouse::isButtonPressed(Mouse::Right))
                {
                    sf::Vector2i right = sf::Mouse::getPosition(window);
                    int x = (right.x - 50) / (w + 10);
                    int y = (right.y - 100) / (w + 10);
                    if (x >= 0 && x < c && y >= 0 && y < r)
                        flag_grid_updater(grid, tiles, x, y, r, c, mines);
                }
            }
            long int success = time.timers(window, check);
            if (win_losee == 2)
            {
                Font affi;
                affi.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/Fonts/HatCheck.ttf");
                Text youwin;
                youwin.setFont(affi);
                youwin.setString("You lose!");
                youwin.setCharacterSize(100);
                youwin.setPosition(450, 725);
                youwin.setColor(Color::Black);
                window.draw(youwin);
            }

            if (win_lose == 1)
            {
                Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        break;
                    }
                }
                check = 1;
                success = time.timers(window, check);
                cout << success << endl;
                Font affi;
                affi.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/Fonts/HatCheck.ttf");
                Text youwin;
                window.clear(Color::Color::White);
                youwin.setFont(affi);
                youwin.setString("YOU WIN!");
                youwin.setCharacterSize(100);
                youwin.setPosition(500, 375);
                youwin.setColor(Color::Black);
                window.draw(youwin);
                high_score = 1;
            }
            window.display();
            if (high_score == 1)
            {
                string test_name;
                cout << "Enter your name: " << endl;
                cin >> test_name;
                string *names = new string[6];
                int *scores = new int[6];
                for (int i = 0; i < 5; i++)
                {
                    fin >> names[i];
                    fin >> scores[i];
                }
                scores[5] = success;
                names[5] = test_name;
                // SORT
                int last = 6;
                for (int i = 0; i < 6; i++)
                {
                    int max = scores[0];
                    for (int j = 0; j < last; j++)
                    {
                        if (scores[max] < scores[j])
                            max = j;
                    }
                    swap(scores[max], scores[last - 1]);
                    swap(names[max], names[last - 1]);
                    last--;
                }
                for (int i = 0; i < 5; i++)
                {
                    fout << names[i] << endl;
                    fout << scores[i] << endl;
                }
                cout << "Score updated" << endl;
                window.close();
            }
        }
    }
}