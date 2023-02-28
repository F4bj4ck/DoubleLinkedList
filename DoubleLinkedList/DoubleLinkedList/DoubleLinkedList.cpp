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
    bool AddNode(Node<T>* nodeToAdd)
    {
        if(nodeToAdd == nullptr)
        {
            return false;
        }
        
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

        return true;
    }

    bool InsertAfter(Node<T>* node, Node<T>* nodeToAdd)
    {
        if(headNode == nullptr || node == nullptr || nodeToAdd == nullptr)
        {
            return false;
        }
        
        if(node == tailNode)
        {
            tailNode = nodeToAdd;
        }
        else
        {
            node->nextNode->previousNode = nodeToAdd;
        }

        nodeToAdd->previousNode = node;
        nodeToAdd->nextNode = node->nextNode;
        node->nextNode = nodeToAdd;

        return true;
    }

    bool InsertBefore(Node<T>* node, Node<T>* nodeToAdd)
    {
        if(headNode == nullptr || node == nullptr || nodeToAdd == nullptr)
        {
            return false;
        }

        if (node == headNode)
        {
            headNode = nodeToAdd;
        }
        else
        {
            node->previousNode->nextNode = nodeToAdd;    
        }
        
        nodeToAdd->previousNode = node->previousNode;
        nodeToAdd->nextNode = node;
        node->previousNode = nodeToAdd;
        
        return true;
    }

    bool InsertAtIndex(int index, Node<T>* nodeToAdd)
    {
        if(index > Count() - 1 || nodeToAdd == nullptr)
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

    bool RemoveNode(Node<T>* nodeToRemove)
    {
        if(nodeToRemove == nullptr)
        {
            return false;
        }

        if(nodeToRemove == headNode && nodeToRemove == tailNode)
        {
            headNode = nullptr;
            tailNode = nullptr;

            return true;
        }
        if(nodeToRemove == headNode)
        {
            nodeToRemove->nextNode->previousNode = nullptr;
            headNode = nodeToRemove->nextNode;

            return true;
        }
        if(nodeToRemove == tailNode)
        {
            nodeToRemove->previousNode->nextNode = nullptr;
            tailNode = nodeToRemove->previousNode;

            return true;
        }

        nodeToRemove->previousNode->nextNode = nodeToRemove->nextNode;
        nodeToRemove->nextNode->previousNode = nodeToRemove->previousNode;

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

    void PrintForward()
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

    void PrintBackward()
    {
        if(headNode == nullptr)
        {
            return;
        }
        
        Node<T>* tmp = tailNode;

        while (tmp != nullptr)
        {
            std::cout << tmp->data << ", ";
            tmp = tmp->previousNode;
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

    list.PrintForward();
    std::cout << "\n";
    std::cout << "List has " << list.Count() << " nodes\n";
    
    list.AddNode(&node2);

    list.PrintForward();
    std::cout << "\n";
    std::cout << "List has " << list.Count() << " nodes\n";
    
    list.InsertBefore(&node, &node3);

    list.PrintForward();
    std::cout << "\n";
    std::cout << "List has " << list.Count() << " nodes\n";
    
    return list.Count();
}