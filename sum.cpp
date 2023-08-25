/*  File Structure Mini Project On "Pharmacy Management System"
 *   By kusuma sree-  manvi shah- akanksha -alfahad
 */

// Standard Libraries
#include <iostream>

#include <stdlib.h>

#include <unistd.h>

#include <string>

#include <cstring>

#include <cctype>

#include <cmath>

#include <cstdio>

#include <fstream>

#include <iomanip>

#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <vector>
#define MAX 10

// Header File
using namespace std;

// Base Class
class pharmacyManagementSystem
{
public:
    void mainMenu();            // Pharmacy Management System Main Menu
    void search();              // Search For Certain Medicine
    void takeOrder();           // Orders To Be Taken
    void deleteOrder();         // Delete The Medicine
    void modify();              // Modify The Medicine/ Customer Information
    void orderList();           // Display The Order List
    void dailySummary();        // Display The Summary List
    void exit();                // Exit Function
    void displayMedicine();     // Displays The Set Of Medicine
    void displayCustomers();
    int addNewMedicine();    // Displays The Set Of Customers - Back Up
    void deleteMedicine();
    void modifyMedicine();
    void userSelection();
         // Admin/Customer Selection
    pharmacyManagementSystem(); // Constuctor
};

pharmacyManagementSystem::pharmacyManagementSystem() {} // Constructor For Class pharmacyManagementSystem

// Structure Of Type Node
struct node
{
    string customerName;
    string date;
    string medicineName[MAX] = {
        "Dolo 650",
        "CITRA C",
        "Bupropion",
        "Zoloft",
        "Sumitop",
        "Omeprazole",
        "Digene",
        "HealthVit",
        "Naproxen",
        "Neurobion"};
    int recieptNumber;
    int quantity[MAX];
    int x, menu2[MAX];
    float amount[MAX];
    double Medicine[MAX] = {
        200.00,
        200.00,
        500.00,
        400.00,
        500.00,
        300.00,
        100.00,
        400.00,
        300.00,
        300.00};
    double total;
    node *prev;
    node *next;
    node *link;
} * q, *temp; // Pointer Of Type Node

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

// Main Menu
void pharmacyManagementSystem::mainMenu()
{
    pharmacyManagementSystem pharmacyManagementSystemObj;
    int choice;
    while(1)
    {
        cout << "======================================================================================================================\n";
        cout << "\n\t\t\t\t\t   Pharmacy Management System \n";
        cout << "----------------------------------------------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t||\t1. Search For The Medicine  \t\t||\n";
        cout << "\t\t\t\t||\t2. New Medicine Order \t\t\t||\n";
        cout << "\t\t\t\t||\t3. Delete Latest Medicine Order Details ||\n";
        cout << "\t\t\t\t||\t4. Modify Order List \t\t\t||\n";
        cout << "\t\t\t\t||\t5. Print Reciept And Make Payment \t||\n";
        cout << "\t\t\t\t||\t6. Daily Summary Of Total Sales \t||\n";
        cout << "\t\t\t\t||\t7. Display Available Medicine \t\t||\n";
        cout << "\t\t\t\t||\t8. Display Back Up Customer Details \t||\n";
        cout << "\t\t\t\t||\t9. Add New Medicine \t\t\t||\n";
        cout << "\t\t\t\t||\t10. Delete Medicine \t\t\t||\n";
        cout << "\t\t\t\t||\t11. Modify Medicine \t\t\t||\n";
        cout << "\t\t\t\t||\t12. Exit \t\t\t\t||\n";
        cout << "---------------------------------------------------------------------------------------------------------------------\n";
        cout << "\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            pharmacyManagementSystemObj.search();
            break;
        }

        case 2:
        {
            pharmacyManagementSystemObj.takeOrder();
            break;
        }

        case 3:
        {
            pharmacyManagementSystemObj.deleteOrder();
            break;
        }

        case 4:
        {
            pharmacyManagementSystemObj.modify();
            break;
        }

        case 5:
        {
            pharmacyManagementSystemObj.orderList();
            break;
        }

        case 6:
        {
            pharmacyManagementSystemObj.dailySummary();
            break;
        }

        case 7:
        {
            pharmacyManagementSystemObj.displayMedicine();
            break;
        }

        case 8:
        {
            pharmacyManagementSystemObj.displayCustomers();
            break;
        }

       case 9:
        {
            pharmacyManagementSystemObj.addNewMedicine();

            break;
        }
        case 10:
        {
            pharmacyManagementSystemObj.deleteMedicine();

            break;
        }
        case 11:
        {
            pharmacyManagementSystemObj.modifyMedicine();

            break;
        }
     case 12:
        {
            pharmacyManagementSystemObj.exit();
            system("CLS");
            break;
        }

        default:
        {
            cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                 << endl;
            break;
        }
        }
    } while (choice != 12);
}


