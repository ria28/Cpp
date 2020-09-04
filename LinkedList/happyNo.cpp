#include<iostream>
using namespace std ;

int sqr(int no)
{
    int cnt =1;
    while(no/10 != 0)
    {
        cnt++;
        no = no /10;
    }
    

}

bool happyNo(int no)
{
    int newNO =0;

    if(no ==1)
    return true;
    else 
    return false;
    while(no !=0)
    {
        newNO += no%10 * no%10;
        no= no/10;
    }
    cout<<no;

    // if(newNO ==1)
    //     return true;

    happyNo(newNO);
    
}


int main(int argc, char** args)
{
    int no = 19;
    cout<<(boolalpha)<<happyNo(no);
}