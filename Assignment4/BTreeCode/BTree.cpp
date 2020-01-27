/*
 * Binary Tree - source file (functions implementation)
 */

#include "BTree.h"
#include <exception>
#include <queue>

struct EmptyBTree : public exception {
  virtual const char* what() const throw()
  {return "BTree is empty.";}
};

ostream& operator<<(ostream& out, BTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream& operator<<(ostream& out, Node& node)
{
  out << "( "
      << node.value
      << ", "
      << node.search_cost
      << " )";
  return out;
}

istream& operator>>(istream& in, BTree& tree)
{
  int node_value;
  in>> node_value;
  tree.insert(node_value);
  return in;
}

void BTree::copy_cons_helper(Node* newNode, const Node* oldNode )//deep copy helper thats recursive
{
	if(oldNode == NULL)
	{
		newNode = NULL;
		return;
	}
	else
	{
		newNode->value = oldNode->value;
		newNode->search_cost = oldNode->search_cost;
		if(oldNode->left == NULL)
		{
			newNode->left = NULL;
		}
		else
		{
			newNode->left = new Node();
			copy_cons_helper(newNode->left, oldNode->left);
		}
		if(oldNode->right == NULL)
		{
			newNode->right = NULL;
		}
		else
		{
			newNode->right = new Node();
			copy_cons_helper(newNode->right, oldNode->right);
		}
	}
}

BTree::BTree(const BTree& other)//copy constructor
{
  Node* otherRoot  = other.root;
  root  = new Node();
  copy_cons_helper(root, otherRoot);//calls the recursive deep copy helper
  size = other.size;
  total_search_cost = other.total_search_cost;
}

BTree::~BTree()//destructor
{
	destructorHelper(root);
}

void BTree::destructorHelper(Node* temp)//recursive function for destructor
{
	if(temp != NULL)
	{
		if(temp->left != NULL)
		{
			destructorHelper(temp->left);
		}
		if(temp->right != NULL)
		{
			destructorHelper(temp->right);
		}
		delete temp;
	}
}
BTree::BTree(BTree&& other)//move constructor
{
  root = other.root;
  size = other.size;
  total_search_cost= other.total_search_cost;
  other.root = nullptr;
  other.size = 0;
}

BTree& BTree::operator=(const BTree& other)//copy assignment 
{
  if (this != &other)
  {
	  this->~BTree();//deallocate old data
	  root = new Node();
	  copy_cons_helper(root, other.root);//copy new data
	  size = other.size;//assign members
	  total_search_cost =other.total_search_cost;
  }
  return *this;
}

BTree& BTree::operator=(BTree&& other)//move assignment
{
  if (this != &other) 
  {
    this->~BTree();//deallocate old data
	root = new Node();
	copy_cons_helper(root, other.root);
	size  = other.size;
	total_search_cost = other.total_search_cost;
	other.~BTree();//deallocate the other 
  }
  return *this;
}

Node* BTree::insert(int obj)//insert function
{
  int search =0;
  Node* temp = root;
  Node* tempTrailer = NULL;
  if(temp == nullptr)
  {
    root = new Node(obj);
	root->search_cost = 1;
	size++;
	total_search_cost++;
	return root;
  }
  while( temp != nullptr)//traverse the list
  {
	  tempTrailer = temp;
	if (obj < temp->value)
	{
		temp = temp->left;
		search++;
	}
	else if (obj > temp->value)
	{
		temp  = temp->right;
		search++;
	}
  }
  if(obj < tempTrailer->value)
  {
	  tempTrailer->left = new Node(obj);
	  size++;
	  tempTrailer->left->search_cost = search+1;
	  total_search_cost = total_search_cost+tempTrailer->left->search_cost;
	  return tempTrailer->left;
  }
  else if(obj > tempTrailer->value)
  {
	  tempTrailer->right = new Node(obj);
	  size++;
	  tempTrailer->right->search_cost = search +1;
	  total_search_cost = total_search_cost +tempTrailer->right->search_cost;
	  return tempTrailer->right;
  }
}

Node* BTree::search(int obj)//search function
{
  Node* t = root;
  if(t == nullptr)
  {
    throw EmptyBTree();
  }
  while(t != nullptr)
  {
    if(obj < t->value)
    {
      t = t->left;
    }
    else if (obj > t->value)
    {
      t = t->right;
    }
    else return t;
  }
  return nullptr;
}

void BTree::update_search_cost()//update search cost of every node
{
	this->update_helper(this->root, 1);
}

void BTree::update_helper(Node* temp, int depth)//recursive helper for the update search cost
{
	if(temp == NULL)
	{
		return;
	}
	else
	{
		temp->search_cost = depth;
		update_helper(temp->left, depth+1);
		update_helper(temp->left, depth+1);
	}
}

void BTree::inorder(ostream& out, const Node& tree)//inorder traversal
{
	if(tree.left != NULL)
	{
		inorder(out, *tree.left);
	}
	out<<"("<<tree.value<<", "<<tree.search_cost<<") ";
	if(tree.right != NULL)
	{
		inorder(out, *tree.right);
	}
}

void BTree::print_level_by_level(ostream& out) //output tree
{
	if(size <= 16)
	{
		for(int i=1;i<=get_height(root);i++)//for loop for every tree level 
		{
			print_helper(out, root, i);
			out<< "\n";
		}
	}
	else
	{
		out<<"Binary Tree to big to print!";
	}
  return;
}

void BTree::print_helper(ostream& out, Node* temp, int currlevel)//recursive helper
{
	if(temp == NULL)
	{
		out<< "X ";
	}
	else if(currlevel == 1)
	{
		out<<*temp;
	}
	if(currlevel > 1)
	{
		if(temp == NULL)
		{
			print_helper(out, temp, currlevel-1);
		}
		else
		{
			print_helper(out, temp->left, currlevel-1);
			print_helper(out, temp->right, currlevel-1);
		}
	}
}

int BTree::get_height(Node* temp)//recursive
{
    if (temp == NULL)
        return 0;
    else {
        int lH = get_height(temp->left);
        int rH = get_height(temp->right);
        if (lH > rH)//max height
            return lH + 1;
        else
            return rH + 1;
    }
}
