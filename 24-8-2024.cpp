#include <bits/stdc++.h>

using namespace std;

typedef void (*SortFunc)(int *, int, bool CompFunc(int, int));

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

bool ascending(int left, int right)
{
    return left > right;
}

bool descending(int left, int right)
{
    return right > left;
}
// SelectionSort

void SelectionSort(int *a, int n, bool CompFunc(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        for (int j = i + 1; j < n; j++)
        {
            if (CompFunc(a[key], a[j]))
            {
                key = j;
            }
        }
        if (key != i)
        {
            Swap(a[key], a[i]);
        }
    }
}

// BubbleSort

void BubbleSort(int *a, int n, bool CompFunc(int, int))
{
    bool swapped;
    int swapCounter = 0;
    do
    {
        bool swapped = false;
        for (int i = 1; i < n; i++)
        {
            if (CompFunc(a[i - 1], a[i]))
            {
                Swap(a[i - 1], a[i]);
                swapped = true;
            }
            ++swapCounter;
        }
    } while (swapped);
}

// InsertionSort

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

// QuickSort

int Partition(int *a, int low, int high, bool CompFunc(int, int))
{
    int pivot = a[low];
    int storeIndex = low + 1;
    for (int i = low + 1; i <= high; i++)
    {
        if (CompFunc(a[i], pivot) || a[i] == pivot && rand() % 2 == 0)
        {
            Swap(a[i], a[storeIndex]);
            ++storeIndex;
        }
    }
    Swap(a[low], a[storeIndex - 1]);
    return storeIndex - 1;
}

void QuickSort(int *a, int low, int high, bool CompFunc(int, int))
{
    if (low == 0 && high > 0)
    {
        srand(time(0));
    }
    if (low < high)
    {
        int pi = Partition(a, low, high, CompFunc);
        QuickSort(a, low, pi - 1, CompFunc);
        QuickSort(a, pi + 1, high, CompFunc);
    }
}

// MergeSort

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

// HeapSort

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
    // build heap
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

// ShellSort

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

// RadixSort

int getMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
void countSort(int *a, int n, int exp, bool CompFunc(int, int))
{
    int *output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    if (CompFunc == ascending)
    {
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
    }
    else
    {
        for (int i = 8; i >= 0; i--)
        {
            count[i] += count[i + 1];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
    delete[] output;
}
void RadixSort(int *a, int n, bool CompFunc(int, int))
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(a, n, exp, CompFunc);
    }
}

// Linear Search
bool LinearSearch(int *a, int n, int key, int &Idx, int &count, int &, int OrderChoice) // sorted array
{
    // check within range validation
    if (key >= a[0] && key <= a[n - 1])
    {
        for (int i = 0; i < n; i++)
        {
            if (key == a[i])
            {
                Idx = i;
                count = 1;
                int j = i + 1;
                while (j < n && key == a[j])
                {
                    count++;
                    j++;
                }
                return true;
            }
            else if (OrderChoice == 1 && key < a[i])
            {   
                cout <<"Not found!\n";
                return false;
            }
            else if (OrderChoice == 2 && key > a[i])
            {   
                cout <<"Not found!\n";
                return false;
            }
        }
    }
    cout <<"Not found!\n";
    return false;
}

// Binary Search
bool BinarySearch(int *a, int n, int key, int &Idx, int &count1, int &count2, int OrderChoice)
{
    

}
int main()
{
    int n;
    cout << "Nhap kich co mang: ";
    cin >> n;
}
