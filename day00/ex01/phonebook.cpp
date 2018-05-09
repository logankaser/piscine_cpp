/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:31:46 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/10 12:49:33 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class PhonebookEntry
{
private:
	std::string first;
	std::string last;
	std::string nick;
	std::string login;
	std::string address;
	std::string email;
	std::string phone_number;
	std::string birthday;
	std::string favorite_meal;
	std::string	underwear_color;
	std::string darkest_secret;
public:
	void set_first(std::string);
	void set_last(std::string);
	void set_nick(std::string);
	void set_login(std::string);
	void set_address(std::string);
	void set_email(std::string);
	void set_phone_number(std::string);
	void set_birthday(std::string);
	void set_favorite_meal(std::string);
	void set_underwear_color(std::string);
	void set_darkest_secret(std::string);
	void print_all(void);
	void print_search(int);
};

void	PhonebookEntry::set_first(std::string str) { first = str; }
void	PhonebookEntry::set_last(std::string str) { last = str; }
void	PhonebookEntry::set_nick(std::string str) { nick = str; }
void	PhonebookEntry::set_login(std::string str) { login = str; }
void	PhonebookEntry::set_address(std::string str) { address = str; }
void	PhonebookEntry::set_email(std::string str) { email = str; }
void	PhonebookEntry::set_phone_number(std::string str) { phone_number = str; }
void	PhonebookEntry::set_birthday(std::string str) { birthday = str; }
void	PhonebookEntry::set_favorite_meal(std::string str) { favorite_meal = str; }
void	PhonebookEntry::set_underwear_color(std::string str) { underwear_color = str; }
void	PhonebookEntry::set_darkest_secret(std::string str) { darkest_secret = str; }

void	print_col(std::string col)
{
	if (col.length() > 10) {
		std::cout << std::setw(9);
		std::cout << col;
		std::cout << '.';
	}
	else {
		std::cout << std::setw(10);
		std::cout << col;
	}
	std::cout << '|';
}

void	PhonebookEntry::print_search(int i)
{
	std::string index;

	index = std::to_string(i);
	print_col(index);
	print_col(first);
	print_col(last);
	print_col(nick);
	std::cout << std::endl;
}

void	PhonebookEntry::print_all(void)
{
	std::cout << first << std::endl;
	std::cout << last << std::endl;
	std::cout << nick << std::endl;
	std::cout << login << std::endl;
	std::cout << address << std::endl;
	std::cout << email << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << birthday << std::endl;
	std::cout << favorite_meal << std::endl;
	std::cout << underwear_color << std::endl;
	std::cout << darkest_secret << std::endl;
}

int	main(void)
{
	PhonebookEntry	entries[8];
	unsigned 		count = 0;
	unsigned 		i = 0;
	std::string 	command = "";
	while (1)
	{
		std::cout << "Please enter a command (\e[0;32mADD\e[0m|\e[0;34mSEARCH\e[0m|\e[0;31mEXIT\e[0m): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "EXIT")
			exit(0);
		if (command == "ADD" && count < 8)
		{
			++count;
			i = count - 1;
			std::cout << "FIRST NAME: ";
			std::getline(std::cin, command);
			entries[i].set_first(command);
			std::cout << "LAST NAME: ";
			std::getline(std::cin, command);
			entries[i].set_last(command);
			std::cout << "NICK NAME: ";
			std::getline(std::cin, command);
			entries[i].set_nick(command);
			std::cout << "LOGIN: ";
			std::getline(std::cin, command);
			entries[i].set_login(command);
			std::cout << "ADDRESS: ";
			std::getline(std::cin, command);
			entries[i].set_address(command);
			std::cout << "EMAIL: ";
			std::getline(std::cin, command);
			entries[i].set_email(command);
			std::cout << "PHONE NUMBER: ";
			std::getline(std::cin, command);
			entries[i].set_phone_number(command);
			std::cout << "BIRTHDAY: ";
			std::getline(std::cin, command);
			entries[i].set_birthday(command);
			std::cout << "FAVORITE MEAL: ";
			std::getline(std::cin, command);
			entries[i].set_favorite_meal(command);
			std::cout << "UNDERWEAR COLOR: ";
			std::getline(std::cin, command);
			entries[i].set_underwear_color(command);
			std::cout << "DARKEST SECRET: ";
			std::getline(std::cin, command);
			entries[i].set_darkest_secret(command);
		}
		else if (command == "ADD")
			std::cout << "ERROR: Phonebook full." << std::endl;
		else if (command == "SEARCH" && count)
		{
			i = 0;
			while (i < count) {
				entries[i].print_search(i + 1);
				++i;
			}
			std::cout << "SELECT INDEX: ";
			std::getline(std::cin, command);
			i = std::stoi(command);
			if (i > 0 && i <= count)
				entries[i - 1].print_all();
			else
				std::cout << "ERROR: Invalid index." << std::endl;
		}
	}
}
