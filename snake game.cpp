#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define up       72
#define down     75
#define right    77
#define left     80
#define ESC      27

int ar[200][2];
int n=1;
int tam=3;
int x=10,y=12;
int dir=3;
int xc=30,yc=15;
int speed=150,h=1;
int score=0;
char charc;
int in,p;


void gotoxy(int x,int y)
{
	HANDLE ab;
	COORD cd;

	cd.X=x;
	cd.Y=y;
	ab = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(ab,cd);
}

void print(){
	//lineas ori
	for(int i=2;i<78;i++){
	gotoxy(i,3); cout<<205;
	gotoxy(i,23);cout<<205;

	}
	//lineas ver
	for(int i=4;i<23;i++){
		gotoxy(2,i); cout<<186;
		gotoxy(77,i);cout<<186;
	}
	//esqu
	gotoxy(2,3);  cout<<201;
	gotoxy(2,23); cout<<200;
	gotoxy(77,3); cout<<187;
	gotoxy(77,23);cout<<188;

}

void put_position(){
	ar[n][0]=x;
	ar[n][1]=y;
	n++;
	if(n==tam) n=1;

}

void image_body(){
	for(int i=1;i<tam;i++)
	{
		gotoxy(ar[i][0],ar[i][1]);  cout<<"*";
	}
}

void dell_body(){

		gotoxy(ar[n][0],ar[n][1]);  cout<<" ";

}
void teclear(){
if(kbhit()){
   	charc =getch();
   	switch(charc){
   		case up:
   			if(dir!=2)
   			    dir=1;
   			    break;
   		case left:
   			if(dir!=1)
   			 dir=2;
   			 break;
   		case right:
   			if(dir !=4)
   			dir=3;
   			break;
   		case down:
		   if(dir !=3)
		   dir=4;
		   	break;


	   }
   }
}
void chan_speed(){
if(score==h*20){
	speed-=10;
	h++;
}

}

void food(){
	if(x == xc && y == yc){
		xc=(rand()%73)+4;
		yc=(rand()%19)+4;

		tam++;
		score +=10;
		gotoxy(xc,yc); cout<<254;

		 chan_speed();
	}

}

bool game_over(){
	if(y ==3 || y == 23 || x == 2 || x == 77) return false;

	for(int j=tam-1;j>0;j--){
		if(ar[j][0]==x && ar[j][1]==y)

		return false;
	}

	return true;
}
void dot(){
gotoxy(3,1); cout<<"Score:"<<score;
}
void snake()
{
system("cls");
cout<<"t\t\t\t\t\t"<<"GAME OVER!!!"<<endl;
}
void pointr()
{
Beep(3000,3000);
Sleep(3000);
}

int main()
{   int i=0,o=1;

    for(int t=0;t<o;t++)
    {
    	system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t"<<"GAME MENU"<<endl;
    cout<<"\n";
    cout<<"\t\t\t\t\t\t"<<"1.START THE GAME"<<endl;
    cout<<"\t\t\t\t\t\t"<<"2.CONTROLLER"<<endl;
    cout<<"\t\t\t\t\t\t"<<"3.CREATOR"<<endl;
    cout<<"\t\t\t\t\t\t"<<"4.QUIT"<<endl;
    cout<<"\t\t\t\t\t\t";  cin>>in;
    if(in==2)
{
     system("cls");

	cout<<"\t\t\t\t\t\t"<<"CONTROLLER"<<endl;
	cout<<"\n\n";
	cout<<"\t\t\t\t"<<"ACTION"<<"\t\t\t\t"<<"KEY"<<endl;
	cout<<"\n";
	cout<<"\t\t\t\t"<<"MOVE UP"<<"\t\t\t\t"<<"UP"<<endl;
	cout<<"\t\t\t\t"<<"MOVE DOWN"<<"\t\t\t"<<"DOWN"<<endl;
	cout<<"\t\t\t\t"<<"MOVE RIGHT"<<"\t\t\t"<<"RIGHT"<<endl;
	cout<<"\t\t\t\t"<<"MOVE LEFT"<<"\t\t\t"<<"LEFT"<<endl;
	cout<<"\n\n\n\n\n";

}

if(in==3)
{   system("cls");
	cout<<"\t\t\t\t\t\t"<<"CREDITS:"<<endl;
	cout<<"\t\t\t\t\t\t"<<"//CODE WRITER//"<<endl;
	cout<<"\t\t\t\t\t\t"<<"Dr. MD WASIF REZA sir"<<endl;
}
if(in==1)
{
	break;
}
if(in==4)
{
	exit(0);
}
cout<<"ENTER ANY NUMBER TO RETURN MAIN MENU:";
cin>>i;
o=i+o;
if(in==1)
{
	break;
}

}

	if(in==1)
    {
    system("cls");
    cout<<"\n\n\\n\n\n";
    cout<<"\t\t\t\t\t\t"<<"DIFFICULTY"<<endl;
    cout<<"\n";
    cout<<"\t\t\t\t\t\t"<<"1.EASY"<<endl;
    cout<<"\t\t\t\t\t\t"<<"2.MEDIUM"<<endl;
    cout<<"\t\t\t\t\t\t"<<"3.HARD"<<endl;
    cin>>p;
    if(p==1||p==2||p==3)
  {
    system("cls");
    print();
    gotoxy(xc,yc); cout<<254;
   while(charc!=ESC && game_over()){
   	dell_body();
   	put_position();
   	image_body();
   	food();
   	dot();
   chan_speed();
    teclear();
    teclear();

   if(dir == 1) y--;
   if(dir == 2) y++;
   if(dir == 3) x++;
   if(dir == 4) x--;




     if(p==1)
     {

   	Sleep(150);
	}
    if(p==2)
    {
	Sleep(100);
    }
   if(p==3)
   {
	Sleep(50);
   }
   }
   }

	print();
	pointr();

	system("pause>null");

	return 0;
}


}

