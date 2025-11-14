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
  struct dates
  {
    int year;
    int month;
    int day;
  };

  struct costumer
  {
    int id; 
    string details;
    string mobile_num;
    double cash;
    double change;
    double total;
    double tax; 
    vector<dates> date;
    vector<Straps ::StrapItems> store;
    vector<Batteries ::BattItems> store_b;
    costumer() : id(), details(""), mobile_num(""), cash(0), change(0), total(0),tax(0) {}
    costumer(string d, string m) : id(0), details(d), mobile_num(m), cash(0), change(0), total(0), tax(0) {}
    costumer(
        int id, 
        string n,
        string mobile,
        int c,
        int chng,
        int t,
        int tx,
        vector<dates> d,
        vector<Straps ::StrapItems> s,
        vector<Batteries ::BattItems> sb)
        : id(id), details(n), mobile_num(mobile), cash(c), change(chng), total(t),tax(tx), date(d), store(s), store_b(sb) {}
  };

private:
  Straps &s;
  Batteries &b;
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
  map<pair<int, int>, vector<costumer>> week;
  set<int> uni_days;
  vector<costumer> costumers;
  vector<costumer> all_costumers;
  vector<pair<int, int>> a_id;
  vector<pair<int, int>> a_id_bat;
  vector<Straps ::StrapItems> &allstraps_arr;
  vector<Batteries ::BattItems> &allbatt_arr;
  costumer c;

