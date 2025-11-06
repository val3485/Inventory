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

class Batteries
{
private:
	string brand;

public:
	void setBrand(string b)
	{
		brand = b;
	}
	string getBrand(string b)
	{
		return b;
	}

	struct BattItems
	{
		int id;
		string categ;
		string brand;
		int quantity;
		int price;

		BattItems(int i, string ct, string b, int q, double p) // this is called a constructor, it reads(?) the data from the array in order.
			: id(i), categ(ct), brand(b), quantity(q), price(p)
		{
		}
	};

	vector<BattItems> allbatt_arr = {
		{1, "renata", "Renata 314", 10, 500},
		{2, "renata", "Renata 510", 10, 500},
		{3, "renata", "Renata 600", 10, 500},
		{4, "renata", "Renata 700", 10, 500},

		{5, "maxwell", "Maxwell 314", 10, 500},
		{6, "maxwell", "Maxwell 510", 10, 500},
		{7, "maxwell", "Maxwell 600", 10, 500},
		{8, "maxwell", "Maxwell 700", 10, 500}};

	int DisplayRenata(vector<BattItems> arr, string categ)
	{
		cout << "\n"
			 << categ << " \n";
		cout << left << setw(5) << "ID"
			 << setw(15) << "Brand"
			 << setw(10) << "Qty"
			 << setw(10) << "Price" << "\n";

		for (auto &i : arr)
		{
			if (i.categ == "renata")
			{
				cout << left << setw(5) << i.id
					 << setw(15) << i.brand
					 << setw(10) << i.quantity
					 << setw(10) << i.price << "\n";
			}
		}
		return 0;
	}

	int DisplayMaxwell(vector<BattItems> arr, string categ)
	{
		cout << "\n"
			 << categ << " \n";
		cout << left << setw(5) << "ID"
			 << setw(15) << "Brand"
			 << setw(10) << "Qty"
			 << setw(10) << "Price" << "\n";

		for (auto &i : arr)
		{
			if (i.categ == "maxwell")
			{
				cout << left << setw(5) << i.id
					 << setw(15) << i.brand
					 << setw(10) << i.quantity
					 << setw(10) << i.price << "\n";
			}
		}
		return 0;
	}

	void switch_view(int bat)
	{
		switch (bat)
		{
		case 1:
			DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
			break;

		case 2:
			DisplayRenata(allbatt_arr, "RENATA BATTERY");
			break;

		case 3:
			DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
			DisplayRenata(allbatt_arr, "RENATA BATTERY");
			break;
		}
	}
};

class BatteryCRUD
{
private:
	Batteries &batt;
	vector<Batteries::BattItems> &allbatt_arr;
	static int nextID;

public:
	BatteryCRUD(Batteries &batts) : batt(batts), allbatt_arr(batts.allbatt_arr) {}

	// DISPLAY
	void displayItems()
	{
		batt.DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
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
				displayItems();
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
        
        //sorting of items (by ascending ID)
        sort(allbatt_arr.begin(), allbatt_arr.end(), [](auto &a, auto &b)
        {
            return a.id < b.id;
        });
        
        //finding smallest unused ID
        int newID = 1; 
        for (const auto &b : allbatt_arr)
        {
            if(b.id == newID)
                newID++;
            else
                break;    
        }
        
        nextID = newID;
        
       Batteries::BattItems newBatt(nextID, categ, itemName, quantity, price);
       
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
		vector<string> validBrands = { "renata", "maxwell"};

		// transform the input to lowercase
		transform(input.begin(), input.end(), input.begin(),
				  [](unsigned char i)
				  {
					  return tolower(i);
				  });

		// trnasform the first char to uppercase
		if (!input.empty())
		{
			input[0] = toupper(input[0]);
		}

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
