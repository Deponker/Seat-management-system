#include<iostream>
#include<string>
using namespace std;

struct node
{
    string data;
    node* next;
};

node* Head = NULL;
node* Tail = NULL;

void PushCustomerInShop(string data)
{
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(Head == NULL)
    {
        Head = temp;
        Tail = temp;
        temp = NULL;
    }
    else
    {
        Tail->next = temp;
        Tail = temp;
        temp = NULL;
    }
}

void PrintCustomerInShop()
{
    node* temp = Head;
    cout << "[ ";
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]";
}

void DeleteCustomerInShop(string name)
{
    node* temp = Head;
    node* pre;
    node* post;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->data == name && temp == Head)
        {
          i=1;
   //       break;
        }
        else if(temp->data == name && temp==Tail)
        {
            i=3;
     //       break;
        }
        else if(temp->data == name)
        {
            i=2;
       //     break;
        }
        temp = temp->next;
    }


    switch(i)
    {
    case 1:
        temp = Head;
        Head = Head->next;
        delete temp;
        break;
    case 2:
        temp = Head;
        while(temp!=NULL)
        {
            if(temp->data == name)
            {
               post = temp->next;
               break;
            }
            pre = temp;
            temp = temp->next;
        }
        pre->next = post;
        pre=NULL;
        post=NULL;
        break;
    case 3:
        temp = Head;
        while(temp!=NULL)
        {
            pre = temp;
            temp = temp->next;
            if(temp->next==NULL)
                break;
        }
        Tail = pre;
        delete temp;
        break;
    default:
        break;
    }


}


node* front = NULL;
node* rear = NULL;
void EnqueueCustomerWaitingInLine(string data)
{
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

string returnWaitingCustomer()
{
   node* temp = front;
   front = front->next;
   string value = temp->data;
   delete temp;
   if(front==NULL)
   {
       rear=NULL;
   }

   return value;

}

void PrintCustomerWaitingInLine()
{
    node* temp = front;
    cout << "[ ";
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]";
}

node* stackHead = NULL;
void seatStack(string data)
{

    node* temp = new node;
    temp->data = data;
    temp->next = NULL;

    if(stackHead == NULL)
    {
        stackHead = temp;
    }
    else
    {
        temp->next = stackHead;
        stackHead = temp;
    }

}

void PopSeatStack()
{
    node* temp = stackHead;
    stackHead = stackHead->next;
    delete temp;
}

void PrintSeatStack()
{
    node* temp = stackHead;
    cout << "[ ";
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]";
}

int main()
{
  //  while(1)

        cout << "........................." << endl;
        cout << "Customers In Shop" << endl;
        PrintCustomerInShop();
        cout << endl << endl;
        cout << "Customers Waiting In Line" << endl;
        PrintCustomerWaitingInLine();
        cout << endl << endl;
        cout << "Seat Stack" << endl;
        //Seat Stack Initialize
        for(int i=0; i<5; i++)
        {
            seatStack("X");
        }
        PrintSeatStack();
        cout << endl << endl;
        cout << "........................." << endl;

    while(1)
    {
         cout << endl;
         string status;
         string name;
         cin >> status;
         if(status=="CLOSE")
            break;
         cin >> name;

         if(status=="ARRIVE")
         {
             if(stackHead==NULL)
             {
                 EnqueueCustomerWaitingInLine(name);
             }
             else
             {
                 PushCustomerInShop(name);
                 PopSeatStack();
             }

         }
         else if(status=="LEAVE")
         {
             DeleteCustomerInShop(name);
             seatStack("X");
             if(front != NULL)
             {
                 string waitedCustomer = returnWaitingCustomer();
                 PushCustomerInShop(waitedCustomer);
                 PopSeatStack();
             }

         }

        cout << "........................." << endl;
        cout << "Customers In Shop" << endl;
        PrintCustomerInShop();
        cout << endl << endl;
        cout << "Customers Waiting In Line" << endl;
        PrintCustomerWaitingInLine();
        cout << endl << endl;
        cout << "Seat Stack" << endl;
        PrintSeatStack();
        cout << endl << endl;
        cout << "........................." << endl;

    }



    return 0;
}
