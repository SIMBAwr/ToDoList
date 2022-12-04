#include "Functions.h"




void ShowMenu()
{
	std::cout << "[1] Добавить заметку \n";
	std::cout << "[2] Удалить заметку \n";
	std::cout << "[3] Вывести все заметки \n";
	std::cout << "[4] Удалить все заметки \n";
	std::cout << "[5] Найти заметку\n";
}




void AddNote(const std::string& str_)
{
	std::ofstream osFile;

	osFile.open("C:\\Users\\Даниил\\Desktop\\ToDoList.txt", std::ios::app);

	if (!osFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	osFile << str_ << "\n";

	osFile.close();
}





void DeleteNote(int index)
{
	std::ifstream isFile("C:\\Users\\Даниил\\Desktop\\ToDoList.txt");


	if (!isFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	std::vector<std::string> vectorFile;

	std::string strFile;

	while (getline(isFile, strFile))
	{
		vectorFile.push_back(strFile);
	}

	if (vectorFile.size() < index)
	{
		std::cout << "Нет такой заметки!";
		exit(1);
	}

	isFile.close();

	std::vector<std::string>::const_iterator iter = vectorFile.begin() + (index - 1);

	vectorFile.erase(iter);


	std::ofstream osFile;

	osFile.open("C:\\Users\\Даниил\\Desktop\\ToDoList.txt");

	if (!osFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	for (size_t i = 0; i < vectorFile.size(); i++)
	{
		osFile << vectorFile[i] << "\n";
	}

	osFile.close();
}




void ShowAllNotes()
{
	std::ifstream isFile;

	isFile.open("C:\\Users\\Даниил\\Desktop\\ToDoList.txt");

	if (!isFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	
	std::string strFile;

	int numberNote = 1;

	while (getline(isFile, strFile))
	{
		std::cout << "[" << numberNote++ << "] " << strFile << std::endl;
	}

	isFile.close();
}





void DeleteAllNotes()
{
	std::ifstream isFile("C:\\Users\\Даниил\\Desktop\\ToDoList.txt");
	

	if (!isFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	std::vector<std::string> vectorFile;

	std::string strFile;

	while (getline(isFile, strFile))
	{
		vectorFile.push_back(strFile);
	}

	vectorFile.clear();
	vectorFile.push_back("");

	isFile.close();

	std::ofstream osFile;

	osFile.open("C:\\Users\\Даниил\\Desktop\\ToDoList.txt");

	if (!osFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	for (size_t i = 0; i < vectorFile.size(); i++)
	{
		osFile << vectorFile[i];
	}

	osFile.close();
}




void FindNote(std::string& str)
{
	std::ifstream isFile("C:\\Users\\Даниил\\Desktop\\ToDoList.txt");


	if (!isFile.is_open())
	{
		std::cout << "Файл не открылся\n";
		exit(1);
	}

	std::vector<std::string> vectorFile;

	std::string strFile;

	while (getline(isFile, strFile))
	{
		vectorFile.push_back(strFile);
	}

	isFile.close();


	int counter = 0;

	for (size_t i = 0; i < vectorFile.size(); i++)
	{
		for (size_t j = 0; j < vectorFile[i].size(); j++)
		{
			for (size_t t = 0; t < str.size(); t++)
			{
				if (vectorFile[i][j] == str[t])
				{
					for (size_t c = j, r = 0; c < vectorFile[i].size(); c++, r++)
					{
							if (vectorFile[i][c] == str[r])
								counter++;
							else
								break;

							if (counter == str.size())
								std::cout << vectorFile[i] << "\n";
					}
				}
			}
			counter = 0;
		}
	}
}
