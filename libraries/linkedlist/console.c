#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"

typedef struct _user{
  char *name;
  int age;
}User;

#define UCOUNT 5

int getChoice();

User users[UCOUNT];

void setupUsers(){
  users[0].name = "User1";
  users[0].age = 11;
  users[1].name = "User2";
  users[1].age = 22;
  users[2].name = "User3";
  users[2].age = 33;
  users[3].name = "User4";
  users[3].age = 44;
  users[4].name = "User5";
  users[4].age = 55;
}

void showUsers(){
  printf("\n%s\n\n", "======== Users ========");
  for(int i = 0; i < UCOUNT; i++){
    printf("User %d: %s age %d\n", i+1, users[i].name, users[i].age);
  } 
}

User *chooseUser(){
  int unumber;
  showUsers();
  unumber = getChoice();
  return &users[(unumber - 1)];
}

void print(LLptr pLL){
  printf("\n---- printing structure, length is %d ----\n\n", LLGetLength(pLL));
  LLResetList(pLL);
    
  while(LLHasNext(pLL)){
    User *u = LLGetNext(pLL);
    printf("%s\n", u -> name);
  }
}

#define TRUE 1
#define FALSE 0

int inputDone(char *buf){
 
  for(int i = 0; i < sizeof(buf); i++){
    if( *(buf + i) == '\n'){
      return TRUE;
    }
  }
  return FALSE;
}

int getChoice(){

  int BUFSIZE = 4;
  char buffer[BUFSIZE];
  int count = 0, choice = 0;

  while(count == 0 || count == EOF || choice < 0){

    printf("%s", "Input an integer >> ");
    fflush(stdout);
    
    if(NULL != fgets(buffer, BUFSIZE, stdin)){
      count = sscanf(buffer, "%d", &choice);
      if(inputDone(buffer) == FALSE){
	while(getchar() != '\n');
      }
    }
  }

  return choice;
}

int main(int argc, char **argv){
 
  List list = LLCreate();
  Stack stack = SCreate();
  Queue queue = QCreate();
  User *usr;

  setupUsers();
  MENU_CHOICE m_choice = MAIN_MENU;
  int choice, count;
  menu();

  choice = getChoice();
  
  while(choice){
    switch(m_choice){
    case MAIN_MENU:
      switch(choice){
      case 1:
	m_choice = LL_MENU; 
	llmenu();
	break;
      case 2:
	m_choice = QUEUE_MENU;
	qmenu();
	break;
      case 3:
	m_choice = STACK_MENU;
	smenu();
	break;
      case 4:
	showUsers();
        menu();
	break;
      case 0:
	exit(0);
	break;
      default:
	m_choice = MAIN_MENU;
	menu();
      }
      break;
    case LL_MENU:
      switch(choice){
      case 1:
	printf("\n%s\n", "adding head, choose a user");
        usr = chooseUser();
        printf("%s %s\n", "You chose ", usr -> name);
        LLAddHead(usr, list);
        llmenu();
	break;
      case 2:
	printf("\n%s\n", "adding tail, choose a user");
        usr = chooseUser();
        printf("%s %s\n", "You chose", usr -> name);
        LLAddTail(usr, list);
        llmenu();
	break;
      case 3:
	printf("\n%s\n", "removing head");
        LLRemoveHead(list);
        llmenu();
	break;
      case 4:
	printf("\n%s\n", "removing tail");
        LLRemoveTail(list);
        llmenu();
	break;
      case 5:
        print(list);
        llmenu();
	break;
      case 6:
        m_choice = MAIN_MENU;
	menu();
	break;
      case 0:
	exit(0);
	break;
      default:
	m_choice = LL_MENU;
      }
      break;
    case QUEUE_MENU:
      switch(choice){
      case 1:
        printf("\n%s\n", "enqueueing, choose a user");
        usr = chooseUser();
        printf("%s %s\n", "You chose ", usr -> name);
        Qenqueue(usr, queue);
        qmenu();
	break;
      case 2:
	printf("\n%s\n", "dequeueing");
        Qdequeue(queue);
        qmenu();
	break;
      case 3:
	print(queue);
        qmenu();
	break;
      case 4:
        m_choice = MAIN_MENU;
	menu();
	break;
      case 0:
	exit(0);
	break;
      default:
	m_choice = QUEUE_MENU;
      }
      break;
    case STACK_MENU:
      switch(choice){
      case 1:
	printf("%s\n", "push");
        smenu();
	break;
      case 2:
	printf("%s\n", "pop");
        smenu();
	break;
      case 3:
	printf("%s\n", "top");
        smenu();
	break;
      case 4:
	printf("%s\n", "print");
        smenu();
	break;
      case 5:
        m_choice = MAIN_MENU;
	menu();
	break;
      case 0:
	exit(0);
	break;
      default:
	m_choice = STACK_MENU;
      }
      break;
    } 
    choice = getChoice();
  }

  return 0;   
}
