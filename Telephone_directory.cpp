#include <iostream>
#include<unordered_map>
#include<cstring>
#include <string.h>
#include <bits/stdc++.h>


using namespace std;

struct Node {
    string name;
    long long int phone;
    string address;
    string dob;
    int ISDcode;
    string country;
    struct Node* next;
    struct Node* prev;
};


// }
void insert_front(struct Node** head,string name,long long int phone,string address,string dob,int ISDcode,string country)
{

    struct Node* newNode = new Node;


    newNode->name = name;
    newNode->address = address;
    newNode->country = country;
    newNode->ISDcode = ISDcode;
    newNode->phone = phone;
    newNode->dob = dob;


    newNode->next = (*head);
    newNode->prev = NULL;


    if ((*head) != NULL)
        (*head)->prev = newNode;
    (*head) = newNode;
}


int val_phone_number(struct Node*head,string name_per)
{
    struct Node* temp;
    temp = head;
    int digits=0;
    while(temp!=NULL) {
        if(temp->name==name_per) {
            while(temp->phone>0) {
                temp->phone = (int)(temp->phone/10);
                ++digits;
            }
            if(digits==10)
                return 1;
            else
                return 0;
        } else
            temp=temp->next;
    }
    return -1;
}

bool mycomp(string a, string b)
{
    //returns 1 if string a is alphabetically
    //less than string b
    //quite similar to strcmp operation
    return a<b;
}

void sortList(struct Node*head)
{
    Node *i,*j;
    int temp;
    string n;
    long long int p;
    string a;
    string DOB;
    string c;
    int isd;
    for(i=head; i->next!=NULL; i=i->next) {
        for(j=i->next; j!=NULL; j=j->next) {
            temp=mycomp(i->name,j->name);
            if(temp!=1) {
                n=i->name;
                i->name=j->name;
                j->name=n;

                p=i->phone;
                i->phone=j->phone;
                j->phone=p;

                c=i->country;
                i->country=j->country;
                j->country=c;

                a=i->address;
                i->address=j->address;
                j->address=a;

                DOB=i->dob;
                i->dob=j->dob;
                j->dob=DOB;

                isd=i->ISDcode;
                i->ISDcode=j->ISDcode;
                j->ISDcode=isd;
            }
        }
    }

}

void displayList(struct Node* ptr)
{
    struct Node* last;
    cout<<"\n\n-------------------TELEPHONE DIRECTORY----------------------"<<endl<<endl;
    while (ptr != NULL) {
        cout<<ptr->name <<": "<< ptr->address<<" "<<ptr->ISDcode<<"-"<<ptr->phone<<" "<<ptr->country<<" "<<ptr->dob<<"\n"<<endl;
        last = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL)
        cout<<"NULL"<<endl<<endl;
}
// int val_hash(unordered_map<string, int> umap,string country,int ISDcode){
//   }


void delete_entry(struct Node* head, string name_del)
{
    Node* temp = head;
    if(head == NULL || head->next == NULL)
        head = NULL;
    else{
        while(temp!=NULL)
        {
            if(temp->name == name_del)
            {
                temp->name = temp->next->name;
                temp->address = temp->next->address;
                temp->country = temp->next->country;
                temp->ISDcode = temp->next->ISDcode;
                temp->phone = temp->next->phone;
                temp->dob = temp->next->dob;
                temp->next = temp->next->next;
            }
            else
                temp = temp->next;
        }
    }
}

void update_entry(struct Node* head,string name,string detail)
{
    struct Node* temp;
    temp = head;
    while(temp!=NULL) {

        if(temp->name==name) {
            if(detail=="number") {
                long long int num;
                cout<<"Enter the new phone number: ";
                cin>>num;
                temp->phone = num;
                break;
            } else if(detail=="country" || detail=="ISDcode") {
                string count;
                int ISD;
                cout<<"Enter the new country and ISD code: ";
                cin>>count>>ISD;
                temp->country = count;
                temp->ISDcode = ISD;
                break;

            } else if(detail=="dob") {
                string dob_new;
                cout<<"Enter the new Date of Birth: ";
                cin>>dob_new;
                temp->dob = dob_new;
                break;
            } else if(detail=="address") {
                string add;
                cout<<"Enter the new Address: ";
                cin>>add;
                temp->address = add;
                break;
            }
        } else {
            temp = temp->next;
        }
    }
}

