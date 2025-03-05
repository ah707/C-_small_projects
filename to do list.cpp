#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(std::string data): description(data), completed(false) {}
};

std::vector<Task> tasks;

void display_menu(){
    std::cout << "\n To-Do list manager \n";
    std::cout << "1. Add task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Mark task as completed\n";
    std::cout << "4. Delete task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter you choice: ";
}

void add_task(){
    std::string description;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    tasks.push_back(Task(description));
    std::cout << "Task is added successfully\n";
   
}

void view_tasks(){
    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            std::cout << ": Completed.";
        }
        std::cout << "\n";
    }
}

void mark_task_completed(){
    view_tasks();
    if (tasks.empty()) return;

    int task_number;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> task_number;

    if (task_number < 1 || task_number > tasks.size()) {
        std::cout << "Invalid task number \n";
        return;
    }

    tasks[task_number - 1].completed = true;
    std::cout << "Task is marked as completed\n";
}

void delete_task(){
    view_tasks();
    if (tasks.empty()) return;

    int task_number;
    std::cout << "Enter task number you want to delete: ";
    std::cin >> task_number;

    if (task_number < 1 || task_number > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + task_number - 1);
    std::cout << "Task deleted sucessfully.\n";
}

int main() {
    int choice;
    do {
        display_menu();
        std::cin >> choice;
         switch(choice) {
            case 1: 
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                mark_task_completed();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                std::cout << "Exiting ... \n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
         } 
    } while (choice != 5);
    return 0;
}