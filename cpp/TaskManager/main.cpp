#include "User.h"
#include "UserManager.h"
#include "Task.h"
#include "TaskManager.h"
#include "LoginInterface.h"
int main() {
	User temploaduser("null","null","null","null",0); //this user is used for loading data
	User loginUser("null", "null", "null", "null", 0); //this user is used for login
	TaskManager loadtasks;
	loadtasks.login(&temploaduser);
	loadtasks.loadFromFile();//load task list from file
	//loadtasks.displayALLTasks();
	while (true) {
		loginmain(loginUser);
		UserManager usermanager(loginUser);
		usermanager.loadFromFile();
		loadtasks.login(&loginUser);
		displayMenu(loadtasks, usermanager);
	}
}