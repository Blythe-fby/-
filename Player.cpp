class Player1:public Block{
	int id1;//玩家A当前的图形id 
	int next_id1;//玩家A的下一个图形id 
	int t1; 
	public:
		int play1[20][10];
		void update();//不断更新绘制A画布 
		void newblock();//生成新的方块 
		void nextblock();//生成下一个方块 
		void getfunA();//获取A玩家的操作 
		void carry();
		
};

void Player1::carry()
{
	newblock();
	update();
	while(isDown_collide()&&isDown())
	{
		fall();	
		Sleep(300);
		getfunA();
		int m=Fix();
		del();	
		update();
		if(!m) break; 
	}	
	
}
void Player1::update(){
	int x,y;
	for(x=0;x<20;x++){
		for(y=0;y<10;y++){
			if(ground->background[x][y]==1||ground->background[x][y]==2){
				gotoxy(2*y+12,x+5);
				cout<<"■";
			}
			if(ground->background[x][y]==0){
				gotoxy(2*y+12,x+5);
				cout<<"  ";
			}
		}
	}
}
void Player1::newblock(){
	int type;
	int x;
	int i;
	type=rand()%5;
	if(type==0){//田字格 
		ground->background[0][4]=1;ground->background[0][5]=1;
		ground->background[1][4]=1;ground->background[1][5]=1;
	}
	if(type==1){//长条形 
		for(i=3;i<7;i++)
			ground->background[0][i]=1;
	}
	if(type==2){//T型
		ground->background[0][3]=1;ground->background[0][4]=1;ground->background[0][5]=1;
		ground->background[1][4]=1;
	}
	if(type==3){//L型 
		ground->background[0][3]=1;ground->background[0][4]=1;ground->background[0][5]=1;
		ground->background[1][5]=1;
	}
	if(type==4){//Z型 
		ground->background[0][4]=1;ground->background[0][5]=1;
		ground->background[1][5]=1;ground->background[1][6]=1;
	}
}
void Player2::newblock(){
	int type;
	int i;
	type=rand()%5;
	if(type==0){//田字格 
		play2[0][4]=1;play2[0][5]=1;
		play2[1][4]=1;play2[1][5]=1;
	}
	if(type==1){//长条形 
		for(i=3;i<7;i++)
			play2[0][i]=1;
	}
	if(type==2){//T型 
		play2[0][3]=1;play2[0][4]=1;play2[0][5]=1;
		play2[1][4]=1;
	}
	if(type==3){//L型 
		play2[0][3]=1;play2[0][4]=1;play2[0][5]=1;
		play2[1][5]=1;
	}
	if(type==4){//Z型 
		play2[0][4]=1;play2[0][5]=1;
		play2[1][5]=1;play2[1][6]=1;
	}
}
void Player1::getfunA(){
	
	char c;
	if(c=_getch()){
		
		//if(c=='w')
		
	if(c=='a')
		if(isLeft()&&isLeft_collide())		
			MoveLeft();		
	if(c=='s')
		fall();
	if(c=='d')
		if(isRight()&&isRight_collide())
			MoveRight();
	} 
	
}
	
int main(){
	game control;
	control.welcome();
	control.drawborder();
	Player1 a;
	int i,j;
	
	while(1)
	{
		a.carry();
	}
	
	cout<<endl;
	return 0;
}