public:
    Pos(Straps &straps, Batteries &bats) : s(straps), b(bats), allstraps_arr(straps.allstraps_arr), allbatt_arr(bats.allbatt_arr) {}
  
    set<string> num_valid = {
      "900","901","902","903","904","905",
      "906","907","908","909",
      "817",
      "910","911","912","913","914","915","916","917","918","919",
      "920","921","928","926","929",
      "930","938","939",
      "946","947","948","949",
      "950","951","952","953",
      "961","962","963",
      "970","975","977","978","979",
      "981","989",
      "991","992","993","994","995","996","997","998","999"
    };

    //dummy data 
    //specified constructor calling instead of aggregate 
    vector<costumer> costumer_list = {
      costumer (
          1,"Clare Lubiano", "0962 585 8585", 10000, 7300, 2700, 3024, 
          vector<dates> {{2025, 11, 01}}, 
          vector<Straps ::StrapItems>{
            {3, "stitched", "black w/ white", "No type", "Buffalo Calf", 1, 4, "16-19", 850, ""},
            {4, "stitched", "brown light", "No type", "Buffalo Calf", 1, 4, "16-19", 850, ""}
            },
          vector<Batteries ::BattItems>{
             {3, "renata", "Renata 600", 1, 8, 500},
             {4, "renata", "Renata 700", 1, 8, 500}
          }
      ),

    costumer(
          2,"Sylvia Heart Sulla", "0962 656 8910", 10000, 6650, 3350, 3752, 
          vector<dates> {{2025, 11, 01}}, 
          vector<Straps ::StrapItems>{
          {23, "no stitch", "Black", "Alpha", "No type", 10, 7, "16-24", 1500, ""},
          {4, "stitched", "brown light", "No type", "Buffalo Calf", 1, 4, "16-19", 850, ""}
            },
          vector<Batteries ::BattItems>{
             {3, "renata", "Renata 600", 1, 8, 500},
             {4, "renata", "Renata 700", 1, 8, 500}
          }
      ),

      costumer(
         3, "Chybs Shantee Naje", "0962 114 5862", 10000, 8650, 1350, 1512 , 
          vector<dates> {{2025, 10, 29}}, 
          vector<Straps ::StrapItems>{
            {3, "stitched", "black w/ white", "No type", "Buffalo Calf", 1, 4, "16-19", 850, ""}
            },
          vector<Batteries ::BattItems>{
             {3, "renata", "Renata 600", 1, 8, 500}
          }
      ),
      
      costumer(
         4,"Vinea Lei", "0962 645 7012", 10000, 7300, 2700, 3024 ,
          vector<dates> {{2025, 10, 27}}, 
          vector<Straps ::StrapItems>{
            {3, "stitched", "black w/ white", "No type", "Buffalo Calf", 1, 4, "16-19", 850, ""},
            {4, "stitched", "brown light", "No type", "Buffalo Calf", 1, 4, "16-19", 850, ""}
            },
          vector<Batteries ::BattItems>{
             {3, "renata", "Renata 600", 2, 8, 500}
          }
      )
  };
    
     //main input for recipts
    void input()
    {
        id_maker();
        cout << "\033[96mDOUBLE CHECK YOU CANNOT EDIT!!";
        cout << "\n\033[0mCostumers name: ";
        cin.ignore();
        getline(cin, c.details);
        costumers.push_back(c);

    do
    {
      cout << "\nEnter mobile number: +63";
      getline(cin, c.mobile_num);
      costumers.push_back(c);
    } while (mobile_checker() == 1);

    add_date();

    do
    {
      cout << "\n\nPick Items\n[1] Straps\n[2] Battery\n[0] done";
      cout << "\nPick: ";
      cin >> pick;

      POS_pick(pick);

      // checks if the costumer added any item
      if (store_checker(a_id, a_id_bat) == 1)
      {
        pick = 1;
      }

    } while (pick != 0);

    do
    {
      cout << "\nSubtotal: " << total_price();
      cout << "\nTotal: " << c.tax;
      cout << "\n___________________________";
      cout << "\nInput Costumers Money: ";
      cin >> c.cash;
      if (c.cash < c.tax)
      {
        cout << "\nInsufficient Cash :<";
      }
      costumers.push_back(c);
    } while (c.cash < c.tax);

    show_current();
    change();
    a_id.clear(); 
    a_id_bat.clear();
    all_costumers.push_back(c);
    // clears all costumer so no repeating data
    c.store.clear();
    c.store_b.clear();
  }

  int id_maker(){
    int new_id = 1; 

    if(!all_costumers.empty()){
      new_id = all_costumers.back().id + 1;
    }else if (!costumer_list.empty()){
      new_id = costumer_list.back().id + 1;
    }

    c.id = new_id; 
    costumers.push_back(c); 
    return new_id; 
  }

  // format to display vectors feeded in the function
  // template can take any data type
  template <typename T>
  void display(T &ac)
  {
    cout << "\n\nName: \033[96m" << left << setw(100) << ac.details << "\n";
    cout << "\033[0m09" << ac.mobile_num << "\n";

    for (const auto &d : ac.date)
    {
      cout << d.month << "/" << d.day << "/" << d.year << "\n";
    }
    cout << "\nSubtotal: " << ac.total;
    cout << " | Change: " << ac.change;
    cout << " | Money: " << ac.cash;
    cout << " | Total: " << ac.cash;

    cout << "\n------------------------------------------------------------------------------";
    cout << "\nSTRAPS\n";
    if (ac.store.empty())
    {
      cout << "No items selected\n";
    }
    else
    {
      cout << left
           << setw(20) << "Color"
           << setw(15) << "Brand"
           << setw(15) << "Leather Type"
           << setw(10) << "Qty"
           << setw(10) << "Size"
           << setw(10) << "Price" << "\n";
      for (const auto &s : ac.store)
      {
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

        if (ac.store_b.empty())
        {
            cout << "No items selected";
        }
        else
        {
            cout << left
                 << setw(15) << "Brand"
                 << setw(15) << "Qty"
                 << setw(10) << "Price" << "\n";
            for (const auto &b : ac.store_b)
            {
                cout << setw(15) << b.brand
                     << setw(15) << b.quantity
                     << setw(10) << b.price << "\n";
            }
        }
    }

  // return data to help check if items already existed
  int store_checker(vector<pair<int, int>> &a_id, vector<pair<int, int>> &a_id_bat)
  {
    if (a_id.empty() && a_id_bat.empty())
    {
      cout << "Input atleast one item :<";
      return 1;
    }
    return 0;
  }

  // totals overall price for both stores
  double total_price()
  {
    double total_s = 0;
    for (const auto &s : c.store)
    {
      total_s += s.price * s.quantity;
    }
    double total_b = 0;
    for (const auto &b : c.store_b)
    {
      total_b += b.price * b.quantity;
    }

    c.total = total_b + total_s;
    c.tax = c.total*1.12; 
    costumers.push_back(c);
    return costumers.back().total;
  }

  // gives change
  int change()
  {
    c.change = c.cash - c.tax;
    costumers.push_back(c);

    cout << "\nTotal amount: " << total_price();
    cout << "\nChange: " << costumers.back().change;
    return 0;
  }

  // shows current added for receipts
  void show_current()
  {
    cout << "\n\nName: " << c.details << "\n";
    cout << "09" << c.mobile_num << "\n";
    for (const auto &d : c.date)
    {
      cout << d.month << "/" << d.day << "/" << d.year << "\n";
    }

    cout << "------------------------------------------------------------------------------";
    cout << "\nSTRAPS\n";
    if (c.store.empty())
    {
      cout << "No items selected\n";
    }
    else
    {
      cout << left
           << setw(20) << "Color"
           << setw(15) << "Brand"
           << setw(20) << "Leather Type"
           << setw(10) << "Qty"
           << setw(10) << "Size"
           << setw(10) << "Price" << "\n";
      for (const auto &s : c.store)
      {
        cout << left << setw(5)
             << setw(20) << s.color
             << setw(15) << s.brand
             << setw(20) << s.leather_type
             << setw(10) << s.quantity
             << setw(10) << s.size
             << setw(10) << s.price << "\n";
      }
    }
    cout << "-------------------------------------------------------------------------------";
    cout << "\nBATTERIES\n";

    if (c.store_b.empty())
    {
      cout << "No items selected\n";
    }
    else
    {
      cout << left
           << setw(15) << "Brand"
           << setw(15) << "Qty"
           << setw(10) << "Price" << "\n";
      for (const auto &b : c.store_b)
      {
        cout << setw(15) << b.brand
             << setw(15) << b.quantity
             << setw(10) << b.price << "\n";
      }
    }
    cout << "------------------------------------------------------------------------------";
    cout << "\nMoney: " << c.cash;
    cout << "\nTotal: " << c.tax;
    return;
  }

  // adds date
  int add_date()
  {
      // get the current date
      time_t now = time(nullptr);

      // passes it to a variable to be converted into a readable format
      tm *localTime = localtime(&now);

      // Store each date component in separate variables
      current.year = 1900 + localTime->tm_year;
      current.month = 1 + localTime->tm_mon;
      current.day = localTime->tm_mday;

      // makes sure we dont reuse past data
      c.date.clear();
      c.date.push_back(current);\
      
    return 0;
  }

  // handles users input
  int pick_id()
  {
    cout << "\n[0] done\npick by id: ";
    cin >> access;
    return 0;
  }

  // switch for straps
  // shows all options for straps
  int POS_straps(int straps)
  {
    switch (straps)
    {
    case 1:
      do
      {
        s.DisplayStitched(allstraps_arr, "WITH STITCH STRAPS");
        pick_id();
        // stops when user is done with picking items
        if (access == 0)
          break;

        do
        { // makes sure user atleast get 1 quantity
          cout << "Quantity: ";
          cin >> qty;
          if (qty == 0)
          {
            cout << "invalid :<\n";
          }
        } while (qty == 0);

        access_id(access, qty);
      } while (access != 0);
      break;

    case 2:
      do
      {
        s.DisplayNoStitched(allstraps_arr, "NO STITCH STRAPS");
        pick_id();
        // stops when user is done with picking items
        if (access == 0)
          break;

        do
        { // makes sure user atleast get 1 quantity
          cout << "Quantity: ";
          cin >> qty;
          if (qty == 0)
          {
            cout << "invalid :<\n";
          }
        } while (qty == 0);
        access_id(access, qty);
      } while (access != 0);

      break;

    case 3:
      do
      {
        s.DisplayCasioKids(allstraps_arr, "CASIO STRAPS KIDS SIZE W/ COVER");
        pick_id();
        // stops when user is done with picking items
        if (access == 0)
          break;

        do
        { // makes sure user atleast get 1 quantity
          cout << "Quantity: ";
          cin >> qty;
          if (qty == 0)
          {
            cout << "invalid :<\n";
          }
        } while (qty == 0);
        access_id(access, qty);
      } while (access != 0);
      break;
    case 4:
      do
      {
        s.DisplayCasioAdult(allstraps_arr, "CASIO STRAPS ADULT SIZE");
        pick_id();
        // stops when user is done with picking items
        if (access == 0)
          break;

        do
        { // makes sure user atleast get 1 quantity
          cout << "Quantity: ";
          cin >> qty;
          if (qty == 0)
          {
            cout << "invalid :<\n";
          }
        } while (qty == 0);
        access_id(access, qty);

      } while (access != 0);

      break;

    default:
      if (straps != 0)
      {
        cout << "invalid input :<";
      }
    }

    return 0;
  }

  // stores all the users picked item
  void access_id(int access, int &qty)
  {
    // stores the id and quantity
    a_id.emplace_back(access, qty);
    // marker to keep track of existing items
    bool found = false;

    // loops through all items
    for (auto &item : s.allstraps_arr)
    {
      // checks is input id is same as item id
      if (access == item.id)
      {

        // stores the picked item
        c.store.emplace_back(s.allstraps_arr[access - 1]);
        found = true; // item exist

        int last_id = a_id.back().first;

        // deletes 0
        // 0 is used to exit switch, it shouldn't be stored
        if (last_id == 0)
        {
          a_id.erase(
              // moves all numbers that needed to be deleted at the end
              remove_if(a_id.begin(), a_id.end(),
                        [](pair<int, int> &p)
                        {
                          // condition to satisfy which number goes in the end
                          return p.first == 0;
                        }),
              a_id.end());
          // deletes the items at the end of the vector
        }

        int current_qty = item.quantity;

        // checks if theres is enough quantity in stock
        while (qty > current_qty)
        {
          cout << "Not enough items :<\nInput quantity: ";
          cin >> qty;
        }

        // updates items quantity
        c.store.back().quantity = qty;
        item.quantity -= qty;

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
             << setw(20) << s.allstraps_arr[last_id - 1].color
             << setw(15) << s.allstraps_arr[last_id - 1].brand
             << setw(15) << s.allstraps_arr[last_id - 1].leather_type
             << setw(10) << c.store.back().quantity
             << setw(10) << s.allstraps_arr[last_id - 1].size
             << setw(10) << s.allstraps_arr[last_id - 1].price << "\n";
      }
    }

    if (!found)
    {
      cout << "Id not found :<\n";
    }

    return;
  }

  // switch for straps
  // shows all options for straps
  int POS_bats(int bats)
  {
    switch (bats)
    {
    case 1:
      do
      {
        b.DisplayMaxell(allbatt_arr, "MAXWELL BATTERY");
        // stops when user is done with picking items
        pick_id();
        if (access == 0)
          break;

        do
        { // makes sure user atleast get 1 quantity
          cout << "Quantity: ";
          cin >> qty;
          if (qty == 0)
          {
            cout << "invalid :<\n";
          }
        } while (qty == 0);
        access_id2(access, qty);
      } while (access != 0);
      break;

    case 2:
      do
      {
        b.DisplayRenata(allbatt_arr, "RENATA BATTERY");
        pick_id();
        // stops when user is done with picking items
        if (access == 0)
          break;

        do
        { // makes sure user atleast get 1 quantity
          cout << "Quantity: ";
          cin >> qty;
          if (qty == 0)
          {
            cout << "invalid :<\n";
          }
        } while (qty == 0);
        access_id2(access, qty);
      } while (access != 0);
      break;

    default:
      if (bats != 0)
      {
        cout << "invalid input :<";
      }
    }
    return 0;
  }

  // stores all the users picked item
  void access_id2(int access, int &qty)
  {
    a_id_bat.emplace_back(access, qty);
    bool found = false;

    for (auto &item : b.allbatt_arr)
    {
      if (access == item.id)
      {
        c.store_b.emplace_back(item);
        found = true;
        int last_id = a_id_bat.back().first;

        if (last_id == 0)
        {
          a_id_bat.erase(
              remove_if(a_id.begin(), a_id.end(),
                        [](pair<int, int> &p)
                        {
                          return p.first == 0;
                        }),
              a_id.end());
        }

        int current_qty = item.quantity;

        while (qty > current_qty)
        {
          cout << "Not enough items :<\nInput quantity: ";
          cin >> qty;
        }

        c.store_b.back().quantity = qty;
        item.quantity -= qty;

                cout << right << setw(5) << " ";
                cout << left << setw(5) << "ID"
                     << setw(15) << "Brand"
                     << setw(15) << "Qty"
                     << setw(10) << "Price" << "\n";

                cout << right << setw(5) << " ";
                cout << left << setw(5) << c.store_b.back().id
                     << setw(15) << item.brand
                     << setw(15) << c.store_b.back().quantity
                     << setw(10) << item.price << "\n";
                break;
            }
        }

    if (!found)
    {
      cout << "Id not found :<\n";
    }

    return;
  }

  // checks if mobile number is valid
  int mobile_checker()
  {
    string num = c.mobile_num;
    string extract = num.substr(0,3); 
    int found = (num_valid.find(extract) != num_valid.end()) ?  1 : 0;

    if (counter(c.mobile_num) != 10 && counter(c.mobile_num) != 12 || found == 0)
    {
      cout << "invalid number :<";
      return 1;
    }
    return 0;
  }

  // counts number of characters
  int counter(string mobile_num)
  {
    int count = 0;
    for (size_t c = 0; c < mobile_num.length(); c++)
    {
      count++;
    }
    return count;
  }

  // switch for to pick what item to choose
  //(batteries or straps)
  void POS_pick(int pick)
  {
    switch (pick)
    {
    case 1:
      do
      {
        cout << "\n\nSTRAPS";
        cout << "\n[1] WITH STITCH STRAPS\n[2] NO STITCH STRAPS\n[3] CASIO STRAPS KIDS SIZE W/ COVER\n[4] CASIO STRAPS ADULT SIZE\n[0] back\n";
        cout << "items: ";
        cin >> straps;
        POS_straps(straps);
      } while (straps != 0);
      break;

    case 2:
      do
      {
        cout << "\n\nBATTERIES";
        cout << "\n[1] MAXELL BATTERY\n[2] RENATA BATTERY\n[0] back\n";
        cout << "items: ";
        cin >> bats;
        POS_bats(bats);
      } while (bats != 0);
      break;

    default:
      if (pick != 0)
      {
        cout << "invalid input :<";
      }
    }
  }

  // switch to check point os sale
  int POS_switch(int pos, int sale)
  {
    switch (pos)
    {
    case 1:
      do
      {
        cout << "\n\nOVERVIEW OF SALES";
        cout << "\nView by\n"
             << "[1] Day\n[2] Week\n[0] back\n"
             << "Enter Option: ";
        insert_days(costumer_list, all_costumers);
        cin >> sale;

        POS_sales(sale, costumer_list, all_costumers, uni_days, week);
      } while (sale != 0);

      break;

        case 2:{
            pos = 0;
            cout << "\nSEARCH DATE OF SALES";
            cout << "\nSearch Day: ";
            cin >> srch_d;
            cout << "\nSearch Month: ";
            cin >> srch_m;
            bool found = false; 

            for (const auto &c : costumer_list)
            {
                for (auto &d : c.date)
                {   //filters the day and month 
                    if (d.day == srch_d && d.month == srch_m)
                    {
                        display(c);
                        found = true; 
                    }       
                    
                }
            }

            for (const auto &c : all_costumers)
            {
                for (auto &d : c.date)
                {   //filters the day and month 
                    if (d.day == srch_d || d.month == srch_m)
                    {
                        display(c);
                        found = true; 
                    }
                }
            }
                
            if(!found){
                  cout << "\nNo data found :< \n"; 
            }


            break;
        }

    case 3:
      pos = 0;
      cout << "\nHISTORY OF RECEIPTS";
      display_receipts(costumer_list);
      display_receipts(all_costumers);
      break;

    default:
      if (pos != 0)
      {
        cout << "invalid input :<";
      }
    }
    return 0;
  }

  // function to display costumers
  // for vectors that is not contained in a loop
  int display_receipts(vector<costumer> costum)
  {
    for (const auto &c : costum)
    {
      cout << "\n\nName: \033[96m" << left << setw(100) << c.details << "\n";
      cout << "\033[0m09" << c.mobile_num << "\n";
      for (const auto &d : c.date)
      {
        cout << d.month << "/" << d.day << "/" << d.year << "\n";
      }
      cout << "\nSubtotal: " << c.total;
      cout << " | Change: " << c.change;
      cout << " | Money: " << c.cash;
      cout << " | Total: " << c.tax;

      cout << "\n------------------------------------------------------------------------------";
      cout << "\nSTRAPS\n";
      if (c.store.empty())
      {
        cout << "No items selected\n";
      }
      else
      {
        cout << left
             << setw(20) << "Color"
             << setw(15) << "Brand"
             << setw(15) << "Leather Type"
             << setw(10) << "Qty"
             << setw(10) << "Size"
             << setw(10) << "Price" << "\n";
        for (const auto &s : c.store)
        {
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

      if (c.store_b.empty())
      {
        cout << "No items selected";
      }
      else
      {
        cout << left
             << setw(15) << "Brand"
             << setw(10) << "Qty"
             << setw(10) << "Price" << "\n";
        for (const auto &b : c.store_b)
        {
          cout << setw(15) << b.brand
               << setw(10) << b.quantity
               << setw(10) << b.price << "\n";
        }
      }
    }
    return 0;
  }

  // adds day to be sorted in the set vector
  int insert_days(vector<costumer> arr, vector<costumer> arr2)
  {
    for (const auto &c : arr)
    {
      for (const auto &d : c.date)
      {
        uni_days.insert(d.day);
      }
    }
    for (const auto &c : arr2)
    {
      for (const auto &d : c.date)
      {
        uni_days.insert(d.day);
      }
    }
    return 0;
  }

  // to determine the number of week in a month
  int getWeek(int day)
  {
    if (day >= 1 && day <= 7)
      return 1;
    if (day >= 8 && day <= 14)
      return 2;
    if (day >= 15 && day <= 21)
      return 3;
    return 4;
  }

  int POS_sales(int &sale, vector<costumer> &costum, vector<costumer> &costum2, set<int> &uni, map<pair<int, int>, vector<costumer>> &week)
  {

    switch (sale)
    {
        case 1:
          //  stores month and week number
          for (const auto &c : costum)
          {
            for (const auto &d : c.date)
            {
              int week_num = getWeek(d.day);
              week[{d.month, week_num}].push_back(c);
            }
          }

          for (const auto &c : costum2)
          {
            for (const auto &d : c.date)
            {
              int week_num = getWeek(d.day);
              week[{d.month, week_num}].push_back(c);
            }
          }
          cout << "\nORDER BY DAY\n";

          // Iterates through all weeks and displays customer data per month/day
          for (const auto &[key, c_week] : week)
          {
            int month_count = key.first;
            cout << "\n\033[91mMONTH : " << month_count;

            for (int u : uni)
            { // marks the date is not listed yet
              bool mark_costumer = false;

              for (const auto &c : costum)
              {
                for (const auto &d : c.date)
                { // checks if the date matches the categorizer for day
                  // checks if the month matches the categorizer for month
                  if (d.day == u && d.month == month_count)
                  { // makes sure we only print the header once per day
                    if (!mark_costumer)
                    {
                      cout << "\n\033[91mDATE " << u << "\033[0m";
                      // marks the data as listed
                      mark_costumer = true;
                    }
                    display(c);
                  }
                }
              }

              for (const auto &c : costum2)
              {

                for (const auto &d : c.date)
                {
                  if (d.day == u && d.month == month_count)
                  {
                    if (!mark_costumer)
                    {
                      cout << "\n\033[91mDATE " << u << "\033[0m";
                      mark_costumer = true;
                    }
                    display(c);
                  }
                }
              }
            }
          }
          break;

        case 2: {
          // stores month and week number
          for (const auto &c : costum)
          {
            for (const auto &d : c.date)
            {
              int week_num = getWeek(d.day);
              week[{d.month, week_num}].push_back(c);
            }
          }

          for (const auto &c : costum2)
          {
            for (const auto &d : c.date)
            {
              int week_num = getWeek(d.day);
              week[{d.month, week_num}].push_back(c);
            }
          }
          
          cout << "\nOrder by Week: \n";

          // iterates thorygh all week number and month
          for (const auto &[key, c_week] : week){
            int month_count = key.first;
            int week_count = key.second;
            cout << "\n\033[91mMonth " << month_count << "| Week " << week_count << "\033[0m\n";

            set<int> shown;
            // stores date of the costumers that already existed
            // prevents duplicates

            for (const auto &c : c_week){
              if(shown.find(c.id) == shown.end()){
                //not found 
                display(c);
                shown.insert(c.id);
              }
                
            }

            cout << "\n\n";
          }
        
          break;
        }

        default:
          if (sale != 0){
            cout << "invalid input :<";
          }
          break;
       
        // return 0;
    };
  };
};