#include <iostream>
using namespace std;
class Polynomial {
	public :
	int *degCoeff;
	int capacity;

	public :
		// Default Constructor
		Polynomial() {
			degCoeff = new int[5];
			capacity = 5;
			for(int i = 0; i < capacity; i++) {
				degCoeff[i] = 0;
			}
		}
		// Copy constructor
		Polynomial(Polynomial const &p) {
			this -> degCoeff = new int[p.capacity]; 
			for(int i = 0; i < p.capacity; i++) {
				this -> degCoeff[i] = p.degCoeff[i];
			}
			this -> capacity = p.capacity;
		}
		// Copy assignment operator
		void operator=(Polynomial const &p) {
			this -> degCoeff = new int[p.capacity]; 
			for(int i = 0; i < p.capacity; i++) {
				this -> degCoeff[i] = p.degCoeff[i];
			}
			this -> capacity = p.capacity;
		}
		// print 
		void print() {
			for(int i = 0; i < capacity; i++) {
				if(degCoeff[i] != 0) {
					cout << degCoeff[i] << "x" << i << " ";
				}
			}
			cout << endl;
		}
		// setCoefficient 
		void setCoefficient(int degree, int coeff) {
			while(degree >= capacity) {
				int *newDegCoeff = new int[2 * capacity];
				for(int i = 0; i < capacity; i++) {
					newDegCoeff[i] = degCoeff[i];
				}
				for(int i = capacity; i < 2 * capacity; i++) {
					newDegCoeff[i] = 0;
				}
				delete[] degCoeff;
				degCoeff = newDegCoeff;
				capacity *= 2;
			}
			degCoeff[degree] = coeff;
		}

		// +
		Polynomial operator+(Polynomial const &p) {
			int newCapacity = max(this -> capacity, p.capacity);
			Polynomial pNew;
			if(newCapacity == this -> capacity) {
				for(int i = 0; i < p.capacity; i++) {
					pNew.setCoefficient(i, (this -> degCoeff[i] + p.degCoeff[i]));
				}
				for(int i = p.capacity; i < newCapacity; i++) {
					pNew.setCoefficient(i, this -> degCoeff[i]);
				}
			}
			if(newCapacity == p.capacity) {
				for(int i = 0; i < this -> capacity; i++) {
					pNew.setCoefficient(i, (this -> degCoeff[i] + p.degCoeff[i]));
				}
				for(int i = this -> capacity; i < newCapacity; i++) {
					pNew.setCoefficient(i, p.degCoeff[i]);
				}
			}
			return pNew;
		}

		// -
		Polynomial operator-(Polynomial const &p) {
			int newCapacity = max(this -> capacity, p.capacity);
			Polynomial pNew;
			if(newCapacity == this -> capacity) {
				for(int i = 0; i < p.capacity; i++) {
					pNew.setCoefficient(i, (this -> degCoeff[i] - p.degCoeff[i]));
				}
				for(int i = p.capacity; i < newCapacity; i++) {
					pNew.setCoefficient(i, this -> degCoeff[i]);
				}
			}
			if(newCapacity == p.capacity) {
				for(int i = 0; i < this -> capacity; i++) {
					pNew.setCoefficient(i, (this -> degCoeff[i] - p.degCoeff[i]));
				}
				for(int i = this -> capacity; i < newCapacity; i++) {
					pNew.setCoefficient(i, -p.degCoeff[i]);
				}
			}
			return pNew;
		}

		// * 
		Polynomial operator*(Polynomial const &p) {
			Polynomial pNew;
			for(int i = 0; i < this -> capacity; i++) {
				Polynomial pNew2;
				for(int j = 0; j < p.capacity; j++) {
					pNew2.setCoefficient(i + j, (this -> degCoeff[i] * p.degCoeff[j]));
				}
				pNew = pNew + pNew2;
			}
			return pNew;
		}
};
