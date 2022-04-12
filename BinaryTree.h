#pragma once
#include <iostream>

template <class T>
struct node
{
	T info;
	node<T> *left;
	node<T> *right;
};

template <class T>
class BinaryTree
{
public:
	// CONSTRUCTORS & DESTRUCTORS //
	BinaryTree()
	{
		root = nullptr;
	}

	~BinaryTree()
	{
		destroy(root);
	}

	// MEMBER FUNCTIONS //
    bool search(const T& data) const
    {
        node<T>* curr;
        bool found = false;

        if (this->root == nullptr)
        {
            std::cout << "Cannot search an empty tree." << std::endl;
        }
        else
        {
            curr = this->root;

            while (curr != nullptr && !found)
            {
                if (curr->info == data)
                {
                    found = true;
                }
                else if (curr->info > data)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return found;
    }

	void insert(const T& data)
	{
        node<T> *curr; // pointer to traverse the tree //
        node<T> *TrailCurr = nullptr; // pointer //
        node<T> *NewNode;  // pointer to create the node //

        NewNode = new node<T>;
        NewNode->info = data;
        NewNode->left = nullptr;
        NewNode->right = nullptr;

        if (this->root == nullptr)
        {
            this->root = NewNode;
        }
        else
        {
            curr = this->root;

            while (curr != nullptr)
            {
                TrailCurr = curr;
                if (curr->info > data)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            if (TrailCurr->info > data)
            {
                TrailCurr->left = NewNode;
            }
            else
            {
                TrailCurr->right = NewNode;
            }
        }
	}

    void DelNode(const T& data)
    {
        node<T>* curr; //pointer to traverse the tree
        node<T>* TrailCurr; //pointer behind current
        bool found = false;

        if (this->root == nullptr)
        {
            std::cout << "Cannot delete from an empty tree." << std::endl;
        }
        else
        {
            curr = this->root;
            TrailCurr = this->root;
            while (curr != nullptr && !found)
            {
                if (curr->info == data)
                {
                    found = true;
                }
                else
                {
                    TrailCurr = curr;
                    if (curr->info > data)
                    {
                        curr = curr->left;
                    }
                    else
                    {
                        curr = curr->right;
                    }
                }
            }
            if (curr == nullptr)
            {
                std::cout << "The item to be deleted is not in the tree." << std::endl;
            }
            else if (found)
            {
                if (curr == this->root)
                {
                    DelFromTree(this->root);
                }
                else if (TrailCurr->info > data)
                {
                    DelFromTree(TrailCurr->left);
                }
                else
                {
                    DelFromTree(TrailCurr->right);
                }
            }
            else
            {
                std::cout << "The item to be deleted is not in the tree." << std::endl;
            }
        }
    }

    void InOrder_Traversal()
    {
        InOrder_Traversal(root);
    }

private:
	node<T> *root;

    // priv function //
    void DelFromTree(node<T>*& pointer)
    {
        node<T>* curr; //pointer to traverse the tree
        node<T>* TrailCurr;  //pointer behind current
        node<T>* temp;      //pointer to delete the node

        if (pointer == nullptr)
        {
            std::cout << "Error: The node to be deleted does not exist." << std::endl;
        }
        else if (pointer->left == nullptr && pointer->right == nullptr)
        {
            temp = pointer;
            pointer = nullptr;
            delete temp;
        }
        else if (pointer->left == nullptr)
        {
            temp = pointer;
            pointer = temp->right;
            delete temp;
        }
        else if (pointer->right == nullptr)
        {
            temp = pointer;
            pointer = temp->left;
            delete temp;
        }
        else
        {
            curr = pointer->left;
            TrailCurr = nullptr;
            while (curr->right != nullptr)
            {
                TrailCurr = curr;
                curr = curr->right;
            }

            pointer->info = curr->info;

            if (TrailCurr == nullptr) // curr did not move //

                pointer->left = curr->left;
            else
                TrailCurr->right = curr->left;

            delete curr;
        }
    }

    void destroy(node<T>*& pointer)
    {
        if (pointer != nullptr)
        {
            destroy(pointer->left);
            destroy(pointer->right);
            delete pointer;
            pointer = nullptr;
        }
    }

    void InOrder_Traversal(node<T>* pointer) const
    {
        if (pointer != nullptr)
        {
            InOrder_Traversal(pointer->left);
            std::cout << pointer->info << ' ';
            InOrder_Traversal(pointer->right);
        }
        std::cout << std::endl;
    }
};