#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c++

void PrintVector(vector<int> vector)
{
    for (int i : vector)
    {
        cout << i << " ";
    }
    cout << endl;
}

void SelectionSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int i = 0; i < n ; ++i) 
    {
        for (int j = i; j < n ; ++j) 
        {
            if (arr[j] < arr[i]) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void InverseSelectionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n ; ++i) 
    {
        for (int j = i; j < n ; ++j) 
        {
            if (arr[j] > arr[i]) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void BubbleSort(vector<int>& arr)
{
    int i, j;
    int n = arr.size();

    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InverseBubbleSort(vector<int>& arr)
{
    int i, j;
    int n = arr.size();

    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int>& arr)
{
    int i, j;
    int n = arr.size();

    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j = j - 1;
        }
    }
}

void InverseInsertionSort(vector<int>& arr)
{
    int i, j;
    int n = arr.size();

    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j = j - 1;
        }
    }
}

void ShellSort(vector<int>& arr)
{
    int n = arr.size();

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

void InverseShellSort(vector<int>& arr)
{
    int n = arr.size();

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

void UseMergeSort(vector<int>& arr)
{

}

vector<int> Merge(vector<int> a, vector<int> b)
{
    vector<int> c;

    while (!a.empty() && !b.empty())
    {
        if (a[0] > b[0])
        {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        else
        {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    while (!a.empty())
    {
        c.push_back(a[0]);
        a.erase(a.begin());
    }

    while (!b.empty())
    {
        c.push_back(b[0]);
        b.erase(b.begin());
    }

    return c;
}

vector<int> MergeSort(vector<int>& arr)
{
    int n = arr.size();

    if (n == 1)
    {
        return arr;
    }

    vector<int> arr1, arr2;
    arr1.assign(arr.begin(), arr.begin() + n/2);
    arr2.assign(arr.begin() + n/2, arr.end());
    
    arr1 = MergeSort(arr1);
    arr2 = MergeSort(arr2);

    return Merge(arr1, arr2);
}

void UseInverseMergeSort(vector<int>& arr)
{

}

vector<int> InverseMerge(vector<int> a, vector<int> b)
{
    vector<int> c;

    while (!a.empty() && !b.empty())
    {
        if (a[0] < b[0])
        {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        else
        {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    while (!a.empty())
    {
        c.push_back(a[0]);
        a.erase(a.begin());
    }

    while (!b.empty())
    {
        c.push_back(b[0]);
        b.erase(b.begin());
    }

    return c;
}

vector<int> InverseMergeSort(vector<int>& arr)
{
    int n = arr.size();

    if (n == 1)
    {
        return arr;
    }

    vector<int> arr1, arr2;
    arr1.assign(arr.begin(), arr.begin() + n/2);
    arr2.assign(arr.begin() + n/2, arr.end());
    
    arr1 = InverseMergeSort(arr1);
    arr2 = InverseMergeSort(arr2);

    return InverseMerge(arr1, arr2);
}

void UseQuickSort(vector<int>& arr)
{

}

int Partition(vector<int>& arr, int start, int end)
{
    int i = start;
    int pivot = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

void QuickSort(vector<int>& arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = Partition(arr, start, end);
 
    QuickSort(arr, start, p - 1);
    QuickSort(arr, p + 1, end);
}

void UseInverseQuickSort(vector<int>& arr)
{

}

int InversePartition(vector<int>& arr, int start, int end)
{
    int i = start;
    int pivot = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] >= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

void InverseQuickSort(vector<int>& arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = InversePartition(arr, start, end);
 
    InverseQuickSort(arr, start, p - 1);
    InverseQuickSort(arr, p + 1, end);
}

void Heapify(vector<int>& arr, int n, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i; 

    if (l < n && arr[l] > arr[i])
    {
        largest = l;
    }
    
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void BuildHeap(vector<int>& arr)
{
    int n = arr.size();

    for (int i = n/2; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
}

void HeapSort(vector<int>& arr)
{
    BuildHeap(arr);

    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        Heapify(arr, i, 0);
    }        
}

void InverseHeapify(vector<int>& arr, int n, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i; 

    if (l < n && arr[l] < arr[i])
    {
        largest = l;
    }
    
    if (r < n && arr[r] < arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        InverseHeapify(arr, n, largest);
    }
}

void InverseBuildHeap(vector<int>& arr)
{
    int n = arr.size();

    for (int i = n/2; i >= 0; i--)
    {
        InverseHeapify(arr, n, i);
    }
}

void InverseHeapSort(vector<int>& arr)
{
    InverseBuildHeap(arr);

    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        InverseHeapify(arr, i, 0);
    }        
}

auto GetTimeTakenFromAlg(vector<int>& arr, void (*func)(vector<int>& arr)) 
{
    auto start = high_resolution_clock::now();

    if (func == &UseMergeSort)
    {
        start = high_resolution_clock::now();
        arr = MergeSort(arr);
    }
    else if (func == &UseInverseMergeSort)
    {
        start = high_resolution_clock::now();
        arr = InverseMergeSort(arr);
    }
    else if (func == &UseQuickSort)
    {
        start = high_resolution_clock::now();
        QuickSort(arr, 0, arr.size() - 1);
    }
    else if (func == &UseInverseQuickSort)
    {
        start = high_resolution_clock::now();
        InverseQuickSort(arr, 0, arr.size() - 1);
    }
    else
    {
        start = high_resolution_clock::now();
        func(arr);
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}

// double GetTimeTakenFromAlg(vector<int>& arr, void (*func)(vector<int>& arr)) 
// {
//     time_t start, end;
//     double time_taken;

//     if (func == &UseMergeSort)
//     {
//         time(&start);
//         ios_base::sync_with_stdio(false);
        
//         arr = MergeSort(arr);
        
//         time(&end);
//         time_taken = double(end - start);
//     }
//     else if (func == &UseInverseMergeSort)
//     {
//         time(&start);
//         ios_base::sync_with_stdio(false);
        
//         arr = InverseMergeSort(arr);
        
//         time(&end);
//         time_taken = double(end - start);
//     }
//     else if (func == &UseQuickSort)
//     {
//         time(&start);
//         ios_base::sync_with_stdio(false);
        
//         QuickSort(arr, 0, arr.size() - 1);
        
//         time(&end);
//         time_taken = double(end - start);
//     }
//     else if (func == &UseInverseQuickSort)
//     {
//         time(&start);
//         ios_base::sync_with_stdio(false);
        
//         InverseQuickSort(arr, 0, arr.size() - 1);
        
//         time(&end);
//         time_taken = double(end - start);
//     }
//     else
//     {
//         time(&start);
//         ios_base::sync_with_stdio(false);
        
//         func(arr);
        
//         time(&end);
//         time_taken = double(end - start);
//     }
    
//     return time_taken;
// }

bool IsNumber(string s) //Funcion para saber si un string entregado es un número o no
{
	for (int i = 0; i < s.length(); i++ ) 
	{
		if (!isdigit(s[i])) 
		{
			return false;
		}
	}
	return true;
}

int GetMax(int inf, int sup)
{
    return inf + (rand() % (sup - inf));
}

vector<int> CreateRandomArray(vector<int> numbers, vector<int> vector)
{
    while (numbers.size() != 0)
    {
        int random = rand() % numbers.size();
        vector.push_back(numbers[random]);
        numbers.erase(numbers.begin() + random);
    }

    return vector;
}

int main(int argc, char* argv[]) 
{
    srand(time(NULL));

    list<int> infs;
    list<int> sups;

    ifstream file("Config.txt");

    if (file.is_open())
    {
        string line;
        string min;
        string max;
        int i = 0;

        while(getline(file, line))
        {
            stringstream ss(line);

            getline(ss, min, ',');
            if (!IsNumber(min))
			{
				cout << "Hubo un problema al leer el archivo, ya que se encontro con algo que no es un numreo" << endl
                << "Corrija el archivo <Config.txt>" << endl;
				return 0;
			}
            infs.push_back(stoi(min));

            getline(ss, max, ',');
            if (!IsNumber(max))
			{
				cout << "Hubo un problema al leer el archivo, ya que se encontro con algo que no es un numreo" << endl
                << "Corrija el archivo <Config.txt>" << endl;
				return 0;
			}
            sups.push_back(stoi(max));

            i++;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    file.close();

    int maxRace1 = GetMax(infs.front(), sups.front());
    infs.pop_front();
    sups.pop_front();
    int maxRace2 = GetMax(infs.front(), sups.front());
    infs.pop_front();
    sups.pop_front();
    int maxRace3 = GetMax(infs.front(), sups.front());

    int op;
    bool asc;

    cout << "Carreras de Algoritmos: " << endl << "1. Ascendente" << endl << "2. Descendente" << endl << "Opcion elegida: ";
    cin >> op;

    if (op != 1 && op != 2)
    {
        op = 1;
    }

    if (op == 1)
    {
        asc = true;
    }
    else
    {
        asc = false;
    }

    cout << "Generando set de datos..." << endl;

    vector<int> ascArray;
    vector<int> descArray;
    vector<int> randomWithRepArray;
    vector<int> randomArray;
    
    for (int i = 0; i < maxRace1 ; ++i) 
    {
        ascArray.push_back(i + 1);
        descArray.push_back(maxRace1 - i);
        int random = 1 + rand() % (maxRace1);
        randomWithRepArray.push_back(random);
    }

    vector<int> numbers;
    numbers.assign(ascArray.begin(), ascArray.end());
    randomArray = CreateRandomArray(numbers, randomArray);

    cout << "Set de datos generados" << endl << endl 
    << "\tInician las carreras" << endl;

    unordered_map<string, duration<double>> results;
    int id;
    float minTime;
    string minTimeAlg;

    if (asc)
    {
        //INICIO DE LAS CARRERAS DEL TABLERO
        cout << endl << "************************************************************" << endl;

        cout << endl << "Carrera del tablero: Modo ordenado" << endl << endl;
        
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera del tablero: Modo inversamente ordenado" << endl << endl;

        numbers.assign(descArray.begin(), descArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera del tablero: Modo aleatorio con repeticion" << endl << endl;

        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera del tablero: Modo aleatorio sin repeticion" << endl << endl;

        numbers.assign(randomArray.begin(), randomArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        //INICIO CARRERA DE LOS CAMINOS ENTRE ALDEAS
        cout << endl << "************************************************************" << endl;

        ascArray.clear();
        descArray.clear();
        randomWithRepArray.clear();
        randomArray.clear();

        for (int i = 0; i < maxRace2 ; ++i) 
        {
            ascArray.push_back(i + 1);
            descArray.push_back(maxRace2 - i);
            int random = 1 + rand() % (maxRace2);
            randomWithRepArray.push_back(random);
        }

        numbers.assign(ascArray.begin(), ascArray.end());
        randomArray = CreateRandomArray(numbers, randomArray);

        cout << endl << "Carrera de los caminos entre aldeas: Modo ordenado" << endl << endl;

        numbers.assign(ascArray.begin(), ascArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de los caminos entre aldeas: Modo inversamente ordenado" << endl << endl;

        numbers.assign(descArray.begin(), descArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de los caminos entre aldeas: Modo aleatorio con repeticion" << endl << endl;

        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;


        cout << endl << "Carrera de los caminos entre aldeas: Modo aleatorio sin repeticion" << endl << endl;

        numbers.assign(randomArray.begin(), randomArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;


        //INICIO DE LAS CARRERAS DE OBJETOS DEL INVENTARIO
        cout << endl << "************************************************************" << endl;

        ascArray.clear();
        descArray.clear();
        randomWithRepArray.clear();
        randomArray.clear();

        for (int i = 0; i < maxRace3 ; ++i) 
        {
            ascArray.push_back(i + 1);
            descArray.push_back(maxRace3 - i);
            int random = 1 + rand() % (maxRace3);
            randomWithRepArray.push_back(random);
        }

        numbers.assign(ascArray.begin(), ascArray.end());
        randomArray = CreateRandomArray(numbers, randomArray);

        cout << endl << "Carrera de objetos del inventario: Modo ordenado" << endl << endl;

        numbers.assign(ascArray.begin(), ascArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de objetos del inventario: Modo inversamente ordenado" << endl << endl;

        numbers.assign(descArray.begin(), descArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de objetos del inventario: Modo aleatorio con repeticion" << endl << endl;

        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de objetos del inventario: Modo aleatorio sin repeticion" << endl << endl;

        numbers.assign(randomArray.begin(), randomArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &SelectionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &BubbleSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InsertionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &ShellSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseMergeSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseQuickSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &HeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

    }
    else
    {
        cout << endl << "Carrera del tablero: Modo ordenado" << endl << endl;

        numbers.assign(descArray.begin(), descArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera del tablero: Modo inversamente ordenado" << endl << endl;

        numbers.assign(ascArray.begin(), ascArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera del tablero: Modo aleatorio con repeticion" << endl << endl;

        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera del tablero: Modo aleatorio sin repeticion" << endl << endl;

        numbers.assign(randomArray.begin(), randomArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;


        //INICIO CARRERA DE LOS CAMINOS ENTRE ALDEAS
        cout << endl << "************************************************************" << endl;

        ascArray.clear();
        descArray.clear();
        randomWithRepArray.clear();
        randomArray.clear();

        for (int i = 0; i < maxRace2 ; ++i) 
        {
            ascArray.push_back(i + 1);
            descArray.push_back(maxRace2 - i);
            int random = 1 + rand() % (maxRace2);
            randomWithRepArray.push_back(random);
        }

        numbers.assign(ascArray.begin(), ascArray.end());
        randomArray = CreateRandomArray(numbers, randomArray);

        cout << endl << "Carrera de los caminos entre aldeas: Modo ordenado" << endl << endl;

        numbers.assign(descArray.begin(), descArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de los caminos entre aldeas: Modo inversamente ordenado" << endl << endl;

        numbers.assign(ascArray.begin(), ascArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de los caminos entre aldeas: Modo aleatorio con repeticion" << endl << endl;

        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de los caminos entre aldeas: Modo aleatorio sin repeticion" << endl << endl;

        numbers.assign(randomArray.begin(), randomArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        //INICIO DE LAS CARRERAS DE OBJETOS DEL INVENTARIO
        cout << endl << "************************************************************" << endl;

        ascArray.clear();
        descArray.clear();
        randomWithRepArray.clear();
        randomArray.clear();

        for (int i = 0; i < maxRace3 ; ++i) 
        {
            ascArray.push_back(i + 1);
            descArray.push_back(maxRace3 - i);
            int random = 1 + rand() % (maxRace3);
            randomWithRepArray.push_back(random);
        }

        numbers.assign(ascArray.begin(), ascArray.end());
        randomArray = CreateRandomArray(numbers, randomArray);

        cout << endl << "Carrera de objetos del inventario: Modo ordenado" << endl << endl;

        numbers.assign(descArray.begin(), descArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(descArray.begin(), descArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de objetos del inventario: Modo inversamente ordenado" << endl << endl;

        numbers.assign(ascArray.begin(), ascArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(ascArray.begin(), ascArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de objetos del inventario: Modo aleatorio con repeticion" << endl << endl;

        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(randomWithRepArray.begin(), randomWithRepArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;

        cout << endl << "Carrera de objetos del inventario: Modo aleatorio sin repeticion" << endl << endl;

        numbers.assign(randomArray.begin(), randomArray.end());
        results["Seleciont Sort"] = GetTimeTakenFromAlg(numbers, &InverseSelectionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Bubble Sort"] = GetTimeTakenFromAlg(numbers, &InverseBubbleSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Insertion Sort"] = GetTimeTakenFromAlg(numbers, &InverseInsertionSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Shell Sort"] = GetTimeTakenFromAlg(numbers, &InverseShellSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Merge Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseMergeSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Quick Sort"] = GetTimeTakenFromAlg(numbers, &UseInverseQuickSort);
        numbers.assign(randomArray.begin(), randomArray.end());
        results["Heap Sort"] = GetTimeTakenFromAlg(numbers, &InverseHeapSort);

        id = 1;
        minTime = 1000000;
        
        for (const auto& pair : results) 
        {
            const string& key = pair.first;
            duration<double> value = pair.second;
            cout << id << ". " << key << ", " << value.count() << endl;
            if (value.count() < minTime)
            {
                minTime = value.count();
                minTimeAlg = key;
            }
            id++;
        }

        cout << endl << "El algoritmo con el menor tiempo fue " << minTimeAlg << " con " << minTime << " segundos" << endl;
    }

    return 0;
}