// Search Function
void pharmacyManagementSystem::search()
{
    system("CLS");
    string search;
    string line;
    int choice, i, offset, flag = 0;
    node *temp;
    temp = new node;
    cout << "=====================================================" << endl;
    cout << "Search :\n";
    cout << "=====================================================" << endl;
    cout << "Enter The Name Of The Medicine You Wish To Search : "; // Search For Medicine
    cin.ignore();//clear any previous input from the input buffer
    getline(cin, search);
    cout << endl;
    for (i = 0; i < MAX; i++)
    {
        if (strcmp((search.c_str()), (temp->medicineName[i].c_str())) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "Found" << endl;
        cout << "************************************" << endl;
        cout << "|  DRUG'S NAME  | DRUGS PRICE(Rs.) |" << endl;
        cout << "************************************" << endl;
        cout << "|    " << temp->medicineName[i] << "     |       " << temp->Medicine[i] << "        |" << endl;
        cout << "************************************" << endl;
        cout << endl;
    }
    else
    {
        cout << "Medicine Stocked Out, Kindly Visit Tomorrow!" << endl;
    }
    system("PAUSE");
    system("CLS");
}

// Take Order Function
void pharmacyManagementSystem::takeOrder()
{
    system("CLS");
    int i;
    float totalPrice = 0;
    string takeOrderText;
    cout << "\nSelect The Medicines That You Would Like To Buy\n";
    cout << "------------------------------------------------ \n\n";
    node *temp;
    temp = new node;

    ofstream out("takeCustomerInfo.txt", ios::out | ios::app);
    ifstream in("takeOrder.txt");

    for (i = 0; i < 30; i++)
    {
        getline(in, takeOrderText);
        cout << takeOrderText << endl;
    }

    cout << "" << endl;

    bool receiptExists;

    do
    {
        receiptExists = false;
        cout << "Type Receipt Number: ";
        cin >> temp->recieptNumber;

        // Check if receipt number already exists
        node *current = start_ptr;
        while (current != nullptr)
        {
            if (current->recieptNumber == temp->recieptNumber)
            {
                cout << "Receipt number already exists. Please enter a different number.\n";
                receiptExists = true;
                break;
            }
            current = current->next;
        }
    } while (receiptExists);

    out << "Receipt Number : " << temp->recieptNumber << endl;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, temp->customerName);
    out << "Customer Name : " << temp->customerName << endl;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin >> temp->date;
    out << "Date : " << temp->date << endl;
    cout << "" << endl;
    cout << "\"NOTE: Maximum 10 Medicines Can Be Ordered Per Transaction\"\n";
    cout << "Please Enter The Total Count Of Medicines You Would Like To Order: ";
    cin >> temp->x;
    out << "Number Of Medicines Ordered : " << temp->x << endl;

    if (temp->x > MAX)
    {
        cout << "Excessive Amount Of Medicine Ordered Error!";
        system("PAUSE");
    }
    else
    {
        for (i = 0; i < temp->x; i++)
        {
            cout << "Please Enter The Medicine That You Wish To Buy : ";
            cin >> temp->menu2[i];
            cout << "Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
            out << "Medicine Name : " << temp->medicineName[temp->menu2[i] - 1] << endl;
            cout << "Count Of The Respective Medicine : ";
            cin >> temp->quantity[i];
            out << "Medicine Quantity : " << temp->quantity[i] << endl;
            temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
            totalPrice = totalPrice + temp->amount[i];
        }

        cout << "You've Been Charged With Amount Of Rs. " << totalPrice << ".00" << endl; // Displaying The Total Price Charged
        out << "Total Price : Rs. " << totalPrice << ".00\n" << endl;
        out << "==================================\n" << endl;

        cout << "===========================================================================" << endl;
        cout << "Order Placed Successfully" << endl;
        cout << "===========================================================================" << endl;
        cout << "Head To The Receipt Menu To Pay The Bill" << endl;
        cout << "===========================================================================" << endl;

        temp->next = start_ptr;
        start_ptr = temp;

        system("PAUSE");
        system("CLS");
    }
}

