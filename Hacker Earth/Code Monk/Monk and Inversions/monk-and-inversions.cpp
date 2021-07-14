/* 
------------------------------------------------------------------------------------------------------
Title:                  Monk and Inversions
Problem Description:    Find number of inversions in an matrix.
Author:                 Apoorv Malik
Date:                   4th April, 2021
------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr)
{
    for (const int &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix)
{
    for (vector<int> arr : matrix)
    {
        printArray(arr);
    }
}

vector<vector<int>> scanMatrix(int size)
{
    vector<vector<int>> matrix(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int element;
            cin >> element;
            matrix[i].push_back(element);
        }
    }

    return matrix;
}

int countInversionsBruteForce(vector<vector<int>> matrix)
{
    int count = 0;

    // Brute force approach.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            for (int p = i; p < matrix.size(); p++)
            {
                for (int q = j; q < matrix.size(); q++)
                {
                    if (matrix[i][j] > matrix[p][q])
                    {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<vector<int>> matrix = scanMatrix(size);
        cout << countInversionsBruteForce(matrix) << "\n";
    }
}