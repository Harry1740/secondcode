#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *front=NULL;
NODE *rear=NULL;
NODE *create_memory()
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    return ptr;
}
void enqueue_list()
{
    NODE *ptr=create_memory();
    int item;
    printf("Enter the item you want\n");
    scanf("%d",&item);
    ptr->data=item;
    ptr->next=NULL;
    if(rear==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
    return;
}
void dequeue_list()
{
    NODE *ptr;
    if(front==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ptr=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        free(ptr);
        printf("Node deleted\n");
    }
    return;
}
void display()
{
    NODE *ptr;
    if(front==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ptr=front;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("1.Enqueue Operation\n2.Dequeue Operation\n3.Display\n");
        printf("Enter the choice you want\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue_list();
                break;
            case 2:
                dequeue_list();
                break;
            case 3:
                display();
                break;
        }
    }while(choice!=0);
}