#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "batteries.h"
#include "strapsCRUD.h"
#include "pos.h"
using namespace std;


int main()
{
	int opt, mat, inv, pos, sale = 0, edit, bat, strp;
	Straps s;
	Batteries b;
	BatteryCRUD crud(b);
	string brandName, newItem, input;
	int newQty, newPrice, id, dec;
	StrapsCRUD sCRUD(s);
	Pos myPOS(s,b);

	cout << "\n\n\033[93m-------------------------------------------------------------";
	cout <<R"(
   .---.                .---.      
  / 12  \              (  o  )
 |9  o  3| Minute Key   `-|-'
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
		
								switch (edit)
								{
									case 1:
										do
										{
											cout << "\nSTRAPS\n";
											cout << "[1] ADD ITEM\n";
											cout << "[2] EDIT ITEM\n";
											cout << "[3] DELETE ITEM\n";
											cout << "[4] DISPLAY ALL ITEMS\n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> strp;

											switch (strp)
											{
												case 1:
												{ // ADD
													string categ, color, brand, leather_type,  size,kid_size,  hole;
													int  quantity;
													double price;

													cout << "\nEnter category (stitched | no stitch | casio | casio w/ cover): ";
													cin.ignore();
													getline(cin, categ);
													cout << "Enter new color: ";
													getline(cin, color);
													cout << "Enter new brand: ";
													getline(cin, brand);
													cout << "Leather type? [1-YES/0-NO]: ";
													getline(cin, leather_type);
														if(leather_type == "1")
														{
															cout << "Enter new leather type: ";
															getline(cin, leather_type);
														}
													cout << "Enter quantity: ";
													cin >> quantity;
													cout << "Enter size: ";
													cin >> size;
													cout << "Enter price: ";
													cin >> price;
													cout << "Enter hole (e.g. 1 | 2): ";
													cin >> hole;

													sCRUD.addItems(id, categ, color, brand, leather_type, quantity, size, price, hole);
													break;
												}

												case 2:
												{ // EDIT
													sCRUD.dispItem();
													int id, newPrice, newQty;
													string newColor, newSize, newName;
									
													cout << "\nEnter ID of strap to edit: ";
													cin >> id;
													cin.ignore();
													cout << "New name: ";
													getline(cin, newName);
													cout << "New Color: ";
													cin >> newColor;
													cout << "New quantity: ";
													cin >> newQty;
													cout << "New size: ";
													cin >> newSize;
													cout << "New price: ";
													cin >> newPrice;
													sCRUD.editItem(id,newName, newColor, newQty,newSize, newPrice);
													break;
												}

												case 3:
												{ 
													sCRUD.dispItem();

													int id, dec;
													cout << "\nEnter ID of strap to delete: ";
													cin >> id;
													cout << "Are you sure? [1-Yes / 0-No]: ";
													cin >> dec;
													sCRUD.deleteItem(id, dec);
													break;
												}

												case 4:
												// DISPLAY
													sCRUD.dispItem();
													break;
												

												case 0:
													break;

												default:
													cout << "Invalid option :<\n";
													break;
											}

										} while (strp != 0);
									break;
		
									case 2:
										do
										{
											cout << "\nBATTERIES\n";
											cout << "[1] EDIT\n";
											cout << "[2] ADD\n";
											cout << "[3] DELETE\n";
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

												case 0:
													break;
												default:
													cout << "Invalid input :<";
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
										cout << "[0] back\n";
										cout << "Choose an option: ";
										cin >> bat;

										b.switch_view(bat,strp);

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

			default:
				if(opt != 0){
					cout << "Invalid option :<";
				}
		}
	} while (opt != 0);

	return 0;

}
