#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<iterator>

template<typename C>
void print(const C& c)
{
	for(auto &i: c)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void inc(T& t, int n)
{
	for( auto &i : t)
	{
		i += n;
	}
}

// *-> pointer

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>()&& Output_Iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 p= f1; p!=e1; ++p)
	{
		*f2++=*p;
	}
	return f2;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 elem = f1; elem != e1; elem++)
	{
		*f2 = * elem;
		f2++;
	}
	
	return f2;
}

int main()
{
	//int array[10] = {0,1,2,3,4,5,6,7,8,9};
	//vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	//std::list<int> l = {0,1,2,3,4,5,6,7,8,9};
	
	constexpr int size=10;
		
	int arr[10];
	for(int i = 0; i < size; ++i) arr[i] = i;
		
	std::array<int, size> ai;
	std::copy(arr, arr+ size, ai.begin());
		
	std::vector<int> vi(size);
	std::copy(arr, arr+size, vi.begin());
		
	std::list<int> li(size);
	std::copy(arr, arr + size, li.begin());
		
	// lista -> összes elem feldolgozása
	// pop-front -> elem felhaszbálás
	
	//másolat:
	
	std::array<int, size> ai2 = ai;
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;
	
	print(ai2);
	print(vi2);
	print(li2);
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print(ai2);
	print(vi2);
	print(li2);
	
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	print(ai2);
	print(vi2);
	print(li2);
	
	my_copy(ai2.begin(), ai2.end(), vi2.begin());
	my_copy(li2.begin(), li2.end(), ai2.begin());
	
	std::cout << "Array:" << std::endl;
	print(ai2);
	std::cout << "Vector:" << std::endl;
	print(vi2);
	std::cout<< "List:" << std::endl;
	print(li2);
	
/*	auto vec_find = find(vi2.begin(), vi2.end(), 3);
	int vec_position = distance(vi2.begin(), vi2.find);
	
	auto lis_find = find(li2.begin(), li2.end(), 27);
	int lis_position = distance(li2.begin(), vi2.find);
	
	if(vec_find != vec.end())
		std::cout << "The position of the first element: " << vec_position << std::endl;
	else
		std::cout << "The value wasn't found" << std::endl;
		
	if(lis_find != lis.end())
		std::cout << "The position of the first element: " << lis_position << std::endl;
	else
		std::cout << "The value wasn't found" << std::endl;
*/
}
