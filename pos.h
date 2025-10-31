 #include <iostream>
 #include <string>
 #include <vector>
 #include <limits>
 #include <algorithm>
 #include <cmath>
 #include <ctime>
 using namespace std;
class Pos{ 
		private:  
         struct dates{
                int year; 
                int month; 
                int day; 
        };
            int stop = 1;
            Straps& s;
            Batteries& b;
			string mobile_num; 
            int pick;
            int straps; 
            int access;
            int qty;
            int d;
            int bats;
            dates current; 
            dates input_date;
            string details;
            vector <string> costumer;
            vector <dates> date;
            vector <pair<int,int>> a_id;
            vector <pair<int,int>> a_id_bat;
            vector <Straps :: StrapItems> store;
            vector <Batteries :: BattItems> store_b;
            vector<Straps :: StrapItems>& allstraps_arr;
            vector<Batteries :: BattItems>& allbatt_arr;

           

        public: 
            Pos(Straps& straps , Batteries& bats) : s(straps),b(bats), allstraps_arr(straps.allstraps_arr), allbatt_arr(bats.allbatt_arr){}


            void input() {
                cout << "DOUBLE CHECK BEFORE ENTERING NO EDIT!!";
                cout << "\nCostumers name: ";
                cin.ignore();
                getline(cin, details);
                costumer.push_back(details);
                  for (auto& i : costumer ) {
                        cout << i << endl;
                    }

                do {
                    cout << "\nEnter mobile number: +63";
                    getline(cin,mobile_num);
                }while(mobile_checker() == 1);

                do{
                    cout << "\nDATE\n[1] today\n[2] Different day\n[0] done\nPick: ";
                    cin>> d; 
                    add_date(d);
                }while(stop != 0);

                do{
                    cout << "\n\nPick Items\n[1] Straps\n[2] Battery\n[0] back"; 
                    cout << "\nPick: "; 
                    cin>> pick;
                    POS_pick(pick);
                }while(pick != 0);
            }

            int add_date( int d){
                switch(d){
                    case 1:{

                        time_t now = time(nullptr);
                        tm*localTime = localtime(&now);

                        current.year = 1900 + localTime->tm_year;
                        current.month = 1 + localTime->tm_mon;
                        current.day = localTime->tm_mday;

                        date.push_back(current);

                        cout << "Date saved succesfully! :>";
                        stop = 0;
                        break;
                    }

                    case 2: 
                        cout << "Enter date (YYYY MM DD): ";
                        cin >> input_date.year >> input_date.month >> input_date.day ;

                        date.push_back(input_date);

                        cout << "Date saved succesfully! :>";
                        stop = 0;
                        break;

                    default: 
                        if(d != 0){
                            cout << "invalid input :<";
                        }
                }
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
                        do {
                            cout << "\n\nBATTERIES";
                            cout << "\n[1] MAXWELL BATTERY\n[2] RENATA BATTERY\n[0] back\n";
                            cout << "items: ";
                            cin >>  bats; 
                            POS_bats(bats);
                        }while (bats != 0); 
                        break; 

                    default: 
                        if(pick != 0){
                            cout << "invalid input :<";
                        }
                }
            }

            int POS_bats(int bats){
                switch(bats){
                    case 1: 
                        do{
                            b.DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
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
                                access_id2(access, qty);
                            }while(access != 0);
                            break;

                    case 2: 
                        do{
                            b.DisplayRenata(allbatt_arr, "RENATA BATTERY"); 
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
                                access_id2(access, qty);
                        }while(access != 0);
                        break;
                    default: 
                        if(bats != 0){
                            cout << "invalid input :<";
                        }
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

                    default: 
                        if(straps != 0){
                            cout << "invalid input :<";
                        }
                }
                
                return 0;
            }

            void access_id2 (int access, int& qty){
                a_id_bat.emplace_back(access, qty); 
                store_b.emplace_back(b.allbatt_arr[access -1]);  
                int last_id = a_id_bat.back().first;

                if(last_id == 0){
                    a_id_bat.erase(
                        remove_if(a_id.begin(), a_id.end(), 
                                    [](pair<int,int>& p ){
                                        return p.first == 0;
                                    }), a_id.end()
                    );
                }
                int current_qty = b.allbatt_arr[access - 1].quantity;

                
                while(qty > current_qty ){
                    cout << "Not enough items :<\nInput quantity: ";
                    cin >> qty;
                }

                store_b.back().quantity -=  qty;
                b.allbatt_arr[last_id -1].quantity -= qty;

                cout << right << setw(5) << " ";
			    cout << left << setw(5) << "ID"
                << setw(15) << "Brand"
				<< setw(10) << "Qty"
				<< setw(10) << "Price" << "\n";

                cout << right << setw(5) << " ";
                cout << left << setw(5) << store_b.back().id
                    << setw(15) << b.allbatt_arr[last_id -1].brand
                    << setw(10) << b.allbatt_arr[last_id -1].quantity
                    << setw(10) << b.allbatt_arr[last_id -1].price << "\n";
            
            }

            void access_id(int access,int& qty){
                a_id.emplace_back(access, qty);
               

                store.emplace_back(s.allstraps_arr[access - 1]);    
                

                int last_id = a_id.back().first;

                if(last_id == 0){
                    a_id.erase(
                        remove_if(a_id.begin(), a_id.end(), 
                                    [](pair<int,int>& p ){
                                        return p.first == 0;
                                    }), a_id.end()
                    );
                }

                int current_qty = s.allstraps_arr[access - 1].quantity;
            

                while(qty > current_qty ){
                    cout << "Not enough items :<\nInput quantity: ";
                    cin >> qty;
                }

                store.back().quantity -=  qty;
                s.allstraps_arr[last_id -1].quantity -= qty;
           
                
                cout << right << setw(10) << " ";
			    cout << left << setw(5) << "ID"
				<< setw(20) << "Color"
				<< setw(15) << "Brand"
				<< setw(15) << "Leather Type"
				<< setw(10) << "Qty"
				<< setw(10) << "Size"
				<< setw(10) << "Price" << "\n";

                cout << right << setw(10) << " ";
                cout << left << setw(5) << store.back().id
                    << setw(20) << s.allstraps_arr[last_id -1].color
                    << setw(15) << s.allstraps_arr[last_id -1].brand
                    << setw(15) << s.allstraps_arr[last_id -1].leather_type
                    << setw(10) << s.allstraps_arr[last_id -1].quantity
                    << setw(10) << s.allstraps_arr[last_id -1].size
                    << setw(10) << s.allstraps_arr[last_id -1].price << "\n";


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