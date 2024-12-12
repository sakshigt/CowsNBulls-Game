#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    char str_to_be_guessed[20],user_input[20],temp[20],user_temp[20],match_char='_',rem_char,continue_flag,temp_flag;
    int i,pos,length,user_inp_length,count,cow_count,bull_count,no_of_attempts,score;
    char static_data[][20]={"pomegranate","student","zodic","computer","tiger","philosopy","championship","mango","horseride","greenwich","siyaram"};
    do
    {
        //just taking a random word from the defined datas.
       strcpy(str_to_be_guessed,static_data[rand()%10]);
       length=strlen(str_to_be_guessed);
       //initializing variables
       score=0;
       no_of_attempts=0;
       cout<<"Cows N Bulls Game\n\n";
       cout<<"The word has "<<length<<"characters"<<endl;
       do
       {
        strcpy(temp,str_to_be_guessed);
        bull_count=0;
        cow_count=0;
        count=length;
        cin>>user_input;
        //as user's input can be either in lower-case or upper-case 
        //therefore we are converting user's input into lower case
        strlwr(user_input);
        user_inp_length=strlen(user_input);
        strcpy(user_temp,user_input);
        if(user_inp_length<count)
           count=user_inp_length;
        for(i=0;i<count;i++)
        {
            if(str_to_be_guessed[i]==user_input[i])
             {
                bull_count++;
                temp[i]='_';
                user_temp[i]='_';
             }
        }
        if(bull_count!=count)
        {
          do
            {
               pos=0;
               temp_flag='Y';
               for(i=0;i<user_inp_length;i++)
                {
                  if(user_temp[i]!=match_char)
                  {
                    rem_char=user_temp[i];
                    temp_flag='Y';
                    pos=i;
                    break;
                  }
                  temp_flag='N';
                }
                if(temp_flag=='N')
                  break; 
             for(i=0;i<length;i++)
                 {
                   if(temp[i]==rem_char)
                   {
                    cow_count++;
                    temp[i]='_';
                    break;
                   }
                 }
                user_temp[pos]='_'; 
            }while(temp_flag=='Y');  
        }
       no_of_attempts++;
       cout<<user_input;
       cout<<":"<<bull_count<<"Bulls"<<cow_count<<"Cows"<<endl;
       } while (strcmp(str_to_be_guessed,user_input));
       score=100-no_of_attempts+1;
       cout<<endl<<endl<<"Your score:"<<score;
       cout<<"\n\nPress 'q' to Quit and other key to continue:";
       cin>>continue_flag;
    } while (continue_flag!='q');
  return 0;  
}   