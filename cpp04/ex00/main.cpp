#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		Dog*	dog = new Dog();
		Cat		cat;

		cat.makeSound();
		dog->makeSound();
		delete dog;
	}
	std::cout << "=======================================\n";
	{
		Animal*	animals[2];
		animals[0] = new Dog();
		animals[1] = new Cat();

		animals[0]->makeSound();
		animals[1]->makeSound();
		delete animals[0];
		delete animals[1];
	}
	std::cout << "=======================================\n";
	{
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
	}
	std::cout << "=======================================\n";
	{
		WrongAnimal*	cat = new WrongCat();
		WrongAnimal*	anim = new WrongAnimal();

		cat->makeSound();
		anim->makeSound();

		delete cat;
		delete anim;
	}
	return (0);
}
