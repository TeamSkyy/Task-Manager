#include "TaskManager.h"
#include "LoginInterface.h"
#include <sstream>
//add tasks
 bool TaskManager::addTask(const std::string& uid, const std::string& tid, const std::string& t,
	const std::string& desc, int pri, const std::string& ddl, int st) {
	 if (!checkPermissionAndValidUser(uid)) {
		 return false;
	 }
	 taskMap[uid].push_back(Task(tid, t, desc, pri, ddl, (Task::TaskStatus)st));
	return true;
}

//delete tasks
 bool TaskManager::deleteTask(const std::string& uid, const std::string& tid) {
	 if (!checkPermissionAndValidUser(uid)) {
		 return false;
	 }
	auto& tasks = taskMap[uid];
	auto it = std::remove_if(tasks.begin(), tasks.end(), [&](const Task& t) {
		return t.getTaskId() == tid;
		});
	if (it == tasks.end()) {
		std::cerr << "Task ID does not exist.\n";
		return false;
	}
	tasks.erase(it, tasks.end());
	return true;
}
 //admin only(in use to delete user)
bool TaskManager::deleteUserAllTasks(const std::string& uid) {
	if (!isAdmin()) {
		std::cerr << "Permission Denied, you do not have the access to view.\n";
		return false;
	}
	auto it = taskMap.find(uid);
	if (it != taskMap.end()) {
		taskMap.erase(it);
	}
	saveToFile();
	return true;
 }
//check user's tasks
 void TaskManager::checkTask(const std::string& uid, const std::string& tid) const {
	 if (!checkPermissionAndValidUser(uid)) {
		 return;
	 }
	const auto& tasks = taskMap.at(uid);
	std::cout << std::setw(2) << std::right << "Task ID  Title  Description  Deadline  Priority  Status\n";
	if (tid == "0") { //if task id = default 0, show all tasks
		for (const auto& task : tasks) {
			task.showTask();
		}
	}
	else {//show the specific task
		auto it = std::find_if(tasks.begin(), tasks.end(), [&](const Task& t) {return t.getTaskId() == tid; });
		if (it != tasks.end()) {
			it->showTask();
		}
		else {
			std::cerr << "std::cerr << Task ID not found.\n";
			return;
		}
	}

}

//Modify Tasks
 bool TaskManager::modifyTask(const std::string& uid, const std::string& tid) {
	 if (!checkPermissionAndValidUser(uid)) {
		 return false;
	 }
	//find the match task id
	auto it = std::find_if(taskMap[uid].begin(), taskMap[uid].end(),
		[&](const Task& t) {return tid == t.getTaskId(); });
	if (it == taskMap[uid].end()) {
		std::cerr << "Task ID not found.\n";
		return false;
	}

	Task& task = *it;
	int selection;
	std::cout << "Select the operation you wish to proceed.(press 0 to quit)\n";
	displayTaskModifyMenu();
	std::cin >> selection;
	int st = 0;
	while (selection != 0) {
		std::string input;
		switch (selection) {
		case 1:
			std::cout << "Enter the title you want to change to.\n";
			getline(std::cin, input);
			task.title = input;
			break;
		case 2:
			std::cout << "Enter the description you want to change to.\n";
			getline(std::cin, input);
			std::cin.ignore();
			task.description = input;
			break;
		case 3:
			std::cout << "Enter the deadline you want to change to.\n";
			getline(std::cin, input);
			std::cin.ignore();
			task.deadline = input;
			break;
		case 4:
			std::cout << "Status change to: 1.Undone   2.Ongoing   3.Done\n";
			std::cin >> st;
			switch (st) {
			case 1:
				task.status = Task::TaskStatus::Undone;
				break;
			case 2:
				task.status = Task::TaskStatus::Ongoing;
				break;
			case 3:
				task.status = Task::TaskStatus::Done;
				break;
			default:
				std::cout << "Invalid choice.\n";
				break;
			}
			break;
		case 5:
			std::cout << "Enter the priority you want to change to (1-5)..\n";
			std::cin >> st;
			if (st > 0 && st < 6) {
				task.priority = st;
			}
			else {
				std::cout << "Invalid priority.\n";
			}
			break;
		default:
			std::cout << "Invalid selection.\n";
			break;
		};
		system("cls");
		std::cout << "Select the operation you wish to proceed.(press 0 to quit)\n";
		std::cin >> selection;
	}
	return true;
}

