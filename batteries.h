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

	struct BattItems{
		int id;
		string categ;
		string brand;
		int quantity;
		int reorder_point; //to trigger alert
		float price;

				BattItems() = default;
				BattItems(int i, string ct, string b, int q, int rp, float p) //this is called a constructor, it reads(?) the data from the array in order.
				: id(i), categ (ct), brand(b), quantity(q), reorder_point(rp), price(p) {}
			};
			
			vector<BattItems> allbatt_arr = {
				
				{1, "maxell", "Maxell SR416SW", 10, 5, 450},
				{2, "maxell", "Maxell SR512SW", 10, 5, 450},
				{3, "maxell", "Maxell SR521SW", 10, 5, 450},
				{4, "maxell", "Maxell SR416SW", 10, 5, 450},
				{5, "maxell", "Maxell SR616SW", 10, 5, 450},
				{6, "maxell", "Maxell SR621SW", 10, 5, 450},
				{7, "maxell", "Maxell SR626SW", 10, 5, 450},
				{8, "maxell", "Maxell SR626SW", 10, 5, 450},
				{9, "maxell", "Maxell SR716SW", 10, 5, 450},
				{10, "maxell", "Maxell SR721SW", 10, 5, 450},
				{11, "maxell", "Maxell SR726SW", 10, 5, 450},
				{12, "maxell", "Maxell SR920SW", 10, 5, 450},
				{13, "maxell", "Maxell SR927SW", 10, 5, 450},
				{14, "maxell", "Maxell SR936SW", 10, 5, 450},
				{15, "maxell", "Maxell SR1120SW", 10, 5, 450},
				{16, "maxell", "Maxell SR1130SW", 10, 5, 450},
				{17, "maxell", "Maxell CR 1216", 10, 5, 450},
				{18, "maxell", "Maxell CR 1616", 10, 5, 450},
				{19, "maxell", "Maxell CR 1620", 10, 5, 450},
				{20, "maxell", "Maxell CR 1632", 10, 5, 450},
				{21, "maxell", "Maxell CR 2016", 10, 5, 450},
				{22, "maxell", "Maxell CR 2025", 10, 5, 450},
				{23, "maxell", "Maxell CR 2032", 10, 5, 450},
				{24, "maxell", "Maxell LR41", 10, 5, 450},
				{25, "maxell", "Maxell LR44", 10, 5, 450},
				{26, "maxell", "Maxell LR1130", 10, 5, 450},

				{27, "renata", "Renata 315", 10, 5, 550},
				{28, "renata", "Renata 317", 10, 5, 550},
				{29, "renata", "Renata 321", 10, 5, 550},
				{30, "renata", "Renata 335", 10, 5, 550},
				{31, "renata", "Renata 337", 10, 5, 550},
				{32, "renata", "Renata 362", 10, 5, 550},
				{33, "renata", "Renata 364", 10, 5, 550},
				{34, "renata", "Renata 371", 10, 5, 550},
				{35, "renata", "Renata 377", 10, 5, 550},
				{36, "renata", "Renata 379", 10, 5, 550},
				{37, "renata", "Renata 390", 10, 5, 550},
				{38, "renata", "Renata 394", 10, 5, 550},
				{39, "renata", "Renata 395", 10, 5, 550},
				{40, "renata", "Renata 397", 10, 5, 550},
				{41, "renata", "Renata CR 1216", 10, 5, 550},
				{42, "renata", "Renata CR 1616", 10, 5, 550},
				{43, "renata", "Renata CR 1620", 10, 5, 550},
				{44, "renata", "Renata CR 1632", 10, 5, 550},
				{45, "renata", "Renata CR 2016", 10, 5, 550},
				{46, "renata", "Renata CR 2025", 10, 5, 550},
				{47, "renata", "Renata CR 2032", 10, 5, 550},
				{48, "renata", "Renata CR 2320", 10, 5, 550},
				{49, "renata", "Renata CR 2430", 10, 5, 550},
				{50, "renata", "Renata CR 2477", 10, 5, 550},
				{51, "renata", "Renata CR 2450", 10, 5, 550}
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
		
		void Stock_levels(vector<BattItems> arr){
			cout << "----INVENTORY LEVELS----\n";
			bool low_stock = false;
			for(auto&i : arr){
				if(i.quantity <= i.reorder_point){
					cout << "[ALERT] " << i.brand 
					<< "is low on stock! Current quantity: " 
					<< i.quantity << ". Reorder point: "
					<< i.reorder_point << ". \n";
					low_stock = true;
				}
			}

			if(!low_stock){
				cout << "All products are at sufficient stock levels.\n";
			}
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
			case 4:
				Stock_levels(allbatt_arr);  
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
	void editItems(int id, string newBrand, int newQty, float newPrice)
	{
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
				b.brand = newBrand;
				b.quantity = newQty;
				b.price = newPrice;
				cout << "\nItem updated successfully!\n";
				displayItems();
				return;
			}
		}

		cout << "\nBattery with ID " << id << " not found.\n";
	}

	// ADD
	void addItems(string categ, string itemName, int quantity, float price)
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

       Batteries::BattItems newBatt(lastID, categ, itemName, quantity, 5, price);
       
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

	// LEVEINSHTEIN DISTANCE (para sa search)
	int levenshteinDistance(const string &s1, const string &s2)
	{
		const size_t len1 = s1.size(), len2 = s2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

		for (size_t i = 0; i <= len1; ++i)
			dp[i][0] = i;
		for (size_t j = 0; j <= len2; ++j)
			dp[0][j] = j;

		for (size_t i = 1; i <= len1; ++i)
			for (size_t j = 1; j <= len2; ++j)
				dp[i][j] = min({
					dp[i - 1][j] + 1,							// deletion
					dp[i][j - 1] + 1,							// insertion
					dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]) // substitution
				});

		return dp[len1][len2];
	}

	// forda correct brand name
	string correctItemName(string input)
	{
		vector<string> validBrands = { "renata", "maxell"};

		// transform the input to lowercase
		transform(input.begin(), input.end(), input.begin(),
				  [](unsigned char i)
				  {
					  return tolower(i);
				  });

		// // trnasform the first char to uppercase
		// if (!input.empty())
		// {
		// 	input[0] = toupper(input[0]);
		// }

		//return input;

		// store varibles
		string bestMatch = input;
		int bestScore = INT_MAX;

		// ich-check sa validbrand kung ano ang best match
		for (const string &brand : validBrands)
		{
			int dist = levenshteinDistance(input, brand);
			if (dist < bestScore)
			{
				bestScore = dist;
				bestMatch = brand;
			}
		}
		if (bestScore <= 2) // only accepts 2 typos
			return bestMatch;
		else
			return input; // too different, keep original
	}

	// SEARCH
	void searchItems(string input)
	{
		string brandPart, number;

		stringstream ss(input);
		ss >> brandPart;
		getline(ss, number);							// separates the brandPart from the number part
		number.erase(0, number.find_first_not_of(" ")); // erases the excess space from the number part

		// search the brand part
		string correctBrand = correctItemName(brandPart);
        
        cout << left << setw(5) << "ID"
                     << setw(15) << "BRAND"
                     << setw(10) << "Qty"
                     << setw(10) << "Price" << "\n";
        
		bool found = false;
		for (const auto &batt : allbatt_arr)
		{
			string battNameLower = batt.brand; // brand includes the full name, e.g., "Renata 567"
            transform(number.begin(), number.end(), number.begin(), ::tolower);
			transform(battNameLower.begin(), battNameLower.end(), battNameLower.begin(), ::tolower);
			transform(correctBrand.begin(), correctBrand.end(), correctBrand.begin(), ::tolower);	
			
			// match if brand or brand+number found
            if ((!number.empty() && battNameLower.find(correctBrand + " " + number) != string::npos) ||
                (number.empty() && battNameLower.find(correctBrand) != string::npos))
            {
                cout << left << setw(5) << batt.id
                     << setw(15) << batt.brand
                     << setw(10) << batt.quantity
                     << setw(10) << batt.price << "\n";
                found = true;
            }
		}
		

		if (!found)
		{
			cout << "No items matches :<\n";
		}
	}

};
