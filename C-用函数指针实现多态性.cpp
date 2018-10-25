void print1(){
	cout << "123" << endl;
}

void print2() {
	cout << "234" << endl;
}

typedef void (* fun_pointer) ();

void polymorphsim_print(dun_pointer fun) {
	fun();
}

int main(){
	polymorphsim_print(print1);
	polymorphsim_print(print2)
	fun_pointer pointer;
	pointer = print2;
	pointer();
}
