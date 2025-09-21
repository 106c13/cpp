#include <iostream>
#include <array>
#include <string>
#include <exception>

bool	isInteger(const std::string& s){
	size_t	pos;
	int		num;

	try {
		num = std::stoi(s, &pos);
		return pos == s.length() && num > 0;
	} catch (const std::exception& e) {
		return false;
	}
}

bool	validate(int argc, char **argv) {
	int	i = 1;

	while (i < argc) {
		if (!isInteger(argv[i]))
			return false;
		i++;
	}
	return true;
}

int	main(int argc, char **argv) {
	std::array<int, 6>	nums;

	if (!validate(argc, argv)) {
		std::cout << "Error\n";
		return 1;
	}
	std::cout << "Cool\n";
	return 0;
}
