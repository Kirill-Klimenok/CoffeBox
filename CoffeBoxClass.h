#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class CoffeBoxClass
{
private:
	const int PIN = 1111;
	const int ESPRESSO_PRICE = 2;
	const int CAPPUCCINO_PRICE = 3;
	const double LATTE_PRICE = 2.5;
	double moneyClient = 0;
	double moneyCoffeeBox = 0;
	int numberCups = 7;
	bool isPinTrue = true;

	int attempts = 1;//Vlad

	void printMenu();
	double enterData();
	void selectingAnAction(double number);
	void depositMoney();
	void buyCoffee(double priceCoffee);
	void clearConsole();
	void cookingCoffee();
	bool isTrueMoney(double money);
	void printException(int number);
	//vlad
	void managingTheService();
	bool isTruePassword(double number);
	void verificationServise();//I
	void serviseMenu();
	void balance();
	void cupsEmpty();

public:
	void start();
};



