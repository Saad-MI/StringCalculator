#include <cassert>
#include <string>
#include <iostream>
using namespace std;

//plan is to neter a string with numbers
// go through each character and determine if its a number or not
//if number than add to the initalized sum
//if not then go to next character until last character

int string_calculator(string str) {
	int sum2 = 0;
	if (str.empty()) {
		return 0;
	}

	int length = str.length(); 
	//cout << str.length() << "length" << endl;

	for (int i = 0; i < length; i++) {
		string sum = "";
		if (isdigit(str[i])) {
			
			sum += string(1, str[i]);
			while (i+1 < str.length() && isdigit(str[i+1])) {
				i++;
				sum += string(1, str[i]);
				//if is digit, check if i+1 is a digit
				//if it is then check if i++ is digit/ keep adding the digit until a non number is found
			}
			sum2 += stoi(sum);

		}


	}
	//				sum += stoi(string(1, str[i]));

	return sum2;
}

int main() {
	assert(string_calculator("") == 0);
	assert(string_calculator("0") == 0);
	assert(string_calculator("1") == 1);
	assert(string_calculator("4,5,6") == 15);
	assert(string_calculator("4;5,6") == 15);

	assert(string_calculator("123") == 123);
	assert(string_calculator("14, 26; 2") == 42);
	assert(string_calculator("1,1,1,1,1,1,1,1,1,1") == 10);
	assert(string_calculator("100,200,300") == 600);
	assert(string_calculator("5,0,10") == 15);



	cout << "Your code passed the asserts successfully!" << endl;
	// And so on with more examples...
}

