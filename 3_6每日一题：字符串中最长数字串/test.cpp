#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsNum(char ch){
	auto temp = ch + 0;
	if (48 <= temp && temp <= 57){
		return true;
	}
	return false;
}

int main(){
	vector<string> array;
	string str;
	string temp = "";
	cin >> str;
	if (str.empty()){
		cout << "" << endl;
		system("pause");
		return 0;
	}
	auto it = str.begin();
	while (it != str.end()){
		auto nustr = it;
		while (it != str.end()&&(!IsNum(*it))){
			it++;
		}
		//if (it == str.end()){
		//	cout << "" << endl;
		//	system("pause");
		//	return 0;
		//}
		nustr = it;
		while (nustr != str.end()&&IsNum(*nustr)){
			nustr++;
		}
		
		for (auto i = it; i != nustr; ++i){
			char ch = *i;
			char tmp[1];
			tmp[0] = ch;
			string res(tmp, 1);
			temp += res;
		}

		array.push_back(temp);
		temp = "";
		it = nustr;
	}
	int maxstr = 0;
	for (int i = 0; i < array.size(); ++i){
		if (array[i].size() >= maxstr){
			maxstr = array[i].size();
		}
	}
	for (int i = 0; i < array.size(); ++i){
		if (maxstr == array[i].size()){
			cout << array[i] << endl;
		}
	}
	system("pause");
	return 0;
}
