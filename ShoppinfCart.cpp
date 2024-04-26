#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void clearScreen()
{ // Clear the screen based on the operating system
#ifdef _WIN32
    std::system("cls");
#else
  // Assume UNIX-like system
    std::system("clear");
#endif
}
class Product
{
protected:
    string brand;
    int price;

public:
    void dashboard();
    void account(string arr[], int n);
    void sign_up();
    void sign_in();
    void printCategory(const string &categoryName, const string arr[][3], int size);
};
void addUser(const string &username, const string &password)
{
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
}
bool doesUserExist(const string &username, const string &password)
{
    ifstream file("users.txt");
    string line;
    string check = username + " " + password;
    while (getline(file, line))
    {
        if (line == check)
        {
            return true;
        }
    }
    return false;
}
void Product::sign_in()
{
    cout << "\n\nYou are on the Sign-in Page\n"
         << "\nEnter your Card ID: ";
    string username;
    cin >> username;
    cout << "\nEnter card cvv: ";
    string password;
    cin >> password;
    bool ans = doesUserExist(username, password);
    if (ans)
    {
        cout << "\n\n-----------------------------------------------------------------------------------------------------" << "\nWelcome again " << username << "!\n"
             << "\nYour payment is successful!" << "\nThank for buying with us\n"
             << "\nDo you want to buy anything else? " << "\nEnter 'y' for Yes and 'n' for No: ";
        char ask;
        cin >> ask;
        while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
        {
            cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
            cin >> ask;
        }
        if (ask == 'y' || ask == 'Y')
        {
            dashboard();
        }
        else
        {
            cout << "\nThank you. Visit again!" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "User does not exist. Please Sign-up." << endl;
        sign_up();
    }
}
void Product::sign_up()
{
    cout << "-----------------------------------------------------------------------------------------------------";
    cout << "\nYou are on the Sign-up Page" << "\n\nEnter your Card ID: ";
    string newuser;
    cin >> newuser;
    cout << "\nEnter card cvv: ";
    string newpassword;
    cin.ignore();
    getline(cin, newpassword);
    if (doesUserExist(newuser, ""))
    {
        cout << "Username already exists. Please sign in if you have an account." << endl;
        return;
    }
    addUser(newuser, newpassword);
    cout << "-----------------------------------------------------------------------------------------------------" << "\nWelcome " << newuser << "! You have been signed up." << "\nYour payment is successful!" << "\nThank you for buying with us." << "\nDo you want to buy anything else?\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        dashboard();
    }
    else
    {
        cout << "\nThank you. Visit again!" << endl;
        exit(0);
    }
}
void Product::account(string arr[], int n)
{
    cout << "---------------------------------------CART------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nYour Total Bill is " << arr[1] << endl
         << "\nSign-in / Sign-up CARD to buy the product\n"
         << "\nEnter '1' to Sign-in and '2' to Sign-up: ";
    int opt;
    cin >> opt;
    while (opt != 1 && opt != 0)
    {
        cout << "Invalid input. Please enter '1' for Yes or '0' for No: ";
        cin >> opt;
    }
    switch (opt)
    {
    case 1:
        sign_in();
        break;
    case 2:
        sign_up();
        break;
    }
}
void Product::printCategory(const string &categoryName, const string arr[][3], int size)
{
    clearScreen();
    cout << "------------------------------------------" << categoryName << "-----------------------------------------------" << endl
         << "------------------------------------------------------------------------------------------------" << endl
         << "|" << setw(7) << "Product Number" << setw(8) << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty/Size" << setw(15) << "|" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "-----------------------------------------------------------------------------------------------" << endl
             << "|" << setw(7) << i + 1 << setw(8) << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------" << endl
         << "\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
}
class fashion : public Product
{
public:
    void fashion_dashboard();
    void mens_wear();
    void womens_wear();
    void kids_wear();
    void further_action();
};
void fashion::fashion_dashboard()
{
    cout << "--------------------------------------------FASHION DASHBOARD------------------------------------------------\n"
         << "1) Men's Wear\n\n"
         << "2) Women's Wear\n\n"
         << "3) Kids Wear\n\n";
    int option;
    cout << "Please select the sub-category: ";
    cin >> option;
    switch (option)
    {
    case 1:
        mens_wear();
        break;
    case 2:
        womens_wear();
        break;
    case 3:
        kids_wear();
        break;
    }
}
void fashion::mens_wear()
{
    string mensWear[5][3] = {{"Formal Shirt", "Rs 1000", "Small/Medium/Large"}, {"T-shirt", "Rs 850", "Small/Medium/Large"}, {"Jeans", "Rs 1500", "34"}, {"Trouser", "Rs 700", "38"}, {"Jacket", "Rs 2000", "Small/Medium/Large"}};
    printCategory("MEN'S WEAR", mensWear, 5);
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        cout << "\nWhich product you wish to buy?" << "\nEnter the product number you want to buy: ";
        int option;
        cin >> option;
        account(mensWear[option - 1], 3);
    }
    else
    {
        further_action();
    }
}
void fashion::womens_wear()
{
    string arr[5][3] = {{"Top", "Rs 800", "Small/Medium/Large"}, {"Kurti", "Rs 950", "Small/Medium/Large"}, {"Jeans", "Rs 2500", "28"}, {"Saree", "Rs 3700", "6 yards"}, {"Jacket", "Rs 3000", "Small/Medium/Large"}};
    printCategory("WOMEN'S WEAR", arr, 5);
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        cout << "\nWhich product you wish to buy?\n"
             << "Enter the product number you want to buy: ";
        int option;
        cin >> option;
        account(arr[option - 1], 3);
    }
    else
    {
        further_action();
    }
}
void fashion::kids_wear()
{
    string arr[5][3] = {{"T-shirt", "Rs 400", "Small/Medium/Large"}, {"Jeans", "Rs 550", "Small/Medium/Large"}, {"Frock", "Rs 600", "Small/Medium/Large"}, {"Skirt", "Rs 480", "Small/Medium/Large"}, {"Jacket", "Rs 800", "Small/Medium/Large"}};
    printCategory("KIDS WEAR", arr, 5);
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        cout << "\nWhich product you wish to buy?" << "\nEnter the product number you want to buy: ";
        int option;
        cin >> option;
        account(arr[option - 1], 3);
    }
    else
    {
        further_action();
    }
}
void fashion::further_action()
{
    cout << "\n\n";
    cout << "Do you want to select other options\n\n";
    cout << "1) Men's Wear\n\n";
    cout << "2) Women's Wear\n\n";
    cout << "3) Kids Wear\n\n";
    cout << "4) Main Dashboard\n\n";
    cout << "5) Fashion Dashboard\n\n";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        mens_wear();
        break;
    case 2:
        womens_wear();
        break;
    case 3:
        kids_wear();
        break;
    case 4:
        dashboard();
        break;
    case 5:
        fashion_dashboard();
        break;
    }
}
class electronics : public Product
{
public:
    void electronics_dashboard();
    void TV();
    void mobile();
    void fridge();
    void further_action();
};
void electronics::electronics_dashboard()
{
    cout << "---------------------------------------------ELECTRONICS DASHBOARD--------------------------------------------" << endl;
    cout << "1) TV\n\n";
    cout << "2) Mobile\n\n";
    cout << "3) Fridge\n\n";
    int option;
    cout << "Please select the sub-category: ";
    cin >> option;
    switch (option)
    {
    case 1:
        TV();
        break;
    case 2:
        mobile();
        break;
    case 3:
        fridge();
        break;
    }
}
void electronics::TV()
{

    string arr[3][3] = {{"Sony", "Rs 1,20,000",
                         "5 years warranty"},
                        {"LG", "Rs 85,000",
                         "2 years warranty"},
                        {"Samsung", "Rs 96,000",
                         "2 years warranty"}};
    printCategory("TV", arr, 3);
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        cout << "\nWhich product you wish to buy?" << endl;
        cout << "Enter the product number you want to buy: ";
        int option;
        cin >> option;
        account(arr[option - 1], 3);
    }
    else
    {
        further_action();
    }
}
void electronics::mobile()
{
    string arr[4][3] = {{"Iphone", "Rs 90,000", "1 years warranty"}, {"Oppo", "Rs 25,000", "2 years warranty"}, {"Samsung", "Rs 36,000", "2 years warranty"}, {"Realme", "Rs 15,000", "1 years warranty"}};
    printCategory("MOBILE", arr, 4);
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        cout << "\nWhich product you wish to buy?" << "\nEnter the product number you want to buy: ";
        int option;
        cin >> option;
        account(arr[option - 1], 3);
    }
    else
    {
        further_action();
    }
}
void electronics::fridge()
{
    string arr[3][3] = {{"Whirlpool", "Rs 25,000", "3 years warranty"}, {"LG", "Rs 35,000", "5 years warranty"}, {"Samsung", "Rs 31,000", "4 years warranty"}};
    printCategory("FRIDGE", arr, 3);
    char ask;
    cin >> ask;
    while (ask != 'y' && ask != 'Y' && ask != 'n' && ask != 'N')
    {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No: ";
        cin >> ask;
    }
    if (ask == 'y' || ask == 'Y')
    {
        cout << "\nWhich product you wish to buy?" << "\nEnter the product number you want to buy: ";
        int option;
        cin >> option;
        account(arr[option - 1], 3);
    }
    else
    {
        further_action();
    }
}
void electronics::further_action()
{
    cout << "\n\n"
         << "Do you want to select other options\n\n"
         << "1) TV\n\n"
         << "2) Mobile\n\n"
         << "3) Fridge\n\n"
         << "4) Main Dashboard\n\n"
         << "5) Electronics Dashboard\n\n";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        TV();
        break;
    case 2:
        mobile();
        break;
    case 3:
        fridge();
        break;
    case 4:
        dashboard();
        break;
    case 5:
        electronics_dashboard();
        break;
    }
}
void Product::dashboard()
{
    cout << "-------------------------------------------WELCOME TO SHOPPING CART--------------------------------------------\n"
         << "\nCategories\n\n"
         << "\n1) Fashion\n\n"
         << "\n2) Electronics\n\n"
         << "\n3) EXIT\n\n"
         << "Please select the category: ";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        fashion fashionObj;
        fashionObj.fashion_dashboard();
    }
    break;
    case 2:
    {
        electronics electronics;
        electronics.electronics_dashboard();
    }
    break;
    default:
        cout << "Thank you for visiting our Shopping Cart" << endl;
        return;
        break;
    }
}
int main()
{
    Product user;
    user.dashboard();
    return 0;
}