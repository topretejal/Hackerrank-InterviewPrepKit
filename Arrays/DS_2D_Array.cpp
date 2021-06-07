#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr) {
vector<int> hourglass_sum;
//no. of rows in 2d vector
int nr=arr.size();
//no. of columns in first row(here same in all rows)
int nc=arr[0].size();
// cout<<nr<<" and "<<nc<<endl;
int sum,max;
for(int i=0;i<=nr-3;i++)
{
    
    for(int j=0;j<=nc-3;j++)
    {
        sum=0;
        //first row
        sum+=arr[i][j]+arr[i][j+1]+arr[i][j+2];
        //middle element
        sum+=arr[i+1][j+1];
        //third row
        sum+=(arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]);
        //for debugging
        // cout<<"i:"<<i<<" j: "<<j<<" sum: "<<sum<<endl;
        hourglass_sum.push_back(sum);
    }
    
    
}
//for debugging
// cout<<"vector elements:"<<endl;
// for(int k=0;k<hourglass_sum.size();k++)
//     cout<<hourglass_sum[k];
// cout<<endl;
max=*max_element(hourglass_sum.begin(),hourglass_sum.end());
return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

