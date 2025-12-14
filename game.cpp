#include <iostream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

void bersihkan(char map[HEIGHT][WIDTH]);
void draw(char map[HEIGHT][WIDTH], int score, int lives);
void bulatbulat(int &fx, int &fy);

int main() {

    char map[HEIGHT][WIDTH];
    int playerX = WIDTH / 2;
    int playerY = HEIGHT - 1;

    int buletX, buletY;
    int score = 0;
    int lives = 3;
    bool gameOver = false;

    bulatbulat(buletX, buletY);

     cout << "Selamat Datang, Tangkap Yaa, Jangan Sampai Lolos!" << endl;
     cout << "Good Luck, fellas. And, HAVE FUN!!!" << endl;

    while (!gameOver) {
        bersihkan(map);

        char input;
        cout << "[a] kiri | [d] kanan | [q] quit : ";
        cin >> input;

        if (input == 'a' && playerX > 0)
            playerX--;
        else if (input == 'd' && playerX < WIDTH - 1)
            playerX++;
        else if (input == 'q')
             cout << "Yaudah deh, bye-bye" << endl;
            break; 

        buletY++;

        if (buletY == playerY && buletX == playerX) {
            score++;
            bulatbulat(buletX, buletY);
        }

        else if (buletY >= HEIGHT) {
            lives--;
            bulatbulat(buletX, buletY);

            if (lives <= 0)
            gameOver = true;
        }

        map[playerY][playerX] = 'U';
        if (buletY < HEIGHT)
            map[buletY][buletX] = '*';

        draw(map, score, lives);
    }

    cout << "OH NO! the loser's standing small ah moment \n Score akhir: " << score << endl;
    cout << "ALL FINE, it's always free to try again XOXO" << endl;
    return 0;
}

void bersihkan(char map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            map[i][j] = '.';
}

void draw(char map[HEIGHT][WIDTH], int score, int lives) {
    cout << "\nScore: " << score << " | Lives: " << lives << endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
}

void bulatbulat(int &fx, int &fy) {
    fx = rand() % WIDTH;
    fy = 0;
}
