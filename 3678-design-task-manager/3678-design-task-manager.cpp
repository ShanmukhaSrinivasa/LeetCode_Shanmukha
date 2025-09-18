class TaskManager {
public:
    map<int, int> taskToUser;
    map<int, int> taskToPriority;
    set<pair<int, int>> task;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto i : tasks) {
            int userId = i[0];
            int taskId = i[1];
            int priority = i[2];

            task.insert({priority, taskId});
            taskToUser[taskId] = userId;
            taskToPriority[taskId] = priority;
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        task.insert({priority, taskId});
        taskToUser[taskId] = userId;
        taskToPriority[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        int Priority = taskToPriority[taskId];
        task.erase({Priority, taskId});
        task.insert({newPriority, taskId});
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int Priority = taskToPriority[taskId];
        task.erase({Priority, taskId});
        taskToPriority.erase(taskId);
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        if (task.size() == 0) {
            return -1;
        }
        int taskId = task.rbegin()->second;
        int userId = taskToUser[taskId];
        rmv(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */