#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countEdgeOneBits(string binaryNumber, string start = "left")
{
    int numOneBits = 0;

    if (start == "left")
    {
        for (int i = 0; i < binaryNumber.size(); i++)
        {
            if (binaryNumber[i] == '0')
                break;
            numOneBits++;
        }
    }
    else
    {
        for (int i = binaryNumber.size() - 1; i <= 0; i--)
        {
            if (binaryNumber[i] == '0')
                break;
            numOneBits++;
        }
    }

    return numOneBits;
}

string performCyclicShift(string binaryNumber)
{
    string shiftedBinaryNumber = binaryNumber.substr(1, binaryNumber.size() - 1);
    shiftedBinaryNumber.push_back(binaryNumber[0]);
    return shiftedBinaryNumber;
}

// Brute force approach.
vector<string> findMaxBinaryUsingCyclicShift(string binaryNumber)
{
    long long int nShifts = 0;
    string maxSoFar = binaryNumber;
    string newNum = binaryNumber;

    for (long long int i = 0; i < binaryNumber.size(); i++)
    {
        newNum = performCyclicShift(newNum);
        if (countEdgeOneBits(newNum) > countEdgeOneBits(maxSoFar))
        {
            maxSoFar = newNum;
            nShifts = i + 1;
        }
    }

    vector<string> output{maxSoFar, to_string(nShifts)};

    return output;
}

long long int findCyclicShiftStepsToNextOccurence(string binaryNumber)
{
    long long int nShifts = 0;
    string nextNum = binaryNumber;
    while (1)
    {
        nextNum = performCyclicShift(nextNum);
        nShifts++;

        if (nextNum == binaryNumber && nShifts > 0)
        {
            return nShifts;
        }
    }
}

void runProgram(string binaryNumber, long long int K)
{
    vector<string> _output = findMaxBinaryUsingCyclicShift(binaryNumber);

    string maxBinaryNumber = _output[0];
    long long int sum = stoi(_output[1]);

    sum += findCyclicShiftStepsToNextOccurence(maxBinaryNumber) * (K - 1);

    // cout << maxBinaryNumber << endl;
    cout << sum << endl;
}

int main()
{
    long long int T, N, K;
    string binaryNumber;

    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        cin >> binaryNumber;
        runProgram(binaryNumber, K);
    }
}