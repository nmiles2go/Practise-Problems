# include <iostream>

int FibonacciCalls[21];

int fibonacciIteration(int);
int fibonacciRecursion(int);
int fibonacciMemoization(int);

int main()
{

    // Initializing the memoization array with -1
    for(int i{0}; i < 20; ++i)
    {
        FibonacciCalls[i] = -1;
    }



    std::cout << fibonacciIteration(5)    << std::endl;

    std::cout << fibonacciRecursion(5)    << std::endl;
    std::cout << fibonacciMemoization(10) << std::endl;
    return 0;
}

int fibonacciRecursion(int numTerms)
{
    if(numTerms < 2) return numTerms;

    else
    {
        return fibonacciRecursion(numTerms-2) + fibonacciRecursion(numTerms-1);
    }

}

int fibonacciMemoization(int numTerms)
{
    if(numTerms < 2) return numTerms;

    if(-1 == FibonacciCalls[numTerms])
    {
        FibonacciCalls[numTerms] = fibonacciMemoization(numTerms-2) + fibonacciMemoization(numTerms - 1);
        return FibonacciCalls[numTerms];
    }

    else
    {
        return FibonacciCalls[numTerms];
    }
}

int fibonacciIteration(int numTerms)
{
    int first  {0};
    int second {1};

    int sum {first + second};

    if (numTerms < 2) return numTerms;

    else
    {
        for(int i{2}; i <= numTerms; ++i)
        {
           sum = first + second;
           first = second;
           second = sum;
        }
        
        return sum;
    }
}