// Delete Order Function
void pharmacyManagementSystem::deleteOrder()
{
    system("CLS");
    int num;
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);

    cout << "Enter the Receipt Number You Wish To Delete: ";
    cin >> num;
    node *q;
    node *temp;
    bool found = false;

    if (start_ptr == NULL)
    {
        cout << "Empty List, No Entries Detected To Delete" << endl;
    }
    else
    {
        if (start_ptr->recieptNumber == num)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;
            if (start_ptr == NULL)
                last = NULL;
            cout << "The Receipt is Deleted Successfully!" << endl;
            found = true;
        }
        else
        {
            temp = start_ptr;
            q = start_ptr->next;
            while (q != NULL)
            {
                if (q->recieptNumber == num)
                {
                    temp->next = q->next;
                    if (last == q)
                        last = temp;
                    cout << "The Receipt is Deleted Successfully!" << endl;
                    found = true;
                    break;
                }
                temp = q;
                q = q->next;
            }
        }
    }

    if (found)
    {
        // Display the data of the deleted receipt
        cout << "Deleted Receipt Information:" << endl;
        cout << "Receipt Number: " << q->recieptNumber << endl;
        cout << "Customer Name: " << q->customerName << endl;
        cout << "Date: " << q->date << endl;
        // Display other receipt details as needed

        delete q;
    }
    else
    {
        cout << "Sorry, No Such Receipt Found!" << endl;
    }
}

// Modify Order/Customer Details Function
void pharmacyManagementSystem::modify()
{
    system("CLS");
    int sid;
    bool found = false;
    float totalPrice = 0;
    node *temp;
    temp = start_ptr;
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);

    cout << "Enter Receipt Number To Modify: ";
    cin >> sid;

    while (temp != NULL)
    {
        if (temp->recieptNumber == sid)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        // Display the previous data of the receipt
        cout << "Previous Receipt Information:" << endl;
        cout << "Receipt Number: " << temp->recieptNumber << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Date: " << temp->date << endl;
        // Display other previous receipt details as needed

        cout << "\n----- Enter Modified Details -----\n";
        cout << "Change Receipt Number: ";
        cin >> temp->recieptNumber;
        out << "Receipt Number: " << temp->recieptNumber << endl;
        cout << "Change Customer Name: ";
        cin.ignore();
        getline(cin, temp->customerName);
        out << "Customer Name: " << temp->customerName << endl;
        cout << "Change Date: ";
        cin >> temp->date;
        out << "Date: " << temp->date << endl;
        cout << "" << endl;
        cout << "\"NOTE: Maximum 10 Medicines Can Be Ordered Per Transaction\"\n";
        cout << "Please Enter The Total Count Of Medicines You Would Like To Order: ";
        cin >> temp->x;
        out << "Number Of Medicines Ordered: " << temp->x << endl;

        if (temp->x > MAX)
        {
            cout << "Excessive Amount Of Medicines Ordered Error!";
            system("PAUSE");
        }
        else
        {
            for (int i = 0; i < temp->x; i++)
            {
                cout << "Please Enter The Medicine That You Wish To Buy: ";
                cin >> temp->menu2[i];
                cout << "Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
                out << "Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
                cout << "Count Of The Respective Medicine: ";
                cin >> temp->quantity[i];
                out << "Medicine Quantity: " << temp->quantity[i] << endl;
                temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
                totalPrice = totalPrice + temp->amount[i];
            }
            cout << "You've Been Charged With An Amount Of Rs. " << totalPrice << ".00" << endl; // Displaying The Total Price Charged
            out << "Total Price: Rs. " << totalPrice << ".00\n" << endl;
            out << "==================================\n" << endl;

            // Display the modified data of the receipt
            cout << "\nModified Receipt Information:" << endl;
            cout << "Receipt Number: " << temp->recieptNumber << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Date: " << temp->date << endl;
            // Display other modified receipt details as needed

            temp = temp->next;
            system("CLS");
            cout << "Record Modification Successful!" << endl;
        }
    }
    else
    {
        cout << "No Such Record Found To Modify!" << endl;
    }
}


