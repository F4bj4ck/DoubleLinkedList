#include <iostream>

template<class T>
struct Node
{
    Node* previousNode = nullptr;
    Node* nextNode = nullptr;

    T data;
};

template<class T>
struct DoubleLinkedList
{
    Node<T>* headNode = nullptr;
    Node<T>* tailNode = nullptr;

    //Adds a node at the end
    void AddNode(Node<T>* nodeToAdd)
    {
        if(headNode == nullptr)
        {
            headNode = nodeToAdd;
            tailNode = nodeToAdd;
        }
        else
        {
            tailNode->nextNode = nodeToAdd;
            nodeToAdd->previousNode = tailNode;
            tailNode = nodeToAdd;
        }
    }

    bool InsertAfter(Node<T>* node, Node<T>* nodeToAdd)
    {
        if(headNode == nullptr || node == nullptr || nodeToAdd == nullptr)
        {
            return false;
        }
        
        Node<T>* tmp = headNode;

        while (tmp != nullptr)
        {
            if(tmp == node)
            {
                if(node == tailNode)
                {
                    tailNode = nodeToAdd;
                }
                nodeToAdd->previousNode = node;
                nodeToAdd->nextNode = node->nextNode;
                node->nextNode = nodeToAdd;

                return true;
            }
            else
            {
                tmp = tmp->nextNode;
            }
        }

        return false;
    }

    bool InsertBefore(Node<T>* node, Node<T>* nodeToAdd)
    {
        if(headNode == nullptr || node == nullptr || nodeToAdd == nullptr)
        {
            return false;
        }

        Node<T>* tmp = headNode;

        while (tmp != nullptr)
        {
            if (tmp == node)
            {
                if (node == headNode)
                {
                    headNode = nodeToAdd;
                }
                nodeToAdd->previousNode = node->previousNode;
                nodeToAdd->nextNode = node;
                node->previousNode = nodeToAdd;

                return true;
            }
        }

        return false;
    }

    bool InsertAtIndex(int index, Node<T>* nodeToAdd)
    {
        if(index > Count() - 1)
        {
            return false;
        }

        if(index == 0)
        {
            nodeToAdd->nextNode = headNode;
            headNode->previousNode = nodeToAdd;
            headNode = nodeToAdd;

            return true;
        }
        
        Node<T>* tmp = headNode;
        
        int i = 0;

        while (i < index)
        {
            i++;
            tmp = tmp->nextNode;
        }

        tmp->previousNode->nextNode = nodeToAdd;
        nodeToAdd->previousNode = tmp->previousNode;
        nodeToAdd->nextNode = tmp;
        tmp->previousNode = nodeToAdd;
        
        return true;
    }

    int Count()
    {
        if(headNode == nullptr)
        {
            return 0;
        }
        
        int count = 0;

        Node<T>* tmp = headNode;

        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->nextNode;
        }
        
        return count;
    }

    void Print()
    {
        if(headNode == nullptr)
        {
            return;
        }
        
        Node<T>* tmp = headNode;

        while (tmp != nullptr)
        {
            std::cout << tmp->data << ", ";
            tmp = tmp->nextNode;
        }
    }
};

int main(int argc, char* argv[])
{

    Node<int> node;
    node.data = 2;

    Node<int> node2;
    node2.data = 15;

    Node<int> node3;
    node3.data = 12;

    DoubleLinkedList<int> list;

    std::cout << "List has " << list.Count() << " nodes\n";
    
    list.AddNode(&node);

    list.Print();
    std::cout << "\n";
    std::cout << "List has " << list.Count() << " nodes\n";
    
    list.AddNode(&node2);

    list.Print();
    std::cout << "\n";
    std::cout << "List has " << list.Count() << " nodes\n";
    
    list.InsertAtIndex(0, &node3);

    list.Print();
    std::cout << "\n";
    std::cout << "List has " << list.Count() << " nodes\n";
    
    return list.Count();
}