#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>

using namespace std;

struct tm parseTime(string& time) {
    int index1 = time.find('.');
    int index2 = time.find('.', index1 + 1);

    int year = atoi(time.substr(0, index1).c_str()) - 1900;
    int month = atoi(time.substr(index1 + 1, index2 - index1 - 1).c_str()) - 1;
    int day = atoi(time.substr(index2 + 1).c_str());

    struct tm datetime = {};
    datetime.tm_year = year;
    datetime.tm_mon = month;
    datetime.tm_mday = day;
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_sec = 0;

    return datetime;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> ans;
    struct tm ttoday = parseTime(today);
    // cout << ttoday;

    map<string, int> table;

    for(auto& str: terms) {
        int index = str.find(' ');
        table[str.substr(0, index)] = atoi((str.substr(index + 1)).c_str());
    }

    int res = 0;
    int j = 1;
    for(auto& str: privacies) {
        int index = str.find(' ');
        string t1Str = str.substr(0, index);
        struct tm t1 = parseTime(t1Str);

        string t2Str = str.substr(index + 1);
        int dur = table[t2Str];
        t1.tm_mon += dur;
        
        if(t1.tm_mon >= 12) {
            t1.tm_mon -= 12;
            t1.tm_year += 1;
        }
        
        if(mktime(&t1) <= mktime(&ttoday)) {
            ans.push_back(j);
        }
        j++;
    }

    return ans;
}