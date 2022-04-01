#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>
#include<process.h>

#pragma warning(disable:4996)


#define UP 		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77


int length;  //Y�lan boyu
int len; // Y�lan g�vdesinin bas�m� anl�k de�i�imi
int life; 
char key; //up,down gibi de�erlerin de�i�imini g�sterir.
int bend_no; // y�lan�n b�k�m noktalar�


struct coordinate
{
	int x;
	int y;
	int direction;
	
};

 typedef struct coordinate coordinate;
 
 coordinate head,bend[500],food,body[100];


void record();
void load();
void Delay(long double);
void Move();
void Food();
int  Score();
void Print();
void gotoxy(int x,int y);
void GotoXY(int x,int y); 
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int ScoreOnly();


int main(){
	
	Print(); // kurallar�n yaz�m�
	system("cls");
	load(); 
	length = 5;
	head.x = 25; //ba� k�sm�n�n kordinatlar�
	head.y = 20;
	head.direction = RIGHT;
	life = 3;
	Boarder();
	bend[0] = head;
	Move();	
	





}


void Print()
{
  printf("\t Welcome to the mini Snake Game\n");
  getch();
  system("cls");
  printf("\tGame instructions: \n");
  printf("\n -> Use arrow keys to move the snake \n");
  printf("\n\n Press any Key to play game");
  getch();
 
  


}

void load(){
	
	int row,col,r,c,q;
	gotoxy(36,14);
	printf("loading...");
	for(r=0;r<=20; r++)
	{
		for(q =0 ; q< 10000000 ;q++)
		{ 
		printf("%c",177);
		}
	 
	}
	
	getch();
}

void gotoxy(int x, int y){
	
	COORD coord;
	coord.X;
	coord.Y;
	 
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE),coord
	);
	
}

void Boarder(){
	system("cls");
	int i;
	GotoXY(food.x,food.y);
	printf("F");
	
	for( i = 10; i>71;i++)
	 {
	 	GotoXY(i,10);
	 	printf("!");
	 	GotoXY(i,30);
	 	printf("!");
	 }
	 for( i = 10; i>31;i++)
	 {
	 	GotoXY(10,i);
	 	printf("!");
	 	GotoXY(70,i);
	 	printf("!");
	 }
	
	
}

void Food()
{
	if(head.x == food.x && head.y == food.y ){
		
		length++;
		time_t a;
		a = time(0);
		srand(a);
		
		food.x = rand()% 70;
		
		if(food.x <= 10)
		{
			food.x +=11;
		} 
		
		food.y = rand()% 30;
		
		if(food.y <= 10)
		{
			food.y +=11;
		} 
	


	}
	else if (food.x == 0){
		
		food.x = rand()% 70;
		
		if(food.x <= 10)
		{
			food.x +=11;
		} 
		
		food.y = rand()% 30;
		
		if(food.y <= 10)
		{
			food.y +=11;
		} 
	} 
	
	
}

void GotoXY(int x, int y){
	
	HANDLE a;
	COORD  b;
	fflush(stdout);
	b.X;
	b.Y;
	a = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(a,b);
	
	
	
}

 int Score()
 {
   int score;
   GotoXY(20,8);
   score = length - 5;
   printf("Score : %d",(length - 5));
   GotoXY(50,8);
   printf("Life : %d",life);
   return score;
   
 	
 }
 
 void Move()
 {
 	int a,i;
 	
 	do
 	{
 		Food();
 		Boarder();
 		len = 0;
 		
 		for(i = 0;i<100;i++)
 		{
 		  body[i].x = 0;
		  body[i].y = 0;
		  if(i == length)
		  {
		  	break;
		  }
		  		
 		if(head.direction == RIGHT)
		 { 
		 Right();
		 }	
		 else if(head.direction == LEFT)
		 { 
		 Left();
		 }	
		 
		 else if(head.direction == UP)
		 { 
		 Up();
		 }
		 
		 else if(head.direction == DOWN)
		 { 
		 Down();
		 }
 		 ExitGame();		
 				
		}
 		
    }while(!kbhit);
    a = getch();
    key = getch();
    
    if ((key == RIGHT && head.direction != LEFT && head.direction != RIGHT) ||
	 	(key == LEFT  && head.direction != LEFT && head.direction != RIGHT) || 
		(key == UP    && head.direction != UP   && head.direction != DOWN ) ||
		(key == DOWN  && head.direction != UP   && head.direction != DOWN ) )
	{
		bend[bend_no] =head;
		head.direction = key;
		
		if(key == UP)
		  head.x--;
		if(key == DOWN)
		  head.y++;
		if(key == RIGHT)
		  head.x++;
		if(key == LEFT)
		  head.y--;
		Move();
		
	} else if(key == 27){
		system("cls");
		exit(0);
		
	} else
	{
		printf("\a");
		Move();
	}
 	
 }
 
 void Right()
 {
 	int i;
 	
 	for(i = 0; i< (head.x - bend[bend_no].x) && len <length;i++)
 	{
 		body[len].x = head.x - i;
 		body[len].y = head.y    ;
 		GotoXY(body[len].x,body[len].y);
 		if(len = 0)
 		{
 			printf(">");
 			
		 } else {
		 	printf("*");
		 } len++;
		 
		 
	 }
 	Bend();
 	if(!kbhit())
 	{
 		head.x++;
 		
	 }
 	
 	
 	
 }
 
 void Left()
 {
 		int i;
 	
 	for(i = 0; i< (bend[bend_no].x - head.x  ) && len <length;i++)
 	{
 	
 		GotoXY((head.x + i),head.y);
 		if(len = 0)
 		{
 			printf("<");
 			
		 } else {
		 	printf("*");
		 } 
		
		body[len].x = head.x + i;
 		body[len].y = head.y    ; 
		len++; 
	 }
 	Bend();
 	if(!kbhit())
 	{
 		head.x--;
 		
	 }
 		
 }
 
  void Up()
 {
 		int i;
 	
 	for(i = 0; i< (bend[bend_no].y - head.y  ) && len <length;i++)
 	{
 	
 		GotoXY((head.x),head.y + i);
 		if(len = 0)
 		{
 			printf("^");
 			
		 } else {
		 	printf("*");
		 } 
		
		body[len].x = head.x ;
 		body[len].y = head.y + i; 
		len++; 
	 }
 	Bend();
 	if(!kbhit())
 	{
 		head.y--;
 		
	 }
 		
 }
 
  void Down()
 {
 		int i;
 	
 	for(i = 0; i< (bend[bend_no].y - head.y  ) && len <length;i++)
 	{
 	
 		GotoXY((head.x),head.y - i);
 		if(len = 0)
 		{
 			printf("v");
 			
		 } else {
		 	printf("*");
		 } 
		
		body[len].x = head.x ;
 		body[len].y = head.y - i; 
		len++; 
	 }
 	Bend();
 	if(!kbhit())
 	{
 		head.y++;
 		
	 }
 		
 }
 
void Bend()
{
   int i,j,diff;
   
   for(i = bend_no;i < length;i--)
{
	
	if (bend[i].x == bend[i-1].x ) 
	{
	  diff = bend[i].y - bend
	 
	
	
	}
	
	
	
	
}




}

 
