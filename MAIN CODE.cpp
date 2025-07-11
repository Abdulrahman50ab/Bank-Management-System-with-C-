#include<iostream>     
#include<fstream>      
#include<windows.h>    
#include <conio.h>     
#include <time.h>      
#include <string>     
#include <ctime>    
#include <cmath>          
#include <regex>       
#include "mmsystem.h"        
using namespace std;

char load=219;         

//=========================================================================================================================================================================================	
//																 ====================
//																	CLASS ---- NODE
//																 ====================
//=========================================================================================================================================================================================	

class Node { 
	public:
	   string NAME,ID,PIN_N,MOBILE,CNIC_c,DATE,EMAIL;
	   int AMOUNT;
	   Node *prev;   
	   Node *next;   
	   

	   Node(string I,string P,string N,string M,string C,int A,string D,string eml){
	   
	   		NAME  = N;
			ID = I;
			PIN_N  = P;
			MOBILE  = M;
			CNIC_c  = C;
			EMAIL = eml;
			AMOUNT  = A;
			DATE  = D;
			next = NULL;  
			prev = NULL;  
	   } 
};

//=========================================================================================================================================================================================	
//															 =====================================
//																CLASS ---- DOUBLE_POINTER_LINKED
//															 =====================================
//=========================================================================================================================================================================================	
// Definition of the Double_Pointer_Linked class
class Double_Pointer_Linked{
	private: 
		Node *head,*tail;
	public:
		Double_Pointer_Linked(){
			head=NULL; 
			tail=NULL; 
		}
	
	//------------------------------------------------------------------->> INSERT - DLL <<------------------------------------------------------------------------------------------------
	// Function to insert a new node into the doubly linked list
	void insert(string I,string P,string N,string M,string C,int A,string D,string eml) { 
	 
			Node* newnode = new Node(I,P,N,M,C,A,D,eml);  
			
	
			if(head ==  NULL) 
			{
			
				head = newnode;  
				tail = newnode;  
				return;          
			}
			else
			{  
				tail->next = newnode ;    
				newnode->prev=tail;       
				tail=newnode;           
				return;                   
			}
		}
		
		
	// Function to read user data from a file and insert it into the linked list --------------------------------------------------------------------------------
	void traverse(){
		p:	
			ifstream w("User.txt");   
			if(!w)
			{
				w.close();  
				goto p;    
			}
	        string VL1,VL2,VL3,VL4,VL5,VL7,VL18;
	        int VL6;
	        int n=0;                  
	        ifstream no("count.txt"); 
	        no >> n;                 
	        no.close();               
			for(int i=0; i<n ;i = i+8)
			{
				w>>VL1;				w.ignore(); 
				w>>VL2;				w.ignore();
				getline(w,VL3,',');	w.ignore();
				w>>VL4;				w.ignore();
				w>>VL5;				w.ignore();
				w>>VL6;				w.ignore();
				w>>VL7;				w.ignore();
				w>>VL18;			w.ignore();
				// Insert the read values into the linked list
				insert(VL1,VL2,VL3,VL4,VL5,VL6,VL7,VL18);
			}
			w.close(); // Close the file after reading all the data
	}
	
	//----------------------------------------------------------------------->> CREATE NEW ACCOUNT - DLL <<-------------------------------------------------------------------------------------------------------------------------
	// Function to create a new account in the linked list
		void Create_New_Account(string I,string P,string N,string M,string C,int A,string D,string eml){
	        traverse();
			insert(I,P,N,M,C,A,D,eml);
			Node* ptr; 
			Update(ptr); 
		}
	
	
	//------------------------------------------------------------------------->> UPDATE - DLL <<----------------------------------------------------------------------------------
	// Function to update the user accounts in the file
		void Update(Node* obj){
			Node* ptr;  
			ptr = head;         
			p:               
			ofstream w("User.txt");                 
			if(!w)
			{
				w.close();
				goto p;
			}
			 // Loop through the linked list and write each node's data to the file
			while(ptr != NULL) 
			{ 
				w<< ptr->ID 					<<endl;  
				w<< ptr->PIN_N 					<<endl;  
				w<< ptr->NAME			   <<","<<endl; 
				w<< ptr->MOBILE 				<<endl;   
				w<< ptr->CNIC_c 				<<endl;  
				w<< ptr->AMOUNT 				<<endl;    
				w<< ptr->DATE 					<<endl;   
				w<< ptr->EMAIL					<<endl;  
				ptr = ptr->next;     
			}
			w.close(); 
		}
				
		string removeIntegers(const string& input) {
				    string result;
				    for (char c : input) {
				        if (!isdigit(c)) {
				            result += c;
				        }
				    }
				    return result;
				}
				
				bool isValidGmail(const string& email1) {
				    const regex pattern(R"(^[a-zA-Z0-9._%+-]+@gmail\.com$)");
				    return regex_match(email1, pattern);
				}
				
				bool isValidPakistaniMobileNumber(const string& Phone) {
				    const regex pattern(R"(^(?:\+923|03)?[0-4]\d{8}$)");
				    return regex_match(Phone, pattern);
				}
			
	//---------------------------------------------------------------------------------------->> DISPLAY ALL - DLL <<-------------------------------------------------------------------------------
	   // Function to display all user account information from the linked list
		void display_ALL() { 
			traverse();	 
			Node* ptr;   
			ptr = head;  
			while(ptr != NULL) 
			{ 
			// Print decorative elements for formatting
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<"    NAME   : "<< ptr->NAME <<endl;                           
				cout<<"\t\t\t\t\t"<<"    ID     : "<< "7861 1111 1111 " << ptr->ID <<endl;       
				cout<<"\t\t\t\t\t"<<"    PIN    : "<< ptr->PIN_N <<endl;                       
				cout<<"\t\t\t\t\t"<<"    MOBILE : "<< ptr->MOBILE  <<endl;   
				cout<<"\t\t\t\t\t"<<"    CNIC   : "<< ptr->CNIC_c <<endl;        
				cout<<"\t\t\t\t\t"<<"    EMAIL  : "<< ptr->EMAIL <<endl;                     
				cout<<"\t\t\t\t\t"<<"    AMOUNT : "<< ptr->AMOUNT <<endl;                  
				cout<<"\t\t\t\t\t"<<"    DATE   : "<< ptr->DATE <<endl;                    
				cout<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<endl;
				// Move to the next node in the linked list
				ptr = ptr->next; 
		  	}
		}
		
		
	//-------------------------------------------------------------------------------->> DEPOST - DLL <<-------------------------------------------------------------------------------------------
	// Function to deposit a new loan amount into a user's account
		void Deposit(string ID1,int New_loanAmount){
			traverse();  
			Node* ptr;  
			ptr = head;   
			
			 
			while(ptr != NULL) 
			{ 
			
				if(ptr->ID==ID1 )
				{
					
					ptr->AMOUNT=ptr->AMOUNT+New_loanAmount; 
					
					Update(ptr);
				}
				// Move to the next node in the linked list
				ptr = ptr->next; 
			}
		}
	
