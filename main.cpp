#include<iostream>
#include <windows.h>
#include<conio.h>
#include<fstream>
#include <string>
#include <vector>
using namespace std;
int totalproducts = 0;
double totalPrice = 0;
char bar = 219;
class shop
{
public:
    string CartedItems[100];
    int CartedQuantity[100];
    double CartedPrice[100];
    int cartIndex = 0;

    void Carted(string item, int quantity, double price)
    {
        CartedItems[cartIndex] = item;
        CartedQuantity[cartIndex] = quantity;
        CartedPrice[cartIndex] = price;
        cout << item << " " << "Added to the cart!!!";
        cartIndex+=1;
    }


    void displayCart()
    {
        cout << "\n\nItems in the cart:\n" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Quantity      Name                               Price" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < cartIndex; ++i)
        {
            cout << "  " << CartedQuantity[i];
            cout << "\t     " << CartedItems[i] ;
            cout << "\t     \t\t" << CartedPrice[i] << " Rupees "<< endl;
        }
        cout << endl << "-----------------------------------------------------------" << endl;
        cout << "\tTotal price is: \t\t\t" << totalPrice << " Rupees" << endl;
    }
};



class user
{
private:
    string password, nickname,Address,Contact,gmail;
    int balance = 0;
public:

    string attempt;
    string username;
    bool returns = true;
    string getNickname() const { return nickname; }
    string getAddress() const { return Address; }
    string getContact() const { return Contact; }
    string getGmail() const { return gmail; }
    int getBalance() const { return balance; }
    void print(int *k)
    {
        int ch;
        system("COLOR B");
        system ("cls");
        cout << "                          Welcome to Online Shopping System!!!                       " << endl;
        cout<<"\n\n \t\t\t\t\t1) LOGIN    \n\t\t\t\t\t2) SIGN UP  \n\n\t\t\t\t\tEnter choice  :";
        cin>>ch;
        if (ch==1)
{
     login(k);
}
        if (ch==2)
        {
            user1(k);
        }
        getch();
    }
     bool  login(int*k) {
    string &fileUsername=username,&filenickname=nickname, &filePassword=password, &fileContact=Contact, &fileAddress=Address, &fileGmail=gmail;
    int &fileBalance=balance;
    system("COLOR 0B");
    system("cls");
    cout << "                          Welcome Back to Online Shopping System!!!                       " << endl;
    cout << endl;
    cout << "Please login to continue Shopping" << endl;
    cout << "Enter Your username: ";
    cin>>ws;
    getline(cin>>ws, username);
    cout << "Enter Your Password: ";
    cin>>ws;
    string password;
    getline(cin>>ws, password);
    ifstream read("user_data.txt");
    if (!read.is_open()) {
        cout << "Unable to open file" << endl;
        return false;
    }

    while (getline(read, fileUsername)) {
            getline(read, filenickname);
        getline(read, filePassword);
        getline(read, fileContact);
        getline(read, fileAddress);
        getline(read, fileGmail);
        read >> fileBalance;
        read.ignore();
        if (username == fileUsername && password == filePassword)
            {
            read.close();
            cout << "Login Successful!" << endl;
            *k=1;
            return true;
        }

    }

}

    user1(int *k)
    {

    system("COLOR 0B");
        system ("cls");
        cout << "                          Welcome to Online Shopping System!!!                       " << endl;
        cout <<endl;
        cout<< "Please create an Account to continue Shopping" << endl;
           cout << "Enter Your username: ";

    getline(cin>>ws, username);

    cout<<"enter your nickname:";
    getline(cin>>ws,nickname);
    cout << "Enter Your Password: ";

    getline(cin>>ws, password);
    cout << "Contact Number: ";

    getline(cin>>ws, Contact);
    cout << "Address: ";

    getline(cin>>ws, Address);
    cout << "Add some balance to buy products: ";

    cin >> balance;
    cin.ignore();
    cout << "Enter Gmail: ";
    string gmail;
    getline(cin>>ws, gmail);


    ofstream write("user_data.txt", ios::app);
    if (write.is_open()) {
        write << username << '\n' <<nickname<< '\n' << password << '\n' << Contact << '\n' << Address << '\n' << gmail << '\n' << balance << '\n';
        write.close();
    } else {
        cout << "Unable to open file";
    }
        system("cls");
		system("COLOR 0A");

		cout<<" \n\n\n\n\n\n  \t   \t\t\t  CREATING YOUR ACCOUNT....."<<endl;
		 for(int j=0;j<67500;j++);
    	cout<<"              \t\t\t";

   for(int j=0;j<30;j++)
    {
        Sleep(200);
        system("COLOR 0A");
            cout<<bar;
    }

	system("cls");
		cout<<"  \n\n\n\n       \t                               ACCOUNT REGISTERED!                                                 "<<endl;
		Sleep(2000);
  *k=1;
    }

