 #include <iostream>
 #include <set>    
 #include <map>
 #include <string>
 #include <vector>
 #include <limits>
 #include <algorithm>
 #include <cmath>
 #include <ctime>
 using namespace std;
class Pos{ 
        public: 
            struct dates{
                int year; 
                int month; 
                int day; 
            };
            struct costumer{
                string details;
                string mobile_num; 
                int cash; 
                int change; 
                int total;
                vector <dates> date;
                vector <Straps :: StrapItems> store;
                vector <Batteries :: BattItems> store_b;
                Pos* ref; 
                costumer() : details(""), mobile_num(""), cash(0),change(0),total(0){}
                costumer(string d, string m) : details(d), mobile_num(m), cash(0),change(0),total(0){}
                costumer(
                    string n,
                    string mobile,
                    int c ,
                    int chng,
                    int t,
                    vector <dates> d,
                    vector <Straps :: StrapItems> s,
                    vector <Batteries :: BattItems> sb
                ) 
                : details(n), mobile_num(mobile), cash(c),change(chng),total(t),date(d), store(s), store_b(sb){}

                void display() const {
                    cout << "\n\nName: \033[96m" <<left << setw(100) << details << "\n";
                    cout << "\033[0m09"<< mobile_num << "\n";
                    
                    for (const auto& d : date) {
                        cout << d.month << "/" << d.day << "/" << d.year << "\n";
                    }
                    cout << "\nTotal: " << total ; 
                    cout << " | Change: " << change; 
                    cout << " | Money: " << cash;  

                    cout << "\n------------------------------------------------------------------------------";
                    cout << "\nSTRAPS\n";
                    if(store.empty()){
                        cout << "No items selected\n"; 
                    }else{
                            cout << left 
                            << setw(20) << "Color"
                            << setw(15) << "Brand"
                            << setw(15) << "Leather Type"
                            << setw(10) << "Qty"
                            << setw(10) << "Size"
                            << setw(10) << "Price" << "\n";
                        for (const auto& s : store) {
                            cout << left << setw(5) 
                            << setw(20) << s.color
                            << setw(15) << s.brand
                            << setw(15) << s.leather_type
                            << setw(10) << s.quantity 
                            << setw(10) << s.size
                            << setw(10) << s.price << "\n";
                        }
                    }
                    cout << "-------------------------------------------------------------------------------";
                    cout << "\nBATTERIES\n";
                    
                    if(store_b.empty()){
                        cout << "No items selected"; 
                    }else {
                        cout << left 
                        << setw(15) << "Brand"
                        << setw(10) << "Qty"
                        << setw(10) << "Price" << "\n";
                        for (const auto& b : store_b) {
                            cout << setw(15) << b.brand
                            << setw(10) << b.quantity
                            << setw(10) << b.price << "\n";
                        }
                    }
                }
            };

        private:  
            int stop = 1;
            Straps& s;
            Batteries& b;
            int pick;
            int straps; 
            int access;
            int qty;
            int d;
            int bats;
            int srch_d;  
            int srch_m;  
            dates current; 
            dates input_date;
            map<pair<int,int>, vector<costumer>> week;
            set<int> uni_days;
            set<int> uni_month;
            vector <costumer> costumers;
            vector <costumer> all_costumers;
            vector <pair<int,int>> a_id;
            vector <pair<int,int>> a_id_bat;
            vector<Straps :: StrapItems>& allstraps_arr;
            vector<Batteries :: BattItems>& allbatt_arr;
            costumer c; 

        public: 
            //heuy
            Pos(Straps& straps , Batteries& bats) : s(straps),b(bats), allstraps_arr(straps.allstraps_arr), allbatt_arr(bats.allbatt_arr){}

