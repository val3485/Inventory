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
	string searchTerm;
	Straps s;
	Batteries b;
	BatteryCRUD crud(b);
	string brandName, newItem, input;
	int newQty,  id, dec;
	float newPrice;
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
		while(true)
		{
			cout << "\n\nPICK FROM THE FOLLOWING: \n";
			cout << "[1] INVENTORY\n";
			cout << "[2] POINT OF SALES (POS)\n";
			cout << "[3] ADD RECEIPT\n";
			cout << "[0] End\n\n";
			cout << "Choose an option: ";
			cin >> opt;

			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number.\n";
			}
			else if(opt >= 0 && opt <= 3)
			{
				switch (opt)
				{
					case 1:
						do
						{
							while(true)
							{
								cout << "\nINVENTORY\n";
								cout << "[1] EDIT\n";
								cout << "[2] VIEW\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> inv;

								if(cin.fail())
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input. Please enter a number.\n";
								}
								else if(inv >= 0 && inv <= 2)
								{

									switch (inv)
									{
										case 1:
											do
											{
												while(true)
												{
													cout << "\nEDIT MATERIALS: \n";
													cout << "[1] STRAPS\n";
													cout << "[2] BATTERIES\n";
													cout << "[0] back\n\n";
													cout << "Choose an option: ";
													cin >> edit;

													if(cin.fail())
													{
														cin.clear();
														cin.ignore(numeric_limits<streamsize>::max(), '\n');
														cout << "Invalid input. Please enter a number.\n";
													}
													else if(edit >= 0 && edit <= 2)
													{
							
														switch (edit)
														{
															case 1:
																do
																{	
																	while(true)
																	{
																		cout << "\nSTRAPS\n";
																		cout << "[1] ADD ITEM\n";
																		cout << "[2] EDIT ITEM\n";
																		cout << "[3] DELETE ITEM\n";
																		cout << "[4] DISPLAY ALL ITEMS\n";
<<<<<<< HEAD
=======
																		cout << "[5] SEARCH\n";
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
																		cout << "[0] back\n";
																		cout << "Choose an option: ";
																		cin >> strp;
																		if(cin.fail())
																		{
																			cin.clear();
																			cin.ignore(numeric_limits<streamsize>::max(), '\n');
																			cout << "Invalid input. Please enter a number.\n";
																		}
<<<<<<< HEAD
																		else if(strp >= 0 && strp <= 4)
=======
																		else if(strp >= 0 && strp <= 5) // ✅ FIXED HERE
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
																		{
																			switch (strp)
																			{
																				case 1:
																				{ // ADD
																					string categ, color, brand, leather_type,  size,kid_size,  hole;
																					int  quantity;
																					float price;

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
																					int id, newQty;
																					float newPrice;
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
																				{ // DISPLAY
																					sCRUD.dispItem();
																					break;
																				}

<<<<<<< HEAD
																				case 0:
																					break;

=======
																				case 5:
																				{
																					cin.ignore(numeric_limits<streamsize>::max(), '\n');
																					string searchTerm;
																					cout << "\nEnter strap brand name to search(No type, Alpha, Casio): ";
																					getline(cin, searchTerm);

																					sCRUD.searchItems(searchTerm);
																					break;
																				}

																				case 0:
																					break;

>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
																				default:
																					cout << "Invalid option :<\n";
																					break;
																			}
																		}
																		else
																		{
																			cout << "Invalid input :<";
																		}

																		if(strp == 0)
																			break;
																	}
											
																} while (strp != 0);
																break;

															case 2:
																do
																{
																	while(true)
																	{
																		cout << "\nBATTERIES\n";
																		cout << "[1] EDIT\n";
																		cout << "[2] ADD\n";
																		cout << "[3] DELETE\n";
																		cout << "[4] SEARCH\n";
																		cout << "[0] back\n";
																		cout << "Choose an option: ";
																		cin >> bat;

																		if(cin.fail())
																		{
																			cin.clear();
																			cin.ignore(numeric_limits<streamsize>::max(), '\n');
																			cout << "Invalid input. Please enter a number.\n";
																		}
																		else if(bat >= 0 && bat <= 4)
																		{
																			switch (bat)
																			{
																				case 1:
																					crud.displayItems();
							
																					cout << "Input Item ID you want to edit: ";
																					cin >> id;
																					cin.ignore(numeric_limits<streamsize>::max(), '\n');
																					cout << "Input new item name: ";
																					getline(cin, newItem);
																					cout << "Input new quantity: ";
																					cin >> newQty;
																					cout << "Input new price: ";
																					cin >> newPrice;
<<<<<<< HEAD
										
																					crud.editItems(id, newItem, newQty, newPrice);
																				
										
																				break;
=======
										 
																					crud.editItems(id, newItem, newQty, newPrice);
																					break;
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
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
<<<<<<< HEAD
										
																					crud.addItems(brandName, newItem, newQty, newPrice);
										
																				break;
																				case 3:
																					crud.displayItems();
										
=======
										 
																					crud.addItems(brandName, newItem, newQty, newPrice);
																					break;
																				case 3:
																					crud.displayItems();
										 
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
																					cout << "Input ID you want to delete: ";
																					cin >> id;
																					cout << "Are you sure you want to delete item? [1-Yes/0-No]: ";
																					cin >> dec;
<<<<<<< HEAD
											
																					crud.deleteItems(id, dec);

																				break;
																				case 4:
																					
																					cout << "Enter brand name to search: ";
																					cin.ignore(numeric_limits<streamsize>::max(), '\n');
																					getline(cin, searchTerm);
										
																					crud.searchItems(searchTerm);
										
																				break;
=======
											 
																					crud.deleteItems(id, dec);
																					break;
																				case 4:
																					cout << "Enter brand name to search: ";
																					cin.ignore(numeric_limits<streamsize>::max(), '\n');
																					getline(cin, searchTerm);
										 
																					crud.searchItems(searchTerm);
																					break;
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3

																				case 0:
																				break;
																				default:
																					cout << "Invalid input :<";
																					break;
																			}
																		}
																		else
																		{
																			cout << "Invalid input :<";
																		}
																		if (bat == 0)
																			break;
																	}
																}while (bat != 0);
																break;
														}
													}
													else
													{
														cout << "Invalid input :<";
													}

													if(edit == 0)
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
<<<<<<< HEAD
														cout << "[5] CHECK INVENTORY LEVELS\n";
=======
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
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
<<<<<<< HEAD
														cout << "[4] CHECK INVENTORY LEVELS\n";
=======
>>>>>>> ffebe97aa7275e987eef451527f93541a62542d3
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
								}
								else
								{
									cout << "Invalid input :<";
								}

								if (inv == 0)
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
						break;
				}
			}
			else
			{
				cout << "Invalid input :<";
			}

			if (opt == 0)
			{
				break;
			}
		}
	} while (opt != 0);

	return 0;

}
