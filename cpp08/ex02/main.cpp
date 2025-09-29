#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int	main()
{
	{
		MutantStack<int>	d;
		d.push(10);
		d.push(2);

		MutantStack<int>	s = d;

		std::cout << &d.top() << " = " << d.top() << std::endl;
		std::cout << &s.top() << " = " << s.top() << std::endl;
	}
	std::cout << "=============================\n";
	{
		MutantStack<int>	s;
		//std::stack<int>			badStack;
		
		//badStack.push(2);
		//badStack.push(9);
		//badStack.push(22);
		s.push(1);
		s.push(2);
		s.push(6);
		//std::stack<int>::iterator it = badStack.begin();
		for(MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "==================================\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	return 0;
}
