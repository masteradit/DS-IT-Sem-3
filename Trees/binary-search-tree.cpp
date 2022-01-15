#include <iostream>
#include <process.h>

using namespace std;

class node
{
    int info;
    node *rcl;
    node *lcl;

public:
    node *ins_bst(node *);
    void display(node *, int);
    void del_bst(node *, int);
};

void node::del_bst(node *root, int ele)
{
    node *par, *cur, *succ;
    if (root == NULL)
        return;
    par = cur = NULL;
    node *q = root;
    while (q != NULL)
    {
        if (q->info == ele)
        {
            cur = q;
            break;
        }
        par = q;
        if (q->info > ele)
            q = q->lcl;
        else
            q = q->rcl;
    }
    if (cur->lcl != NULL && cur->rcl != NULL)
    {
        par = cur;
        succ = cur->rcl;
        while (succ->lcl != NULL)
        {
            par = succ;
            succ = succ->lcl;
        }
        cur->info = succ->info;
        cur = succ;
    }
    if (cur->lcl == NULL && cur->rcl == NULL)
    {
        if (par->rcl == cur)
            par->rcl = NULL;
        else
            par->lcl = NULL;
        delete (cur);
        return;
    }
    if (cur->lcl == NULL && cur->rcl != NULL)
    {
        if (par->lcl == cur)
            par->lcl = cur->rcl;
        else
            par->rcl = cur->rcl;
        delete cur;
        return;
    }
    if (cur->lcl != NULL && cur->rcl == NULL)
    {
        if (par->lcl == cur)
            par->lcl = cur->lcl;
        else
            par->rcl = cur->lcl;
        delete cur;
        return;
    }
}
void node::display(node *root, int level)
{
    int i;
    if (root == NULL)
        return;
    display(root->rcl, level + 1);
    cout << root->info << endl;
    display(root->lcl, level + 1);
}
node *node::ins_bst(node *root)
{
    node *temp, *prev, *cur;
    temp = new node;
    cout << "\nEnter the element\n";
    cin >> temp->info;
    temp->lcl = NULL;
    temp->rcl = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (temp->info == cur->info)
        {
            cout << "\nNo Duplicates please!\n";
            delete temp;
            return root;
        }
        if (temp->info < cur->info)
            cur = cur->lcl;
        else
            cur = cur->rcl;
    }
    if (temp->info < prev->info)
        prev->lcl = temp;
    else
        prev->rcl = temp;
    return root;
}

int main()
{
    node *root = NULL, b;
    int c, level = 0, ele;
    while (1)
    {
        cout << "\n1. Insert   2.Print  3. Delete  4. Exit\n";
        cin >> c;
        switch (c)
        {
        case 1:
            root = b.ins_bst(root);
            break;
        case 2:
            b.display(root, level);
            break;
        case 3:
            cout << "Enter the node info to delete the node";
            cin >> ele;
            b.del_bst(root, ele);
            break;
            //   case 4:exit(0);
        }
    }
    return 0;
}
