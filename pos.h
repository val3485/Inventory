 #include <iostream>
 #include <string>
 #include <vector>
 #include <limits>
 #include <algorithm>
 #include <cmath>
 #include "Straps.h" 
 using namespace std;

class Pos{ 
		private:  
        Straps s;
			string name;
			string mobile_num; 
            int pick;
            int straps; 
            int access;
            vector <int> store;

		public: 
            void input() {
                cout << "Costumers name: ";
                cin.ignore();
                getline(cin, name);

                do {
                    cout << "\nEnter mobile number: +63";
                    getline(cin,mobile_num);
                }while(mobile_checker() == 1);


                do{
                    cout << "\nPick Items\n[1] Straps\n[2] Battery\n[0] back"; 
                    cout << "\nPick: "; 
                    cin>> pick;
                    POS_pick(pick);
                }while(pick != 0);
            }

            int mobile_checker(){
                if(counter(mobile_num) != 9 &&  counter(mobile_num) != 11 ){
                    cout<<"invalid number :<";
                    return 1;
                }
                return 0;
            }

            int counter(string mobile_num){
                int count = 0;
                for (size_t c = 0 ; c < mobile_num.length(); c++){
                    count++;
                }
                return count;
            }

            void POS_pick(int pick){
                switch(pick){
                    case 1: 
                         do{
                            cout << "\nSTRAPS";
                            cout << "\n[1] WITH STITCH STRAPS\n[2] NO STITCH STRAPS\n[0]back\n";
                            cout << "items: ";
                            cin >> straps;  
                            POS_straps(straps);
                        }while(straps != 0);
                        break; 

                    case 2:
                        cout << "BATTERIES";
                        break; 
                }
                // return 0;
            }

            //function to store picked data :> 
            //add here function to remove when access is 0 

            int POS_straps(int straps){
                switch (straps){
                    case 1: 
                        do{

                            s.DisplayStitched();
                            cout << "\n[0] done\npick by id: ";

                            cin >> access;
                            store.push_back(access);
                                
                        }while(access != 0);
                        
                        for(int i =0 ; i < store.size(); i++){
                            cout << store[i] << " ";
                        }

                        break; 
                    case 2:
                        do{
                            s.DisplayNoStitched(); 
                            cout << "\n[0] done\npick by id: ";

                            cin >> access;
                            store.push_back(access);
                                    
                        }while(access != 0);
                        
                        for(int i =0 ; i < store.size(); i++){
                            cout << store[i] << " ";
                        }
                        
                        break;
                }
                return 0;
            }

			int POS_switch(int pos, int sale){
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
                return 0;
			}


            int POS_sales (int &sale){
					switch(sale) {
						case 1:
							cout << "\nORDER BY DAY";
							cout <<"\nDATA\n";	
							break;

						case 2:
							cout << "\nOrder by Week: ";
                            cout <<"\nDATA\n";
							break;
					}
                return 0;
			}
	};