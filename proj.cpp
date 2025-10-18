 #include <iostream>
 #include <iomanip>
 #include <vector>
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
			// int size = sizeof(hihi) / sizeof(hihi[0]);

			// int battery_list(int i){
			// 	for(int i = 0; i < size; i++){
			// 		cout << "ID: " << hihi[i].id << endl;
			// 	}
			// }
			// int switch_bat (int bat){
			// 	 switch(bat){
			// 		case 1:
			// 			cout << "\nMAXWELL\n";
			// 			// details
			// 			break;
			// 		case 2:
			// 			cout << "\nRENATA\n"; 
				
						//array function
						//call function 
						// int index = 0; 
						// for(int i = 0; i < 5; i++){
						// 	cout << setw(20) << left << items[index++];
						// 	cout << setw(20) << left << items[index++];
						// 	//make function
						// 	//return variabke 
						// 	//call here
						// 	cout << endl;
						// }        
						
						// int hihi = battery_list(bat);
						// return hihi;
						// break;                      
			// 	}
			// };
	};

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

	class Straps{
    	private:
        	string color;
        	string brand;
        	int qty;
        	int size;
        	double price;
       	 
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

int main(){ 
	int opt, mat, inv, pos, bat, strp;
	Batteries battery;
	Straps s; 
    
	do{
    	cout << "\n\nPICK FROM THE FOLLOWING: \n";
    	cout << "[1] INVENTORY\n";
    	cout << "[2] POINT OF SALES (POS)\n";
    	cout << "[0] End\n\n";
    	cout << "Choose an option: ";
    	cin >> opt;
   	 
    
        	switch (opt){
            	case 1: 
					cout << "\nINVENTORY\n";
					cout << "[1] EDIT\n";
					cout << "[2] VIEW\n";
					cout << "[0] back\n\n";
					cout << "Choose an option: ";
					cin >> inv;
					
					do{
						switch (inv){
							case 1:
								cout << "\nEDIT MATERIALS: \n";
								cout << "[1] STRAPS\n";
								cout << "[2] BATTERIES\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> mat;
							
								switch (mat){
									case 1: 
                                    do{
										cout << "\nSTRAPS\n";
                                        cout << "[1] EDIT\n";
                                        cout << "[2] ADD\n";
                                        cout << "[3] DELETE\n";                                    
                                        cout << "[4] SEARCH NAME OF STRAP \n";
                                        cout << "[0] back\n";
                                        cout << "Choose an option: ";
                                        cin >> strp;

                                        switch(strp){
                                            case 1:
                                            	break;
                                            case 2:
                                            	break;
                                            case 3:
                                            	break;
                                            case 4:
                                            	break;
                                        }
                                    }while(strp !=0);
										break;

									case 2: 
                                    do{
										cout << "\nBATTERIES\n";
                                        cout << "[1] EDIT\n";
                                        cout << "[2] ADD\n";
                                        cout << "[3] DELETE\n";                                    
                                        cout << "[4] SEARCH NAME OF BATTERY \n";
                                        cout << "[0] back\n";
                                        cout << "Choose an option: ";
                                        cin >> bat;

                                        switch(bat){
                                            case 1:
                                            	break;
                                            case 2:
                                            	break;
                                            case 3:
                                            	break;
                                            case 4:
                                            	break;
                                        }
                                    }while(bat != 0);   
                                        break;
								}
								break;

							case 2:
								cout << "\nVIEW LIST OF MATERIALS: \n";
								cout << "[1] STRAPS\n";
								cout << "[2] BATTERIES\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> mat;
								                                                 
								switch (mat){
									case 1: 
										do{
											cout << "\nSTRAPS\n";
											cout << "[1] WITH STITCH STRAP\n";
											cout << "[2] NO STITCH STRAP\n";
											cout << "[3] SEARCH NAME OF STRAP \n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> strp;

											
											switch(strp){
												case 1:
													s.DisplayCategory(s.withstitch_arr, "WITH STITCH STRAPS");
													break;
												case 2:
													s.DisplayCategory(s.nostitch_arr, "NO STITCH STRAPS");           
													break;                      
												}										 
											
										}while(strp != 0);
										break;
									 
                                    
									case 2: 
										do{
											cout << "\nBATTERIES\n";
											cout << "[1] MAXWELL\n";
											cout << "[2] RENATA\n";
											cout << "[3] SEARCH NAME OF BATTERY \n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> bat;

				
											// battery.switch_bat(bat); 

										}while(bat != 0);
									    break;
                                }
								break;
						}

					}while(inv != 0 && mat != 0);

            	break;
           	 
            	case 2:
                	cout << "\nPOINT OF SALES (POS)\n";
					cout << "[1] OVERVIEW OF SALES\n";
					cout << "[2] SEARCH DATE OF SALES\n";
					cout << "[3] HISTORY OF RECEIPTS\n";
					cout << "[0] back\n\n";
					cout << "Choose an option: ";
					cin >> pos;
					
					do{
						switch (pos){
							case 1: 	
								cout << "\nOVERVIEW OF SALES";
								break; 

							case 2: 
								cout << "\nSEARCH DATE OF SALES";
								break;
							case 3:
								cout << "\nHISTORY OF RECEIPTS";
								break;
						}
					}while(pos < 0);

            	// break;
        	}
       	 
	}while (opt != 0);    

	return 0;
}

