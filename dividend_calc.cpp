#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstddef>
#include <cstring>
#include <limits.h>

using namespace std;

// Constant definition
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;

// Forward Declaration
void CalculateDividendOverYears();

// Main Function
int main()
{	
	int input = 0;
	system("clear");
	cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "This program provides various service for dividend calculation.\n";
	cout << "////////////////////////////////////////////////////////////////////\n" << endl << endl << endl;
	cout << "Menu:\n1. Dividend calculation over years\n2.\n3.\n";
	cout << "Enter your selection menu:";
	cin >> input;
	
	switch (input)
	{
		case 1:
		{
			CalculateDividendOverYears();
			break;
		}
		default:
			break;
	}
	return 0;
}

struct DividendInfoType
{
	// Input
	float principle;
	float div_rate;
	float increase_perc;
	uint32 duration;
	
	// Output
	float div_amt_received;
	float f_ROI;
};

void CalculateDividendOverYears()
{
	DividendInfoType* input = new DividendInfoType;
	memset(input, 0, sizeof(DividendInfoType));
	cout << "What is the principle amount?";
	cin >> input->principle;
	cout << "What is div rate?";
	cin >> input->div_rate;
	cout << "How many years?";
	cin >> input->duration;
	cout << "How much dividend increase in (%) per year?";
	cin >> input->increase_perc;
	
	// Dividend amount received is equal to (year ^ div_increase) * div_rate * principle amount
	// ROI = div_amt_received / principle
	// cout << "Debug " << input->duration << " " << input->div_rate << " " << input->principle << " " << input->div_amt_received << endl;
	
	// * pow((1.0f + input->increase_perc/100.0f), i)
	cout << "==================================================================\n";
	cout << "\t\t\tResult\t\t\t\t\t\n";
	cout << "==================================================================\n";
	float temp_principle = input->principle;
	for (int i = 0; i < input->duration; i++)
	{
		float cur_year_div = input->div_rate * temp_principle * (i == 0? 1:(1.0f + input->increase_perc/100.0f));
		temp_principle += cur_year_div;
		input->div_amt_received += cur_year_div;
		cout << "Dividend received on year " << i << " = " << cur_year_div << endl;		
	}
	input->f_ROI = (float)(input->div_amt_received / input->principle);
	
	cout << "Dividend amount received over " << input->duration << " years gives you = " << input->div_amt_received << '\n';
	cout << "Rate-Of-Return(ROI) = " << input->f_ROI * 100  << "%\n";
	
	delete input;
}