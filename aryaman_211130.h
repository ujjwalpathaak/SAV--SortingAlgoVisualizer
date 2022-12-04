void CAlgorithms::insertionSort()
{
    for (int i = 1; i < arrSize; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;

            visualize(i, j + 1);
            SDL_Delay(5);
        }
        arr[j + 1] = temp;
    }
}
void COperations::intro()
{
    cout << "X--------------- Sorting Visualizer ---------------X\n\n"
         << "We are using SDL2 Library.\n"
         << "We'll be looking at some of these sorting algorithms and visually comprehend their working.\n"
         << "The sorting algorithms covered here are Selection Sort, Insertion Sort, Bubble Sort, Merge Sort and Quick Sort.\n";
};
bool COperations::initialize()
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