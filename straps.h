#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Straps
{
private:
	string color;
	string brand;
	int qty;
	int size;
	double price;

public:

	struct StrapItems
	{ // struct is used as a container for related data
		bool isActive = true;
		int id;
		string categ;
		string color;
		string brand;
		string leather_type;
		int quantity;
		string size;
		string kid_size;
		float price;
		string hole;
		int reorder_point;


		StrapItems(int i, string ct, const string c, const string b, const string lt, int q, int rp, const string s, float p, const string h)
			: isActive(true), id(i), categ(ct), color(c), brand(b), leather_type(lt), quantity(q), reorder_point(rp), size(s), kid_size(""), price(p), hole(h) {}

		void setActive(bool active)
		{
			isActive = active;
		}

		bool getActive()
		{
			return isActive;
		}
	};

	vector<StrapItems> allstraps_arr = {
		{1, "stitched", "Black w/ black", "No type", "Buffalo Calf", 10, 7, "16-24", 950.00, ""},
		{2, "stitched", "Black w/ white", "No type", "Buffalo Calf", 10, 7, "16-24", 950.00, ""},
		{3, "stitched", "Brown dark", "No type", "Buffalo Calf", 8, 4, "16-24", 950.00, ""},
		{4, "stitched", "Brown light", "No type", "Buffalo Calf", 8, 4, "16-24", 950.00, ""},
		{5, "stitched", "Black w/ black", "No type", "Chrono Genuine", 10, 7, "20-24", 1200.00, ""},
		{6, "stitched", "Black w/ white", "No type", "Chrono Genuine", 10, 7, "20-24", 1200.00, ""},
		{7, "stitched", "Brown w/ white", "No type", "Chrono Genuine", 8, 4, "20-24", 1200.00, ""},
		{8, "stitched", "Black", "No type", "Genuine", 10, 7, "16-24", 650.00, ""},
		{9, "stitched", "Brown dark", "No type", "Genuine", 10, 7, "16-24", 650.00, ""},
		{10, "stitched", "Brown light", "No type", "Genuine", 18, 4, "16-24", 650.00, ""},
		{11, "stitched", "Gray", "No type", "Genuine", 8, 4, "16-24", 650.00, ""},
		{12, "stitched", "Red", "No type", "Genuine", 8, 4, "16-24", 650.00, ""},
		{13, "stitched", "Black w/ black", "No type", "Cobra Genuine", 10, 7, "16-24", 550.00, ""},
		{14, "stitched", "Blue light w/ blue", "No type", "Cobra Genuine", 8, 4, "16-24", 550.00, ""},
		{15, "stitched", "Brown dark w/ brown", "No type", "Cobra Genuine", 10, 7, "16-24", 550.00, ""},
		{16, "stitched", "Brown light w/ brown", "No type", "Cobra Genuine", 8, 4, "16-24", 550.00, ""},
		{17, "stitched", "Gray w/ blue", "No type", "Cobra Genuine", 8, 4, "16-24", 550.00, ""},
		{18, "stitched", "Red w/ red", "No type", "Cobra Genuine", 8, 4, "16-24", 550.00, ""},
		{19, "stitched", "Black w/ blue", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{20, "stitched", "Black w/ orange", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{21, "stitched", "Black w/ red", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{22, "stitched", "Black w/ white", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},

		{23, "no stitch", "Black", "Alpha", "No type", 10, 7, "16-24", 1500.00, ""},
		{24, "no stitch", "Brown dark", "Alpha", "No type", 10, 7, "16-24", 1500.00, ""},
		{25, "no stitch", "Brown light", "Alpha", "No type", 10, 7, "16-24", 1500.00, ""},
		{26, "no stitch", "Red", "Alpha", "No type", 8, 4, "16-24", 1500.00, ""},
		{27, "no stitch", "Black", "No type", "Brazilian", 10, 7, "16-24", 1200.00, ""},
		{28, "no stitch", "Brown dark", "No type", "Brazilian", 8, 4, "16-24", 1200.00, ""},
		{29, "no stitch", "Brown light", "No type", "Brazilian", 8, 4, "16-24", 1200.00, ""},
		{30, "no stitch", "Black", "No type", "Buffalo Swiss", 10, 7, "16-24", 750.00, ""},
		{31, "no stitch", "Blue", "No type", "Buffalo Swiss", 8, 4, "16-24", 750.00, ""},
		{32, "no stitch", "Brown light", "No type", "Buffalo Swiss", 8, 4, "16-24", 750.00, ""},
		{33, "no stitch", "Green", "No type", "Buffalo Swiss", 8, 4, "16-24", 750.00, ""},
		{34, "no stitch", "White", "No type", "Buffalo Swiss", 10, 7, "16-24", 750.00, ""},
		{35, "no stitch", "Black", "No type", "Genuine", 10, 7, "24", 850.00, ""},
		{36, "no stitch", "Black", "No type", "Genuine Italy", 10, 7, "16-24", 650.00, ""},
		{37, "no stitch", "Brown dark", "No type", "Genuine Italy", 8, 4, "16-24", 650.00, ""},
		{38, "no stitch", "Brown light", "No type", "Genuine Italy", 8, 4, "16-24", 650.00, ""},
		{39, "no stitch", "Black", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{40, "no stitch", "Brown", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{41, "no stitch", "Green", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{42, "no stitch", "Orange", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{43, "no stitch", "Red", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{44, "no stitch", "Violet", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{45, "no stitch", "White", "No type", "Silicone", 8, 4, "16-24", 750.00, ""},
		{46, "no stitch", "Black", "No type", "Vintage Calf Genuine", 10, 7, "18-24", 1500.00, ""},
		{47, "no stitch", "Brown dark", "No type", "Vintage Calf Genuine", 10, 7, "18-24", 1500.00, ""},
		{48, "no stitch", "Brown light", "No type", "Vintage Calf Genuine", 8, 4, "18-24", 1500.00, ""},
		{49, "no stitch", "Orange", "No type", "Vintage Calf Genuine", 8, 4, "18-24", 1500.00, ""},
		{50, "no stitch", "Red light", "No type", "Vintage Calf Genuine", 8, 4, "18-24", 1500.00, ""},
		{51, "no stitch", "Yellow", "No type", "Vintage Calf Genuine", 8, 4, "18-24", 1500.00, ""},

		{52, "casio", "Black", "Casio", "No type", 10, 7, "Fixed", 750.00, "1 hole"},
		{53, "casio", "Blue dark", "Casio", "No type", 8, 4, "Fixed", 750.00, "1 hole"},
		{54, "casio", "Blue light", "Casio", "No type", 8, 4, "Fixed", 750.00, "1 hole"},
		{55, "casio", "Orange", "Casio", "No type", 8, 4, "Fixed", 750.00, "1 hole"},
		{56, "casio", "Pink dark", "Casio", "No type", 8, 4, "Fixed", 750.00, "1 hole"},
		{57, "casio", "Pink light", "Casio", "No type", 8, 4, "Fixed", 750.00, "1 hole"},
		{58, "casio", "White", "Casio", "No type", 10, 7, "Fixed", 750.00, "1 hole"},

		{59, "casio", "Black", "Casio", "No type", 10, 7, "Fixed", 950.00, "2 hole"},
		{60, "casio", "Blue dark", "Casio", "No type", 8, 4, "Fixed", 950.00, "2 hole"},
		{61, "casio", "Gray", "Casio", "No type", 8, 4, "Fixed", 950.00, "2 hole"},
		{62, "casio", "Red", "Casio", "No type", 8, 4, "Fixed", 950.00, "2 hole"},
		{63, "casio", "White", "Casio", "No type", 10, 7, "Fixed", 950.00, "2 hole"},

		{64, "casio w/ cover", "Black", "Casio", "No type", 8, 4, "Small", 1200.00, "1 hole"},
		{65, "casio w/ cover", "Blue dark", "Casio", "No type", 8, 4, "Small", 1200.00, "1 hole"},
		{66, "casio w/ cover", "Red", "Casio", "No type", 8, 4, "Small", 1200.00, "1 hole"},
		{67, "casio w/ cover", "Violet", "Casio", "No type", 8, 4, "Small", 1200.00, "1 hole"},
		{68, "casio w/ cover", "White", "Casio", "No type", 8, 4, "Small", 1200.00, "1 hole"},

		{69, "casio w/ cover", "Black", "Casio", "No type", 10, 7, "Large", 1500.00, "2 hole"},
		{70, "casio w/ cover", "Blue dark", "Casio", "No type", 8, 4, "Large", 1500.00, "2 hole"},
		{71, "casio w/ cover", "Orange", "Casio", "No type", 8, 4, "Large", 1500.00, "2 hole"},
		{72, "casio w/ cover", "Red", "Casio", "No type", 8, 4, "Large", 1500.00, "2 hole"},
		{73, "casio w/ cover", "White", "Casio", "No type", 10, 7, "Large", 1500.00, "2 hole"}};

	int DisplayStitched(vector<StrapItems> arr, string categ)
	{
		cout << "\n " << categ << " \n";
		cout << right << setw(10) << " ";
		cout << left << setw(5) << "ID"
			 << setw(25) << "Color"
			 << setw(15) << "Brand"
			 << setw(30) << "Leather/Non-Leather"
			 << setw(10) << "Qty"
			 << setw(10) << "Size"
			 << setw(10) << "Price" << "\n";

		for (auto &i : arr)
		{
			if (i.categ == "stitched")
			{
				cout << right << setw(10) << " ";
				cout << left << setw(5) << i.id
					 << setw(25) << i.color
					 << setw(15) << i.brand
					 << setw(30) << i.leather_type
					 << setw(10) << i.quantity
					 << setw(10) << i.size
					 << setw(10) << i.price << "\n";
			}
		}
		return 0;
	}

	int DisplayNoStitched(vector<StrapItems> arr, string categ)
	{
		cout << "\n " << categ << " \n";
		cout << right << setw(10) << " ";
		cout << left << setw(5) << "ID"
			 << setw(25) << "Color"
			 << setw(15) << "Brand"
			 << setw(30) << "Leather/Non-Leather Type"
			 << setw(10) << "Qty"
			 << setw(10) << "Size"
			 << setw(10) << "Price" << "\n";

		for (auto &i : arr)
		{
			if (i.categ == "no stitch")
			{
				cout << right << setw(10) << " ";
				cout << left << setw(5) << i.id
					 << setw(25) << i.color
					 << setw(15) << i.brand
					 << setw(30) << i.leather_type
					 << setw(10) << i.quantity
					 << setw(10) << i.size
					 << setw(10) << i.price << "\n";
			}
		}
		return 0;
	}

	int DisplayCasioAdult(vector<StrapItems> arr, string categ)
	{
		cout << "\n " << categ << " \n";
		cout << right << setw(10) << " ";
		cout << left << setw(5) << "ID"
			 << setw(20) << "Color"
			 << setw(15) << "Brand"
			 << setw(10) << "Qty"
			 << setw(10) << "Size"
			 << setw(10) << "Price" << "\n";

		cout << "1 HOLE\n";
		for (auto &i : arr)
		{
			if (i.hole == "1 hole")
			{
				if (i.categ == "casio")
				{
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						 << setw(20) << i.color
						 << setw(15) << i.brand
						 << setw(10) << i.quantity
						 << setw(10) << i.size
						 << setw(10) << i.price << "\n";
				}
			}
		}

		cout << "\n2 HOLE\n";
		for (auto &i : arr)
		{
			if (i.hole == "2 hole")
			{
				if (i.categ == "casio")
				{
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						 << setw(20) << i.color
						 << setw(15) << i.brand
						 << setw(10) << i.quantity
						 << setw(10) << i.size
						 << setw(10) << i.price << "\n";
				}
			}
		}
		return 0;
	}

	int DisplayCasioKids(vector<StrapItems> arr, string categ)
	{
		cout << "\n " << categ << " \n";
		cout << right << setw(10) << " ";
		cout << left << setw(5) << "ID"
			 << setw(20) << "Color"
			 << setw(15) << "Brand"
			 << setw(10) << "Qty"
			 << setw(10) << "Size"
			 << setw(10) << "Price" << "\n";

		cout << "1 HOLE\n";
		for (auto &i : arr)
		{
			if (i.hole == "1 hole")
			{
				if (i.categ == "casio w/ cover")
				{
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						 << setw(20) << i.color
						 << setw(15) << i.brand
						 << setw(10) << i.quantity
						 << setw(10) << i.size
						 << setw(10) << i.price << "\n";
				}
			}
		}

		cout << "\n2 HOLE\n";
		for (auto &i : arr)
		{
			if (i.hole == "2 hole")
			{
				if (i.categ == "casio w/ cover")
				{
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						 << setw(20) << i.color
						 << setw(15) << i.brand
						 << setw(10) << i.quantity
						 << setw(10) << i.size
						 << setw(10) << i.price << "\n";
				}
			}
		}
		return 0;
	}

	void Inventory_levels(vector<StrapItems> arr, string categ){
			cout << right << setw(100) << "----INVENTORY LEVELS----\n";
			bool low_stock = false;
			cout << " ";
			cout << left << setw(5) << "ID"
			<< setw(25) << "Color"
			<< setw(15) << "Brand"
			<< setw(30) << "Leather/Non-Leather"
			<< setw(10) << "Size"
			<< setw(10) << "Price" << "\n";
				
			for(auto&i : arr){
				if(i.quantity <= i.reorder_point){
					cout << " ";
					cout << "\n " << categ << " \n";
					cout << " ";
					cout << left << setw(5) << i.id
						<< setw(25) << i.color
						<< setw(15) << i.brand
						<< setw(30) << i.leather_type
						<< setw(10) << i.size
						<< setw(10) << i.price << "\n"
						<<" Current quantity: " << i.quantity << ". \n" 
						<<" Reorder point: " << i.reorder_point << ". \n\n\n";
					low_stock = true;
				}
			}
			if(!low_stock){
				cout << "All straps are at sufficient stock levels.\n";
			}
		}

	void switch_view(int strp){
		int opt;
		switch (strp){
			case 1:
				DisplayStitched(allstraps_arr, "STITCHED STRAPS");
				break;

			case 2:
				DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");
				break;

			case 3:
				do{
					cout << "\nCHOOSE CASIO TYPE:\n";
					cout << "[1] ADULT SIZE\n";
					cout << "[2] KIDS SIZE\n";
					cout << "[0] back\n";
					cout << "Choose an option: ";
					cin >> opt;

					switch (opt){
						case 1:
							DisplayCasioAdult(allstraps_arr, "CASIO STRAPS ADULT SIZE");
							break;

						case 2:
							DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
							break; 
						
						case 3:
							// needed for case 4 and 5 to not break.
							break;
						
						case 0:
							break;
						
						default:
							cout << "Invalid option :<\n";
							break;
					}
				} while (opt != 0);
				break;

			case 4:
				DisplayStitched(allstraps_arr, "STITCHED STRAPS");
				DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");
				DisplayCasioAdult(allstraps_arr, "CASIO STRAPS ADULT SIZE");
				DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
				break;

			case 5:
				Inventory_levels(allstraps_arr, "[ALERT] LOW ON STOCK!");
				break;

			case 0:
				break;

			default:
				cout << "Invalid option :<\n";
				break;
		}
	}
};