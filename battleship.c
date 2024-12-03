#include <stdio.h>
#include <stdlib.h>
#include <time.h>//rand function seed
#include <unistd.h>//adds sleep function
#include <ctype.h>// to convert capital letters into lowercase ones
int field[10][10]={0}, turns = 0, carrierPOS[10][10]={0}, battleshipPOS[10][10]={0}, destroyerPOS[10][10]={0}, submarinePOS[10][10]={0}, patroalBoatPOS[10][10] = {0};
void carrier()//5 tiles
{
	int orientation = rand() % 2 + 1;
	if(orientation == 1)
	{
		int y = rand() % 10;
		int x = rand() % 6;
		for(int i = 0; i < 5; i++)
		{
			field[y][x + i] = 1;
			carrierPOS[y][x + i] = 1;
		}
	}
	else
	{
		int y = rand() % 6;
		int x = rand() % 10;
		for(int i = 0; i < 5; i++)
		{
			field[y + i][x] = 1;
			carrierPOS[y + i][x] = 1;
		}
	}
}
void battleship()//4 tiles
{
	int orientation, placement, placing = 1;
	while(placing == 1)
	{
		placement = 0;
		orientation = rand() % 2 + 1;
		if(orientation == 1)
		{
			int y = rand() % 10;
			int x = rand() % 7;
			for(int i = 0; i < 4; i++)
			{
				placement = placement + field[y][x + i];
			}
			if(placement == 0)
			{
				for(int i = 0; i < 4; i++)
				{
					field[y][x + i] = 1;
					battleshipPOS[y][x + i] = 1;
				}
				placing = 0;
			}
		}
		else
		{
			int y = rand() % 7;
			int x = rand() % 10;
			for(int i = 0; i < 4; i++)
			{
				placement = placement + field[y + i][x];
			}
			if(placement == 0)
			{
				for(int i = 0; i < 4; i++)
				{
					field[y + i][x] = 1;
					battleshipPOS[y + i][x] = 1;
				}
				placing = 0;
			}
		}
	}
}
void destroyer()//3 tiles
{
	int orientation, placement, placing = 1;
	while(placing == 1)
	{
		placement = 0;
		orientation = rand() % 2 + 1;
		if(orientation == 1)
		{
			int y = rand() % 10;
			int x = rand() % 8;
			for(int i = 0; i < 3; i++)
			{
				placement = placement + field[y][x + i];
			}
			if(placement == 0)
			{
				for(int i = 0; i < 3; i++)
				{
					field[y][x + i] = 1;
					destroyerPOS[y][x + i] = 1;
				}
				placing = 0;
			}
		}
		else
		{
			int y = rand() % 8;
			int x = rand() % 10;
			for(int i = 0; i < 3; i++)
			{
				placement = placement + field[y + i][x];
			}
			if(placement == 0)
			{
				for(int i = 0; i < 3; i++)
				{
					field[y + i][x] = 1;
					destroyerPOS[y + i][x] = 1;
				}
				placing = 0;
			}
		}
	}
}
void submarine()//3 tiles
{
        int orientation, placement, placing = 1;
        while(placing == 1)
        {
                placement = 0;
                orientation = rand() % 2 + 1;
                if(orientation == 1)
                {
                        int y = rand() % 10;
                        int x = rand() % 8;
                        for(int i = 0; i < 3; i++)
                        {
                                placement = placement + field[y][x + i];
                        }
                        if(placement == 0)
                        {
                                for(int i = 0; i < 3; i++)
                                {
                                        field[y][x + i] = 1;
					submarinePOS[y][x + i] = 1;
                                }
                                placing = 0;
                        }
                }
                else
                {
                        int y = rand() % 8;
                        int x = rand() % 10;
                        for(int i = 0; i < 3; i++)
                        {
                                placement = placement + field[y + i][x];
                        }
                        if(placement == 0)
                        {
                                for(int i = 0; i < 3; i++)
                                {
                                        field[y + i][x] = 1;
					submarinePOS[y + i][x] = 1;
                                }
                                placing = 0;
                        }
                }
        }
}
void patrolBoat()//2 tiles
{
        int orientation, placement, placing = 1;
        while(placing == 1)
        {
                placement = 0;
                orientation = rand() % 2 + 1;
                if(orientation == 1)
                {
                        int y = rand() % 10;
                        int x = rand() % 9;
                        for(int i = 0; i < 2; i++)
                        {
                                placement = placement + field[y][x + i];
                        }
                        if(placement == 0)
                        {
                                for(int i = 0; i < 2; i++)
                                {
                                        field[y][x + i] = 1;
					patroalBoatPOS[y][x + i] = 1;
                                }
                                placing = 0;
                        }
                }
                else
                {
                        int y = rand() % 9;
                        int x = rand() % 10;
                        for(int i = 0; i < 2; i++)
                        {
                                placement = placement + field[y + i][x];
                        }
                        if(placement == 0)
                        {
                                for(int i = 0; i < 2; i++)
                                {
                                        field[y + i][x] = 1;
					patroalBoatPOS[y + i][x] = 1;
                                }
                                placing = 0;
                        }
                }
        }
}
void printScreen()//self explanitory
{
	printf("    A B C D E F G H I J TURN: %d\n", turns);
	printf("  +--------------------\n");
	for(int y = 0; y < 10; y++)
	{
		if(y < 9)
		{
			printf("%d | ", y + 1);
		}
		else
		{
			printf("%d| ", y + 1);
		}
		for(int x = 0; x < 10; x++)
		{
			if(field[y][x] < 2)
			{
				printf("0 ");
			}
			else if(field[y][x] == 2)
			{
				printf("* ");
			}
			else if(field[y][x] > 2)
			{
				printf("X ");
			}
			else//extrenious else statement somehow managed to stop "X" hit markers from dissapearing
			{
				printf("what the hell");
			}
		}
		printf("\n");
	}
}
int carrierCheck()// checks to see if carrier has tiles left
{
	int carrierLeft = 0;
	for(int y = 0; y < 10; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			if(carrierPOS[y][x] == 1)
			{
				if(field[y][x] == 1)
				{
					carrierLeft = 1;
				}
			}
		}
	}
	return carrierLeft;
}
int battleshipCheck()// checks to see if battleship has tiles left
{
        int battleshipLeft = 0;
        for(int y = 0; y < 10; y++)
        {
                for(int x = 0; x < 10; x++)
                {
                        if(battleshipPOS[y][x] == 1)
                        {
                                if(field[y][x] == 1)
                                {
                                        battleshipLeft = 1;
                                }
                        }
                }
        }
        return battleshipLeft;
}
int destroyerCheck()// checks to see if destroyer has tiles left
{
        int destroyerLeft = 0;
        for(int y = 0; y < 10; y++)
        {
                for(int x = 0; x < 10; x++)
                {
                        if(destroyerPOS[y][x] == 1)
                        {
                                if(field[y][x] == 1)
                                {
                                        destroyerLeft = 1;
                                }
                        }
                }
        }
        return destroyerLeft;
}
int submarineCheck()// checks to see if submarine has tiles left
{
        int submarineLeft = 0;
        for(int y = 0; y < 10; y++)
        {
                for(int x = 0; x < 10; x++)
                {
                        if(submarinePOS[y][x] == 1)
                        {
                                if(field[y][x] == 1)
                                {
                                        submarineLeft = 1;
                                }
                        }
                }
        }
        return submarineLeft;
}
int patroalBoatCheck()// checks to see if patroal boat has tiles left
{
        int patroalBoatLeft = 0;
        for(int y = 0; y < 10; y++)
        {
                for(int x = 0; x < 10; x++)
                {
                        if(patroalBoatPOS[y][x] == 1)
                        {
                                if(field[y][x] == 1)
                                {
                                        patroalBoatLeft = 1;
                                }
                        }
                }
        }
        return patroalBoatLeft;
}
int main()
{
	int winCondition = 0, number, letterNum, counter, selecting, carrierD = 0, battleshipD = 0, destroyerD = 0, submarineD = 0, patroalBoatD = 0;
	char letter;
	srand(time(NULL));
	carrier();
	battleship();
	destroyer();
	submarine();
	patrolBoat();
	printf("Welcome to battleship!\n");
	while(winCondition == 0)// while game not yet won loop
	{
		letterNum = 0;
		selecting = 1;
		turns = turns + 1;
		counter = 0;
		sleep(1);
		number = 0;
		while(selecting == 1)
		{
			printf("Enter the coordinate you wish to attack!\n");
			printScreen();
			scanf(" %c%d", &letter, &number);
			letter = tolower(letter);//code to switch capital letters to lowercase ones
			switch(letter)//switch letters to numbers
			{
				case 'a':
				letterNum = 1;
				break;
				case 'b':
				letterNum = 2;
				break;
				case 'c':
				letterNum = 3;
				break;
				case 'd':
				letterNum = 4;
				break;
				case 'e':
				letterNum = 5;
				break;
				case 'f':
				letterNum = 6;
				break;
				case 'g':
				letterNum = 7;
				break;
				case 'h':
				letterNum = 8;
				break;
				case 'i':
				letterNum = 9;
				break;
				case 'j':
				letterNum = 10;
				break;
				case 'y':
				letterNum = 777;
				break;
			}
			if(letterNum != 0 && !(number > 10 || number < 1))
			{
				selecting = 0;
			}
			else
			{
				if(letterNum == 0 && (number > 10 || number < 1))
				{
					printf("\n\nERROR, SELECT LETTERS A - J\nERROR, SELECT NUMBERS 1 - 10\n\n");
				}
				else if(letterNum == 0)
				{
					printf("\n\nERROR, SELECT LETTERS A - J\n\n");
				}
				else if(number > 10 || number < 1)
				{
					printf("\n\nERROR, SELECT NUMBERS 1 - 10\n\n");
				}
			}
			if(letterNum == 777 && number == 7)//dev code to put the game in an instant win state
			{
				selecting = 0;
				for(int y = 0; y < 10; y++)
				{
					for(int x = 0; x < 10; x++)
					{
						field[y][x] = 2;
					}
				}
			}
		}
		if((field[number - 1][letterNum - 1] == 2) || (field[number - 1][letterNum - 1] == 3))//note for not shooting the same tile twice
		{
			printf("why would you do that? you already shot there\n");
		}
		if(field[number - 1][letterNum - 1] == 1)//hit calculation
		{
			printf("HIT!\n");
			field[number - 1][letterNum - 1] = 3;
		}
		if(field[number - 1][letterNum - 1] == 0)//miss calculation
		{
			printf("MISS!\n");
			field[number - 1][letterNum - 1] = 2;
		}
		if(carrierCheck() == 0 && carrierD == 0)// carrier sunk message
		{
			printf("you sunk the carrier!\n");
			carrierD = 1;
		}
		if(battleshipCheck() == 0 && battleshipD == 0)// battleship sunk message
		{
			printf("you sunk the battleship!\n");
			battleshipD = 1;
		}
		if(destroyerCheck() == 0 && destroyerD == 0)// destroyer sunk message
		{
			printf("you sunk the destroyer!\n");
			destroyerD = 1;
		}
		if(submarineCheck() == 0 && submarineD == 0)// submarine sunk message
		{
			printf("you sunk the submarine!\n");
			submarineD = 1;
		}
		if(patroalBoatCheck() == 0 && patroalBoatD == 0)// patroal boat production
		{
			printf("you sunk the patroal boat!\n");
			patroalBoatD = 1;
		}
		printf("\n\n\n\n\n\n");
		for(int y = 0; y < 10; y++)//sets counter to how many ship tiles are left
		{
			for(int x = 0; x < 10; x++)
			{
				if(field[y][x] == 1)
				{
					counter = counter + 1;
				}
			}
		}
		if(counter == 0)//sees how many ship tiles are left, if 0, ends game
		{
			winCondition = 1;
		}
	}
	printScreen();
	printf("You Won!!! It only took you %d turns!\n", turns);
        return 0;
}
