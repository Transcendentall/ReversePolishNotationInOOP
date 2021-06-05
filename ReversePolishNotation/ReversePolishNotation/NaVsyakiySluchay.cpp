#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

class Operation
{

private:

public:
    char symbol = 0;
    unsigned short int priority = 0;

    int res(int a, int b)
    {
        return -1;
    }

protected:
};

class Plus: public Operation
{

private:

public:

    Plus()
    {
        this->symbol = '+';
        this->priority = 1;
    };

    int res(int a, int b)
    {
        return (a + b);
    }

protected:

};

class Minus : public Operation
{

private:

public:

    Minus()
    {
        this->symbol = '-';
        this->priority = 1;
    };

    int res(int a, int b)
    {
        return (a - b);
    }

protected:

};

class Umnozhit : public Operation
{

private:

public:

    Umnozhit()
    {
        this->symbol = '*';
        this->priority = 2;
    };

    int res(int a, int b)
    {
        return (a * b);
    }

protected:

};

class Razdelit : public Operation
{

private:

public:

    Razdelit()
    {
        this->symbol = '/';
        this->priority = 2;
    };

    int res(int a, int b)
    {
        return (a / b);
    }

protected:

};





struct SymbolLink
{
    char symb = ' ';
    Operation* link;
};

const unsigned short int MaxCountOfOperations = 20;

Operation* o[MaxCountOfOperations];
SymbolLink symbolmass[MaxCountOfOperations] = {};



int SymbolContained(char ab)
{
    for (unsigned short int i = 0; i < MaxCountOfOperations; ++i)
    {
        if (symbolmass[i].symb == ab)
        {
            return i;
        }
    }
    return -1;
}

int ReversePolishNotationFunction(char* input) 
{


    for (unsigned short int i = 0; i < MaxCountOfOperations; ++i) 
    {
        o[i] = 0; // зачистка мусора
        symbolmass[i].symb = ' ';
    }

    
    

    Plus* op0 = new Plus();  // тут подключаются операции
    o[0]   = op0;
    symbolmass[0].symb = op0->symbol;
    symbolmass[0].link = op0;

    Minus* op1 = new Minus();
    o[1] = op1;
    symbolmass[1].symb = op1->symbol;
    symbolmass[1].link = op1;

    Umnozhit* op2 = new Umnozhit();
    o[2] = op2;
    symbolmass[2].symb = op2->symbol;
    symbolmass[2].link = op2;

    Razdelit* op3 = new Razdelit();
    o[3] = op3;
    symbolmass[3].symb = op3->symbol;
    symbolmass[3].link = op3;










    stack <char> steck;
    stack <char> steck2;

    int otvet;
    const int N = 200;
    char output[N];
    otvet = 0;
    int j = 0;
    for (j = 0; j < N; ++j)
    {
        output[j] = 0;
    }
    int i = 0;
    int istack = 0;
    int ioutput = 0;
    while (input[i] != 0)
    {
//        cout << sym[0] << endl;
        if (((input[i] >= 48) && (input[i] <= 57)))
        {
            output[ioutput] = input[i];
            ++ioutput;
        }
        else
        {
            if (input[i] == '(')
            {
                    steck.push(input[i]);
                    ++istack;
            }
            else
            {
                if (input[i] == ')')
                {
                    while (steck.top() != '(')
                    {
                        output[ioutput] = steck.top();
                        ++ioutput;
                        steck.pop();
                        --istack;
                    }
                    steck.pop();
                    --istack;
                }
                else
                {
                    if (input[i] != ' ')
                    {
                        if (SymbolContained(input[i])!=-1)
                        {
                            cout << "aw " << istack << endl;

                            if (istack > 0)
                            {
                                cout << "aa " << steck.top() << endl;

                                cout << "as " << ((symbolmass[SymbolContained(steck.top())]).link->priority) << endl;
                                cout << "ad " << ((symbolmass[SymbolContained(input[i])]).link->priority) << endl;
                                while (((symbolmass[SymbolContained(steck.top())]).link->priority) >= ((symbolmass[SymbolContained(input[i])]).link->priority))
                                {
                                    output[ioutput] = steck.top();
                                    ++ioutput;
                                    steck.pop();
                                    --istack;
                                }
                            }

                            steck.push(input[i]);
                            ++istack;  
                        }
                    }
                }
            }
        }
        ++i;
        cout << output << endl << endl << endl;
    }

    while (istack>0)
    {
        output[ioutput] = steck.top();
        ++ioutput;
        steck.pop();
        --istack;
    }



    cout << output << endl << endl << endl;
    cout << symbolmass[0].link->priority << endl;
    cout << symbolmass[1].link->priority << endl;
    cout << symbolmass[2].link->priority << endl;
    cout << symbolmass[3].link->priority << endl;
    cout << symbolmass[0].link->symbol << endl;
    cout << symbolmass[1].link->symbol << endl;
    cout << symbolmass[2].link->symbol << endl;
    cout << symbolmass[3].link->symbol << endl;
    cout << op0->res(2, 2) << endl;
    cout << op1->res(2, 2) << endl;
    cout << symbolmass[2].link->res(2, 2) << endl;
    cout << symbolmass[3].link->res(2, 2) << endl;

 //   return (int)steck2.top();

}