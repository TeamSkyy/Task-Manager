#include "UserManager.h"
#include "LoginInterface.h"
//add user definition
 bool UserManager::addUser(std::string i, std::string psw, std::string fn, std::string ln, bool is) {
	checkAdminAccess();
	User temp(i, psw, fn, ln, is);
	auto x = std::find_if(userlist.begin(), userlist.end(), [&](const User& u) {return u.getUserId() == temp.getUserId();});
	if (x != userlist.end()) {
		std::cout << "User ID already exsist.\n";
		return false;
	}
	userlist.push_back(temp);
	return true;
}
//delete user definition
 bool UserManager::deleteUser(const std::string& i) {
	checkAdminAccess();
	auto it = std::find_if(userlist.begin(), userlist.end(), [&](const User& u) {return u.getUserId() == i; });
	if (it == userlist.end()) {
		std::cerr << "User ID does not exsist.\n";
		return false;
	}
	userlist.erase(it);
	saveToFile();
	return true;
}
//modify User definition
 bool UserManager::modifyUser(std::string& i) {
	checkAdminAccess();
	int m;
	for (m = 0;m != userlist.size();m++) {
		if (i == userlist[m].getUserId()) {
			break;
		}
	}
	User& tempu = userlist[m];
	int selection;
	std::cout << "Select the operation you wish to proceed.(press 0 to quit)\n";
	displayUserModifyMenu();
	std::cin >> selection;
	while (selection != 0) {
		std::cin.ignore();
		std::string temp;
		switch (selection) {
		case 1:
			std::cout << "Enter the first name you want to change to.\n";
			getline(std::cin, temp);
			tempu.firstname = temp;

			std::cout << "Enter the last name you want to change to.\n";
			getline(std::cin, temp);
			tempu.lastname = temp;
			break;
		case 2:
			std::cout << "Enter the id you want to change to.\n";
			getline(std::cin, temp);
			tempu.id = temp;
			break;
		case 3:
			std::cout << "Enter the passwords you want to change to.\n";
			getline(std::cin, temp);
			while (temp.size() < 6) {
				std::cout << "Password must be more than 6 characters.\n";
				getline(std::cin, temp);
			}
			tempu.password = temp;
			break;
		case 4:
			if (tempu.isAdmin == 0) {
				std::cout << "Clearance has changed to admin.\n";
			}
			else {
				std::cout << "Clearance has changed to employee.\n";
			}
			tempu.isAdmin = !tempu.isAdmin;
			break;
		default:
			std::cout << "Invalid selection.\n";
			break;
		};
		PAUSE_AND_CLEAR_SCREEN;
		std::cout << "Select the operation you wish to proceed.(press 0 to quit)\n";
		displayUserModifyMenu();
		std::cin >> selection;
	}
	return true;
}
//search User definition
 User UserManager::searchUser(const std::string& i) {
	checkAdminAccess();
	auto it = std::find_if(userlist.begin(), userlist.end(), [&](const User& u) {return u.getUserId() == i; });
	if (it == userlist.end()) {
		std::cerr << "User ID does not exsist.\n";
		throw std::runtime_error("User ID does not exsist.\n");
	}
	return *it;
}

//file format must be uid password name isadmin
 void UserManager::loadFromFile() {
	//checkAdminAccess();
	std::ifstream fin;
	fin.open("UserData.txt");
	if (!fin.is_open()) {
		std::cerr << "File open failed.\n";
		throw std::ios_base::failure("Failed to open file: UserData.txt");
	}
	std::string line;
	std::string uid, fname, lname, psw;
	bool isadm;
	while (fin >> uid >> psw >> fname >> lname >> isadm) {
		User tempUser(uid, psw, fname, lname, static_cast<int>(isadm));
		userlist.push_back(tempUser);
	}
	fin.close();
	std::cout << "User data load successful.\n";
}
 void UserManager::saveToFile() {
	checkAdminAccess();
	std::ofstream fout;
	fout.open("UserData.txt");
	if (!fout.is_open()) {
		std::cerr << "File open failed.\n";
		throw std::ios_base::failure("Failed to open file: UserData.txt");
	}
	std::string line;
	std::string uid, fname, lname, psw;
	bool isadm;
	for (auto x : userlist) {
		uid = x.getUserId();
		psw = x.password;
		fname = x.firstname;
		lname = x.lastname;
		isadm = static_cast<int>(x.isAdmin);
		fout << uid << " " << psw << " " << fname << " " << lname << " " << isadm << std::endl;
	}
	std::cout << "Save successful.\n";
	fout.close();
}

//show user methods
void UserManager::showUsers() const {
	checkAdminAccess();
	std::for_each(userlist.begin(), userlist.end(), [](const User& u) {u.showUserInfo();});
}
void UserManager::showUserById(const std::string& i) const {
	checkAdminAccess();
	auto it = std::find_if(userlist.begin(), userlist.end(), [&](const User& u) {return u.getUserId() == i; });
	if (it == userlist.end()) {
		std::cerr << "User ID does not exsist.\n";
		throw std::runtime_error("User ID does not exsist.\n");
	}
	std::string temp = (it->isAdmin) ? "Admin" : "Employee";
	std::cout << "ID: " << it->getUserId() << "\tPassword: " << it->password << "\tName: "
		<< it->firstname + " " << it->lastname << "\tAccess: " << temp << std::endl;
}

//for user login
bool UserManager::login(const std::string uid, const std::string psw, User& u) {
	auto it = std::find_if(userlist.begin(), userlist.end(), [&](const User& u) {return u.getUserId() == uid; });
	if (it == userlist.end()) {
		return false;
	}
	if (it->password != psw) {		
		return false;
	}
	u = *it;
	return true;
}
