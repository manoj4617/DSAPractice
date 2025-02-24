#include "user.h"

class TaskManager {
    private:
        unordered_map<int, shared_ptr<BaseTask>> taskRegistry;
        unordered_map<string , shared_ptr<Users>> users;
    
    public:
        shared_ptr<Task> createTask(string desc, string ddl){
            auto task = make_shared<Task>(desc, ddl);
            taskRegistry[task->getId()] = task;
            return task;
        }

        shared_ptr<SubTask> createSubtask(string desc, string ddl, int parentTaskId){
            if(taskRegistry.find(parentTaskId) == taskRegistry.end()){
                cout << "Parent Task not found\n";
                return nullptr;
            }
            auto subTask = make_shared<SubTask>(desc, ddl);
            taskRegistry[subTask->getId()] = subTask;
            
            auto parentTask = dynamic_pointer_cast<Task>(taskRegistry[parentTaskId]);
            if(parentTask){
                parentTask->addSubtasks(subTask);
            }
            else{
                cout << "Invalid parent Task (not a task)!\n";
            }
            return subTask;
        }

        shared_ptr<Story> createStory(string desc, string ddl){
            auto story = make_shared<Story>(desc, ddl);
            taskRegistry[story->getId()] = story;
            return story;
        }

        shared_ptr<Users> registerUser(string name, string email, string password){
            auto user = make_shared<Users>(name, email, password);
            users[email] = user;
            return user;
        }

        bool loginUser(string email, string password){
            if(users.find(email) != users.end()){
                return users[email]->login(email,password);
            }
            return false;
        }
        void assignTasktoUser(int taskId, string userEmail){
            if(users.find(userEmail) == users.end() || taskRegistry.find(taskId) == taskRegistry.end()){
                cout << "User or task not found\n";
                return;
            }

            users[userEmail]->assignTask(taskRegistry[taskId]);
        }

        void showUserTask(string email){
            if(users.find(email) != users.end()){
                users[email]->showTasks();
            }
        }
};