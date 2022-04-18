#include<iostream>
#include<stdexcept>
#include<vector>
#include<fstream>
#include<numeric>
#include<algorithm>
#include<list>
#include<iterator>

struct Item
{
	std::string name;
	int iid;
	double value;
	
	
	Item()
	{
		name = "";
		iid = 0;
		value = 0.0;
	}
	Item(std::string n, int i, double v) : name(n), iid(i), value(v) {}
};

void print(std::vector<Item> vd)
{	
	for(int i = 0; i < vd.size(); i++)
	{
		std::cout << vd[i].name << '\t' << vd[i].iid << '\t' << vd[i].value << std::endl;
	}	
	
	std::cout << '\n';
}

void print_list(std::list<Item>& g)
{	

    	for(std::list<Item>::iterator it=g.begin(); it!=g.end(); it++)
    	{
    		std::cout << (*it).name << '\t' << (*it).iid << '\t' << (*it).value << std::endl;
    	}
    
    	std::cout << '\n';
}

std::list<Item>& erase_name(std::list<Item>& li, std::string name)
{
	for (std::list<Item>::iterator it = li.begin(); it != li.end(); it++)
	{
		if ((*it).name == name)
		{
			li.erase(it);
			return li;
		}
		
	}
	
}

std::list<Item>& erase_iid(std::list<Item>& li, int iid)
{
	for (std::list<Item>::iterator it = li.begin(); it != li.end(); it++)
	{
		if ((*it).iid == iid)
		{
			li.erase(it);
			return li;
		}
	}
	
}

int main()
{
	std::vector<Item> vi;
	
	const std::string iname {"input2.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Could not read file: " + iname);
	
	std::string n;
	int id;
	double v;
	Item item;
		
	for (int i = 0; i < 10; i++)
	{
		
		ifs >> n >> id >> v;
		vi.push_back( {n, id, v});
		
	}
	
	print(vi);
	
	//sort by name
	
	std::sort(vi.begin(), vi.end(), [] (Item a, Item b){return a.name < b.name;});
	print(vi);
	
	//sort by iid
	
	std::sort(vi.begin(), vi.end(), [] (Item a, Item b) {return a.iid < b.iid;});
	print(vi);
	
	//sort by value in reverse order
	
	std::sort(vi.begin(), vi.end(), [] (Item a, Item b) {return a.value > b.value;});
	print(vi);
	
	vi.push_back( {"horse shoe", 99, 12.34} );
	vi.push_back( {"Canon S400", 9988, 499.95} );
	print(vi);
	
	//remove items identified by name
	
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i].name == "horse shoe")
			vi.erase(vi.begin()+i);
	}
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i].name == "Canon S400")
			vi.erase(vi.begin()+i);
	}
	print(vi);
	
	// remove items identified by iid
	
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i].iid == 8)
			vi.erase(vi.begin()+i);
	}
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i].iid == 2)
			vi.erase(vi.begin()+i);
	}
	
	print(vi);
	
//list

	std::cout << "List:" << std::endl << std::endl;	
	
	std::list<Item> lis;
	
	const std::string in {"input2.txt"};
	std::ifstream ifl {in};
	if(!ifl) throw std::runtime_error("Could not read file: " + in);
	
	while(ifl >> n >> id >> v)
	{
		item.name = n;
		item.iid = id;
		item.value = v;
		lis.push_back(item);
	}
	
	print_list(lis);
	
	//sort
	
	lis.sort([](Item i1, Item i2) {return i1.name < i2.name; });
	print_list(lis);

	lis.sort([](Item i1, Item i2) {return i1.iid < i2.iid; });
	print_list(lis);

	lis.sort([](Item i1, Item i2) {return i1.value > i2.value; });
	print_list(lis);
	
	lis.push_back( {"horse shoe", 99, 12.34} );
	lis.push_back( {"Canon S400", 9988, 499.95} );
	print_list(lis);
	
	//remove items
	
	erase_name(lis, "horse shoe");
	erase_name(lis, "Canon S400");
	print_list(lis);
	
	erase_iid(lis, 8);
	erase_iid(lis, 2);
	print_list(lis);
}
