/*
https://www.acmicpc.net/submit/2941/46003622

크로아티아 알파벳	변경
č	            c=
ć	            c-
dž	            dz=
đ	            d-
lj	            lj
nj	            nj
š	            s=
ž	            z=



예제 입력 1 
ljes=njak
예제 출력 1 
6

예제 입력 2 
ddz=z=
예제 출력 2 
3

예제 입력 3 
nljj
예제 출력 3 
3

예제 입력 4 
c=c=
예제 출력 4 
2

예제 입력 5 
dz=ak
예제 출력 5 
3

*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> cro = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    string input;
    cin >> input;
    for(int i = 0; i < cro.size(); ++i)
    {
        long long pos = 0;
        while((pos = input.find(cro[i])) != string::npos)
        {
            input.replace(pos, cro[i].length(), "#");
        }
    }
    cout << input.size() << "\n";
    return 0;
}
