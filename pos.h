 #include <iostream>
 #include <string>
 #include <vector>
 #include <limits>
 #include <algorithm>
 #include <cmath>
 using namespace std;
class Pos{ 
		private:  
            Straps& s;
			string name;
			string mobile_num; 
            int pick;
            int straps; 
            int access;
            int qty;
            // vector <stored> all;
            vector <pair<int,int>> a_id;
            vector <Straps :: StrapItems> store;
            vector<Straps :: StrapItems>& allstraps_arr;
            
            // struct Stored {
            //     int access;
            //     int qty;
            //     Straps::StrapItems item;
            // };
		public: 

            Pos(Straps& straps) : s(straps), allstraps_arr(straps.allstraps_arr){}



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
                            cout << "\n\nSTRAPS";
                            cout << "\n[1] WITH STITCH STRAPS\n[2] NO STITCH STRAPS\n[3] CASIO STRAPS KIDS SIZE W/ COVER\n[4] CASIO STRAPS ADULT SIZE\n[0]back\n";
                            cout << "items: ";
                            cin >> straps;  
                            POS_straps(straps);
                        }while(straps != 0);
                        break; 

                    case 2:
                        cout << "BATTERIES";

                        break; 
                }
            }



            int POS_straps(int straps){
                switch (straps){
                    case 1: 
                        do{
                            s.DisplayStitched(s.allstraps_arr, "WITH STITCH STRAPS");;
                            cout << "\n[0] done\npick by id: ";
                            cin >> access;
                            
                            if (access == 0) break;
                            
                                do{ 
                                    cout << "Quantity: ";
                                    cin >> qty;
                                    if (qty == 0 ){
                                        cout << "invalid :<\n";
                                    }
                                }while(qty == 0);
                            access_id(access, qty);
                        }while(access != 0);
                        break; 

                    case 2:
                        do{
                            s.DisplayNoStitched(s.allstraps_arr, "NO STITCH STRAPS"); 
                            cout << "\n[0] done\npick by id: ";
                            cin >> access;
                             if (access == 0) break;
                            
                                do{ 
                                   
                                    cout << "Quantity: ";
                                    cin >> qty;
                                    if (qty == 0 ){
                                        cout << "invalid :<\n";
                                    }
                                }while(qty == 0);
                            access_id(access, qty);
                        }while(access != 0);
     
                        break;

                    case 3: 
                        do{
                            s.DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
                            cout << "\n[0] done\npick by id: ";
                            cin >> access;
                           
                             if (access == 0) break;
                            
                                do{ 
                                   
                                    cout << "Quantity: ";
                                    cin >> qty;
                                    if (qty == 0 ){
                                        cout << "invalid :<\n";
                                    }
                                }while(qty == 0);
                            access_id(access, qty);
                        }while(access != 0);
                        break; 
                    case 4: 
                         do{
                            s.DisplayCasio(allstraps_arr, "CASIO STRAPS ADULT SIZE"); 
                            cout << "\n[0] done\npick by id: ";

                            cin >> access;
                             if (access == 0) break;
                            
                                do{ 
                                   
                                    cout << "Quantity: ";
                                    cin >> qty;
                                    if (qty == 0 ){
                                        cout << "invalid :<\n";
                                    }
                                }while(qty == 0);
                            access_id(access, qty);

                        }while(access !=0 );

                        break; 


                }
                
                return 0;
            }


            void access_id(int access,int& qty){
                a_id.emplace_back(access, qty);

                store.emplace_back(s.allstraps_arr[access - 1]);    
                
                if(access == 0){
                    a_id.erase(
                        remove_if(a_id.begin(), a_id.end(), 
                                    [](pair<int,int>& p ){
                                        return p.first == 0;
                                    }), a_id.end()
                    );
                }

                store[access - 1].quantity -=  qty;
                allstraps_arr[access -1].quantity -= qty;
                

                cout << right << setw(10) << " ";
			    cout << left << setw(5) << "ID"
				<< setw(20) << "Color"
				<< setw(15) << "Brand"
				<< setw(15) << "Leather Type"
				<< setw(10) << "Qty"
				<< setw(10) << "Size"
				<< setw(10) << "Price" << "\n";

                cout << right << setw(10) << " ";
                cout << left << setw(5) << store[access - 1].id
                    << setw(20) << store[access - 1].color
                    << setw(15) << store[access - 1].brand
                    << setw(15) << store[access - 1].leather_type
                    << setw(10) << store[access - 1].quantity
                    << setw(10) << store[access - 1].size
                    << setw(10) << store[access - 1].price << "\n";
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