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

//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c++

void SelectionSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n ; ++i) 
    {
        for (int j = i; j < n ; ++j) 
        {
            if (arr[j] < arr[i]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double getResultFromAlg(vector<int>& arr,int option) 
{
    time_t start, end;
    double time_taken;

    time(&start);
    ios_base::sync_with_stdio(false);
    
    SelectionSort(arr);
    
    time(&end);
    time_taken = double(end - start);
    
    return time_taken;
}

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

void PrintVector(vector<int> vector)
{
    for (int i : vector)
    {
        cout << i << " ";
    }
    cout << endl;
}

void CreateRandomArray(vector<int> numbers, vector<int> vector)
{
    int max = numbers.size();

    for (int i = 0; i < max; i++)
    {
        int random = rand() % numbers.size();
        vector.push_back(numbers[random]);
        numbers.erase(vector.begin() + random);
        PrintVector(vector);
    }
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

    int maxRace1 = GetMax(infs.front(), sups.front());
    infs.pop_front();
    sups.pop_front();
    int maxRace2 = GetMax(infs.front(), sups.front());
    infs.pop_front();
    sups.pop_front();
    int maxRace3 = GetMax(infs.front(), sups.front());
    infs.pop_front();
    sups.pop_front();

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
    vector<int> randomArray;
    vector<int> randomWithRepArray;

    int random;
    
    for (int i = 0; i < maxRace1 ; ++i) 
    {
        ascArray.push_back(i + 1);
        descArray.push_back(maxRace1 - i);
        int random = 1 + rand() % (maxRace1);
        randomWithRepArray.push_back(random);
    }

    PrintVector(ascArray);
    PrintVector(descArray);
    PrintVector(randomWithRepArray);

    vector<int> numbers;
    numbers.assign(ascArray.begin(), ascArray.end());

    PrintVector(numbers);

    CreateRandomArray(numbers, randomArray);

    PrintVector(randomArray);

    return 0;
}
