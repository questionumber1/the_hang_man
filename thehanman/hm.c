// to make it case insensitive .. subtract  32 or add 32 based on which case has been entered as use that as key

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define size 123
char s[size];
int count=0;
void disp();
/* displays the name with the discovered letters */

void upd_arr()
{

    printf("\n\n");
  for(int i=0;i<strlen(s);i++)
  {
    printf(" %c ",s[i]);
  }
    printf("\n\n");
}

struct node
{
  char data;
  int pos;                    // pos is used to identify the position of the letter in the original string
  struct node* next;
};
 struct node *head=NULL,*temp=NULL,*newnode=NULL,*arr[size],*dis;

void init()                  // setting our hash map to null
{
  for(int i=0;i<size;i++)
  {
    arr[i]=NULL;
  }
}
void display(struct node *head)
{
  dis=head;
  while(dis!=NULL)
  {
    printf("\n [%c] --> [%d]",dis->data,dis->pos);
    dis=dis->next;
  }
}


 void addnode( char val,int pos)
 {
newnode=(struct node*)malloc(sizeof(struct node));
newnode->next=NULL;
int key=(int)(val);
newnode->data=key;
newnode->pos=pos;
if(arr[key]==NULL)                             // if array key is null ( which it always is in the beginning ) and our list grows as we add letters
{
  arr[key]=newnode;
//  display(arr[key]);
}
else
{
  temp=arr[key];                            // list id growing here
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newnode;
  //display(arr[key]);
}
}

struct node* find_val(char val)
{
//printf(" \n in find_val \n ");
  int key=(int)(val);
  if(arr[key]==NULL)
  {
  //  printf("not found");
    return -1;
  }
  else
{
    temp=arr[key];
    //int i=0;
    while (temp!=NULL)
    {
      count--;
       s[temp->pos]=(char)(temp->data);
        temp=temp->next;

    }
}
    arr[key]=NULL;
    return 0;
    upd_arr();
}


void insert()             //inserts all the letters into the hashmap .. we can discard the original array that the string was read into
{                         // since we know the letters & their locations
printf("\n                                                            enter the string\n ");
gets(s);

for(int i=0;i<strlen(s);i++)
{
addnode(s[i],i);
if(s[i]!=' ')
{
count++;
}
}
printf("\n");
for(int i=0;i<strlen(s);i++)
{
    if(s[i]==' ')
    {
        s[i]=' \| ';
    }
    else
        s[i]=' _';
}
//upd_arr();
disp();
}

void disp()
{
  int wrong=5;
   char leter;
   int ret_code;
   system("clear");
    while(wrong>0 && count >0)
   {

       for(int cnt=0;cnt<wrong;cnt++)
       {

           printf("[X] ");
       }
      printf("\n");
      upd_arr();

printf("enter the leter  ----> ");
leter=getchar();
//fflush(stdin);
while ((getchar()) != '\n');       // this is to ensure that an additional \n is not sent as the next input

int ret_code=(int)(find_val(leter));
if(ret_code==-1)
{
--wrong;
}
system("clear");
}
if(wrong > 0)
printf("\n                                                            YOU WIN ");
else
printf("                                                            GAME OVER");
}


int main(){
insert();
}
