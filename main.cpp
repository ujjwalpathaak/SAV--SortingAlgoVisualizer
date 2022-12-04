#include <SDL2/SDL.h>
#include <iostream>
#include <limits>
#include <time.h>
#include <string>
#include <cstring>
using namespace std;

// Constants
const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;

// Array
const int arrSize = 75;
const int rectSize = 10;

int arr[arrSize];
int Barr[arrSize];

bool complete = false;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

class CAlgorithms
{
public:
    void bubbleSort();
    void mergeSort(int a[], int si, int ei);
    void insertionSort();
    void selectionSort();
    void quickSort(int a[], int si, int ei);
    void swapSelectionSort();
};

class COperations
{
public:
    void intro();
    bool controls();
    void execute(CAlgorithms objAlgo);
    void randomizeAndSaveArray();
    void loadArr();
    bool initialize();
    void close();
};

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
#include "ujjwal_211105.h"
#include "aamya_211112.h"
#include "deep_211132.h"
#include "aryaman_211130.h"
#include "vinayak_211117.h"

int main(int argc, char *args[])
{
    CAlgorithms objAlgo;
    COperations objOper;
    objOper.intro();

    while (1)
    {
        if (objOper.controls())
            objOper.execute(objAlgo);
        else
        {
            cout << "\nEXITING PROGRAM.\n";
            break;
        }
    }

    return 0;
}