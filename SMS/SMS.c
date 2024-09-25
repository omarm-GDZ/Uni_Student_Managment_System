#include<stdio.h>
#include<stdlib.h>
struct student{
	int ID;
	char name[50];
	int age;
	float gpa;
};
struct node{
	struct student data;
	struct node* next;
};
struct node* head=NULL;
void addStudent(const struct student* const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id) ;
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id) ;

int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int id;
	char x;
	float AvgGPA;
	do{
		printf("************************************************************************************\n");
		printf("Choose Action\n");
		printf("1.Add a Student\n");
		printf("2.Display Students\n");
		printf("3.Search for a Student by ID\n");
		printf("4.Update a Student's data\n");
		printf("5.Delete a Student\n");
		printf("6.Calculate Average GPA\n");
		printf("7.Search for the  Highest GPA\n");
		printf("8.Exit\n");
		printf("\nInsert no from 1-8 :\n");
		fflush(stdin);
		scanf("%c",&x);
		switch(x)
		{
		case '1':
			printf("************************************************************************************\n");
			struct student s;
			printf("Enter Student's ID:");
			scanf("%d",&s.ID);
			fflush(stdin);
			printf("Enter Student's Name:");
			gets(s.name);
			printf("Enter Student's age:");
			scanf("%d",&s.age);
			printf("Enter Student's GPA:");
			scanf("%f",&s.gpa);
			addStudent(&s);
			break;
		case '2':
			printf("************************************************************************************\n");
			displayStudents();
			break;
		case '3':
			printf("************************************************************************************\n");
			printf("Enter student's ID:");
			scanf("%d",&id);
			searchStudentByID(id);
			break;
		case '4':
			printf("************************************************************************************\n");
			printf("Enter student's ID:");
			scanf("%d",&id);
			updateStudent(id);
			break;
		case '5':
			printf("************************************************************************************\n");
			printf("Enter Student's ID:");
			scanf("%d",&id);
			deleteStudent(id);
			break;
		case '6':
			printf("************************************************************************************\n");
			AvgGPA=calculateAverageGPA();
			if(AvgGPA==0)
				printf("No data yet\n");
			else
				printf("Average GPA of the students= %f\n",AvgGPA);
			break;
		case '7':
			printf("************************************************************************************\n");
			searchHighestGPA();
			break;
		case '8':
			printf("************************************************************************************\n");
			printf("Exiting....\n");
			break;
		default:
			printf("************************************************************************************\n");
			printf("Must insert a number be between 1-8\n");
		}
	}while(x!='8');
	return 0;
}
void addStudent(const struct student* const ptr){
	struct node*current=NULL;
	current=head;
	while(current!=NULL){
		if(current->data.ID==ptr->ID){
			printf("************************************************************************************\n");
			printf("This ID is reserved already!\nTry again.\n");
			return;
		}
		current=current->next;

	}
	struct node*link=(struct node*)malloc(sizeof(struct node));
	if(link==NULL)
	{
		printf("Allocation Failed");
		return;
	}
	link->data=*ptr;
	link->next=NULL;
	if(head==NULL)
	{
		head=link;
		return;
	}
	current=head;
	while(current->next !=NULL)
	{
		current=current->next;
	}
	current->next=link;
}
void displayStudents(void){
	struct node*current=NULL;
	if (head==NULL)
	{
		printf("No data yet\n");
		return;
	}
	current=head;
	while(current!=NULL)
	{
		printf("[ ");
		printf("ID: %d, ",current->data.ID);
		printf("Name: %s, ",current->data.name);
		printf("Age: %d, ",current->data.age);
		printf("GPA: %.2f ",current->data.gpa);
		printf("]\n");
		current=current->next;;
	}
}
void searchStudentByID(int id){
	struct node*current=NULL;
	if (head==NULL)
	{
		printf("No data yet\n");
		return;
	}
	current=head;
	while(current!=NULL)
	{
		if(current->data.ID==id)
		{
			printf("Student found:\n");
			printf("[ ");
			printf("ID: %d, ",current->data.ID);
			printf("Name: %s, ",current->data.name);
			printf("Age: %d, ",current->data.age);
			printf("GPA: %.2f ",current->data.gpa);
			printf("]\n");
			return;
		}
		current=current->next;
	}
	printf("Student not found!\n");
}
void updateStudent(int id){
	struct node*current=NULL;
	if (head==NULL)
	{
		printf("No data yet\n");
		return;
	}
	current=head;
	while(current!=NULL)
	{
		if(current->data.ID==id)
		{
			printf("Student found\n");
			fflush(stdin);
			printf("Update Student's Name: ");
			gets(current->data.name);
			printf("Update Student's Age: ");
			scanf("%d",&current->data.age);
			printf("Update Student's GPA: ");
			scanf("%f",&current->data.gpa);
			printf("Updated successfully\n");
			return;
		}
		current=current->next;
	}
	printf("Student not found!\n");
}
float calculateAverageGPA(void){
	struct node*current=NULL;
	float sum=0;
	int num=0;
	if(head==NULL)
		return 0;
	current=head;
	while (current!=NULL){
		sum+=current->data.gpa;
		num++;
		current=current->next;
	}
	return sum/num;
}
void searchHighestGPA(void){
	struct node* current=NULL;
	float max;
	if(head==NULL)
	{
		printf("No data yet\n");
		return;
	}
	max=head->data.gpa;
	current = head;
	while(current!=NULL)
	{
		if(current->data.gpa>max){
			max=current->data.gpa ;
		}
		current=current->next;
	}
	current=head;
	while(current!=NULL)
	{
		if(current->data.gpa==max)
		{
			printf("Student with the Highest GPA\n");
			printf("[ ");
			printf("ID: %d, ",current->data.ID);
			printf("Name: %s, ",current->data.name);
			printf("Age: %d, ",current->data.age);
			printf("GPA: %.2f ",current->data.gpa);
			printf("]\n");
			return;
		}
		current=current->next;
	}
}
void deleteStudent(int id){
	struct node* current=NULL;
	struct node* prev=NULL;
	struct node* delete_PTR=NULL;
	if(head==NULL)
	{
		printf("No data yet\n");
		return;
	}
	if(head->data.ID==id)
	{
		delete_PTR=head;
		head=head->next;
		free(delete_PTR);
		printf("Successful Operation\n");
		return;
	}
	prev=head;
	current=head->next;
	while(current!=NULL)
	{
		if(current->data.ID==id)
		{
			delete_PTR=current;
			prev->next=current->next;
			free(delete_PTR);
			printf("Successful Operation\n");
			return;
		}
		prev=current;
		current=current->next;
	}
	printf("Student not found!\n");
}
