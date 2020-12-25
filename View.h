#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"

class View {
	public:
		void viewCheckOut();
		void viewInRoom();
		void viewShowAllRoom(string who);
		void viewSetRoomTypePrice();
		void viewShowContinueInDiscount();
		void viewManageContinueInDiscount();
		void viewSetMemberDiscount();
		void viewSetDiscount();
		void viewReceptIndex();
		void viewReceptLogin();
		void viewLookRoom(string who);
		void viewAdminLookRoom();
		void viewAdminIndex();
		void viewAdminLogin();
		void viewCustomerCancelBook();
		void viewCustomerFindAllEmptyRoom();
		void viewCustomerFindRoom();
		void viewCustomerBookRoom();
		void viewCustomerIndex();
		void viewCustomerRegister();
		void viewCustomerLogin();
		void viewCustomer();
		void viewIndex();

		void run() {
			viewIndex();
		}
};