    bool checkout()
    {
        string checkpass;
trypassagain:
        cout << endl <<"Enter your password to confirm Checkout or (Type 0 to return Main Menu): ";
        cin>>ws;
        getline(cin,checkpass);
        if(checkpass == "0")
           returns = false;
        else if(checkpass == password)
        {
            if(balance < totalPrice)
            {
                cout << "Insufficient Balance!!" << endl;
                cout << "Please add balance from (My Account and balance)" << endl << endl;
                returns = false;
            }
            else
            {
                balance -= totalPrice;
                cout << "-------------------------------------------" << endl ;
                cout << "     Purchase Successful !!! " << endl;
                cout << "    Your current balance is " << balance << " Rupees"<< endl;
                cout << "-------------------------------------------" << endl ;
                cout << "* ";
                cout << endl << "* Thank You For shopping !!! *" << endl;
                cout << "    Hope you Have a lovely day!!!      " << endl;
                cout << "*" << endl;
                returns = true;
                return 1;
            }
        }
        else
        {
            cout << endl << "Wrong Password!!! " << endl;
            cout << "If forgot password Please go My Account and Balance to Reset Password " << endl;
            goto trypassagain;
        }
    }

    void showbalance()
    {
        cout << "  Your balance is " << balance << "Rupees" << endl;
        cout << "-----------------------------------------" << endl;
    }
    void addbalance()
    {
        int extrabalance;
        cout << "Enter amount to add: ";
        cin >> extrabalance;
        balance += extrabalance;
        cout  << extrabalance << " Rupees added successfully " << endl;
        cout << "Current Balance is " << balance << " Rupees"<< endl;
        cout << "-----------------------------------------" << endl;
        extrabalance = 0;
    }
    void displayuserdata()
    {
attemptagain:
        cout << "Enter Your password: ";
        getline(cin,attempt);
        if(attempt == password)
        {
            cout << "Your UserName is :" << username << endl;
            cout << "Your nickname is :" << nickname << endl;
            cout << "Your Address is  :" << Address << endl;
            cout << "Your Contact Number is: "<< Contact << endl;
            cout << "Your Balance is :" << balance << " Rupees" << endl;
            cout << "-----------------------------------------" << endl;

        }
        else
        {
            cout << "Wrong password!!! Try Again!!!" << endl;
            goto attemptagain;
        }

    }
    void forgetpass()
    {
        string forgetnick;
forgetnickname:
        cout << "Enter your nickname: ";
        getline(cin,forgetnick);
        if(forgetnick == nickname)
        {
            cout << "Enter your new Password: ";
            getline(cin,password);
            cout << "Password reset Successful....." <<endl;
        }
        else
        {
            cout << "Wrong Nickname!!! Try Again!!!" << endl;
            goto forgetnickname;
        }
    }
};
class Gmail {
public:
    void sendEmail(string recipient, string subject, string body)
    {
        cout << "\nSending email to: " << recipient << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
        cout << "Email sent successfully!" << endl;
    }
};

string generateEmailBody(shop &Shop, user &User) {
    string body = "Dear " + User.getNickname() + ",\n\n";
    body += "Thank you for shopping with us!\n\n";
    body += "Your purchased items:\n";
    for (int i = 0; i < Shop.cartIndex; ++i) {
        body += "Item: " + Shop.CartedItems[i] + ", Quantity: " + to_string(Shop.CartedQuantity[i]) + ", Total Price: " + to_string(Shop.CartedPrice[i]) + " Rupees\n";
    }

    body += "Shipping Details:\n";
    body += "Address: " + User.getAddress() + "\n";
    body += "Contact Number: " + User.getContact() + "\n";
    body += "\n\nThank you!\n";
    body += "Best Regards,\nYour Online Shopping Team";
    return body;
}


