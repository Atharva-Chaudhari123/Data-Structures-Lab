/*
Second year Computer Engineering class, set A of students like Vanilla
Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two
sets using linked list. compute and display
i. Set of students who like either vanilla or butterscotch
ii. Set of students who like both vanilla and butterscotch
iii. Set of students who like only vanilla not butterscotch
iv. Set of students who like only butterscotch not vanilla
v. Number of students who like neither vanilla nor butterscotch
*/

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *next;
};
class SLL
{
public:
    node *head;
    node *tail;

public:
    void create()
    {
        node *newNode;
        node *temp;
        char c = 'y';
        bool flag = true;
        do
        {
            newNode = new node();
            cout << "Enter student roll: ";
            cin >> newNode->data;
            newNode->next = nullptr;

            if (flag)
            {
                head = newNode;
                newNode->next = nullptr;
                temp = newNode;
                flag = false;
            }
            else
            {
                temp->next = newNode;
                temp = newNode;
            }

            cout << "Do you want to add more : (y/n)";
            cin >> c;
        } while (c == 'y');
    }
    void display()
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ii)
vector<int> intersection(SLL a, SLL b)
{

    node *van = a.head;
    node *butter = b.head;
    vector<int> v;

    while (van != nullptr)
    {
        // cout<<"Value of van is "<<van->data<<endl;
        butter=b.head;
        while (butter != nullptr)
        {
            
            // cout<<"Value of butter is"<<butter->data<<endl;
            if (van->data == butter->data)
            {
                    // cout<<"Hey it is main logic of comparision";
                v.push_back(van->data);
                break;
            }
            butter = butter->next;
        }
        van = van->next;
    }
    return v;

   
}
// i) either vanilla or butterscotch
vector<int> symmetric(SLL a, SLL b)
{
    vector<int> v = intersection( a,  b);
    vector<int> ans;
    node *van = a.head;
    node *butter = b.head;

    bool flag;
    // cout<<"before while loop";
    while (van != nullptr)
    {
        
        flag = false;
        for (int i=0;i<v.size();i++){

            // cout<<"hey it is coming inside the for loop";

            if (v[i] == van->data)
            {
                // cout<<van->data;

                flag = true ;
            }
        }
        if (!flag)
        {
            ans.push_back(van->data);
        }

        van = van->next;
    }
    while (butter != nullptr)
    {
        flag = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == butter->data)
            {
                flag = true ;
            }
        }
        if (!flag)
        {
            ans.push_back(butter->data);
        }
        butter = butter->next;
    }
    return ans ;
}

int main()
{
    SLL vanila;
    vanila.create();

    SLL butterscotch;
    butterscotch.create();
    cout << "Students who like butterscotch : ";
    butterscotch.display();

    cout << "Students who like vanila : ";
    vanila.display();

    vector<int> v = intersection(vanila, butterscotch);
    cout<<"Students who like both : " ;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }


    vector <int > d = symmetric(vanila,butterscotch) ;
    cout<<"\n students who only like either of em: " ;
    for (int i = 0; i < v.size(); i++)
    {
        cout << d[i] << " ";
    }
}


// Rest of the code can be implemented hence skipped
// if you wish to complete just raise a PR 