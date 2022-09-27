#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	
	float CarMoney;
	float FirstPay;
	float AnnualPayRate;
	float MonthlyPayRate;
	float BorrowMoney;
	float MonthlyPay;
	int TotalNumber;

	printf("Enter the car's purchase price: ");
	scanf("%f", &CarMoney);
	printf("Enter the down payment(<=500): ");
	scanf("%f", &FirstPay);
	printf("Enter the annual interest rate: ");
	scanf("%f", &AnnualPayRate);
	printf("Enter the number of payments: ");
	scanf("%d", &TotalNumber);
	BorrowMoney = CarMoney - FirstPay;
	MonthlyPayRate = AnnualPayRate / 12;
	MonthlyPay = MonthlyPayRate * BorrowMoney / (1 - pow(1 + MonthlyPayRate, -1 * (TotalNumber)));
	printf("\nThe amount borrowed is: %.2f", BorrowMoney);
	printf("\nThe monthly pay-ment is %.2f", MonthlyPay);
	
	return 0;
}