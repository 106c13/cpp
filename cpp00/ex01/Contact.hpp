#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
private:
  std::string  _first_name;
  std::string  _last_name;
  std::string  _nickname;
  std::string  _phone;
  std::string  _secret;
public:
  Contact()
  {
    _first_name = "";
    _last_name = "";
    _nickname = "";
    _phone = "";
    _secret = "";
  }
  void  set_first_name(const std::string &first_name) { _first_name = first_name; }
  void  set_last_name(const std::string &last_name)   { _last_name = last_name; }
  void  set_nickname(const std::string &nickname)     { _nickname = nickname; }
  void  set_phone(const std::string &phone)           { _phone = phone; }
  void  set_secret(const std::string &secret)         { _secret = secret; }
  const std::string&  get_first_name() const { return _first_name; }
  const std::string&  get_last_name()  const { return _last_name; }
  const std::string&  get_nickname()   const { return _nickname; }
  const std::string&  get_phone()      const { return _phone; }
  const std::string&  get_secret()     const { return _secret; }
};

#endif
