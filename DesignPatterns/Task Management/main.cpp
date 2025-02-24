#include "taskmanager.h"

int main(){

    TaskManager tm;
    auto user1 = tm.registerUser("Manoj", "mbagewadi@ot.com", "novell");
    auto user2 = tm.registerUser("Amar", "amar@ot.com", "novell");


    auto task1 = tm.createTask("Add ldap support", "2025-02-28");
    auto task2 = tm.createTask("Add https support", "2025-03-10");
    
    auto subTask = tm.createSubtask("understand ldap", "2025-02-27", task1->getId());
    auto subTask1 = tm.createSubtask("understand https", "2025-03-01", task2->getId());

    auto story = tm.createStory("Project EDIR", "2025-04-15");
    story->addTasks(task1);
    story->addTasks(task2);

    tm.assignTasktoUser(task1->getId(), user1->getEmail());
    tm.assignTasktoUser(task2->getId(), user2->getEmail());

    tm.showUserTask(user1->getEmail());
    tm.showUserTask(user2->getEmail());
    task1->setStatus(TaskStatus::COMPLETED);
    tm.showUserTask(user1->getEmail());

    // task1->removeSubTask(subTask);
    // tm.showUserTask(user1->getEmail());

    // story->display();
    return 0;
}