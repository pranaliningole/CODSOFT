#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, int& counter) {
    Task t;
    t.id = counter++;
    t.completed = false;

    cout << "Enter task: ";
    getline(cin, t.description);

    tasks.push_back(t);
    cout << "Task added.\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";

    for (const Task& t : tasks) {
        cout << "[" << t.id << "] "
             << (t.completed ? "[Done]    " : "[Pending] ")
             << t.description << "\n";
    }

    cout << "------------------\n";
}

void markCompleted(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty())
        return;

    int id;
    cout << "Enter task ID to mark complete: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Task& t : tasks) {
        if (t.id == id) {
            if (t.completed) {
                cout << "Already completed.\n";
            } else {
                t.completed = true;
                cout << "Marked as done.\n";
            }
            return;
        }
    }

    cout << "Task not found.\n";
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty())
        return;

    int id;
    cout << "Enter task ID to remove: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto it = find_if(tasks.begin(), tasks.end(),
                      [id](const Task& t) {
                          return t.id == id;
                      });

    if (it != tasks.end()) {
        cout << "Removed: " << it->description << "\n";
        tasks.erase(it);
    } else {
        cout << "Task not found.\n";
    }
}

void showMenu() {
    cout << "\n=== To-Do List Manager ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choice: ";
}

int main() {
    vector<Task> tasks;
    int counter = 1;
    int choice;

    while (true) {
        showMenu();

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask(tasks, counter);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                markCompleted(tasks);
                break;

            case 4:
                removeTask(tasks);
                break;

            case 5:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}