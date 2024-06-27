#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
	int length = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s.at(i) != ' ') {
			length++;
		}
		else if (length != 0) {
			return length;
		}
	}
	return length;
}

string addBinary(string a, string b) {
	string answer;
	int carry = 0;
	for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0;i--, j--) {
		int sum = carry;
		sum += i >= 0 ? a[i] - '0' : 0;
		sum += j >= 0 ? b[j] - '0' : 0;
		string s = to_string(sum % 2);
		answer = s + answer;
		carry = sum / 2;
	}
	if (carry == 1) {
		string c = to_string(carry);
		answer = c + answer;
	}
	return answer;
}
void main(){
////lengthoflastword
//	string s = "happy new year";
//	string a = "a";
//	cout << lengthOfLastWord(s) << endl;
//	cout << lengthOfLastWord(a) << endl;
////lengthoflastword

//addBinary
	string a = "1001";
	string b = "100";
	cout << addBinary(a, b);
//addBinary
}