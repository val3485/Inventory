#include <vector>
#include "straps.h"
#include <algorithm> // required for transform / sort

class StrapsCRUD
{
private:
    Straps &s;
    vector<Straps::StrapItems> &allstraps_arr;


public:
    StrapsCRUD(Straps &str) : s(str), allstraps_arr(str.allstraps_arr) {}
    
    string name;
    int quantity;
    int price;
    string category;
    //  Straps::StrapItems newStrap(nextID, categ, color, brand, leather_type, quantity, size, price, hole);

    void addItems(int nextID ,string categ, string color, string brand, string leather_type, int quantity, string size,  int price, string hole)
    {
        // make categ lowercase
        transform(categ.begin(), categ.end(), categ.begin(),
                  [](unsigned char c)
                  { return tolower(c); });

        // make brand lowercase first, then capitalize first letter
        transform(brand.begin(), brand.end(), brand.begin(),
                  [](unsigned char c)
                  { return tolower(c); });
        if (!brand.empty())
            brand[0] = toupper(brand[0]);

        // make color lowercase first, then capitalize first letter
        transform(color.begin(), color.end(), color.begin(),
                  [](unsigned char c)
                  { return tolower(c); });
        if (!color.empty())
            color[0] = toupper(color[0]);

        // sort by ascending ID
        //sort(s.allstraps_arr.begin(), s.allstraps_arr.end(), [](auto &a, auto &b)
             //{ return a.id < b.id; });

        // find smallest unused ID
        // int newID = 1;
        // for (const auto &s : s.allstraps_arr)
        // {
        //     if (s.id == newID)
        //         newID++;
        //     else
        //         break;
        // }

        // nextID = newID;

        if(leather_type == "0")
        {
            leather_type = "No type";
        }

        if(hole == "1")
        {
            hole = "1 hole";
        }

        else if(hole == "2")
        {
            hole = "2 hole";
        }

        else
        {
            hole = "--";
        }
        
        // create new strap
        int last_id =   allstraps_arr.back().id  + 1;
        Straps::StrapItems newStrap(last_id, categ, color, brand, leather_type, quantity, size, price, hole);
        // only allow valid categories (you can modify this list)
        if (categ == "stitched" || categ == "no stitch" || categ == "casio" || categ == "casio w/ cover")
        {
            s.allstraps_arr.push_back(newStrap);

            cout << "\nStrap successfully added to " << categ << " category!\n";
            displayTableHeader();
            for (auto &s : s.allstraps_arr)
                displayItem(s);
        }
        else
        {
            cout << "\nCategory not found :(\n";
            return;
        }
    }

    // DELETE
    void deleteItem(int id, int decision)
    {   
       


        if (decision == 1)
        {
            bool found = false;

            // find the strap in s.allstraps_arr that matches the input ID
            for (auto it = s.allstraps_arr.begin(); it != s.allstraps_arr.end(); ++it)
            {
                if (it->id == id)
                {
                    s.allstraps_arr.erase(it);
                    found = true;
                    cout << "\nStrap deleted successfully.\n";
                    break;
                }
            }

            if (!found)
                cout << "\nStrap with ID " << id << " not found :(\n";

                 s.DisplayStitched(allstraps_arr, "STITCHED STRAPS");
        s.DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");
        s.DisplayCasioAdult(allstraps_arr, "CASIO STRAPS ADULT SIZE");
        s.DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");

            return;
        }
    }

    void dispItem()
    {
        s.DisplayStitched(allstraps_arr, "STITCHED STRAPS");
		s.DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");
		s.DisplayCasioAdult(allstraps_arr, "CASIO STRAPS ADULT SIZE");
		s.DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
    }

