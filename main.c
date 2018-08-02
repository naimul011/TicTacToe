#include <stdio.h>
#include <stdlib.h>
#define MaxGrid 10

#define P1 1
#define P2 2

int grid_size;
char grid[MaxGrid][MaxGrid];
int turn = P1;
int playing = 1;
int x,y;


int main()
{

    printf("Enter the size of the grid\n");
    scanf("%d",&grid_size);

    if(init_grid(grid_size))
    {
        show_grid(grid_size);
    }

    turn = P1;

    while(playing)
    {


        if(turn == P1)
        {
            int invalid = 1;

            while (invalid)
            {   printf("Player X. Choose Location (x,y)\n");
                scanf("%d %d",&x,&y);
                invalid = check_location_range(x,y);
            }

            //make_move(x,y,'X');

            make_move(x,y,'X');
            show_grid(grid_size);

            if(player_won('X'))
            {   printf("*********************\n");
                printf("Player X has won\n");
                printf("*********************\n");
                playing = 0;
                break;
            }
            if(draw_check())
            {
                printf("Game over: there are no winners.\n");
                playing = 0;
                break;
            }
            turn = P2;

        }
        else if(turn == P2)
        {
            int invalid = 1;

            while (invalid)
            {   printf("Player O. Choose Location (x,y)\n");
                scanf("%d %d",&x,&y);
                invalid = check_location_range(x,y);

            }

            make_move(x,y,'O');
            show_grid(grid_size);

            if(player_won('O'))
            {   printf("*********************\n");
                printf("Player O has won\n");
                printf("*********************\n");
                playing = 0;
                break;
            }

            if(draw_check())
            {
                printf("Game over: there are no winners.\n");
                playing = 0;
                break;
            }
            turn = P1;
        }

    }
    return 0;
}


int check_location_range(int x,int y)
{

    if (x < 0 || x  >= grid_size || y < 0 || y  >= grid_size)
    {

        printf("Index out of range, please re-enter.\n");
        return 1;
    }
    else if(grid[x][y]!='.')
    {
        printf("This location is already taken.\n");
        return 1;
    }

    return 0;
}
void show_grid(grid_size)
{
    int i,j;
    printf("\t");
    for(i = 0 ;i <grid_size;i++)
    {
        printf("%d\t",i);
    }
    printf("\n");

    for(i = 0; i <grid_size; i++)
    {
        printf("%d\t",i);
        for(j = 0; j <grid_size; j++)
        {
            printf("%c\t",grid[i][j]);
        }
        printf("\n");
    }
}

int init_grid(int grid_size) {

    if(grid_size<0 || grid_size > MaxGrid)
    {
        return 0;
    }

    int i ,j ;

    for(i = 0; i <grid_size; i++)
    {
        for(j = 0; j<grid_size; j++)
        {
            grid[i][j] = '.';
        }
    }

    return 1;
}

int player_won(int letter) {

    char ch = (char)letter;

    int winner = 0;
    int i,j;

    for(i = 0; !winner && i < grid_size; i++)
    {
        j  = 0;
        while(grid[i][j] == ch && j < grid_size)
        {
            j++;
        }
        if(j==grid_size)
            winner = 1;

    }
    for(i = 0; !winner && i < grid_size; i++)
    {
        j  = 0;
        while(grid[j][i] == ch && j < grid_size)
        {
            j++;
        }
        if(j==grid_size)
            winner = 1;

    }
    j = 0;
    for(i = 0; !winner && i < grid_size; i++)
    {

        if(grid[j][i] == ch && j < grid_size)
        {
            j++;
        }
        if(j==grid_size)
            winner = 1;

    }

    j = 0;
    for(i = 0; !winner && i < grid_size; i++)
    {

        if(grid[i][i] == ch && j < grid_size)
        {
            j++;
        }
        if(j==grid_size)
            winner = 1;

    }

    j = 0;
    for(i = 0; !winner && i < grid_size; i++)
    {

        if(grid[i][grid_size-i-1] == ch && j < grid_size)
        {
            j++;
        }
        if(j==grid_size)
            winner = 1;

    }



    return winner;
}

int draw_check()
{


    int i,j;
    for(i = 0; i <grid_size ; i++)
    {
        for(j = 0; j < grid_size ;j ++)
        {
            if(grid[i][j]=='.')
            {
                return 0;
            }
        }
    }
    return 1;
}

int make_move(int x, int y,int letter) {


    grid[x][y] = (char)letter;

    return 0;

}
