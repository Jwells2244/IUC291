/* Print out a payroll earnings sheet for the Bloomington Skating company
 *Author: Jonathan Wells 
 *This took me a long time, with a lot of different revisions that I didn't bother committing, since they were either broken 
 *or I didn't like how they look/performed. I also didn't use the file1.c thing since I was unable to obtain it, instead I 
 *just used the values given on the assignment breakdown document.
 * Final version completed on Tuesday February 8th, 2022
 */

#include <stdio.h>
#include <stdlib.h>

void print_statement(double commissionRate, double federalRate, double stateRate, double retirementRate, double bonus){
	int salesTotal, fRateTotal, sRateTotal, rtTotal, bonusTotal, bonus1, fedW, stW, retRate, netPay; //All of these variables either hold a total or are used inside the 
	//switch case in order for calculations to be done, and the output to be printed correctly for each case
	int sales1 = (rand() % (10000 - 1000 + 1)) + 1000;//Calculation the random values for each employee
	int sales2 = (rand() % (10000 - 1000 + 1)) + 1000;
	int sales3 = (rand() % (10000 - 1000 + 1)) + 1000;
	int sales4 = (rand() % (10000 - 1000 + 1)) + 1000;
	int sales5 = (rand() % (10000 - 1000 + 1)) + 1000;
	salesTotal = sales1+sales2+sales3+sales4+sales5;//Calculating the total sales so it can be printed in the top of the output
	int profit = salesTotal*.45; //Calculating Profit
	double re, netPayTotal, comissionTotal; //Variables as doubles that hold the values of sums of doubles
	comissionTotal = 0.0; //Initializing all of the variables to 0
	netPayTotal = 0.0;
	comissionTotal = 0;
	fRateTotal = 0;
	sRateTotal = 0;
	rtTotal = 0;
	bonusTotal = 0;
	//The actual print statements and calculations part ->
	printf("Monthly Statement (February 2022)\n");
	printf("Bloomington Skating Company\nBloomington, IN\nPhone: (812)-855-0000\n");
	printf("MONTHLY SALES: %i\nMONTHLY PROFIT: %i\n", salesTotal, profit);
	printf("================================================================================\n");
	printf("Name   Commission    Bonus     Fed W.    St W.    RT    Net Pay\n");
	printf("--------------------------------------------------------------------------------\n");
	for (int i = 1; i<7; i++){
		switch(i){
			case 1:
			        re = (rand() % (30-1+1)+1);//Re is just a random variable used to do the calculations for the bonus, in multiple steps
				re = re/2.0;
				re = re/100.0;
				bonus1 = profit*(bonus+re);
				fedW = (bonus1+(sales1*commissionRate))*federalRate;
				stW = (bonus1+(sales1*commissionRate))*stateRate;
				retRate = (bonus1+(sales1*commissionRate))*retirementRate;
				netPay = (sales1*commissionRate)+bonus1-fedW-stW-retRate;
				printf("Mr. A:     %.2f%10d%10d%10d%7d%7d\n", sales1*commissionRate,bonus1,fedW, stW, retRate, netPay);
				comissionTotal += sales1*commissionRate;
				fRateTotal += fedW;
				sRateTotal += stW;
				rtTotal += retRate;
				netPayTotal += netPay;
				bonusTotal += bonus1;
				fflush(stdout);
				break;
			case 2:
				re = (rand() % (30-1+1)+1);
                                re = re/2.0;
                                re = re/100.0;
                                bonus1 = profit*(bonus+re);
                                fedW = (bonus1+(sales2*commissionRate))*federalRate;
                                stW = (bonus1+(sales2*commissionRate))*stateRate;
                                retRate = (bonus1+(sales2*commissionRate))*retirementRate;
                                netPay = (sales2*commissionRate)+bonus1-fedW-stW-retRate;
                                printf("Mrs. C:     %.2f%10d%10d%10d%7d%7d\n", sales2*commissionRate,bonus1,fedW, stW, retRate, netPay);
                                comissionTotal += sales2*commissionRate;
                                fRateTotal += fedW;
                                sRateTotal += stW;
                                rtTotal += retRate;
                                bonusTotal += bonus1;
				netPayTotal += netPay;
				fflush(stdout);
				break;
			case 3:
				re = (rand() % (30-1+1)+1);
                                re = re/2.0;
                                re = re/100.0;
                                bonus1 = profit*(bonus+re);
                                fedW = (bonus1+(sales3*commissionRate))*federalRate;
                                stW = (bonus1+(sales3*commissionRate))*stateRate;
                                retRate = (bonus1+(sales3*commissionRate))*retirementRate;
                                netPay = (sales3*commissionRate)+bonus1-fedW-stW-retRate;
                                printf("Mr. B:     %.2f%10d%10d%10d%7d%7d\n", sales3*commissionRate,bonus1,fedW, stW, retRate, netPay);
                                comissionTotal += sales3*commissionRate;
                                fRateTotal += fedW;
                                sRateTotal += stW;
                                rtTotal += retRate;
                                bonusTotal += bonus1;
				netPayTotal += netPay;
				fflush(stdout);
				break;
			case 4:
				re = (rand() % (30-1+1)+1);
                                re = re/2.0;
                                re = re/100.0;
                                bonus1 = profit*(bonus+re);
                                fedW = (bonus1+(sales4*commissionRate))*federalRate;
                                stW = (bonus1+(sales4*commissionRate))*stateRate;
                                retRate = (bonus1+(sales4*commissionRate))*retirementRate;
                                netPay = (sales4*commissionRate)+bonus1-fedW-stW-retRate;
                                printf("Mrs. D:     %.2f%10d%10d%10d%7d%7d\n", sales4*commissionRate,bonus1,fedW, stW, retRate, netPay);
                                comissionTotal += sales4*commissionRate;
                                fRateTotal += fedW;
                                sRateTotal += stW;
                                rtTotal += retRate;
                                bonusTotal += bonus1;
				netPayTotal += netPay;
				fflush(stdout);
				break;
			case 5:
				re = (rand() % (30-1+1)+1);
                                re = re/2.0;
                                re = re/100.0;
                                bonus1 = profit*(bonus+re);
                                fedW = (bonus1+(sales5*commissionRate))*federalRate;
                                stW = (bonus1+(sales5*commissionRate))*stateRate;
                                retRate = (bonus1+(sales5*commissionRate))*retirementRate;
                                netPay = (sales5*commissionRate)+bonus1-fedW-stW-retRate;
                                printf("Mrs. X:     %.2f%10d%10d%10d%7d%7d\n", sales5*commissionRate,bonus1,fedW, stW, retRate, netPay);
                                comissionTotal += sales5*commissionRate;
                                fRateTotal += fedW;
                                sRateTotal += stW;
                                rtTotal += retRate;
                                bonusTotal += bonus1;
				netPayTotal += netPay;
				fflush(stdout);
				break;
			case 6:
				printf("Totals:     %.2f%10d%10d%7d%7d %.2f\n",comissionTotal, bonusTotal, fRateTotal, sRateTotal, rtTotal, netPayTotal); 
				break;
		}
	}
}




int main(){
	double commission, federalRate, stateRate, retirementRate, bonus;
	commission = .10;//Since I couldn't find or obtain file1.c, I just used the values in the assignment
	federalRate = .15;
	stateRate = .05;
	retirementRate = .075;
	bonus = .10;
	print_statement(commission, federalRate, stateRate, retirementRate, bonus);//I also didn't know how to make number of employees work, with creating a random name each
	//time for them, so I just settled on 5 employees like the example
	return (0);
}