	//--------------------------------------------------------------------------------->> WITHDRAW - DLL <<-----------------------------------------------------------------------------------------
	// Function to withdraw a specified amount from a user's account
		void Withdraw_Amount(string ID1,int New_loanAmount){
			traverse(); 
			Node* ptr;  
			ptr = head; 
			
			while(ptr != NULL) 
			{ 
			 
				if(ptr->ID==ID1 )
				{
					
					if(ptr->AMOUNT<New_loanAmount)
					{
						system("cls"); // Clear the console screen
						//system("color 0A");
						cout<<"\n\n\n\n\n\n";
						cout<<"\t\t\t\t\t";
						for(int i=0;i<=31;i++)
						cout<<load;
						cout<<"\n";
						cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
						cout<<"\t\t\t\t\t"<<load<<"  Sorry! Bank Balance is Low  "<<load<<endl;   // Print a warning message about insufficient funds
						cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
						cout<<"\t\t\t\t\t";
						for(int i=0;i<=31;i++)
						cout<<load;
						cout<<"\n";
						getch(); // Wait for a key press from the user
						system("cls");
					}
					else   // If sufficient funds are available, deduct the amount
					ptr->AMOUNT=ptr->AMOUNT-New_loanAmount; 
					
					
					Update(ptr); 
				}
			
				ptr = ptr->next; 
			}
		}
		
		//--------------------------------------------------------------------------------->> TRANSFER - DLL <<--------------------------------------------------------------------------------------------------------------------------
		// Function to transfer an amount from one user's account to another
		int Transfer_Amount(string ID1,string ID2,int New_loanAmount){
			traverse();    
			Node* ptr;     
			ptr = head;    
			int count = 0;   
			
			// Loop through each node in the linked list to find the recipient's account
			while(ptr != NULL) 
			{ 
				 
				if(ptr->ID == ID2)
				{
					ptr->AMOUNT = ptr->AMOUNT + New_loanAmount; 
					count++;                                    
				}
				ptr = ptr->next;   
			}
			if(count == 0) // if id not found
			{
				return 0;
			}
			ptr = head;  
			while(ptr != NULL)
			{
	
				if(ptr->ID==ID1 )
				{

					if(ptr->AMOUNT<New_loanAmount)
					{
						system("cls");
						//system("color 0A");
						cout<<"\n\n\n\n\n\n";
						cout<<"\t\t\t\t\t";
						for(int i=0;i<=31;i++)
						cout<<load;
						cout<<"\n";
						cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
						cout<<"\t\t\t\t\t"<<load<<"  Sorry! Bank Balance is Low  "<<load<<endl;  // Print a warning message about insufficient funds
						cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
						cout<<"\t\t\t\t\t";
						for(int i=0;i<=31;i++)
						cout<<load;
						cout<<"\n";
						getch();  // Wait for a key press from the user
						system("cls");
					}
					else {    // If sufficient funds are available, deduct the amount
					ptr->AMOUNT=ptr->AMOUNT-New_loanAmount; 
					Update(ptr);
				 }
				}
				ptr = ptr->next;  // Move to the next node in the linked list
			}
			return 1;    
		}
	
	//===================================================delete account
		bool Delete_Account(string t_id){
			traverse();
			Node* curr = head;
			while(curr != NULL)
			{
				if(curr->ID == t_id)
				{
					if(curr == head)
					{
						Node* temp = head;
						curr = curr->next;
						curr->prev = NULL;
						head = curr;
						delete temp;
						Update(head);
						return 1;
					}
					if(curr == tail)
					{
						Node* temp = tail;
						curr = curr->prev;
						curr->next = NULL;
						tail = curr;
						delete temp;
						Update(head);
						return 1;
					}
					Node* temp = curr;
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
					delete temp;
					Update(head);
					return 1;
				}
				curr = curr->next;
			}
			return 0;
		}  
	
	
	//																---->> SEARCH ACCOUNT - DLL <<----
	
