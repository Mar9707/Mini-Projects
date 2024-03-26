#include <iostream>

class Table {
   private:
      char mat[3][3];
      bool flag;

   public:
      Table() : flag(true) {
         for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
               mat[i][j] = '.';
            }
         }
      }

      Table(const Table& rhv) = delete;
      Table(Table&& rhv) = delete;

      void print() const {
         for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
               std::cout << mat[i][j] << ' ';
            }

            std::cout << std::endl;
         }
      }


      void set_elem(){
         int ind1 = 0;
         int ind2 = 0;
         std::cout << "Please enter coordinate" << std::endl;
         std::cin >> ind1 >> ind2;
         if (ind1 < 0 || ind1 > 2 || ind2 < 0 || ind2 > 2){
            throw std::out_of_range("Error");
         }

         while (mat[ind1][ind2] == 'X' || mat[ind1][ind2] == 'O'){
             std::cout << "Please enter coordinate" << std::endl;
             std::cin >> ind1 >> ind2;
         }

         if (mat[ind1][ind2] != '.') {
            std::cout << "Cell is already taken. Please enter new coordinates." << std::endl;
            set_elem();
            return;
         }

         if (flag){
            mat[ind1][ind2] = 'X';
         } else {
            mat[ind1][ind2] = 'O';
         }

         flag = !flag;
         print();
      }


      bool full (){
         for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
               if (mat[i][j] == '.'){
                  return false;
               }
            }
         }

         return true;
      }


  bool checkWin(char symbol) const {
        for (int i = 0; i < 3; ++i) {
            if (mat[i][0] == symbol && mat[i][1] == symbol && mat[i][2] == symbol) {
                return true;
            }
            if (mat[0][i] == symbol && mat[1][i] == symbol && mat[2][i] == symbol) {
                return true;
            }
        }
        if (mat[0][0] == symbol && mat[1][1] == symbol && mat[2][2] == symbol) {
            return true;
        }
        if (mat[0][2] == symbol && mat[1][1] == symbol && mat[2][0] == symbol) {
            return true;
        }
        return false;
    }

    void game() {
        int turn = 0;
        while (!full()) {
            set_elem();
            if (turn >= 4) {
                if (checkWin('X')) {
                    std::cout << "Game wins X!" << std::endl;
                    return;
                } else if (checkWin('O')) {
                    std::cout << "Game wins O!" << std::endl;
                    return;
                }
            }
            turn++;
        }
        std::cout << "Game ended in a draw." << std::endl;
    }
};


      int main () {
         Table toe;
         toe.game();
         return 0;
      }
