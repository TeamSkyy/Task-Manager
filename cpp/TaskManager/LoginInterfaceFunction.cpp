#include "LoginInterface.h"
//login interface
void loginmain(User& u) {
	using std::cout, std::endl;
	//load data from file
	UserManager umana(u);
	umana.loadFromFile();
	std::string uid, psw;
	cout << "User ID: ";
	while (true) {
		std::cin >> uid;
		cout << "Password: ";
		std::cin >> psw;
		if (umana.login(uid, psw, u)) {
			system("cls");
			std::cout << "Login successful.\n";
			std::cout << "Welcome, " << u.getName() << "\tClearance: "
				<< ((u.getisAdmin()) ? "Admin" : "Employee") << std::endl;
			break;
		}
		else {
			system("cls");
			std::cin.ignore();
			std::cout << "Username and password do not match. Please try again.\n";
			cout << "User ID: ";
			continue;
		}
		break;
	}
}
void displayMenu(TaskManager& tm, UserManager& um) {
	using std::string;
	int selection, SecondaryMenuSelection = 0;
	while (tm.isAdmin()) {
		std::cout << "1. Manage Users.\n";
		std::cout << "2. Manage Tasks.\n";
		std::cout << "3. Log out.\n";
		std::cin >> selection;
		//User manage menu
		if (selection == 1) {
			while (SecondaryMenuSelection!=8) {
				std::cin.ignore();
				std::cin.clear();
				string uid, psw, fn, ln;
				int isadm;
				User temp("null", "null", "null", "null", 0);
				system("cls");
				std::cout << "1. Add user.\n";
				std::cout << "2. Delete user.\n";
				std::cout << "3. Modify User.\n";
				std::cout << "4. Search user.\n";
				std::cout << "5. View all users.\n";
				std::cout << "6. View user by id.\n";
				std::cout << "7. Save changes.\n";
				std::cout << "8. Return to the previous menu.\n";
				std::cin >> SecondaryMenuSelection;
				switch (SecondaryMenuSelection) {
				case 1:
					std::cout << "Please enter user id, password, first name, last name" <<
						" and the clearance.(0 = user, 1 = admin)\n";
					if (std::cin >> uid >> psw >> fn >> ln >> isadm) {
						if (um.addUser(uid, psw, fn, ln, isadm)) {
							std::cout << "User added.\n";
						}
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 2:
					std::cout << "Please enter the user id you wish to delete.\n";
					if (std::cin >> uid) {
						if (um.deleteUser(uid)&&tm.deleteUserAllTasks(uid)) {
							std::cout << "The user and their tasks have been deleted\n";
						}
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 3:
					std::cout << "Please enter the user id you wish to modify.\n";
					if (std::cin >> uid) {
						if (um.modifyUser(uid)) {
							std::cout << "User info modified successfully.\n";
						}
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 4:
					std::cout << "Please enter the user id you wish to search.\n";
					if (std::cin >> uid) {
						temp = um.searchUser(uid);
						std::cout << "User found.\n";
						temp.showuser();
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 5:
					um.showUsers();
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 6:
					std::cout << "Please enter the user id you wish to view.\n";
					if (std::cin >> uid) {
						um.showUserById(uid);
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 7:
					um.saveToFile();
					PAUSE_AND_CLEAR_SCREEN;
					break;
				case 8:
					system("cls");
					break;
				default:
					PAUSE_AND_CLEAR_SCREEN;
					std::cout << "Invalid selection, try again.\n";
					continue;
				}
				
			}
		}
		//Task manage menu
		else if (selection == 2) {
			SecondaryMenuSelection = 0;//reset to 0
			while (SecondaryMenuSelection != 10) {
				std::cin.ignore();
				std::cin.clear();
				string uid, tid, ttl, describ, ddl;
				int pri, status;
				User temp("null", "null", "null", "null", 0);
				system("cls");
				std::cout << "1. Add task for any user\n";
				std::cout << "2. Delete any user's task\n";
				std::cout << "3. View the specific tasks\n";
				std::cout << "4. Modify any user's task\n";
				std::cout << "5. View specific user's all tasks.\n";
				std::cout << "6. View specific task.\n";
				std::cout << "7. View tasks by priority. (descending order)\n";
				std::cout << "8. View specific status task.\n";
				std::cout << "9. Save to file.\n";
				std::cout << "10. Return to the previous menu.\n\n";
				std::cout << "Please enter the number to select the option you want to operate: ";
				std::cin >> SecondaryMenuSelection;
				switch (SecondaryMenuSelection) {
				case 1:
					std::cout << "Please enter user id, task id, title, discription" <<
						", priority(0-5), deadline and the status.(0 = Undone, 1 = Ongoing, 2 = Done)\n";
					if (std::cin >> uid >> tid >> ttl >> describ >> pri >> ddl >> status) {
						if (tm.addTask(uid, tid, ttl, describ, pri, ddl, status)) {
							std::cout << "Task added.\n";
						}
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 2:
					std::cout << "Please enter the user id and the task id you wish to delete.\n";
					if (std::cin >> uid >> tid) {
						if (tm.deleteTask(uid, tid)) {
							std::cout << "Task deleted.\n";
						}
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 3:
					std::cout << "Please enter the user id and the task id you wish to check.\n";
					if (std::cin >> uid >> tid) {
						tm.checkTask(uid, tid);
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 4:
					std::cout << "Please enter the user id and the task id you wish to modify.\n";
					if (std::cin >> uid >> tid) {
						if (tm.modifyTask(uid, tid)) {
							std::cout << "Modification successful.\n";
						}
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 5:
					std::cout << "Please enter the user id to view their tasks.\n";
					if (std::cin >> uid) {
						tm.showTasks(uid);
						std::cout << "Found " << tm.getTasksNumForUser(uid) << " results.\n";
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 6:
					std::cout << "Please enter the task id to view all users were assigned.\n";
					if (std::cin >> tid) {
						tm.showTaskById(tid);
					}
					else {
						std::cerr << "Invalid input.\n";
					}
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 7:
					tm.viewTasksSortedByPriority();//on hold need to fix
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 8:
					std::cout << "Please enter the status.(0 = Undone, 1 = Ongoing, 2 = Done)\n";
					if (std::cin >> status) {
						tm.viewTasksByStatus(Task::TaskStatus(status));
						PAUSE_AND_CLEAR_SCREEN;
						continue;
				case 9:
					tm.saveToFile();
					PAUSE_AND_CLEAR_SCREEN;
					continue;
				case 10:
					system("cls");
					break;
				default:
					system("cls");
					std::cout << "Invalid selection, try again.\n";
					PAUSE_AND_CLEAR_SCREEN;
					continue;
					}
					break;
				}
			}
		}
		else if (selection == 3) {
			system("cls");
			tm.logout();
			std::cout << "Loged out successfully.\n";
			return;
		}
		else {
			std::cout << "Invalid selection, try again.\n";
			std::cin.clear();
			std::cin.ignore();
			break;
		}
	}
	//User's menu
	while (!tm.isAdmin()) {
		std::cin.ignore();
		std::cin.clear();
		string uid, tid, ttl, describ, ddl;
		int pri, status;
		uid = tm.returnUserID();//uid is fixed, user can't enter other user's id
		std::cout << "1. Add task\n";
		std::cout << "2. Delete your task\n";
		std::cout << "3. View the your specific tasks\n";
		std::cout << "4. Modify your task\n";
		std::cout << "5. View all your tasks.\n";
		std::cout << "6. View your tasks by priority. (descending order)\n";
		std::cout << "7. View your specific status task.\n";
		std::cout << "8. Save to file.\n";
		std::cout << "9. Log out.\n\n";
		std::cout << "Please enter the number to select the option you want to operate: ";
		std::cin >> SecondaryMenuSelection;
		switch (SecondaryMenuSelection) {
		case 1:
			std::cout << "Please enter task id, title, discription" <<
				", priority(0-5), deadline and the status.(0 = Undone, 1 = Ongoing, 2 = Done)\n";
			if (std::cin >> tid >> ttl >> describ >> pri >> ddl >> status) {
				if (tm.addTask(uid, tid, ttl, describ, pri, ddl, status)) {
					std::cout << "Task added.\n";
				}
			}
			else {
				std::cerr << "Invalid input.\n";
			}
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 2:
			std::cout << "Please enter the task id you wish to delete.\n";
			if (std::cin >> tid) {
				if (tm.deleteTask(uid, tid)) {
					std::cout << "Task deleted.\n";
				}
			}
			else {
				std::cerr << "Invalid input.\n";
			}
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 3:
			std::cout << "Please enter the task id you wish to check.\n";
			if (std::cin >> tid) {
				tm.checkTask(uid, tid);
			}
			else {
				std::cerr << "Invalid input.\n";
			}
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 4:
			std::cout << "Please enter the task id you wish to modify.\n";
			if (std::cin >> tid) {
				if (tm.modifyTask(uid, tid)) {
					std::cout << "Modification successful.\n";
				}
			}
			else {
				std::cerr << "Invalid input.\n";
			}
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 5:
			tm.showTasks(uid);
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 6:
			tm.viewTasksSortedByPriority();//on hold need to fix
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 7:
			std::cout << "Please enter the status.(0 = Undone, 1 = Ongoing, 2 = Done)\n";
			if (std::cin >> status)
				tm.viewTasksByStatus(Task::TaskStatus(status));
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 8:
			tm.saveToFile();
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		case 9:
			break;
		default:
			system("cls");
			std::cout << "Invalid selection, try again.\n";
			PAUSE_AND_CLEAR_SCREEN;
			continue;
		}
			system("cls");
			break;
	}
}
void displayTaskModifyMenu() {
	std::cout << "1. Modify the task title.\n";
	std::cout << "2. Modify the task description.\n";
	std::cout << "3. Modify the task deadline.\n";
	std::cout << "4. Modify the task status.\n";
	std::cout << "5. Modify the task priority.\n";
}
//show the modification menu in Usermanager class function
void displayUserModifyMenu() {
	using std::cout;
	using std::endl;
	cout << "1. Modify name.\n";
	cout << "2. Modify id.\n";
	cout << "3. Modify password.\n";
	cout << "4. Modify clearance.\n";
}