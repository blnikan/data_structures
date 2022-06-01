#include <iostream>

#include <string>
/*
дерево в каждом узле которого- двусвязный список
в списке хранится string
*/
using namespace std;

class ListNode 
{
  public:

  string Value;
  ListNode *Next;
  ListNode *Prev;

    ListNode() 
    {
      Value = nullptr;
      Next = nullptr;
      Prev = Next;

    }
  ListNode(string Value_) 

  {
    Value = Value_;
    Next = nullptr;
      Prev = Next;
  }
};

class Double_List 
{
  private:
  ListNode *First;
  ListNode *Last;

  public:

    
    ListNode getFirst(){return *First;}
  
    void setFirst(ListNode *val_){First=val_;}

    ListNode getLast(){return *Last;}

    void setLast(ListNode *val_){Last=val_;}


    Double_List() 
    {
      First = nullptr;
      Last = First;

    }

    void insert_back(string newValue)
    {
      ListNode *Temp = new ListNode(newValue);
      

      if (Last == nullptr)
      {
        Last=Temp;
        First=Last;
      }
      else
      {
        ListNode  *Current = Last;

        Current->Next = Temp;
        Temp->Prev=Current;
        Last=Temp;
      }
    }

    void Input()
    {
      string ValueAdd;
      cout<<"Enter Val of list-TREE:"<<endl;
      while (true)
      {
        cin >> ValueAdd;
        if(ValueAdd=="999") 
        { cout<<"end of list."<<endl; break;  }
        else  {   insert_back(ValueAdd);  }
      }
    }

    void Print()
    {
      if (First==nullptr) 
      { 
      cout<<"list is empty";
      return; 
      }
      else
      {
        ListNode *Current=First;

        while(Current->Next != nullptr)
        {
          cout<<Current->Value<<endl;
          Current=Current->Next;
        }
        cout<<Current->Value<<endl<<"end of list";

      }
    }
    

};

class TreeNode
{
  public:
  Double_List *ValTre;
  TreeNode *LeftChild;
  TreeNode *RightChild;
  
  TreeNode()
  {
    ValTre=nullptr;
    LeftChild=nullptr;
    RightChild=nullptr;
  }

  TreeNode(Double_List *Value_)
  {
    ValTre=Value_;
    LeftChild=nullptr;
    RightChild=nullptr;
  }
};

class TreeOfList
{
  public:
  TreeNode *Root;

  TreeOfList()
  {
    Root = nullptr;
  }


  void Insert ( TreeNode *Start, Double_List *newValue )
  {
    if (Root==nullptr)  //если корень-пуст
    {
      TreeNode *Temp = new TreeNode(newValue);
      Root=Temp;
    }
    else 
    {
      TreeNode *Temp = new TreeNode(newValue);
      TreeNode *Cursor = Start; 

      if (Cursor->ValTre->getFirst().Value.size() < newValue->getFirst().Value.size())
      {
        if (Cursor -> RightChild == nullptr) Cursor -> RightChild = Temp;
        else
        {
          Cursor = Cursor -> RightChild;
          Insert(Cursor, newValue);
        }

      }
      else
      {
         if (Cursor ->LeftChild == nullptr) Cursor -> LeftChild = Temp;
        else
        {
          Cursor = Cursor -> LeftChild;
          Insert(Cursor,newValue);
        }

      }
      
    }

  }

  void PrintTr(TreeNode* Current)
  {
    if ( Current == nullptr )
    {
      cout<<endl<<"tree is empty"<<endl;
    }
    else
    {
      cout<<endl<<"Print Curent Treenode"<<endl;
      Current->ValTre->Print();

      if (Current->RightChild == nullptr)
      {
        cout << endl <<"No Right Child " << endl;
        if(Current->LeftChild == nullptr)
        {
          cout << endl <<"No Left Child " << endl;
        }
        else 
        {
          cout<<"Left Child: "<<endl;
          PrintTr(Current->LeftChild);
        }
      }
      else
      { 
        if(Current->LeftChild== nullptr)
        {
        cout << endl <<"No Left Child " << endl;
        cout << "Right Child:" << endl ; 
        
        PrintTr(Current->RightChild);
        }
        else
        {
          cout << "Right Child:" << endl ;
          Current->RightChild->ValTre->Print();
          cout << "Left Child:" << endl ;
          Current->LeftChild->ValTre->Print();
          if(Current->RightChild->RightChild!=nullptr)
          {
            if(Current->RightChild->LeftChild!=nullptr)
            {
            PrintTr(Current->RightChild->RightChild);
            PrintTr(Current->RightChild->LeftChild);
            }
            PrintTr(Current->RightChild->RightChild);
            
          }
          else 
          {
            return;
          }
        }
      }

    }
  }

  void Print()
  {
    PrintTr(Root);
  }


};

int main() 
{
  Double_List A;
  A.Input();

  Double_List A1;
  A1.Input();

  Double_List A2;
  A2.Input();
  
  Double_List *tempPtr;

  tempPtr=&A;
  TreeOfList B;
  B.Insert(B.Root,tempPtr);

  tempPtr=&A1;
  B.Insert(B.Root,tempPtr);

  tempPtr=&A2;
  B.Insert(B.Root,tempPtr);

  B.PrintTr(B.Root);
}
