#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int bestInvitation(vector<string>, vector<string>);

int main(int argc, char* argv[]){
	const char* input1[] = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
 "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
	const char* input2[] = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
 "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};

	vector<string> first(std::begin(input1), std::end(input1)) ;
	vector<string> second(std::begin(input2), std::end(input2));
	cout<<bestInvitation(first, second)<<endl;
	return 1;

}

int bestInvitation(vector<string> first, vector<string> second){
	map<string, int> res;

	for(vector<string>::iterator i = first.begin(), j = second.begin(); i != first.end(), j != second.end(); i++, j++){
			res[*i]++;
			res[*j]++;
	}
	int max = 1;
	for(map<string, int>::iterator i = res.begin(); i != res.end(); i++){
		if(max < i->second){ max = i->second;}
	}
	return max;

}
