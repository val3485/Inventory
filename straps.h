#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Straps{
    	private:
        	string color;
        	string brand;
        	int qty;
        	int size;
        	double price;
       	 
			public:
			
			struct StrapItems { //struct is used as a container for related data
				int id;
				string categ;
				string color;
				string brand;
				string leather_type;
				int quantity;
				string size;
				string kid_size;
				double price;
				string hole;
	
				StrapItems(int i, string ct, string c, string b, string lt, int q, string s, double p, string h) //this is called a constructor, it reads(?) the data from the array in order.
				: id(i), categ (ct), color(c), brand(b), leather_type(lt), quantity(q), size(s), price(p), hole(h) {}
			};
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

			vector<StrapItems> allstraps_arr = { //vector is used make the array more efficient. you can modify it without manually entering the size 
				{1, "stitched", "black w/ black", "", "Buffalo Calf", 10, "16-19", 850, ""},
				{2, "stitched", "brown dark", "", "Buffalo Calf", 10, "16-19", 850, ""},
				{3, "stitched", "black w/ white", "", "Buffalo Calf", 10, "16-19", 850, ""},
				{4, "stitched", "brown light", "", "Buffalo Calf", 10, "16-19", 850, ""}, 

				{5, "no stitch", "black", "Alpha", "", 10, "16 - 24", 1500, ""},
				{6, "no stitch", "black", "Alpha", "", 10, "16 - 24", 1500, ""},
				{7, "no stitch", "black", "Alpha", "", 10, "16 - 24", 1500, ""},
				{8, "no stitch", "black", "Alpha", "", 10, "16 - 24", 1500, ""},

				{9, "casio", "black", "Casio", "Null", 10, "Fixed", 750, "1 hole"},
				{10, "casio", "blue dark", "Casio", "Null", 10, "Fixed", 750, "1 hole"},
				{11, "casio", "blue light", "Casio", "Null", 10, "Fixed", 750, "1 hole"},
				{12, "casio", "pink dark", "Casio", "Null", 10, "Fixed", 750, "1 hole"},

				{13, "casio", "black", "Casio", "Null", 10, "Fixed", 950, "2 hole"},
				{14, "casio", "blue dark", "Casio", "Null", 10, "Fixed", 950, "2 hole"},
				{15, "casio", "pink dark", "Casio", "Null", 10, "Fixed", 950, "2 hole"},
				{16, "casio", "pink dark", "Casio", "Null", 10, "Fixed", 950, "2 hole"},

				{17, "casio", "black", "Casio", "Null", 10, "small", 1200, "1 hole"},
				{18, "casio", "blue dark", "Casio", "Null", 10, "small", 1200, "1 hole"},
				{19, "casio", "blue light", "Casio", "Null", 10, "small", 1200, "1 hole"},
				{20, "casio", "pink dark", "Casio", "Null", 10, "small", 1200, "1 hole"},

				{21, "casio", "black", "Casio", "Null", 10, "large", 1500, "2 hole"},
				{22, "casio", "blue dark", "Casio", "Null", 10, "large", 1500, "2 hole"},
				{23, "casio", "pink dark", "Casio", "Null", 10, "large", 1500, "2 hole"},
				{24, "casio", "pink dark", "Casio", "Null", 10, "large", 1500, "2 hole"}
			};

			int DisplayStitched(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << right << setw(10) << " ";
				cout << left << setw(5) << "ID"
					<< setw(20) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Size"
         			<< setw(10) << "Price" << "\n";

				for (auto &i : arr) {
					if(i.categ == "stitched"){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}
				return 0;
			}

			int DisplayNoStitched(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << right << setw(10) << " ";
				cout << left << setw(5) << "ID"
					<< setw(20) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Size"
         			<< setw(10) << "Price" << "\n";

				for (auto &i : arr) {
					if(i.categ == "no stitch"){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}
				return 0;
			}

			int DisplayCasio(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << right << setw(10) << " ";
				cout << left << setw(5) << "ID"
					<< setw(20) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Size"
         			<< setw(10) << "Price" << "\n";

				cout << "1 HOLE\n";
				for (auto &i : arr) {
					if(i.hole == "1 hole"){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}

				cout << "\n2 HOLE\n";
				for (auto &i : arr) {
					if(i.hole == "2 hole"){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}
				return 0;
			}

			int DisplayCasioKids(vector<StrapItems> arr, string categ) {
				cout << "\n " << categ << " \n";
				cout << right << setw(10) << " ";
				cout << left << setw(5) << "ID"
					<< setw(20) << "Color"
					<< setw(15) << "Brand"
         			<< setw(15) << "Leather Type"
         			<< setw(10) << "Qty"
         			<< setw(10) << "Size"
         			<< setw(10) << "Price" << "\n";

				cout << "1 HOLE\n";
				for (auto &i : arr) {
					if(i.size == "small"){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}

				cout << "\n2 HOLE\n";
				for (auto &i : arr) {
					if(i.size == "large"){
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}
				return 0;
			}

			void switch_view(int strp){
			int choice;
			switch(strp){
				case 1:
					DisplayStitched(allstraps_arr, "WITH STITCH STRAPS");
					break;

				case 2:
					DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");           
					break;    

				case 3:
					cout << "\nCHOOSE CASIO TYPE:\n";
					cout << "[1] KIDS SIZE\n" ;
					cout << "[2] ADULT SIZE\n" ;
					cout << "[0] back\n" ;
					cout << "Choose an option: " ;
					cin >> choice;

					if(choice == 1) {
						DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
					} else if(choice == 2) {
						DisplayCasio(allstraps_arr, "CASIO STRAPS ADULT SIZE");                                 
					}
					break;   

				case 4:
					DisplayStitched(allstraps_arr, "WITH STITCH STRAPS");
					DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");
					DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
					DisplayCasio(allstraps_arr, "CASIO STRAPS ADULT SIZE"); 
					break;
				}	
			}	

			void switch_edit(int strp){  //go by id??
				switch(strp){
					case 1:
						do{
							cout << "\nADD ITEM\n";
							cout << "[1] WITH STITCH STRAP\n";
							cout << "[2] NO STITCH STRAP\n";
							cout << "[3] CASIO STRAP\n";
							cout << "[0] back\n";
							cout << "Choose an option: ";
							cin >> strp;
							

						}while(strp != 0);
						break;
					case 2:
						do{
							cout << "\nEDIT ITEM\n";
							cout << "[1] WITH STITCH STRAP\n";
							cout << "[2] NO STITCH STRAP\n";
							cout << "[3] CASIO STRAP\n";
							cout << "[0] back\n";
							cout << "Choose an option: ";
							cin >> strp;
							

						}while(strp != 0);
						break;
					case 3:
						do{
							cout << "\nDELETE ITEM\n";
							cout << "[1] WITH STITCH STRAP\n";
							cout << "[2] NO STITCH STRAP\n";
							cout << "[3] CASIO STRAP\n";
							cout << "[4] SEARCH NAME OF STRAP \n";
							cout << "[0] back\n";
							cout << "Choose an option: ";
							cin >> strp;
							

						}while(strp != 0);
						break;
					case 4:
						break;
				}
			}
};
// #endif