



/// code Error kom merl bro Xd




#include<stdio.h>
#include<malloc.h>
 
 /* TREE structure */
    typedef struct  TREE
        {
            struct TREE *left;
            int data;
            struct TREE *right;
            
        }TREE;

 TREE *BinaryTree (nArray, low, high)
 int *nArray, low, high;
 {
        TREE *tree;
        int mid;
        mid = (int) (low + high )/2;
        if(!(tree = (TREE*)malloc(sizeof( TREE))))
        {
            printf("Error: Out of Memory.!");
            return(tree);
        }

        tree -> data = nArray[mid];
        /* Table lower ptr is equal to higher ptr then no further division */
        if(low >= high)
        {
            tree -> left = NULL;
            tree -> right = NULL;
            return(tree);
        }
        /* Divide and Conquer Method: i.e. Divide the table into two equal
        halves until no further division is possible */
        if (low <= mid - 1)
            tree -> left = BinaryTree (nArray, low, mid-1);
        else
            tree -> left = NULL;
        if(mid + 1 <= high)
            tree -> right = BinaryTree (nArray, mid + 1, high);
        else
            tree -> right = NULL;
        return(tree);   

}


/* Pre order Traversal */
void PreOrder(tree)
TREE *tree; 
{
    if(tree) 
    {
        printf("%d", tree -> data); /* Process node */
        PreOrder(tree -> left);
        PreOrder(tree -> right);
    }
}       

/* In Order Traversal */
void inOrder(tree)
TREE *tree;
{
    if(tree)
    {
        InOrder( tree -> left);
        printf("%d", tree -> data);  /* Process node */
        InOrder( tree -> right);
    }    
}

/* Post Order Traversal */
void PostOrder(tree)
TREE *tree;
{
    if(tree) 
    {
        PostOrder(tree -> left);
        PostOrder(tree -> right);
        printf("%d", tree -> data); /* Process node */
    }  
}      

/* Tree Printing in Triangle Form */
void PrintTreeTriangle(tree, level)
TREE *tree;
    int level;
    {
        int i;
        if(tree)
        {
            PrintTreeTriangle( tree -> right, level + 1);
            printf("\n");
            for(i = 1; i < level; i++)
                printf(" ");

            printf("%d", tree -> data);
            PrintTreeTriangle (tree -> left, level + 1);
        }

    }

/* Tree Printing in Diagonal Form */
void PrintTreeDiagonal( tree, level)
TREE *tree;
int level;
    {
        int i;
        if(tree)
        {
            printf("\n");
            for(i = 0; i < level; i++)
                printf(" ");
            printf("%d", tree -> data);
            PrintTreeDiagonal( tree -> left, level + 1);
            PrintTreeDiagonal( tree -> right, level + 1);
        }
    }

void main()
{
    int array[20], i, ndata, disptype;
    TREE *btree;
    printf("This Program Demonstrates the Binary Tree Creation\n");
    printf("and Traversal for Binary Search:\n\n");
    printf("Enter Number of Elements in Data list:");
    scanf("%d", &ndata);
    printf("%d\n", ndata);
    printf("\nEnter Data in Ascending Order;\n");
    for(i = 0; i < ndata; i++)
    {
        printf("Data[%d]? = ", i);
        scanf("%d", &array[i]);
        printf("%d\n", array[i]);
    }
    btree = BinaryTree ( array, 0, ndata - 1);
    printf("Binary Tree Creation Done !.\n");
    printf("\nTree Display Style: [1]-Triangular [2]-Diagonal form:");
    scanf("%d", &disptype);
    printf("%d\n", disptype);
    printf("\nBinary Tree is :\n");
    if (disptype == 1)
        PrintTreeTriangle(btree, 1);
    else
        PrintTreeDiagonal(btree,1);
    printf("\nPr-Order Traversal:");
    PreOrder(btree);
    printf("\nIn-Order Traversal:");
    InOrder (btree );
    printf("\nPost-Order Traversal:");
    PostOrder(btree);
    printf("\n");
}
































// {
// }TREE;
// struct TREE *left;
// int data;
// struct TREE *right;
// TREE *BinaryTree (nArray, low, high)
// int *nArray, low, high;
// {
// TREE *tree;
// int mid;
// mid = (int) (low + high )/2;
// if(!(tree = (TREE*)malloc(sizeof( TREE))))
// {
// }
// printf("Error: Out of Memory.!");
// return(tree);
// tree -> data = nArray[mid];
// /* Table lower ptr is equal to higher ptr then no further division */
// if(low >= high)
// {
// }
// tree -> left = NULL;
// tre -> right = NULL;
// return(tree);
// /* Divide and Conquer Method: i.e. Divide the table into two equal
// halves until no further division is possible */
// if (low <= mid - 1)
// tree -> left = BinaryTree (nArray, low, mid-1);
// }
// else
// tree -> left = NULL;
// if(mid + 1 <= high)
// else
// tree -> right = BinaryTree (aArray, mid + 1, high); UIATR
// tree -> right = NULL;
// return(tree);