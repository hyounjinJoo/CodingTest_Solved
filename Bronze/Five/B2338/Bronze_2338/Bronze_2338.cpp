// Bronze_2338.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>



// 1000자리 수를 2개 입력받아서
// +, -, * 처리
// 1000자리이므로 C++ 제공 타입은 사용할 수 없음.
// char 1000크기의 배열을 선언하고 받는다.

void CheckSign(const char& number, char& signNum);
char isAbsoluteBiggerLeft(const char* num1, const char* num2);
void Add(const char* num1, const char* num2, const char& signNum1, const char& signNum2);
void Minus(const char* num1, const char* num2, const char& signNum1, const char& signNum2);
void Multiply(const char* num1, const char* num2, const char& signNum1, const char& signNum2);

enum eSign
{
	Plus = 0,
	Minus = 1,
};

enum eBiggerResult
{
	Equal = 0,
	LeftBig = 1,
	RightBig = 2,
};

int main()
{
	char num1[1001] = {};
	char num2[1001] = {};

	char signNum1 = 0;
	char signNum2 = 0;

	std::cin >> num1 >> num2;

	CheckSign(num1[0], signNum1);
	CheckSign(num2[0], signNum2);

	Add(num1, num2, signNum1, signNum2);


	return 0;
}

void CheckSign(const char& number, char& signNum)
{
	if (number == '-')
	{
		signNum = 1;
	}
	else
	{
		signNum = 0;
	}
}

char isAbsoluteBiggerLeft(const char* num1, const char* num2)
{
	size_t sizeOfNum1 = std::strlen(num1);
	size_t sizeOfNum2 = std::strlen(num2);

	char result = 0;

	if (sizeOfNum1 > sizeOfNum2)
	{
		result = static_cast<char>(eBiggerResult::LeftBig);
	}
	else if (sizeOfNum1 < sizeOfNum2)
	{
		result = static_cast<char>(eBiggerResult::RightBig);
	}
	else
	{
		for (size_t index = 0; index < sizeOfNum1; ++index)
		{
			if (num1[index] > num2[index])
			{
				result = static_cast<char>(eBiggerResult::LeftBig);
				break;
			}
			else if(num2[index] < num2[index])
			{
				result = static_cast<char>(eBiggerResult::RightBig);
				break;
			}
		}
	}

	return result;
}

void Add(const char* num1, const char* num2, const char& signNum1, const char& signNum2)
{
	int signResult = signNum1 + signNum2;
	// 더해서 1이면 한쪽이 음수
	// 더해서 0이면 둘다 양수
	// 더해서 2이면 둘다 음수


}

void Minus(const char* num1, const char* num2, const char& signNum1, const char& signNum2)
{
}

void Multiply(const char* num1, const char* num2, const char& signNum1, const char& signNum2)
{
}