// Order List Function
// Order List Function
void pharmacyManagementSystem::orderList()
{
    int i, num, num2;
    bool found = false; // Search Variable
    system("cls");
    node *temp;
    temp = start_ptr;
    float totalPrice = 0;

    cout << "Enter the Reciept Number To Print The Reciept : ";
    cin >> num2;
    cout << "\n";
    cout << "=====================================================" << endl;
    cout << "List Of Orders :\n";
    cout << "=====================================================" << endl;

    if (temp == NULL) // Entered Receipt Number Is Invalid
    {
        cout << "No Such Receipt Number Found In Our Record!\nKindly Enter The Correct Receipt Number\n\n";
    }
    while (temp != NULL && !found)
    {
        if (temp->recieptNumber == num2)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
        if (found) // Print The Receipt
        {
            cout << "Reciept Number : " << temp->recieptNumber;
            cout << "\n";
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Order Date : " << temp->date << endl;
            cout << "_____________________________________________________" << endl;
            cout << "=====================================================" << endl;
            cout << "|  Medicine Name  |  	Quantity    |  Total Price  |" << endl;
            cout << "=====================================================" << endl;
            for (i = 0; i < temp->x; i++)
            {
                cout << "|    " << temp->medicineName[temp->menu2[i] - 1] << "     ";
                cout << "|        " << temp->quantity[i] << "        ";
                cout << "|    "
                     << " Rs." << temp->amount[i] << "    |" << endl;
                cout << "_____________________________________________________" << endl;
                totalPrice = totalPrice + temp->amount[i];
            }
            cout << "Total Bill : "
                 << " Rs." << totalPrice << ".00" << endl; // Displaying The Total Bill
            cout << "\n";
        b:
            cout << "Type In The Amount To Be Payed : ";
            cin >> num;
            if (num < totalPrice)
            {
                cout << "Kindly Pay The Prescribed Amount!\n"
                     << endl;
                goto b;
            }
            else if (num > totalPrice)
            {
                cout << "_____________________________________________________\n";
                cout << "Payment Done Successfully!" << endl;
                cout << "Here's Your Change Of Rs. " << num - totalPrice << ".00" << endl;
                cout << "Thank You" << endl;
            }
            else
            {
                cout << "Payment Done Successfully!\nThank You\n";
                cout << "_____________________________________________________\n";
            }
        }
    }
    system("PAUSE");
    system("CLS");
}

// Daily Summary Function
void pharmacyManagementSystem::dailySummary()
{
    int i, num;
    system("CLS");
    node *temp;
    temp = start_ptr;
    float totalPrice = 0;

    if (temp == NULL) // Invalid Receipt Code
    {
        cout << "No Orders To Show!\n"
             << endl;
    }
    else
    {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Daily Summary Of All Orders \n"; // Print All Transactions Occurred
        cout << "=====================================================" << endl;

        while (temp != NULL)
        {
            cout << "Reciept Number : " << temp->recieptNumber;
            cout << "\n";
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Order Date : " << temp->date << endl;
            cout << "_____________________________________________________" << endl;
            cout << "=====================================================" << endl;
            cout << "|  Medicine Name  |  	Quantity    |  Total Price  |" << endl;
            cout << "=====================================================" << endl;
            for (i = 0; i < temp->x; i++)
            {
                cout << "|    " << temp->medicineName[temp->menu2[i] - 1] << "     ";
                cout << "|        " << temp->quantity[i] << "        ";
                cout << "|    "
                     << " Rs." << temp->amount[i] << "    |" << endl;
                cout << "_____________________________________________________" << endl;
                totalPrice = totalPrice + temp->amount[i];
            }
            cout << "Total Bill : "
                 << " Rs." << totalPrice << ".00" << endl; // Displaying The Total Bill
            cout << "_____________________________________________________\n";

            temp = temp->next;
        }
    }
    system("PAUSE");
    system("CLS");
}


