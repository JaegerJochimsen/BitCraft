#include <iostream>
#include "sha256.h"

/*
* An attempt at a bitcoin mining script using sha256 hashing and open MP for loop parallelization.
* Currently, it seems to work except that it isn't quite fast enough; it WILL find suitable nonce values
* for 8 leading zeroes, it just takes a long time. Still more optimization needs to happen to work for 16
* zeroes.
* 
* Credit: 
* sha256.cc & sha256.h : http://www.zedwood.com/article/cpp-sha256-function
* mine() function format : NeuralNine (YouTube)
*/

using namespace std;

unsigned long long int NONCE_LIMIT = 1000000000000;

/*
* A function which checks the leading 8 digits of a string to determine if they are all "0";
*
* PARAM: string s -- the string to be checked for leading zeroes;
* RETURN: unsigned int -- 1 if all 8 leading digits are "0", otherwise returns 0;
*/
unsigned int check_lead_zeroes(string s){
	// if all 8 leading positions are '0' then we have successfully found a nonce val
	return ((s[0] =='0') && 
			(s[1] =='0') && 
			(s[2] =='0') && 
			(s[3] =='0') &&
			(s[4] =='0') && 
			(s[5] =='0') && 
			(s[6] =='0') && 
			(s[7] = '0'));
 }

void mine(unsigned long long int block_num, string trans, string
prev_hash){
	// pull base text creation out of loop 
	string base_text = to_string(block_num) + trans + prev_hash;
	
	// parallelize
	#pragma omp parallel for
	for(unsigned long long int i = 0; i < NONCE_LIMIT; ++i){

		// current attempt to find an additive which achieves desired hex output (num_zeroes leading zeroes)
		string current = base_text + to_string(i);
		string attempt = sha256(current);

		// Check to see if current attempt was successful
		if(check_lead_zeroes(attempt)){
			cout << "Nonce Found: " << i << endl;
		}
	}
	return;
}

int main(){
	unsigned long long int block = 24;
	string tra = "76123fcc2142";
	string prev = "876de8756b967c87";
	mine(block, tra, prev);
	return 0;
}