class Footware
{
    public:
    int FootwareIndex = 15;
    int FootwareID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int FootwarePrice[15] = {4000,3300,2500,2700,1500,3200,3200,1200,1200,1300,3700,3300,4500,1000,4999};
    string FootwareItems[100] = { "Men's Running Shoes (Black)              ",
                                 "Strap Heeled Pumps (Gray)                 ",
                                 "Chuck Taylor  Sneakers (White)            ",
                                 "Sneakers (White and Metallic Cherry)      ",
                                 "Rubber Shoes (Black)                      ",
                                 "Sneakers (Black)                          ",
                                 "Sneakers (White)                          ",
                                 "Ladies Rubber Shoes (White)               ",
                                 "Ladies Rubber Shoes (Navy Blue)           ",
                                 "Rubber Shoes (White)                      ",
                                 "Broad Heels( Golden)                      ",
                                 "Sandels (White)                           ",
                                 "Block Heel(Black)                         ",
                                 "Khussa (Multi)                            ",
                                 "Pencil Heels(Black)                       ",
                               };
    string FootwareQuantity[100] = {"1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                    "1 pair",
                                  };
public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "ProductID     Name                                                                Price                                          Quantity           " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for(int i = 0; i < FootwareIndex; ++i)
        {
            cout << " " << FootwareID[i];
            cout << "\t  " << FootwareItems[i] ;
            cout << "\t                         " << FootwarePrice[i] << " Rupees ";
            cout << "\t                              " << FootwareQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
};


class Perfume
{
    public:
    int PerfumeIndex = 15;
    string PerfumeItems[100] = {"Janan        ",
                                 "Blue lady   ",
                                 "Chichi Michi",
                                 "Fog         ",
                                 "Secret      ",
                                 "Floral      ",
                                 "Aventus     ",
                                 "Eros        ",
                                 "Charisma    ",
                                 "Voyage      ",
                                 "Blossom     ",
                                 "Jazmin      ",
                                 "Zarar       ",
                                 "She         ",
                                 "Havoc       ",
                                };

    int PerfumeID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int PerfumePrice[15] = {6500,2500,1700,1800,1300,2000,3200,3400,4300,7200,4200,5500,5700,2500,2200};

    string PerfumeQuantity[15] = { "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",
                                   "1 pck",

                                  };

public:
    void displayProducts()
    {
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "ProductID      Name                       Price                           Quantity                " << endl;
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        for(int i = 0; i < PerfumeIndex; ++i)
        {
            cout << "  " << PerfumeID[i];
            cout << "\t       " << PerfumeItems[i] ;
            cout << "\t           " << PerfumePrice[i] << " Price";
            cout << "\t              " << PerfumeQuantity[i] << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    }
};


class Toys
{
    public:
    int KidsToysIndex = 15;
    string KidsToysItems[100] = { "Teddy Bear         ",
                                  "Rocking dog       ",
                                  "Toy Car          ",
                                  "Tennis Ball      ",
                                  "Toy Train        ",
                                  "Basketball       ",
                                  "Kite             ",
                                  "Rubik'sCube      ",
                                  "Tricycle         ",
                                  "Crayons         ",
                                  "Dice           ",
                                  "Dominoes       ",
                                  "Airplane         ",
                                  "Robot           ",
                                  "Bicycle         "
                                };
    int KidsToysID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int KidsToysPrice[15] = {1330,2113,2345,254,2314,1410,1630,1011,1033,1050,1715,1313,1452,1953,10000};
    string KidsToysQuantity[15] = {"1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs"
                                  };
public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < KidsToysIndex; ++i)
        {
            cout << "  " << KidsToysID[i];
            cout << "\t    " << KidsToysItems[i] ;
            cout << "\t" << KidsToysPrice[i] << " Rupees ";
            cout << "\t" << KidsToysQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};


class Jewelry
{
    public:
    int JewelryItemsIndex = 15;
    string JewelryItems[15] = {"Brooches      ",
                               "Rings        ",
                               "Necklaces    ",
                               "Earrings    ",
                               "Pendants    ",
                               "Cuff-links    ",
                               "Nose pin     ",
                               "Bracelet     ",
                               "Chain       ",
                               "Hairpin     ",
                               "Beads       ",
                               "Anklet      ",
                               "Watch         ",
                               "Crown         ",
                               "Choker        "
                              };

