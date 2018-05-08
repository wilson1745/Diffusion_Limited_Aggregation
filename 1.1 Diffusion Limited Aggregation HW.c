#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 50						// Define the scope
#define MAX 250						// Cluster number

int Xinc(int);						// function which define row + 1
int Xdec(int);						// function which define row - 1
int Yinc(int);						// function which define column + 1
int Ydec(int);						// function which define column - 1
void MoveRandom();					// Move at random (up, down, left, right) 
void PrintMap();					// Print the map after all clusters have been selected 

int map[SIZE][SIZE];				// Two dimension array (follow SIZE)
int Xrange, Yrange;					// Value of row & column
int Xcenter, Ycenter;				// Center of two dimension array
int cluster = 0;					// Cluster count

int main(void)
{
   srand(time(0));					
   Xcenter = SIZE / 2;
   Ycenter = SIZE / 2;
   map[SIZE / 2][SIZE / 2] = 1;		// Judge to print # when map[][]=1 

   do {
      do {
      Xrange = rand() % SIZE;				// Making random value limited by SIZE
      Yrange = rand() % SIZE;
      } while (map[Xrange][Yrange] == 1);		// Exclude the previous map[][] which equals to 1

      if (map[Xinc(Xrange)][Yrange] == 1 || map[Xdec(Xrange)][Yrange] == 1 || map[Xrange][Yinc(Yrange)] == 1 || map[Xrange][Ydec(Yrange)] == 1) {	
         map[Xrange][Yrange] = 1;
         cluster++;
      }
      else {
         MoveRandom();				
      }
   } while (cluster < MAX);

   PrintMap();							
   printf("\n");

   system("pause");
   return 0;
}
int Xinc(int Xrange)
{
   Xrange++;
   if (Xrange > (SIZE - 1)) {
      return 0;
   }
   else {
      return Xrange;
   }
}
int Yinc(int Yrange)
{
   Yrange++;
   if (Yrange > (SIZE - 1)) {
      return 0;
   }
   else {
      return Yrange;
   }
}
int Xdec(int Xrange)
{
   Xrange--;
   if (Xrange < 0) {
      Xrange = Xrange + SIZE;
      return Xrange;
   }
   else {
      return Xrange;
   }
}
int Ydec(int Yrange)
{
   Yrange--;
   if (Yrange < 0) {
      Yrange = Yrange + SIZE;
      return Yrange;
   }
   else {
      return Yrange;
   }
}
void MoveRandom()
{
   do {
      int Move;
      Move = rand() % 4;

      switch (Move)
      {
         case 0:
            Xrange++;
            if (Xrange > SIZE - 1) {
               Xrange = Xrange - SIZE;
            }
            if (map[Xinc(Xrange)][Yrange] == 1 || map[Xdec(Xrange)][Yrange] == 1 ||	map[Xrange][Yinc(Yrange)] == 1 || map[Xrange][Ydec(Yrange)] == 1) {
               map[Xrange][Yrange] = 1;
               cluster++;
            }
            else {
               map[Xrange][Yrange] = 0;
            }
            break;
         case 1:
            Xrange--;
            if (Xrange < 0) {
               Xrange = Xrange + SIZE;
            }
            if (map[Xinc(Xrange)][Yrange] == 1 || map[Xdec(Xrange)][Yrange] == 1 || map[Xrange][Yinc(Yrange)] == 1 || map[Xrange][Ydec(Yrange)] == 1) {
               map[Xrange][Yrange] = 1;
               cluster++;
            }
            else {
               map[Xrange][Yrange] = 0;
            }
            break;
         case 2:
            Yrange++;
            if (Yrange > (SIZE - 1)) {
               Yrange = Yrange - SIZE;
            }
            if (map[Xinc(Xrange)][Yrange] == 1 || map[Xdec(Xrange)][Yrange] == 1 ||	map[Xrange][Yinc(Yrange)] == 1 || map[Xrange][Ydec(Yrange)] == 1) {
               map[Xrange][Yrange] = 1;
               cluster++;
            }
            else {
               map[Xrange][Yrange] = 0;
            }
            break;
         case 3:
            Yrange--;
            if (Yrange < 0) {
               Yrange = Yrange + SIZE;
            }
            if (map[Xinc(Xrange)][Yrange] == 1 || map[Xdec(Xrange)][Yrange] == 1 || map[Xrange][Yinc(Yrange)] == 1 || map[Xrange][Ydec(Yrange)] == 1) {
               map[Xrange][Yrange] = 1;
               cluster++;
            }
            else {
               map[Xrange][Yrange] = 0;
            }
            break;
            }
  } while (map[Xrange][Yrange] == 0);
}
void PrintMap()
{
   int row, column;				

   for (row = 0; row < SIZE; row++) {
      for (column = 0; column < SIZE; column++) {
         if (map[row][column] == 1) {
            printf("#");
         }
         else {
            printf(" ");
         }
      }
      printf("\n");
   }
}