            vector<costumer> costumer_list = {
                { "Clare Lubiano", "0962 585 8585", 10000, 7300, 2700,
                    {
                        {2025, 11, 01}
                    }, 
                    {
                        {3, "stitched", "black w/ white", "Null", "Buffalo Calf", 1, "16-19", 850, ""},
			            {4, "stitched", "brown light", "Null", "Buffalo Calf", 1, "16-19", 850, ""}, 
                    }, 
                    {
                        {3, "renata", "Renata 600", 1, 500},
				        {4, "renata", "Renata 700", 1, 500},
                    }
                },
                { "Sylvia Heart Sulla", "0962 656 8910", 10000, 7300, 2700 ,
                    {
                        {2025, 11, 01}
                    }, 
                    {
                        {3, "stitched", "black w/ white", "Null", "Buffalo Calf", 1, "16-19", 850, ""},
			            {4, "stitched", "brown light", "Null", "Buffalo Calf", 1, "16-19", 850, ""}, 
                    }, 
                    {
                        {3, "renata", "Renata 600", 1, 500},
				        {4, "renata", "Renata 700", 1, 500},
                    }
                },
                { "Chybes Shantee Naje", "0962 114 5862", 10000, 7300, 2700 ,
                    {
                        {2025, 10, 29}
                    }, 
                    {
                        {3, "stitched", "black w/ white", "Null", "Buffalo Calf", 1, "16-19", 850, ""},
			            {4, "stitched", "brown light", "Null", "Buffalo Calf", 1, "16-19", 850, ""}, 
                    }, 
                    {
                        {3, "renata", "Renata 600", 1, 500},
				        {4, "renata", "Renata 700", 1, 500},
                    }
                },
                { "Vinea Lei", "0962 645 7012", 10000, 7300, 2700 ,
                    {
                        {2025, 10, 27}
                    }, 
                    {
                        {3, "stitched", "black w/ white", "Null", "Buffalo Calf", 1, "16-19", 850, ""},
			            {4, "stitched", "brown light", "Null", "Buffalo Calf", 1, "16-19", 850, ""}, 
                    }, 
                    {
                        {3, "renata", "Renata 600", 1, 500},
				        {4, "renata", "Renata 700", 1, 500},
                    }
                }
            };

            void input() {
                cout << "\033[96mDOUBLE CHECK YOU CANNOT EDIT!!";
                cout << "\n\033[0mCostumers name: ";
                cin.ignore();
                getline(cin, c.details);
                costumers.push_back(c);

                do {
                    cout << "\nEnter mobile number: +63";
                    getline(cin,c.mobile_num);
                    costumers.push_back(c);
                }while(mobile_checker() == 1);

                do{
                    cout << "\nDATE\n[1] today\n[2] Different day\n[0] done\nPick: ";
                    cin>> d; 
                    add_date(d);
                }while(stop != 0);

                do{
                    cout << "\n\nPick Items\n[1] Straps\n[2] Battery\n[0] Done"; 
                    cout << "\nPick: "; 
                    cin>> pick;
                    POS_pick(pick);
                }while(pick != 0);

                do{
                    cout << "\nInput Costumers Money: "; 
                    cin >> c.cash ; 
                    if(c.cash < total_price()){
                        cout << "Insufficient Cash :<" << "\nTo be paid: " << total_price();
                    }
                    costumers.push_back(c);
                }while(c.cash < total_price());

                
                show_current();
                change();
                all_costumers.push_back(c);
            }
      

            int total_price(){
                int total_s = 0;
                for(const auto& s : c.store ){
                    total_s +=  s.price * s.quantity; 
                }
                int total_b = 0;
                for(const auto& b : c.store_b ){
                    total_b +=  b.price * b.quantity; 
                }

                c.total = total_b + total_s;
                costumers.push_back(c);
                return costumers.back().total;
            }

            int change(){
                c.change = c.cash - total_price();
                costumers.push_back(c);

                cout << "\nTotal amount: " << total_price();
                cout << "\nChange: " << costumers.back().change;
            }
            
            void show_current(){
                cout << "\n\nName: " << c.details << "\n";
                cout << "09"<< c.mobile_num << "\n";
                for (const auto& d : c.date) {
                    cout << d.month << "/" << d.day << "/" << d.year << "\n";
                }

                cout << "------------------------------------------------------------------------------";
                cout << "\nSTRAPS\n";
                if(c.store.empty()){
                    cout << "No items selected\n"; 
                }else{
                        cout << left 
                        << setw(20) << "Color"
                        << setw(15) << "Brand"
                        << setw(15) << "Leather Type"
                        << setw(10) << "Qty"
                        << setw(10) << "Size"
                        << setw(10) << "Price" << "\n";
                    for (const auto& s : c.store) {
                        cout << left << setw(5) 
                        << setw(20) << s.color
                        << setw(15) << s.brand
                        << setw(15) << s.leather_type
                        << setw(10) << s.quantity 
                        << setw(10) << s.size
                        << setw(10) << s.price << "\n";
                    }
                }
                cout << "-------------------------------------------------------------------------------";
                cout << "\nBATTERIES\n";
                
                if(c.store_b.empty()){
                    cout << "No items selected"; 
                }else {
                    cout << left 
                    << setw(15) << "Brand"
                    << setw(10) << "Qty"
                    << setw(10) << "Price" << "\n";
                    for (const auto& b : c.store_b) {
                        cout << setw(15) << b.brand
                        << setw(10) << b.quantity
                        << setw(10) << b.price << "\n";
                    }
                }
                cout << "Total: " << c.total ; 
                cout << "Change: " << c.change; 
                cout << "Money: " << c.cash; 
                cout << "\n------------------------------------------------------------------------------";

            }

