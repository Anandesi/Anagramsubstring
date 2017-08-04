#include<iostream>
#include<cstring>

using namespace std;
 
bool isEqual(char a[], char b[])
{
    for (int i=0; i<256; i++)
        if (a[i] != b[i])
            return false;
    return true;
}
 
void search(const char *pattern, const char *text)
{
    int lenP = strlen(pattern), lenT = strlen(text), flag=0;
 
    char patternFreq[256] = {0}, textFreq[256] = {0};
  
    for (int i = 0; i < lenP; i++)
    {
        (patternFreq[pattern[i]])++;
        (textFreq[text[i]])++;
    }
 
    for (int i = lenP; i < lenT; i++)
    {
        if (isEqual(patternFreq, textFreq))
            flag=1;
 
        (textFreq[text[i]])++;
 
        textFreq[text[i-lenP]]--;
    }
 
    if (isEqual(patternFreq, textFreq))
        flag = 1;
  
      if( flag == 1 )
      cout<<"True";
      else
      cout<<"False";
  
}
 
int main()
{
      string pattern, text;
      getline(cin, text);
      getline(cin, pattern);
    search(pattern.c_str(), text.c_str());
    return 0;
}