		void Search_Account(string ID1,string cnic) {
			traverse();
			int c=0;
			Node* ptr;
			ptr = head;  
			while(ptr != NULL) 
			{
				if(ptr->ID==ID1)
				{
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
						cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      |      Detail     |     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<"    NAME   : "<< ptr->NAME <<endl;
					cout<<"\t\t\t\t\t"<<"    ID     : 7861 1111 1111 "<< ptr->ID <<endl;
					//cout<<"\t\t\t\t"<<"    PIN    : "<< ptr->PIN_N <<endl;
					cout<<"\t\t\t\t\t"<<"    MOBILE : "<< ptr->MOBILE  <<endl;
					cout<<"\t\t\t\t\t"<<"    CNIC   : "<< ptr->CNIC_c <<endl;
					cout<<"\t\t\t\t\t"<<"    Mail   : "<< ptr->EMAIL <<endl;
					cout<<"\t\t\t\t\t"<<"    AMOUNT : "<< ptr->AMOUNT <<endl;
					cout<<"\t\t\t\t\t"<<"    DATE   : "<< ptr->DATE <<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					c++;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
					cout<<load;
					cout<<"\n";
				}
				else if(ptr->CNIC_c== cnic){
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
						cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      |      Detail     |     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<"    NAME   : "<< ptr->NAME <<endl;
					cout<<"\t\t\t\t\t"<<"    ID     : 7861 1111 1111 "<< ptr->ID <<endl;
					//cout<<"\t\t\t\t"<<"    PIN    : "<< ptr->PIN_N <<endl;
					cout<<"\t\t\t\t\t"<<"    MOBILE : "<< ptr->MOBILE  <<endl;
					cout<<"\t\t\t\t\t"<<"    CNIC   : "<< ptr->CNIC_c <<endl;
					cout<<"\t\t\t\t\t"<<"    Mail   : "<< ptr->EMAIL <<endl;
					cout<<"\t\t\t\t\t"<<"    AMOUNT : "<< ptr->AMOUNT <<endl;
					cout<<"\t\t\t\t\t"<<"    DATE   : "<< ptr->DATE <<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					c++;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
					cout<<load;
					cout<<"\n";
				}
				ptr = ptr->next; 
			}
			if(c==0)
			{
				system("cls");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)
				cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  SORRY THIS ID NOT FOUND     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)
				cout<<load;
				cout<<"\n";
			}
		}
		
		void modify_main(string t_id,char ch){
		traverse();
		bool found = false;
			Node* ptr;
			ptr = head;  
			while(ptr != NULL) 
			{
				if(ptr->ID==t_id)
				{
					found=true;
					if(ch=='1'){
						system("cls");
						cout<<"\n\n\n";
						cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
						cout<<"\t\t\t\t\t"<<load<<"         Modify Name          "<<load<<endl;
						cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
						cout<<"\t\t\t\t\t"<<"                 || ID ||      "<<endl;
						cout<<"\t\t\t\t\t"<<"                  "<< ptr->ID <<endl<<endl;
						cout<<"\t\t\t\t\t"<<" New NAME   : ";
						cin>>ptr->NAME; 
						ptr->NAME=removeIntegers(ptr->NAME);
						cout<<"\n\n\t\t\t\t\t Changed Successfully";
						_getch();
					}
					else if(ch=='2'){
						do {
							system("cls");
							cout<<"\n\n\n";
							cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
							cout<<"\t\t\t\t\t"<<load<<"         Modify Number        "<<load<<endl;
							cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
							cout<<"\t\t\t\t\t"<<"                 || ID ||      "<<endl;
							cout<<"\t\t\t\t\t"<<"                  "<< ptr->ID <<endl<<endl;
							int length=0;
							char password=0;
							ptr->MOBILE.clear();
							cout<<"\n\t\t\t\t\t  Mobile    : ";
							while(length!=11) 
							{
								password = _getch(); 
								if(password>=48 && password<=57) 
								{
									ptr->MOBILE.push_back(password);
									cout << password;
									length++;
									if(length==4)	cout<<"-";
								}
								
							}
							
						
						        if (!isValidPakistaniMobileNumber(ptr->MOBILE)) {
						            cout << "\n\n\t\t\t\tInvalid Pakistani mobile number. Please try again." << endl;
						            _getch();
						        }
				    		} while (!isValidPakistaniMobileNumber(ptr->MOBILE));
							cout<<"\n\n\t\t\t\t\t Changed Successfully";
							_getch();
						}
						else if(ch=='3'){
							system("cls");
							cout<<"\n\n\n";
							cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
							cout<<"\t\t\t\t\t"<<load<<"         Modify Pin           "<<load<<endl;
							cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
							cout<<"\t\t\t\t\t"<<"                 || ID ||      "<<endl;
							cout<<"\t\t\t\t\t"<<"                  "<< ptr->ID <<endl<<endl;
							cout<<"\t\t\t\t\t       New PIN :     ";
							int length = 0;
							char password;
							ptr->PIN_N.clear();
							while (length < 4) 
							{
								password = _getch();
								if (password >= '0' && password <= '9') 
								{  
									ptr->PIN_N.push_back(password);  
									cout << '*';
									length++;
								}
							}
							cout<<"\n\n\t\t\t\t\t Changed Successfully";
							_getch();
							
						}
						else if(ch=='4'){
							do {
								system("cls");
								cout<<"\n\n\n";
								cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
								cout<<"\t\t\t\t\t"<<load<<"         Modify Gmail         "<<load<<endl;
								cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
								cout<<"\t\t\t\t\t"<<"                 || ID ||      "<<endl;
								cout<<"\t\t\t\t\t"<<"                  "<< ptr->ID <<endl<<endl;
				        		cout<<"\n\t\t\t\t\t New Email    : ";
				        		cin >> ptr->EMAIL;
				
				        		if (!isValidGmail(ptr->EMAIL)) {
				            		cout << "Invalid Gmail address. Please try again." << endl;
				        		}
				    			} while (!isValidGmail(ptr->EMAIL));
				    			cout<<"\n\n\t\t\t\t\t Changed Successfully";
								_getch();
						}
				}
				ptr = ptr->next; 
			}
			if(found == true)
			{
				Update(ptr);
			}
	}
		
		// DEPOSIT SLIP
	
		void Slip_Atm_Deposit(string ID1,int deposit_amount) {
			traverse();
			int c=0;
			Node* ptr;
			ptr = head;  
			while(ptr != NULL) 
			{
				if(ptr->ID==ID1)
				{
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"    ATM MANAGEMENT SYSTEM     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
						cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      |   DEPOSIT SLIP  |     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<"   NAME     : "<< ptr->NAME <<endl;
					cout<<"\t\t\t\t\t"<<"   ACC NO   : "<< ptr->ID <<endl;
					//cout<<"\t\t\t\t"<<"    PIN    : "<< ptr->PIN_N <<endl;
//					cout<<"\t\t\t\t\t"<<"    MOBILE : "<< ptr->MOBILE <<endl;
//					cout<<"\t\t\t\t\t"<<"    CNIC   : "<< ptr->CNIC_c <<endl;
					cout<<"\t\t\t\t\t"<<"   D AMOUNT : "<< deposit_amount <<endl;
					cout<<"\t\t\t\t\t"<<"   R AMOUNT : "<< ptr->AMOUNT <<endl;
					cout<<"\t\t\t\t\t"<<"   DATE     : "<< ptr->DATE <<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					c++;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
					cout<<load;
					cout<<"\n";
				}
				ptr = ptr->next; 
			}
		}
		
		
		// WITHDRAW SLIP
	
	
	void Slip_Atm_Withdraw(string ID1,int withdrawn_amount) {
			traverse();
			int c=0;
			Node* ptr;
			ptr = head;  
			while(ptr != NULL) 
			{
				if(ptr->ID==ID1)
				{
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"    ATM MANAGEMENT SYSTEM     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
						cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      |  WITHDRAW SLIP  |     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<"   NAME            : "<< ptr->NAME <<endl;
					cout<<"\t\t\t\t\t"<<"   Account NO      : "<< ptr->ID <<endl;
					cout<<"\t\t\t\t\t"<<"   Withdraw AMOUNT : "<< withdrawn_amount <<endl;
					cout<<"\t\t\t\t\t"<<"   Running  AMOUNT : "<< ptr->AMOUNT <<endl;
					cout<<"\t\t\t\t\t"<<"   DATE            : "<< ptr->DATE <<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					c++;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
					cout<<load;
					cout<<"\n";
				}
				ptr = ptr->next; 
			}
		}

};

