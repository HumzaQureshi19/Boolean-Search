#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<string>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QStringList>
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>  // for string streams
#include <string>  // for string
using namespace std;

class node{


    public:
    node *next;
    string data;

    node(){
        next = NULL;
    }

    node(string data, node *next){
        this->data=data;
        this->next= next;
    }

    node(string data){
        this->data=data;
        next=NULL;
    }

};

class linklist{



    public:
    node *head, *tail;
    linklist(){
        head=NULL;
        tail=NULL;
    }

    void insertAtFront(string el){


        if(head==NULL){
            head=tail= new node(el, NULL);
        }
        else{
            node *temp= new node(el, head);
            head = temp;
        }

    }

    void insertAtEnd(string el){

        if(head==NULL){
            head=tail=new node(el, NULL);
        }
        else{
            node *temp = new node(el, NULL);
            tail->next=temp;
            tail=temp;
            // delete temp;
        }
    }

    // void insertAtPosition(int pos, string el){
    //     node *temp=head;
    //     int i=1;
    //     while(temp!=NULL){
    //         if(i==pos)
    //         {
    //             temp->next = new node(el, temp->next);
    //         }
    //         temp=temp->next;
    //         i++;
    //     }
    // }
    void display(){
        node *temp = new node;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            // cout<<temp->el<<endl;
            temp=temp->next;
        }
    }

    int listSize(){

        int count = 0; // Initialize count
        node* current = head; // Initialize current
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        // count++;
        // cout<<count;
        return count;

    }

    bool checkHead()
    {
        if(head!=NULL)
            return true;
        else
        {
            false;
        }
    }

    void delete_from_tail()
    {
        node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        tail=temp;
        tail->next=NULL;
        delete temp;
    }
    void emptyList()
    {
        while(head!=NULL)
            delete_from_tail();
    }

    bool checkInList(string str)
    {
        node *temp = new node;
        temp=head;
        while(temp!=NULL){
            if(temp->data==str)
            {
                return true;
            }
            // cout<<temp->el<<endl;
            temp=temp->next;
        }
        return false;
    }
};

linklist* createList(int ST)
{
    linklist *array= new linklist[ST];
    return (array);
}

class BST
{
    public:
    BST *left, *right;
    int asciiValue;
    string data;
    linklist filename;
    BST *root;
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int, string, string);

    // Insert function.
    BST* Insert(BST *, int, string, string);

    // Inorder traversal.
    void Inorder(BST *);
    int ascii(string);
    void insertItem(string, string);
    BST* search(BST*,int, string );
    BST* searcher(int, string);
    int treeSize(BST*);
};

// Default Constructor definition.
BST :: BST() : root(NULL), left(NULL), right(NULL){}

// Parameterized Constructor definition.
BST :: BST(int value, string str, string file)
{
    asciiValue = value;
    filename.insertAtEnd(file);
    data = str;
    left = right = NULL;
}

// Insert function definition.
BST* BST :: Insert(BST *root, int value, string str, string file)
{
    if(!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value, str, file);
    }

    // Insert asciiValue.
    if(value > root->asciiValue)
    {
        // Insert right node asciiValue, if the 'value'
        // to be inserted is greater than 'root' node asciiValue.

        // Process right nodes.
        root->right = Insert(root->right, value, str, file);
    }
    else
    {
        // Insert left node asciiValue, if the 'value'
        // to be inserted is greater than 'root' node asciiValue.

        // Process left nodes.
        root->left = Insert(root->left, value,str, file);
    }

    // Return 'root' node, after insertion.
    return root;
}

void BST:: insertItem(string str, string file)
{
    asciiValue=0;
    for(int i=0;i<(str.length());i++)
    {
        asciiValue += str[i];
    }
    if(searcher(asciiValue, str) )
    {
        if(!(root->filename.checkInList(file)))
            root->filename.insertAtEnd(file);
    }
    else
        root = Insert(root, asciiValue, str, file);
}

int BST :: ascii(string key)
{
    int retVal=0;
    for(int i=0;i<key.length();i++)
    {
        retVal+=key[i];
    }
    return retVal;
}
// Inorder traversal function.
// This gives asciiValue in sorted order.
void BST :: Inorder(BST *root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data ;
    cout << "     " ;
    root->filename.display();
    cout<<endl;
    Inorder(root->right);
}

BST* BST :: searcher(int key,string str)
{
    return(search(root, key, str));
}
BST* BST :: search(BST* root, int key, string str)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == str)
       return root;

    // Key is greater than root's key
    if (root->asciiValue < key)
       return search(root->right, key, str);

    // Key is smaller than root's key
    return search(root->left, key, str);
}

int BST :: treeSize(BST *node)
{
    if (node == NULL)
        return 0;
    else
        return(treeSize(node->left) + 1 + treeSize(node->right));

}

