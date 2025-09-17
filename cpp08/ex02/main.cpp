#include <iostream>
#include <stack>

int	main()
{
	std::stack<int> A;

	A.push(1);
	std::cout << &A << std::endl;
	std::cout << A.top() << "   " << &A.top() << std::endl;
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	A.push(1);
	std::cout << &A << std::endl;
	std::cout << A.top() << "   " << &A.top() << std::endl;
	A.push(2);
	std::cout << &A << std::endl;
	std::cout << A.top() << "   " << &A.top() << std::endl;
	A.pop();
	std::cout << &A << std::endl;
	std::cout << A.top() << "   " << &A.top() << std::endl;

	return 0;
}
