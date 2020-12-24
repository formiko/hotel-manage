#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"

class View {
	public:
		void viewManageSteadyInDiscount();
		void viewSetMemberDiscount();
		void viewSetDiscount();
		void viewReceptIndex();
		void viewReceptLogin();
		void viewLookRoom(string who);
		void viewAdminLookRoom();
		void viewAdminIndex();
		void viewAdminLogin();
		void viewCustomerFindRoom();
		void viewCustomerIndex();
		void viewCustomerRegister();
		void viewCustomerLogin();
		void viewCustomer();
		void viewIndex();

		void run() {
			viewIndex();
		}
};