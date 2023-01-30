#include<iostream>
#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>

using namespace std;

bool gameover;
const int width =40;
const int height =40;
int x=-1,y=-1;
int fruitx=-1,fruity=-1;
int score=-1;
int tailx[100],taily[100];
int ntail;
enum eDirection {STOP =0,LEFT, RIGHT,UP,DOWN};
eDirection dir;


void setup(){
    gameover =false;
    dir = STOP;
    x= width /2;
    y =height/2;
    fruitx = rand()% width;
    fruity = rand()% height;
    score =0;
}

void Draw(){

system("cls");  //clear the screen
for(int i=0;i<width+2;i++){
    cout<<"#";   //top wall
}
cout<<endl;

for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
   if(j==0)
   cout<<"#";

  if(i ==y && j==x){
  cout<<"o";
  }
  else if(i== fruity && j== fruitx){
  cout<<"F";
  }
  else{ 
      bool print =false;
    for(int k=0;k<ntail;k++){
     if(tailx[k] ==j && taily[k]==i){
        cout<<"o";
        print =true;
     }
    }
    if(!print)
     cout<<" ";
  }

   if(j==width-1)
   cout<<"#"; 
    }
    cout<<endl;
}

for(int i=0;i<width+2;i++){
    cout<<"#";   //top wall
}
cout<<endl;
cout<<" Score:"<<score<<endl;

}

void Input(){  //coino.h application:

if(_kbhit()){   //keyboard button is pressed
  switch(_getch()){
    case 'a':
    dir =LEFT;
    break;
    case 'd':
    dir =RIGHT;
    break;
    case 'w':
    dir= UP;
    break;
    case 's':
    dir =DOWN;
    break;
    case 'x':
    gameover =true;
    break;
  }
}
}
void Logic(){
    int prevx =tailx[0];
    int prevy =taily[0];
    int prev2x,prev2y;
    tailx[0] =x;
    taily[0] =y;

    for(int i=1;i< ntail;i++){
        prev2x =tailx[i];
        prev2y =taily[i];
        tailx[i] =prevx;
        taily[i] =prevy;
        prevx =prev2y;
        prevy =prev2x;
    }
    switch(dir){
        case LEFT:
        x--;
        break;

        case RIGHT:
      x++;
      break;

        case UP:
          y--;
          break;
          case DOWN:
           y++;
           break;
           default:
           break;
    }
    if(x>width || x<0 || y> height || y<0) //out of boundary
    gameover =true;

    for(int i=0;i<ntail;i++){    //self collision
        if(tailx[i]==x && taily[i]==y)
        gameover =true;        
    }
    if(x== fruitx && y==fruity){
        score = score +10;
        fruitx =rand()% width;
        fruity =rand()% height;
        ntail++;
    }

}

int main(){

  setup();
 while(!gameover){
    Draw();
    Input();
    Logic();
    Sleep(280);
}    

    return 0;

}