 #include <iostream>
 #include <vector>
 #include <string>
//  #ifndef STRAPS_H
//  #define STRAPS_H

class Straps{
    	private:
        	string color;
        	string brand;
        	int qty;
        	int size;
        	double price;
       	 
		struct StrapItems {
			int id;
			string color;
			string brand;
			string leather_type;
			int quantity;
			string size;
			double price;

			StrapItems(int i, string c, string b, string lt, int q, string s, double p)
			: id(i), color(c), brand(b), leather_type(lt), quantity(q), size(s), price(p) {}
		};

		struct strap{
				string categ_straps; 
				string color; 
				int qty; 
				int size; 
				int price; 
				bool kid_size; 
				
			};
			
    	public:
        	void setColor(string c){
            	color = c;
        	}
        	void setBrand(string brnd){
            	brand = brnd;
        	}
        	void setQty(int q){
            	qty = q;
        	}
        	void setSize(int s){
            	size = s;
        	}
        	void setPrice(double p){
            	price = p;
        	}
       	 
        	string getColor (){
            	return color;
        	}
        	string getBrand (){
            	return brand;
        	}
        	int getQty (){
            	return qty;
        	}
        	int getSize (){
            	return size;
        	}
       	 
        	double getPrice (){
            	return price;
        	}

			vector<StrapItems> withstitch_arr = {
				{1, "black w/ black", "", "Buffalo Calf", 10, "16-19", 850},
				{2, "black w/ white", "", "Buffalo Calf", 10, "16-19", 850},
				{3, "dark brown", "", "Buffalo Calf", 10, "16-19", 850},
				{4, "light brown", "", "Buffalo Calf", 10, "16-19", 850}
			};
			vector<StrapItems> nostitch_arr = {
				{1, "black", "Alpha", "", 10, "16 - 24", 1500}
			};

			int DisplayCategory(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << left << setw(5) << "ID"
					<< setw(15) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Price" << "\n";

				for (auto &i : arr) {
        			cout << left << setw(5) << i.id
						 << setw(15) << i.color
						 << setw(15) << i.brand
             			 << setw(15) << i.leather_type
            			 << setw(10) << i.quantity
            			 << setw(10) << i.price << "\n";
				}
				return 0;
			}
	};
// #endif