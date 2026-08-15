#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void clearScreen() {
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
   cout << endl;
}

void pressB4exit() {
   cout << "Press Enter to Continue...";
   getchar();
}

string trim(string s) {
   if (!s.empty() && s[0] == ' ' && s[s.length() - 1] == ' ') {
      s.erase(0, 1);
      s.erase(s.length()-1, 1);
   }
   return s;
}

void warning(string prompt) {
   cout << endl;
   for (size_t i = 0; i < prompt.length(); i++) {
      cout << "=";
   } cout << endl << prompt << endl;
   for (size_t i = 0; i < prompt.length(); i++) {
      cout << "=";
   }
   cout << endl;
}

string inputString(string prompt) {
   string str;
   cout << prompt;
   getline(cin, str);
   return str;
}

string to_UpperCase(string& str) {
   for (char& c : str) {
      c = toupper(c);
   } return str;
}
string inputUPPERCASE(string prompt) {
   string str = inputString(prompt);
   return to_UpperCase(str);
}

float inputNum(string prompt) {
   float num;
   while (1) {
      cout << prompt;
      if (cin >> num){ 
         cin.ignore(1000, '\n');
         return num;
      } else {
         cin.clear();
         cin.ignore(1000, '\n');
         warning(" !!! PLEASE ENTER ONLY NUMBER !!!");
      }
   }
}

bool Exit(string prompt = "Do you want to Exit?") {
   cout << prompt << endl;
   string ans = inputUPPERCASE("=> Yes/No : ");
   if (ans == "Y" || ans == "YES") return true;
   return false;
}

struct ACCOUNT {
   int id;
   string name;
   string password;
   float money_amount;
   string phone_number;
};

vector<string> OPEN_DATA() {
   vector<string> information;
   string each_info;
   ifstream myFile("SophiaData.txt");

   if (!myFile.is_open()) {
      cout << "This file does not exist, but we will create a new one." << endl;
      ofstream create_file("SophiaData.txt");
      create_file.close();
      return {};
   }

   while(getline(myFile, each_info)) {
      information.push_back(each_info);
   } 
   myFile.close();
   return information;
}

void SAVE_DATA(vector<ACCOUNT>& account) {
   ofstream myFile("SophiaData.txt");
   if (!myFile.is_open()) return;
   for (const auto& acc : account) {
      myFile << acc.id << " | " << acc.name << " | " << acc.password << " | " << acc.money_amount << " | " << acc.phone_number << " " << endl;
   }
   myFile.close();
}

vector<ACCOUNT> GET_DATA() {
   vector<string> information = OPEN_DATA();

   vector<ACCOUNT> Account;

   for (const string& info : information) {
      ACCOUNT acc;
      stringstream ss(info);
      string data;

      if (getline(ss, data, '|')) acc.id = stoi(data);
      if (getline(ss, data, '|')) acc.name = trim(data);
      if (getline(ss, data, '|')) acc.password = trim(data);
      if (getline(ss, data, '|')) acc.money_amount = stof(trim(data));
      if (getline(ss, data, '|')) acc.phone_number = trim(data);

      Account.push_back(acc);
   }
   return Account;
}

class Banking {
   protected: 
      vector<ACCOUNT>& acc_list;
      void save() {SAVE_DATA(acc_list);}

      int get_id(vector<ACCOUNT>& acc) {
         int search_id = inputNum(" - Enter ID: ");
         for (size_t i = 0; i < acc.size(); i++) {
            if (acc[i].id == search_id) {
               return i;
            }
         }
         return -1;
      }

      ACCOUNT* login(string name,string pwd,string phNum) {
         for (auto& acc : acc_list) {
            if (to_UpperCase(acc.name) == to_UpperCase(name) && acc.password == pwd && acc.phone_number == phNum) {
               return &acc;
            }
         } return nullptr;
      } 

      int get_number(vector<ACCOUNT>& acc) {
         string number = inputString(" - Enter Phone Number: ");
         for (size_t i = 0; i < acc.size(); i++) {
            if (acc[i].phone_number == number) {
               return i;
            }
         } return -1;
      }
   public:
      Banking(vector<ACCOUNT>& real_list) : acc_list(real_list) {}
};

