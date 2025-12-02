#include <iostream>
#include <string>
using namespace std;

struct GLL
{
    int flag;    
    string data; 
    GLL *down;   
    GLL *next;   
};

GLL *createAtom(string val)
{
    GLL *node = new GLL;
    node->flag = 0;
    node->data = val;
    node->down = NULL;
    node->next = NULL;
    return node;
}

GLL *createSublist(GLL *sub)
{
    GLL *node = new GLL;
    node->flag = 1;
    node->data = "";
    node->down = sub;
    node->next = NULL;
    return node;
}

GLL *buildGLL()
{
    cout << "\nEnter number of elements in this set: ";
    int n;
    cin >> n;

    GLL *head = NULL;
    GLL *last = NULL;

    for (int i = 0; i < n; i++)
    {
        cout << "Is element " << i + 1 << " an atom (0) or a sublist (1)? ";
        int type;
        cin >> type;

        GLL *node;
        if (type == 0)
        {
            cout << "Enter atom: ";
            string val;
            cin >> val;
            node = createAtom(val);
        }
        else
        {
            cout << "Creating sublist...\n";
            node = createSublist(buildGLL());
        }

        if (head == NULL)
            head = node;
        else
            last->next = node;
        last = node;
    }

    return head;
}

void printGLL(GLL *head)
{
    cout << "{";
    while (head != NULL)
    {
        if (head->flag == 0)
        {
            cout << head->data;
        }
        else
        {
            printGLL(head->down);
        }
        if (head->next != NULL)
            cout << ", ";
        head = head->next;
    }
    cout << "}";
}

int main()
{
    cout << "Build a Generalized Linked List (Set)" << endl;
    GLL *S = buildGLL();

    cout << "\nSet S = ";
    printGLL(S);
    cout << endl;
   return 0;
}
