#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *head, *tail;
    int length;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    int getLength() { return length; }

    void insert_start(int value)
    {
        Node *new_node = new Node;

        new_node->data = value;
        new_node->next = head;
        new_node->prev = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = head;
        }
        else
        {
            head->prev = new_node;
            head = new_node;
        };
        length++;
    }

    void insert_end(int value)
    {

        if (head == NULL)
        {
            return insert_start(value);
        }

        // Creating a new Node
        Node *new_node = new Node;

        new_node->data = value;
        new_node->next = NULL;
        new_node->prev = tail;

        tail->next = new_node;
        tail = new_node;
        length++;
    }

    void insert_position(int position, int value)
    {
        if (position == 0)
            return insert_start(value);
        if (position == (length - 1))
            return insert_end(value);

        if (head == NULL)
        {
            cout << "The linked list is empty!\n";
            return;
        }

        if (position >= length)
        {
            cout << "Invalid position!\n";
            return;
        }

        Node *ptr = head;

        int i = 0;
        while (ptr != NULL)
        {
            if (i == position)
            {
                break;
            }
            else
            {
                ptr = ptr->next;
            }
            i++;
        }

        Node *new_node = new Node;
        new_node->data = value;

        ptr->prev->next = new_node;
        ptr->prev = new_node;

        new_node->prev= ptr->prev;
        new_node->next = ptr;
        length++;
    }

    void delete_start()
    {
        if (head == NULL)
            return;
        Node *next = head->next;
        delete head;
        head = next;
        if(head == NULL){
            tail = NULL;
        }
        length--;
    }

    void delete_end()
    {
        if (tail == NULL)
            return;

        Node *prev = tail->prev;

        delete tail;
        tail = prev;
        prev->next = NULL;

        length--;
        if (length == 0)
        {
            head = NULL;
            tail = NULL;
        }
    }

    void delete_position(int position)
    {
        if (position == 0)
            return delete_start();
        if (position == (length - 1))
            return delete_end();

        if (head == NULL)
        {
            cout << "The linked list is empty!\n";
            return;
        }

        if (position >= length)
        {
            cout << "Invalid position!\n";
            return;
        }

        Node *ptr = head;

        int i = 0;
        while (ptr != NULL)
        {
            if (i == position)
            {
                break;
            }
            else
            {
                ptr = ptr->next;
            }
            i++;
            if (length == 0)
            {
                head = NULL;
                tail = NULL;
            }
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        delete ptr;
        length--;
    }

    void display()
    {
        cout << "DoublyLinkedList length:: " << length << " " << endl;

        // Checking if the linked list is empty
        if (head == NULL)
        {
            cout << "The linked list is empty !\n";
        }
        else
        {
            // Storing start in ptr
            Node *ptr = head;

            // Incrementing till the end
            while (ptr != NULL)
            {
                // Printing the elements
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    DoublyLinkedList *a = new DoublyLinkedList;

    int option, value, postion;

    // Continuing to show the menu till the program is exited
    do
    {
        cout << "\n********** MENU **********\n"
             << "1. Create the linked list\n"
             << "2. Insert at the beginning\n"
             << "3. Insert at the end\n"
             << "4. Insert at a position\n"
             << "5. Delete from the beginning\n"
             << "6. Delete from the end\n"
             << "7. Delete at a position\n"
             << "8. Display\n"
             << "9. Exit\n";

        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {

        case 1:
            cout << "Enter -1 to stop\n";
            cout << "Enter the value to be stored: ";
            cin >> value;
            while (value != -1)
            {
                a->insert_end(value);
                cout << "Enter the value to be stored: ";
                cin >> value;
            }
            break;

        case 2: // Storing the value to be inserted
            cout << "Enter the value to be stored: ";
            cin >> value;

            a->insert_start(value);
            break;

        case 3: // Storing the value to be inserted
            cout << "Enter the value to be stored: ";
            cin >> value;

            a->insert_end(value);
            break;

        case 4: // Storing the value to be inserted
            cout << "Enter the position to store data: ";
            cin >> postion;
            cout << "Enter the value to be stored: ";
            cin >> value;

            a->insert_position(postion, value);
            break;

        case 5:
            a->delete_start();
            break;

        case 6:
            a->delete_end();
            break;

        case 7:
            cout << "Enter the position to detete node: ";
            cin >> postion;
            a->delete_position(postion);
            break;

        case 8:
            a->display();
            break;

        case 9:
            break;

        default:
            cout << "Wrong option is selecred !!\n";
            break;
        }
    } while (option != 9);

    // Freeing the space occupied by start
    if (option == 13)
    {
        cout << "\nTHANK YOU for using the program !\n"
             << "Have a good day.\n\n";
    }

    delete a;
}