#include<stdio.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
/* Tree struct TREE */

typedef struct TREE
{
    int data;
    struct TREE *left;
    struct TREE *right;
}TREE;
/* Insert data into Tree */
TREE *InsertTree(data, p)
int data;
TREE *p;

{
    /*Is Tree NULL */
    if(!p)
    {
        p = (TREE*)malloc(sizeof(TREE));
        p-> data = data;
        p-> left = NULL;
        p-> right = NULL;
        return(p);
    }
    /* Is data less than the parent elment*/
    if (data < p->data)
    {
        p-> left = InsertTree(data, p-> left);
    }else{
        /*Is data greater than the parent elment*/
            if (data > p->data)
            {
                p-> right = InsertTree(data, p-> right);
            }
    }
    return(p);
    

}
/*Print Tree*/

void PrintTree(tree, level)
TREE *tree;
int level;
{
    int i;
    if(tree)
    {
        PrintTree(tree-> right, level + 1);
        printf("\n\n");

        for(i = 0; i<level; i++){
            printf("     ");
        }
        printf("%d", tree->data);
        PrintTree(tree->left,level+1);
    }
}

/* Computes Tree Depth, Befor Calling This Fuction Initialize 'depth' to ZERO */
void TreeDepth(tree, depth, level)
TREE *tree;
int *depth;
int level;
{
    if (tree)
    {
        if(level> *depth)
                *depth = level;
        TreeDepth(tree -> left, depth, level + 1);
        TreeDepth(tree -> right, depth, level + 1);
    }
    
}

/* Replace the Node at which key is found with last right key of a left child */

TREE *Del(r,q)
TREE *r, *q;
{
    TREE *dnode;

    if (r-> right != NULL)
    {
        r -> right = Del(r->right, q);
    }
    else
    {
        dnode = r;
        q->data = r->data;
        r = r-> left;
        free(dnode);
    }
    return(r);
}
/* */

TREE *DeleteElement(p, data)
TREE *p;
int data;
{
    TREE *q;
    if(!p)
    {
        printf("\nNon Existent Data\n");
        return(p);
    }
    else
    {
        if (data)
        {
            p -> left = DeleteElement(p->left,data);
        }
        else{
            if (data > p ->data)
            {
                p-> right = DeleteElement(p-> right, data);
            }else{
                q=p;
                if (q->right == NULL)
                {
                   p=q->left;
                   free(q);
                }else{
                    if (q->left == NULL)
                    {
                       p=q->right;
                       free(q);
                    }else{
                        q->left = Del(q->left, q);
                    }
                    
                }
                
            }
            
        }
        
    }
    return(p);
}


/// @brief 
void main()
{
    int data, depth;
    TREE *tree = NULL;
    printf("\nTree-Insert and Delete Operation:\n");
    while (1)
    {
        printf("\nKey to Insert<0>?");
        scanf("%d", &data);
        printf("%d\n", data);
        if (data == 0)
        {
            break;
        }
        tree = InsertTree(data, tree);
        printf("\nTree Display:\n");
        PrintTree(tree, 1);
        depth = 0;
        TreeDepth(tree, &depth, 0);
        printf("\nTree Depth = %d\n", depth);
        
    }while (1)
    {
       printf("\nKey to Delete <0>?");
       scanf("%d", &data);
       printf("%d\n", data);
       if (data == 0)
       {
         break;
       }
       tree = DeleteElement(tree, data);
       printf("\nTree display:\n");
       PrintTree(tree, 1);

       depth = 0;

       TreeDepth(tree, &data, &depth, 0);
       printf("\nTree Depth = %d\n", depth);
       
    }
    
    
}