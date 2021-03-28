#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class CoffeBoxClass
{
private:
	const int PIN = 1111;
	const int ESPRESSO_PRICE = 2.0;
	const int CAPPUCCINO_PRICE = 3.0;
	const double LATTE_PRICE = 2.5;
	double moneyClient = 0.0;
	double moneyCoffeeBox = 0.0;
	int numberCups = 7;
	bool isPinTrue = true;

	int attempts = 1;//Vlad

	void printMenu();
	double enterData();
	void selectingAnAction(double number);
	void depositMoney();
	void buyCoffee(double priceCoffee, string typeCoffee);
	void clearConsole();
	void cookingCoffee();
	bool isTrueMoney(double money);
	//vlad
	void managingTheService();
	bool isTruePassword(double number);
	void verificationServise();
	void serviseMenu();
	void printServiseMenu();
	void balance();
	void printBalance();
	void cupsEmpty();
	void printCupsEmpty();
	void cupsEmptyTopUp();
	void TopUp(int cups);
	void printLockdown();

public:
	void start();
};



