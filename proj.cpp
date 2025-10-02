 #include <iostream>
using namespace std;

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
int main()
{
	int opt, mat, inv, again;
    
	do{
    	cout << "PICK FROM THE FOLLOWING: \n";
    	cout << "1. INVENTORY\n";
    	cout << "2. POINT OF SALES (POS)\n\n";
    	cout << "CHOOSE OPTION: \n";
    	cin >> opt;
   	 
    
        	switch (opt){
            	case 1:
                	cout << "INVENTORY\n";
                	cout << "1. EDIT\n";
                	cout << "2. VIEW\n";
                	cout << "CHOOSE: \n";
                	cin >> inv;
               	 
                	switch (inv){
                     	case 1:
                        	cout << "EDIT MATERIALS: \n";
                        	cout << "1. STRAPS\n";
                        	cout << "2. BATTERIES\n";
                        	cout << "CHOOSE FROM THE FOLLOWING: ";
                        	cin >> mat;
                       	 
                        	switch (mat){
                            	case 1: cout << " STRAPS \n";
                            	case 2: cout << "BATTERIES\n";
                        	}
                     	case 2:
                        	cout << "VIEW LIST OF MATERIALS: \n";
                        	cout << "1. STRAPS\n";
                        	cout << "2. BATTERIES\n";
                        	cout << "CHOOSE FROM THE FOLLOWING: ";
                        	cin >> mat;
                       	 
                        	switch (mat){
                            	case 1: cout << " STRAPS\n";
                            	case 2: cout << "BATTERIES\n";
                        	}
                 	}
            	break;
           	 
            	case 2:
                	cout << "POINT OF SALES (POS)\n";
            	break;
        	}
       	 
    	cout << "BACK TO MAIN MENU? (1-YES, 0-NO)\n";
    	cin >> again;
	}while (again < 0);    
	return 0;
}





