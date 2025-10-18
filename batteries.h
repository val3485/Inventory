 #include <iostream>
 #include <vector>
 #include <string>
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

			void selected(){
				

			}
	};