// Display Medicine Function
void pharmacyManagementSystem::displayMedicine()
{
    system("CLS");
    cout << "=====================================================" << endl;
    cout << "Medicines In Stock \n"; // Print All Medicines In Stock
    cout << "=====================================================" << endl;
    string takeOrderText;
    ifstream in("takeOrder.txt");
    for (int i = 0; i < 30; i++)
    {
        getline(in, takeOrderText);
        cout << takeOrderText << endl;
    }
    cout << "" << endl;
    system("PAUSE");
    system("CLS");
}

// Display Back-Up Customer Details
void pharmacyManagementSystem::displayCustomers()
{
    system("CLS");
    cout << "=====================================================" << endl;
    cout << "Back-Up Customer Details \n"; // Print All Transactions Occurred
    cout << "=====================================================" << endl;
    string takeCustomerInfo;
    ifstream in("takeCustomerInfo.txt");
    while (!in.eof())
    {
        getline(in, takeCustomerInfo);
        cout << takeCustomerInfo << endl;
    }
    system("PAUSE");
    system("CLS");
}
//add
int pharmacyManagementSystem::addNewMedicine()
{   system("CLS");
    string drugId, drugName, drugPurpose;
    double drugPrice;

    cout << "Enter drug ID: ";
    cin >> drugId;

    ifstream file("takeOrder.txt");
    if (file.is_open()) {
        string line;
        vector<string> fileContent;
        bool idExists = false;

        while (getline(file, line)) {
            // Check if drug ID already exists in the file
            if (line.find(drugId) != string::npos) {
                cout << "Drug ID already exists. Do you want to overwrite the existing entry? (y/n): ";
                char choice;
                cin >> choice;
                if (tolower(choice) == 'y') {
                    idExists = true;
                    break;  // Exit the loop as we found a match
                } else {
                    fileContent.push_back(line);
                }
            } else {
                fileContent.push_back(line);
            }
        }

        file.close();

        if (idExists) {
            cout << "Enter drug's name: ";
            cin.ignore();
            getline(cin, drugName);
            cout << "Enter drug's purpose: ";
            getline(cin, drugPurpose);
            cout << "Enter drug's price (Rs.): ";
            cin >> drugPrice;

            string updatedLine = "|   " + drugId + " |   " + drugName + " |    " + drugPurpose + " |    Rs. " + to_string(drugPrice) + "|";
            fileContent.push_back(updatedLine);

            ofstream outFile("takeOrder.txt", ios::trunc);
            if (!outFile) {
                cout << "Error opening file." << endl;

            }

            for (const string& line : fileContent) {
                outFile << line << endl;
            }

            outFile.close();

            cout << "Existing entry updated successfully." << endl;

        } else {
            char addNewChoice;
            cout << "No existing entry found with the given ID. Do you want to add a new entry? (y/n): ";
            cin >> addNewChoice;
            if (tolower(addNewChoice) != 'y') {
                cout << "No changes made. Exiting to the main menu." << endl;
                mainMenu();
            }
        }
    } else {
        cout << "Error opening file." << endl;

    }

// If we reach this point, it means a new medicine is being added
    cout << "Enter drug's name: ";
    cin.ignore();
    getline(cin, drugName);
    cout << "Enter drug's purpose: ";
    getline(cin, drugPurpose);
    cout << "Enter drug's price (Rs.): ";
    cin >> drugPrice;

    ofstream outFile("takeOrder.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file." << endl;

    }

    outFile << "|   " << setw(6) << left << drugId << " |   " << setw(14) << left << drugName << " |    "
            << setw(19) << left << drugPurpose << " |    Rs. " << setw(8) << left << fixed << setprecision(2) << drugPrice << "|\n";

    outFile.close();

    cout << "New medicine added successfully." << endl;

    system("PAUSE");
    system("CLS");
    return 1;
}
//delete medicine
void pharmacyManagementSystem::deleteMedicine()
{
    system("CLS");
    string drugId;

    cout << "Enter drug ID to delete: ";
    cin >> drugId;

    ifstream file("takeOrder.txt");
    if (file.is_open()) {
        string line;
        vector<string> fileContent;
        vector<string> deletedMedicineDetails;  // Store details of the deleted medicine
        bool idExists = false;

        while (getline(file, line)) {
            // Check if drug ID exists in the file
            if (line.find(drugId) != string::npos) {
                idExists = true;
                deletedMedicineDetails.push_back(line);  // Store the line in the vector
            } else {
                fileContent.push_back(line);
            }
        }

        file.close();

        if (idExists) {
            ofstream outFile("takeOrder.txt", ios::trunc);
            if (!outFile) {
                cout << "Error opening file." << endl;
                return;
            }

            for (const string& line : fileContent) {
                outFile << line << endl;
            }

            outFile.close();

            cout << "Medicine with ID " << drugId << " deleted successfully." << endl;

            // Display the details of the deleted medicine
            cout << "Deleted Medicine Details:" << endl;
            for (const string& line : deletedMedicineDetails) {
                cout << line << endl;
            }
        } else {
            cout << "No medicine found with the given ID." << endl;
        }
    } else {
        cout << "Error opening file." << endl;
    }

    system("PAUSE");
    system("CLS");
}
//modify medicine
void pharmacyManagementSystem::modifyMedicine()
{
    system("CLS");
    string drugId;
    bool found = false;
    vector<string> fileContent;

    cout << "Enter the drug ID to modify: ";
    cin >> drugId;

    ifstream file("takeOrder.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Check if drug ID matches in the file
            if (line.find(drugId) != string::npos) {
                found = true;
                cout << "Existing details of the medicine:" << endl;
                cout << line << endl;

                string modifiedDrugId = drugId;
                string modifiedDrugName, modifiedPurpose, modifiedPrice;

                cout << "Enter the modified drug name: ";
                cin.ignore();
                getline(cin, modifiedDrugName);

                cout << "Enter the modified drug purpose: ";
                getline(cin, modifiedPurpose);

                cout << "Enter the modified drug price (Rs.): ";
                getline(cin, modifiedPrice);

                string modifiedLine = "|   " + modifiedDrugId + "        |   " + modifiedDrugName + "                   |    " + modifiedPurpose + "                  |    "+ modifiedPrice + "            |";

                cout << "Medicine details modified successfully." << endl;
                cout << "Modified Medicine Details:" << endl;
                cout << modifiedLine << endl;

                fileContent.push_back(modifiedLine);
            } else {
                fileContent.push_back(line);
            }
        }

        file.close();

        if (!found) {
            cout << "No medicine found with the given ID." << endl;
        } else {
            ofstream outFile("takeOrder.txt", ios::trunc);
            if (!outFile) {
                cout << "Error opening file." << endl;
                return;
            }

            for (const string& line : fileContent) {
                outFile << line << endl;
            }

            outFile.close();
        }
    } else {
        cout << "Error opening file." << endl;
    }

    system("PAUSE");
    system("CLS");
}



