#include <iostream>
#include <vector>
#include <string>

struct pair_pos
{
	int x;
	int y;
}pair_pos;

class Stack_ex
{
public:
	Stack_ex()
	{
		size = 0;
	}
	void addParenthese(int k1)
	{
		position.push_back(k1);
		++size;
	}
	int popParenthese()
	{
		int temp = 0;
		if (size > 0)
		{
			temp = position[size - 1];
			position.pop_back();
			--size;
			return temp;
		}
		else
			return -1;
		
	}
private:
	int size;
	std::vector<int> position;
};

int main(void)
{
	Stack_ex sample1;
	std::string input1 = "";
	std::cin >> input1;
	std::vector<struct pair_pos> pos1;
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < input1.size(); ++i)
	{
		if (input1[i] == '(')
			++temp1;
		else if (input1[i] == ')')
			++temp2;
	}
	if (temp1 != temp2)
	{
		std::cout << "not match" << std::endl;
		return 0;
	}

	for (int i = 0; i < input1.size(); ++i)
	{
		if (input1[i] == '(')
		{
			sample1.addParenthese(i);
		}
		else if (input1[i] == ')')
		{
			int temp = sample1.popParenthese();
			if (temp < 0)
			{
				std::cout << "not match" << std::endl;
				return 0;
			}
			std::cout << temp << " " << i << std::endl;
		}
	}
	return 0;
	
}