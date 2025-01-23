#pragma once
#include <string>
#include <iostream>
#include <iomanip>


class Task {
public:
	enum TaskStatus{Undone,Ongoing,Done};
	friend inline std::string enumToString(Task::TaskStatus t);
private:
	std::string taskId;
	std::string title;
	std::string description;
	int priority;
	std::string deadline;
	TaskStatus status;
	friend class TaskManager;
public:
	Task(std::string tid, std::string t, std::string desc, int pri, std::string ddl, TaskStatus st = Undone) :
		taskId(tid),title(t), description(desc), priority(pri), deadline(ddl), status(st) {
	};
	std::string getTitle() const { return title; }
	std::string getDescription() const { return description; }
	std::string getDeadline() const { return deadline; }
	std::string getTaskId() const{ return taskId; }
	int getPriority() const { return priority; }
	TaskStatus getStatus() const { return status; }
	void showTask() const;
private:
	void setTtile(const std::string& temp) { title = temp; }
	void setDescription(const std::string& temp) { description = temp; }
	void setDeadline(const std::string& temp) { deadline = temp; }
	void setPriority(int x) { priority = x; }
	void setStatus(int x) {
		switch (x) {
		case 1:
			status = TaskStatus::Undone;
			break;
		case 2:
			status = TaskStatus::Ongoing;
			break;
		case 3:
			status = TaskStatus::Done;
			break;
		default:
			status = TaskStatus::Undone;
			break;
		}
	}
};

inline void Task::showTask() const {
	std::cout << std::setw(10) << std::left << taskId << "  "
		<< std::setw(15) << std::left << title << "  "
		<< std::setw(40) << std::left << description << "  "
		<< std::setw(15) << std::left << deadline << "  "
		<< std::setw(10) << std::left << priority << "  "
		<< std::setw(10) << std::left << enumToString(status) << std::endl;
}
inline std::string enumToString(Task::TaskStatus t) {
	std::string temp;
	switch (t) {
	case 0:
		return "Undone";
	case 1:
		return "Ongoing";
	case 2:
		return "Done";
	default:
		return "Unknown";
		break;
	}
}
inline Task::TaskStatus IntToString(int i);
inline Task::TaskStatus IntToString(int i) {
	switch (i) {
	case 0:
		return Task::TaskStatus::Undone;
	case 1:
		return Task::TaskStatus::Ongoing;
	case 2:
		return Task::TaskStatus::Done;
	default:
		return Task::TaskStatus::Undone;
		break;
	}
}