#include <iostream>
#include <stdio.h>
#include <system_error>
#include <vector>
#include <unordered_map>
#include <memory>
#include <chrono>
#include <unordered_set>

using namespace std;

enum TaskStatus {
    PENDING,
    IN_PROGRESS,
    COMPLETED
} ;

static string statusToString(TaskStatus status){
    switch(status){
        case TaskStatus::PENDING: return "PENDING";
        case TaskStatus::IN_PROGRESS: return "IN PROGRESS";
        case TaskStatus::COMPLETED: return "COMPLETED";
    }
    return "UNKNOWN";
}

class BaseTask{
    public:
        static int idCounter;
        int taskId;
        string description;
        string deadline;
        TaskStatus status;
        shared_ptr<BaseTask> parentTask;

    public:
        BaseTask(string desc, string ddl) : 
            description(desc), deadline(ddl), status(TaskStatus::PENDING){
                taskId = ++idCounter;
            }
        
        virtual ~BaseTask() =  default;
        virtual void display(int indent = 0) const = 0;

        int getId() const {
            return taskId;
        }

        void setStatus(TaskStatus newStatus) {
            status = newStatus;
        }

        TaskStatus getStatus() const {
            return status;
        }
};

int BaseTask::idCounter = 0;

class SubTask;
class Task : public BaseTask {
    private:
        unordered_set<shared_ptr<BaseTask>> subTasks;
    public:
        Task(string desc, string ddl) : BaseTask(desc, ddl){}

        void addSubtasks(shared_ptr<BaseTask> subtask){
                subTasks.insert(subtask);
        }

        bool removeSubTask(shared_ptr<BaseTask> task){
            if(subTasks.find(task) == subTasks.end()){
                return false;
            }
            subTasks.erase(task);
            return true;
        }
        void display(int indent = 0) const override {
            cout << string(indent, ' ') << "[Task] " << description << endl;
            cout << string(indent, ' ') << " -> Deadline: " << deadline << endl;
            cout << string(indent, ' ') << " -> Status: " << statusToString(status) << endl;
            for(const auto& subTask : subTasks){
                subTask->display(indent + 2);
            }
        }
};

class SubTask : public BaseTask {
    public:
        SubTask(string desc, string ddl) :
            BaseTask(desc, ddl){}

        void display(int indent) const override {
            cout << string(indent, ' ') << "[SubTask] " << description << endl;
            cout << string(indent, ' ') << " -> Deadline: " << deadline << endl;
            cout << string(indent, ' ') << " -> Status: " << statusToString(status) << endl;
        }
};

class Story : public BaseTask {
    private:
        unordered_set<shared_ptr<Task>> tasks;
    public:
        Story(string desc, string ddl) :
            BaseTask(desc, ddl){}
        
        void addTasks(shared_ptr<Task> task){
            tasks.insert(task);
        }

        bool removeTask(shared_ptr<Task> task){
            if(tasks.find(task) == tasks.end()){
                return false;
            }
            tasks.erase(task);
            return true;
        }

        void display(int indent = 0) const override {
            cout << "[Story] " << description << " (Deadline: " << deadline << ")" << endl;
            cout << string(indent, ' ') << " -> Status: " << statusToString(status) << endl;
            for (const auto& task : tasks) task->display(indent + 1);
        }
};