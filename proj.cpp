#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "batteries.h"
#include "straps.h"
#include "pos.h"
using namespace std;

int BatteryCRUD::nextID = 1;

int main()
{
	int opt, mat, inv, pos, sale = 0, edit, search, bat, strp;
	Batteries b;
	string brandName, newItem, input;
	int newQty, newPrice, id, dec;
	BatteryCRUD crud(b);
	Straps s;
	Pos myPOS(s,b);

	cout << "\n\n\033[93m-------------------------------------------------------------";
	cout <<R"(
   .---.                .---.      
  / 12  \              (  o  )
 |9  o  3| Minute Key   `-|-'3
  \_ 6 _/                |=>
   `---'                 |=>    )";
	cout << "\n-------------------------------------------------------------\033[0m ";

	do
	{
		cout << "\n\nPICK FROM THE FOLLOWING: \n";
		cout << "[1] INVENTORY\n";
		cout << "[2] POINT OF SALES (POS)\n";
		cout << "[3] ADD RECEIPT\n";
		cout << "[0] End\n\n";
		cout << "Choose an option: ";
		cin >> opt;

		switch (opt)
		{
			case 1:
				do
				{
					cout << "\nINVENTORY\n";
					cout << "[1] EDIT\n";
					cout << "[2] VIEW\n";
					cout << "[0] back\n\n";
					cout << "Choose an option: ";
					cin >> inv;

						switch (inv)
						{
						case 1:
							do{

								cout << "\nEDIT MATERIALS: \n";
								cout << "[1] STRAPS\n";
								cout << "[2] BATTERIES\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> edit;
		
								switch (edit){
									case 1:
										do
										{
											cout << "\nSTRAPS\n";
											cout << "[1] ADD ITEM\n";
											cout << "[2] EDIT ITEM\n";
											cout << "[3] DELETE ITEM\n";
											cout << "[4] DISPLAY ALL ITEMS\n"; // i think this is not needed(?) since it will fall under view option
											cout << "[5] SEARCH NAME OF STRAP \n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> strp;
		
											s.switch_edit(strp);
										} while (strp != 0);
										break;
		
									case 2:
										do
										{
											cout << "\nBATTERIES\n";
											cout << "[1] EDIT\n";
											cout << "[2] ADD\n";
											cout << "[3] DELETE\n";
											cout << "[4] SEARCH NAME OF BATTERY \n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> bat;
											
											switch (bat)
											{
												case 1:
													crud.displayItems();
		
													cout << "Input Item ID you want to edit: ";
													cin >> id;
													cout << "Input new brand name [Renata/Maxell]: ";
													cin >> brandName;
													cin.ignore(numeric_limits<streamsize>::max(), '\n');
													cout << "Input new item name: ";
													getline(cin, newItem);
													cout << "Input new quantity: ";
													cin >> newQty;
													cout << "Input new price: ";
													cin >> newPrice;
		
													crud.editItems(id, brandName, newItem, newQty, newPrice);
		
													break;
												case 2:
													cout << "\nInput brand name you want to add [Renata/Maxell]: ";
													cin >> brandName;
													cout << "Input new item name: ";
													cin.ignore(numeric_limits<streamsize>::max(), '\n');
													cin >> newItem;
													cout << "Input new quantity: ";
													cin >> newQty;
													cout << "Input new price: ";
													cin >> newPrice;
		
													crud.addItems(brandName, newItem, newQty, newPrice);
		
													break;
												case 3:
													crud.displayItems();
		
													cout << "Input ID you want to delete: ";
													cin >> id;
													cout << "Are you sure you want to delete item? [1-Yes/0-No]: ";
													cin >> dec;
		
													crud.deleteItems(id, dec);
		
													break;
												case 4:
													cout << "SEARCH ITEM: ";
													cin.ignore(numeric_limits<streamsize>::max(), '\n');
													getline(cin, input);
		
													crud.searchItems(input);
													break;
											}
										} while (bat != 0);
										break;
								}
							}while(edit != 0);

							break;

						case 2:
							do{

								cout << "\nVIEW LIST OF MATERIALS: \n";
								cout << "[1] STRAPS\n";
								cout << "[2] BATTERIES\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> mat;

								switch (mat)
								{
								case 1:
									do
									{
										cout << "\nSTRAPS\n";
										cout << "[1] WITH STITCH STRAP\n";
										cout << "[2] NO STITCH STRAP\n";
										cout << "[3] CASIO STRAP\n";
										cout << "[4] DISPLAY ALL STRAPS\n";
										cout << "[5] SEARCH NAME OF STRAP \n";
										cout << "[0] back\n";
										cout << "Choose an option: ";
										cin >> strp;

										s.switch_view(strp);

									} while (strp != 0);
									break;

								case 2:
									do
									{
										cout << "\nBATTERIES\n";
										cout << "[1] MAXELL\n";
										cout << "[2] RENATA\n";
										cout << "[3] DISPLAY ALL BATTERIES\n";
										cout << "[4] SEARCH NAME OF BATTERY \n";
										cout << "[0] back\n";
										cout << "Choose an option: ";
										cin >> bat;

										b.switch_view(bat);

									} while (bat != 0);
									break;
								}
							}while(mat != 0); 
							break;
						}

				} while (inv != 0 );

				break;

			case 2:
				do
				{
					cout << "\nPOINT OF SALES (POS)\n";
					cout << "[1] OVERVIEW OF SALES\n";
					cout << "[2] SEARCH DATE OF SALES\n";
					cout << "[3] HISTORY OF RECEIPTS\n";
					cout << "[0] back\n\n";
					cout << "Choose an option: ";
					cin >> pos;

					myPOS.POS_switch(pos, sale);
				} while (pos != 0 && sale != 0);
				break;

			case 3:
				myPOS.input();
				break;
		}
	} while (opt != 0);

	return 0;
}