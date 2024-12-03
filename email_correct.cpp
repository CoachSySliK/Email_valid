#include <iostream>
#include <string>

using namespace std;

bool email_dog(string email)
{
	int counter = 0;
	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == '@')
			++counter;
	}
	if (counter != 1)
	{
		cout << "Ошибка!!!\nВ адресе должен быть один символ \'@\'\n";
		return false;
	}
	return true;
}

int email_dog_number(string email, char symbol)
{
	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == symbol)
			return i;
	}
}

string email_name(string email, int dog)
{
	string emailName;
	for (int i = 0; i < dog; i++)
		emailName += email[i];
	return emailName;
}

string email_host(string email, int dog)
{
	string emailHost;
	for (int i = ++dog; i < email.length(); i++)
		emailHost += email[i];
	return emailHost;
}

bool valid_values_name(string email)
{
	string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890-.!#$&'*+-/=?^_`{|}~";
	for (int i = 0; i < email.length(); i++)
	{
		if (valid.find(email[i]) == valid.npos)
		{
			cout << "Ошибка!!!\nНедопустимые символы в имени\n";
			return false;
		}
	}
	return true;
}

bool valid_values_host(string email)
{
	string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890-.";
	for (int i = 0; i < email.length(); i++)
	{
		if (valid.find(email[i]) == valid.npos)
		{
			cout << "Ошибка!!!\nНедопустимые символы в адресе\n";
			return false;
		}
	}
	return true;
}

bool point(string email)
{
	if (email[0] == '.' || email[email.length() - 1] == '.')
	{
		cout << "Ошибка!!!\nИмя и Адрес не могут начинаться или заканчиваться точкой\n";
		return false;
	}
	for (int i = 1; i < email.length(); i++)
	{
		if (email[i] == '.' && email[i] == email[i - 1])
		{
			cout << "Ошибка!!!\nДве точки подряд\n";
			return false;
		}
	}
	return true;
}

int main(void)
{
	string email;
	bool emailRight;
	do
	{
		do
		{
			emailRight = true;
			cout << "Введите Ваш email: ";
			cin >> email;

			emailRight = email_dog(email);
			if (!emailRight)
				continue;

			//int dog = email_dog_number(email, '@');
			int dog = email.find('@');

			//string emailHost(email, dog);
			//email.erase(dog, email.length() - dog);

			string emailName = email_name(email, dog);
			if (emailName.length() < 1 || emailName.length() > 64)
			{
				emailRight = false;
				cout << "Ошибка!!!\nИмя не может быть пустым или слишком длинным\n";
			}
			if (!emailRight)
				continue;

			string emailHost = email_host(email, dog);
			if (emailHost.length() < 1 || emailHost.length() > 63)
			{
				emailRight = false;
				cout << "Ошибка!!!\nАдрес не может быть пустым или слишком длинным\n";
			}
			if (!emailRight)
				continue;

			emailRight = valid_values_name(emailName);
			if (!emailRight)
				continue;

			emailRight = valid_values_host(emailHost);
			if (!emailRight)
				continue;

			emailRight = point(emailName);
			if (!emailRight)
				continue;

			emailRight = point(emailHost);
			if (!emailRight)
				continue;

		} while (!emailRight);

		cout << "Email is correct\n";
		
	} while (true);

	return 0;
}