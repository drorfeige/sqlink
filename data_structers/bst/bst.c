#include "bst.h"
#include <stdlib.h>


struct node{
	int m_val;
	struct node* m_right;
	struct node* m_left;
};

typedef struct node node;


typedef	struct{
	 node* m_root;
}tree_t;

static void addNode(node* root, node* nd, int val);
static void freeTree(node* nd);
static bstStatus inTree(node* nd,int val);
static void walkTree(node* nd, treeMode mode,treeFunc FuncFromUser);

typedef enum{LEFT,RIGHT}leftRight;

Tree createTree(){
	Tree tree;
	tree=(Tree)malloc(sizeof(Tree));
	return tree;

}

bstStatus insertTotree(Tree tree, int val){
		node* newNd;
		newNd=(node*)malloc(sizeof(node));
		if(newNd==NULL){
			return ALLOCATION_FAILED;
		}
		if(tree==NULL){
			return TREE_NONEXISTENT;
		}
		newNd->m_right=NULL;
		newNd->m_left=NULL;
		newNd->m_val=val;	
		if(tree->m_root==NULL){
			tree->m_root=newNd;
			return OK;
		}	
		addNode(tree->m_root,newNd,val);
		return OK;
}

void addNode(node* root, node* nd, int val){
	if(nd->m_val<=root->m_val){
		if(root->m_left==NULL){
			root->m_left=nd;
			return;			
		}		
 		addNode(root->m_left,nd,val);
	}
	else if(nd->m_val>root->m_val){
		if(root->m_right==NULL){
			root->m_right=nd;
			return;
		}
		addNode(root->m_right,nd,val);
	}
	return;
}

void destroyTree(Tree tree){
	if(tree!=NULL){
		freeTree(tree->m_root);
	}	
	free(tree);
}

void freeTree(node* nd){
	if(nd==NULL){
		return;
	}
	freeTree(nd->m_left);
	freeTree(nd->m_right);
	freeTree(nd);
}

bstStatus searchTree(Tree tree, int val){
		if(tree==NULL){
			return TREE_NONEXISTENT;
		}
		
		return inTree(tree->m_root,val);
}

bstStatus inTree(node* nd,int val){
	if(nd==NULL){
		return NOT_IN_TREE;
	}
	else if(val==nd->m_val){
		return OK;
	}
	else if(val<nd->m_val){
		return inTree(nd->m_left,val);
	}
	return inTree(nd->m_right,val);
}

bstStatus walk(Tree tree, treeMode mode,treeFunc FuncFromUser){
	if(tree==NULL){
		return TREE_NONEXISTENT;
	}
	walkTree(tree->m_root, mode, FuncFromUser);
	return OK;
}

void walkTree(node* nd, treeMode mode,treeFunc FuncFromUser){
	if(nd==NULL){
		return;
	}
	if(mode==PREORDER){
		FuncFromUser(nd->m_val);
	}
	walkTree(nd->m_left, mode, FuncFromUser);
	if(mode==INORDER){
		FuncFromUser(nd->m_val);
	}
	walkTree(nd->m_right, mode, FuncFromUser);
	if(mode==POSTORDER){
		FuncFromUser(nd->m_val);
	}
	return;
}


bstStatus deleteFromTree(Tree tree, int val){
	node* nd=NULL;
	node* parent=NULL;
	node* new=NULL;
	leftRight LR=0;/***************left is 0 right is 1************************************/
	if(tree==NULL){
		return TREE_NONEXISTENT;
	}
	/******deleting the only node in the tree********/
	if(tree->m_root->m_val==val && tree->m_root->m_right && tree->m_root->m_left){
		free(tree->m_root);
		return OK;
	}
	/***********finding the node to delete********************/
	parent=tree->m_root;
	if(val<parent->m_val){
		LR=LEFT;
		nd=parent->m_left;
	
	}
	else{
		nd=parent->m_right;
		LR=RIGHT;
	}
	while(nd!=NULL){
		if(val==nd->m_val){
			break;
		}
		if(val<parent->m_val){
			LR=LEFT;
			nd=nd->m_left;
		}
		else if(val>nd->m_val){
			nd=nd->m_right;
			LR=RIGHT;
		}	
	}
	/*************not in tree*******************/	
	if(nd==NULL){
		return NOT_IN_TREE;
	}
	/***********case that node has no children***********************/
	if(nd->m_right==NULL && nd->m_left==NULL){
		if(LR==LEFT){
			parent->m_left=NULL;
		}
		else{
			parent->m_right=NULL;
		}
		free(nd);
		return OK;
	}
	/********case that there is no left child********************/
	if(nd->m_left==NULL){
		if(LR==LEFT){
			parent->m_left=nd->m_right;
		}
		else{
			parent->m_right=nd->m_left;
		}
		free(nd);
		return OK;
	}
	/********case that there is no right child********************/
	if(nd->m_right==NULL){
		if(LR==LEFT){
			parent->m_left=nd->m_right;
		}
		else{
			parent->m_right=nd->m_left;
		}
		free(nd);
		return OK;
	}
	/**********************case that node has 2 children*********************/
	parent=nd;	
	new=nd->m_right;
	LR=RIGHT;
	while(new->m_left!=NULL){
		parent=new;
		new=new->m_left;
	}
	nd=new;
	return OK;			
}


