    int JewelryItemsID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int JewelryItemsPrice[15] = {330,300,1000,900,515,100,910,573,733,850,754,356,1458,1521,522};
    string JewelryItemsQuantity[15] = {"1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs"
                                      };

public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < JewelryItemsIndex; ++i)
        {
            cout << "  " << JewelryItemsID[i];
            cout << "\t    " << JewelryItems[i] ;
            cout << "\t" << JewelryItemsPrice[i] << "Rupees ";
            cout << "\t" << JewelryItemsQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};


class Cloths
{
    public:
    int ClothsIndex = 15;
    string ClothsItems[100] = {"Saree        ",
                               "Shirt        ",
                               "Pant        ",
                               "Abaya       ",
                               "Hijab       ",
                               "Three-piece   ",
                               "Panjabi    ",
                               "Skirt and tops ",
                               "Nikab         ",
                               "Gown        ",
                               "Sweater      ",
                               "Scarf (Muffler) ",
                               "Coat        ",
                               "Orna        ",
                               "Socks      "
                              };

    int ClothsID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int ClothsPrice[15] = {1500,1000,1700,2100,600,1400,1800,1200,400,2500,2600,200,2700,900,150};

    string ClothsQuantity[15] = {"1 pcs",
                                 "1 pcs",
                                 "1 pcs ",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs ",
                                 "1 pcs",
                                 "1 pcs ",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",

                                };
public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < ClothsIndex; ++i)
        {
            cout << "  " << ClothsID[i];
            cout << "\t     " << ClothsItems[i] ;
            cout << "\t" << ClothsPrice[i] << " Rupees ";
            cout << "\t" << ClothsQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};


class cart
{
    int id;
    string name;
    double price;
    int quantity;

public:
    void addcart(double c, int d)
    {

        price = c * d;
        quantity = d;
        calculateTotal();
    }

