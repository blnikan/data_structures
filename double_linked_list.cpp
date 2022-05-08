/* Структура данных список LIST для начала самый простой открытый однонаправленный*/
#include <iostream>

using namespace std;

class ListNode
{
public:
    int Value;
    ListNode* next;
    ListNode* prev;
    int IndeX;

    ListNode(int _Value)
    {
        Value = _Value;
        next = nullptr;
        prev = next;
    }
};


class List
{
public:
    ListNode* First = nullptr;
    ListNode* Last = First;
    bool temp_cours = 0;//костыль 


    void insert_back(int newVal)////push back
    {
        ListNode* Temp = new ListNode(newVal);

        if (Last == nullptr)
        {
            Last = Temp;
            First = Last;
        }
        else
        {
            ListNode* Current = Last;

            Current->next = Temp;
            Temp->prev = Current;
            Last = Temp;
        }
    }

    void insert_front(int newVal)//push front
    {
        ListNode* Temp = new ListNode(newVal);

        if (First == nullptr)
        {
            First = Temp;
            Last = First;
        }
        else
        {
            ListNode* Current = First;

            Current->prev = Temp;
            Temp->next = Current;
            First = Temp;

        }
    }




    void Vvod()
    {
        int val_add;
        int qu = 0;

        cout << "1-front\n2-pushback" << endl;
        cin >> qu; cout << endl;

        if (qu == 1)
        {
            temp_cours = true;
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
                    insert_front(val_add);
                }

            }
        }
        else
        {
            temp_cours = false;
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
                    insert_back(val_add);
                }
            }

        }
    }

    void Print()
    {
        if (First == nullptr)
        {
            return;
        }
        else
        {
            ListNode* Current = First;

            while (Current->next != nullptr)
            {
                cout << Current->Value << endl;
                Current = Current->next;
            }
            cout << Current->Value << endl;
        }
    }

    void Print_reverse()//print from Last to First
    {

        if (Last == nullptr)
        {
            return;
        }
        else
        {
            ListNode* Current = Last;

            while (Current->prev != nullptr)
            {
                cout << Current->Value << endl;
                Current = Current->prev;
            }
            cout << Current->Value << endl;
        }
    }



    void Search_First_L()
    {

        int SeaValue;
        cout << "Search iteam is: ";  cin >> SeaValue;  cout << endl;
        ListNode* Current = First;
        if (First == nullptr)
        {
            cout << " This list is Empty" << endl;
            return;
        }
        while (Current->Value != SeaValue)
        {
            Current->prev = Current;
            Current = Current->next;
        }

        if (Current->prev == nullptr) { cout << "have no el before" << endl; }
        else { cout << "el before: " << Current->prev->Value << endl; }

        cout << "el is: " << Current->Value << endl;

        if (Current->next == nullptr) { cout << "have no el next" << endl; }
        else { cout << "el next: " << Current->next->Value << endl; }
    }

    void Search_all_el()
    {
        int Value_Search;
        int counter = 0;
        cout << "Search iteams are: ";  cin >> Value_Search;  cout << endl;
        ListNode* Current = First;
        if (First == nullptr)
        {
            cout << " This list is Empty" << endl;
            return;
        }
        else
        {
            while (true)
            {
                if (Current->next == nullptr) { break; } //loop exit condition

                else if (Current->Value == Value_Search)
                {
                    counter++;

                    if (Current->prev == nullptr) { cout << "have no el before" << endl; }
                    else { cout << "el before is: " << Current->prev->Value << endl; }

                    cout << "Search el is: " << Current->Value << endl;

                    if (Current->next == nullptr) { cout << "have no el next" << endl; }
                    else { cout << "next el is: " << Current->next->Value << endl; }
                }

                Current->prev = Current;
                Current = Current->next;
            }

            cout << "there are " << counter << " matches";
        }


    }


    void Sort_List()
    {
        ListNode* Current = First;

        if (Current == nullptr) { cout << "List is empty." << endl; }
        else
        {
            if (Current->next == nullptr) { cout << "List have only 1 el" << endl; }
            else
            {
                //Мой Костя (счетчик элементов)
                int counter = 0;
                while (Current->next != nullptr) { counter++; }
                cout << counter<<endl;



            }
        }

    }

    

};

int main()
{
    List a;
    a.Vvod();
    a.Print();
    a.Search_all_el();
}