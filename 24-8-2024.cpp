#include <bits/stdc++.h>

using namespace std;

int *DynamicAllocating(int n)
{
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        *(a + i) = 0;
    }
    return a;
}

void InputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void PrintArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

//SelectionSort

void SelectionSort(int *a, int n, bool CompFunc(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (CompFunc(a[j], a[min]))
            {
                min = j;
            }
        }
        if (min != i)
        {
            Swap(a[i], a[min]);
        }
    }
}

//BubbleSort

void BubbleSort(int *a, int n, bool CompFunc(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (CompFunc(a[j], a[j + 1]))
            {
                Swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

//InsertionSort

void InsertionSort(int *a, int n, bool CompFunc(int, int))
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && CompFunc(a[j], key))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

//QuickSort

int Partition(int *a, int low, int high, bool CompFunc(int, int))
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (CompFunc(a[j], pivot))
        {
            i++;
            Swap(a[i], a[j]);
        }
    }
    Swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSort(int *a, int low, int high, bool CompFunc(int, int))
{
    if (low < high)
    {
        int pi = Partition(a, low, high, CompFunc);
        QuickSort(a, low, pi - 1, CompFunc);
        QuickSort(a, pi + 1, high, CompFunc);
    }
}

//MergeSort

void Merge(int *a, int l, int m, int r, bool CompFunc(int, int))
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (CompFunc(L[i], R[j]))
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void MergeSort(int *a, int l, int r, bool CompFunc(int, int))
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    MergeSort(a, l, m, CompFunc);
    MergeSort(a, m + 1, r, CompFunc);
    Merge(a, l, m, r, CompFunc);
}

//HeapSort

void Heapify(int *a, int n, int i, bool CompFunc(int, int))
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && CompFunc(a[l], a[largest]))
    {
        largest = l;
    }
    if (r < n && CompFunc(a[r], a[largest]))
    {
        largest = r;
    }
    if (largest != i)
    {
        Swap(a[i], a[largest]);
        Heapify(a, n, largest, CompFunc);
    }
}

void HeapSort(int *a, int n, bool CompFunc(int, int))
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(a, n, i, CompFunc);
    }
    for (int i = n - 1; i > 0; i--)
    {
        Swap(a[0], a[i]);
        Heapify(a, i, 0, CompFunc);
    }
}
//ShellSort

void ShellSort(int *a, int n, bool CompFunc(int, int))
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && CompFunc(a[j - gap], temp); j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

//sequentialSearch

int SequentialSearch(int *a, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//BinarySearch - iterative

int BinarySearch(int *a, int l, int r, int key, bool CompFunc(int, int))
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == key)
        {
            return m;
        }
        if (CompFunc(a[m], key))
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}


int main()
{   
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *a = DynamicAllocating(n);
    cout << "Enter the elements: ";
    InputArr(a, n);
    cout << "The elements are: ";
    PrintArr(a, n);
    cout << endl;
    int key;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Choose the sorting method: " << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Heap Sort" << endl;
    cout << "7. Shell Sort" << endl;
    int choice;
    cin >> choice;
    cout << "Choose the sorting order: " << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    int order;
    cin >> order;
    switch (choice)
    {
    case 1:
        SelectionSort(a, n, order == 1 ? ascending : descending);
        break;
    case 2:
        BubbleSort(a, n, order == 1 ? ascending : descending);
        break;
    case 3:
        InsertionSort(a, n, order == 1 ? ascending : descending);
        break;
    case 4:
        QuickSort(a, 0, n - 1, order == 1 ? ascending : descending);
        break;
    case 5:
        MergeSort(a, 0, n - 1, order == 1 ? ascending : descending);
        break;
    case 6:
        HeapSort(a, n, order == 1 ? ascending : descending);
        break;
    case 7:
        ShellSort(a, n, order == 1 ? ascending : descending);
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    cout << "The sorted array is: ";
    PrintArr(a, n);
    cout << endl;
    cout << "Choose the search method: " << endl;
    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;
    int searchChoice;
    cin >> searchChoice;
    switch (searchChoice)
    {
    case 1:
        cout << "The key is at index: " << SequentialSearch(a, n, key) << endl;
        break;
    case 2:
        cout << "The key is at index: " << BinarySearch(a, 0, n - 1, key, order == 1 ? ascending : descending) << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    delete[] a;
    return 0;
}