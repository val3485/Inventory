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
			
			struct batt {
				int id;
				string brand;
				int quantity;
				int price;
			};
			
			vector<batt> renata_arr = {
				{1, "Renata 314", 10, 500},
				{2, "Renata 510", 10, 500},
				{3, "Renata 600", 10, 500},
				{4, "Renata 700", 10, 500},
			};
			
			vector<batt> maxwell_arr = {
				{1, "Maxwell 314", 10, 500},
				{2, "Maxwell 510", 10, 500},
				{3, "Maxwell 600", 10, 500},
				{4, "Maxwell 700", 10, 500},
			};
			
			
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


	
				//EDIT
			void editItems(string brandName, int id, string newBrand, int newQty, int newPrice) {
				vector<Batteries::batt>*arr = nullptr;

				if(brandName == "Renata")
					arr = &batteryData->renata_arr;

				else if(brandName == "Maxwell")
					arr = &batteryData->maxwell_arr;

				else {
					cout << "Brand Name not found :(\n";
					return;
				}

				for(auto &b : *arr) {
					if(b.id == id) {
						b.brand = newBrand;
						b.quantity = newQty;
						b.price = newPrice;
						cout << "Item updated successfully!\n";
						return;
					}
				}

				cout << "Battery with ID " << id << " not found.\n";
			}

			//ADD
			void addItems(string brandName, int id, string brand, int quantity, int price) {
				Batteries::batt newBatt = {id, brand, quantity, price};

				if(brandName == "Renata")
					batteryData->renata_arr.push_back(newBatt);

				else if(brandName == "Maxwell")
					batteryData->maxwell_arr.push_back(newBatt);
				else {
					cout << "Brand Name not found :(\n";
					return;
				}

				cout << "Battery successfully added to " << brandName << " list.\n";
			}

			//DELETE
			void deleteItems(string brandName, int id, int dec) {
				vector<Batteries::batt> *arr = nullptr;

				if(brandName == "Renata")
					arr = &batteryData->renata_arr;

				else if(brandName == "Maxwell")
					arr = &batteryData->maxwell_arr;

				else {
					cout << "Brand Name not found :(\n";
					return;
				}

				if(dec == 1 ){
					for(auto it = arr->begin(); it != arr->end(); it++) {
						if(it->id == id) {
							arr->erase(it);
							cout << "Item deleted successfully.\n";
							return;
						}
					}
				}	

				else{
					cout << "Item not deleted.";
					return;
				}
				cout << "Item with ID " << id << " not found.\n";
			}
		};
