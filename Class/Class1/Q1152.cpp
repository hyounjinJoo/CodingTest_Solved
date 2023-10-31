#include <iostream>
#include <cstring>

int main()
{
	char str[1000001];
	std::cin.getline(str, 1000001);

	size_t length = std::strlen(str);

	int countWord = 0;
	size_t index = 0;
	if (' ' == str[index])
	{
		++index;
	}

	for (; index < length; ++index)
	{
		if (' ' == str[index] || index == (length - 1))
		{
			++countWord;
		}
	}

	std::cout << countWord;

	return 0;
}