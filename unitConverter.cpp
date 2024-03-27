#include <iostream>

class Converter {
   private:
   double number;
   std::string setUnit;
   std::string returnUnit;

   public:
   Converter() : number(0.0) {};
   Converter(double num, std::string unit1, std::string unit2) : number(num), setUnit(unit1), returnUnit(unit2) {}
   Converter(const Converter& rhv) = delete;
   Converter(Converter&& rhv) = delete;

   double kmToMeters () const {
      return number * 1000;
   }

   double kmToDeci () const {
      return number * 10000;
   }

   double kmToSanti () const {
      return number * 100000;
   }

   double kmToMili () const {
      return number * 1000000;
   }

   double metersToKm() const {
      return number / 1000;
   }

   double metersToDeci() const {
      return number * 10;
   }

   double metersToSanti() const {
      return number * 100;
   }

   double metersToMili() const {
      return number * 1000;
   }




   void choose () {
      if (setUnit == "km") {
         if (returnUnit == "m"){
             std::cout << number << "km = " << kmToMeters() << " meters" << std::endl;
         } else if (returnUnit == "dm"){
             std::cout << number << "km = " << kmToDeci() << " decimeters" << std::endl;
         } else if (returnUnit == "sm"){
             std::cout << number << "km = " << kmToSanti() << " santimeters" << std::endl;
         } else if (returnUnit == "mm") {
            std::cout << number << "km = " << kmToMili() << " milimeters" << std::endl;
         } else {
            throw std::invalid_argument("Error");
         }
      } else if (setUnit == "m"){
            if (returnUnit == "km"){
               std::cout << number << "meters = " << metersToKm() << " kilometers" << std::endl;
            } else if (returnUnit == "dm"){
               std::cout << number << "meters = " << metersToDeci() << " decimeters" << std::endl;
            } else if (returnUnit == "sm"){
               std::cout << number << "meters = " << metersToSanti() << " santimeters" << std::endl;
            } else if (returnUnit == "mm"){
               std::cout << number << "meters = " << metersToMili() << " milimeters" << std::endl;
            } else {
               throw std::invalid_argument("Error");
            }
      } else {
         throw std::invalid_argument("Error");
      }
 }



   void run (){
      bool flag = true;
      while (flag){
         std::cout << "Enter the unit to be converted" << std::endl;
         std::cin >> this -> setUnit;
         std::cout << "enter the unit size to be converted" << std::endl;
         std::cin >> this -> number;
         std::cout << "enter what unit to convert to" << std::endl;
         std::cin >> this -> returnUnit;

         choose(); 
         std::cout << "do you want to continue? press 1 if yes, press 0 if not" << std::endl;
         std::cin >> flag;
      }

      if (!flag) {
         std::cout << "Good bye" << std::endl;
      }
   }
};



int main () {
   Converter converter;
   converter.run();
   return 0;
}
   
