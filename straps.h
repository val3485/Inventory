 #ifndef STRAPS_H
 #define STRAPS_H

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;

struct StrapItems 
{
	//struct is used as a container for related data
	bool isActive = true;
	int id;
	string categ;
	string color;
	string brand;
	string leather_type;
	int quantity;
	string size;
	string kid_size;
	double price;
	string hole;

	StrapItems(int i, string ct, string c, string b, string lt, int q, string s, double p, string h) //this is called a constructor, it reads(?) the data from the array in order.
			: id(i), categ (ct), color(c), brand(b), leather_type(lt), quantity(q), size(s), price(p), hole(h) {}

	void setActive(bool active)
	{
		isActive = active;
	}

	bool getActive()
	{
		return isActive;
	}
};
		inline vector<StrapItems> allstraps_arr = { //vector is used make the array more efficient. you can modify it without manually entering the size 
			{1, "stitched", "Black w/ black", "No type", "Buffalo Calf", 10, "16-24", 950, ""},
			{2, "stitched", "Black w/ white", "No type", "Buffalo Calf", 10, "16-24", 950, ""},
			{3, "stitched", "Brown dark", "No type", "Buffalo Calf", 10, "16-24", 950, ""},
			{4, "stitched", "Brown light", "No type", "Buffalo Calf", 10, "16-24", 950, ""},
			{5, "stitched", "Black w/ black", "No type", "Chrono Genuine", 10, "20-24", 1200, ""},
			{6, "stitched", "Black w/ white", "No type", "Chrono Genuine", 10, "20-24", 1200, ""},
			{7, "stitched", "Brown w/ white", "No type", "Chrono Genuine", 10, "20-24", 1200, ""},
			{8, "stitched", "Black", "No type", "Genuine", 10, "16-24", 650, ""},
			{9, "stitched", "Brown dark", "No type", "Genuine", 10, "16-24", 650, ""},
			{10, "stitched", "Brown light", "No type", "Genuine", 10, "16-24", 650, ""},
			{11, "stitched", "Gray", "No type", "Genuine", 10, "16-24", 650, ""},
			{12, "stitched", "Red", "No type", "Genuine", 10, "16-24", 650, ""},
			{13, "stitched", "Black w/ black", "No type", "Cobra Genuine", 10, "16-24", 550, ""},
			{14, "stitched", "Blue light w/ blue", "No type", "Cobra Genuine", 10, "16-24", 550, ""},
			{15, "stitched", "Brown dark w/ brown", "No type", "Cobra Genuine", 10, "16-24", 550, ""},
			{16, "stitched", "Brown light w/ brown", "No type", "Cobra Genuine", 10, "16-24", 550, ""},
			{17, "stitched", "Gray w/ blue", "No type", "Cobra Genuine", 10, "16-24", 550, ""},
			{18, "stitched", "Red w/ red", "No type", "Cobra Genuine", 10, "16-24", 550, ""},
			{19, "stitched", "Black w/ blue", "No type", "Silicone", 10, "16-24", 750, ""},
			{20, "stitched", "Black w/ orange", "No type", "Silicone", 10, "16-24", 750, ""},
			{21, "stitched", "Black w/ red", "No type", "Silicone", 10, "16-24", 750, ""},
			{22, "stitched", "Black w/ white", "No type", "Silicone", 10, "16-24", 750, ""},
			

			{23, "no stitch", "Black", "Alpha", "No type", 10, "16-24", 1500, ""},
			{24, "no stitch", "Brown dark", "Alpha", "No type", 10, "16-24", 1500, ""},
			{25, "no stitch", "Brown light", "Alpha", "No type", 10, "16-24", 1500, ""},
			{26, "no stitch", "Red", "Alpha", "No type", 10, "16-24", 1500, ""},
			{27, "no stitch", "Black", "No type", "Brazilian", 10, "16-24", 1200, ""},
			{28, "no stitch", "Brown dark", "No type", "Brazilian", 10, "16-24", 1200, ""},
			{29, "no stitch", "Brown light", "No type", "Brazilian", 10, "16-24", 1200, ""},
			{30, "no stitch", "Black", "No type", "Buffalo Swiss", 10, "16-24", 750, ""},
			{31, "no stitch", "Blue", "No type", "Buffalo Swiss", 10, "16-24", 750, ""},
			{32, "no stitch", "Brown light", "No type", "Buffalo Swiss", 10, "16-24", 750, ""},
			{33, "no stitch", "Green", "No type", "Buffalo Swiss", 10, "16-24", 750, ""},
			{34, "no stitch", "White", "No type", "Buffalo Swiss", 10, "16-24", 750, ""},
			{35, "no stitch", "Black", "No type", "Genuine", 10, "24", 850, ""},
			{36, "no stitch", "Black", "No type", "Genuine Italy", 10, "16-24", 650, ""},
			{37, "no stitch", "Brown dark", "No type", "Genuine Italy", 10, "16-24", 650, ""},
			{38, "no stitch", "Brown light", "No type", "Genuine Italy", 10, "16-24", 650, ""},
			{39, "no stitch", "Black", "No type", "Silicone", 10, "16-24", 750, ""},
			{40, "no stitch", "Brown", "No type", "Silicone", 10, "16-24", 750, ""},
			{41, "no stitch", "Green", "No type", "Silicone", 10, "16-24", 750, ""},
			{42, "no stitch", "Orange", "No type", "Silicone", 10, "16-24", 750, ""},
			{43, "no stitch", "Red", "No type", "Silicone", 10, "16-24", 750, ""},
			{44, "no stitch", "Violet", "No type", "Silicone", 10, "16-24", 750, ""},
			{45, "no stitch", "White", "No type", "Silicone", 10, "16-24", 750, ""},
			{46, "no stitch", "Black", "No type", "Vintage Calf Genuine", 10, "18-24", 1500, ""},
			{47, "no stitch", "Brown dark", "No type", "Vintage Calf Genuine", 10, "18-24", 1500, ""},
			{48, "no stitch", "Brown light", "No type", "Vintage Calf Genuine", 10, "18-24", 1500, ""},
			{49, "no stitch", "Orange", "No type", "Vintage Calf Genuine", 10, "18-24", 1500, ""},
			{50, "no stitch", "Red light", "No type", "Vintage Calf Genuine", 10, "18-24", 1500, ""},
			{51, "no stitch", "Yellow", "No type", "Vintage Calf Genuine", 10, "18-24", 1500, ""},

			{52, "casio", "Black", "Casio", "No type", 10, "Fixed", 750, "1 hole"},
			{53, "casio", "Blue dark", "Casio", "No type", 10, "Fixed", 750, "1 hole"},
			{54, "casio", "Blue light", "Casio", "No type", 10, "Fixed", 750, "1 hole"},
			{55, "casio", "Orange", "Casio", "No type", 10, "Fixed", 750, "1 hole"},
			{56, "casio", "Pink dark", "Casio", "No type", 10, "Fixed", 750, "1 hole"},
			{57, "casio", "Pink light", "Casio", "No type", 10, "Fixed", 750, "1 hole"},
			{58, "casio", "White", "Casio", "No type", 10, "Fixed", 750, "1 hole"},

			{59, "casio", "Black", "Casio", "No type", 10, "Fixed", 950, "2 hole"},
			{60, "casio", "Blue dark", "Casio", "No type", 10, "Fixed", 950, "2 hole"},
			{61, "casio", "Gray", "Casio", "No type", 10, "Fixed", 950, "2 hole"},
			{62, "casio", "Red", "Casio", "No type", 10, "Fixed", 950, "2 hole"},
			{63, "casio", "White", "Casio", "No type", 10, "Fixed", 950, "2 hole"},

			{64, "casio w/ cover", "Black", "Casio", "No type", 10, "Small", 1200, "1 hole"},
			{65, "casio w/ cover", "Blue dark", "Casio", "No type", 10, "Small", 1200, "1 hole"},
			{66, "casio w/ cover", "Red", "Casio", "No type", 10, "Small", 1200, "1 hole"},
			{67, "casio w/ cover", "Violet", "Casio", "No type", 10, "Small", 1200, "1 hole"},
			{68, "casio w/ cover", "White", "Casio", "No type", 10, "Small", 1200, "1 hole"},
			
			{69, "casio w/ cover", "Black", "Casio", "No type", 10, "Large", 1500, "2 hole"},
			{70, "casio w/ cover", "Blue dark", "Casio", "No type", 10, "Large", 1500, "2 hole"},
			{71, "casio w/ cover", "Orange", "Casio", "No type", 10, "Large", 1500, "2 hole"},
			{72, "casio w/ cover", "Red", "Casio", "No type", 10, "Large", 1500, "2 hole"},
			{73, "casio w/ cover", "White", "Casio", "No type", 10, "Large", 1500, "2 hole"}
			
		};

#endif