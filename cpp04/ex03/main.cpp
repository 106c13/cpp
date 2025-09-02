#include <iostream>
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "===============================================\n";
	{
		Character pl1 = Character("Karlos");

		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		AMateria* m1 = src->createMateria("ice");
		AMateria* m2 = src->createMateria("cure");

		pl1.equip(m1);
		pl1.equip(m1);
		pl1.equip(m2);

		Character pl2;
		
		pl2 = pl1;
		pl2.use(0, pl1);
		pl2.use(3, pl1);

		delete src;
	}
	return 0;
}
