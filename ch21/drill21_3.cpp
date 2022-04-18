#include<iostream>
#include<stdexcept>
#include<vector>
#include<fstream>
#include<numeric>
#include<algorithm>

template<typename C>
void print(const C& c, char sep= '\n')
{
	std::cout << "Container elements:" << std::endl;
	
	for(const auto elem: c)
	{
		std::cout << elem << sep;
	}
	
	std::cout << std::endl;
}

int main ()
{
try{
	const std::string iname {"input.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Could not read file: " + iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d;)
	{
		vd.push_back(d);
	}
	
	
	print(vd);
	
	std::vector<int> vi(vd.size());
	/*for(auto i:vd)
	{
		vi.push_back(i);
	}*/
	std::copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for(int i=0; i<vd.size(); ++i)
	{
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}
	
	std::cout.precision(10);
	
	double sum_vd=0;
	for(int i=0; i<vd.size(); i++)
		sum_vd += vd[i];
	std::cout<< "\nSum of the vd: " << sum_vd << std::endl;
	
	double sum_vi=0;
	for(int i=0; i<vi.size(); i++)
		sum_vi += vi[i];
	std::cout<< "Sum of the vi: " << sum_vi << std::endl;
	
	double dif = sum_vd - sum_vi;
	std::cout << "The difference: " << dif << std::endl;
	
	std::reverse(vd.begin(), vd.end());
	print(vd);
	
	double vd_mean = sum_vd/vd.size();
	std::cout << "Mean value of vd: " << vd_mean << std::endl;
	
	std::vector<double> vd2;
	for(int i=0; i < vd.size(); i++)
	{
		if(vd[i] < vd_mean)
			vd2.push_back(vd[i]);
	}
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);
	
} catch(std::exception& e) {
	std::cerr<<e.what() << '\n';
	return 1;
} catch (...){
	std::cerr << "Unknown exception" << '\n';
	return 2;
}
}
