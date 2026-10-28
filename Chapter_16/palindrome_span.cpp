import std;
using namespace std;

bool is_palindrome(span<char> s)
{
    if (s.size() <= 1)
        return true;

    if (s.front() != s.back())
        return false;

    return is_palindrome(s.subspan(1, s.size() - 2));
}

int main()
{
    char word[] = "level";

    cout << boolalpha
         << is_palindrome(span<char>{word, strlen(word)})
         << '\n';
}