//=========================================================================================================================================================================================	
//																 ====================
//																	CLASS ---- BANK
//																 ====================
//=========================================================================================================================================================================================	
class Bank{
	public:
		//Starting line design //?
		virtual void starting_line(string a){};
		//Introduction of group memebers    
		virtual void group_introduction(){};
		virtual void starting_line_atm(){}
		//Admin login function
		virtual bool Admin_login(){}
		// Main manue functions
		virtual int main_manu(){}
		virtual int main_manu_2(){} 
		virtual int atm_manu(){}
		virtual int Display_manu(){}
		virtual int setting(){}
		virtual void change_user_id(){}
		virtual void change_user_PIN(){}
		virtual void logout(){}
		virtual void Create_Account(){}
		virtual void Modify_Account(){}
		virtual void Del_Acc(){}
		virtual bool login_user_account(){}
		virtual bool login_user_account_atm(){}
		virtual void Search_accounts(){}
		virtual int User_Login_Manu(){}
		virtual void Withdraw(){}
		virtual void Detail(){}
		virtual string IntToString(int a){}
		virtual void Deposit(){}
		virtual void Display_Accounts(){}
		virtual void Transfer(){}
};

//=========================================================================================================================================================================================
//																 =====================
//																	CLASS ---- MAN_U
//																 =====================
//=========================================================================================================================================================================================																 
class Man_u:public Bank{
	private:
		string ID,PIN, confirm_pin;
		char password,password2;
		int confirm;
	public:
		
		
	//																---->> MAIN MENU - MAN_U <<----
		
		int main_manu(){
			int Select;
			do{
				system("cls");
				cout<<"\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"   BANKING MANAGEMENT SYSTEM    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       |     Bank Manu   |      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [1]  :  Create Account      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [2]  :  Delete Account      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [3]  :  Login User Account  "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [4]  :  Display Accounts    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [5]  :  Search Accounts     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [6]  :  Setting             "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      Logout (Press: esc)       "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				Select = _getch();
			}while(Select!='1'&&Select!='2'&&Select!='3'&&Select!='4'&&Select!='5'&&Select!='6'&&Select!=27);
			return Select;
		}
		
		
	//																---->> ATM MANU - MAN_U <<----
		
		int atm_manu(){
			int Select;
			do{
				system("cls");
				cout<<"\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"   BANKING MANAGEMENT SYSTEM    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       |     ATM Manu    |      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [1]  :  Check Balance       "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [2]  :  Deposit Money       "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [3]  :  Withdraw Money      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [4]  :  Transfer Money      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      Logout (Press: esc)       "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)
				cout<<load;
				cout<<"\n";
				
				Select=_getch();
			}while(Select!='1'&&Select!='2'&&Select!='3'&&Select!='4'&&Select!=27);
			return Select; // used to return the selected value
		}
		
		
	//	?															---->> MAIN MANU 2 - MAN_U <<----	
		
		int main_manu_2(){
			int Select;
			do{
				system("cls");
				cout<<"\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"   BANKING MANAGEMENT SYSTEM    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       |     Main Manu   |      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [1]  :  Bank Management     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [2]  :  ATM   	         "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      Exit (Press: esc)         "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				Select = _getch();
			}while(Select != '1' && Select != '2' && Select != 27 );
			return Select; // used to return the selected value
		}
		
		int Display_manu(){
			int Select;
			do{
				system("cls");
				cout<<"\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"   BANKING MANAGEMENT SYSTEM    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       |     Display     |      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    [1]  : All Accounts         "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"    Back (Press: BackSpace )    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=33;i++)	cout<<load;
				cout<<"\n";
				Select=_getch();
			}while(Select!='1'&&Select!='2'&&Select!=8);
			return Select; // used to return the selected value
		}
		
		
	//																---->> SETTING - MAN_U <<----	
			
		int setting(){
			int Select;
			do{
				system("cls");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      |     SETTING     |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [1]   :  Change ID      "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [2]   :  Change PIN     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      Back  (<-Backspace)     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				Select=_getch();
			}while(Select!='1'&&Select!='2'&&Select!=8);
			return Select;  
		}
		
		
	//																---->> LOGOUT - MAN_U <<----	
		
		void logout()
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t\t\t";
			cout<<"Logout.";
			Sleep(500);
			cout<<".";
			Sleep(500);
			cout<<".";
			Sleep(500);
			cout<<".";
			Sleep(500);
		}
		
		
	//															---->> CHANGE Admin ID - MAN_U <<----	
		
		void change_user_id()
		{
			p:
			system("cls");
			string ID,PIN;
			int confirm;
			ifstream read("Admin.txt");
			if(!read)
			{
				read.close();
				goto p;
			}
			read >> ID;
			read>>PIN;
			read.close();
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |     SETTING     |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      New ID :";
			cin>>ID;
			cout<<"\t\t\t\t\t"<<load<<"      New ID Confirm  (Y/N)   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)
			cout<<load;
			cout<<"\n";
			confirm=_getch();
			if(confirm == 'y' || confirm == 'Y')
			{
				p1:
				ofstream wrt("Admin.txt");
				if(!wrt)
				{
					wrt.close();
					goto p1;
				}
				wrt<<ID<<endl;
				wrt<<PIN<<endl;
				wrt.close();
			}
			else if(confirm=='n' || confirm=='N'){}
			else 	change_user_id();
			system("cls");	
		}
		
		
	//																---->> CHANGE Admin PIN - MAN_U <<----	
		
		void change_user_PIN() 
		{
			p:
			system("cls");
			ifstream read("Admin.txt");
			if(!read)
			{
				read.close();
				goto p;
			}
			read>>ID;
			read.close();
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)
			cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)
			cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |     SETTING     |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t       New PIN :     ";
			int length = 0;
			while (length < 4) 
			{
				password = _getch();
				if (password >= '0' && password <= '9') 
				{  
					PIN.push_back(password);  
					cout << '*';
					length++;
				}
			}
			cout<<endl;
			cout<<"\t\t\t\t\t       Confirm PIN : ";
			length=0;
			while(length < 4)   //for confirm PIN
			{
				password2 = _getch();
				if(password2 >= '0' && password2 <= '9')  //only enter numeric value in PIN
				{
					confirm_pin.push_back(password2); //store char by char in string (confirm_pin)
					cout << '*';
					length++;
				}
			}
			cout<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      Submit   (Y/N)          "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			confirm=_getch();
			if(confirm=='y'|| confirm=='Y')
			{
				if(PIN==confirm_pin)
				{
					p1:
					fstream wrt;
					wrt.open("Admin.txt",ios::out);
					if(!wrt)
					{
						wrt.close();
						goto p1;
					}
					wrt<<ID<<endl;
					wrt<<PIN;	    
					wrt.close();
				}
			}
			else  if(confirm=='n'|| confirm=='N'){}
			else
			{
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n\n";
				cout<<"\t\t\t\t\tPlease Enter Correct ID and PIN\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				system("pause");	
				change_user_PIN();
			}
			read.close();	
		}
};


