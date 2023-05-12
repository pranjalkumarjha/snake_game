// #include<bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;
int b = 1;
int x = 2, y = 3;
vector<int> posx;
vector<int> posy;  
int inix; 
int iniy;
int count=0;  
bool ate=0;   //to know whether the fruit generated has been eaten or not
int fx=0;     // fruit coordinates
int fy=0;   
void fruit_gen(){
   fx = rand()%29; 
   fy = rand()%59; 
   if(fx==0 || fy==0){
    fruit_gen();
   } 
   return;
}
void fruit_ate(){
     if(x==fx && y==fy){
         ate=1;          
         fruit_gen(); 
     }    
     else{
      ate=0;
     }
 

} 

void gameend(int x, int y)
{
  if (y == 0 || x == 0 || x == 29 || y == 59)
  {
    b = 0;
  }
  //  this is for the snake to die if it touches itself

  else
  { 
    if(posx.size()>1){ 
      int sn_len=posx.size();
    for (int i = 0; i < posx.size() - 1; i++)
    {
      
        if ((posx[sn_len-1] == posx[i]) && (posy[sn_len-1] == posy[i]) )
        {
          b = 0;
        }
      
    } 
    }
  }
}

void input()
{

  if (_kbhit())
  { 

    switch (_getch())
    {
    case 'w':   
      iniy=y;
      inix = x;
      x--; 

      posx.push_back(x);
      posy.push_back(y); 
       fruit_ate(); 
          if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }
      gameend(x, y);  
     
      count++;
      break;
    case 's': 
      inix= x; 
      iniy=y;
      x++;
      posx.push_back(x);
      posy.push_back(y); 
      fruit_ate();
        if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }

      gameend(x, y);  
      
      count++;
      break;
    case 'd': 
      inix=x;
      iniy=y;
      y++;
      posx.push_back(x);
      posy.push_back(y); 
          fruit_ate();
        if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }
      gameend(x, y); 
  
      count++;
      break;
    case 'a':  
      inix =x;
      iniy=y;
      y--;
      posx.push_back(x);
      posy.push_back(y); 
       fruit_ate();
         if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }
      gameend(x, y); 
     
      count++;
      break;
    
    } 
  
      
  }   
  return ;
  
}
void draw()
{
  
  for (int i = 0; i < 30; i++)
  {

    if (i == 0 || i == 29)
    {

      for (int j = 0; j < 60; j++)
      {
        cout << "#";
      }
    }
    else
    {
      for (int l = 0; l < 60; l++)
      { 
       
           
    
        if (l == 0 || l == 59)
        {
          cout << "#";
        }
        else
        { 
           if(i==fx && l==fy){ 
               
               cout<<"F"; 
               
            } 
            else{
          int c = 0;
          for (int j = 0; j < posx.size(); j++)
          {
            if (posx[j] == i && posy[j] == l)
            { 
              if(posx[j]==x && posy[j]==y){
                     cout<<"0";
              }
              else{
                 cout << "o";
              }
              
              c++;
            }
          }
          if (c == 0)
          {
            cout << " ";
          } 
          }
        }
      }
    }
  
    cout << "\n";
  } 
  return;
}
void auto_move(){
   
      if(inix-1==x){ 
          inix = x;
       x--;
      posx.push_back(x);
      posy.push_back(y);  
     
      fruit_ate();
        if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }  
      
      gameend(x,y); 
      
      }  
      else if(inix+1==x){ 
          inix=x; 
      x++;    
      posx.push_back(x);
      posy.push_back(y); 
     
      fruit_ate();
        if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }  
      
      gameend(x,y); 
      
      } 
      else  if(iniy-1==y){ 
          iniy=y;
      y--;
      posx.push_back(x);
      posy.push_back(y);  
     
      fruit_ate();
        if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }  

      gameend(x,y); 
      
      } 
       else if(iniy+1==y){ 
           iniy=y;
      y++;
      posx.push_back(x);
      posy.push_back(y);  
     
      fruit_ate();
        if(ate==0){
      posx.erase(posx.begin() + 0);
      posy.erase(posy.begin() + 0);
      }  

      gameend(x,y); 
      
      }  
     
     return; 
  
}
int main()
{
  // this push_back statement acts as  a bug when a 4 tailed snake is initialized // but in game it probably won't be a problem
  posx.push_back(x);
  posy.push_back(y);
  ate=1; 
  fruit_gen();
  inix = x; 
  iniy=y;
   cout<<"           WELCOME TO THE ULTIMATE FLICKER SNAKE GAME            "<<endl; 
   cout<<"                                                 --it's not a bug it's a feature"<<endl;  
   b=0;
   cout<<"PRESS 1 TO START"<<endl; 
   cin>>b;
  while (b)
  { 
    cout<<count<<endl; 
    draw();
    input();  
    auto_move();
    Sleep(120); 
    system("cls");  // this causes the flicker as everything is cleared before printing all over again
  }

  return 0;
}