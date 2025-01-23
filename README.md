Task Manager
A simple command-line task manager application built using C++ to create, manage, and track tasks such as to-do lists. It includes user registration, login, and task management features with data persistence through file handling.

Features
User Registration and Login:
Users can register, log in, and log out. User data is stored in a file and loaded on startup. Each user has a unique task list.

Task Management:

Add Task: Include task title, description, priority (high, medium, low), deadline, and other relevant details.
View Tasks: View all tasks or sort them by priority or deadline.
Update Task: Modify task status (e.g., undone, ongoing, done).
Delete Task: Remove a specific task from the list.
Data Persistence
Data is saved and loaded using text files with fstream. This format allows for easier debugging compared to binary formats and suits the application's needs.

Technical Features
Object-Oriented Design:

Implements classes like User, Task, and TaskManager to structure the program and keep functionality modular.
Admin users can manage permissions and operate on other users' data.
STL Usage:

Uses std::vector and std::map to manage task and user data.
std::sort is utilized to sort tasks by priority or deadline.
Templates:

Generic utility classes (e.g., sorter, logger) are implemented using templates.
Exception Handling:

Handles various user input errors (e.g., invalid dates, duplicate usernames).
Catches errors in file reading and writing operations.
File Operations:

Task data is saved and loaded with fstream, ensuring data persistence between sessions.
Project Insights
This project helped me deepen my understanding of the Standard Template Library (STL), particularly with unordered_map, which simplifies the process of associating multiple values with a single key.

A key challenge was managing permissions. Initially, I integrated permissions into the task management module, but this caused high coupling and increased complexity. After rethinking the design, I separated the permission management into the login function. This allows users to operate within their own data scope, while leaving room for future enhancements if broader permissions are needed.

Setup Instructions
Using Visual Studio 2022:
Open TaskManager.sln with Visual Studio 2022, ensuring C++ modules are installed.
Using Another IDE:
Download the .cpp and .h files.
Run the main() function to start the program.
Contribution Guide
Contributions are welcome! If you'd like to contribute, please follow these steps:

Fork this repository to your GitHub account.

Clone the forked repository to your local machine.

Create a new branch:

sh
git checkout -b new-feature
Develop your feature, ensuring the code follows the existing style and standards.

Commit your changes and push to your forked repository:

sh
git add .
git commit -m "Add new feature"
git push origin new-feature
Create a Pull Request, describing your changes.

License
This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0) license.

Contact
Email: Zijie_Su@outlook.com
GitHub: [Skyy](https://github.com/TeamSkyy)