//=========================================================================================================================================================================================
//																 =====================
//																	CLASS ---- LOGIN
//																 =====================
//=========================================================================================================================================================================================
class Login:public Bank{
	public:
		
		
	//	?														---->> STARTING LINE - LOGIN <<----	
		
		void starting_line_atm(){
			PlaySound(TEXT("WELCOME A.wav"),NULL,SND_SYNC);
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"    WELCOME TO ATM            "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n\n\n";
			cout<<"\t\t\t      Loading ";
			for(int i=0; i<35; i++)
			{
				cout<<load;
				if(i<10)
				Sleep(300);
				if(i>=10 && i<20)
				Sleep(150);
				if(i>=10)
				Sleep(25);
			}
			system("cls");
		}
		void starting_line(string a){
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t"<<a<<endl<<endl<<endl;
			for(int i=0;i<118;i++)
			{
				Sleep(15);
				cout<<load;
			}	
		}
		
	//														---->> GROUP INTRODUCTION - LOGIN <<----	
		
		void group_introduction(){ 
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |  Group Members  |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"    Abdul Rahman              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"     Hafiz Ahmed Zahid        "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			PlaySound(TEXT("WELCOME B.wav"),NULL,SND_SYNC);
			getch();	
			system("cls");
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n\n\n";
			cout<<"\t\t\t      Loading ";
			for(int i=0; i<35; i++)
			{
				cout<<load;
				if(i<10)
				Sleep(300);
				if(i>=10 && i<20)
				Sleep(150);
				if(i>=10)
				Sleep(25);
			}
			system("cls");
		}
		
	//														---->> ADMIN LOGIN - LOGIN <<----	//change name to admin **			
		
		bool Admin_login(){
			string user_id, pin,compare_id,compare_pin;
			char password;
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=32;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"   BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=32;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |      Login      |      "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"       Please enter your       "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      Admin id and Password    "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"    For login this Software    "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=32;i++)	cout<<load;
			cout<<"\n";
			ifstream rd("Admin.txt");
			if(!rd)
			{
				p1:
				ofstream wrt("Admin.txt");
				if(!wrt)
				{
					wrt.close();
					goto p1;
				}
				wrt<<"root"<<endl;
				wrt<<"1234"<<endl;
				wrt.close();
			}
			else
			{
				rd>>compare_id;
				rd>>compare_pin;
				cout<<"\n\t\t\t\t\t Admin ID:   ";
				cin>>user_id;
				password = 0;
				cout<<"\t\t\t\t\t      PIN:   ";
				//cin >> pin;
				while(password != 13) 
				{
					if(password >= 48 && password <= 57) 
					{
						pin.push_back(password);
					    cout << '*';
					    PlaySound(TEXT("ATM KEY.wav"),NULL,SND_SYNC);
					}
					password = _getch(); 
				}		
			}
			rd.close();
			if(user_id == compare_id && pin == compare_pin)  return true;
			else	return false;		
		}
};

//=========================================================================================================================================================================================
//																 ========================
//																	CLASS ---- CUSTOMER
//																 ========================
//=========================================================================================================================================================================================
class Customer: public Bank{
	private:
		char password;
		string name, id ,Phone,CNIC,pin,retype_pin,date,email;
		int length;
	public:
		
		
	//														---->> CREATE ACCOUNT - CUSTOMER <<----
		string removeIntegers(const string& input) {
		    string result;
		    for (char c : input) {
		        if (!isdigit(c)) {
		            result += c;
		        }
		    }
		    return result;
		}
		
		bool isValidGmail(const string& email1) {
		    const regex pattern(R"(^[a-zA-Z0-9._%+-]+@gmail\.com$)");
		    return regex_match(email1, pattern);
		}
		bool isValidPakistaniMobileNumber(const string& Phone1) {
		    const regex pattern(R"(^(?:\+923|03)?[0-4]\d{8}$)");
		    return regex_match(Phone1, pattern);
		}
		
		void Create_Account(){
			id="\0";
			Phone="\0";
			CNIC="\0";
			pin="\0";
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |   New Account   |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t  Name    : ";
			int t_i=0;
			l:
			string name;
			cin>>name;
			name = removeIntegers(name);
			if(name == "")
			{
				goto l;
			}
			length=0;
			password=0;
			int id2;
			ifstream file("id.txt");
			file >> id2;
			file.close();
			id2++;
			id = to_string(id2);
			cout<<"\t\t\t\t\t  Account Number    : ";
			cout<<"7861 11111111"<<id<<endl;
			cout<<"\t\t\t\t\t  PIN    : ";
			while(length!=4) 
			{
				if (password>=48 && password<=57)
				{
					pin.push_back(password);
					cout <<"*";
					length++;
				}
				password = _getch(); 
			}
			do {
			Phone.clear();
			length=0;
			password=0;
			cout<<"\n\t\t\t\t\t  Mobile    : ";
			while(length!=11) 
			{
				if(password>=48 && password<=57) 
				{
					Phone.push_back(password);
					cout << password;
					length++;
					if(length==4)	cout<<"-";
				}
				password = _getch(); 
			}
			
		        if (!isValidPakistaniMobileNumber(Phone)) {
		            cout << "Invalid Pakistani mobile number. Please try again." << endl;
		        }
    		} while (!isValidPakistaniMobileNumber(Phone));
    		cin.clear();
    		
			length=0;
			password=0;
			cout<<"\n\t\t\t\t\t  CNIC      : ";
			while(length != 13) 
			{
				if(password>=48 && password<=57) 
				{
					CNIC.push_back(password);
					cout << password;
					length++;
					if(length == 5 || length==12)	cout<<"-";
				}
				password = _getch(); 
			}
			cin.clear();
			do {
        		cout<<"\n\t\t\t\t\t  Email    : ";
        		cin >> email;
        		if (!isValidGmail(email)) {
            		cout << "Invalid Gmail address. Please try again." << endl;
        		}
    		} while (!isValidGmail(email));
			cin.clear();
			cout<<"\n\t\t\t\t\t  Date     : ";
			time_t now = time(0);
			tm *ltm = localtime(&now);
			cout << ltm->tm_mday;
			cout << ":"<< 1 + ltm->tm_mon;
			cout << ":" << 1900 + ltm->tm_year << endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			string a;
			ofstream te("t.txt");
			te<<ltm->tm_mday<<":"<<1 + ltm->tm_mon<<":"<<1900 + ltm->tm_year<<endl;
			te.close();
			ifstream to("t.txt");
			to>>a;
			Double_Pointer_Linked Ob;
			Ob.Create_New_Account(id,pin,name,Phone,CNIC,5000,a,email);
			ofstream file2("id.txt");
			file2 << id2;
			file2.close();
			ifstream r("count.txt");	
			int i=0;
	        if(r)
	        {
	            r>>i;
	            ofstream s( "count.txt");
	            i=i+8;
	            s<<i;
	        }
	        else
	        {
	            ofstream s( "count.txt");
	            i=0;
	            i=i+8;
	            s<<i;
	        }
	        r.close();
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n\n";
			cout<<"\t\t\t\t\t"<<load<<"   Account Has Been Created   "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n\n";
		}
		
		
		void Del_Acc(){
			system("cls");
			string t_id;
			cout<<"Enter ID to Delete: "; 
			cin>>t_id;
			Double_Pointer_Linked ob;
			if(ob.Delete_Account(t_id))
			{
				cout<<"Account Deleted Successfully."<<endl;
				int n;
				ifstream no("count.txt");
				no >> n;
				no.close();
				n = n-8;
				ofstream no2("count.txt");
				no2 << n;
				no2.close();
				return;
			}
			cout<<"No such ID!"<<endl;
			
		}
		
		
		
