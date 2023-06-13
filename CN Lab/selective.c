#include <stdlib.h>
#include <stdio.h>

int n, r;
struct frame
{
    char ack;
    int data;
} frm[10];

void sender()
{
    int i;
    printf("\nEnter the no. of packets to be sent:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter data for packets[%d]: ", i);
        scanf("%d", &frm[i].data);
        frm[i].ack = 'y';
    }
}
void recvack()
{
    int i;
    r = rand() % n;
    frm[r].ack = 'n';
    for (i = 1; i <= n; i++)
    {
        if (frm[i].ack == 'n')
            printf("\nThe packet number %d is not received\n", r);
        else
            printf("\nThe packet number %d is recieved having data %d\n", i, frm[i].data);
    }
}
void resend()
{
    printf("\nResending packet %d", r);
    sleep(2);
    frm[r].ack = 'y';
    printf("\nThe received packet is %d having data %d", r, frm[r].data);
}
int main()
{
    sender();
    recvack();
    resend();
    printf("\nAll packets sent successfully\n");
    return 0;
}