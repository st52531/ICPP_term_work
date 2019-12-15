#include <db.h>
#include <helpful.h>
#include <iostream>
#include "simpleDbException.h"

using namespace std;

int main() {
	try {
		// Create db
		Db* db = Db::open("testdb");

		// Create table Customer
		auto customerId = Db::Field("id", FieldType::Integer);
		auto customerFirstName = Db::Field("first_name", FieldType::String);
		auto customerLastName = Db::Field("last_name", FieldType::String);
		auto customerEmail = Db::Field("email", FieldType::String);
		auto customerPasswd = Db::Field("password", FieldType::String);
		auto customerFields = combineToDefinition(customerId, customerFirstName, customerLastName, customerEmail, customerPasswd);
		Table* customers = db->openOrCreateTable("customer", 5, customerFields);
		// Create table Product
		auto productId = Db::Field("id", FieldType::Integer);
		auto productName = Db::Field("name", FieldType::String);
		auto productPrice = Db::Field("price", FieldType::Double);
		auto productFields = combineToDefinition(productId, productName, productPrice);
		Table* products = db->openOrCreateTable("product", 3, productFields);
		// Create table Purchase
		auto purchaseId = Db::Field("id", FieldType::Integer);
		auto customerIdFK = Db::Field("customer_id", FieldType::Integer);
		auto productIdFK = Db::Field("product_id", FieldType::Integer);
		auto purchaseFields = combineToDefinition(purchaseId, customerIdFK, productIdFK);
		Table* purchases = db->openOrCreateTable("purchase", 3, customerFields);

		// Insert rows into Customer	
		customers->insert(combineToRow(Db::Int(0), Db::String("Karel"), Db::String("Novak"), Db::String("novak@email.cz"), Db::String("novak123")));
		customers->insert(combineToRow(Db::Int(1), Db::String("Jan"), Db::String("Stary"), Db::String("stary@email.cz"), Db::String("stary123")));
		customers->insert(combineToRow(Db::Int(2), Db::String("Josef"), Db::String("Vyskocil"), Db::String("vyskocil@email.cz"), Db::String("vyskocil123")));
		customers->insert(combineToRow(Db::Int(3), Db::String("Frantisek"), Db::String("Jedly"), Db::String("jedly@email.cz"), Db::String("jedly123")));
		customers->insert(combineToRow(Db::Int(4), Db::String("Stepan"), Db::String("Dlouhy"), Db::String("dlouhy@email.cz"), Db::String("dlouhy123")));
		customers->insert(combineToRow(Db::Int(5), Db::String("David"), Db::String("Vysoky"), Db::String("vysoky@email.cz"), Db::String("vysoky123")));

		// Insert rows into Product
		products->insert(combineToRow(Db::Int(100), Db::String("Intel Core i5-9400"), Db::Double(5424)));
		products->insert(combineToRow(Db::Int(101), Db::String("AMD Athlon 3000G"), Db::Double(1399)));
		products->insert(combineToRow(Db::Int(102), Db::String("AMD A6-9500"), Db::Double(960)));
		products->insert(combineToRow(Db::Int(103), Db::String("Intel Core i5-9400F"), Db::Double(3999)));
		products->insert(combineToRow(Db::Int(104), Db::String("AMD Ryzen 7 3700X"), Db::Double(8980)));
		products->insert(combineToRow(Db::Int(105), Db::String("Intel Core i7-9700K"), Db::Double(10410)));

		// Insert rows into Purchase
		purchases->insert(combineToRow(Db::Int(321), Db::Int(0), (Db::Int(105))));
		purchases->insert(combineToRow(Db::Int(322), Db::Int(1), (Db::Int(100))));
		purchases->insert(combineToRow(Db::Int(323), Db::Int(2), (Db::Int(102))));
		purchases->insert(combineToRow(Db::Int(324), Db::Int(3), (Db::Int(101))));
		purchases->insert(combineToRow(Db::Int(325), Db::Int(4), (Db::Int(104))));
		purchases->insert(combineToRow(Db::Int(326), Db::Int(5), (Db::Int(103))));
		purchases->insert(combineToRow(Db::Int(327), Db::Int(0), (Db::Int(101))));

		// Select
		auto it = customers->select();
		while (it->moveNext())
		{
			auto row = it->getRow();

			cout << row[0]->getInt() << ": " << row[1]->getString() << endl;
		}
		it->close();

		// Save tables to files
		customers->commit();
		products->commit();
		purchases->commit();

		// Uzavření tabulky
		customers->close();

		// Uzavření db
		db->close();

		cin.get();
		return 0;
	}
	catch (WrongInputException & ex) {
		cout << ex.getMessage() << endl;
	}
	catch (InvalidOperationException & ex) {
		cout << ex.getMessage() << endl;
	}
	catch (LoadFileException & ex) {
		cout << ex.getMessage() << endl;
	}
}