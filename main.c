#include "stdlib.h"
#include <stdio.h>

int main()
{
	long int c1, c2;
	long int doors[3];
	long int car, choice, choice_tmp;
	long int car_chosen, goat_chosen;
	long int car_chosen_tmp, goat_chosen_tmp;
	for(car_chosen=0, goat_chosen=0, car_chosen_tmp=0, goat_chosen_tmp=0, c1=0;c1<10000;c1++)
	{
		//we setup the initial conditions
		printf("\nIteration Number #%d",c1);
		//first, where is the car? in variable "car" only!
		car = rand()%3;
		printf("\nThe hosts knows that the car is in door #%d", car+1);
		for(c2=0;c2<3;c2++)
		{
			if(c2==car)
				doors[c2]=2;
			else
				doors[c2]=1;
		}
		
		//second, what is the contestant choice? this is in the variable "choice"
		choice = rand()%3;
		choice_tmp=choice;
		printf("\nThe contestant 'X' initially chooses door #%d", choice+1);
		//Then, we open a door (not the one choosen by the contestant, nor the one where the car is)
		for(c2=0;c2<3;c2++)
		{
			if(c2==choice || c2==car)
				continue;
			else
				doors[c2]=0;	//a zero signals that the door was open
			printf("\nThen the hosts reveals that behind the door number #%d there is a goat", c2+1);
			break;
		}
	
		//then the contestant changes his/her mind and switches
		for(c2=0;c2<3;c2++)
		{
			if(doors[c2]==0 || c2==choice)
				continue;
			else
				choice=c2;	//a zero signals that the door was open
			printf("\n\nIf 'X' switches his choice to #%d\t||   If 'X' stays with his choice (#%d)", choice+1, choice_tmp+1);
			break;
		}
		
		//then we see if the car was behind our choice
	
		if(doors[choice]==2)
		{
			car_chosen++;
			printf("\nThe contestant found a car!!\t");
		}
		else
		{
			goat_chosen++;
			printf("\nThe contestant found a goat...\t");
		}
		if(doors[choice_tmp]==2)
		{
			car_chosen_tmp++;
			printf("\t||   The contestant found a car!!");
		}
		else
		{
			goat_chosen_tmp++;
			printf("\t||   The contestant found a goat...");
		}
		if(printf("\nGoats: %d\tCars: %d", goat_chosen, car_chosen)<18)
			printf("\t");
		printf("\t\t||   Goats: %d\tCars: %d", goat_chosen_tmp, car_chosen_tmp);
		printf("\nThe current ratio is	%.4f\t", ((float)car_chosen)/((float)goat_chosen+(float)car_chosen));
		printf("\t||   The current ratio is	%.4f\n", ((float)car_chosen_tmp)/((float)goat_chosen_tmp+(float)car_chosen_tmp));
		//getc(stdin);
	}



	return 0;

}