#pragma once

#include <iostream>
using namespace std;


template <class T>
class clsDblLinkedList
{

protected:
    int _Size = 0;

public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;

    }

    void PrintList()

    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
        delete Current;

    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value) {




        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;

    }

    void InsertAtEnd(T value) {


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;

    }

    void DeleteNode(Node*& NodeToDelete) {

      
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;

        _Size--;
    }

    void DeleteFirstNode()
    {

        

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode() {


        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;

        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty() {
        return !_Size;
    }

    private: void _delete_node_and_content(Node*& node) {

        if (node->next == NULL) {
            delete node;
            node = NULL;
            return;
        }


        _delete_node_and_content(node->next);
        
        delete node;
        node = NULL;
        
    }

public :

    void Clear() {

        _delete_node_and_content(head);
        _Size = 0;
    }

    void Reverce() {

        if (head == NULL)
            return;
        Node* tmp = NULL;

        while (true) {

            tmp = head->next;
            head->next = head->prev;
            head->prev = tmp;

            if (head->prev == NULL)
                break;

            head = head->prev;
        }
    }

    Node* GetNode(int index) {

        if (index < 0 || index >= _Size)
            return NULL;

        Node* tmp = head;
        while (index--) {
            tmp = tmp->next;
        }

        return tmp;
    }

    T GetItem(int index) {

        Node* item = GetNode(index);
        return (item == NULL)? NULL : item->value;
    }

    void UpdateItem(int index , T value) {

        if (index >= _Size || index < 0)return;

        GetNode(index)->value = value;
    }

    void InsertAfter(int index,T value) {

        if (index >= _Size || index < 0) return;

        InsertAfter(GetNode(index), value);
    }

};

