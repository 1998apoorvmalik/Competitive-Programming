/* 
------------------------------------------------------------------------------------------------------
Link:                   https://www.hackerearth.com/problem/algorithm/monk-and-rotation-3-bcf1aefe/
Title:                  Monk and Rotation
Problem Description:    Shift an array by a required number n.
Author:                 Apoorv Malik
Date:                   3rd April, 2021
------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArray(vector<int> arr)
{
    for (const int &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> rotateArray(vector<int> arr, int offset)
{
    vector<int> newArr = arr;
    for (int i = 0; i < arr.size(); i++)
    {
        offset = offset % arr.size();
        int newIndex = i + offset;
        if (newIndex >= arr.size())
        {
            newIndex -= arr.size();
        }
        newArr[newIndex] = arr[i];
    }
    return newArr;
}

int main()
{
    int T, N, K;
    vector<int> arr;
    cin >> T;

    while (T--)
    {
        cin >> N;
        cin >> K;

        for (int i = 0; i < N; i++)
        {
            int nextElement;
            cin >> nextElement;
            arr.push_back(nextElement);
        }
        printArray(rotateArray(arr, K));
        arr.clear();
    }
}
