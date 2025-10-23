#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

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
				: id(i), categ (ct), brand(b), quantity(q), price(p) {}
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

		struct BatteryCRUD {
			private:
				Batteries *batteryData;

			public:
				BatteryCRUD(Batteries *data) {
					batteryData = data;
				}

			BatteryCRUD() {
				batteryData = nullptr;
			}


	
			// 	//EDIT
			// void editItems(string brandName, int id, string newBrand, int newQty, int newPrice) {
			// 	vector<Batteries::batt>*arr = nullptr;

			// 	if(brandName == "Renata")
			// 		arr = &batteryData->allbatt_arr;

			// 	else if(brandName == "Maxwell")
			// 		arr = &batteryData->allbatt_arr;

			// 	else {
			// 		cout << "Brand Name not found :(\n";
			// 		return;
			// 	}

			// 	for(auto &b : *arr) {
			// 		if(b.id == id) {
			// 			b.brand = newBrand;
			// 			b.quantity = newQty;
			// 			b.price = newPrice;
			// 			cout << "Item updated successfully!\n";
			// 			return;
			// 		}
			// 	}

			// 	cout << "Battery with ID " << id << " not found.\n";
			// }

			// //ADD
			// void addItems(string brandName, int id, string brand, int quantity, int price) {
			// 	Batteries::batt newBatt = {id, brand, quantity, price};

			// 	if(brandName == "Renata")
			// 		batteryData->allbatt_arr.push_back(newBatt);

			// 	else if(brandName == "Maxwell")
			// 		batteryData->allbatt_arr.push_back(newBatt);
			// 	else {
			// 		cout << "Brand Name not found :(\n";
			// 		return;
			// 	}

			// 	cout << "Battery successfully added to " << brandName << " list.\n";
			// }

			// //DELETE
			// void deleteItems(string brandName, int id, int dec) {
			// 	vector<Batteries::batt> *arr = nullptr;

			// 	if(brandName == "Renata")
			// 		arr = &batteryData->allbatt_arr;

			// 	else if(brandName == "Maxwell")
			// 		arr = &batteryData->allbatt_arr;

			// 	else {
			// 		cout << "Brand Name not found :(\n";
			// 		return;
			// 	}

			// 	if(dec == 1 ){
			// 		for(auto it = arr->begin(); it != arr->end(); it++) {
			// 			if(it->id == id) {
			// 				arr->erase(it);
			// 				cout << "Item deleted successfully.\n";
			// 				return;
			// 			}
			// 		}
			// 	}	

			// 	else{
			// 		cout << "Item not deleted.";
			// 		return;
			// 	}
			// 	cout << "Item with ID " << id << " not found.\n";
			// }
		};