    void calculateTotal()
    {
        totalPrice += price;
        cout <<"\nCurrent total is " << totalPrice << " " << "Rupees" << endl;
        cout << "*"<< endl;
    }
};


class run :public Toys ,public Jewelry ,public Cloths, public cart, public Perfume ,public shop, public Footware, public Gmail
{
public:
void  runp()
  {
         ///Object Create
    user User;
    cart product;
    shop Shop;
    Footware ft;
    Perfume per;
    Toys toy;
    Jewelry jew;
    Cloths cloth;
    Gmail gmail;

    int i = totalproducts;
    int choice2;
    double ProPrice = 0;
    int option = 0, choice, quantity;
    string  items;

int k=0;

    User.print(&k);
   if(k==1){
mainmenu:
    cout << "\n\t\t\t ----------------Welcome to Online Shopping System!!!------------------" << endl;
    cout << "\t\t\t ----------------- What would you like to buy?-------------------" << endl << endl;
    cout << "1. Footwares" << endl;
    cout << "2. Perfumes " << endl;
    cout << "3. Toy Items" << endl;
    cout << "4. Jewelry Items" << endl;
    cout << "5. Cloths Items" << endl;
    cout << "6. My Account and Balance" << endl;
    cout << "7. Show All Products" << endl;
    cout << "8. Show my carted Products and Checkout" << endl << endl;

    cout << "Enter an option: ";
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
    {
foot:
        cout << "\n\n\t\t\tChoose Your  Footwares" << endl;
        ft.displayProducts();
        for(i = totalproducts; i< 100; i++)
        {
choiceFootware:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

           if(choice>0&&choice<15)

            {
              ProPrice =ft.FootwarePrice[choice -1];
                items=ft.FootwareItems[choice -1];
                Shop.Carted(items, quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;

            }
            else
                cout << "Invalid choice!" << endl;

            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Footware Section , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto foot;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceFootware;
            }
        }
    }
    break;


    case 2:
    {
perf:
        cout << "\n\n\t\t\tChoose Your Perfumes" <<endl ;
        per.displayProducts();
        for(i = 0; i< 100; i++)
        {
choiceper:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            if(choice>0&&choice<15)

            {
                ProPrice =per.PerfumePrice[choice -1];
                items=per.PerfumeItems[choice -1];
                Shop.Carted(items, quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                }
            else
                cout << "Invalid choice!" << endl;



            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Perfume Store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto perf;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceper;
            }
        }


    }
    break;


    case 3:
    {
toyss:
        cout << "\n\n\t\t\tChoose Your Toys Item" << endl;
        toy.displayProducts();
        for(i = 0; i< 100; i++)
        {
choicetoys:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            if(choice>0&&choice<15)

            {
                ProPrice =toy.KidsToysPrice[choice -1];
                items=toy.KidsToysItems[choice -1];
                Shop.Carted(items, quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
             }
            else
                cout << "Invalid choice!" << endl;

            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Toys store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto toyss;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choicetoys;
            }
          }


    }
    break;


    case 4:
    {

Jewelrys:
        cout << "\n\n\t\t\tChoose Your Jewelry Item" << endl;
        jew.displayProducts();
        for(i = 0; i< 100; i++)
        {
choiceJewelry:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

             if(choice>0&&choice<15)

            {
                ProPrice =jew.JewelryItemsPrice[choice-1];
                items=jew.JewelryItems[choice -1];
                Shop.Carted(items, quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;

            }
            else
                cout << "Invalid choice!" << endl;

            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Jewelry store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto Jewelrys;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceJewelry;
            }
        }

    }
    break;


    case 5:
    {

Clothsc:
        cout << "\n\n\t\t\tChoose Your Cloths Item" << endl;
        cloth.displayProducts();
        for(i = 0; i< 100; i++)
        {
choiceCloths:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

             if(choice>0&&choice<15)

            {
                ProPrice =cloth.ClothsPrice[choice-1];
                items=cloth.ClothsItems[choice -1];
                Shop.Carted(items, quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                }
            else
                cout << "Invalid choice!" << endl;
            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Cloths store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto Clothsc;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceCloths;
            }
        }
    }
    break;


    case 6:
    {
        int userchoice;
userchoiced:
        cout << endl << "1. Check Balance " << endl;
        cout << "2. Add More Balance " << endl;
        cout << "3. Show my all data " << endl;
        cout << "4. Reset password " << endl;
        cout << "5. Return to Main Menu " << endl;
        cin >> userchoice;
        cin.ignore();
        if(userchoice == 1)
            User.showbalance();
        else if(userchoice == 2)
            User.addbalance();
        else if(userchoice == 3)
            User.displayuserdata();
        else if(userchoice == 4)
            User.forgetpass();
        else if(userchoice == 5)
            goto mainmenu;
        else
        {
            cout << "Invalid Choice!!!" << endl;
            goto userchoiced;
        }
        goto mainmenu;
    }
    break;



    case 7:
    {
        cout << "\n\n\t\tFootware" << endl;
        ft.displayProducts();
        cout << "\n\n\t\tPerfume Products" << endl;
        per.displayProducts();
        cout << "\n\n\t\tToys Items" << endl;
        toy.displayProducts();
        cout << "\n\n\t\tJewelry Items" << endl;
        jew.displayProducts();
        cout << "\n\n\t\tCloths Items" << endl;
        cloth.displayProducts();
        goto mainmenu;
    }
    break;
    case 8:
    {
        Shop.displayCart();
        User.checkout();
        if(User.returns == false)
            goto mainmenu;
        else
        {

         gmail.sendEmail(User.getGmail(), "Shopping and Shipping Details", generateEmailBody(Shop, User));
            exit(0);
        }
    }
    break;
    }
  }
  else{User.print(&k);}
  }
};
int main()
{

run r;
r.runp();
return 0;
}

