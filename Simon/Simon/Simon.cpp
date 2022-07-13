using namespace std;

#include <iostream>
#include <ctime>

// Variables globales
#define MAX_LEVEL 100
int level = 1;


#ifdef _WIN32
#include <windows.h>

void sleep(unsigned seconds)
{
    Sleep(seconds * 1000);
}
#else
#include <chrono>
#include <thread>

void sleep(unsigned seconds)
{
    std::chrono::duration<int, std::milli> timespan(seconds * 1000);
    std::this_thread::sleep_for(timespan);
}
#endif

int main()
{
    srand(time(NULL));
    int sequence[100], player_sequence;
    bool isFalse = false;

    for (int i = 0; i < level; i++) {
        if (isFalse) {
            level = 1;
            isFalse = false;
            i = 0;
        }
        if (level == 1) {
            for (int i = 0; i < MAX_LEVEL; i++) {
                sequence[i] = rand() % 4 + 1;
            }
        }
        for (int j = 0; j < level; j++) {
            system("CLS");
            switch (sequence[j]) {
            case 1:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A); // texte blanc (F) sur fond noir (0)
                cout << "Vert ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); // texte blanc (F) sur fond noir (0)
                cout << "Bleu ";
                cout << "Rouge ";
                cout << "VIolet";
                break;
            case 2:
                cout << "Vert ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B); // texte blanc (F) sur fond noir (0)
                cout << "Bleu ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); // texte blanc (F) sur fond noir (0)
                cout << "Rouge ";
                cout << "Violet";
                break;
            case 3:
                cout << "Vert ";
                cout << "Bleu ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); // texte blanc (F) sur fond noir (0)
                cout << "Rouge ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); // texte blanc (F) sur fond noir (0)
                cout << "Violet";
                break;
            case 4:
                cout << "Vert ";
                cout << "Bleu ";
                cout << "Rouge ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D); // texte blanc (F) sur fond noir (0)
                cout << "Violet";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); // texte blanc (F) sur fond noir (0)
                break;
            }
            Sleep(500);
        }
        for (int k = 0; k < level; k++) {
            cout << "\n" << k + 1 << ". digits : ";
            cin >> player_sequence;

            if (player_sequence != sequence[k]) {
                isFalse = true;
            }
        }
        level++;
    }
    return 0;
}