#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <climits>

using namespace std;

// class BatteryCRUD; 

class Batteries
{
private:
	string brand;


public:

	struct BattItems
	{
		int id;
		string categ;
		string brand;
		int quantity;
		int price;

				BattItems(int i, string ct, string b, int q, double p) //this is called a constructor, it reads(?) the data from the array in order.
				: id(i), categ (ct), brand(b), quantity(q), price(p) {}
			};
			
			vector<BattItems> allbatt_arr = {
				
				{1, "maxell", "Maxell SR416SW", 10, 450},
				{2, "maxell", "Maxell SR512SW", 10, 450},
				{3, "maxell", "Maxell SR521SW", 10, 450},
				{4, "maxell", "Maxell SR416SW", 10, 450},
				{5, "maxell", "Maxell SR616SW", 10, 450},
				{6, "maxell", "Maxell SR621SW", 10, 450},
				{7, "maxell", "Maxell SR626SW", 10, 450},
				{8, "maxell", "Maxell SR626SW", 10, 450},
				{9, "maxell", "Maxell SR716SW", 10, 450},
				{10, "maxell", "Maxell SR721SW", 10, 450},
				{11, "maxell", "Maxell SR726SW", 10, 450},
				{12, "maxell", "Maxell SR920SW", 10, 450},
				{13, "maxell", "Maxell SR927SW", 10, 450},
				{14, "maxell", "Maxell SR936SW", 10, 450},
				{15, "maxell", "Maxell SR1120SW", 10, 450},
				{16, "maxell", "Maxell SR1130SW", 10, 450},
				{17, "maxell", "Maxell CR 1216", 10, 450},
				{18, "maxell", "Maxell CR 1616", 10, 450},
				{19, "maxell", "Maxell CR 1620", 10, 450},
				{20, "maxell", "Maxell CR 1632", 10, 450},
				{21, "maxell", "Maxell CR 2016", 10, 450},
				{22, "maxell", "Maxell CR 2025", 10, 450},
				{23, "maxell", "Maxell CR 2032", 10, 450},
				{24, "maxell", "Maxell LR41", 10, 450},
				{25, "maxell", "Maxell LR44", 10, 450},
				{26, "maxell", "Maxell LR1130", 10, 450},

				{27, "renata", "Renata 315", 10, 550},
				{28, "renata", "Renata 317", 10, 550},
				{29, "renata", "Renata 321", 10, 550},
				{30, "renata", "Renata 335", 10, 550},
				{31, "renata", "Renata 337", 10, 550},
				{32, "renata", "Renata 362", 10, 550},
				{33, "renata", "Renata 364", 10, 550},
				{34, "renata", "Renata 371", 10, 550},
				{35, "renata", "Renata 377", 10, 550},
				{36, "renata", "Renata 379", 10, 550},
				{37, "renata", "Renata 390", 10, 550},
				{38, "renata", "Renata 394", 10, 550},
				{39, "renata", "Renata 395", 10, 550},
				{40, "renata", "Renata 397", 10, 550},
				{41, "renata", "Renata CR 1216", 10, 550},
				{42, "renata", "Renata CR 1616", 10, 550},
				{43, "renata", "Renata CR 1620", 10, 550},
				{44, "renata", "Renata CR 1632", 10, 550},
				{45, "renata", "Renata CR 2016", 10, 550},
				{46, "renata", "Renata CR 2025", 10, 550},
				{47, "renata", "Renata CR 2032", 10, 550},
				{48, "renata", "Renata CR 2320", 10, 550},
				{49, "renata", "Renata CR 2430", 10, 550},
				{50, "renata", "Renata CR 2477", 10, 550},
				{51, "renata", "Renata CR 2450", 10, 550}
			};
			
		int DisplayMaxell(vector<BattItems> arr, string categ) {
			cout << "\n" << categ << " \n";
			cout << left << setw(5) << "ID"
				<< setw(25) << "Brand"
				<< setw(10) << "Qty"
				<< setw(10) << "Price" << "\n";

			for (auto &i : arr) {
				if(i.categ == "maxell"){
					cout << left << setw(5) << i.id
						<< setw(25) << i.brand
						<< setw(10) << i.quantity
						<< setw(10) << i.price << "\n";
				}
			}
			return 0;
		}

