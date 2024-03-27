#include <iostream>
#include <vector>
#include <string>

class Task {
   private:
      std::string task;
      bool done;
      bool favourite;

   public:
      Task() : done(false), favourite(false) {}
      
      void setTask (const std::string& str) {
         this -> task = str;
      }

      void setDone (bool flag) {
         this -> done = flag;
      }

      void setFavourites (bool flag) {
         this -> favourite = flag;
      }

      void getTask () const {
         for (int i = 0; i < task.size(); ++i){
             std::cout << task[i];
         }
         std::cout << std::endl;
      }

      bool getDone () const {
         return this -> done;
      }

      bool getFavourites () const {
         return this -> favourite;
      }
};


class ToDoList {
   private:
      std::vector<Task> list;

    public:
      void setList(const Task& str) {
         list.push_back(str);
      }

      void getList () const {
         for (int i = 0; i < list.size(); ++i){
            list[i].getTask();
         }
      }

      void deleteList (int index) {
         list.erase(list.begin() + index);
      }
      
      void addList(const std::string& str) {
         Task newTask;
         newTask.setTask(str);
         setList(newTask);
      }

      void printFav () const {
         for (int i = 0; i < list.size(); ++i){
            if (list[i].getFavourites()){
                 list[i].getTask();
                 std::cout << list[i].getFavourites() << ' ' << list[i].getDone();
                 std::cout << std::endl;
            }
         }
      }

      void printDone () const {
         for (int i = 0; i < list.size(); ++i){
            if (list[i].getDone()){
                 list[i].getTask();
                 std::cout << list[i].getFavourites() << ' ' << list[i].getDone();
                 std::cout << std::endl;
            }
         }
      }

      void printNotDone () const {
         for (int i = 0; i < list.size(); ++i){
            if (list[i].getDone() == 0){
                 list[i].getTask();
                 std::cout << list[i].getFavourites() << ' ' << list[i].getDone();
                 std::cout << std::endl;
            }
         }
      }

      void addFav (int ind) {
         if (ind < 0 && ind > list.size()){
            throw std::out_of_range("Invalid task number");
         }

         list[ind].setFavourites(true);
      }

      void addDone (int ind) {
         if (ind < 0 && ind > list.size()){
            throw std::out_of_range("Invalid task number");
         }

         list[ind].setDone(true);
      }

      void removeFav (int ind) {
         if (ind < 0 && ind > list.size()){
            throw std::out_of_range("Invalid task number");
         }
         list[ind].setFavourites(false);
      }

      void removeDone (int ind) {
         if (ind < 0 && ind > list.size()){
            throw std::out_of_range("Invalid task number");
         }
         list[ind].setDone(false);
      }

      size_t size () {
         return list.size();
      }
};

void run () {
   ToDoList List;
   int operation = 0;
   bool end = true;
   std::string str;
   int taskNumber = 0;

   while(end){
      std::cout << "Choose the type of operation․" << std::endl;
      std::cout << "press 1 to add" << std::endl;
      std::cout << "press 2 to delete" << std::endl;
      std::cout << "press 3 to see the list of favorites" << std::endl;
      std::cout << "press 4 to see the list of completers" << std::endl;
      std::cout << "Press 5 to see a list of those who have not completed" << std::endl;
      std::cout << "Press 6 to favourite" << std::endl;
      std::cout << "press 7 to execute" << std::endl;
      std::cout << "press 8 to delete the favourited one" << std::endl;
      std::cout << "press 9 to delete the executed one" << std::endl;
      std::cout << "press 10 to see the list of tasks" << std::endl;
      
      std::cin.ignore();
      std::cin >> operation;

      switch(operation){
         case 1: 
               std::cout << "Enter your task name" << std::endl;
               std::cin.ignore();
               std::getline(std::cin, str);
               List.addList(str);
               break;
         case 2: 
               std::cout << "Enter your task number" << std::endl;
               std::cin >> taskNumber;
               if (taskNumber > 0 && taskNumber <= List.size()) {
                   List.deleteList(taskNumber - 1);
               } else {
                   throw std::out_of_range("Invalid task number");
               }
               break;
         case 3: 
               List.printFav();
               break;
         case 4: 
               List.printDone();
               break;
         case 5:
               List.printNotDone();
               break;
         case 6: 
               std::cout << "Enter your task number" << std::endl;
               std::cin >> taskNumber;
               List.addFav(taskNumber - 1);
               break;
         case 7: 
               std::cout << "Enter your task number" << std::endl;
               std::cin >> taskNumber;
               List.addDone(taskNumber - 1);
               break;
         case 8: 
               std::cout << "Enter your task number" << std::endl;
               std::cin >> taskNumber;
               List.removeFav(taskNumber - 1);
               break;
         case 9: 
               std::cout << "Enter your task number" << std::endl;
               std::cin >> taskNumber;
               List.removeDone(taskNumber - 1);
               break;
         case 10: 
               List.getList();
               break;
         default: 
               std::cout << "Invalid choice" << std::endl;
               break;
      }
   
         std::cout << "do you want to continue? press 1 if yes, press 0 if not" << std::endl;
         std::cin >> end;
      }

         std::cout << "Good bye" << std::endl;
}




int main (){
   run();
   return 0;
}
   




























