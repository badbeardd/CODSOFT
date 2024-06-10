#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task
{
private:
bool status = false;
string description;


public:
void addition(const string &str){
description = str;
}
void display(int index){
    cout<< index <<".["<<(status ? "Completed": "Incomplete") <<"] -"<<description<<"\n";
}

void mark(){
    status = true;
}
};

int main()
{
    vector<Task*> obj_list;
    int choice;
while(true){    
cout<<"Welcome to the To-Do List Manager\n";
cout<<"Please choose an option: \n";
cout<< "1. Add Task\n";
cout<<"2. View Tasks\n";
cout<<"3. Mark Task as Completed\n";
cout<<"4. Remove Task\n";
cout<<"5. Exit\n";
cout<<"Your choice: \n";
cin>>choice;
cin.ignore();

switch (choice)
{
    case 1:
    {
    string user_input;
    cout << "Enter the task description: ";
    getline(cin,user_input);
    Task* obj =  new Task();
    obj->addition(user_input);
    obj_list.push_back(obj);
    break;
    }
    case 2:
    {
    cout<<"Your List\n";
    for(size_t i = 0; i < obj_list.size(); ++i)
    {
        obj_list[i]->display(i);
    }
    cout<<" List End\n";
    break;
    }
    case 3:
    {
        int num;
        cout << "Enter task number to mark as completed: ";
        cin>>num;
        if (num >= 0 && static_cast<size_t>(num) < obj_list.size()) {
                obj_list[num]->mark();
            } else {
                cout << "Invalid task number.\n";
            }
    break;
    }
    case 4:
    {
           int num;
            cout << "Enter task number to remove: ";
            cin >> num;
            if (num >= 0 && num < obj_list.size()) {
                delete obj_list[num];
                obj_list.erase(obj_list.begin() + num);
            } else {
                cout << "Invalid task number.\n";
            }
            break;
    }
    case 5:
    {
        // Free dynamically allocated memory
            for (Task* task : obj_list) {
                delete task;
            }
            return 0;
    }
    default:
    {
     cout << "Please provide a valid input.\n";
            break;
    }
}

}

}