	//														---->> DSIPLAY ACCOUNTS - CUSTOMER <<----
		
		void Display_Accounts(){
			system("cls");
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |   All Accounts  |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			Double_Pointer_Linked ob;
			ob.display_ALL();
		}
		
};

//=========================================================================================================================================================================================
//																 ============================
//																	CLASS ---- USER ACCOUNT
//																 ============================
//=========================================================================================================================================================================================
class User_Account:public Bank{
	private:
		string id,check_id,pin,check_pin,data,DVL3, DVL4, DVL5, DVL7, DVL18;
		int length,no,g,DVL6,DVL9,DVL10;
		char password;
		int index,index1,index2,position;
		int W,D;
	public:
	//														---->> LOGIN USER ACCOUNT - USER ACCOUNT <<----		
    	bool login_user_account(){
			system("cls");
			bool log=false;
			length=0;
			password=0;
			id.clear();
			pin.clear();
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |  Login Account  |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t         ID  : ";
			length = 0;
			while(password!=13 && length!=4)
			{
				if (password>=48 && password<=57)
				{
					id.push_back(password);
					PlaySound(TEXT("ATM KEY.wav"),NULL,SND_SYNC);
					cout <<password;
					length++;
				}
				password = _getch(); 
			}
			cout<<"\n\t\t\t\t\t         PIN : ";
			length = 0;
			while(password!=13 && length!=4)
			{
				if (password>=48 && password<=57)
				{
					pin.push_back(password);
					PlaySound(TEXT("ATM KEY.wav"),NULL,SND_SYNC);
					cout <<"*";
					length++;
				}
				password = _getch(); 
			}
			p:
			ifstream w("User.txt");
			if(!w)
			{
				w.close();
				goto p;
			}
			int n=0;
	        ifstream no("count.txt");
	        no >> n;
	        no.close();
			for(int i=0; i<n; i=i+8)
			{
				w >> check_id;          w.ignore();
				w >> check_pin;         w.ignore();
				getline(w,DVL3,',');	w.ignore(); 
				w >> DVL4;				w.ignore();
				w >> DVL5;				w.ignore();
				w >> DVL6;				w.ignore();
				w >> DVL7;				w.ignore();
				w >> DVL18;             w.ignore();
				if(check_id==id && check_pin==pin)
				{
					cout<<endl;
					cout<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n\n";
					cout<<"\t\t\t\t\t"<<"     WELCOME  ["<<DVL3<<"]"<<endl;
					cout<<"\n\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n\n";
					PlaySound(TEXT("LOGGED IN SUCCES.wav"),NULL,SND_SYNC);
					return true;
				}
			}
			w.close();
			if(log==false)
			{
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;	 
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"     Incorrect Password       "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n\n";
				getch();
			}
			return false;
		}
    bool login_user_account_atm(){
			system("cls");
			bool log = false;
			length=0;
			password=0;
			id.clear();
			pin.clear();
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      |  Login Account  |     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t         ID  : ";
			//cin>>id;
			password = 0;
			length = 0;
			while(password!=13 && length!=4)
			{
				if (password>=48 && password<=57)
				{
					id.push_back(password);
					PlaySound(TEXT("ATM KEY.wav"),NULL,SND_SYNC);
					cout <<password;
					length++;
				}
				password = _getch(); 
			}
			cout<<"\n\t\t\t\t\t         PIN : ";
			password=0;
			length = 0;
			while(password!=13 && length!=4)
			{
				if (password>=48 && password<=57)
				{
					pin.push_back(password);
					PlaySound(TEXT("ATM KEY.wav"),NULL,SND_SYNC);
					cout <<"*";
					length++;
				}
				password = _getch(); 
			}
			p:
			ifstream w("User.txt");
			if(!w)
			{
				w.close();
				goto p;
			}
			int n=0;
	        ifstream no("count.txt");
	        no >> n;
	        no.close();
			for(int i=0; i<n; i=i+8)
			{
				w >> check_id;          w.ignore();
				w >> check_pin;         w.ignore();
				getline(w,DVL3,',');	w.ignore(); 
				w >> DVL4;				w.ignore();
				w >> DVL5;				w.ignore();
				w >> DVL6;				w.ignore();
				w >> DVL7;				w.ignore();
				w >> DVL18;             w.ignore();
				if(check_id==id && check_pin==pin)
				{
					cout<<endl;
					cout<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n\n";
					cout<<"\t\t\t\t\t"<<"     WELCOME  ["<<DVL3<<"]"<<endl;
					cout<<"\n\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n\n";
				    PlaySound(TEXT("LOGGED IN SUCCES.wav"),NULL,SND_SYNC);
					return true;
				}
			}
			w.close();
			if(log==false)
			{
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;	 
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"     Incorrect Password       "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n\n";
				getch();
			}
			return false;
		}
	//														---->> DSIPLAY ACCOUNTS - USER ACCOUNT <<----
		
