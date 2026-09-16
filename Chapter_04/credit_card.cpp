#include <iostream>

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int digit);
int getSize(long long number);
long long getPrefix(long long number, int k);

bool isValid(long long number)
{
    const int size = getSize(number);

    return size >= 13 && size <= 16 &&
           (prefixMatched(number, 4) || prefixMatched(number, 5) ||
            prefixMatched(number, 37) || prefixMatched(number, 6)) &&
           (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    number /= 10;

    while (number > 0)
    {
        sum += getDigit(static_cast<int>((number % 10) * 2));
        number /= 100;
    }

    return sum;
}

int getDigit(int number)
{
    return number < 10 ? number : number / 10 + number % 10;
}

int sumOfOddPlace(long long number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += static_cast<int>(number % 10);
        number /= 100;
    }

    return sum;
}

bool prefixMatched(long long number, int digit)
{
    if (digit == 37)
    {
        return getPrefix(number, 2) == 37;
    }

    return getPrefix(number, 1) == digit;
}

int getSize(long long number)
{
    int size = 0;

    do
    {
        ++size;
        number /= 10;
    } while (number > 0);

    return size;
}

long long getPrefix(long long number, int k)
{
    const int size = getSize(number);

    for (int digits_to_remove = size - k; digits_to_remove > 0; --digits_to_remove)
    {
        number /= 10;
    }

    return number;
}

int main()
{
    long long number;
    std::cout << "Enter a credit card number: ";
    std::cin >> number;

    std::cout << number << (isValid(number) ? " is valid.\n" : " is invalid.\n");

    return 0;
}
