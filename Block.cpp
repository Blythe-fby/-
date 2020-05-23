#include<iostream>
#include<time.h>
#include<windows.h>
#include <ctime>
using namespace std;

class backg
{
public:
	backg(void);
	int addmarkA(int num);//玩家A满行加分 
	int addmarkB(int num);
public:
	int background[20][10];
private:
	int markA,markB;//计分 

};
backg *ground = new backg;
backg::backg()//构造函数初始化背景
{
	for(int i =0;i<20;i++)//边框行数为20 
		for(int j=0;j<10;j++)//边框列数为10 
			background[i][j]=0;//初始化无方块的空白背景为0 
	markA=0;
	markB=0;
}
int backg::addmarkA(int num)
{
	return this->markA=this->markA+num;
}
int backg::addmarkB(int num)
{
	return this->markB=this->markB+num;
}
class Block{
	public:
		void fall();//&方块下落函数 
		void MoveLeft();//&方块左移函数  
		void MoveRight();//&方块右移函数 
		void Fix();//固定函数 
		void Dchange();//&方块旋转函数 
		bool isDown();
		bool isDown_collide();
		bool isLeft();//左右边框判断 
		bool isRight();
		bool isLeft_collide();//左右碰撞判断	
		bool isRright_collide();	
		bool isFull(int a);//&满行判断 
		void del();//&消行函数 
	protected:
		POINT point[8];//记录方块坐标  用于画图* 
		int block[2][4]; //记录方块状态* 
		int num ;
};

bool Block::isDown()//是否接触到框下边 
{
	for(int i=0;i<10;i++)
		if(1==ground->background[19][i])
			return false;
	return true;
}

bool Block::isLeft()//是否接触到框右边 
{
	for(int i=0;i<20;i++)	
		if(1==ground->background[i][0])
			return false;			
	return true;
}

bool Block::isRight()//是否接触到框右边 
{
	for(int i=0;i<20;i++)	
		if(1==ground->background[i][11])		
			return false;			
	return true;
}

bool Block::isDown_collide()//下落障碍碰撞* 
{
	for(int i=19;i>=0;i--)
		for(int j=0;j<10;j++)		
			if(1==ground->background[i][j])			
				if(2==ground->background[i+1][j])
				//&若下落方块（1）下面那行是2（固定方块）则碰撞不能下落
					return false;								
	return true;
}

bool Block::isLeft_collide()//左移障碍碰撞* 
{
	for(int i=0;i<20;i++)	
		for(int j=0;j<10;j++)		
			if(1==ground->background[i][j])			
				if(2==ground->background[i][j-1]) 				
					return false;
					//&任一个移动方块（1）左边的方块为固定方块（2）									
	return true;
}

bool Block::isRright_collide()//右移障碍碰撞* 
{
	for(int i=0;i<20;i++)	
		for(int j=9;j>=0;j--)		
			if(1==ground->background[i][j])			
				if(2==ground->background[i][j+1])				
					return false;//&同理 										
	return true;
}
 
void Block::fall()//下落*
{
	for(int i=0;i<sizeof(point)/sizeof(POINT); i++)
	{
		point[i].y +=20;
	}
	for(int i=19;i>=0;i--)
	{
		for(int j=0;j<10;j++)
		{
			if(1==ground->background[i][j])
			{
				ground->background[i+1][j]=ground->background[i][j];//&使（1）方块下面的方块变为（1） 
				ground->background[i][j]=0;//&每次移动方块的下落是使（1）方块变为（0） 
			}
		}
	}
	//squareline++;
}

void Block::MoveLeft()//左移 
{
	for(int i=0;i<sizeof(point)/sizeof(POINT);i++)
	{
		point[i].x-=20;
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(1==ground->background[i][j])
			{
				ground->background[i][j-1]=ground->background[i][j];
				ground->background[i][j]=0;//&同理使左边的方块变为（1）原来为（1）的变为（0） 
			}
		}
	}	

	//squarelist--;

}
//右移* 
void Block::MoveRight()
{
	for(int i=0;i<sizeof(point)/sizeof(POINT);i++)
	{
		point[i].x+=20;
	}
	for(int i=0;i<20; i++)
	{
		for(int j=9;j>=0;j--)
		{
			if(1==ground->background[i][j])
			{
				ground->background[i][j+1]=ground->background[i][j];
				ground->background[i][j]=0;//&同上 
			}
		}
	}
	//squarelist++;
}
void Block::Fix()//固定函数 
{
	if(!isDown_collide()&&!isDown()) //两个下落判断函数都传回false 
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(1==ground->background[i][j])
				{
					ground->background[i][j]=2;//1>>2; 
					num = 0;// 
				}
			}
		}
	}
	
}
//判断是否满行* 
bool Block::isFull(int a)//&第a行是否满行 
{
	int n=0;
	for(int j=0;j<10;j++)
		if(ground->background[a][j]==2)
			n++;
	if(n==10)//&这行10个方块都是（2） 
	{
		ground->addmarkA(10);//&分数加10
		//给对方增加一随机行 
		return true;
	}
	return false;
}

void Block::del()//消行* 
{
	for(int i=0;i<20;i++)
	{
		if(isFull(i))//&第i行的满行函数return true时 
		{
			for(int n=i;n>=0;n--)			
				for(int j=0;j<10;j++)				
					ground->background[n][j] = ground->background[n-1][j];
				//&从第i行往上的每行都向下移一行 			
			for(int i2=0;i2<10;i2++)			
				ground->background[0][i2]=0; 			
		//&由于所有行都向下了，最上面缺一行所以补一行（0）
		}
	}
}
