#include <iostream>

void game () {
   srand(time(0));
   int secretNum = rand() % 1001;
   int myNum = 0;
   int count = 0;

   
      std::cout << "Enter a number between 0 and 1000" << std::endl;
      std::cin >> myNum;

      while (myNum != secretNum){
         if (myNum > secretNum){
             std::cout << "Your number is greater than the stored number" << std::endl;
             ++count;
             std::cin >> myNum;
         } else if (myNum < secretNum) {
             std::cout << "your number is less than the stored number" << std::endl;
             ++count;
             std::cin >> myNum;
         }
      }

      if(myNum == secretNum){
         std::cout << "Congratulations! You guessed the number in " << count << " attempts" <<  std::endl;
      }
   }

int main () {
   game();
   return 0;
}
