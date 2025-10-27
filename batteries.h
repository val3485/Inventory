#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

 using namespace std;

class Batteries{
		private:
			string brand; 
			
		public: 
			void setBrand(string b){
				brand = b;
			}
			string getBrand (string b){
				return b;
        	}
			
			struct BattItems {
				int id;
				string categ;
				string brand;
				int quantity;
				int price;

				BattItems(int i, string ct, string b, int q, double p) //this is called a constructor, it reads(?) the data from the array in order.
				: id(i), categ(ct), brand(b), quantity(q), price(p) {}
			};
			
			vector<BattItems> allbatt_arr = {
				{1, "renata", "Renata 314", 10, 500},
				{2, "renata", "Renata 510", 10, 500},
				{3, "renata", "Renata 600", 10, 500},
				{4, "renata", "Renata 700", 10, 500},

				{5, "maxwell", "Maxwell 314", 10, 500},
				{6, "maxwell", "Maxwell 510", 10, 500},
				{7, "maxwell", "Maxwell 600", 10, 500},
				{8, "maxwell", "Maxwell 700", 10, 500}
			};

		int DisplayRenata(vector<BattItems> arr, string categ) {
			cout << "\n" << categ << " \n";
			cout << left << setw(5) << "ID"
				<< setw(15) << "Brand"
				<< setw(10) << "Qty"
				<< setw(10) << "Price" << "\n";

			for (auto &i : arr) {
				if(i.categ == "renata"){
					cout << left << setw(5) << i.id
						<< setw(15) << i.brand
						<< setw(10) << i.quantity
						<< setw(10) << i.price << "\n";
				}
			}
			return 0;
		}
			
		int DisplayMaxwell(vector<BattItems> arr, string categ) {
			cout << "\n" << categ << " \n";
			cout << left << setw(5) << "ID"
				<< setw(15) << "Brand"
				<< setw(10) << "Qty"
				<< setw(10) << "Price" << "\n";

			for (auto &i : arr) {
				if(i.categ == "maxwell"){
					cout << left << setw(5) << i.id
						<< setw(15) << i.brand
						<< setw(10) << i.quantity
						<< setw(10) << i.price << "\n";
				}
			}
			return 0;
		}

		void switch_view(int bat){
			switch(bat){
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

		class BatteryCRUD {
			private:
				Batteries& batt;
				// int geh;
				vector<Batteries::BattItems>& allbatt_arr;
				// vector<Batteries::BattItems>& heuy;
					
			public:

				BatteryCRUD(Batteries& batts) : batt(batts), allbatt_arr(batts.allbatt_arr){}

				//EDIT
			void editItems(string categ, int id, string newCateg, int newQty, int newPrice ) {
				
				transform(categ.begin(), categ.end(), categ.begin(), 
					[](unsigned char c)
					{
						return tolower(c);
					}
				);

				if(!categ.empty()){
					categ[0] = toupper(categ[0]);
				}

				batt.allbatt_arr = allbatt_arr;
				//play with this
				for(auto &b : allbatt_arr) {
					if(b.id == id) {
						b.categ = newCateg;
						b.quantity = newQty;
						b.price = newPrice;
						cout << "Item updated successfully!\n";
						return;
					}
				}

				cout << "Battery with ID " << id << " not found.\n";
			}

			//ADD
			void addItems(string categ, int id, string brand, int quantity, int price) { 
				vector<Batteries::BattItems>& allbatt_arr;
				
				Batteries::BattItems newBatt(id, categ, brand, quantity, price);

				transform(categ.begin(), categ.end(), categ.begin(), 
					[](unsigned char c){return tolower(c);}
				);

				if(categ == "renata" || categ == "maxwell"){
					batt.allbatt_arr.push_back(newBatt);

					cout << newBatt.brand << " " << newBatt.id;
					batt.DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
					batt.DisplayRenata(allbatt_arr, "RENATA BATTERY");
					return;
				}	
				else{
					cout << "Brand Name not found :(\n";
					return;
				}

				cout << "Battery successfully added to " << categ << " list.\n";
			}

			//DELETE
			void deleteItems(int id, int dec) {
				// batt.allbatt_arr
				// allbatt_arr* hi = &heuy;
				// batt.BattItems(int i) 
				// : id(i){}
				if(dec == 1 ){
					// for(auto it = allbatt_arr.begin(); it != allbatt_arr.end(); it++) {
						// if(it->id == id) {
							allbatt_arr.erase(allbatt_arr.begin() );
							cout << "Item deleted successfully.\n";
							cout << id;
							batt.DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
							batt.DisplayRenata(allbatt_arr, "RENATA BATTERY"); 
							return;
						// }
					// }
				}	
				else{
					cout << "Item not deleted.";
					return;
				}
				cout << "Item with ID " << id << " not found.\n";
			}
		};
