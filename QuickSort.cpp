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

using namespace std;

void PrintVector(vector<int> vector)
{
    for (int i : vector)
    {
        cout << i << " ";
    }
    cout << endl;
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

double GetTimeTakenFromAlg(vector<int>& arr, void (*func)(vector<int>& arr)) 
{
    time_t start, end;
    double time_taken;

    time(&start);
    ios_base::sync_with_stdio(false);
    
    QuickSort(arr, 0, arr.size() - 1);
    
    time(&end);
    time_taken = double(end - start);
    return time_taken;
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

int main()
{
    int maxRace1 = 100000; //Cambiar al valor deseado
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

    double time_taken;

    vector<int> numbers;

    cout << "inicio Ordenamiento" << endl;

    numbers.assign(ascArray.begin(), ascArray.end()); //Asignarle a numbers los distintos arreglos
    randomArray = CreateRandomArray(numbers, randomArray);

    time_taken = GetTimeTakenFromAlg(numbers, &UseQuickSort);

    cout << fixed << time_taken << setprecision(5) << endl;

    return 0;
}