    void viewItem(int strp)
    {
        // todo: print all the available choices here
        do
        {
            cout << "\nSTRAPS\n";
            cout << "[1] WITH STITCH STRAP\n";
            cout << "[2] NO STITCH STRAP\n";
            cout << "[3] CASIO STRAP\n";
            cout << "[4] DISPLAY ALL STRAPS\n";
            cout << "[5] SEARCH NAME OF STRAP\n";
            cout << "[0] BACK\n";
            cout << "Choose an option: ";
            cin >> strp;

            int choice;
            string categ, categ2, categ3, categ4;
            switch (strp)
            {
            case 1:
                categ = "WITH STITCH STRAPS";
                DisplayStitched(categ);
                break;

            case 2:
                categ = "NO STITCH STRAPS";
                DisplayNoStitched(categ);
                break;

            case 3:
                cout << "\nCHOOSE CASIO TYPE:\n";
                cout << "[1] KIDS SIZE\n";
                cout << "[2] ADULT SIZE\n";
                cout << "[0] back\n";
                cout << "Choose an option: ";
                cin >> choice;

                if (choice == 1)
                {
                    categ = "CASIO STRAPS KIDS SIZE W/ COVER";
                    DisplayCasioKids(categ);
                }
                else if (choice == 2)
                {
                    categ = "CASIO STRAPS ADULT SIZE";
                    DisplayCasio(categ);
                }
                break;

            case 4:
                categ = "WITH STITCH STRAPS";
                DisplayStitched(categ);
                categ2 = "NO STITCH STRAPS";
                DisplayNoStitched(categ2);
                categ3 = "CASIO STRAPS KIDS SIZE W/ COVER";
                DisplayCasioKids(categ3);
                categ4 = "CASIO STRAPS ADULT SIZE";
                DisplayCasio(categ4);
                break;
            }
        } while (strp != 0);
    }

    void editItem(int id, string newName, string newColor, int newQty,  string newSize, int newPrice)
    {
        bool found = false; 
        for (auto &i : s.allstraps_arr)
        {
            if (i.id == id)
            {
            //    cout << "New name: ";
            //             getline(cin, newName);
            //             cout << "New Color: ";
            //             cin >> newColor;
            //             cout << "New quantity: ";
            //             cin >> newQty;
            //             cout << "New size: ";
            //             cin >> newSize;
            //             cout << "New price: ";
            //             cin >> newPrice;

                        i.brand = newName;
                        i.quantity = newQty;
                        i.price = newPrice;
                        i.size = newSize;
                        i.color = newColor;
                        found = true;
                        cout << "\nItem updated successfully!\n";
                        break; 
            }

            
        }
        
        if (!found)
                cout << "Item not found or id does not exist in that category!\n";
                // break;
    }
    //     do
    //     {
    //         cout << "\nEDIT ITEM\n";
    //         cout << "[1] WITH STITCH STRAP\n";
    //         cout << "[2] NO STITCH STRAP\n";
    //         cout << "[3] CASIO STRAP\n";
    //         cout << "[0] BACK\n";
    //         cout << "Choose an option: ";
    //         cin >> strp;

    //         string nameToEdit;
    //         string newName, newColor, newleather_Type;
    //         int newQty, newSize, newHole;
    //         double newPrice;
    //         bool found = false;

    //         switch (strp)
    //         {
    //         case 1:
    //         {
    //             cout << "Enter name of brand to edit (WITH STITCHED): ";
    //             cin.ignore();
    //             getline(cin, nameToEdit);

    //             for (auto &i : s.allstraps_arr)
    //             {
    //                 // if (i.categ == "WITH STITCH STRAPS" && i.brand == nameToEdit)
    //                 if (i.id ==  id)
    //                 {
    //                     cout << "New name: ";
    //                     getline(cin, newName);
    //                     cout << "New Color: ";
    //                     cin >> newColor;
    //                     cout << "New quantity: ";
    //                     cin >> newQty;
    //                     cout << "New size: ";
    //                     cin >> newSize;
    //                     cout << "New price: ";
    //                     cin >> newPrice;

    //                     i.brand = newName;
    //                     i.quantity = newQty;
    //                     i.price = newPrice;
    //                     i.size = newSize;
    //                     i.color = newColor;
    //                     found = true;
    //                     cout << "\nItem updated successfully!\n";
    //                     break;
    //                 }
    //             }
    //             if (!found)
    //                 cout << "Item not found or id does not exist in that category!\n";
    //             break;
    //         }

    //         case 2:
    //         {
    //             cout << "Enter name of brand to edit (NO STITCH): ";
    //             cin.ignore();
    //             getline(cin, nameToEdit);

