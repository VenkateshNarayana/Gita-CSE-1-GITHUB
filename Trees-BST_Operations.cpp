/* BST - Binary Search Tree
Operations - insert
			 delete
			 traverse - preorder, inorder, postorder
			 search
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* create_treenode(int data);
struct node* insert(struct node* root,int data);
struct node* delete_treenode(struct node* root,int delete_data);

struct node* search(struct node* root,int search_data);
struct node* find_leftmost(struct node* root);
//traversal
void preorder_traverse(struct node* root);
void inorder_traverse(struct node* root);
void postorder_traverse(struct node* root);

//free tree nodes
void free_tree(struct node* root);
int main(){
	struct node* root = NULL;
	
	int arr[] = {10,5,6,15,29,12,35,10};
	int size = sizeof(arr)/sizeof(int);
	for(int i=0;i<size;i++){
		root = insert(root,arr[i]);
	}
	printf("\nInserted the data in tree successfully!!!");
	printf("\nInorder Traversal ");
	inorder_traverse(root);
	
	printf("\nPreorder Traversal ");
	preorder_traverse(root);
	printf("\nPostorder Traversal ");
	postorder_traverse(root);
	
	/* Search */
	struct node* temp;
	int search_val = 8;
	temp = search(root,search_val);
	printf((temp==NULL)?"\nSearch(%d) not found in tree.":"\nSearch(%d) found in tree.",search_val);
	
	 /* Delete */
    if(search(root, search_val) == NULL){
        printf("\nTreenode(%d) could not be found ..cannot perform delete.", search_val);
    }else{
    	root = delete_treenode(root, search_val);
        printf("\nTreenode(%d) deleted from tree.", search_val);
    }

	printf("\nInorder Traversal ");
	inorder_traverse(root);
	
	free_tree(root);
	root=NULL; //reset the root
	printf("\nAll tree nodes freed successfully!!!");
	return 0;
}
struct node* create_treenode(int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("\nMemory allocation failed..cannot proceed!!!");
		return NULL;
	}
	new_node->data  = data;
	new_node->left  = NULL;
	new_node->right = NULL;
	return new_node;
}
struct node* insert(struct node* root,int data){
	if (root==NULL){
		return create_treenode(data);
	}else{
		if(data > root->data){
			//check the right node is null
			root->right = insert(root->right,data);
		}else if (data < root->data){
			root->left = insert(root->left,data);
		}else { /* Duplicate value */
	        printf("Duplicate value %d not inserted.\n", data);
		}
	}
	return root;
}
struct node* search(struct node* root,int search_data){
	if (root==NULL){
		return NULL;
	}else{
		if(search_data > root->data){
			//check in the right node 
			return search(root->right,search_data);
		}else if (search_data < root->data){
			return search(root->left,search_data);
		}else { /* Search value */
	        return root;
		}
	}
}
struct node* delete_treenode(struct node* root,int delete_data){
	if (root==NULL){
		return NULL;
	}else{
		if(delete_data > root->data){
			//check in the right node 
			root->right = delete_treenode(root->right,delete_data);
		}else if (delete_data < root->data){
			root->left = delete_treenode(root->left,delete_data);
		}else { /* search found */
	        //case 1 when its leaf node
	        if (root->right==NULL && root->left==NULL){
	        	free(root);
				return NULL;
			}else if(root->left==NULL){// case2 when it has one child
				struct node* temp = root->right;
				free(root);
				return temp;
			}else if(root->right==NULL){// case2 when it has one child
				struct node* temp = root->left;
				free(root);
				return temp;
			}else{
				//case when it has 2 child - find inorder successor in the right subtree
				/* Find inorder successor */
            	struct node *temp = find_leftmost(root->right);

            	/* Copy successor's data */
           		root->data = temp->data;
           		
				/* Delete successor from right subtree */
            	root->right = delete_treenode(root->right, temp->data);
			}
		}
		return root;
	}
}
//recursive version
//struct node* find_leftmost(struct node* root){
//	if (root==NULL) return NULL;
//	if (root->left==NULL) return root;
//	return find_leftmost(root->left);
//}

//iterative version
struct node* find_leftmost(struct node* root){
    if (root == NULL) return NULL;
	//traverse left until NULL is reached
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}
void preorder_traverse(struct node *root) {
    if (root != NULL) {
		printf("%d ", root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void inorder_traverse(struct node *root) {
    if (root != NULL) {
        inorder_traverse(root->left);
        printf("%d ", root->data);
        inorder_traverse(root->right);
    }
}

void postorder_traverse(struct node *root) {
    if (root != NULL) {
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        printf("%d ", root->data);
        
    }
}

void free_tree(struct node *root){
    if (root == NULL) return;

    /* First free left subtree */
    free_tree(root->left);

    /* Then free right subtree */
    free_tree(root->right);

    /* Finally free the root */
    free(root);
}