class ADMIN : public Banking {
   private:
      void acc_info(const ACCOUNT& acc) {
         cout << "=======================================" << endl;
         cout << "    - ID       : " << acc.id << endl;
         cout << "    - Name     : " << acc.name << endl;
         cout << "    - Balance  : " << acc.money_amount << endl;
         cout << "    - Password : " << acc.password << endl;
         cout << "    - Number   : " << acc.phone_number << endl;
         cout << "=======================================" << endl;
      }
   public: 
      ADMIN(vector<ACCOUNT>& real_list) : Banking(real_list) {}
      void DISPLAY_ALL_USER() {
         if (acc_list.empty()) {
            cout << "!!! NO DATA !!!" << endl;
            return;
         }
         for (const auto& acc : acc_list) {
            acc_info(acc);
         }
      }
      void ADD_ACC() {
         cout << "|===============> New Account <===============|" << endl;
         string name = inputString("     +  Enter Name         : ");
         string password = inputString("     +  Enter Password     : ");
         float balance = inputNum("     +  Enter Balance      : ");
         string phNum = inputString("     +  Enter Phone Number : ");
         cout << "|=============================================|" << endl;
         for (const auto& acc : acc_list) {
            if (acc.phone_number == phNum) {
               warning(" !!! THIS PHONE NUMBER ALREADY EXIST !!! ");
               return;
            }
         }
         int id = (acc_list.empty()) ? 1 : acc_list.back().id + 1;
         acc_list.push_back({id, name, password, balance, phNum});
         save();
         cout << "New Account added." << endl;
      }

      void DELETE_ACC() {
         cout << "==========> REMOVE ACCOUNT <==========" << endl;
         int id = get_id(acc_list);
         if (id == -1) {
            warning(" !!! ID Not Found !!! ");
            return;
         } acc_info(acc_list[id]);
         string ans = inputUPPERCASE(" - Do you really want to delete this ID? (Y/N): ");
         if (ans == "YES" || ans == "Y") {
            acc_list.erase(acc_list.begin()+id);
            cout << " - ID: " << id << " Deleted." << endl;
            save();
         }
      }

      void UPDATE_ACC() {
         bool update = false;
         cout << "==========> UPDATE ACCOUNT <==========" << endl;
         int id = get_id(acc_list);
         if (id == -1) {
            warning(" !!! ID Not Found !!! ");
            return;
         } acc_info(acc_list[id]);
         cout << "=> Update: " << endl;
         cout << " - 1. Name" << endl;
         cout << " - 2. Password" << endl;
         cout << " - 3. Balance" << endl;
         cout << " - 4. Phone Number" << endl;
         cout << " - 0. Exit" << endl;
         int choice = inputNum(" Enter Choice: ");
         switch (choice) {
            case 1: {
                       acc_list[id].name = inputString(" + Enter your new name: ");
                       cout << "Your name has been changed." << endl;
                       update = true;
                    } break;
            case 2: {
                       acc_list[id].password = inputString(" + Enter your new password: ");
                       cout << "Your password has been changed." << endl;
                       update = true;
                    } break;
            case 3: {
                       float new_balance = inputNum(" + Enter your new balance: ");
                       if (!(new_balance >= 0)) warning(" !!! BANLANCE MUST BE GREATER THAN !!! ");
                       acc_list[id].money_amount = new_balance;
                       cout << "Your balance has been changed." << endl;
                       update = true;
                    } break;
            case 4: {
                       acc_list[id].phone_number = inputString(" + Enter your new phone number: ");
                       cout << "Your phone number has been changed." << endl;
                       update = true;
                    } break;
            case 0: {
                       cout << "Exit..." << endl;
                       return;
                    }
            default: cout << "Invalid Choice..." << endl;
         } if (update) save();
      }
};

class CUSTOMER : public Banking {
   private: 
      ACCOUNT* myACC = nullptr;

      float get_amount() {
         float amount = inputNum(" + Enter Amount of Money: ");
         if (amount <= 0) {
            warning(" YOUR AMOUNT MUST BE GREATER THAN 0. ");
            return -1;
         } return amount;
      }

      bool balance_is_enough(float amount) {
         if (amount >= myACC->money_amount) {
            warning(" THIS AMOUNT IS LARGER THAN YOUR BALANCE ");
            return false;
         } return true;
      }

      bool verify_amount(const float amount) {
         if (amount == -1) return false;
         if (!balance_is_enough(amount)) return false;
         return true;
      }

      void info_of(const ACCOUNT& acc) {
         cout << "|===> ACC INFO <=============================\\" << endl;
         cout << "|  - Name    : " << acc.name << endl;
         cout << "|  - Phone   : " << acc.phone_number << endl;
         cout << "|============================================/" << endl;
      }
   public:
      CUSTOMER(vector<ACCOUNT>& real_list) : Banking(real_list) {}
      bool User_Login(string name,string pwd,string phNum) {
         if (login(name, pwd, phNum) == nullptr) return false;
         myACC = login(name, pwd, phNum);
         return true;
      }

