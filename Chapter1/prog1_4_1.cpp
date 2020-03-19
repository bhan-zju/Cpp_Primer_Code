#include <iostream>

int main()
{
	int val = 1, sum = 0;
	while (val <= 10) {
		sum += val;  // sum = sum + val;
		++val;  // val = val + 1;
	}
	std::cout << "Sum of 1 to 10 is "
		      << sum << std::endl;
	return 0;
}