 #include <iostream>
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
	};

	int POS_sales (int &sale){
			// cin >> sale;
			switch(sale) {
				case 1:
					cout << "\nORDER BY DAY";
						cout <<"\n[0] back\n";
						cin >> sale;
					
					break;
				case 2:
					cout << "\nOrder by Week: ";
					break;
				// default: 
				// 	cout << "Invalid input :<"; 
				// 	break; 

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

int main(){ 
	int opt, mat, inv, pos, sale,edit, search;
    
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
										cout << " STRAPS \n";
										break;
									case 2: 
										cout << "BATTERIES\n";
										break;
								}
								break;

							case 2:
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
                	cout << "\nPOINT OF SALES (POS)\n";
					cout << "[1] OVERVIEW OF SALES\n";
					cout << "[2] SEARCH DATE OF SALES\n";
					cout << "[3] HISTORY OF RECEIPTS\n";
					cout << "[0] back\n\n";
					cout << "Choose an option: ";
					cin >> pos;
					
					do{
						POS_switch(pos, sale,search);
					}while(pos != 0 && sale != 0);

        	}
       	 
	}while (opt != 0);    

	return 0;
}





