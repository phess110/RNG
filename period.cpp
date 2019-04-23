#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

/*
Given a function f: {0,...,m-1} -> {0,...,m-1}, and a seed X_0,
Let X_i = f(X_(i-1)) for i >= 1.

This function computes the smallest µ,p such that X_0,...,X_(µ+p-1) are distinct, but X_(n+p) = X_n for n >= µ.
That is, f is p-periodic starting at µ given seed X_0.

Memory: O(1) 
Time: O(µ+p)
*/
vector<int> findPeriod(int (*f)(int), int seed){

	vector<int> period (2);
	int n = 1;
	int v1 = f(seed); //X_n
	int v2 = f(v1);	//X_2n

	/* Compute smallest n > 0 such that X_n = X_2n */
	while(true){
		if(v1 == v2){ break; }
		v1 = f(v1);
		v2 = f(f(v2));
		n++;
	}

	v2 = v1; // v2 = X_n
	v1 = seed; // v1 = X_0
	int i = 0, v3 = v2, p = n; //v3 = X_n and p = n

	/* 
	Compute smallest i such that v1 = X_i = X_(n+i) = v2.
	p is the smallest i, 0 < i < µ, such that X_n = X_n+i. 
	*/
	while(true){
		if(v1 == v2){ break; }
		if( i > 0 && v2 == v3 && p == n){ p = i; } 
		v1 = f(v1);
		v2 = f(v2);
		i++;
	}

	period[0] = i; //µ = i
	period[1] = p; //period

	return period;
}


/* 
l(n) = largest power of 2 <= n
	
	n 	| 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15 ...
 l(n)-1	| 0  1  1  3  3  3  3  7  7   7   7   7   7   7   7 ...

*/
/* Stop generating numbers from a pseudorandom sequence when a repetition occurs. Return the period of the sequence. TODO */
int generator(int (*f)(int), int seed){
	// unfinished
	int X = seed, Y = seed;
	int k = 1, m = 1;

	X = f(X);
	k--;
	if(X == Y){
		//period = m - k
		return X;
	}
	else if(k == 0){
		Y = X;
		m *= 2;
		k = m;
	}
}

int main(){

	auto mod = [](int i) { return (5*i+13) % 99; }; // lambda which defines the recursive sequence

	vector<int> v = findPeriod(mod, 5);

	cout << "Period: " << v[1] << "\n";
	cout << "Starts at: " << v[0];

}