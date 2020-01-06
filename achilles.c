#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COMPUTATIONS 10000

/*To programma douleuei apsoga gia MAXNUM=100000 */

/*Gia COMPUTATION= */
/*1000		time~1 second	*/
/*10000 	time~60 seconds */
/*100000	time>>10 minutes*/

int main(void)
{

	/*Arxikopoihsh tou fitrou sunarthsh toy xronoy  */
	long currtime;
	currtime= time(NULL);
	printf("Current time is %ld\n\n", currtime);
  	srand((unsigned int) currtime);

	/*Metablhtes  */
	int a_counter=0,counter; 	//Metriths kai metriths axilleiwn
	int x,y,z,n;			//Metablhtes twn rand
	int dunamh2,dunamh;		//Dunameis tou 2 kai dunameis tou 3 kai panw
	int i,k;			//Gia tis epanalhpseis
	int flag,flag1,flag2;		//flags
	int dunamh_temp1,dunamh_temp2;	//proswrines dunameis gia elenxous
	int rem,large,small,gcd_temp;	//euresh ekp/gcd


	for(counter =1; counter <= COMPUTATIONS; counter ++)	//Epanalhpsh poy ginontai ola
	{

		/*Se kathe epanalipsh arxikopoiountai ola sumfwna me parakatw  */
		dunamh2=0;
		dunamh=0;
		dunamh_temp1=0;
		dunamh_temp2=0;
		large=0;
		small=0;
		rem=0;
		gcd_temp=0;
		i=2;
		flag2=0;

		y = rand() % COMPUTATIONS + 1;
    		z = rand() % COMPUTATIONS + 1;
    		x=((y%32768)+1)*((z%32768)+1)+1;
    		n=x;

		/*Diairesh tou arithmou me 2 kai apothikeush twn dunamewn  */
		while(x%i == 0)
		{
			x=x/i;
			dunamh2++;
		}

		/*Elenxoi gia thn dunamh tou 2  */

		if(dunamh2>=2)				//O arithmos diairethike me to 2 parapanw apo 2 fores,ara krataw auth th dunamh
		{
			dunamh_temp1=dunamh2;
		}
		else if (dunamh2==0)			// Mporei na mhn diairitai me to 2 px 675
		{
			flag1=1;
		}
		else if (dunamh2==1)			//Diareitai mono mia fora ara den mporei na einai plhrhs dunamewn
		{
			flag=0;
			continue;
		}

		/*Epanalhpsh gia diairetes tous prwtous arithmous 3,5,7 ktp  */
		for(i=3; i*i<=x; i=i+2)
		{
			/*Diairesh toy enapomeinontos arithmoy me 3,5,7 ktp */
			while(x%i==0)
 			{
				x=x/i;
				dunamh++;
			}

			/*Sthn periptwsh poy exoume tis proswrines dunameis !=0  */
			if( dunamh_temp1!=0 && dunamh_temp2!=0 && dunamh_temp1!=1 && dunamh_temp2!=1 && dunamh!=1)
			{
					if(dunamh_temp1==dunamh_temp2) 		//An einai ises
					{
						gcd_temp=dunamh_temp1;	//bale sto proswrino ekp mia apo tis duo dynameis px thn 1
						dunamh_temp1=dunamh_temp2; // kane swap metaksei twn proswrinwn dunamewn kai sunexise
						dunamh_temp2=dunamh;
						continue;
					}
					else if(dunamh_temp1>dunamh_temp2)
					{
						large=dunamh_temp1;
						small=dunamh_temp2;
					}
					else
					{
						large=dunamh_temp2;
						small=dunamh_temp1;
					}

					while(small)				//Euresh ekp/gcd opou einia to large
					{
						rem=large%small;
						large=small;
						small=rem;
					}

					if(x>i)					//An  x>i mporei na exei kai alla i san diairetes
					{
						gcd_temp=large;		//proswrinh apothikeush tou large sto gcd_temp
					}
					else if(x==1)				//Exoume x==i ara den uparxei allos diaireths
					{
						if( large==dunamh || gcd_temp==dunamh ) // An to large h to gcd_temp einai iso me thn dunamh tou i fuge
						{
							continue;
						}
						else					//Alliws einai axilleios
						{
							printf("%d is achilles number \n",n);
							a_counter++;
							flag2=1;
						}
					}
				}

			/*Elegxoi gia tis dunameis twn i 3,5,7 klp  */
			if(flag1==1)			//An o arithmos den exei diairethei me to 2
			{
				dunamh_temp1=dunamh;	//pale thn dunamh tou ekastote i sthn prwth proswtinh
				flag1=0;		//arxikopoihse to flag
				dunamh=0;		//arxikopoihse thn dunamh
				continue;		//fuge
			}
			if(dunamh==1)			//Den einia PD,arxikoipoihse ta panta kai fuge
			{
				dunamh_temp1=0;
				dunamh_temp2=0;
				flag=0;
				break;
			}
			else if(dunamh==0)		//Mporei na exei allous diairetes px oxi to i=3 alla nai to i=5 alla sunexizei
			{
				continue;
			}
			else				//Dunamh megaluterh tou 2
			{
				if(dunamh_temp1==0)	//An den exei diairethei me 2;
				{
					dunamh_temp1=dunamh;
					dunamh=0;
				}
				else			//An to temp1 einai hdh arithmos
				{
					dunamh_temp2=dunamh;
					dunamh=0;
				}
			}

		}

		for(k=3;k<=x; k=k+2)			//Elegxos an ton x pou exei meinei mporei na diairethei parapanw, sunhthws menei n=5,7,11 ktl
		{
			if(x==k)		//An brethei oti mporoume na ton diairesoyme tote den tha einai PD
			{
				dunamh_temp2=0;
			}
		}


		/*Elexnoi gia mikroterous arithmous ~10000 opou oi proswrines dunameis exoun parei arithmo mono mia fora  */
		if(dunamh_temp1!=0 && dunamh_temp1!=0 && dunamh_temp1!=1 && dunamh_temp2!=1)
		{
			if(dunamh_temp1>dunamh_temp2)
        		{
				large=dunamh_temp1;
                		small=dunamh_temp2;
            		}
        		else
        		{
				large=dunamh_temp2;
                		small=dunamh_temp1;
            		}

			while(small)
            		{
                		rem=large%small;
                		large=small;
				small=rem;
            		}

			if(large!=1 )		//An to large den einai 1 tote to gcd twn arithmwn einai megalutero to 1 ara den einai axilleioi
            		{
            			continue;
            		}
            		else if(flag2!=1)	//An exei hdh ektypwthei o arithmos sthn apo panw loupa
            		{
        			printf("%d is achilles number \n",n);
                		a_counter++;
            		}
		}

	}

printf("Found %d achilles numbers after %d repeats \n",a_counter, COMPUTATIONS);

return 0;
}



