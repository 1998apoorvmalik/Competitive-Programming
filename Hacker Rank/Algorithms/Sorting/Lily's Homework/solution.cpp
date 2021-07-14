#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int findSwaps(vector<int> &sortedArr, vector<int> &unsortedArr)
{
    map<int, vector<int>> arrValueIndexMap;
    int nSwaps = 0;

    // Mapping each value of the sorted array to its corresponding index.
    for (int i = 0; i < sortedArr.size(); i++)
    {
        if (arrValueIndexMap.find(sortedArr[i]) == arrValueIndexMap.end())
        {
            vector<int> temp{i};
            arrValueIndexMap[sortedArr[i]] = temp;
        }
        else
        {
            arrValueIndexMap[sortedArr[i]].push_back(i);
        }
    }

    // Finding number of swaps to convert the unsorted array to sorted.
    for (int i = 0; i < unsortedArr.size(); i++)
    {
        while (unsortedArr[i] != sortedArr[i])
        {
            int j = arrValueIndexMap[unsortedArr[i]].back();
            arrValueIndexMap[unsortedArr[i]].pop_back();
            nSwaps++;

            int temp = unsortedArr[i];
            unsortedArr[i] = unsortedArr[j];
            unsortedArr[j] = temp;
        }
    }

    return nSwaps;
}

int lilysHomework(vector<int> &arr)
{
    vector<int> unsortedArr = arr;
    vector<int> unsortedArrRev = arr;

    sort(arr.begin(), arr.end());
    vector<int> sortedArr = arr;
    reverse(arr.begin(), arr.end());
    vector<int> sortedArrRev = arr;

    // Find number of swaps to convert the unsorted array to both sorted
    // and reverse sorted arrays.
    int nSwaps = findSwaps(sortedArr, unsortedArr);
    int nSwapsRev = findSwaps(sortedArrRev, unsortedArrRev);

    // Return whatever is minimum.
    return min(nSwaps, nSwapsRev);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
