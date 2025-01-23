#pragma once
#include <string>
#include <iostream>
class User {
private:
	std::string firstname, lastname;
	std::string id;
	std::string password;
	bool isAdmin;//check user if it's admin
	friend class UserManager;
	void showUserInfo() const; //For user manager only
public:
	User(std::string i, std::string psw, std::string fn, std::string ln, bool is = 0) :
		firstname(fn), lastname(ln), id(i), password(psw), isAdmin(is) {
	};
	std::string getName() const { return firstname+" "+lastname; }
	bool isLogin(std::string i, std::string psw) {
		return ((i == id) && (password == psw));
	}
	bool getisAdmin()const { return isAdmin; }
	std::string getUserId() const { return id; }
	void showuser()const;//for user to view their own data
};

inline void User::showUserInfo() const {
	std::string temp = ((getisAdmin()) ? "Admin" : "Employee");
	std::cout << "ID: " << getUserId() << "\tPassword: " << password << "\tName: "
		<< firstname + " " << lastname << "\tAccess: " << temp << std::endl;
}
inline void User::showuser()const {
	std::string temp = ((getisAdmin()) ? "Admin" : "Employee");
	std::cout << "ID: " << getUserId() << "\tName: "
		<< firstname + " " << lastname << "\tAccess: " << temp << std::endl;
}