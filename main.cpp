#include <SDL2/SDL.h>
#include <iostream>
#include <limits>
#include <time.h>
#include <string>
#include <cstring>

using namespace std;

// Constants
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 750;

// Array
const int arrSize = 100;
const int rectSize = 9;

int arr[arrSize];
int Barr[arrSize];

bool complete = false;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

// class COperations {
//     public:
//     void intro();
// };

// class CAlgorithms {
//     public:
//         void bubbleSort();
//         void mergeSort();
//         void merge2SortedArrays();
//         void insertionSort();
//         void selectionSort();
//         void quickSort();
//         void arrayPartition();
//         void swapSelectionSort();
// };


bool initialize()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Couldn't initialize SDL. SDL_Error: " << SDL_GetError();
        success = false;
    }
    else
    {
        if (!(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")))
        {
            cout << "Warning: Linear Texture Filtering not enabled.\n";
        }

        window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Couldn't create window. SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                cout << "Couldn't create renderer. SDL_Error: " << SDL_GetError();
                success = false;
            }
        }
    }
    return success;
}

void visualize(int x = -1, int y = -1, int z = -1)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    int j = 0;
    for (int i = 0; i <= SCREEN_WIDTH - rectSize; i += rectSize)
    {
        SDL_PumpEvents();

        SDL_Rect rect = {i, 0, rectSize, arr[j]};
        if (complete)
        {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        else if (j == x || j == z)
        {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
        else if (j == y)
        {
            SDL_SetRenderDrawColor(renderer, 165, 105, 189, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 170, 183, 184, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        j++;
    }
    SDL_RenderPresent(renderer);
}

void close()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

void intro()
{
    cout << "X--------------- Sorting Visualizer ---------------X\n\n"
         << "We are using SDL2 Library.\n"
         << "We'll be looking at some of these sorting algorithms and visually comprehend their working.\n"
         << "The sorting algorithms covered here are Selection Sort, Insertion Sort, Bubble Sort, Merge Sort and Quick Sort.\n";
};

bool controls()
{
    cout << "1 to start Selection Sort Algorithm.\n"
         << "2 to start Insertion Sort Algorithm.\n"
         << "3 to start Bubble Sort Algorithm.\n"
         << "4 to start Merge Sort Algorithm.\n"
         << "5 to start Quick Sort Algorithm.\n"
         << "-1 to exit out of Sorting Visualizer\n\n"
         << "PRESS ENTER TO START SORTING VISUALIZER...\n\n"
         << "Or -1 to quit.";

    string s;
    getline(cin, s);
    if (s == "-1")
    {
        return false;
    }
    return true;
}

void randomizeAndSaveArray()
{
    unsigned int seed = (unsigned)time(NULL);
    srand(seed);
    for (int i = 0; i < arrSize; i++)
    {
        int random = rand() % (SCREEN_HEIGHT);
        Barr[i] = random;
    }
}

void loadArr()
{
    memcpy(arr, Barr, sizeof(int) * arrSize);
}
#include "ujjwal_211105.h"
#include "aamya_211112.h"
#include "deep_211132.h"
#include "aryaman_211130.h"
#include "vinayak_211117.h"
void execute()
{
        initialize();
        randomizeAndSaveArray();
        loadArr();

        SDL_Event e;
        bool check = false;
        while (!check)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    check = true;
                    complete = false;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                    case (SDLK_1):
                        loadArr();
                        cout << "\nSELECTION SORT STARTED.\n";
                        complete = false;
                        selectionSort();
                        complete = true;
                        cout << "\nSELECTION SORT COMPLETE.\n";
                        break;
                    case (SDLK_2):
                        loadArr();
                        cout << "\nINSERTION SORT STARTED.\n";
                        complete = false;
                        insertionSort();
                        complete = true;
                        cout << "\nINSERTION SORT COMPLETE.\n";
                        break;
                    case (SDLK_3):
                        loadArr();
                        cout << "\nBUBBLE SORT STARTED.\n";
                        complete = false;
                        bubbleSort();
                        complete = true;
                        cout << "\nBUBBLE SORT COMPLETE.\n";
                        break;
                    case (SDLK_4):
                        loadArr();
                        cout << "\nMERGE SORT STARTED.\n";
                        complete = false;
                        mergeSort(arr, 0, arrSize - 1);
                        complete = true;
                        cout << "\nMERGE SORT COMPLETE.\n";
                        break;
                    case (SDLK_5):
                        loadArr();
                        cout << "\nQUICK SORT STARTED.\n";
                        complete = false;
                        quickSort(arr, 0, arrSize - 1);
                        complete = true;
                        cout << "\nQUICK SORT COMPLETE.\n";
                        break;
                    }
                }
            }
            visualize();
        }
        close();
    }

int main(int argc, char *args[])
{
    intro();

    while (1)
    {
        if (controls())
            execute();
        else
        {
            cout << "\nEXITING PROGRAM.\n";
            break;
        }
    }

    return 0;
}
