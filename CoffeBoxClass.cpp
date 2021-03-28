#include "CoffeBoxClass.h"

void CoffeBoxClass::start()
{
	while (isPinTrue) {

		printMenu();

		selectingAnAction(enterData());
	}

	printException(1);
}

void CoffeBoxClass::clearConsole() {
	system("CLS");
}

void CoffeBoxClass::printMenu()
{
	string menu[] = { "1. Deposit money","2. Espresso - ", "3. Cappuccino - ", "4. Latte - ", "5. Service" };
	double price[] = { ESPRESSO_PRICE, CAPPUCCINO_PRICE, LATTE_PRICE };

	if (numberCups < 10 && numberCups > 0) cout << "there are " << numberCups << " cups left" << endl << endl;
	if (numberCups == 0) printException(4);

	cout << "Your balance: " << moneyClient << endl << endl;

	for (int i = 0; i < size(menu); i++) {
		cout << menu[i];
		if (i >= 1 && i < 4) cout <<price[i - 1];
		cout << endl << endl;
	}
}

double CoffeBoxClass::enterData()
{
	double number = 0;
	cout << "_: ";
	cin >> number;
	cout << endl;

	cin.clear();
	fflush(stdin);

	return number;
}

void CoffeBoxClass::selectingAnAction(double number)
{
	switch ((int)number)
	{
	case 1: {
		depositMoney();

		clearConsole();

		break;
	}
	case 2: {
		buyCoffee(ESPRESSO_PRICE);

		clearConsole();

		break;
	}
	case 3: {
		buyCoffee(CAPPUCCINO_PRICE);

		clearConsole();

		break;
	}
	case 4: {

		buyCoffee(LATTE_PRICE);

		clearConsole();

		break;
	}
	case 5: {
		managingTheService();

		clearConsole();

		break;
	}
	default:
		break;
	}
}

void CoffeBoxClass::depositMoney()
{
	double money = 0;

	cout << "How much money do you want to put on the balance: ";
	cin >> money;

	if (!isTrueMoney(money)) {
		printException(2);

		Sleep(2000);
	}
	else {
		moneyClient += money;
		moneyCoffeeBox += money;
	}
}

bool CoffeBoxClass::isTrueMoney(double money)
{
	if (money < 0) return false;
	else if (money == 0.5 || money == 1 || money == 2 || money == 5 || money == 10 || money == 20 || money == 50 || money == 100 || money == 200 || money == 500) return true;
	else return false;

}

void CoffeBoxClass::cookingCoffee()
{
	if (numberCups > 0) {
		cout << "Cooking" << endl << "|";
		for (int i = 0; i < 10; i++) {
			cout << '*';

			Sleep(500);
		}
		cout << "|" << endl << "Complite" << endl;
	}
	else;
	Sleep(3000);
}

void CoffeBoxClass::buyCoffee(double priceCoffee)
{
	if (moneyClient < priceCoffee) {
		bool isYouWantUpYourBalance = false;

		printException(3);

		cin >> isYouWantUpYourBalance;

		if (isYouWantUpYourBalance) {
			cin.clear();
			fflush(stdin);

			depositMoney();
			buyCoffee(priceCoffee);
		}
		else {
			cin.clear();
			fflush(stdin);
		}
	}
	else {
		moneyClient -= priceCoffee;
		if (numberCups > 0) numberCups--;

		cookingCoffee();

		clearConsole();
	}
}

void CoffeBoxClass::printException(int number) {
	switch (number)
	{
	case 1:
	{
		cout << "The device is blocked. Please call in  (+375-(29)-***--)" << endl;
	}
	case 2:
	{
		cout << "Error!" << endl << "You have invested a coin of less than 50 kopecks or this bill does not exist" << endl;
	}
	case 3:
	{
		cout << "You don't have enough money to buy coffee" << ',' << endl << " maybe you want to top up your balance? " << endl << "enter 1 or 0: ";
	}
	case 4:
	{
		cout << "Warning !" << endl << "No cups!" << endl << endl;
	}
	default:
		break;
	}
}

//Vlad

void CoffeBoxClass::managingTheService()
{
	cout << "1. Enter the code." << endl;
	cout << "0. Exit the menu." << endl;

	switch ((int)enterData()) {
	case 1:
		verificationServise();
		break;

	case 0:
		break;

	default:
		managingTheService();
		break;
	}
}

bool CoffeBoxClass::isTruePassword(double number)
{
	if ((int)number == PIN)
	{
		return true;
	}
	else return false;
}

void CoffeBoxClass::verificationServise()
{
	cout << "Please, enter PIN: " << endl;

	if (isTruePassword(enterData()))
	{
		attempts = 1;

		serviseMenu();
	}
	else
	{
		attempts++;

		cout << "The password is incorrect." << endl << endl;

		if (attempts > 3) {
			printMenu();
			cout << "The device is blocked. Please call in  (+375-(29)-***--)" << endl;
			isPinTrue = false;
		}
		else
		{
			managingTheService();
		}
	}
}

void CoffeBoxClass::serviseMenu()
{
	cout << "1. View the balance." << endl;
	cout << "2. View the number of remaining empty cups." << endl;
	cout << "3. Withdrawal of revenue." << endl;
	cout << "0. Exit the menu." << endl;

	moneyCoffeeBox += moneyClient;
	moneyClient == 0;

	switch ((int)enterData()) {
	case 1:
		balance();
		break;

	case 2:
		cupsEmpty();
		break;

	case 3:
		serviseMenu();
		break;

	case 0:
		break;

	default:
		serviseMenu();
		break;
	}
}

void CoffeBoxClass::balance()
{
	cout << "Balance: " << moneyCoffeeBox << endl;
	cout << "0. Back." << endl;

	switch ((int)enterData())
	{
	case 0: {  // Back
		serviseMenu();
		break;
	}
	default:
		cupsEmpty();
		break;
	}
}

void CoffeBoxClass::cupsEmpty()
{
	cout << "Empty cups: " << numberCups << endl;
	cout << "1. Top up." << endl;
	cout << "0. Back." << endl;

	switch ((int)enterData())
	{
	case 0:
	{
		serviseMenu();
		break;
	}
	case 1:
	{
		if (numberCups == 700) // Cheak MAX
		{
			cout << "No top-up required." << endl << endl;
		}
		else
		{
			cout << "Quantity:" << endl;

			numberCups += enterData();

			if (numberCups > 700) // Cheak MAX
			{
				cout << "The quantity is overflowing. Maximum of 700." << endl << endl;

				numberCups = 700;
			}
		}
	}
	default:
		cupsEmpty();
		break;
	}
}