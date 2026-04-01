#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node* copil;
	Node* frate;

	Node(T val)
	{
		value = val;
		copil = NULL;
		frate = NULL;
	}
};
template<typename T>
class Tree
{
private:
	Node<T>* radacina;

public:
	Tree()
	{
		radacina = NULL;
	}
	void add_node(T value, Node<T>* parinte)
	{
		Node<T>* nodNou = new Node<T>(value);
		if (parinte == NULL)
		{
			if (radacina == NULL)
			{
				radacina = nodNou;
			}
		}
		else
		{
			if (parinte->copil == NULL)
			{
				parinte->copil = nodNou;
			}
			else
			{
				Node<T>* temp = parinte->copil;
				while (temp->frate != NULL)
				{
					temp = temp->frate;
				}
				temp->frate = nodNou;
			}
		}
	}
	Node<T>* get_root()
	{
		return radacina;
	}
	Node<T>* find(bool(*comparare)(T))
	{
		return cauta(radacina, comparare);
	}
	Node<T>* cauta(Node<T>* nod, bool (*comparare)(T))
	{
		if (nod == NULL)
		{
			return NULL;
		}
		if (comparare(nod->value))
		{
			return nod;
		}
		Node<T>* rez = cauta(nod->copil, comparare);
		if (rez != NULL)
		{
			return rez;
		}
		return cauta(nod->frate, comparare);
	}
	void delete_node(Node<T>* parinte, Node<T>* nodSters)
	{
		if (nodSters == NULL) 
		{
			return;
		}
		if (nodSters == radacina) 
		{
			sterge(radacina);
			radacina = NULL;
			return;
		}
		if (parinte == NULL) 
		{
			return;
		}
		if (parinte->copil == nodSters) 
		{
			parinte->copil = nodSters->frate;
			sterge(nodSters);
		}
		else 
		{
			Node<T>* temp = parinte->copil;
			while (temp != NULL && temp->frate != nodSters) 
			{
				temp = temp->frate;
			}

			if (temp != NULL) 
			{
				temp->frate = nodSters->frate;
				sterge(nodSters);
			}
		}
	}
	void sterge(Node<T>* nod)
	{
		if (nod == NULL)
		{
			return;
		}
		sterge(nod->copil);
		sterge(nod->frate);
		delete nod;
	}
	void insert(T value, Node<T>* parinte, int pozitie) 
	{
		if (parinte == NULL) 
		{
			return;
		}
		Node<T>* nodNou = new Node<T>(value);
		if (pozitie == 0) 
		{
			nodNou->frate = parinte->copil;
			parinte->copil = nodNou;
		}
		else 
		{
			Node<T>* temp = parinte->copil;
			int contor = 0;
			while (temp != NULL && contor < pozitie - 1) 
			{
				temp = temp->frate;
				contor = contor + 1;
			}
			if (temp != NULL)
			{
				nodNou->frate = temp->frate;
				temp->frate = nodNou;
			}
		}
	}
	void sort(Node<T>* nod, bool (*comparare)(T, T))
	{
		if (nod == NULL)
		{
			sorteaza(radacina, comparare);
		}
		else
		{
			sorteaza(nod, comparare);
		}
	}
	void sorteaza(Node<T>* nod, bool (*comparare)(T, T))
	{
		if (nod == NULL) 
		{
			return;
		}
		if (nod->copil != NULL) 
		{
			sorteazaCopii(nod->copil, comparare);
		}
		Node<T>* copil = nod->copil;
		while (copil != NULL) 
		{
			sorteaza(copil, comparare);
			copil = copil->frate;
		}
	}
	void sorteazaCopii(Node<T>* primul, bool (*comparare)(T, T))
	{
		if (primul == NULL || primul->frate == NULL)
		{
			return;
		}
		bool schimbat = true;
		while (schimbat)
		{
			schimbat = false;
			Node<T>* curent = primul;
			while (curent->frate != NULL)
			{
				bool trebuieSchimbat;
				if (comparare == NULL)
				{
					trebuieSchimbat = curent->value < curent->frate->value;
				}
				else
				{
					trebuieSchimbat = comparare(curent->value, curent->frate->value);
				}
				if (trebuieSchimbat)
				{
					T temp = curent->value;
					curent->value = curent->frate->value;
					curent->frate->value = temp;
					schimbat = true;
				}
				curent = curent->frate;
			}
		}
	}
	int count(Node<T>* nod)
	{
		if (nod == NULL)
		{
			return numara(radacina);
		}
		else
		{
			return numara(nod);
		}
	}
	int numara(Node<T>* nod)
	{
		if (nod == NULL)
		{
			return 0;
		}
		int cnt = 1;
		cnt = cnt + numara(nod->copil);
		cnt = cnt + numara(nod->frate);
		return cnt;
	}
	~Tree()
	{}
};

int main()
{
	Tree<int> arbore;
	cout << "Adaug radacina (10)" << endl;
	arbore.add_node(10, NULL);
	Node<int>* radacina = arbore.get_root();
	cout << "Radacina: " << radacina->value << endl;
	cout << "Adaug copii (20,30,40)" << endl;
	arbore.add_node(20, radacina);
	arbore.add_node(30, radacina);
	arbore.add_node(40, radacina);

	Node<int>* nod20 = radacina->copil;
	cout << "Nod 20: " << nod20->value << endl;
	cout << "Adaug copii (25,26) lui 20" << endl;
	arbore.add_node(25, nod20);
	arbore.add_node(26, nod20);

	cout << "Caut nodul 25 " << endl;
	Node<int>* gasit = arbore.find([](int val)
		{
			return val == 25;
		});
	if (gasit != NULL)
	{
		cout << "Gasit: " << gasit->value << endl;
	}
	else
	{
		cout << " NU sa gasit"<<endl;
	}

	int total = arbore.count(NULL);
	cout << "Nr noduri: " <<total<< endl;
	cout << "Inserez 35 pe poz 2" << endl;
	arbore.insert(35, radacina, 2);
	cout << "Sortez copii" << endl;
	arbore.sort(radacina, NULL);
	cout << "Sterg nod 20" << endl;
	arbore.delete_node(radacina, nod20);
	
	return 0;
}