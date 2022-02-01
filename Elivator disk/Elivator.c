
#include <stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 199
void display(int a, int max)
{
    a != max ? printf(" %d -->", a) : printf(" %d", a);
}
int main()
{
    int queue[20];
    int head, max, q_size, temp, total_seek_time;
    int dloc;
    printf("\nEnter the queue size : ");
    scanf("%d", &q_size);
    printf("\nEnter the queue of disk portions to be read : ");
    for (int i = 0; i < q_size; i++)
    {
        scanf(" %d", &queue[i]);
    }
    printf("\nEnter head position : ");
    scanf("%d", &head);
    queue[q_size] = head;
    q_size++;
    for (int i = 0; i < q_size; i++)
    {
        for (int j = i; j < q_size; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    max = queue[q_size - 1];

        for (int i = 0; i < q_size; i++)
    {
        if (head == queue[i])
        {
            dloc = i;
            break;
        }
    }
    printf("\nSequence\n\n");
    if (abs(head - LOW) <= abs(head - HIGH))
    {
        for (int j = dloc; j >= 0; j--)
        {
            display(queue[j], max);
        }
        printf(" 0 --> ");
        for (int j = dloc + 1; j < q_size; j++)
        {
            display(queue[j], max);
        }
    }
    else
    {
        for (int j = dloc + 1; j < q_size; j++)
        {
            display(queue[j], max);
        }
        printf(" 0 --> ");
        for (int j = dloc; j >= 0; j--)
        {
            display(queue[j], max);
        }
    }
    total_seek_time = head + max;
    float avg_seek_time = total_seek_time / (float)(q_size - 1);

    printf("\n\nTotal Seek Time is : %d", total_seek_time);
    printf("\nAverage Seek Time is : %.3f\n\n", +avg_seek_time);

    return 0;
}