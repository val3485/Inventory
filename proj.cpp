 #include <iostream>
 #include <iomanip>
 #include <vector>
 #include <string>
 #include "batteries.h"
 #include "straps.h"
 #include "pos.h"
 using namespace std;

int main(){ 
	int opt, mat, inv, pos, sale,edit, search,bat,strp;
	Batteries battery;
	Straps s; 
	Pos myPOS; 
    
	do{
    	cout << "\n\nPICK FROM THE FOLLOWING: \n";
    	cout << "[1] INVENTORY\n";
    	cout << "[2] POINT OF SALES (POS)\n";
    	cout << "[0] End\n\n";
    	cout << "Choose an option: ";
    	cin >> opt;
   	 
    
        	switch (opt){
            	case 1: 
					cout << "\nINVENTORY\n";
					cout << "[1] EDIT\n";
					cout << "[2] VIEW\n";
					cout << "[0] back\n\n";
					cout << "Choose an option: ";
					cin >> inv;
					
					do{
						switch (inv){
							case 1:
								cout << "\nEDIT MATERIALS: \n";
								cout << "[1] STRAPS\n";
								cout << "[2] BATTERIES\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> edit;
							
								switch (edit){
									case 1: 
                                    do{
										cout << "\nSTRAPS\n";
                                        cout << "[1] EDIT\n";
                                        cout << "[2] ADD\n";
                                        cout << "[3] DELETE\n";                                    
                                        cout << "[4] SEARCH NAME OF STRAP \n";
                                        cout << "[0] back\n";
                                        cout << "Choose an option: ";
                                        cin >> strp;

                                        switch(strp){
                                            case 1:
                                            	break;
                                            case 2:
                                            	break;
                                            case 3:
                                            	break;
                                            case 4:
                                            	break;
                                        }
                                    }while(strp !=0);
										break;

									case 2: 
                                    do{
										cout << "\nBATTERIES\n";
                                        cout << "[1] EDIT\n";
                                        cout << "[2] ADD\n";
                                        cout << "[3] DELETE\n";                                    
                                        cout << "[4] SEARCH NAME OF BATTERY \n";
                                        cout << "[0] back\n";
                                        cout << "Choose an option: ";
                                        cin >> bat;

                                        switch(bat){
                                            case 1:
                                            	break;
                                            case 2:
                                            	break;
                                            case 3:
                                            	break;
                                            case 4:
                                            	break;
                                        }
                                    }while(bat != 0);   
                                        break;
								}
								break;

							case 2:
								cout << "\nVIEW LIST OF MATERIALS: \n";
								cout << "[1] STRAPS\n";
								cout << "[2] BATTERIES\n";
								cout << "[0] back\n\n";
								cout << "Choose an option: ";
								cin >> mat;
								                                                 
								switch (mat){
									case 1: 
										do{
											cout << "\nSTRAPS\n";
											cout << "[1] WITH STITCH STRAP\n";
											cout << "[2] NO STITCH STRAP\n";
											cout << "[3] SEARCH NAME OF STRAP \n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> strp;

											
											switch(strp){
												case 1:
													s.DisplayCategory(s.withstitch_arr, "WITH STITCH STRAPS");
													break;
												case 2:
													s.DisplayCategory(s.nostitch_arr, "NO STITCH STRAPS");           
													break;                      
												}										 
											
										}while(strp != 0);
										break;
									 
									case 2: 
										do{
											cout << "\nBATTERIES\n";
											cout << "[1] MAXWELL\n";
											cout << "[2] RENATA\n";
											cout << "[3] SEARCH NAME OF BATTERY \n";
											cout << "[0] back\n";
											cout << "Choose an option: ";
											cin >> bat;
											// battery.switch_bat(bat); 

										}while(bat != 0);
									    break;
                                }
								break;
								do {
									cout << "\nVIEW LIST OF MATERIALS: \n";
									cout << "[1] STRAPS\n";
									cout << "[2] BATTERIES\n";
									cout << "[0] back\n\n";
									cout << "Choose an option: ";
									cin >> mat;
								
									switch (mat){
										case 1: 
											cout << " STRAPS\n";
											break;
										case 2: 
											cout << "BATTERIES\n";
											break;
									}
								}while (mat != 0);
							break;
						}

					}while(inv != 0 && mat != 0 && edit != 0);

            	break;
           	 
            	case 2:
					do{
						cout << "\nPOINT OF SALES (POS)\n";
						cout << "[1] OVERVIEW OF SALES\n";
						cout << "[2] SEARCH DATE OF SALES\n";
						cout << "[3] HISTORY OF RECEIPTS\n";
						cout << "[0] back\n\n";
						cout << "Choose an option: ";
						cin >> pos;
						
						myPOS.POS_switch(pos, sale,search);
					}while(pos != 0 && sale != 0);
					break; 
				case 3: 
					cout << "";
					break;

        	}
       	 
	}while (opt != 0);    

	return 0;
}