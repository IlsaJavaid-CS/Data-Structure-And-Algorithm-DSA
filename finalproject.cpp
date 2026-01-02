#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <sstream>
#include <iomanip> 
#include <limits>  
#include <windows.h> 

using namespace std;

// Function Prototypes
void mainmenu();
void login();
void signup();
void userpanel();
void adminpanel();
void addprod();
void removeprod();
void updateprod();
void displayprod();

// Global Variables
string adminid = "adminisme", adminpass = "admin123"; 
string pass = "", username = ""; 
const int MAX_PRODUCTS = 10;

// 12=Red, 10=Green, 14=Yellow, 11=Cyan, 15=Bright White
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printLogo() {
    setColor(11);  
    cout << R"(
      __   ___ ___ _  _   _     ___   _   ___ _____   __
     /  \ / __/ __| || | /_\   |   \ /_\ |_ _| _ \ \ / /
    / /\ \ (_| (__| __ |/ _ \  | |) / _ \ | ||   /\ V / 
   /_/  \_\___\___|_||_/_/ \_\ |___/_/ \_\___|_|_\ |_|  
                                                        
    )" << endl;
    setColor(15); 
}

int main() {
    system("title Accha Dairy Shop System");
    
    system("color 0F"); 

    cout << "\n\n";
    printLogo(); 
    
    setColor(14); // Yellow Border
    cout << "\t========================================" << endl;
    cout << "\t     FRESH . ORGANIC . PURE             " << endl;
    cout << "\t========================================" << endl << endl;
    setColor(15); // Reset to White
    
    mainmenu();
    return 0;
}

