 #include <iostream>
 #include <string>
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
			};

			struct total_used {
				// get strtuct mats and add other expenses aside from materials
				//possible function 1

			};
		
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