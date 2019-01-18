#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define NULL 0x00
#include <string>
template <class T>
class ElmtList {
	private:
		T value; // Menyimpan nilai elemen linked list
		ElmtList<T> *next; // Menyimpan alamat elemen linked list berikutnya
  public:
  	ElmtList(T val) {
  		value = val;
  		next = NULL;
  	}
  	T getValue() {
  		return value;
  	}
  	ElmtList<T>* getNext() {
  		return next;
  	}
  	void setNext(ElmtList<T>* element) {
  		next = element;
  	}
};

template <class T>
class List {
	private:
		ElmtList<T> *head; // Pointer to first element list
	public:
		// Konstruktor. Inisialisasi pointer next dengan NULL.
		List() {
			head = NULL;
		}
  		List(const List& L) {
  			head = L;
  		}
		// Destruktor
		~List() {
		}

		/* METHOD SPESIFIKASI */
		// Kembalikan indeks element di linked list. Kembalikan -1 jika tidak ditemukan.
		// Asumsikan elemen pertama berindeks 0.
		int find(T element) {
			ElmtList<T> *P = head;
			int i = 0;

			while(P != NULL && P->getValue() != element){
				P = P->getNext();
				i += 1;
			}

			if (P->getValue() == element){
				return i;
			} else {
				return -1;
			}
		}
		// Kembalikan nilai true apabila linked list kosong, false jika sebaliknya.
		bool isEmpty() {
			return (head == NULL);
		}
		// Menambahkan elemen sebagai elemen paling belakang pada linked list.
		void add(T element) {
			ElmtList<T> *P = head;
			ElmtList<T> *temp = new ElmtList<T>(element);

			if(P == NULL){
				P = temp;
				head = P;
			}
			else{
				while(P->getNext() != NULL){
					P = P->getNext();
				}
				P->setNext(temp);
			}
		}
		// Membuang elemen yang sama dengan masukan parameter
		void remove(T element) {
			  ElmtList<T> *P = head;
			  ElmtList<T> *Pdel;

			  if(P->getValue() == element){
			    head = P->getNext();
			    delete(P);
			  }
			  else{
			    while(P->getNext()->getValue() != element && P->getNext() != NULL){
			      P = P->getNext();
			    }
			    if(P->getNext()->getValue() == element){
			      Pdel = P->getNext();
			      P->setNext(P->getNext()->getNext());
			      delete(Pdel);
			    }
			  }
		}
		// Mengembalikan elemen bertipe T pada indeks ke-i
		T get(int index) {
			  int i = 0;
			  ElmtList<T> *P = head;

			  while(i != index){
			    P = P->getNext();
			    i += 1;
			  }

			  return P->getValue();
		}
		// Mengembalikan panjang list
		int length() {
			  int i = 0;
			  ElmtList<T> *P = head;

			  while(P != NULL){
			    P = P->getNext();
			    i += 1;
			  }

			  return i;
		}
		
		void operator<<(T element) {
			this->add(element);
		}
		//menambah element sebagai elemen paling belakang linked list
};

#endif
