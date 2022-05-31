/* Структура данных список LIST для начала самый простой открытый однонаправленный*/

/*data structure LIST to start with the simplest open unidirectional*/


#include <iostream>

using namespace std;

class ListNode
{
  public:
  int Value; 
  ListNode *next;
  ListNode(int _Value)
  {
    Value=_Value;
    next=nullptr;
  }
};


class List
{
  public:
  ListNode *First = nullptr;
  
  void insert(int newValue)// insert back
  {
    ListNode *Temp= new ListNode(newValue);

    if (First==nullptr)
    {
      First = Temp;
    }
    else
    {
      ListNode *Current=First;
      ListNode *Temp= new ListNode(newValue);

      while(Current->next!=nullptr)
      {
        Current=Current->next;
      }
      Current->next=Temp;
    }
  }

  void insert_front(int newValue)// insert in front of list
  {
    ListNode *Temp= new ListNode(newValue);

    if (First==nullptr)
    {
      First = Temp;
    }
    else
    {
      ListNode *Current=First;
      Temp->next=Current;
      First=Temp;
      
    }
     
  }


  void Vvod()
  {
    int val_add;
    cout<<"Enter Value of LIST: "<<endl;

    while(true)
    {
      cin>>val_add;
      if(val_add==999)
      {
        cout<<"end of LIST."<<endl;
        break;
      }
      else
      {
        insert(val_add);
      }
    }
  }


  void Print() //print list
  {
    cout<<"your LIST:"<<endl;

    if (First == nullptr)
    {
      return;
    }
    else
    {
      ListNode *Current=First;

      while(Current->next!=nullptr)
      {
        cout<<Current->Value<<endl;
        Current=Current->next;
        
      }
      cout<<Current->Value<<endl;
    }
  }
  

  void Cearch_L()  //find all matches
  {
    int CeaValue;
    int i=1;
    cout<<"Search iteam is: ";  cin>>CeaValue;  cout<<endl;
    ListNode *Current=First;

    while(true)
    {
      if(Current->next->Value==CeaValue)
      {
        cout<<"Value before: "<<Current->Value<<endl;
        cout<<"search results: "<<Current->next->Value<<endl;

        if(Current->next==nullptr)
        {
          break;
        }

        cout<<"next value: "<<Current->next->next->Value<<endl;
        cout<<"match: "<<i<<endl<<endl;i++;
      }
      Current=Current->next;

      if (Current->next==nullptr)
      {
        break;
      }
    }
  }


  void Search_First_L() //finding the first match
  {
    int CeaValue;
    cout<<"Search iteam is: ";  cin>>CeaValue;  cout<<endl;
    ListNode *Current=First;
    
    while(Current->next->Value!=CeaValue)
      {
        Current=Current->next;
      }
    cout<<"Value before: "<<Current->Value<<endl;
    cout<<"search results: "<<Current->next->Value<<endl;
    Current=Current->next;
    cout<<"next value: "<<Current->next->Value<<endl;
  }


  void e(int i) //element output by index
  {
    int j=0;
    ListNode *Current=First;

    while(true)
    {
      if(j==i)
      {
        cout<<endl<<"element by index"<<i<<" = "<<Current->Value<<endl;
        break;
      }
      else
      {
        Current=Current->next;
        j++;
      }
    }
  }


  void e_i() //element output by index from stream
  {
    int input=0; cout<<endl<<endl<<"enter item number: "; 
    cin>>input;  
    cout<<endl<<endl;
    e(input);
  }


  void remove_F() //remove the first element
  {
    ListNode *Current=First;
    First=Current->next;
    delete Current;

    cout<<endl<<"first element was deleted"<<endl;
  }


  void remove_La() //delete last element
  {
    ListNode *Current=First;

    while(true)
    {
      if (Current->next->next==nullptr)
      {
        Current->next=nullptr;
        break;
      }
      Current=Current->next;
    }
    cout<<endl<<"last element was deleted"<<endl;
  }


  //deleting an element by value
  void del(int del_elem)
  {
    ListNode *Current=First;

    if(Current->Value==del_elem){remove_F();}
    else 
    {
      while(true)
      {
      if (Current->next->next==nullptr)
      {
        Current->next=nullptr;
        break;
      }
        else
        {
          if(Current->next->Value==del_elem)
          {
            Current->next=Current->next->next;
            break;
          }
        }
        Current=Current->next;

      }
    }
    cout<<endl<<"element"<<del_elem<<"was deleted"<<endl;
  }
  

  void Standart()
  {
    Vvod();
    printf("\e[1;1H\e[2J");
    Print();
  }
};

int main() 
{
List a;
a.Standart();
//a.Print();
//a.remove_La();
a.insert_front(5);
//a.Print();
//a.e(2);   //вывод 4-го элемента
//a.e_i();    //вывод произвольного эл-та
//a.Cearch_L();   //поиск всех совпадений
//a.Search_First_L();   //поиск 1-го совпадения
//a.remove_F();//удаляет 1-й эл-т
a.Print();
}
