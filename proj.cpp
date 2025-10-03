 #include <iostream>
using namespace std;

 	class Batteries{
		private:
			string brand; 
		
		public: 
			void setBrand(string b){
				brand = b;
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
	} ;

int main(){ 
	int opt, mat, inv, again;
    
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
										cout << " STRAPS \n";
										break;
									case 2: 
										cout << "BATTERIES\n";
										break;
								}
								break;

							case 2:
								cout << "VIEW LIST OF MATERIALS: \n";
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

							}
						break;
						}while(inv != 0);

				
                 	

            	break;
           	 
            	case 2:
                	cout << "POINT OF SALES (POS)\n";
            	break;
        	}
       	 
	}while (opt != 0);    

	return 0;
}





