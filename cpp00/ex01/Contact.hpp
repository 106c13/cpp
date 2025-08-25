#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
public:
	Contact();
	~Contact() {};
	void				set_first_name(const std::string &first_name);
	void				set_last_name(const std::string &last_name);
	void				set_nickname(const std::string &nickname);
	void				set_phone(const std::string &phone);
	void				set_secret(const std::string &secret);
	const std::string&	get_first_name(void);
	const std::string&	get_last_name(void);
	const std::string&	get_nickname(void);
	const std::string&	get_phone(void);
	const std::string&	get_secret(void);
};

#endif
