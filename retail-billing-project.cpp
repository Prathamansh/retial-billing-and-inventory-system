#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<vector>
using namespace std;

// Global variable declaration
int k=7,r=0,flag=0;
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct date
{
    int mm,dd,yy;
};

class item
{
public:
    int itemno;
    char name[25];
    date d;
    float price, qty, tax, dis, netamt;

    void add()
    {
        cout<<"\n\n\tItem No: ";
        cin>>itemno;
        cout<<"\n\n\tName of the item: ";
        cin>>name;
        cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
        cout<<"\n\n\tPrice: ";
        cin>>price;
        cout<<"\n\n\tQuantity: ";
        cin>>qty;
        cout<<"\n\n\tTax percent: ";
        cin>>tax;
        cout<<"\n\n\tDiscount percent: ";
        cin>>dis;
        calculate();
    }
    void calculate()
    {
        float gross = price + (price * (tax / 100));
        netamt = qty * (gross - (gross * (dis / 100)));
    }
    void show()
    {
        cout<<"\n\tItem No: "<<itemno;
        cout<<"\n\tName: "<<name;
        cout<<"\n\tDate: "<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
        cout<<"\n\tPrice: "<<price;
        cout<<"\n\tQuantity: "<<qty;
        cout<<"\n\tTax: "<<tax<<"%";
        cout<<"\n\tDiscount: "<<dis<<"%";
        cout<<"\n\tNet amount: "<<netamt;
    }
    void saveToFile(ofstream& file)
    {
        file << itemno << " " << name << " " << d.mm << " " << d.dd << " " << d.yy << " " 
             << price << " " << qty << " " << tax << " " << dis << " " << netamt << endl;
    }
};

void loadPredefinedItems()
{
    ifstream file("items.txt");
    if (!file.good())
    {
        ofstream file("items.txt");
        file << "1 Rice 01 01 2024 50 100 5 10 4500\n";
        file << "2 Sugar 02 02 2024 40 50 5 5 1900\n";
        file << "3 Milk 03 03 2024 30 20 5 2 588\n";
        file << "4 Bread 04 04 2024 25 30 5 3 700\n";
        file << "5 Butter 05 05 2024 60 10 5 5 570\n";
        file << "6 Eggs 06 06 2024 10 100 5 2 950\n";
        file << "7 Cheese 07 07 2024 90 5 5 10 405\n";
        file << "8 Salt 08 08 2024 20 25 5 2 475\n";
        file << "9 Oil 09 09 2024 120 15 5 8 1665\n";
        file << "10 Flour 10 10 2024 45 35 5 6 1480\n";
        file.close();
    }
    file.close();
}

void displayItems()
{
    ifstream fin("items.txt");
    item amt;
    cout << "\n\tItem List";
    cout << "\n---------------------------------------------------";
    while (fin >> amt.itemno >> amt.name >> amt.d.mm >> amt.d.dd >> amt.d.yy >> amt.price >> amt.qty >> amt.tax >> amt.dis >> amt.netamt)
    {
        amt.show();
        cout << "\n---------------------------------------------------";
    }
    fin.close();
}

void editItem(int ino)
{
    ifstream fin("items.txt");
    ofstream fout("temp.txt");
    item amt;
    int found = 0;
    while (fin >> amt.itemno >> amt.name >> amt.d.mm >> amt.d.dd >> amt.d.yy >> amt.price >> amt.qty >> amt.tax >> amt.dis >> amt.netamt)
    {
        if (amt.itemno == ino)
        {
            cout << "\nEditing Item No: " << ino;
            amt.add();
            found = 1;
        }
        amt.saveToFile(fout);
    }
    fin.close();
    fout.close();
    remove("items.txt");
    rename("temp.txt", "items.txt");
    if (found)
        cout << "\nItem successfully edited!";
    else
        cout << "\nItem not found!";
}

