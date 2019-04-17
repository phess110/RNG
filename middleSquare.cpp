#include <iostream>
#include <cmath>
using namespace std;

int middleSquare(unsigned int n){
	if(n < 10){
		return 0;
	}

	int len = floor(log10(n)) + 1;
	int chop = ceil(len/2.0);
	return (n*n/((int)pow(10,chop))) % (int)(pow(10, 2*(len-chop)));
}

int main(){

	unsigned int n;

	cout << "Enter a positive integer: ";
	cin >> n;

	for(int i = 0; i < 10; i++){
		n = middleSquare(n);
		cout << "Middle square: " << n << "\n";
	}
}