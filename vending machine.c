

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int picturemenu();
int menu();
int payment();
int calculateChange(int, int);
void drinkPic(int);

int totalSum = 0;
int origPrice = 0;
int menuChoice = 0;
int picture;

int main()
{
	int drink = 0;
	int price = 0;
	int water = 10, orangeJuice = 10, appleJuice = 10, sprite = 10, cola = 10;

	menuChoice = picturemenu(drink);
	if (menuChoice <= 0)
		return 1;

	while (1)
	{
		if (price != 0) {

			price = calculateChange(price, drink);
		}
		else {



			drink = menu();
			if (drink == 6)
			{
				printf("Good bye.\n");
				break;
			}

			else if (drink < 1 || drink > 6)
			{
				printf("Invalid choice.\n");
			}

			else
			{
				switch (drink) {

				case 1:
					if (water > 0) {
						printf("The price is 9 nis.\n");
						origPrice = price = 9;
						--water;
						price = calculateChange(price, drink);
					}
					else {
						printf("There are no bottles of water left.\n");
					}
					break;

				case 2:
					if (orangeJuice > 0) {
						printf("The price is 8 nis.\n");
						origPrice = price = 8;
						--orangeJuice;
						price = calculateChange(price, drink);
					}
					else {
						printf("There is no bottles of Apple juice left.\n");
					}
					break;

				case 3:
					if (appleJuice > 0) {
						printf("The price is 8 nis.\n");
						origPrice = price = 8;
						--appleJuice;
						price = calculateChange(price, drink);
					}
					else {
						printf("There are no bottles of Orange juice left.\n");
					}
					break;

				case 4:
					if (sprite > 0) {
						printf("The price is 4 nis.\n");
						origPrice = price = 4;
						--sprite;
						price = calculateChange(price, drink);
					}
					else {
						printf("There are no bottles of Sprite left.\n");
					}
					break;

				case 5:
					if (cola > 0) {
						printf("The price is 4 nis.\n");
						origPrice = price = 4;
						--cola;
						price = calculateChange(price, drink);
					}
					else {
						printf("There are no bottles of Cola left.\n");
					}
					break;

				default:
					;
				}
			}

		}

	}

	return 0;

}

int picturemenu()
{
	printf("Please enter drawing's size:\n");
	scanf("%d", &menuChoice);
	if (menuChoice <= 0)
	{
		printf("Invalid size.\n");
	}

	return menuChoice;
}

int menu()
{
	int choice;

	printf("********************\n");
	printf("* Please choose:   *\n");
	printf("* 1. Water.        *\n");
	printf("* 2. Orange juice. *\n");
	printf("* 3. Apple Juice.  *\n");
	printf("* 4. Sprite.       *\n");
	printf("* 5. Cola.         *\n");
	printf("* 6. exit          *\n");
	printf("********************\n");

	scanf("%d", &choice);
	return choice;
}


int calculateChange(int price, int drink)
{
	int money = payment(price);
	totalSum += money;
	int change = price - money;

	if (change < 0)
	{
		change = totalSum - origPrice;
		printf("Your change is: %d nis.\n", change);
		int sum10, sum5, sum2, sum1;
		sum10 = change / 10;
		change = change % 10;
		sum5 = change / 5;
		change = change % 5;
		sum2 = change / 2;
		change = change % 2;
		sum1 = change;
		printf("You get back (1, 2, 5, 10): %d %d %d %d.\n\n", sum1, sum2, sum5, sum10);

		printf("Thank you for buying!\n\n");
		drinkPic(drink);

		totalSum = 0;
		origPrice = 0;

		return 0;

	}
	else if (change > 0)
	{
		printf("The amount does not suffice! Please enter %d more nis.\n", change);

		return change;
	}
	else
	{
		printf("Thank you for buying!\n\n");
		totalSum = 0;
		origPrice = 0;
		drinkPic(drink);

		return 0;


	}
}

int payment()
{
	int sh1, sh2, sh5, sh10;//sh=shekel

	printf("To pay please enter 4 numbers. The first number is the amount of 1 nis coins, the second is the amount of 2 nis coins, then 5 and 10\n");
	printf("Please enter payment (1, 2, 5, 10):\n");

	scanf("%d%d%d%d", &sh1, &sh2, &sh5, &sh10);

	int money = 1 * sh1 + 2 * sh2 + 5 * sh5 + 10 * sh10;

	return money;
}


void waterPick(int menuChoice)
{
	int a, b;
	for (a = 0; a < menuChoice - 1; a++)
	{
		for (b = 0; b < menuChoice * 2; b++)
			printf("W");
		printf("\n");
	}
	for (a = 0; a < 2; a++) {
		printf("W");
		for (b = 0; b < menuChoice * 2 - 2; b++)
			printf(" ");
		printf("W\n");

	}
	for (a = 0; a < menuChoice - 1; a++)
	{
		for (b = 0; b < menuChoice * 2; b++)
			printf("W");
		printf("\n");
	}
}

void orangePick(int menuChoice)
{
	int a, b;

	for (a = 0; a < menuChoice; a++)
	{
		for (b = 0; b <= a; b++)
		{
			printf("O");
		}
		printf("\n");
	}
}

void spritePic(int menuChoice)
{
	int a, b, c;
	for (a = menuChoice; a > 0; a--) {

		for (b = 0; b < a - 1; b++) {
			printf(" ");
		}
		for (c = 0; c < menuChoice * 2 - 1 - b * 2; c++)
		{
			printf("S");
		}
		printf("\n");

	}

}

void colaPic(int menuChoice)
{
	int a, b, c;

	for (a = menuChoice; a > 0; a--)
	{

		for (c = 0; c < menuChoice - a; c++)
		{
			printf(" ");
		}
		for (b = 0; b < menuChoice * 2 - 1 - c * 2; b++)
		{
			printf("C");
		}


		printf("\n");
	}
	for (a = menuChoice; a > 0; a--)
	{
		for (b = 0; b < a - 1; b++)
		{
			printf(" ");
		}
		for (c = 0; c < menuChoice * 2 - 1 - b * 2; c++)
		{
			printf("c");
		}
		printf("\n");
	}
}

void applePick(int menuChoice)
{
	int a, b, c;

	for (a = menuChoice; a > 0; a--)
	{

		for (b = 0; b < a - 1; b++)
		{
			printf(" ");
		}
		for (c = 0; c < menuChoice - b; c++)
		{
			printf("A");
		}
		printf("\n");
	}
}

void drinkPic(int drink)
{

	switch (drink)
	{
	case 1:
		waterPick(menuChoice);
		break;
	case 2:
		orangePick(menuChoice);
		break;
	case 3:
		applePick(menuChoice);
		break;
	case 4:
		spritePic(menuChoice);
		break;
	case 5:
		colaPic(menuChoice);
		break;

	default:
		break;
	}
}
}