            int add_date( int d){
                switch(d){
                    case 1:{

                        time_t now = time(nullptr);
                        tm*localTime = localtime(&now);

                        current.year = 1900 + localTime->tm_year;
                        current.month = 1 + localTime->tm_mon;
                        current.day = localTime->tm_mday;

                        c.date.clear();
                        c.date.push_back(current);
                        cout << "Date saved succesfully! :>";
                        stop = 0;
                        break;
                    }

                    case 2: 
                        cout << "Enter date (YYYY MM DD): ";
                        cin >> input_date.year >> input_date.month >> input_date.day ;
                        c.date.clear();
                        c.date.push_back(input_date);
                        cout << "Date saved succesfully! :>";
                        stop = 0;
                        break;

                    default: 
                        if(d != 0){
                            cout << "invalid input :<";
                        }
                }
            }
            
            int id_checker(){
                cout << "\n[0] done\npick by id: ";
                cin >> access;
                if(access > s.allstraps_arr.back().id){
                    cout << "no existing ID :<";
                }
            }

            int POS_straps(int straps){
                switch (straps){
                    case 1: 
                        do{
                            s.DisplayStitched(allstraps_arr, "WITH STITCH STRAPS");;
                            do{
                               id_checker();
                            }while(access > s.allstraps_arr.back().id);
                            
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
                            s.DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS"); 
                            do{
                               id_checker();
                            }while(access > s.allstraps_arr.back().id);
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
                            do{
                               id_checker();
                            }while(access > s.allstraps_arr.back().id);
                        
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
                           do{
                               id_checker();
                            }while(access > s.allstraps_arr.back().id);

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


            void access_id(int access,int& qty){
                a_id.emplace_back(access, qty);
            

                c.store.emplace_back(s.allstraps_arr[access - 1]);    
                

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

                c.store.back().quantity =  qty;
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
                cout << left << setw(5) << c.store.back().id
                    << setw(20) << s.allstraps_arr[last_id -1].color
                    << setw(15) << s.allstraps_arr[last_id -1].brand
                    << setw(15) << s.allstraps_arr[last_id -1].leather_type
                    << setw(10) << c.store.back().quantity
                    << setw(10) << s.allstraps_arr[last_id -1].size
                    << setw(10) << s.allstraps_arr[last_id -1].price << "\n";


            }

            int POS_bats(int bats){
                switch(bats){
                    case 1: 
                        do{
                            b.DisplayMaxwell(allbatt_arr, "MAXWELL BATTERY");
                            do{
                               id_checker();
                            }while(access > s.allstraps_arr.back().id);

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
                            do{
                               id_checker();
                            }while(access > s.allstraps_arr.back().id);

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

            
            void access_id2 (int access, int& qty){
                a_id_bat.emplace_back(access, qty); 
                c.store_b.emplace_back(b.allbatt_arr[access -1]);  

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

                c.store_b.back().quantity =  qty;
                b.allbatt_arr[last_id -1].quantity -= qty;

                cout << right << setw(5) << " ";
                cout << left << setw(5) << "ID"
                << setw(15) << "Brand"
                << setw(10) << "Qty"
                << setw(10) << "Price" << "\n";

                cout << right << setw(5) << " ";
                cout << left << setw(5) << c.store_b.back().id
                    << setw(15) << b.allbatt_arr[last_id -1].brand
                    << setw(10) << c.store_b.back().quantity
                    << setw(10) << b.allbatt_arr[last_id -1].price << "\n";
            
            }

            int mobile_checker(){
                if(counter(c.mobile_num) != 9 &&  counter(c.mobile_num) != 11 ){
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

                
			int POS_switch(int pos, int sale){
				switch (pos){
					case 1: 	
						do{
							cout << "\nOVERVIEW OF SALES";
							cout << "\nView by\n" << "[1] Day\n[2] Week\n[0] back\n" <<"Enter Option: ";
							insert_days(costumer_list, all_costumers);
                            cin >> sale;
							POS_sales(sale, costumer_list, all_costumers, uni_days, uni_month, week);
						}while(sale != 0);
		
						break; 
		
					case 2: 
						pos = 0;
						cout << "\nSEARCH DATE OF SALES";
                        cout << "\nSearch Day: "; 
                        cin >> srch_d;
                        cout << "\nSearch Month: "; 
                        cin >> srch_m; 

                        for (const auto& c : costumer_list){
                            for(auto& d : c.date){
                                if( d.day == srch_d || d.month == srch_m){
                                   c.display();
                                }
                            }
                        }
                        for (const auto& c : all_costumers){
                            for(auto& d : c.date){
                                if( d.day == srch_d || d.month == srch_m){
                                   c.display();
                                }
                            }
                        }
						break;

					case 3:
						pos = 0;
						cout << "\nHISTORY OF RECEIPTS";
                        display_receipts(costumer_list);
                        for(const auto& c :  all_costumers ){
                            c.display();
                        }
						break;

                    default:
                        if(pos != 0){
                                cout << "invalid input :<";
                            }
				}
                return 0;
			}
            
 
            int display_receipts(vector <costumer> costum){
                for(const auto&c : costum){

                    cout << "\n\nName: \033[96m" <<left << setw(100) << c.details << "\n";
                    cout << "\033[0m09"<< c.mobile_num << "\n";
                    for (const auto& d : c.date) {
                        cout << d.month << "/" << d.day << "/" << d.year << "\n";
                    }
                    cout << "\nTotal: " << c.total ; 
                    cout << " | Change: " << c.change; 
                    cout << " | Money: " << c.cash;  
    
                    cout << "\n------------------------------------------------------------------------------";
                    cout << "\nSTRAPS\n";
                    if(c.store.empty()){
                        cout << "No items selected\n"; 
                    }else{
                            cout << left 
                            << setw(20) << "Color"
                            << setw(15) << "Brand"
                            << setw(15) << "Leather Type"
                            << setw(10) << "Qty"
                            << setw(10) << "Size"
                            << setw(10) << "Price" << "\n";
                        for (const auto& s : c.store) {
                            cout << left << setw(5) 
                            << setw(20) << s.color
                            << setw(15) << s.brand
                            << setw(15) << s.leather_type
                            << setw(10) << s.quantity 
                            << setw(10) << s.size
                            << setw(10) << s.price << "\n";
                        }
                    }
                    cout << "-------------------------------------------------------------------------------";
                    cout << "\nBATTERIES\n";
                    
                    if(c.store_b.empty()){
                        cout << "No items selected"; 
                    }else {
                        cout << left 
                        << setw(15) << "Brand"
                        << setw(10) << "Qty"
                        << setw(10) << "Price" << "\n";
                        for (const auto& b : c.store_b) {
                            cout << setw(15) << b.brand
                            << setw(10) << b.quantity
                            << setw(10) << b.price << "\n";
                        }
                    }
                }

            }

            int insert_days(vector <costumer> arr, vector <costumer> arr2){
                for (const auto& c : arr){
                    for(const auto& d : c.date){
                            uni_days.insert(d.day);
                    }
                } 
                for (const auto& c : arr2){
                    for(const auto& d : c.date){
                            uni_days.insert(d.day);
                    }
                } 
            }

            int getWeek (int day){
                if (day >= 1 && day <= 7) return 1;   
                if (day >= 8 && day <= 14) return 2;  
                if (day >= 15 && day <= 21) return 3; 
                return 4;           
            }

            int POS_sales (  int& sale ,vector <costumer> costum, vector <costumer> costum2, set<int>uni, set<int>unim,   map <pair<int,int>,vector<costumer>> week){
					switch(sale) {
						case 1:
							cout << "\nORDER BY DAY\n";
                            
                            for (int u : uni){
                                cout << "\n\033[91mDATE " << u <<"\033[0m";  
                                for (const auto& c : costum){
                                    for(const auto& d : c.date){
                                        if(d.day == u ){
                                            c.display();
                                        }
                                    }
                                } 
                                for (const auto& c : costum2){
                                    for(const auto& d : c.date){
                                        if(d.day == u ){
                                            c.display();
                                        }
                                    }
                                } 
                            }

							break;

						case 2:
							cout << "\nOrder by Week: \n";
                            for(const auto& c : costum){
                                for(const auto& d : c.date){
                                    int week_num = getWeek( d.day);
                                    week[{d.month, week_num}].push_back(c);
                                }
                            }

                            for(const auto& c : costum2){
                                for(const auto& d : c.date){
                                    int week_num = getWeek( d.day);
                                    week[{d.month, week_num}].push_back(c);
                                }
                            }

                            for (const auto& [key, c_week] : week) {
                                int month_count = key.first; 
                                int week_count = key.second; 
                                cout << "\n\033[91mMonth "<< month_count << "| Week " << week_count << "\033[0m\n";
                                for (const auto& c : c_week) {
                                    c.display();
                                }
                            }
                            cout << "\n\n";
							break;
                       
                        default: 
                            if(sale != 0){
                                cout << "invalid input :<";
                            }
                            
					}
                return 0;
			};


	};