		void Search_accounts(){
			length=0;
			password=0;
			pin="\0";
			int option;
			do{
				system("cls");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      |     Search      |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"        [1]   :   ID          "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"        [2]   :   CNIC        "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      Back  (<-Backspace)     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				option=getch();
			}while(option!='1' && option!='2' && option!= 8);
			string id1,cnic;
			if(option=='1')
			{
				system("cls");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      |  Search by ID   |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t      ID  : ";
				cin>>id1;
			}
			
			if(option=='2')
			{
				system("cls");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      |  Search by CNIC |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t      CNIC : ";
				char p=0;
				while(p!=13 && length!=13) 
				{
					if(p>=48 && p<=57) 
					{
						pin.push_back(p);
						cout << p;
						length++;
						if(length==5 || length==12)
						cout<<"-";
					}
					p = _getch(); 
				}
			}
			cnic = pin;
			Double_Pointer_Linked ob;
			if(option!=8)
			ob.Search_Account(id1,cnic);
		}
		
		
	//														---->> USER LOGIN MANU - USER ACCOUNT <<----	
		
		int User_Login_Manu(){
			int S;
			do{
				system("cls");
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      |   User Account  |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [1] : Withdraw          "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [2] : Deposit           "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [3] : Detail            "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [4] : Transfer          "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      [5] : Modify Account    "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      Back  (<-Backspace)     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				S=_getch();
			}while(S!='1'&&S!='2'&&S!='3'&&S!='4'&&S!='5'&&S!=8);
			return S;
		}
		
		void Modify_Account(){
			while(true){
			char choic;
			do{
				system("cls");
				cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"         Modify Account       "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)
						cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"     ~~~~~~~~~~~~~~~~~~~~~    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"     |  What do Want to  |    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"     |       Modify      |    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"     ~~~~~~~~~~~~~~~~~~~~~    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      [1]  :  Name            "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      [2]  :  Mobile          "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      [3]  :  Password        "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"      [4]  :  Gmail           "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"    Back (Press: Bspace )     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int i=0;i<=31;i++)
					cout<<load;
					cout<<"\n";
					choic=_getch();
					if(choic==8){
						return;
					}
			}while(choic!='1'&& choic!='2'&& choic!='3' && choic!='4');
			Double_Pointer_Linked Ob;
			Ob.modify_main(id, choic);
		}
	}
		
		
		
	//																---->> DETAIL - USER ACCOUNT <<----
		
		void Detail(){
			Double_Pointer_Linked obj;
			obj.Search_Account(id,"0");
		}
		
		
	//																---->> DEPOSIT - USER ACCOUNT <<----	
	
		void Deposit(){
			do{
				 k:
				system("cls");
				int take1;
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      | Deposit  Amount |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t         Amount  : ";
				if (cin >> W) 
				 {
           		 break;
		         } 
				else 
				{
		            cin.clear(); 
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
		            cout << "Invalid input. Please enter an integer.\n";
		            _getch();
					goto k;
		        }
				if(W<=0)
				{
					cout<<"\n\t\t\t\t\t";
					for(int i=0;i<=31;i++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"  Please Enter Valid Range    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int i=0;i<=31;i++)	cout<<load;
					cout<<"\n";
					getch();
				}
			}while(W<=0);
			
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"       Yes : ('Y' OR 'y')     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"        NO : ('N' OR 'n')     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			
			do{
				g=getch();
			}while(g!='Y'&&g!='y'&&g!='N'&&g!='n');
			system("cls");
			if(g=='Y'||g=='y')
			{
				Double_Pointer_Linked Ob;
				Ob.Deposit(id,W);
				cout<<"\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t           Slip.";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)	cout<<load;
				cout<<"\n";
				Ob.Slip_Atm_Deposit(id,W);
			}
		
		}
		
		
	//																---->> WITHDRAW - USER ACCOUNT <<----
		
		void Withdraw(){
			do{
				k:
				system("cls");
				int take1;
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)
				cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)
				cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      | Withdraw Amount |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t         Amount  : ";
				//cin>>W;
				if (cin >> W) 
				 {
           		 break;
		         } 
				else 
				{
		            cin.clear(); 
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
		            cout << "Invalid input. Please enter an integer.\n";
		            _getch();
					goto k;
		        }
				if(W<=0)
				{
					cout<<"\n\t\t\t\t\t";
					for(int i=0;i<=31;i++)
					cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"  Please Enter Valid Range    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int i=0;i<=31;i++)
					cout<<load;
					cout<<"\n";
					getch();
				}
			}while(W<=0);
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"       Yes : ('Y' OR 'y')     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"        NO : ('N' OR 'n')     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			do{
				g=getch();
			}while(g!='Y'&&g!='y'&&g!='N'&&g!='n');
			system("cls");
			if(g=='Y'||g=='y')
			{
				Double_Pointer_Linked Ob;
				Ob.Withdraw_Amount(id,W);
				cout<<"\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout<<"\t\t\t\t\t           Slip.";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				Ob.Slip_Atm_Withdraw(id,W);
			}
		}
		
	void Transfer(){
			do{
				k:
				system("cls");
				int take1;
				cout<<"\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t";
				for(int i=0;i<=31;i++)
				cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t";
				for(int j=0;j<=31;j++)
				cout<<load;
				cout<<"\n";
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      | Transfer Amount |     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
				cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
				cout<<"\t\t\t\t\t         Amount  : ";
				
//				cin>>W;
				 if (cin >> W) 
				 {
           		 break;
		         } 
				else 
				{
		            cin.clear(); 
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
		            cout << "Invalid input. Please enter an integer.\n";
		            _getch();
					goto k;
		        }
				if(W<=0)
				{
					cout<<"\n\t\t\t\t\t";
					for(int i=0;i<=31;i++)
					cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"  Please Enter Valid Range    "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int i=0;i<=31;i++)
					cout<<load;
					cout<<"\n";
					getch();
				}
			}while(W<=0);
			string id2;
			cout<<"\t\t\t\t\t"<<	  "Enter ID to Transfer to: ";// cin>>id2;
			char password = 0;
			int length = 0;
			while(password!=13 && length!=4)
			{
				if (password>=48 && password<=57)
				{
					id2.push_back(password);
					PlaySound(TEXT("ATM KEY.wav"),NULL,SND_SYNC);
					cout <<password;
					length++;
		} 
				password = _getch(); 
			}
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"       Yes : ('Y' OR 'y')     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"        NO : ('N' OR 'n')     "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)	cout<<load;
			cout<<"\n";
			do{
				g=getch();
			}while(g!='Y'&&g!='y'&&g!='N'&&g!='n');
			system("cls");
			if(g=='Y'||g=='y')
			{
				Double_Pointer_Linked Ob;
				if(!Ob.Transfer_Amount(id,id2,W))
				{
					cout<<"\t\t\t\t\t";
					for(int i=0; i<31; i++)		cout << load;
					cout<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                             "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"          NU SUCH ID!        "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"        TRANSFER FAILED!     "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                             "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int i=0; i<31; i++)		cout << load;
					cout<<endl;
					return;
				}
				cout<<"\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout<<"\t\t\t\t\t        Transfer Slip.";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				Detail();
			}
			}
		};


	
	//																-------->>>>>> MAIN <<<<<<---------
	
