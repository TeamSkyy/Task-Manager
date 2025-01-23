#pragma once
#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "User.h"
class UserManager {
private:
	std::vector<User> userlist;
	User user;

	//if the user is not a admin, throw exception
	void checkAdminAccess() const {
		if (!user.getisAdmin()) {
			throw std::runtime_error("Access denied.\n");
		}
	}
public:
	explicit UserManager(const User& u) :user(u) {}
	bool addUser(std::string i, std::string psw, std::string fn, std::string ln, bool is = 0);	//add user
	bool deleteUser(const std::string& i); //delete user
	bool modifyUser(std::string& i); //modify User
	User searchUser(const std::string& i); //search User
	void showUsers() const;//Loop through all users
	void showUserById(const std::string& i) const;
	//Data persistence
	void loadFromFile();
	void saveToFile();

	//for user login
	bool login(const std::string uid, const std::string psw, User& u);
};


