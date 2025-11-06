#ifndef STRAPSCRUD_H
#define STRAPSCRUD_H

#include <vector>
#include "straps.h"

class StrapsCRUD
{
public:
    StrapsCRUD() = default;
    void addItem(StrapItems& item)
    {
		bool temp = true;
		//find all deleted items
		for(auto& s : allstraps_arr)
		{
			//if the item is deleted
			if(!s.isActive)
			{
				std::cout << s.id << '\n';
				temp = false;
				//edit/change/override the existing data
				if(item.categ == "stitched")
				{
					// s.id = item.id;
					s.color = item.color;
					s.brand = item.brand;
					s.leather_type = item.leather_type;
					s.quantity = item.quantity;
					s.size = item.size;
					s.price = item.price;
					s.setActive(true);
				}
			}
		}
		//otherwise, add another
		if(temp)
		{
			allstraps_arr.push_back(item);
			temp = true;
		}
    }

    void deleteItem(int id)
    {
		int count = 0;
        for(auto& s : allstraps_arr)
		{
			//delete item
			if(s.id == id)
				s.setActive(false);
		}
    }

    void viewItem(int strp)
    {
		//todo: print all the available choices here

		
        int choice;
		std::string categ;
		switch(strp){
			case 1:
				categ = "WITH STITCH STRAPS";
				DisplayStitched(categ);
				break;

			case 2:
				categ = "NO STITCH STRAPS";
				DisplayNoStitched(categ);           
				break;    

			case 3:
				cout << "\nCHOOSE CASIO TYPE:\n";
				cout << "[1] KIDS SIZE\n" ;
				cout << "[2] ADULT SIZE\n" ;
				cout << "[0] back\n" ;
				cout << "Choose an option: " ;
				cin >> choice;

				if(choice == 1) {
					categ = "CASIO STRAPS KIDS SIZE W/ COVER";
					DisplayCasioKids(categ);
				} else if(choice == 2) {
					categ = "CASIO STRAPS ADULT SIZE";
					DisplayCasio(categ);                                 
				}
				break;   

			case 4:
				categ = "WITH STITCH STRAPS";
				DisplayStitched(categ);
				categ = "NO STITCH STRAPS";
				DisplayNoStitched(categ);
				categ = "CASIO STRAPS KIDS SIZE W/ COVER";
				DisplayCasioKids(categ);
				categ = "CASIO STRAPS ADULT SIZE";
				DisplayCasio(categ); 
				break;
			}	
    }

    void editItem(int strp)
    {
		// do
        // {
		// 	cout << "\nEDIT ITEM\n";
		// 	cout << "[1] WITH STITCH STRAP\n";
		// 	cout << "[2] NO STITCH STRAP\n";
		// 	cout << "[3] CASIO STRAP\n";
		// 	cout << "[0] back\n";
		// 	cout << "Choose an option: ";
		// 	cin >> strp;
		// }
        // while(strp != 0);

		// for(auto& i : allstraps_arr)
		// {
		// 	i.brand = "mat";
		// }


    }

    int DisplayStitched(string& categ) {
			cout << "\n " << categ << " \n";
			cout << right << setw(10) << " ";
			cout << left << setw(5) << "ID"
				<< setw(20) << "Color"
				<< setw(15) << "Brand"
				<< setw(15) << "Leather Type"
				<< setw(10) << "Qty"
				<< setw(10) << "Size"
				<< setw(10) << "Price" << "\n";

			for (auto &i : allstraps_arr) {
				if(i.isActive) //if the variable is true
				{
					if(i.categ == "stitched")
					{
						cout << right << setw(10) << " ";
						cout << left << setw(5) << i.id
							<< setw(20) << i.color
							<< setw(15) << i.brand
							<< setw(15) << i.leather_type
							<< setw(10) << i.quantity
							<< setw(10) << i.size
							<< setw(10) << i.price << "\n";
					}
				}
			}
			return 0;
		}

	int DisplayNoStitched(string& categ) {
			cout << "\n " << categ << " \n";
			cout << right << setw(10) << " ";
			cout << left << setw(5) << "ID"
				<< setw(20) << "Color"
				<< setw(15) << "Brand"
				<< setw(15) << "Leather Type"
				<< setw(10) << "Qty"
				<< setw(10) << "Size"
				<< setw(10) << "Price" << "\n";

			for (auto &i : allstraps_arr) {
				if(i.categ == "no stitch"){
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						<< setw(20) << i.color
						<< setw(15) << i.brand
						<< setw(15) << i.leather_type
						<< setw(10) << i.quantity
						<< setw(10) << i.size
						<< setw(10) << i.price << "\n";
				}
			}
			return 0;
		}

	int DisplayCasio(string& categ) {
			cout << "\n " << categ << " \n";
			cout << right << setw(10) << " ";
			cout << left << setw(5) << "ID"
				<< setw(20) << "Color"
				<< setw(15) << "Brand"
				<< setw(15) << "Leather Type"
				<< setw(10) << "Qty"
				<< setw(10) << "Size"
				<< setw(10) << "Price" << "\n";

			cout << "1 HOLE\n";
			for (auto &i : allstraps_arr) {
				if(i.hole == "1 hole"  && i.isActive){
					if(i.categ == "casio"){
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						<< setw(20) << i.color
						<< setw(15) << i.brand
						<< setw(15) << i.leather_type
						<< setw(10) << i.quantity
						<< setw(10) << i.size
						<< setw(10) << i.price << "\n";
					}
				}
			}

			cout << "\n2 HOLE\n";
			for (auto &i : allstraps_arr) {
				if(i.hole == "2 hole" && i.isActive){
					if(i.categ == "casio"){
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						<< setw(20) << i.color
						<< setw(15) << i.brand
						<< setw(15) << i.leather_type
						<< setw(10) << i.quantity
						<< setw(10) << i.size
						<< setw(10) << i.price << "\n";
					}
				}
			}
			return 0;
		}

	int DisplayCasioKids(string& categ) {
			cout << "\n " << categ << " \n";
			cout << right << setw(10) << " ";
			cout << left << setw(5) << "ID"
				<< setw(20) << "Color"
				<< setw(15) << "Brand"
				<< setw(15) << "Leather Type"
				<< setw(10) << "Qty"
				<< setw(10) << "Size"
				<< setw(10) << "Price" << "\n";

			cout << "1 HOLE\n";
			for (auto &i : allstraps_arr) {
				if(i.hole == "1 hole"){
					if(i.categ == "casio w/ cover"){
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						<< setw(20) << i.color
						<< setw(15) << i.brand
						<< setw(15) << i.leather_type
						<< setw(10) << i.quantity
						<< setw(10) << i.size
						<< setw(10) << i.price << "\n";
					}
				}
			}

			cout << "\n2 HOLE\n";
			for (auto &i : allstraps_arr) {
				if(i.hole == "2 hole"){
					if(i.categ == "casio w/ cover"){
					cout << right << setw(10) << " ";
					cout << left << setw(5) << i.id
						<< setw(20) << i.color
						<< setw(15) << i.brand
						<< setw(15) << i.leather_type
						<< setw(10) << i.quantity
						<< setw(10) << i.size
						<< setw(10) << i.price << "\n";
					}
				}
			}
			return 0;
		}
    
};

#endif