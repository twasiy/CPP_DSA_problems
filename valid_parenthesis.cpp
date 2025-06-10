#include<iostream>
#include<stack>

bool isValid(std::string str){
	std::stack<char> st;
	int size = str.size();
	for(int i{};i<size;i++){
		if(str[i]== '(' || str[i] == '{' || str[i] == '['){ //opening
			st.push(str[i]);
		}else{ //closing
			if(st.size() == 0){
				return false;
			}else if((st.top() == '(' && str[i] == ')') 
			|| (st.top() == '{' && str[i] == '}') 
			|| (st.top() == '[' && str[i] == ']')){
				st.pop();
			}else{ //no match
				return false;
			}
		}
	}
	return st.size() == 0;
}

int main(){
	std::string str{"()[]{}"};
	std::string str1{"(]"};
	std::string str2{"([])"};
	std::string str3{"()"};
	
	std::cout << isValid(str) << std::endl;
	std::cout << isValid(str1) << std::endl;
	std::cout << isValid(str2) << std::endl;
	std::cout << isValid(str3) << std::endl;

	return 0;
}
