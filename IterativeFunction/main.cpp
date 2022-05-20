#include <iostream>
#include <stack>

using namespace std;

//Recursive function
int F(int n)
{
    if(n<=1) return 1;
    int a=n+F(n-1);
    int b=n*F(n/2);
    int c=n-2-(a+b)%2;
    int d=F(c);

    return a+b+d;

}

enum callType{callA,callB,callC,callD};

struct functionCall
{

    callType type=callA;
    int n; // Input n
    int result=1; // Final result
    int a=0; // n+F(n-1)
    int b=1; // n*F(n/2)
    int c=0; // n-2-(a+b)%2
    int d=0; // F(n)
};

int functionIterative(int n)
{
    // Stack of calls
    stack<functionCall> s;

    // Base call
    functionCall base;
    base.type=callA;
    base.n=n;
    base.a=0;
    base.b=1;
    base.c=0;
    base.d=0;
    base.result=1;

    s.push(base);

    while(!s.empty())
    {

        functionCall current=s.top(); s.pop();

       //base case n = 1
        if(current.n<=1)
        {
            if (n<=1)
            {
                return current.result;
            }

            if(!s.empty())
            {
                s.top().result=1;
            }
            continue;
        }

        if(current.type==callA)
        {
            current.type=callB;

            functionCall c1;
            c1.n=current.n-1;

            s.push(current);
            s.push(c1);
        }

        if(current.type==callB)
        {
            current.a=current.result+current.n;

            current.type=callC;

            functionCall c2;
            c2.n=current.n/2;

            s.push(current);
            s.push(c2);
        }

        if(current.type==callC)
        {
            current.b=current.result*current.n;

            current.type=callD;

            current.c=current.n-2-(current.a+current.b)%2;

            functionCall c3;
            c3.n=current.c;

            s.push(current);
            s.push(c3);
        }

        if(current.type==callD)
        {
            current.d=current.result;

            if(!s.empty())
            {
                s.top().result=current.a+current.b+current.d;
            }
            else
            {
                current.result=current.a+current.b+current.d;
                return current.result;
            }
        }
    }
}


int main()
{

/*
    cout << "Enter n: "; cin >> n;
    cout << "Recursive function: F(" << n << ")= " << F(n) << endl;
    cout << "Iterative function: F(" << n << ")= " << functionIterative(n) << endl;
*/



    cout << "Recursive function from 1 to 20: " << endl;
    for(int i=0;i<21;i++)
    {
        cout << "F(" << i << ")= " << F(i) << endl;
    }

    cout << "Iterative function from 1 to 20: " << endl;
    for(int i=0;i<21;i++)
    {
        cout << "F(" << i << ")= "  << functionIterative(i) << endl;
    }

    return 0;
}
