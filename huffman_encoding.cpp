#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    char x;
    node* left;
    node* right;
};

struct comp {
    bool operator()(node* x, node* y)
    {
        return x->data > y->data;
    }
};


void pre(node* root, map<char, string>& mp, string temp)
{
    if (root == NULL)
    {
        return;
    }

    if (root->x != '$')
    {
        cout << temp << " " << root->x << " " << endl;
        mp[root->x] = temp;
        return;
    }
    string a = temp;
    a += "0";

    string b = temp;
    b += "1";

    pre(root->left, mp, a);
    pre(root->right, mp, b);

    return;

}

map<char, string> huffman(string& s, map<char, int>& freq)
{

    for (auto it : freq)
    {
        cout << it.first << " " << it.second << endl;
    }

    priority_queue< node*, vector<node*>, comp>pq;


    for (auto i : freq)
    {
        node* temp = new node();
        temp->data = i.second;
        temp->x = i.first;
        temp->left = NULL;
        temp->right = NULL;
        pq.push(temp);
    }


    while (pq.size() > 1)
    {
        node* X = pq.top();
        pq.pop();
        node* Y = pq.top();
        pq.pop();



        int z = X->data + Y->data;

        char w = '$';
        node* temp = new node();
        temp->data = z;
        temp->x = w;

        temp->left = X;
        temp->right = Y;

        pq.push(temp);
    }

    node* root = pq.top();


    map<char, string>ans;
    pre(root, ans, "");

    for (auto it : ans)
    {
        cout << it.first << " " << it.second;
        cout << endl;
    }





}






int main()
{
    string s;
    cin >> s;

    //perform huffman encoding and give the new codes for each charcter in string s

    map<char, int>mymap;

    mymap['a'] = 5;
    mymap['b'] = 9;
    mymap['c'] = 12;
    mymap['d'] = 13;
    mymap['e'] = 16;
    mymap['f'] = 45;




    map<char, string>ans = huffman(s, mymap);

}
