 #include <iostream>
 #include <iomanip>
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
			struct strap{
				string categ_straps; 
				string color; 
				int qty; 
				int size; 
				int price; 
				bool kid_size; 
				
			};
	};

	class Pos{ 
		private:  
			string name;
			int mobile_num; 
			// struct straps{
				// get picked strap fro functions same with batt
			// }

			// struct batt{

			// }

			struct materials{
				// combine struct strapa and batt
			}

			struct total_used {
				// get strtuct mats and add other expenses aside from materials
				//possible function 1

			}
		
		public: 
			void setName(string n){
				name = n;
			}
			void setMobile_num(int m){
				mobile_num = m;
			}

			int POS_sales (int &sale){
					switch(sale) {
						case 1:
							cout << "\nORDER BY DAY";
								cout <<"\nDATA\n";
								// cin >> sale;
							
							break;
						case 2:
							cout << "\nOrder by Week: ";
							break;
					}
			
			}

			int POS_switch(int pos, int sale, int search){
				switch (pos){
					case 1: 	
						do{
							cout << "\nOVERVIEW OF SALES";
							cout << "\nSearch by\n" << "[1] Day\n[2] Week\n[0] back\n" <<"Enter Option: ";
							cin >> sale;
		
							POS_sales(sale);
						}while(sale != 0);
		
						break; 
		
					case 2: 
						pos = 0;
						cout << "\nSEARCH DATE OF SALES";
						break;
					case 3:
						pos = 0;
						cout << "\nHISTORY OF RECEIPTS";
						break;
				}
			}


	};


int main(){ 
	int opt, mat, inv, pos, bat, strp;
	Batteries battery;
	Straps s; 
	int opt, mat, inv, pos, sale,edit, search,bat,strp;
	Pos myPOS; 
    
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
								cin >> edit;
							
								switch (edit){
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
								do {
									cout << "\nVIEW LIST OF MATERIALS: \n";
									cout << "[1] STRAPS\n";
									cout << "[2] BATTERIES\n";
									cout << "[0] back\n\n";
									cout << "Choose an option: ";
									cin >> mat;
								
									switch (mat){
										case 1: 
											cout << " STRAPS\n";
											break;
										case 2: 
											cout << "BATTERIES\n";
											break;
									}
								}while (mat != 0);
							break;
						}

					}while(inv != 0 && mat != 0 && edit != 0);

            	break;
           	 
            	case 2:
					do{
						cout << "\nPOINT OF SALES (POS)\n";
						cout << "[1] OVERVIEW OF SALES\n";
						cout << "[2] SEARCH DATE OF SALES\n";
						cout << "[3] HISTORY OF RECEIPTS\n";
						cout << "[0] back\n\n";
						cout << "Choose an option: ";
						cin >> pos;
						
						myPOS.POS_switch(pos, sale,search);
					}while(pos != 0 && sale != 0);
					break; 
				case 3: 
					cout << "";
					break;

        	}
       	 
	}while (opt != 0);    

	return 0;
}

