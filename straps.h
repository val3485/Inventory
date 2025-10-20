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
				{2, "brown dark", "", "Buffalo Calf", 10, "16-19", 850},
				{3, "black w/ white", "", "Buffalo Calf", 10, "16-19", 850},
				{4, "brown light", "", "Buffalo Calf", 10, "16-19", 850}
			};

			vector<StrapItems> nostitch_arr = {
				{1, "black", "Alpha", "", 10, "16 - 24", 1500},
				{2, "black", "Alpha", "", 10, "16 - 24", 1500},
				{3, "black", "Alpha", "", 10, "16 - 24", 1500},
				{4, "black", "Alpha", "", 10, "16 - 24", 1500}
			};

			vector<StrapItems> casio_arr = {
				{1, "black", "Casio", "Null", 10, "Fixed", 750},
				{2, "blue dark", "Casio", "Null", 10, "Fixed", 750},
				{3, "blue light", "Casio", "Null", 10, "Fixed", 750},
				{4, "pink dark", "Casio", "Null", 10, "Fixed", 750},

				{5, "black", "Casio", "Null", 10, "Fixed", 950},
				{6, "blue dark", "Casio", "Null", 10, "Fixed", 950},
				{7, "pink dark", "Casio", "Null", 10, "Fixed", 950},
				{8, "pink dark", "Casio", "Null", 10, "Fixed", 950},
			};

			int DisplayCategory(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << left << setw(5) << "ID"
					<< setw(20) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Size"
         			<< setw(10) << "Price" << "\n\n";

				for (auto &i : arr) {
        			cout << left << setw(5) << i.id
						 << setw(20) << i.color
						 << setw(15) << i.brand
             			 << setw(15) << i.leather_type
            			 << setw(10) << i.quantity
            			 << setw(10) << i.size
            			 << setw(10) << i.price << "\n";
				}
				return 0;
			}

			int DisplayCasio(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << right << setw(10) << " ";
				cout << left << setw(5) << "ID"
					<< setw(15) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Size"
         			<< setw(10) << "Price" << "\n";

				cout << "1 HOLE\n";
				for (auto &i : arr) {
					if(i.price == 750){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(15) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}

				cout << "\n2 HOLE\n";
				for (auto &i : arr) {
					if(i.price == 950){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(15) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}
					// } else if(i.price == 950){
					// 	cout << "\n2 HOLE\n";
					// 	cout << left << setw(5) << i.id
					// 		<< setw(15) << i.color
					// 		<< setw(15) << i.brand
					// 		<< setw(15) << i.leather_type
					// 		<< setw(10) << i.quantity
					// 		<< setw(10) << i.size
					// 		<< setw(10) << i.price << "\n";
					// }
				
				return 0;
			}

			int switch_strp(int strp){
			switch(strp){
				case 1:
					DisplayCategory(withstitch_arr, "WITH STITCH STRAPS");
					break;
				case 2:
					DisplayCategory(nostitch_arr, "NO STITCH STRAPS");           
					break;                      
				case 3:
					DisplayCasio(casio_arr, "CASIO STRAPS");           
					break;                      
				}	
			}			
};
// #endif