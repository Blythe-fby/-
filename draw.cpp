#include<iostream>
#include<time.h>
#include<windows.h>
#include <ctime>
#include<conio.h>
using namespace std;
void setcolor(int num){
	int n;
	switch (num)
	{
	case 0: n = 0x0C; break;
	case 1: n = 0x08; break;
	case 2: n = 0x0E; break;
	case 3: n = 0x0D; break;
	case 4: n = 0x0A; break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
void gotoxy(int x, int y) {
	HANDLE hout;
	COORD coor;
	coor.X = x;
	coor.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coor);
}//控制光标位置的函数 
class draw{
	public:
		void drawborder();
};//渲染类 
void draw::drawborder(){
	int i;
	for(i=5;i<17;i++){
    	gotoxy(2*i,4);
    	cout<<"◇";
    	gotoxy(2*i,24);//注意这个符号是占两个空格的 
    	cout<<"◇";
  	}
  	for(i=5;i<24;i++){
  		gotoxy(10,i);
  		cout<<"◇";
  		gotoxy(32,i);//纵向只需要一个空格 
  		cout<<"◇";
	} 
	cout<<"\n\n\n\n\n";
	for(i=30;i<42;i++){
    	gotoxy(2*i,4);
    	cout<<"◇";
    	gotoxy(2*i,24);
    	cout<<"◇";
  	}
  	for(i=5;i<24;i++){
  		gotoxy(60,i);
  		cout<<"◇";
  		gotoxy(82,i);
  		cout<<"◇";
	} 
	cout<<"\n\n\n\n\n";//同理可以画出第二个框 
	gotoxy(18,27);
	cout<<"玩家A";
	gotoxy(16,28);
	cout<<"W:旋转方块";
	gotoxy(16,29);
	cout<<"S:加速下落";
	gotoxy(16,30);
	cout<<"A:左移方块";
	gotoxy(16,31);
	cout<<"D:右移方块";
	
	gotoxy(68,27);
	cout<<"玩家B";
	gotoxy(66,28);
	cout<<"↑:旋转方块";
	gotoxy(66,29);
	cout<<"↓:加速下落";
	gotoxy(66,30);
	cout<<"←:左移方块";
	gotoxy(66,31);
	cout<<"→:右移方块";
	
	gotoxy(42,10);
	cout<<"A分数："; 
	gotoxy(42,12);
	cout<<"B分数："; 
	gotoxy(40,15);
	cout<<"空格键暂停"; 
}
 

int main()
{
	draw a;
	a.drawborder();
	system("pause");
}
