#include "Functions.h"

enum choice
{
	ADD_NOTE = 1, DELETE_NOTE, SHOW_ALL_NOTES, DELETE_ALL_NOTES, FIND_NOTES
};


int main()
{


	std::system("chcp 1251");

	int choiceAction;

	while (true)
	{
		system("cls");

		ShowMenu();

		std::cout << "Выберите действие: ";
		std::cin >> choiceAction;

		if (choiceAction == ADD_NOTE)
		{
			std::string strAdd;

			std::cout << "Введите новую заметку: ";
			std::cin.ignore();

			getline(std::cin, strAdd);

			AddNote(strAdd);
			std::cout << std::endl;
			std::cout << "Заметка \"" << strAdd << "\" добавлена\n";
			system("pause");
		}


		if (choiceAction == DELETE_NOTE)
		{
			int index;

			std::cout << std::endl;
			ShowAllNotes();
			std::cout << std::endl;

			std::cout << "Удалить заметку под номером: ";
			std::cin >> index;

			DeleteNote(index);

			std::cout << "Заметка №" << index << " удалена\n";
			system("pause");
		}

		
		if (choiceAction == SHOW_ALL_NOTES)
		{
			std::cout << std::endl;
			ShowAllNotes();
			std::cout << std::endl;
			system("pause");
		}


		if (choiceAction == DELETE_ALL_NOTES)
		{
			DeleteAllNotes();
			std::cout << "\nВсе заметки удалены\n";
			system("pause");
		}


		if (choiceAction == FIND_NOTES)
		{
			std::string str;
			std::cout << "Ключево слово для поиска: ";
			std::cin >> str;

			std::cout << std::endl;
			FindNote(str);
			std::cout << std::endl;
			system("pause");
		}

	}
}

