void deleteItem(int ino)
{
    ifstream fin("items.txt");
    ofstream fout("temp.txt");
    item amt;
    int found = 0;
    while (fin >> amt.itemno >> amt.name >> amt.d.mm >> amt.d.dd >> amt.d.yy >> amt.price >> amt.qty >> amt.tax >> amt.dis >> amt.netamt)
    {
        if (amt.itemno != ino)
        {
            amt.saveToFile(fout);
        }
        else
        {
            found = 1;
        }
    }
    fin.close();
    fout.close();
    remove("items.txt");
    rename("temp.txt", "items.txt");
    if (found)
        cout << "\nItem successfully deleted!";
    else
        cout << "\nItem not found!";
}

void generateBill()
{
    vector<pair<int, float>> billItems; // pair of itemno and quantity
    char ch;
    float total = 0;
    
    do {
        system("cls");
        displayItems();
        cout << "\n\nEnter Item Number to bill: ";
        int ino;
        cin >> ino;
        cout << "Enter Quantity: ";
        float qty;
        cin >> qty;

        ifstream fin("items.txt");
        ofstream fout("temp.txt");
        item amt;
        bool found = false;
        
        while (fin >> amt.itemno >> amt.name >> amt.d.mm >> amt.d.dd >> amt.d.yy >> amt.price >> amt.qty >> amt.tax >> amt.dis >> amt.netamt)
        {
            if (amt.itemno == ino)
            {
                found = true;
                if (amt.qty >= qty)
                {
                    billItems.push_back({ino, qty});
                    float unitPrice = (amt.price + (amt.price * (amt.tax/100))) * (1 - (amt.dis/100));
                    total += unitPrice * qty;
                    amt.qty -= qty;
                    amt.calculate();
                    cout << "\nAdded " << qty << " " << amt.name << " to bill";
                }
                else
                {
                    cout << "\nWarning: Only " << amt.qty << " " << amt.name << " available in stock!";
                }
            }
            amt.saveToFile(fout);
        }
        fin.close();
        fout.close();
        remove("items.txt");
        rename("temp.txt", "items.txt");

        if (!found)
            cout << "\nItem not found!";

        cout << "\nAdd more items? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    // Display bill
    system("cls");
    cout << "\n\t\tBILL";
    cout << "\n-----------------------------------------------";
    cout << "\nItem No\tName\tQty\tPrice\tTotal";
    cout << "\n-----------------------------------------------";
    
    for (auto& billItem : billItems)
    {
        ifstream fin("items.txt");
        item amt;
        while (fin >> amt.itemno >> amt.name >> amt.d.mm >> amt.d.dd >> amt.d.yy >> amt.price >> amt.qty >> amt.tax >> amt.dis >> amt.netamt)
        {
            if (amt.itemno == billItem.first)
            {
                float unitPrice = (amt.price + (amt.price * (amt.tax/100))) * (1 - (amt.dis/100));
                cout << "\n" << amt.itemno << "\t" << amt.name << "\t" << billItem.second 
                     << "\t" << unitPrice << "\t" << unitPrice * billItem.second;
                break;
            }
        }
        fin.close();
    }
    cout << "\n-----------------------------------------------";
    cout << "\nTotal Amount: " << total;
    cout << "\n-----------------------------------------------";
}

int main()
{
    loadPredefinedItems();
    int choice;
    do
    {
        system("cls");
        cout << "\n1. Add Item";
        cout << "\n2. Display Items";
        cout << "\n3. Edit Item";
        cout << "\n4. Delete Item";
        cout << "\n5. Generate Bill";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            item newItem;
            newItem.add();
            ofstream fout("items.txt", ios::app);
            if (fout.is_open())
            {
                newItem.saveToFile(fout);
                fout.close();
                cout << "\nItem Added Successfully!";
            }
            else
            {
                cout << "\nError opening file!";
            }
        }
        break;
        case 2:
            displayItems();
            break;
        case 3:
        {
            int ino;
            cout << "\nEnter Item Number to Edit: ";
            cin >> ino;
            editItem(ino);
        }
        break;
        case 4:
        {
            int ino;
            cout << "\nEnter Item Number to Delete: ";
            cin >> ino;
            deleteItem(ino);
        }
        break;
        case 5:
            generateBill();
            break;
        case 6:
            exit(0);
        default:
            cout << "\nInvalid choice! Try again.";
        }
        getch();
    } while (choice != 6);
    return 0;
}