		int DisplayRenata(vector<BattItems> arr, string categ) {
			cout << "\n" << categ << " \n";
			cout << left << setw(5) << "ID"
				<< setw(25) << "Brand"
				<< setw(10) << "Qty"
				<< setw(10) << "Price" << "\n";

			for (auto &i : arr) {
				if(i.categ == "renata"){
					cout << left << setw(5) << i.id
						<< setw(25) << i.brand
						<< setw(10) << i.quantity
						<< setw(10) << i.price << "\n";
				}
			}
			return 0;
		}
			

    void switch_view(int bat, int strp) {
        switch (bat) {
            case 1:
                DisplayMaxell(allbatt_arr, "MAXELL BATTERY");
                break;
            case 2:
                DisplayRenata(allbatt_arr, "RENATA BATTERY");
                break;
            case 3:
                DisplayMaxell(allbatt_arr, "MAXELL BATTERY");
                DisplayRenata(allbatt_arr, "RENATA BATTERY");
                break;
				
            default:
                if (strp != 0)
                    cout << "Invalid option :<\n";
                break;
        }
    }
};
		

class BatteryCRUD
{
private:
	// Batteries *b;
	Batteries &batt;
	vector<Batteries::BattItems> &allbatt_arr;

public:
	// BatteryCRUD(Batteries *bRef) : b(bRef),allbatt_arr(bRef.allbatt_arr) {}
	BatteryCRUD(Batteries &batts) : batt(batts), allbatt_arr(batts.allbatt_arr) {}
	// DISPLAY
	void displayItems()
	{
		batt.DisplayMaxell(allbatt_arr, "MAXWELL BATTERY");
		batt.DisplayRenata(allbatt_arr, "RENATA BATTERY");
	}
    
	// EDIT
	void editItems(int id, string newCateg, string newBrand, int newQty, int newPrice)
	{
        //lowercase the newCateg    
		transform(newCateg.begin(), newCateg.end(), newCateg.begin(),
				  [](unsigned char c)
				  {
					  return tolower(c);
				  });
        //capitalized th first letter of newBrand
		transform(newBrand.begin(), newBrand.end(), newBrand.begin(),
				  [](unsigned char br)
				  {
					  return tolower(br);
				  });

		if (!newBrand.empty())
		{
			newBrand[0] = toupper(newBrand[0]);
		}

		for (auto &b : allbatt_arr) //input one by one
		{
			if (b.id == id)
			{
				b.categ = newCateg;
				b.brand = newBrand;
				b.quantity = newQty;
				b.price = newPrice;
				cout << "\nItem updated successfully!\n";
				return;
			}
		}

		cout << "\nBattery with ID " << id << " not found.\n";
	}

	// ADD
	void addItems(string categ, string itemName, int quantity, int price)
	{
        //make categ all lowercase    
		transform(categ.begin(), categ.end(), categ.begin(),
				  [](unsigned char c)
				  { return tolower(c); });
        
        //make itemName's first letter capital
        transform(itemName.begin(), itemName.end(), itemName.begin(),
				  [](unsigned char na)
				  {
					  return tolower(na);
				  });

	    	if (!itemName.empty())
		    {
		    	itemName[0] = toupper(itemName[0]);
		    }          
        
       int lastID = allbatt_arr.back().id + 1;

       Batteries::BattItems newBatt(lastID, categ, itemName, quantity, price);
       
	   if (categ == "renata" || categ == "maxwell")
	   {
			batt.allbatt_arr.push_back(newBatt);
			displayItems();
			cout << "\nBattery successfully added to " << categ << " list.\n";
			return;
	   }
	   else
	   {
			cout << "\nBrand Name not found :(\n";
			return;
	   }
	}

	// DELETE
	void deleteItems(int id, int dec)
	{
		if (dec == 1)
		{
            bool found = false;
            //finding the id in allbatt_arr that matches the inputed id (for deletion)
            for(auto it = batt.allbatt_arr.begin(); it!= batt.allbatt_arr.end(); it++)
            {
                if(it->id == id)
                {
                    batt.allbatt_arr.erase(it);
                    found = true;
                    cout << "\nItem deleted successfully.\n";
                    break;
                }
			}
            
            if(!found)
                cout << "\nItem with ID  " << id << " not found :(\n";
		    displayItems();
			return;
		}
		
	}

};