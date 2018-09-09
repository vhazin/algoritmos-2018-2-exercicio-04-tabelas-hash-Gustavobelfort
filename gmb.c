#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} t_hashTableNode;

t_hashTableNode *hashMapChained[1];
int counterH = 0;

int hash(int value, int mod);
void chainedHashInsert(int value, int mod);
void printList(int i);
void removeList(int i);
void printHashMap(int size);

int main(int argc, char const *argv[])
{

    int elems, size, tests_number = 0;

    scanf("%d", &tests_number);

    while (tests_number > 0)
    {
        scanf("%d %d", &size, &elems);

        t_hashTableNode *hashMapChained = malloc(sizeof(int) * size);

        for (int j = 0; j < elems; j++)
        {
            int element;
            scanf("%d", &element);
            chainedHashInsert(element, size);
        }

        printHashMap(size);
        tests_number--;
    }
}

int hash(int value, int mod)
{
    return (value % mod);
}

void chainedHashInsert(int value, int mod)
{
    int probe = hash(value, mod);
    if (hashMapChained[probe] == NULL)
    {
        hashMapChained[probe] = malloc(sizeof(t_hashTableNode)); // then creates a new list
        hashMapChained[probe]->value = value;
        hashMapChained[probe]->next = NULL;
    }
    else
    {
        t_hashTableNode *hashTableNode = hashMapChained[probe];
        while (hashTableNode->next != NULL)
        {
            hashTableNode = hashTableNode->next;
        }
        hashTableNode->next = malloc(sizeof(t_hashTableNode)); // inserst the value as the last element of the list
        hashTableNode->next->value = value;
        hashTableNode->next->next = NULL;
    }
}

void printList(int hashMapRow)
{
    t_hashTableNode *hashMapNode = hashMapChained[hashMapRow];

    int first = 1;

    if (hashMapNode == NULL)
    {
        printf("%d -> \\ \n", counterH);
        return;
    }
    else
    {
        while (hashMapNode != NULL)
        {
            if (first == 1)
            {
                printf("%d -> %d", counterH, hashMapNode->value);
                first = 0;
            }
            else
            {
                printf(" -> %d", hashMapNode->value);
            }
            hashMapNode = hashMapNode->next;
        }
        printf(" -> \\\n");
    }
}

void removeList(int hashMapRow)
{
    hashMapChained[hashMapRow] = NULL;
}

void printHashMap(int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printList(i);
        removeList(i);
        counterH += 1;
    }

    counterH = 0;
}
