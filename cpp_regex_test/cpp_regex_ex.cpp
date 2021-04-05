#include <bits/stdc++.h>
// #include <regex>

using namespace std;

/*
    regex_match() : 문자열이 정규 표현식에 정확하게 
                    일치하는지 여부 반환(bool)
    regex_search() : 문자열이 정규 표현식에 매치되는 sub-string을 
                     포함하고 있는지 여부 반환 (bool)
    regex_replace() : 매치된 정규 표현식을 replace 문자열로 교체하고,
                      교체된 전체 문자열을 반환
*/

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    string s = "1+10+100+1000";
    //string s = "1921";
 
    //regex self_regex("REGULAR EXPRESSIONS");
    //if (regex_search(s, self_regex)) {
    //    cout << "Text contains the phrase 'regular expressions'\n";B
    //}g

    regex word_regex;

    try {
        word_regex = "(?x)(?:a(?=a*(\\1+?b)))+\\1";
        //word_regex = "(([0-9]{2})|([0-9]{1})|([0-9]{3}))(([0-9]{1})|([0-9]{2})|([0-9]{3}))";
        //word_regex = "((([0-9]{1})|([0-9]{2})|([0-9]{3}))\\.){3}([0-9]{1,3})";
        //word_regex = "((\\d{1})|(\\d{2})|(\\d{3})\\.){3}(\\d{1,3})";
        //word_regex = "(((\\d{1,2})|(1\\d{2})|(2[0-4]\\d)|(25[0-5]))\\.){3}((\\d{1,2})|(1\\d{2})|(2[0-4]\\d)|(25[0-5]))";
    }
    catch(const regex_error& e) {
        
        cout << "regex_error caught: " << e.what() << endl;
    }

    smatch m;

    // if(regex_match(s, m, word_regex)) {
    //     for(int i=0; i<m.size(); i++) {
    //         cout << "m[" << i << "] = " << m[i] << '\n';
    //     }
    // }
    // else {
    //     cout << "not found";
    // }



    // while(regex_search(s, m, word_regex)) {
    //     for(int i=0; i<m.size(); i++) {
    //         cout << m[i] << '\n';
    //     }
    //     cout << "next" << '\n';
    //     s = m.suffix();
    // }
    // auto words_begin = sregex_iterator(s.begin(), s.end(), word_regex);
    // auto words_end = sregex_iterator();
 
    // cout << "Found " << distance(words_begin, words_end) << " words\n";
 
    // for (sregex_iterator i = words_begin; i != words_end; ++i) {
    //     smatch match = *i;
    //     string match_str = match.str();
    //     cout << "  " << match_str << '\n';
        
    // }
 

    //string new_s = regex_replace(s, word_regex, "[$4]");
    //cout << new_s << '\n';

    return 0;
}