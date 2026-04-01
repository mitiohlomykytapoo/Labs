#include<iostream>
using namespace std;
float operator"" _Kelvin(long double kelvin)
{
	float celsius = kelvin - 273.15f;
	return celsius;
}
float operator"" _Fahrenheit(long double fahrenheit)
{
	float celsius = (fahrenheit - 32.0f) * 5.0f / 9.0f;
	return celsius;
}
int main()
{
	float a = 300.0_Kelvin;
	cout << "Kelvin->Celsius: " << "300.0 Kelvin -> " << a <<" Celsius" << endl;
	float b = 120.0_Fahrenheit;
	cout << "Fahrenheitn->Celsius: " << "120.0 Fahreinheit -> " << b << " Celsius" << endl;
	return 0;
}