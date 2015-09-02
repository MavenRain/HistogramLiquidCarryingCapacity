#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char** argv)
{
	if (argc < 4)
	{
		cout << "Usage: HistogramLiquidCarryingCapacity [array of whole numbers, beginning with a positive number]\r\n";
		return -11111;
	}
	
	vector<unsigned int> modes;
	for (unsigned int index = 1; index < static_cast<unsigned int>(argc); ++index)
	{
		if (stoi(argv[index]) < 0)
		{
			cout << "All program arguments must be whole numbers.\r\n";
			return -11111;
		}
		modes.push_back(stoi(argv[index]));
	}
	if (modes[0] == modes[modes.size() - 1])
	{
		cout << "Liquid carrying capacity = 0\r\n";
		return 0;
	}
	auto leftOuterBound = static_cast<unsigned int>(0);
	while (modes[leftOuterBound] <= modes[leftOuterBound + 1])
	{
		++leftOuterBound;			
		if (leftOuterBound + 1 > modes.size() - 1) break;
	}
	if (leftOuterBound == modes[modes.size() - 1])
	{
		cout << "Liquid carrying capacity = 0\r\n";
		return 0;
	}
	auto rightOuterBound = modes.size() - 1;
	while (modes[rightOuterBound] <= modes[rightOuterBound - 1])
	{
		--rightOuterBound;
		if (rightOuterBound < 1) break;
	}
	if (leftOuterBound == rightOuterBound)
	{
		cout << "Liquid carrying capacity = 0\r\n";
		return 0;
	}
	for (unsigned int index = 0; index < leftOuterBound; ++index) modes.erase(modes.begin() + index);
	for (auto index = modes.size() - 1; index > rightOuterBound; --index) modes.erase(modes.begin() + index);
	unsigned int offset = 0;
	auto leftBound = offset;
	auto total = offset;
	while (leftBound < modes.size() - 1)
	{
		if (modes[offset] <= modes[leftBound])
		{
			total += modes[leftBound] - modes[offset];
			++offset;
			if (offset >= modes.size() - 1) break;
		}
		else
		{
			leftBound = offset;
		}
	}

	cout << "Liquid carrying capacity = " << total << "\r\n";
	return 0;
}