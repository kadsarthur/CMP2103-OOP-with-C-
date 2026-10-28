import std;
using namespace std;

int sum(span<int> s)
{
	int s = 0;
	for(int x : s)
		s += x;
	return s;
}

int arr[100];
// …
int r = sum(arr);

int main()
{
    int arr[100];
    // …
    int r = sum(arr);
}