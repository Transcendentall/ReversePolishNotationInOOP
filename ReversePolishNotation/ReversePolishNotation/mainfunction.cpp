#include "pch.h"
#include <iostream>

using namespace std;


int main()
{
    char input[200];
    int j = 0;
    for (j = 0; j < 200; ++j)
    {
        input[j] = 0;
    }
    cout << "Input the expression, please (max 200 symbols) (for example,    2 / (3 - (4 + (5 * 6)))   ): " << endl;
    cin.getline((char*)input, 200);
    cout << endl << "______________________" << endl << endl << "Answer: " << endl << ReversePolishNotationFunction(input) << endl << endl;
}

