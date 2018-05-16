//http://www.lintcode.com/zh-cn/problem/word-pattern/#
class Solution {
public:
    /**
     * @param pattern: a string, denote pattern string
     * @param str: a string, denote matching string
     * @return: an boolean, denote whether the pattern string and the matching string match or not
     */
    bool wordPattern(string &pattern, string &str) {
        // write your code here
        
        string allFirst[1000000];//可改为vector
        //string [] allFirst;编译错误
		int count;//单词编号
		count = 0;
		allFirst[0] ="";
		for (int i = 0; i<str.size(); i++) {
			if (str[i] != ' ') {
				allFirst[count] += str[i];
			}
			 if (str[i] == ' ') {
				 count = count +1;
				 allFirst[count] = "";
			}
		}
		
		map<char,string> pattern_map;
		set<string> str_set;//用于检测是否有不同的字母对应一个单词
		
		for(int i=0;i<pattern.size();i++){
		    if(!pattern_map.count(pattern[i])){//该字母第一次出现
		        if(str_set.find(allFirst[i])!=str_set.end()){//不同的字母对应一个单词
		            return false;
		        }
		        else{
		            pattern_map.insert(pair<char,string>(pattern[i],allFirst[i]));
		            str_set.insert(allFirst[i]);
		           
		        }
		    }
		    else{//该字母以前出现过
		        if(pattern_map.find(pattern[i])->second!=allFirst[i]){
		            return false;
		        }
		    }
		}
        
        return true;
    //不用map的做法   
        
	/*	string pattern_temp = "";//相等添加"1",不相等添"0"
		for (int i = 0; i<pattern.size() - 1; i++) {
			for (int j = i + 1; j<pattern.size(); j++) {
				if (pattern[i] == pattern[j]) {
					pattern_temp += "1";
				}
				else if (pattern[i] != pattern[j]) {
					pattern_temp += "0";
				}
			}
		}

		string allFirst[1000000];
		int count;//单词编号
		count = 0;
		allFirst[0] ="";
		for (int i = 0; i<str.size(); i++) {
			if (str[i] != ' ') {
				allFirst[count] += str[i];
			}
			 if (str[i] == ' ') {
				 count = count +1;
				 allFirst[count] = "";
			}
		}

		string allFirst_temp = "";
		for (int b = 0; b<count; b++) {
			for (int c = b + 1; c<count + 1; c++) {
				if (allFirst[b] == allFirst[c]) {
					allFirst_temp += "1";
				}
				else {
					allFirst_temp += "0";
				}
			}
		}

		for (int i = 0; i<pattern_temp.size(); i++) {
			if (pattern_temp[i] != allFirst_temp[i]) {
				return false;
			}
		}
		return true;*/
    }
};