#include "tasks.h"

class Users{
    private:
        string name;
        string email;
        string password;
        unordered_set<shared_ptr<BaseTask>> assingedTasks;
    public:
        Users(string nm, string emailId, string pass) :
            name(nm), email(emailId), password(pass){}

        void assignTask(shared_ptr<BaseTask> task){
            assingedTasks.insert(task);
        }

        void showTasks() const {
            cout << "Tasks for user: " << name << endl;
            for(const auto& task : assingedTasks){
                task->display();
            }
        }

        string getEmail() const{
            return email;
        }
        bool login(string userEmail, string pass){
            return (email == userEmail && password == pass);
        }
};