//main program
int main()
{
    int i,n,o;
    string name,address,dob,country;
    long long int phone;
    int ISDcode;



    /* Start with the empty list */
    struct Node* head = NULL;
    insert_front(&head,"Zara",8779245102,"Champs-Élysées, Paris","25/09/1999",33,"France");
    insert_front(&head,"Amar",8797275102,"Lower Parel,Mumbai","19/02/1986",91,"India");
    insert_front(&head,"Harry",8779245102,"North Reese Avenue, California","20/12/2003",1,"USA");
    insert_front(&head,"Dolly",8999915109,"Charlottenburg-Wilmersdorf, Berlin","09/09/2001",44,"Germany");
    insert_front(&head,"Sam",8779234202,"Birrell Street,Birmingham","17/01/2000",44,"UK");
    insert_front(&head,"Riya",8777512023,"Meritullinkatu, Helsinki","03/07/1997",358,"Finland");
    insert_front(&head,"Avi",9776785992,"Malviya Nagar, Jaipur","29/02/2000",91,"India");
    insert_front(&head,"Emiko",9110338100,"Komatsu-shi, Ishikawa","30/05/2002",85,"Japan");

    // cout<<"Enter the number of entries in the linked list";
    // cin>>n;

    //  for(i=1;i<n+1;i++){
    //  		cout<<"enter the name "<<i<<endl;
    // cin>>name;
    // cout<<"enter the address "<<i<<endl;
    // cin>>address;
    // cout<<"enter the phone number "<<i<<endl;
    // cin>>phone;

    // cout<<"enter the date of birth "<<i<<endl;
    // cin>>dob;
    // cout<<"enter the ISD code "<<i<<endl;
    // cin>>ISDcode;
    // cout<<"enter the name of country "<<i<<endl;
    // cin>>country;
    //  		insert_front(&head,name,phone,address,dob,ISDcode,country);
    //  	}

    sortList(head);
    cout<<"\n\n-------------------TELEPHONE DIRECTORY----------------------"<<endl<<endl;

    displayList(head);
    int k =1;
    while(k == 1) {

        cout<<"\n\n-------------------OPERATIONS MENU---------------------"<<endl;
        cout<<"1:SHOW CONTACT DETAILS"<<endl<<"2:INSERTION OF NEW ENTRTY"<<endl<<"3:DELETION OF ENTRY"<<endl<<"4:VALIDATION OF PHONE NUMBER"<<endl<<"5:UPDATION OF EXISTING ENTRY"<<endl;
        cin>>o;
        switch(o) {
        case 1: {


            cout<<"\nDoubly linked list is as follows: "<<endl;
            displayList(head);
            break;
        }
        case 2: {
            int po = 0,code_v = 0;
            cout<<"Enter the name: "<<endl;
            cin>>name;
            cout<<"Enter the address: "<<endl;
            cin>>address;
            cout<<"Enter the phone number: "<<endl;
            cin>>phone;
            cout<<"Enter the date of birth: "<<endl;
            cin>>dob;
            cout<<"Enter the ISD code: "<<endl;
            cin>>ISDcode;
            cout<<"Enter the name of country: "<<endl;
            cin>>country;
            insert_front(&head,name,phone,address,dob,ISDcode,country);
            //po = val_phone_number(phone);
            /*code_v = val_hash(umap,country,ISDcode);
            	   if(code_v==1){
            	 	    insert_front(&head,name,phone,address,dob,ISDcode,country);
            		sortList(head);
            	}*/
            // else if(po==0){
            // 	cout<<"INVALID NUMBER ENTERED"<<endl;
            // }
            /* else if(code_v==0){
             cout<<"COUNTRY CODE MISMATCH FOUND"<<endl;
            }*/

            break;
        }
        case 3: {

            string name_del;
            cout<<"Enter the name of entry to be deleted: ";
            cin>>name_del;
            delete_entry(head,name_del);
            break;
        }
        case 4: {

            string name_per;
            cout<<"Enter the name of person whose phone number has to be validated: ";
            cin>>name_per;
            //val_phone_number(head,name_per);
            int res = val_phone_number(head,name_per);
            if(res==-1)
                cout<<"\nContact not found"<<endl;
            else if(res==1)
                cout<<"\nValid phone number"<<endl;
            else
                cout<<"\nALERT: Invalid phone number!!"<<endl;
            break;
        }
        case 5: {

            string name_per,det;
            cout<<"Enter the name of person whose detail has to be updated and the detail that has to be updated: ";
            cin>>name_per>>det;
            update_entry(head,name_per,det);
            break;
        }
        }

        cout<<"\n\nPress 1 to continue: ";
        cin>>k;
        if(k!=1)
            cout<<"\nEXIT"<<endl;

    }
    return 0;
}