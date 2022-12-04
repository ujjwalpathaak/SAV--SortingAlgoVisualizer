void CAlgorithms::selectionSort()
{
    int minIndex;
    for (int i = 0; i < arrSize - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                visualize(i, minIndex);
            }
            SDL_Delay(1);
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
bool COperations::controls()
{
    cout << "1 to start Selection Sort Algorithm." << endl
         << "2 to start Insertion Sort Algorithm." << endl
         << "3 to start Bubble Sort Algorithm." << endl
         << "4 to start Merge Sort Algorithm." << endl
         << "5 to start Quick Sort Algorithm." << endl
         << "-1 to exit out of Sorting Visualizer" << endl
         << "PRESS ENTER TO START SORTING VISUALIZER..." << endl
         << "Or -1 to quit." << endl;

    string s;
    getline(cin, s);
    if (s == "-1")
    {
        return false;
    }
    return true;
}

void COperations::close()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

void COperations::loadArr()
{
    memcpy(arr, Barr, sizeof(int) * arrSize);
}