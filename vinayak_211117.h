void CAlgorithms::bubbleSort()
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = 0; j < arrSize - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                visualize(j + 1, j, arrSize - i);
            }
            SDL_Delay(1);
        }
    }
}
void COperations::execute(CAlgorithms objAlgo)
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
                    objAlgo.selectionSort();
                    complete = true;
                    cout << "\nSELECTION SORT COMPLETE.\n";
                    break;
                case (SDLK_2):
                    loadArr();
                    cout << "\nINSERTION SORT STARTED.\n";
                    complete = false;
                    objAlgo.insertionSort();
                    complete = true;
                    cout << "\nINSERTION SORT COMPLETE.\n";
                    break;
                case (SDLK_3):
                    loadArr();
                    cout << "\nBUBBLE SORT STARTED.\n";
                    complete = false;
                    objAlgo.bubbleSort();
                    complete = true;
                    cout << "\nBUBBLE SORT COMPLETE.\n";
                    break;
                case (SDLK_4):
                    loadArr();
                    cout << "\nMERGE SORT STARTED.\n";
                    complete = false;
                    objAlgo.mergeSort(arr, 0, arrSize - 1);
                    complete = true;
                    cout << "\nMERGE SORT COMPLETE.\n";
                    break;
                case (SDLK_5):
                    loadArr();
                    cout << "\nQUICK SORT STARTED.\n";
                    complete = false;
                    objAlgo.quickSort(arr, 0, arrSize - 1);
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