      void info() {
         cout << "|===> ACC INFO <===============================\\" << endl;
         cout << "|  - Name    : " << myACC->name << endl;
         cout << "|  - Balance : " << myACC->money_amount << "$" << endl;
         cout << "|  - Phone   : " << myACC->phone_number << endl;
         cout << "|==============================================|" << endl;
      }

      void DEPOSIT() {
         while (1) {
            float amount = get_amount();
            if (amount == -1) continue;
            myACC->money_amount += amount;
            save();
            return;
         }
      }

      void WITHDRAW() {
         while (1) {
            float amount = get_amount();
            if (!verify_amount(amount)) continue;
            myACC->money_amount -= amount;
            save();
            return;
         }
      }

      void TRANSFER() {
         while (1) {
            int phID = get_number(acc_list);
            if (phID == -1) {
               warning( " !!! NOT FOUND !!! ");
               if (Exit()) return;
               continue;
            } info_of(acc_list[phID]);
            int amount = get_amount();
            if (!verify_amount(amount)) continue;
            myACC->money_amount -= amount;
            acc_list[phID].money_amount += amount;
            cout << "Transfer Successfully" << endl;
            save();
            return;
         }
      }
};

void USER_INTERFACE(CUSTOMER& user) {
   while (1) {
      clearScreen();
      user.info();
      cout << "|  - 1. Deposit." << endl;
      cout << "|  - 2. Withdraw." << endl;
      cout << "|  - 3. Transfer." << endl;
      cout << "|  - 0. Exit." << endl;
      cout << "|==============================================/" << endl;

      int op = inputNum("\n\tEnter Option: ");

      switch (op) {
         case 1: user.DEPOSIT(); break;
         case 2: user.WITHDRAW(); break;
         case 3: user.TRANSFER(); break;
         case 0: return;
         default: warning(" !!! Invalid Option !!!"); break;
      }
      pressB4exit();
   }

}

void ADMIN_INTERFACE(ADMIN& admin) {
   while (1) {
      clearScreen();
      cout << "|==============>> Sopheaia <<===============|" << endl;
      cout << "|           - 1. Add New Account            |" << endl;
      cout << "|           - 2. Display Account            |" << endl;
      cout << "|           - 3. Update Account             |" << endl;
      cout << "|           - 4. Delete Account             |" << endl;
      cout << "|           - 5. Exit.                      |" << endl;
      cout << "\\===========================================/" << endl; 
      int op = inputNum("\n\tEnter Option: ");

      switch (op) {
         case 1: admin.ADD_ACC(); break;
         case 2: admin.DISPLAY_ALL_USER(); break;
         case 3: admin.UPDATE_ACC(); break;
         case 4: admin.DELETE_ACC(); break;
         case 5: return;
         default: warning(" !!! Invalid Option !!!"); break;
      }
      pressB4exit();
   }
}

bool It_is_Admin(string name,string pwd,string phNum) {
   if (name == "ADMIN" && phNum == "0" && pwd == "1") {
      return true;
   } return false;
}

bool login() {
   while (1) {
      clearScreen(); 
      cout << "|==============>> Sopheaia <<==============|" << endl;
      cout << "|           - 1. Login                     |" << endl;
      cout << "|           - 2. Exit                      |" << endl;
      cout << "\\==========================================/" << endl;
      int choice = inputNum("  + Enter: ");
      if (choice == 1) return true;
      else if (choice == 2) return false;
      else warning(" !!! Wrong Input !!! ");
   }
}
int main() {
   while (1) {
      vector<ACCOUNT> master_list = GET_DATA();
      CUSTOMER acc(master_list);
      if (!login()) return 0;
      clearScreen();

      cout << "/==============| LOGIN |=============|" << endl;
      string username = inputString("| - Enter Username    : ");
      string phNumber = inputString("| - Enter PhoneNumber : ");
      string password = inputString("| - Enter Password    : ");
      cout << "\\====================================|" << endl;

      if (It_is_Admin(username, password, phNumber)) {
         ADMIN admin(master_list);
         ADMIN_INTERFACE(admin);
         continue;
      }
      if (!acc.User_Login(username, password, phNumber)) {
         warning(" !!! NOT FOUND !!! ");
         continue;
      }

      USER_INTERFACE(acc);
      pressB4exit();
   }
   return 0;
}