void mainmenu() {
    int choose;
    cout << "\n --- Main Menu ---\n";
    cout << " 1) Login \n";
    cout << " 2) Signup \n";
    cout << " 3) Exit \n";
    
    setColor(14); 
    cout << " Enter Your Choice: ";
    setColor(15); 
    
  
    if (!(cin >> choose)) {
        setColor(12); // 
        cout << "\n Invalid Input! Please enter a number.\n";
        setColor(15);
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        mainmenu();
        return;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer 

    if (choose == 1) login();
    else if (choose == 2) signup();
    else if (choose == 3) exit(0);
    else {
        setColor(12);
        cout << " Invalid Choice !!\n";
        setColor(15);
        mainmenu();
    }
}

void signup() {
    cout << "\n --- Sign Up Page ---\n";
    cout << " Enter Username: ";
    getline(cin, username);
    cout << " Enter Password: ";
    getline(cin, pass);
    
    setColor(10); 
    cout << " Sign UP Successful!\n";
    setColor(15);
    
    cout << " Press any key to back to main menu...";
    getch();
    mainmenu();
}

void login() {
    string checkusername, checkpass;
    cout << "\n --- Log IN ---\n";
    cout << " Enter Username: ";
    getline(cin, checkusername);
    cout << " Enter Password: ";
    getline(cin, checkpass);

    if (checkusername == adminid && checkpass == adminpass) {
        setColor(10); 
        cout << "\n [ ADMIN LOGIN SUCCESSFUL ] \n";
        setColor(15);
        cout << " Press any key to continue...";
        getch();
        adminpanel();
    } 
    else if (!username.empty() && checkusername == username && checkpass == pass) {
        setColor(10); 
        cout << "\n [ EMPLOYEE LOGIN SUCCESSFUL ] \n";
        setColor(15);
        cout << " Press any key to continue...";
        getch();
        userpanel();
    } 
    else {
        setColor(12); 
        cout << "\n [!] Wrong Credentials or No User Signed Up! \n";
        setColor(15);
        cout << " Press any key to try again...";
        getch();
        mainmenu();
    }
}

void adminpanel() {
    int choose;
    system("cls"); 
    printLogo();   
    
    setColor(14);
    cout << "\n ////////// ADMIN PANEL ////////// \n";
    setColor(15);
    
    cout << " 1) Add Product \n";
    cout << " 2) Remove Product \n";
    cout << " 3) Update Product\n";
    cout << " 4) Display Products \n";
    cout << " 5) Logout \n";
    
    setColor(14);
    cout << " Enter Choice: ";
    setColor(15);
    
    cin >> choose;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    switch (choose) {
        case 1: addprod(); break;
        case 2: removeprod(); break;
        case 3: updateprod(); break;
        case 4: 
            displayprod(); 
            cout << " Press any key to return...";
            getch();
            adminpanel();
            break;
        case 5: 
            cout << " Logout Successful! \n"; 
            mainmenu(); 
            break;
        default: 
            setColor(12);
            cout << " Invalid Choice... \n"; 
            setColor(15);
            getch();
            adminpanel();
    }
}

void addprod() {
    double price[MAX_PRODUCTS];
    int qty[MAX_PRODUCTS];
    string prodname[MAX_PRODUCTS];
    int size = 0;
    
    int choice = 1;


    while (size < MAX_PRODUCTS && choice == 1) {
        cout << "\n Entry " << (size + 1) << ":\n";
        cout << " Enter Product name: ";
        getline(cin, prodname[size]);
        
        // Validation for Price
        cout << " Enter Product Price: ";
        while(!(cin >> price[size])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setColor(12); cout << " Invalid input! Enter a number: "; setColor(15);
        }
        
        // Validation for Quantity
        cout << " Enter Product Quantity: ";
        while(!(cin >> qty[size])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setColor(12); cout << " Invalid input! Enter a number: "; setColor(15);
        }
        
        size++;

        cout << " Add another? (1=Yes, 0=No): ";
        while(!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Enter 1 or 0: ";
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    ofstream file("Products.txt", ios::app);
    if(file.is_open()) {
        for(int i = 0; i < size; i++) {
            file << prodname[i] << "," << price[i] << "," << qty[i] << endl;
        }
        file.close();
        setColor(10);
        cout << " Products saved successfully. \n";
        setColor(15);
    } else {
        setColor(12);
        cout << " Error: Unable to open file!" << endl;
        setColor(15);
    }
    
    cout << " Press any key to return...";
    getch();
    adminpanel();
}

void removeprod() {
    string prodname;
    cout << "\n Enter PRODUCT NAME to Remove: ";
    getline(cin, prodname);
    
    ifstream file("Products.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    
    if (file.is_open() && temp.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            getline(ss, name, ','); 

            if (name != prodname) {
                temp << line << endl;
            } else {
                found = true;
            }
        }
        file.close();
        temp.close();
        
        remove("Products.txt");
        rename("temp.txt", "Products.txt");
        
        if (found) {
            setColor(10);
            cout << " Product Removed Successfully!" << endl;
        } else {
            setColor(12);
            cout << " Product Not Found!" << endl;
        }
        setColor(15);
        
    } else {
        cout << " Unable to open file" << endl;
    }
    
    cout << " Press any key to go back...";
    getch();
    adminpanel();
}

void updateprod() {
    string prodname, newprodname, newprodprice, newprodqty;
    cout << "\n Enter PRODUCT NAME to Update: ";
    getline(cin, prodname);
    
    ifstream file("Products.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    
    if (file.is_open() && temp.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            getline(ss, name, ','); 

            if (name == prodname) {
                cout << " Enter New PRODUCT NAME: ";
                getline(cin, newprodname);
                cout << " Enter New PRODUCT PRICE: ";
                getline(cin, newprodprice);
                cout << " Enter New PRODUCT QTY: "; 
                getline(cin, newprodqty);

                temp << newprodname << "," << newprodprice << "," << newprodqty << endl;
                found = true;
            } else {
                temp << line << endl;
            }
        }
        file.close();
        temp.close();
        
        remove("Products.txt");
        rename("temp.txt", "Products.txt");
        
        if (found) {
            setColor(10);
            cout << " Product Updated Successfully!" << endl;
        } else {
            setColor(12);
            cout << " Product Not Found!" << endl;
        }
        setColor(15);
    } else {
        cout << " Unable to open file" << endl;
    }
    
    cout << " Press any key to go back...";
    getch();
    adminpanel();
}

void displayprod() {
    ifstream file("Products.txt");
    if (!file.is_open()) {
        setColor(12);
        cout << " No products found or unable to open file!\n";
        setColor(15);
        return;
    }

    string line;
    setColor(11); 
    cout << "\n----------------------------------------------------\n";
    cout << " No | " << left << setw(20) << "Name" << " | " << setw(10) << "Price" << " | Qty";
    cout << "\n----------------------------------------------------\n";
    setColor(15);
    int index = 1;
    while (getline(file, line)) {
        if(line.empty()) continue; 

        stringstream ss(line);
        string name, priceStr, qtyStr;
        
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, qtyStr);

        try {
            double price = stod(priceStr);
            int qty = stoi(qtyStr);
            cout << " " << index << "  | " << left << setw(20) << name << " | " << setw(10) << price << " | " << qty << "\n";
            index++;
        } catch (...) {}
    }
    file.close();
    setColor(11);
    cout << "----------------------------------------------------\n";
    setColor(15);
}

void userpanel() {
    system("cls"); 
    printLogo();
    
    setColor(14);
    cout << "\n|||||||||||||||||||||||||||||||||||||||\n";                                  
    cout << "          Employee Panel \n";
    cout << "______________________________________\n";
    setColor(15);

    int choice;
    do {
        cout << "\n 1) View Products\n";
        cout << " 2) Billing / Checkout\n";
        cout << " 3) Logout\n";
        
        setColor(14);
        cout << " Enter choice: ";
        setColor(15);
        
        // Input validation for menu
        while(!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setColor(12); cout << " Invalid input! Enter a number: "; setColor(15);
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer             

        switch (choice) {
            case 1:
                displayprod();
                cout << " Press any key...";
                getch();
                break;

            case 2: {                              
                const int MAX_ITEMS = 10;
                string cartNames[MAX_ITEMS];
                double cartPrices[MAX_ITEMS];
                int cartQtys[MAX_ITEMS];
                double total = 0.0;
                int itemCount = 0;

                char addMore;
                do {
                    displayprod();
                    int prodIndex;
                    cout << " Enter product number to add to cart: ";
                    if(!(cin >> prodIndex)) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << " Invalid input. Try again.\n";
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

                    ifstream file("Products.txt");
                    string line;
                    int idx = 1;
                    bool found = false;
                    
                    while (getline(file, line)) {
                         if(line.empty()) continue;

                        if (idx == prodIndex) {
                            stringstream ss(line);
                            string name, priceStr, qtyStr;
                            getline(ss, name, ',');
                            getline(ss, priceStr, ',');
                            getline(ss, qtyStr);

                            double price = stod(priceStr);
                            int qty = stoi(qtyStr);

                            cout << " Enter quantity (Available: " << qty << "): ";
                            int reqQty;
                            if(!(cin >> reqQty)) {
                                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                reqQty = -1; // invalid
                            } else {
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                            }

                            if (reqQty > 0 && reqQty <= qty) {
                                cartNames[itemCount] = name;
                                cartPrices[itemCount] = price;
                                cartQtys[itemCount] = reqQty;
                                total += price * reqQty;
                                itemCount++;
                                setColor(10);
                                cout << " Added to cart.\n";
                                setColor(15);
                                found = true;
                            } else {
                                setColor(12);
                                cout << " Invalid Quantity!\n";
                                setColor(15);
                            }
                            break;
                        }
                        idx++;
                    }
                    file.close();

                    if (!found) {
                        setColor(12);
                        cout << " Product not found!\n";
                        setColor(15);
                    }

                    cout << " Add more items? (y/n): ";
                    cin >> addMore;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                } while ((addMore == 'y' || addMore == 'Y') && itemCount < MAX_ITEMS);
                
                // Receipt
                setColor(11);
                cout << "\n\n ========== RECEIPT ==========\n";
                setColor(15);
                cout << left << setw(15) << "Item" << setw(5) << "Qty" << setw(10) << "Price" << "Total\n";
                cout << "------------------------------------\n";
                for (int i = 0; i < itemCount; i++) {
                    double itemTotal = cartPrices[i] * cartQtys[i];
                    cout << left << setw(15) << cartNames[i] << setw(5) << cartQtys[i] << setw(10) << cartPrices[i] << itemTotal << "\n";
                }
                cout << "------------------------------------\n";
                
                setColor(10); // Green for money
                cout << " Total Amount: Rs. " << total << "\n";
                setColor(15);
                
                cout << " ====================================\n";
                cout << " Press any key to continue...";
                getch();
                break;
            }

            case 3:
                cout << " Logging out...\n";
                mainmenu();
                return; 

            default:
                cout << " Invalid choice, try again.\n";
        }
    } while (choice != 3); 
}