//
// Created by Aditya Ved on 03/11/22.
//

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
int player_id;
struct node *next;
};
􏰨􏰫􏰬􏰩􏱂􏰫 􏰹􏱄􏱮􏰾 􏲤􏰨􏰫􏱇􏰬􏰫􏱞 􏲤􏰸􏰫􏰬􏱞 􏲤􏰹􏰾􏱆􏱨􏰹􏱄􏱮􏰾􏰲
int main() {
    int n, k, i, count;

    printf("\n Enter the number of players : ");
    scanf("%d", &n);
    printf("\n Enter the value of k (every kth player gets eliminated): "); scanf("%d", &k);
// Create circular linked list containing all the players
    struct node * start = malloc(sizeof(struct node));
    start->player_id = 1;
    struct node * ptr = start;
    for (i = 2; i <= n; i++)
    {
        􏰹􏰾􏱆􏱨􏰹􏱄􏱮􏰾 􏰰 􏱅􏱇􏱉􏱉􏱄􏱂􏰻􏰨􏰱􏲨􏰾􏱄􏰺􏰻􏰨􏰫􏰬􏰩􏱂􏰫 􏰹􏱄􏱮􏰾􏱁􏱁􏰲 􏰸􏰫􏰬􏱼􏱰􏰹􏰾􏱝􏰫 􏰰 􏰹􏰾􏱆􏱨􏰹􏱄􏱮􏰾􏰲 􏰹􏰾􏱆􏱨􏰹􏱄􏱮􏰾􏱼􏱰􏰸􏱉􏱇􏲕􏰾􏰬􏱨􏰱􏱮 􏰰 􏰱􏰲 􏰹􏰾􏱆􏱨􏰹􏱄􏱮􏰾􏱼􏱰􏰹􏰾􏱝􏰫􏰰􏰨􏰫􏱇􏰬􏰫􏰲
        􏰸􏰫􏰬􏰰􏰹􏰾􏱆􏱨􏰹􏱄􏱮􏰾􏰲
    }
    for (count = n; count > 1; count --)
    {
        􏰺􏱄􏰬 􏰻ptr = ptr–>next;
        ptr–>next = ptr–>next–>next; // Remove the eliminated player from the circular linked list

    }
    printf("\n The Winner is Player %d", ptr–>player_id); getche();
    􏰬􏰾􏰫􏰩􏰬􏰹 􏰷􏰲