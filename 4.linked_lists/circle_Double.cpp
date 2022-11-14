#include <iostream>
using namespace std;
//21BBS0100
struct Dnode
{
    Dnode* Next;
    Dnode* Previous;

    int Value;

    Dnode(int value)
    {
        Value = value;
    }
};



class DoubleLinkedList
{
public:
    Dnode* First;
    Dnode* Last;
    int Count;

    DoubleLinkedList()
    {
        First = NULL;
        Last = NULL;

        Count = 0;
    }

    void Insert_begining(int value)
    {
        Dnode* node = new Dnode(value);
        Dnode* temp = Last;

        node->Next = temp;
        node->Previous = NULL;

        if (Count == 0)
        {
            First = node;
            Last = First;
        }
        else
        {
            First = node;
            temp->Previous = node;
        }

        Count++;
    }

    void Insert_End(int value)
    {
        Dnode* node = new Dnode(value);
        Dnode* temp = Last;

        node->Next = NULL;
        node->Previous = node;
        Last = node;

        if (Count == 0)
        {
            Last = node;
            First = Last;
        }
        else
        {
            Last = node;
            temp->Next = node;
        }

        Count++;
    }

    void Insert_Desired(int pos, int value)
    {
        Dnode* node = new Dnode(value);

        if (pos == 0)
        {
            Insert_begining(value);
        }
        else if (pos >= Count)
        {
            Insert_End(value);
        }
        else
        {
            Dnode* temp = First;

            int i = 0;

            while (temp != NULL)
            {
                if (pos == i)
                {
                    node->Previous = temp->Previous;
                    node->Next = temp;
                    temp->Previous->Next = node;
                    temp->Previous = node;

                    Count++;

                    break;
                }
                i++;
                temp = temp->Next;
            }
        }
    }

    bool delete_node(int pos)
    {
        Dnode* temp = First;

        if (pos == 0)
        {
            temp->Next->Previous = temp->Next;
            First = First->Next;

            Count--;

            return true;
        }
        else if (pos == Count - 1)
        {
            temp->Previous = NULL;
            Last = Last->Previous;

            Count--;

            return true;
        }
        else
        {
            int i = 0;

            while (temp != NULL)
            {
                if (i == pos)
                {
                    temp->Previous->Next = temp->Next;
                    temp->Next->Previous = temp->Previous;

                    Count--;

                    return true;
                }

                temp = temp->Next;
                i++;
            }
        }
        return false;
    }

  
void PrintList(DoubleLinkedList& list)
{
    for (int index = 0; index < list.Count; index++)
    {
        if (index == 0)
        {
            cout << list.First->Value << " ";
        }
        else if (index == list.Count - 1)
        {
            cout << list.Last->Value << " ";
        }
        else
        {
            Dnode* current = list.First;

            for (int i = 0; index < list.Count; i++)
            {
                if (i == index)
                {
                    cout << current->Value << " ";

                    break;
                }

                current = current->Next;
            }
        }
    }
}
};

int main()
{
    DoubleLinkedList list;
    int choice;
    int val,pos;
    do
	{
	
	cout<<"\nEnter the Operation to be performed:\n1.insert begining\n2.insert End\n3.Insert Desired\n4.Delete\n5.Display\nYour Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"enter the value u want to insert : ";
		        cin>>val;   
		        list.Insert_begining(val);
		        break;
	    case 2: cout<<"enter the value u want to insert : ";
		        cin>>val;
		        list.Insert_End(val);
		        break;
		case 3: cout<<"enter the value u want to insert : ";
		        cin>>val;
                cout<<"enter the position : ";
                cin>>pos;
		        list.Insert_Desired(pos,val);
		        break;
	    	    
	    case 4:cout<<"Enter the index to be Deleted : ";
               cin>>val;
               list.delete_node(val);
	           break;
	    case 5: list.PrintList(list);
	            break;

	}
  }while(choice!=6);
}


