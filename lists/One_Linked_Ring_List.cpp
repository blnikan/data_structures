#include <iostream>

using namespace std;

class ListNode
{
public:
    int Value;
    ListNode* next;

    ListNode(int _Value)
    {
        Value = _Value;
        next = nullptr;
    }
};


class List
{
public:
    ListNode* First = nullptr;

    List()
    {
        ListNode* First = new ListNode(5);
        First->Value = INT32_MIN;
        First->next = First;
    }


    void insert(int Value)
    {
        ListNode* Temp = new ListNode(Value);

        if (First == nullptr) { First = Temp; First->next = First; }
        else
        {
            Temp->next = First->next;
            First->next = Temp;
        }
    }

    void Vvod()
    {
        int val_add;
        cout << "Enter Value of LIST: " << endl;

        while (true)
        {
            cin >> val_add;
            if (val_add == 999)
            {
                cout << "end of LIST." << endl;
                break;
            }
            else
            {
                insert(val_add);
            }
        }
    }

    void Print()
    {
        ListNode* Current = First;

        if (Current == nullptr)
        {
            cout << "Your List is empty" << endl;
        }
        else
        {
            while (Current->next != First)
            {
                cout << Current->Value << endl;
                Current = Current->next;

            }
            cout << Current->Value << endl;
            cout << "End of List" << endl;

        }
    }

    void Swap(ListNode *_Current)
    {
      int temp=_Current->Value;
      _Current->Value=_Current->next->Value;
      _Current->next->Value=temp;

    }
    
    //ListNode *Next(ListNode *_Current, int shift=1)
    //{
        /*сдвиг врерёд на значение  shift
          по умолчанию на 1
        */
    //}
    
    void Sort()
    {
      ListNode* Current=First;
      ListNode* Temp=Current;
      int counter=0;

      while(Temp->next!=First)
      {
        while(Current->next!=First)
        {
          if(Current->Value>Current->next->Value)
          {
            Swap(Current);
          }
          Current=Current->next;
        }
        Temp=Temp->next;
        Current=Temp;
        //cout<<endl<<"nd:"<<endl;
      //Print();
      }
      cout<<endl<<"List after Sort:"<<endl;
      Print();
    }

};


int main()
{
    List a;
    a.Vvod();
    a.Print();
    a.Sort();
}
