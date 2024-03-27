#include <iostream>

double add (double num1, double num2) {
   return num1 + num2;
}

double minus (double num1, double num2){
   return num1 - num2;
}

double mul (double num1, double num2) {
   return num1 * num2;
}

double div (double num1, double num2){
   if (num2 == 0){
      throw std::invalid_argument("Error");
   }
   return num1 / num2;
}


void calculate () {
   char operation = '\0';
   double elem1 = 0;
   double elem2 = 0;
   bool end = false;


   while (!end){
      std::cout << "Enter two number" << std::endl;
      std::cin >> elem1 >> elem2;
      std::cout << "Enter operation ` +, -, *, /" << std::endl;
      std::cin >> operation;
      switch (operation){
         case '+': std::cout << "result = " << add(elem1, elem2) << std::endl; break;
         case '-': std::cout << "result = " << minus(elem1, elem2) << std::endl; break;
         case '*': std::cout << "result = " << mul(elem1, elem2) << std::endl; break;
         case '/': std::cout << "result = " << div(elem1, elem2) << std::endl; break;
         default: throw std::invalid_argument("Error");
      }

      std::cout << "do you want to continue? press 0 if yes, press 1 if not" << std::endl;
      std::cin >> end;
   }

   if (end){
      std::cout << "Good bye" << std::endl;
   }
}


int main () {
   calculate();
   return 0;
}
