#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Task.h"
#include "User.h"
void displayTaskModifyMenu();
class TaskManager {
private:
	std::unordered_map<std::string, std::vector<Task>> taskMap;
	User* currentUser;
	bool checkValidUser(const std::string& tempuid) const;//in class use only
public:
	bool addTask(const std::string& uid, const std::string& tid, const std::string& t,
		const std::string& desc, int pri, const std::string& ddl, int st);
	bool deleteTask(const std::string& uid, const std::string& tid);
	bool deleteUserAllTasks(const std::string& uid);//admin only
	void checkTask(const std::string& uid, const std::string& tid = "0") const;
	bool modifyTask(const std::string& uid, const std::string& tid);
	void showTasks(const std::string uid) const;
	void showTaskById(const std::string tid) const;
	void displayTasks(const std::vector<Task>& tasks) const;
	int getTasksNumForUser(const std::string& uid) const;
	std::string returnUserID()const { return currentUser->getUserId(); } //for user to get the id
	//Data persistence
	void loadFromFile();
	void saveToFile();
	//sort
	void viewTasksSortedByPriority();
	void viewTasksByStatus(Task::TaskStatus st);
	//login modules
	void login(User* user) { currentUser = user; }
	void logout() { currentUser = nullptr; }
	bool isAdmin() const { return currentUser->getisAdmin(); }
	//bool hasPermission(const std::string uid) const { return isAdmin() || (currentUser->getUserId() == uid); }
	bool checkPermissionAndValidUser(const std::string& uid) const;
	//void displayALLTasks(); //in use for debug
};