    //             for (auto &i : s.allstraps_arr)
    //             {
    //                 if (i.categ == "NO STITCH STRAPS" && i.brand == nameToEdit)
    //                 {
    //                     cout << "New name: ";
    //                     getline(cin, newName);
    //                     cout << "New Color: ";
    //                     cin >> newColor;
    //                     cout << "New quantity: ";
    //                     cin >> newQty;
    //                     cout << "New size: ";
    //                     cin >> newSize;
    //                     cout << "New price: ";
    //                     cin >> newPrice;

    //                     i.brand = newName;
    //                     i.quantity = newQty;
    //                     i.price = newPrice;
    //                     i.size = newSize;
    //                     i.color = newColor;
    //                     found = true;
    //                     cout << "\nItem updated successfully!\n";
    //                     break;
    //                 }
    //             }
    //             if (!found)
    //                 cout << "Item not found or id does not exist in that category!\n";
    //             break;
    //         }

    //         case 3:
    //         {
    //             int choice;
    //             cout << "\nCHOOSE CASIO TYPE:\n";
    //             cout << "[1] KIDS SIZE\n";
    //             cout << "[2] ADULT SIZE\n";
    //             cout << "[0] BACK\n";
    //             cout << "Choose an option: ";
    //             cin >> choice;

    //             if (choice == 1)
    //                 nameToEdit = "CASIO STRAPS KIDS SIZE W/ COVER";
    //             else if (choice == 2)
    //                 nameToEdit = "CASIO STRAPS ADULT SIZE";
    //             else
    //                 break;

    //             cin.ignore();
    //             string strapName;
    //             cout << "Enter name of brand to edit (" << nameToEdit << "): ";
    //             getline(cin, strapName);

    //             for (auto &i : s.allstraps_arr)
    //             {
    //                 if (i.categ == nameToEdit && i.brand == strapName)
    //                 {
    //                     cout << "New name: ";
    //                     getline(cin, newName);
    //                     cout << "New Color: ";
    //                     cin >> newColor;
    //                     cout << "New quantity: ";
    //                     cin >> newQty;
    //                     cout << "New size: ";
    //                     cin >> newSize;
    //                     cout << "New price: ";
    //                     cin >> newPrice;

    //                     i.brand = newName;
    //                     i.quantity = newQty;
    //                     i.price = newPrice;
    //                     i.size = newSize;
    //                     i.color = newColor;
    //                     found = true;
    //                     cout << "\nItem updated successfully!\n";
    //                     break;
    //                 }
    //             }
    //             if (!found)
    //                 cout << "Item not found or id does not exist in that category!\n";
    //             break;
    //         }
    //         }

    //     } while (strp != 0);
    // }

    int DisplayStitched(string &categ)
    {
        cout << "\n " << categ << " \n";
        cout << right << setw(10) << " ";
        cout << left << setw(5) << "ID"
             << setw(20) << "Color"
             << setw(15) << "Brand"
             << setw(30) << "Leather Type"
             << setw(10) << "Qty"
             << setw(10) << "Size"
             << setw(10) << "Price" << "\n";

        for (auto &i : s.allstraps_arr)
        {
            if (i.isActive) // if the variable is true
            {
                if (i.categ == "stitched")
                {
                    cout << right << setw(10) << " ";
                    cout << left << setw(5) << i.id
                         << setw(20) << i.color
                         << setw(15) << i.brand
                         << setw(30) << i.leather_type
                         << setw(10) << i.quantity
                         << setw(10) << i.size
                         << setw(10) << i.price << "\n";
                }
            }
        }
        return 0;
    }

    int DisplayNoStitched(string &categ)
    {
        cout << "\n " << categ << " \n";
        cout << right << setw(10) << " ";
        cout << left << setw(5) << "ID"
             << setw(20) << "Color"
             << setw(15) << "Brand"
             << setw(30) << "Leather Type"
             << setw(10) << "Qty"
             << setw(10) << "Size"
             << setw(10) << "Price" << "\n";

        for (auto &i : s.allstraps_arr)
        {
            if (i.categ == "no stitch")
            {
                cout << right << setw(10) << " ";
                cout << left << setw(5) << i.id
                     << setw(20) << i.color
                     << setw(15) << i.brand
                     << setw(30) << i.leather_type
                     << setw(10) << i.quantity
                     << setw(10) << i.size
                     << setw(10) << i.price << "\n";
            }
        }
        return 0;
    }

