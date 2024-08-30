#include <bits/stdc++.h>

using namespace std;

typedef void (*SortMethod)(int *, int, bool CompFunc(int, int));
typedef bool (*SearchMethod)(int *, int, int, int &, bool CompFunc(int, int), int &count1, int &count2);

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
        cout << a[i] << " ";
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
    do
    {
        swapped = false;
        for (int i = 1; i < n; i++)
        {
            if (CompFunc(a[i - 1], a[i]))
            {
                Swap(a[i - 1], a[i]);
                swapped = true;
            }
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
        if (!CompFunc(a[i], pivot) || a[i] == pivot && rand() % 2 == 0)
        {
            Swap(a[i], a[storeIndex]);
            ++storeIndex;
        }
    }
    Swap(a[low], a[storeIndex - 1]);
    return storeIndex - 1;
}

void QuickSortComponent(int *a, int low, int high, bool CompFunc(int, int))
{
    if (low < high)
    {
        int pi = Partition(a, low, high, CompFunc);
        QuickSortComponent(a, low, pi - 1, CompFunc);
        QuickSortComponent(a, pi + 1, high, CompFunc);
    }
}

void QuickSort(int *a, int n, bool CompFunc(int, int))
{
    QuickSortComponent(a, 0, n - 1, CompFunc);
}
// dong bo hoa tat ca la int*, int, bool
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
        if (!CompFunc(L[i], R[j]))
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

void MergeSortComponent(int *a, int l, int r, bool CompFunc(int, int))
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSortComponent(a, l, m, CompFunc);
        MergeSortComponent(a, m + 1, r, CompFunc);
        Merge(a, l, m, r, CompFunc);
    }
}

void MergeSort(int *a, int n, bool CompFunc(int, int))
{
    MergeSortComponent(a, 0, n - 1, CompFunc);
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
bool LinearSearch(int *a, int n, int key, int &Idx, bool CompFunc(int, int), int &count, int &) // sorted array
{
    // check within range validation
    if ((key - a[0]) * (key - a[n - 1]) > 0)
    {
        cout << "Not found!\n";
        return false;
    }
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
        else if (!CompFunc(key, a[i]))
        {
            cout << "Not found!\n";
            return false;
        }
    }
    cout << "Not found!\n";
    return false;
}

// Binary Search
bool BinarySearch(int *a, int n, int key, int &Idx, bool CompFunc(int, int), int &count1, int &count2)
{
    int low = 0;
    int high = n - 1;
    if ((key - a[low]) * (key - a[high]) > 0)
    {
        cout << "Not found!\n";
        return false;
    }
    count1 = 0;
    count2 = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == key)
        {
            Idx = mid;
            int left = mid, right = mid + 1;
            while (left >= low && a[left] == key)
            {
                count1++;
                left--;
            }
            while (right <= high && a[right] == key)
            {
                count2++;
                right++;
            }
            return true;
        }
        else if (!CompFunc(a[mid], key))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Not found!\n";
    return false;
}

int ChooseSortingMethodAndOrder(int *a, int n)
{
    int choice;
    cout << "Choose sorting method: \n";
    cout << "1. Selection Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Heap Sort\n";
    cout << "7. Shell Sort\n";
    cout << "8. Radix Sort\n";
    cout << "Your choice: ";
    cin >> choice;
    SortMethod sortMethod;
    bool flagLoop = true;
    do
    {
        switch (choice)
        {
        case 1:
            sortMethod = SelectionSort;
            flagLoop = false;
            break;
        case 2:
            sortMethod = BubbleSort;
            flagLoop = false;
            break;
        case 3:
            sortMethod = InsertionSort;
            flagLoop = false;
            break;
        case 4:
            sortMethod = QuickSort;
            flagLoop = false;
            break;
        case 5:
            sortMethod = MergeSort;
            flagLoop = false;
            break;
        case 6:
            sortMethod = HeapSort;
            flagLoop = false;
            break;
        case 7:
            sortMethod = ShellSort;
            flagLoop = false;
            break;
        case 8:
            sortMethod = RadixSort;
            flagLoop = false;
            break;
        default:
            cout << "Invalid choice! Please choose again!\n";
            break;
        }
    } while (flagLoop);

    int Order;
    cout << "Choose order: \n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Your choice: ";
    cin >> Order;
    flagLoop = true;
    do
    {
        switch (Order)
        {
        case 1:
            sortMethod(a, n, ascending);
            flagLoop = false;
            break;
        case 2:
            sortMethod(a, n, descending);
            flagLoop = false;
            break;
        default:
            cout << "Invalid choice! Please choose again!\n";
            break;
        }
    } while (flagLoop);

    return Order;
}

SearchMethod ChooseSearchingMethod(int *a, int n)
{
    int choice;
    cout << "Choose searching method: \n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Your choice: ";
    cin >> choice;
    SearchMethod searchMethod;
    bool flagLoop = true;
    do
    {
        switch (choice)
        {
        case 1:
            searchMethod = LinearSearch;
            flagLoop = false;
            break;
        case 2:
            searchMethod = BinarySearch;
            flagLoop = false;
            break;
        default:
            cout << "Invalid choice! Please choose again!\n";
            break;
        }
    } while (flagLoop);
    return searchMethod;
}

int main()
{   
    cout <<"+-------------------------------------------------+\n";
    cout <<"|         Ho va ten: Nguyen Huu Minh Quan         |\n";
    cout <<"|         MSSV: 102230208                         |\n";
    cout <<"|         Lop: 23T_DT1                            |\n";
    cout <<"+-------------------------------------------------+\n";
    
    again: 
    int n;
    cout << "Input the size of array: ";
    cin >> n;
    int *a = DynamicAllocating(n);
    cout << "Enter the elements: ";
    InputArr(a, n);
    int Order = ChooseSortingMethodAndOrder(a, n);
    cout << "Sorted array: ";
    PrintArr(a, n);
    cout << endl;
    SearchMethod searchMethod = ChooseSearchingMethod(a, n);
    int key;
    cout << "Enter the key: ";
    cin >> key;
    int Idx;
    int count1 = 0, count2 = 0;
    if (searchMethod(a, n, key, Idx, Order == 1 ? ascending : descending, count1, count2))
    {
        cout << "Found number at index: ";
        // linear search thi count1 la so lan xuat hien cua key, tu dau den cuoi
        // binary search thi count1 la so lan xuat hien cua key o ben trai mid va count2 la ben phai mid
       for(int i = count1 - 1; i >= 0; i--)
		{
			cout << " " << Idx - i << " ";
		}
		for(int i = count2; i > 0; i--)
		{
			cout << " " << Idx + i << " ";
		}
        cout << endl;
    }
    cout<< "\nDo you want to continue? (Y/N): "; 
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') 
    {
        delete[] a;
        count1 = 0;
        count2 = 0;
        goto again;
    }
    delete[] a;
    return 0;
}