int main(){
	system("color A");
	Double_Pointer_Linked ob;
	Bank* a[4]; 
	Login obj1; 
	Man_u obj2; 
	Customer obj3;
	User_Account obj4;
	a[0]= &obj1; //create an object of class bank 
	a[1]= &obj2; 
	a[2]= &obj3;
	a[3]= &obj4;
	int select2;
	a[0]->group_introduction(); 
	system("cls");
	string wlm = "WELCOME TO BANKING MANAGEMENT SYSTEM";
	a[0]->starting_line(wlm);
	p:
	while(true)
	{
		system("cls");
		int selct; 
		selct = a[1]->main_manu_2();
		
		if(selct=='1')
		{
			a:
			bool check;
			bool fc; 
			system("cls");
			check = a[0]->Admin_login();
			if(check == true){
				
				wlm="     THANKS YOU SUCCESSFULY ENTERED TO BANK ";
				a[0]->starting_line(wlm);
				PlaySound(TEXT("LOGGED IN SUCCES.wav"),NULL,SND_SYNC);
			}
			do{ 
				system("cls");
				if(check==true)  
				{
					int Select;
					b:
					g:
					system("cls");
					Select = a[1]->main_manu();
					system("cls");
					if(Select == '1')
					{
						a[2]->Create_Account();
						_getch();
					}
					else if(Select=='2'){
						a[2]->Del_Acc();
						_getch();
					}
					else if(Select=='3')
					{
						bool c;
						do{	
							c=a[3]->login_user_account();
							_getch();
						}while(c==false);
							
							if(c==true){
						do{
							select2 = a[3]->User_Login_Manu();
							if(select2 == '1')
							{
								a[3]->Withdraw();
								_getch();
							}
							else if(select2=='2')
							{
								a[3]->Deposit();
								_getch();
							}
							else if(select2=='3')
							{
								a[3]->Detail();
								_getch();
							}
							else if(select2=='4')
							{
								a[3]->Transfer();
								_getch();
							}
							else if(select2=='5')
							{
								a[3]->Modify_Account();
								_getch();
							}
							else if(select2==8)
							{
								a[1]->logout();
								PlaySound(TEXT("THANK B.wav"),NULL,SND_SYNC);
								break;
								
							}
							
						}while(select2!=8);
						select2=0;
						goto g;
				}
			}
					
					else if(Select=='4')
					{
						char d_ch;
						do{
						d_ch=a[1]->Display_manu();
							if(d_ch=='1'){
								a[2]->Display_Accounts();
								_getch();
							}
						}while(d_ch!=8);
					}
					
					else if(Select=='5')
					{
						a[3]->Search_accounts();
						_getch();
					}
					else if(Select=='6')   //into Setting portion
					{
						do{
							select2=a[1]->setting();
							if(select2=='1')  //for change user ID
							{
								a[1]->change_user_id();
								_getch();
							}
							else if(select2=='2')  
							{
								system("cls");
								a[1]->change_user_PIN();
								_getch();
							}
						}while(select2!=8);
					}
					else if (Select == 27)
					{
						a[1]->logout();
						string wlm="              Loging Out"; 
						a[0]->starting_line(wlm);
						goto p;
					}
				}
				else 
				{   
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int i=0;i<=31;i++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout<<"\t\t\t\t\tPlease Enter Correct ID and PIN\n";
					cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout<<"\t\t\t\t\t   [0] Go Back. [Enter] Retry.  \n";
					if(_getch() == '0')
					{
						goto p;
					}
					goto a;
				}
			}while(selct != 27);
		}
		else if(selct=='2')
		{
			system("cls");
			a[0]->starting_line_atm();
			wlm="           WELLCOME TO ATM ";
	    	a[0]->starting_line(wlm);
			q:
			system("cls");
			bool chec;
			chec=a[3]->login_user_account_atm();
			if(chec==true){
				PlaySound(TEXT("LOGGED IN SUCCES.wav"),NULL,SND_SYNC);
				_getch();
				wlm="     THANKS YOU SUCCESSFULY ENTERED TO ATM ";
					a[0]->starting_line(wlm);

			}
			while(true)
			{
				
				if(chec==true)
				{
					int Select;
					
					
					system("cls");
					Select=a[1]->atm_manu();
					system("cls");
					if(Select=='1')
					{
						a[3]->Detail();
						PlaySound(TEXT("TRANS B PROS.wav"),NULL,SND_SYNC);
						_getch();
					}
					else if(Select=='2')
					{
						a[3]->Deposit();
						PlaySound(TEXT("TRANS B PROS.wav"),NULL,SND_SYNC);
						_getch();
					}
					else if(Select=='3')
					{
						a[3]->Withdraw();
						PlaySound(TEXT("TRANS B PROS.wav"),NULL,SND_SYNC);
						_getch();
					}
					else if(Select=='4')
					{
						a[3]->Transfer();
						PlaySound(TEXT("TRANS B PROS.wav"),NULL,SND_SYNC);
						_getch();
					}
					else if(Select==27)
					{
						a[1]->logout();
						PlaySound(TEXT("THANK ATM.wav"),NULL,SND_SYNC);
						string wlm="              Loging Out"; //this strng will on above the starting line
						a[0]->starting_line(wlm);
						
						goto p;
					}
				}
				else 
				{    
					system("cls");
					cout<<"\n\n\n\n\n\n";
					cout<<"\t\t\t\t\t";
					for(int i=0;i<=31;i++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"           A T M              "<<load<<endl;
					cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
					cout<<"\t\t\t\t\t";
					for(int j=0;j<=31;j++)	cout<<load;
					cout<<"\n";
					cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout<<"\t\t\t\t\tPlease Enter Correct ID and PIN\n";
					cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout<<"\t\t\t\t\t   [0] Go Back. [Enter] Retry.  \n";
					char tc=_getch();
					if(tc == '0')
					{
						system("cls");
						goto p;
					}
						
					system("cls");
					goto q;
				}
			}
		}
		else if(selct == 27)
		{
			system("cls");
			exit(0);
		}
	}

	return 0;
}