//Format: UserID TaskID Title Description Deadline Status Priority
 void TaskManager::loadFromFile() {
	std::ifstream fin;
	fin.open("TaskList.txt");
	if (!fin.is_open()) {
		std::cerr << "File open failed.\n";
		throw std::ios_base::failure("Failed to open file: UserData.txt");
	}
	std::string uid, tid, ttl, descri, ddl, sta, line;
	int pri = 0, intsta{ 0 };
	try {
		while (std::getline(fin, line)) {
			std::istringstream iss(line);
			//std::cout << "Read line: " << line << std::endl;//debug
			iss >> uid >> tid;
			// Extract title and description (quoted strings)
			std::getline(iss, ttl, '"');// Skip leading whitespace or partial content
			std::getline(iss, ttl, '"');// Extract the title inside quotes
			std::getline(iss, descri, '"');// Skip leading whitespace
			std::getline(iss, descri, '"');// Extract the description inside quotes
			iss >> ddl >> sta >> pri;
			// fin.ignore(); // Ignore a character in the reading stream, causing the UID reading to lose the first character, which has been deleted now
			// Convert status string to enum
			if (sta == "Undone") intsta = 0;
			else if (sta == "Ongoing") intsta = 1;
			else if (sta == "Done") intsta = 2;
			else {
				std::cout << "Invalid status\n";
				continue;
			}
			Task task(tid, ttl, descri, pri, ddl, (Task::TaskStatus)intsta);
			taskMap[uid].push_back(task);
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error loading tasks: " << e.what() << "\n";
	}
	std::cout << "Task list load successful.\n";
	fin.close();
}
 void TaskManager::saveToFile() {
	std::ofstream fout;
	fout.open("TaskList.txt");
	if (!fout.is_open()) {
		std::cerr << "File open failed.\n";
		throw std::ios_base::failure("Failed to open file: UserData.txt");
	}
	try {
		for (auto& [uid, tasklist] : taskMap) {
			for (auto& task : tasklist) {
				fout << uid << " "
					<< task.getTaskId() << " "
					<< "\"" << task.getTitle() << "\" "
					<< "\"" << task.getDescription() << "\" "
					<< task.getDeadline() << " "
					<< enumToString(task.getStatus()) << " "
					<< task.getPriority() << "\n";
			}
		}
	}
	catch (const std::exception e) {
		std::cerr << "Save failed." << e.what() << std::endl;
	}
	
	std::cout << "Task list save successfully.\n";
	fout.close();
}

 void TaskManager::showTasks(const std::string uid) const {
	 /*if (!hasPermission(uid)) {
		 std::cerr << "Permission denied. Users can only modify/view their own tasks.\n";
		 return;
	 }*/
	 for (const auto& x : taskMap) {
		 if (x.first == uid) {
			 for (const auto& y : x.second) {
				 y.showTask();
			 }
		 }
	 }
}

//admin only
 void TaskManager::showTaskById(const std::string tid) const {
	 if (!isAdmin()) {
		 std::cerr << "Permission Denied, you do not have the access to view.\n";
	 }
	 bool found = false;
	 for (const auto& x : taskMap) {
		for (const auto& y : x.second) {
			if (y.getTaskId() == tid) {
				std::cout << "User ID: " << x.first << "  " << currentUser->getName() << std::endl;
				y.showTask();
				found = true;
			}
		}
	}
	 if (!found) {
		 std::cout << "No results.\n";
	 }
}
int TaskManager::getTasksNumForUser(const std::string& uid) const {
	if (!checkPermissionAndValidUser(uid)) {
		std::cerr << "Permission Denied, you do not have the access to view.\n";
		return 0;
	}
	return taskMap.at(uid).size();
 }
//sort functions (need to distinguish admin and user)
 void TaskManager::viewTasksSortedByPriority() {
	 //admin sorts all
	 if (isAdmin()) {
		 std::vector<Task> allTasks;
		 for (auto& x : taskMap) {
			 std::sort(x.second.begin(), x.second.end(),
				 [&](const Task& a, const Task& b) {return a.getPriority() > b.getPriority(); });
			 allTasks.insert(allTasks.end(), x.second.begin(), x.second.end());
		 }
		std:;sort(allTasks.begin(), allTasks.end(), [&](const Task& a, const Task& b) {return a.getPriority() > b.getPriority();});
		 for (auto it : allTasks) {
			 it.showTask();
		}
		 std::cout << "Sort completed.\n";
	 }
	 //user sorts their own
	 else {
		 auto x = taskMap.at(currentUser->getUserId());
		 sort(x.begin(), x.end(), [&](const Task& a, const Task& b) {return a.getPriority() > b.getPriority(); });
		 for (auto y: x) {
			 y.showTask();
		 }
	 }
	 
 }
// (need to distinguish admin and user)
 void TaskManager::viewTasksByStatus(Task::TaskStatus st) {
	 //admin views all
	 std::vector<Task> filteredTasks;
	 if (isAdmin()) {
		 for (const auto& [uid, tasks] : taskMap) {
			 for (const auto& task : tasks) {
				 if (task.getStatus() == st) {
					 filteredTasks.push_back(task);
				 }
			 }
		 }
	 }
	 else {
		 auto& tasks = taskMap.at(currentUser->getUserId());
		 std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(filteredTasks),
			 [&](const Task& t) { return t.getStatus() == st; });
	 }
	 displayTasks(filteredTasks);
 }
//display all tasks
 void TaskManager::displayTasks(const std::vector<Task>& tasks) const {
	 std::cout << std::setw(10) << "Task ID" << std::setw(15) << "Title"
		 << std::setw(25) << "Description" << std::setw(15) << "Deadline"
		 << std::setw(10) << "Priority" << std::setw(10) << "Status" << "\n";

	 for (const auto& task : tasks) {
		 task.showTask(); 
	 }
 }

 //check user id if it's valid(Admin only)
 bool TaskManager::checkValidUser(const std::string& tempuid) const {
	 if (taskMap.find(tempuid) == taskMap.end()) {
		 //std::cout << "No found for user ID:  " << tempuid << std::endl;
		 return false;
	 }
	 return true;
 }
 bool TaskManager::checkPermissionAndValidUser(const std::string& uid) const {
	 // check user's id if it's valid
	 if (!checkValidUser(uid)) {
		 std::cerr << "Invalid user ID.\n";
		 return false;
	 }
	 // check user's clearance
	 if (!isAdmin() && (currentUser->getUserId() != uid)) {
		 return false;
	 }
	 return true;
 }
 //debug only
 //void TaskManager::displayALLTasks() {
	// for (const auto& [uid, tasks] : taskMap) {
	//	 std::cout << uid;
	//	 for (const auto& tid : tasks) {
	//		 tid.showTask();
	//	 }
	// }
 //}