BST* createTree(int ST)
{
    BST *array= new BST[ST];
    return (array);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string filep[100];

               string hundreds, tens, units, txt = ".txt";
               for(int i=0, itr=0;i<1;i++, itr++)
               {

                   hundreds="";
                   ostringstream str1;
                   str1<<i;
                   hundreds = str1.str();
                   for(int j=0;j<10;j++, itr++)
                   {

                       tens="";
                       ostringstream str2;
                       str2<<j;
                       tens = str2.str();
                       for(int k=0;k<10;k++,itr++)
                       {

                            ostringstream str3 ;
                            str3 << k;

                            // the str() coverts number into string
                            units = str3.str();
                            // cout<<units<<endl;
                            filep[itr] = hundreds+tens+units+txt;

                       }
                       itr--;
                   }
                   itr--;
               }
               int ST=0;
               string word;
               fstream file,file2, file3;
               for(int i=1;i<100;i++)
                   {
                       string path = "D:/booleanSearch/projectdsa/";
                       path = path + filep[i];
                       file2.open(path.c_str());
                       while(file2 >> word) { //take word and print
                           ST++;
                       }
                       file2.close();
                   }
BST *array=createTree(ST);
string words;
int key=0;
    // file.open(filename.c_str());
    for(int k=1;k<100;k++)
    {
        string path = "D:/booleanSearch/projectdsa/";
        path = path + filep[k];
        file.open(path.c_str());

        // for(int i=0;i<ST;i++)
        // {
            while(file >> word) { //take word and print

                key=0;
                words=word;
                for(int j=0;words[j]!='\0';j++)
                {
                    key = key + words[j];
                    //    cout<<"\nkey: "<<key<<"\tvalue["<<i<<"]["<<j<<"] = "<<value[i][j];;
                }
                key= key % ST;
                array[key].insertItem(words, filep[k]);
                // cout << word << endl;
            // }


        }
        file.close();
    }
    QString input = ui->lineEdit->text();
    std::string query2 = input.toStdString();
    query2.c_str();
//    cout<<"\n\nEnter word to search: ";
        string search;
//        cin>>search;
          search=query2;

        int searchKey=0;
        linklist listOfAnd, listOfOr;
        string extract;

        int pos1=0, pos2;
        bool flagOfAnd=false, flagOfOr = false;
        int j=0;
        BST *query[2];
        int k=0;
        for(int i=0;search[i]!='\0';i++)
        {
            if((search[i]=='&' && search[i+1]=='&') || search[i+1]=='\0' && flagOfOr==false)
            {
                pos2=i;
                string sub= search.substr(pos1,pos2);
                // cout<<sub<<endl;
                pos1=pos2+2;
                flagOfAnd=true;
                int searchKey=0;
                for(int l=0;sub[l]!='\0';l++)
                {
                    searchKey = searchKey + sub[l];
                }

                // array[searchKey%ST].Inorder(array[searchKey%ST].root);
                // array[searchKey%ST].searcher(searchKey%ST)->asciiValue;
                // cout<<"\nhello&&  word: "<<sub<<endl;
                query[k]=array[searchKey%ST].searcher(searchKey%ST, sub);
                // array[searchKey%ST].searcher(searchKey%ST, sub)->filename.display();
                k++;


                listOfAnd.insertAtEnd(sub);


            }
            if((search[i]=='|' && search[i+1]=='|') || search[i+1]=='\0' && flagOfAnd==false)
            {
                pos2=i;
                string sub= search.substr(pos1,pos2);
                // cout<<sub<<endl;
                pos1=pos2+2;
                flagOfOr=true;
                int searchKey=0;
                for(int l=0;sub[l]!='\0';l++)
                {
                    searchKey = searchKey + sub[l];
                }

                // array[searchKey%ST].Inorder(array[searchKey%ST].root);
                // array[searchKey%ST].searcher(searchKey%ST)->asciiValue;

                query[k]=array[searchKey%ST].searcher(searchKey%ST, sub);
                k++;
                listOfOr.insertAtEnd(sub);
            }
        }

            linklist commonFile;
            node *temp1;
            node *temp2;
            if(flagOfAnd)
            {
                temp1=query[0]->filename.head;
                temp2=query[1]->filename.head;
                // cout<<temp1->data;
            }
            else
            {
                temp1=query[0]->filename.head;
                temp2=query[1]->filename.head;
                // cout<<temp1->data;
            }

            if(flagOfAnd)
            {

                while(temp1!=NULL){
                    while(temp2!=NULL){
                        if(temp1->data==temp2->data)
                        {
                            // cout<<"hello";
                            commonFile.insertAtEnd(temp1->data);
                        }

                        temp2=temp2->next;
                    }
                    temp1=temp1->next;
                }
            }
            else
            {
                while(temp1!=NULL)
                {
                    commonFile.insertAtEnd(temp1->data);
                    temp1=temp1->next;
                }
                while(temp2!=NULL)
                {
                    commonFile.insertAtEnd(temp2->data);
                    temp2=temp2->next;
                }
            }

//            QMessageBox::information(0, "fileName", "hello" );

        if(commonFile.checkHead())
        {
            node *temp = new node;
            temp=commonFile.head;
            QString qstr="\n\n\t\t\t";
            while(temp!=NULL){
//                cout<<temp->data<<"\t";
                qstr = qstr + QString::fromStdString(temp->data) + "\t\t\t\n\t\t\t";

                // cout<<temp->el<<endl;
                temp=temp->next;
            }
//            ui->label->setText(qstr);
            QMessageBox::information(0, "File Name", qstr );
        }
        else
        {
            QMessageBox::information(0, "Error", "File Not Found" );
        }

             //****************************************************************************


}

