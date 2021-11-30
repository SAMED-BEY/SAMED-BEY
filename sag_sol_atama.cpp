#include <iostream>
#include <stdlib.h>

using namespace std;

typedef class TreeNode{
public:
TreeNode *leftPtr;
TreeNode *rightPtr;
int data;
} TreeNode, *TreeNodePtr;





void insertNode(TreeNodePtr *treePtr, int valve)
{
    if(*treePtr == NULL)
    {
        *treePtr =new TreeNode;
        if(*treePtr!=NULL)
        {

            (*treePtr)-> data=valve;
            (*treePtr)-> leftPtr=NULL;
            (*treePtr)-> rightPtr=NULL;
        }else
        {
            cout<<"BM Alloc"<<endl;

        }
    }

    else
    {

        if(valve<(*treePtr)-> data)
            insertNode(&(*treePtr)->leftPtr ,valve );
        else
            if(valve> ( *treePtr )-> data)
             insertNode(&(*treePtr)->rightPtr ,valve );
    }


}

int main()
{
    int i;
    int dizi[7]={49,28,83,18,40,71,97};

    TreeNodePtr rootPtr=NULL;

    for(int i=0;i<7;i++)
    {
        int item=dizi[i];
        insertNode(&rootPtr,item);

    }

    return 0 ;

}


