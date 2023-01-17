#include <iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef string::iterator strit;
class OneEditAway
{
private:
    std::string str;
public:

    OneEditAway(string str):str(str) {}

    string get_str()
    {
        return this->str;
    }

    void set_str(string str)
    {
        this->str = str;
    }

    bool check_on_edit_away(OneEditAway o)
    {
        bool res =false;
        string big_one = (o.str.length() > this->str.length())? o.str:this->str;
        string small_one = (o.str.length() < this->str.length())? o.str:this->str;
        if(str.compare(o.str) == 0){
            res = true;
            return res;
        }
        else if (o.str.length() == this->str.length())
        {
            int diff =0;
            strit s=o.str.begin();

            for(strit t=this->str.begin();t!=this->str.end(); s++,t++)
            {
                if(*s != *t)
                {
                    diff++;
                }
                if(diff>1)
                {
                    return res;
                }
            }
            if(diff <= 1){
                res = true;
                return res;
            }
        }

        else if(big_one.length()-small_one.length() == 1)
        {
            int diff1 = 0;
            int i=0;
            strit t=big_one.begin();
            int j=0;
            strit s=big_one.begin()+1;
            for(;t<big_one.end()-1; i++,t++)
            {
                if(*t != small_one[i])
                {
                    diff1++;
                }
            }
            if(diff1==0){
                    res =true;
                    return res;
            }
            diff1 = 0;
            for (;s<big_one.end(); s++,j++)
            {
                if(*s != small_one[j])
                {
                    diff1++;
                }
            }
            if(diff1==0){
                res=true;
                return res;
            }
            else{
                res = false;
                return res;
            }
        }
        else if((big_one.length()- small_one.length()) > 1){
            return false;
        }

    }

};
int main()
{
    OneEditAway o("hib");
    OneEditAway p("hi");
    cout<< o.check_on_edit_away(p);
    return 0;
}
