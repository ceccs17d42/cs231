/*
 * 41
 * Binary Search Tree using Linked List
 * Name: Ritty Thomas
 * Roll no: 42
 */// C program to demonstrate delete operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node*)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
  
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
/* Given a non-empty binary search tree, return the node with minimum 
   key value found in that tree. Note that the entire tree does not 
   need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
int search(struct node* root,int key )
{
    if (root->key == key || root == NULL)
        return 1;
    
        else if (root->key > key)
        {
            return search(root->left,key);
        }
        else if(root->key < key)
            return search(root->right,key);
    else if (root != NULL)
        return 0;
}
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    
    int choice,key;    
    while(1)
	{
		printf("\t\nBinary Search Tree");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Search");
		printf("\n4.Exit");
		printf("\n5.Print\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter new data:");
				scanf("%d",&key);
				root=insert(root,key);
				 
				break;
			case 2:
				printf("Data to delete:");
				scanf("%d",&key);
				root=deleteNode(root,key);
				
				break;
            		case 3:
               			 printf("Enter data to be searched:");
                		 scanf("%d",&key);
                		 int k;
                		 k=search(root,key);
                    	         if(k==1)
                                	 printf("Data exists.");
                		 else if(k==0)
                    			printf("Data doesnt exist.");
			
			case 4:
				exit(0);
				break;
			case 5:
				printf("Inorder traversal of the given tree \n"); 
    				inorder(root);
				break;
    		}		
    }
    return 0; 
} 

OUTPUT:
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
1
Enter new data:30
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
1
Enter new data:20
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
1
Enter new data:40
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
1
Enter new data:70
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
1
Enter new data:60
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
1
Enter new data:80
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
5
Inorder traversal of the given tree 
20 30 40 60 70 80 	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
2
Data to delete:40
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
5
Inorder traversal of the given tree 
20 30 60 70 80 	
	
Binary Search Tree
1.Insert
2.Delete
3.Search
4.Exit
5.Print
3 
Enter data to be searched:30
Data exists.	

