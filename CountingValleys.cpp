#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
stack<char> s;
int vcount=0;
if(steps<2 || steps>1000000)
    return 0;
if(steps==path.length())
{
for(int i=0;i<steps;i++)
{
    if(s.empty())
        s.push(path[i]);
    else if(s.top()=='U'&& path[i]=='U')
        s.push(path[i]);
    else if(s.top()=='U' && path[i]=='D')
       {
         s.pop();
       } 
    else if(s.top()=='D' && path[i]=='D')
        s.push(path[i]);
    else if(s.top()='D' && path[i]=='U')
    {
        s.pop();
        if(s.empty())
            vcount++;
    }
}
char x;
while(!s.empty())
    {
        x=s.top();
        s.pop();
    }
if(x=='D')
    vcount++;
}
return vcount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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

