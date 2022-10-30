#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

class Worker {
public:
	static int idCounter;
	int id;
	string name;
	string surname;
	int age;
	int pageCount;

	Worker() {
		id = idCounter++;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string name, string surname, int age, int pageCount) {
		id = idCounter++;
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->pageCount = pageCount;
	}

	void Show() {
		cout << "====================" << endl;
		cout << "ID: " << id << "\nName: " << name << "\nSurname: " << surname << "\nAge: " << age << "\nPageCount: " << pageCount << "\n";
		cout << "====================" << endl;
	}

};

int Worker::idCounter = 1;

class WorkerQueue {
public:
	vector<Worker> workers;

	bool IsEmpty() const { return workers.empty(); }

	void Enqueue(const Worker& worker) {
		workers.push_back(worker);
	}

	void Dequeue() {
		if (!workers.empty())
			workers.erase(workers.begin());
	}

	Worker& Front() { return workers.front(); }
};

class Printer {
public:
	WorkerQueue queue;

	void AddWorker(const Worker& worker) {
		queue.Enqueue(worker);
	}

	void Start() {
		while (!queue.IsEmpty())
		{
			Worker worker = queue.Front();
			while (0 < worker.pageCount) {
				system("cls");
				worker.Show();
				Sleep(1000);
				worker.pageCount--;
			}

			queue.Dequeue();
		}
	}
};

void main() {
	Printer pr;
	pr.AddWorker(Worker("Ferid", "Selimov", 15, 10));
	pr.AddWorker(Worker("Rinat", "Qedimov", 15, 8));
	pr.AddWorker(Worker("Yusif", "Seyidov", 15, 3));

	pr.Start();
}