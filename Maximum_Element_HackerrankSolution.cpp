#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    //std::stack<int> s;
    stack<int> nums;
    stack<int> max_tracker;
    vector<int> maxnums;
    int max = INT_MIN;
    //int top = -1;
    for(long unsigned int i=0; i<operations.size(); i++){
        switch(operations[i][0]){
        case('1'):
            cout<<"Operation 1"<<endl;
            nums.push(stoi(operations[i].substr(2)));
            if(max_tracker.empty() || max_tracker.top()<=stoi(operations[i].substr(2)))
                max_tracker.push(stoi(operations[i].substr(2)));
            break;
        
        case('2'):
            cout<<"Operation 2"<<endl;
            if(nums.top() == max_tracker.top())
                max_tracker.pop();
            nums.pop();
            break;
        
        case('3'):
            cout<<"Operation 3"<<endl;
            maxnums.push_back(max_tracker.top());
            break;
        }
    }
    return maxnums;
    
    // for(long unsigned int i=0; i<operations.size(); i++){
        
    //     if(operations[i][0] == '1'){
    //         cout<<"operation 1"<<endl;
    //         //s.push(stoi(operations[i].substr(2)));
    //         nums.push_back(stoi(operations[i].substr(2)));
    //         //top++;
    //     }
    //     else if (operations[i][0] == '2'){
    //         cout<<"operation 2"<<endl;
    //         //s.pop();
    //         nums.pop_back();
    //         max = INT_MIN;
    //         //top--;
    //     }
    //     else if (operations[i][0] == '3'){
    //         cout<<"operation 3"<<endl;
            
    //         for(int j=0;j<nums.size();j++){
    //             if(nums[j]>max){
    //                 cout<<nums[j];
    //                 max = nums[j];
    //             }
    //         }
    //         maxnums.push_back(max);
    //     }
    // }
    // return maxnums;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
