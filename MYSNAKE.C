#include<stdio.h>
#include<conio.h>
#include<stdlib.h>		//for random function
#include<string.h>
void printsnake(char);             //for printing snake
void printfood();                  //for printing the food
void border();                     //for creating the boundary of the shell
void check();               //for checking if snake reached the food or not
void generatefood();	  //generates the food
void menu();
void loading();
void askname();
void lastscreen();
struct cnate{
int x,y;
}head,food,tail[80];
int score=0,len=0,number=0;
char name[20];
void main()
{
char c;
head.x=13;                   // x coordinate of the head of snake
head.y=12;                   // y coordinate of the head of snake
clrscr();
menu();
clrscr();
loading();
border();
gotoxy((head.x),head.y);
printf(">");
generatefood();
printfood();
while(1)
{
printsnake(c);
printfood();
c=getch();
clrscr();
border();

if(c=='d'||c=='D')
{
head.x++;
check();
for(number=1;number<=len;number++)
{
tail[number].x=((head.x)-number);    //tail is behind the head by tail[number]
}
for(number=1;number<=len;number++)
{
tail[number].y=head.y;               //setting up the coordinates
}
}
else if(c=='w'||c=='W')
{
head.y--;
check();
for(number=1;number<=len;number++)
{
tail[number].y=((head.y)+number);      //tail is below the head by tail[number]
}
for(number=1;number<=len;number++)
{
tail[number].x=head.x;
}
}
else if(c=='a'||c=='A')
{
head.x--;
check();
for(number=1;number<=len;number++)
{
tail[number].x=((head.x)+number);      //tail is behind the head by tail[number]
}
for(number=1;number<=len;number++)
{
tail[number].y=head.y;
}
}
else if(c=='s'||c=='S')
{
head.y++;
check();
for(number=1;number<=len;number++)
{
tail[number].y=((head.y)-number);        //tail is above the head by tail[number]
}
for(number=1;number<=len;number++)
{
tail[number].x=head.x;
}
}
else if(c==13||c==27)
{
lastscreen();
clrscr();
gotoxy(35,11);
printf("GAME OVER");
getch();
exit(2);
}
}
}

void printfood()
{
gotoxy(food.x,food.y);
printf("F");
}

void generatefood()
{
do{
food.x=random(74);
}while(food.x==0||food.x<10); //food created must be within the boundary
do{
food.y=random(25);
}while(food.y==0||food.y<3);
}

void border()
{
int i,j;
gotoxy(5,1);
printf("Player :%s",name);
gotoxy(64,1);
printf("Score :%d",score);	   //prints the score

for(i=3,j=2;i<=78;i++,j++)
{
gotoxy(3,j);
printf("!");
gotoxy(78,j);
printf("!");                        //prints the border
gotoxy(i,2);
printf("!");
gotoxy(i,25);
if(i==77||i==78)
continue;
printf("!");
}
}

void printsnake(char c)
{
gotoxy(head.x,head.y);
if(c=='d'||c=='D')
printf(">");
else if(c=='a'||c=='A')
printf("<");
else if(c=='w'||c=='W')
printf("^");
else if(c=='s'||c=='S')
printf("v");
for(number=1;number<=len;number++)
{
gotoxy(tail[number].x,tail[number].y);
if(c=='d'||c=='a'||c=='D'||c=='A')
printf("-");
else if(c=='w'||c=='s'||c=='W'||c=='S')
printf("|");
}
}

void check()
{
if((head.x==food.x)&&(head.y==food.y))
{
score++;
len++;             //increases the length and score if snake eats the food
generatefood();
printf("\a");
}

if(head.x==3||head.x==78||head.y==2||head.y==25)
{
printf("\a");
lastscreen();
clrscr();
gotoxy(35,11);
printf("GAME OVER");
getch();
exit(1);
}
}
void menu()
{
gotoxy(9,11);
printf("\tWelcome to the Snake game.(press any key to continue)\n");
getch();
askname();
clrscr();
printf("\tGame instructions:\n");
printf("\n-> Use W,A,S,D to move the snake.\n\n");
printf("-> You will be provided food within the walls which you have to eat.");
printf("Every time\n   you eat a food,the length of the snake will be increased by 1 and thus the  \n   score.\n\n");
printf("-> The game will end if you hit the walls.\n\n");
printf("-> You can exit the game anytime by pressing ENTER or ESC.\n\n");
printf("-> If you want to exit press esc\n");
printf("\n\n\n\n\t\t\tPress any key to play game...");
gotoxy(60,23);

if(getch()==27)
exit(0);
}
void loading()
{
int i=0;
clrscr();
gotoxy(1,24);
printf("Loading....");
for(i=1;i<=80;i++)
{
delay(100);
gotoxy(i,25);
printf("%c",177);
}
clrscr();
}
void askname()
{

clrscr();
gotoxy(25,11);
printf("Enter your name :");
scanf("%s",name);
}
void lastscreen()
{
int i=0;
clrscr();
gotoxy(25,11);
printf("     ");
while(name[i]!='\0')
printf("%c",toupper(name[i++]));

printf(",Your score is %d",score);
gotoxy(34,12);
printf("Well Played%c",1);
gotoxy(60,20);
printf("DEVELOPED BY :");
gotoxy(60,21);
printf("VIPUL SRIVASTAVA");
gotoxy(60,22);
printf("14/CS/57,JSSATEN");
getch();
}