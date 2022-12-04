int partition_array(int a[], int si, int ei)
{
    int count_small = 0;

    for (int i = (si + 1); i <= ei; i++)
    {
        if (a[i] <= a[si])
        {
            count_small++;
        }
    }
    int c = si + count_small;
    int temp = a[c];
    a[c] = a[si];
    a[si] = temp;
    visualize(c, si);

    int i = si, j = ei;

    while (i < c && j > c)
    {
        if (a[i] <= a[c])
        {
            i++;
        }
        else if (a[j] > a[c])
        {
            j--;
        }
        else
        {
            int temp_1 = a[j];
            a[j] = a[i];
            a[i] = temp_1;

            visualize(i, j);
            SDL_Delay(70);

            i++;
            j--;
        }
    }
    return c;
}
void CAlgorithms::quickSort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int c = partition_array(a, si, ei);
    quickSort(a, si, c - 1);
    quickSort(a, c + 1, ei);
}
