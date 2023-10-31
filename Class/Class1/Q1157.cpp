#include <iostream>
#include <cstring>

int main()
{
	size_t alphabet[26] = {};

	char str[1000001] = {};
	std::cin.getline(str, 1000001);

	size_t length = strlen(str);

	for (size_t index = 0; index < length; ++index)
	{
		if (islower(str[index]))
		{
			str[index] = str[index] - 'a' + 'A';
		}

		char checkedAlphabetIndex = str[index];
		checkedAlphabetIndex -= 'A';

		++(alphabet[static_cast<size_t>(checkedAlphabetIndex)]);
	}

	size_t maximumUse1 = 0;
	size_t pos1 = 0;
	for (size_t index = 0; index < 26; ++index)
	{
		if (maximumUse1 < alphabet[index])
		{
			maximumUse1 = alphabet[index];
			pos1 = index;
		}
	}

	size_t maximumUse2 = 0;
	size_t pos2 = 0;
	for (size_t index = 0; index < 26; ++index)
	{
		if ((index != pos1) && maximumUse2 < alphabet[index])
		{
			maximumUse2 = alphabet[index];
			pos2 = index;
		}
	}

	if (pos1 != pos2 && maximumUse1 == maximumUse2)
	{
		std::cout << '?';
	}
	else
	{
		char outputChar = 'A';
		if (maximumUse1 > maximumUse2)
		{
			outputChar += static_cast<char>(pos1);
		}
		else
		{
			outputChar += static_cast<char>(pos2);
		}

		std::cout << outputChar;
	}

	return 0;
}