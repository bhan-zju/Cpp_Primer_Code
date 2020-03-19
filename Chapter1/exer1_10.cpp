#include <iostream>

int main()
{
	int sum = 0, val = 10;
	while (val >= 1) {
		sum += val;
		--val;
	}
	std::cout<< "Sum of 10 to 1 is "
			<< sum << std::endl;
	return 0;
}