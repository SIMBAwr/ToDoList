#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>



void AddNote(const std::string&);

void DeleteNote(int index);

void ShowAllNotes();

void DeleteAllNotes();

void FindNote(std::string&);



void ShowMenu();



#endif // !FUNCTIONS_H

