#ifndef BST_H
#define BST_H

typedef struct tree_t* Tree;
typedef enum{OK,ALLOCATION_FAILED,TREE_NONEXISTENT,NOT_IN_TREE}bstStatus;
typedef enum{INORDER,PREORDER,POSTORDER}treeMode;
typedef void (*treeFunc)(int val);



Tree createTree();
bstStatus insertTotree(Tree tree, int val);
bstStatus searchTree(Tree tree, int val);
bstStatus deleteFromTree(Tree tree, int val);
void destroyTree(Tree tree);
bstStatus walk(Tree tree, treeMode mode,treeFunc FuncFromUser);


#endif 
