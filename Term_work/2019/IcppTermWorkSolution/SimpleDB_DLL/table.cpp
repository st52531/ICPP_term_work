#include<fstream>
#include "table.h"
#include"simpleDbException.h"
#include <iostream>
#include "iterator.h"
#include <iomanip>

using namespace std;

Table::Table(string name, string database, int fieldCount, FieldObject** fields, int rowCount)
{
	numOfEntries = 0;
	this->name = name;
	this->database = database;
	this->rowCount = rowCount;
	this->fieldCount = fieldCount;
	this->fields = fields;

	data = new Object * *[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		data[i] = new Object * [fieldCount];
	}
}

Table::~Table()
{
	// Deallocate array of FieldObject*
	for (int i = 0; i < fieldCount; i++)
	{
		delete fields[i];
	}
	delete[] fields;

	// Deallocate 2D array of Object* 
	for (int i = 0; i < rowCount; i++)
	{
		if (i < numOfEntries)
			for (int j = 0; j < fieldCount; j++)
			{
				delete data[i][j];
			}
		delete[] data[i];
	}
	delete[] data;
}

void Table::insert(Object** row)
{
	if (row == nullptr)
		throw WrongInputException{ "Given row is empty." };

	if (numOfEntries >= rowCount)
		enlargeDataArray();

	data[numOfEntries] = row;
	numOfEntries++;
}

void Table::remove(int rowid)
{
	if(rowid>=numOfEntries)
		throw WrongInputException{ "Given id is bigger than the number of entries stored in the table." };

	for (int i = rowid; i < numOfEntries - 1; i++)
	{
		data[i] = data[i + 1];
	}
	data[--numOfEntries] = nullptr;
	cout << "Row with id: " << rowid << " in the table '" << name <<"' was removed." << endl << endl;
}

IIterator* Table::select()
{
	return new Iterator(rowCount, fieldCount, numOfEntries, data);
}

void Table::commit()
{
	FieldType type;
	ofstream out("../SimpleDB_DLL/SimpleDB files/" + database + "_" + name + "_data" + ".dat");

	if (out.is_open()) {
		out << numOfEntries << endl;
		for (int i = 0; i < numOfEntries; i++)
		{
			//out.write((char*)&data[i], sizeof(data[i]));
			for (int j = 0; j < fieldCount; j++)
			{
				type = data[i][j]->getDataType();
				switch (type) {
				case FieldType::Integer:
					out << left << setw(5) << data[i][j]->getInt();
					break;
				case FieldType::Double:
					out << left << setw(10) << data[i][j]->getDouble();
					break;
				case FieldType::String:
					out << left << setw(25) << data[i][j]->getString();
					break;
				}
			}
			out << endl;
		}
		out.close();
	}
	else
		throw  LoadFileException("Something went wrong, data of table: " + name + " couldn't be saved.");

}

void Table::close()
{
	Table::~Table();
	name = database = "";
	rowCount = fieldCount = numOfEntries = 0;
}

int Table::getRowCount() const
{
	return numOfEntries;
}

FieldObject** Table::getFields() const
{
	return fields;
}

int Table::getFieldCount() const
{
	return fieldCount;
}

std::string Table::getTableName() const
{
	return name;
}

void Table::enlargeDataArray(int amount)
{
	int oldRowCount = rowCount;
	int entryCount = 0;
	rowCount += amount;
	// Allocate a new array
	Object*** newArr = new Object * *[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		if (entryCount < oldRowCount) {
			newArr[i] = data[i];
			entryCount++;
		}else
			newArr[i] = new Object * [fieldCount];

	}
	delete[] data;

	data = newArr;
}

IIterator* Table::select(ICondition* condition)
{
	int entryCount = 0;
	Object*** selectedData = new Object * *[numOfEntries];
	for (int i = 0; i < numOfEntries; i++)
	{
		//selectedData[i] = new Object * [fieldCount];
		if (condition->matches(fieldCount, fields, data[i]))
		{
			selectedData[entryCount] = data[i];
			entryCount++;
		}
	}
	cout << "Iterator with condition for table '" << name << "' was created." << endl;
	return new Iterator(numOfEntries, fieldCount, entryCount, selectedData, true);
}

int Table::findRowId(ICondition* condition)
{
	for (int i = 0; i < numOfEntries; i++)
	{
		if (condition->matches(fieldCount, fields, data[i]))
			return data[i][0]->getInt();
	}
	return 0;
}

void Table::update(ICondition* condition, std::function<void(Object**)> callback)
{
	for (int i = 0; i < numOfEntries; i++)
	{
		if (condition->matches(fieldCount, fields, data[i]))
			callback(data[i]);
	}

	cout << "Rows satisfying the given condition were updated." << endl << endl;
}

Object** Table::findRowById(int id)
{
	for (int i = 0; i < numOfEntries; i++)
	{
		if (data[i][0]->getInt() == id)
			return data[i];
	}
	throw WrongInputException("Row with the given id does not exist!");
}

void Table::eraseData()
{
	for (int i = 0; i < numOfEntries; i++)
	{
		data[i] = nullptr;
	}
	numOfEntries = 0;
}
