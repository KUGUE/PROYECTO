#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

/* variables globales*/
int snakeX[500];
int snakeY[500];
int tam_snake=5;

int snake_x=5;
int snake_y=5;
bool vivo=true;
int direccion=4; //1 arriba, 2 abajo, 3 izq, 4 derecha

void dibujar()
{

    for(int i=0;i<tam_snake;i++)
    {

      if(i==0)
      {
          textbackground(YELLOW);
      }
      gotoxy(snakeX[i],snakeY[i]);
      cprintf("%c",254);
    }


}

void moverSnake()
{
    gotoxy(snakeX[tam_snake-1],snakeY[tam_snake-1]);
    cout<<" ";

    for(int i=tam_snake-1;i>0;i--)
    {
        snakeX[i]=snakeX[i-1];
        snakeY[i]=snakeY[i-1];
    }

    switch(direccion)
    {
        case 1:
            snakeY[0]=snakeY[0]-1;
        break;
        case 2:
             snakeY[0]=snakeY[0]+1;
        break;
        case 3:
            snakeX[0]=snakeX[0]-1;
        break;
        case 4:
            snakeX[0]=snakeX[0]+1;
        break;
    }

}
void OcultaCursor() {
    CONSOLE_CURSOR_INFO cci = {100, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
int main()
{
    OcultaCursor();
    for(int i=0;i<500;i++)
    {
        snakeX[i]=0;
        snakeY[i]=0;
    }

    snakeX[0]=5;
    snakeY[0]=5;

    snakeX[1]=4;
    snakeY[1]=5;

    snakeX[2]=3;
    snakeY[2]=5;

    snakeX[3]=2;
    snakeY[3]=5;

     snakeX[4]=1;
    snakeY[4]=5;


    while(vivo==true)
    {

       if(kbhit())
       {
         int codigo=(int)getch();
         switch(codigo)
         {
           case 72:
               direccion=1;
            break;
           case 80:
               direccion=2;
            break;
           case 75:
               direccion=3;
            break;
           case 77:
               direccion=4;
            break;
         }
       }
       moverSnake();
       dibujar();
       Sleep(100);
    }
    getch();
    return 0;
}
