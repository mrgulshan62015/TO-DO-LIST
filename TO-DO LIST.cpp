#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Class to manage the to-do list
class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDesc) {
        tasks.push_back(Task(taskDesc));
        cout << "Task \"" << taskDesc << "\" added." << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task \"" << tasks[taskIndex - 1].description << "\" marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            cout << "Task \"" << tasks[taskIndex - 1].description << "\" removed." << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDesc;
    size_t taskIndex;

    while (true) {
        cout << "\n===== TODO LIST MANAGER =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                cout << "Enter task to add: ";
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
                break;
        }
    }

    return 0;
}
