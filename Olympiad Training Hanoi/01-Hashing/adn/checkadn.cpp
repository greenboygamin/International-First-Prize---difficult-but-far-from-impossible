#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define maxn 1003

typedef char NameFile[1000];

using namespace std;

NameFile input, output, answer;
ifstream fi, fo, fa;
int n,m;
string s1, s2, t1, t2;

int read()
{

}

int readInput()
{
  fi.open(input);
}

int readOutput()
{
  fo.open(output);
}

int readAnswer()
{
  fa.open(answer);
}

bool khop(string s, string t)
{
     for (int i = 0; i<n; i++)
     {
         int u = i;
         int v = 0;
         while (v <n && s[u] == t[v]) u= (u+1) % n, v++;
         if (v == n) return true;
     }
     return false;
}

bool check()

{	
  long long ans, out;
  fo >> out;
  fa >> ans;
  fo >> t1;
  fo >> t2;
  fi >> s1;
  fi >> s2;
  n = s1.size();
  if (out!=ans)
  {
      cout << out << " " << ans << " " << " Ket qua sai so luong!!\n";
      return 0;
  }
// others here

  if (out <= n && khop(s1,t1) && khop(s2,t2) && (t1.substr(n-out, out) ==  t2.substr(n-out, out)))
  {
      cout << " Ket qua dung!!! \n";
      return 1;
  } else 
  {
      cout << " Ket qua Sai!!! \n";
      return 0;  
  }
}

main()
{
  gets(input);
  gets(output);

  strcpy(answer, input);
  strcat(input,  "adn.inp");
  strcat(output, "adn.out");
  strcat(answer, "adn.out");

  readInput();
  readOutput();
  readAnswer();
  read();

  cout << ((check()) ? "1.00" : "0.00");
  fi.close();
  fo.close();
  fa.close();
//  system("pause");
}
