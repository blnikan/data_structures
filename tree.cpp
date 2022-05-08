#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    int count;
    Node* Left_child = nullptr;
    Node* Right_child = nullptr;
};

class Derevo
{
public:
    Node* root = new Node();//вот тут была проблема,не было написано new Node()

    Derevo()
    {
        root->value = INT32_MIN;
        root->Left_child = root;
        root->Right_child = root;
    }
    ~Derevo()
    {}

    void Chikl(Node* Cursor, int addval)
    {
        Node* Temp = new Node();
        if (addval > Cursor->value)//идём направо
        {
            Temp->value = addval;
            if (Cursor->Right_child == root) {
                Temp->Right_child = root;
                Temp->Left_child = root;
                Cursor->Right_child = Temp;
            }
            else {
                Chikl(Cursor->Right_child, addval);
            }
        }
        else
        {
            Temp->value = addval;
            if (Cursor->Left_child == root)
            {
                Temp->Right_child = root;
                Temp->Left_child = root;
                Cursor->Left_child = Temp;
            }
            else
            {
                Chikl(Cursor->Left_child, addval);
            }
        }
    }

    void Add_Node(int addValue)
    {
        if (root->value == INT32_MIN)
        {
            root->value = addValue;
            root->count++;
        }
        else//если в дереве есть узел то сравнить его value со всеми узлами стартуя от root и найти его место
        {
            Chikl(root, addValue);
        }
    }

    void VVod()
    {
        cout << "vvedite" << endl;
        int arg;
        while (true)
        {
            cin >> arg;
            Add_Node(arg);
            if (arg == 0)//значение при котором прекращается прием значений дерева 
            {
                cout << "end of tree" << endl;
                break;
            }
        }
    }

    void TrWidth(Node* Current)
    {
        cout << Current->value << " ";
        if (Current->Left_child != root)
        {
            cout << Current->Left_child->value << " left child of " << Current->value << " ";

            if (Current->Right_child != root)
            {
                cout << Current->Right_child->value << " right child oof " << Current->value << endl;
                TrWidth(Current->Left_child);
                TrWidth(Current->Right_child);
            }
            else if (Current->Right_child == root)
            {
                cout << Current->value << " have no right child, right stop " << endl;
                TrWidth(Current->Left_child);
            }

        }
        else if (Current->Left_child == root)
        {
            cout << Current->value << " have no left child, left stop ";
            if (Current->Right_child != root)
            {
                cout << Current->Right_child->value << " right child oof " << Current->value << endl;
                TrWidth(Current->Right_child);
            }
            else if (Current->Left_child == root)
            {
                cout << endl << "end " << endl;
            }
        }
    }

    void OutTrWidth()
    {
        if (root->value == INT32_MIN)
        {
            cout << "tree is empty";
        }
        else TrWidth(root);
    }


    void PreSearchOne(Node* Current, int temp_SearchOne)
    {


        if (temp_SearchOne == 0 || temp_SearchOne == INT32_MIN)
        {
            cout << "search is not correct";
        }

        if (temp_SearchOne == Current->value)
        {
            cout << Current->value << endl;

            cout << "finished" << endl;

        }

        else if (Current->value < temp_SearchOne)
        {
            cout << "(current value is: )" << Current->value << endl;

            if (Current->Right_child == root)
            {
                cout << "have no right child";
            }
            else
            {
                cout << "right child is: " << Current->Right_child->value << endl;
                PreSearchOne(Current->Right_child, temp_SearchOne);
            }

        }
        else if (Current->value > temp_SearchOne)
        {
            cout << "(current value is: )" << Current->value << endl;

            if (Current->Left_child == root)
            {
                cout << " have no left child";
            }
            else
            {
                cout << "left child is: " << Current->Left_child->value << endl;

                PreSearchOne(Current->Left_child, temp_SearchOne);
            }

        }
    }
    void SearchOne()
    {
        int temp_SearchOne = INT32_MIN;;
        //ввод числа которого надо найти в дереве
        cout << "************************ Search ************************" << endl;
        cin >> temp_SearchOne; cout << endl;
        PreSearchOne(root, temp_SearchOne);
    }


};

int main()
{
    Derevo* first = new Derevo();

    first->VVod();
    first->OutTrWidth();
    first->SearchOne();

}