// Exit Function

void pharmacyManagementSystem::exit()
{
    cout << "\nYou Chose To Exit" << endl;
    cout << "Thank You So Much!\n"
         << endl;
    system("CLS");
         pharmacyManagementSystem obj;
    obj.userSelection();
    system("PAUSE");
}

void delay(int milliseconds)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
        ;
}

// Admin/Customer Selection
void pharmacyManagementSystem::userSelection()
{
    string userName, passWord = "";
    int choice;
    int L_PER_INCR = 2;
    do
    {
        cout << "\t\t\t===============================================================\n";
        cout << "\n\t\t\t\t\t    THE OXFORD COLLEGE OF ENGINEERING \n";
        cout << "\n\t\t\t\t\t    DEPARTMENT OF INFORMATION SCIENCE \n";
        cout << "\n\t\t\t\t\t    File Structure Mini Project   \n";
        cout << "\t\t\t----------------------------------------------------------------";
        cout << "\n\t\t\t\t\t    Pharmacy Management System \n";
        cout << "\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t||\t1. Admin \t\t\t\t||\n";
        cout << "\t\t\t\t||\t2. Customer \t\t\t\t||\n";
        cout << "\t\t\t\t||\t3. Exit \t\t\t\t||\n";
        cout << "\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n\t\t\t\tEnter The Username : ";
            cin.ignore();
            getline(cin, userName);
            cin.ignore();
            cout << "\t\t\t\tEnter The Password : ";
            getline(cin, passWord);
            if (!(strcmp((userName.c_str()), ("Admin 1"))) && (passWord == "12345") || !(strcmp((userName.c_str()), ("Admin 2"))) && !(strcmp((passWord.c_str()), ("54321"))))
            {
                cout << "\n\t\t\t\t******************Access Granted******************\n"
                     << endl;
                sleep(3);
                for (int i = 0; i <= 100; i++)
                {
                    system("CLS");
                    cout << "\n";
                    cout << "LOADING : ";
                    for (int j = 0; j < i / L_PER_INCR; j++)
                        cout << char(219);
                    cout << " " << i << " %";
                    delay(10 / L_PER_INCR);
                }
                sleep(1);
                system("CLS");
                mainMenu(); // Calling Of Main Menu To Run
            }
            else
            {
                cout << "\n\t\t\t\t******************Access Denied*******************\n\n";
                system("PAUSE");
                system("CLS");
            }
            break;
        }

        case 2:
        {
            system("CLS");
            int c;
            do
            {
                cout << "===================================================================================================================\n";
                cout << "\n\t\t\t\t\t    Pharmacy Management System \n";
                cout << "-------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\t||\t1. Search For The Medicine  \t\t||\n";
                cout << "\t\t\t\t||\t2. Display Available Medicine \t\t||\n";
                cout << "\t\t\t\t||\t3. Exit \t\t\t\t||\n";
                cout << "-------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\tEnter Your Choice: ";
                cin >> c;
                switch (c)
                {
                case 1:
                {
                    search();
                    break;
                }
                case 2:
                {
                    displayMedicine();
                    break;
                }
                case 3:
                {
                    exit();
                    system("CLS");
                    break;
                }

                default:
                {
                    cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                         << endl;
                    break;
                }
                }
            } while (c != 3);
            break;
        }
        case 3:
            system("CLS");
        {
            cout << "==========================================================================================================\n" << endl;
             cout<<"\n \n \n \t\t\t Thankyou for using our service \n \n \n";
             cout << "\n==========================================================================================================" << endl;
            std::exit(0);
            break;
        }
        default:
        {
            cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                 << endl;
            break;
        }
        }
    } while (choice != 3);
}

