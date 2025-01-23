#pragma once
#include "UserManager.h";
#include "TaskManager.h";
#define PAUSE_AND_CLEAR_SCREEN do{system("pause");system("cls");}while(0)
void loginmain(User& u);
void displayMenu(TaskManager& tm, UserManager& um);
void displayUserModifyMenu();