#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
//#include "conio.h"
class node {
   friend class linkedList;
   private:
       char name[30] ;
       float component[100];
       float name2;
       int stno;
       int unit ;
       node *next;
};
class linkedList {
   public:
      linkedList();
      ~linkedList();
      void enter ();
      void display ();
      void delNode ();
      void member();
   private:
      node *first;
      node *last;
};
int no;
//***************
linkedList::linkedList()
{
  first = last = NULL;
}
//***************
linkedList::~linkedList()
{
  node *curPtr = first;
  node *temp;
  while(curPtr)
  {
     temp = curPtr;
     delete temp;
     curPtr = curPtr -> next;
  }
}
//***************
void linkedList::enter()
{
   node *help;
   help = new node;
   help -> next = first;
   if (first == NULL)
       first = last = help ;
   else
   {
	last -> next = help;
	last = help;
	help->next=first;
   }
   std::cout << "Add a name to the list :";
   std::cin>>last->name;
   no++;
 }

//********************
void linkedList::display()
{
   node *h;

   if (first == NULL) {
      std::cout << "List is empty .";
      getchar() ;
      return;
   }
   h = first ;
  // clrscr() ;


  std::cout<< "{" ;
   do {
   //	   std::cout << h -> name;
   std::cout<<h->name;
      h = h -> next ;
      std::cout<<",";
      } while (h != first) ;
      std::cout<<"}";

      std::cout<< "\n" ;
      std::cout<< "\n" ;
      std::cout << "**********************" ;
      std::cout<< "\n" ;
      std::cout << "***************" ;

      std::cout<< "\n " ;
      std::cout << "Press a key to continue.";
      getchar() ;

}
//*****************
void linkedList::member()
{
   std::cout<< "\n";
   std::cout<< " Membrs of the list are  == " << no << "  " <<" members ";
   getchar();

}
void linkedList::delNode()
{
     node *h, *p;
    char st[10] ;
    if(!first)
    {
       std::cout << "List is empty.";
       getchar();
       return;
    }
    std::cout << "Enter a number to delete:";
    std::cin >> st ;
    h = p = first ;
    while (h != first)
    {
       if (h -> name != st)
       {
	  p = h ;
	  h = h -> next ;
	  continue ;
       }
       else {  //remove from start
	if (h == first) {
	    first = h -> next ;
	    delete h ;
	    delete p ;
	    break ;
	 }//end of if
	 else  {
	     if(h == last)
		 last = p;
	     p -> next = h -> next;
	     delete h ;
	     break ;
	 }//end of else
     }//end of else
    }//end of while
}
//****************
int menu();
//****************
int main ()
{
    linkedList list;
    while (1)
    {
       //clrscr() ;
    switch (menu())
       {
	   case 1:
	       list.enter() ;
	       break ;
	   case 2:
	       list.delNode() ;
	       break ;
	   case 3:
	       list.display() ;
	       break ;
	   case 4:
		list.member();
		break;

	   case 5:
	       exit(0) ;
     }//end of switch
   } //end of while
} // end of main
//********************
int menu()
{
   char c[5];
  // int y,x=(1,9);
  // y=random(x);
  // textcolor(y);
  std::cout<< "memebers of the list must be more than 1 " ;
  std::cout<< "\n" ;

  std::cout<< "<><><><><><><><><><><><><><><> " ;
  std::cout<< "\n" ;
  std::cout<< "==============================" ;
  std::cout<< "\n" ;
  std::cout<< "\n" ;
  std::cout<< "\n" ;
  std::cout << "1.Enter a member to the list\n";
  std::cout << "2.Remove a member from the list\n";
  std::cout << "3.Print the list\n";
  std::cout << "4.Number of members :\n";
  std::cout << "5.Exit\n";
  std::cout << "Select an option(1-5):";
  std::cin.getline(c, 5);
  return atoi(c);
}