    int DisplayCasio(string &categ)
    {
        cout << "\n " << categ << " \n";
        cout << right << setw(10) << " ";
        cout << left << setw(5) << "ID"
             << setw(20) << "Color"
             << setw(15) << "Brand"
             << setw(30) << "Leather Type"
             << setw(10) << "Qty"
             << setw(10) << "Size"
             << setw(10) << "Price" << "\n";

        cout << "1 HOLE\n";
        for (auto &i : s.allstraps_arr)
        {
            if (i.hole == "1 hole" && i.isActive)
            {
                if (i.categ == "casio")
                {
                    cout << right << setw(10) << " ";
                    cout << left << setw(5) << i.id
                         << setw(20) << i.color
                         << setw(15) << i.brand
                         << setw(30) << i.leather_type
                         << setw(10) << i.quantity
                         << setw(10) << i.size
                         << setw(10) << i.price << "\n";
                }
            }
        }

        cout << "\n2 HOLE\n";
        for (auto &i : s.allstraps_arr)
        {
            if (i.hole == "2 hole" && i.isActive)
            {
                if (i.categ == "casio")
                {
                    cout << right << setw(10) << " ";
                    cout << left << setw(5) << i.id
                         << setw(20) << i.color
                         << setw(15) << i.brand
                         << setw(30) << i.leather_type
                         << setw(10) << i.quantity
                         << setw(10) << i.size
                         << setw(10) << i.price << "\n";
                }
            }
        }
        return 0;
    }

    int DisplayCasioKids(string &categ)
    {
        cout << "\n " << categ << " \n";
        cout << right << setw(10) << " ";
        cout << left << setw(5) << "ID"
             << setw(20) << "Color"
             << setw(15) << "Brand"
             << setw(30) << "Leather Type"
             << setw(10) << "Qty"
             << setw(10) << "Size"
             << setw(10) << "Price" << "\n";

        cout << "1 HOLE\n";
        for (auto &i : s.allstraps_arr)
        {
            if (i.hole == "1 hole")
            {
                if (i.categ == "casio w/ cover")
                {
                    cout << right << setw(10) << " ";
                    cout << left << setw(5) << i.id
                         << setw(20) << i.color
                         << setw(15) << i.brand
                         << setw(30) << i.leather_type
                         << setw(10) << i.quantity
                         << setw(10) << i.size
                         << setw(10) << i.price << "\n";
                }
            }
        }

        cout << "\n2 HOLE\n";
        for (auto &i : s.allstraps_arr)
        {
            if (i.hole == "2 hole")
            {
                if (i.categ == "casio w/ cover")
                {
                    cout << right << setw(10) << " ";
                    cout << left << setw(5) << i.id
                         << setw(20) << i.color
                         << setw(15) << i.brand
                         << setw(30) << i.leather_type
                         << setw(10) << i.quantity
                         << setw(10) << i.size
                         << setw(10) << i.price << "\n";
                }
            }
        }
        return 0;
    }

    void displayTableHeader()
    {
        cout << "\n"
             << left << setw(5) << "ID"
             << setw(20) << "Category"
             << setw(20) << "Color"
             << setw(20) << "Brand"
             << setw(30) << "Leather Type"
             << setw(10) << "Qty"
             << setw(10) << "Size"
             << setw(10) << "Price"
             << setw(10) << "Hole"
             << "\n";
        cout << string(125, '-') << "\n";
    }

    void displayItem(const Straps::StrapItems &s)
    {
        cout << left << setw(5) << s.id
             << setw(20) << s.categ
             << setw(20) << s.color
             << setw(20) << s.brand
             << setw(30) << s.leather_type
             << setw(10) << s.quantity
             << setw(10) << s.size
             << setw(10) << fixed << setprecision(2) << s.price
             << setw(10) << s.hole
             << "\n";
    }
};