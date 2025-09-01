#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		Cat*	cat = new Cat();
		Cat		c1(*cat);
		Cat		c2;

		c2 = c1;
		c2.setBrainIdea(66, "Dogs are bad");
		cat->setBrainIdea(-1, "Big idea");
		cat->setBrainIdea(0, "1+1=3");
		std::cout << cat->getBrainIdea(0) << std::endl;
		std::cout << c1.getBrainIdea(0) << std::endl;
		std::cout << c1.getBrainIdea(66) << std::endl;
		std::cout << c2.getBrainIdea(66) << std::endl;
		delete cat;
	}
	std::cout << "===========================================================\n";
	{
		int	size = 10;
		const AAnimal* animals[size];
		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();
		for (int i = 0; i < size; i++)
		{
			std::cout << "Animal " << i << " type: " << animals[i]->getType() << " -> ";
			animals[i]->makeSound();
			std::cout << std::endl;
		}
		for (int i = 0; i < size; i++)
			delete animals[i];
	}
	return (0);
}