void Type(const char *p)
{
    if (NULL == p)
        return;

    while (*p)
    {
        printf("%c\xDB", *p++);
        ::Sleep(1);
        printf("\b \b");
        ::Sleep(1);
    }
    ::Sleep(1);
}

// Main Function
int main(void)
{
    system("CLS");
    system("COLOR 7");
    pharmacyManagementSystem pharmacyManagementSystemObj;
    Type("\t\t\t================================================================\n");
    Type("\t\t\t\t\tTHE OXFORD COLLEGE OF ENGINEERING\n\n");
    Type("\t\t\t\t\tDEPARTMENT OF INFORMATION SCIENCE\n\n");
    Type("\t\t\t\t\tFILE STRUCTURE MINI PROJECT\n");
    Type("\t\t\t---------------------------------------------------------------\n");
    Type("\t\t\t\t\tPHARMACY MANAGMENT SYSTEM \t\t\n");
    Type("\t\t\t---------------------------------------------------------------\n");
    Type("\t\t\t\t\tDone By :                          \t\t\n");
    Type("\t\t\t\t\tKusuma Sree A      1OX20IS001 \t\t\n");
    Type("\t\t\t\t\tAkanksha           1OX20IS008 \t\t\n");
    Type("\t\t\t\t\tAlfahad Basha A    1OX20IS009 \t\t\n");
    Type("\t\t\t\t\tManvi Shah         1OX20IS044 \t\t\n");
    Type("\t\t\t================================================================\n");
    sleep(1);
    system("CLS");
    pharmacyManagementSystemObj.userSelection(); // Calling User Selection Page To Run
    return 0;
}
/***************************************END OF PROGRAM***************************************/

