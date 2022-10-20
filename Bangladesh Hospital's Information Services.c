#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int serial = 0;
int token = 100;
int ex = 0;
void search(int x);
void create();
void display();

struct node
{
    char doctor_name[40];
    char disease_name[40];
    char degree_name[40];
    char time[40];
    char fees[20];
    int id;
    struct node *next;
}*head = NULL;

void menu()
{
    int a,b,n,i;

    while(1){
        if(ex == 1){
            break;
        }
        else{
        printf("\nList of Hospitals:\n1.Square Hospital\n2.Lab aid Hospital\n3.Ibn Sina Hospital\n4.Birdem Hospital\n5.Popular Hospital\n\n");
        printf("Chose one by using serial no: ");
        scanf("%d", &n);
        manage();
        }

    }
}
void manage()
{
    FILE *fp;
    struct node *current;
    int a,b,n,i,j,k;
    char name[100],blood[10], ch, location[100], ph[100];

    while(1)
    {
       a = 0;
        printf("\nHow can we help you ??\n");
        printf("1 for Doctor serial\n2 for Ambulance service\n3 for Emergency contact\n4 for Blood Bank\n5 for return main menu\n6 for exit\n");
        scanf("%d", &n);

        if(n==1){
            printf("\nOur Doctors :\n\n");
            display();
            printf("Enter Doctor Id for Serial : ");
            scanf("%d", &a);
            search(a);
        }
        else if(n==2){
           printf("Enter you location : ");
           getchar();
           gets(name);
           printf("We sent Ambulance at %s location. Here is our driver no : 01726-987565\n\n\n", name);
        }
        else if(n==3){
            printf("Please call us as soon as possible\nMobile: 01725-659874\n\n");
        }
        else if(n==4){
            char filename[] = "Document.txt";
            fp = fopen(filename, "w");
            fprintf(fp, "Blood Group : \nA+ --> 10 Bags\nA-  -->  5 Bags\nB+ --> 10 Bags\nB- --> 5 Bags\nAB+  --> 7 Bags\nAB- --> 5 Bags\nO+ --> 10 Bags\nO- --> 15 Bags\n");
            fclose(fp);

            fp = fopen(filename, "r");
            printf("Our Stock : \n");
            while(1){
                ch = fgetc(fp);
                if(ch == EOF){
                    break;
                }

                putchar(ch);
            }
            fclose(fp);


            while(1){
            printf("Which Blood group do you need : ");
            scanf(" %[^\n]", blood);
            if(strcmp(blood, "A+")==0 || strcmp(blood, "A-")==0 || strcmp(blood, "AB+")==0 || strcmp(blood, "AB-")==0 || strcmp(blood, "B+") ==0 || strcmp(blood, "B-") == 0 || strcmp(blood, "O+") == 0 || strcmp(blood, "O-")==0  )
            {
                printf("%s is Available\n", blood);
                break;
            }
            else{
                printf("Oops you enter a wrong blood group\n");
                continue;
             }
            }

            printf("Enter the amount of bag , Location and your Phone number:\n");
            printf("Number of bag : ");
            scanf("%d", &b);
            printf("Location : ");
            getchar();
            gets(location);
            printf("Phone number : ");
            gets(ph);
            printf("\nWe sent your blood to your location : %s\nThanks for staying with us\n\n\n", location);


        }
        else if(n==5){
           return;
        }
        else if(n==6){
            ex = 1;
            break;
        }
    }
}

void search(int x)
{
    struct node *current;
    int t,ch,n,i,j,k;
    int a = 0;
     current = head;
    while(current != NULL){

        if(current->id == x){
            a++;
            serial++;
            token++;
             printf("Choose method : \n1. Bikash\n2. Datch Bangla\n3. Nogod\n");
             scanf("%d", &n);

             if(n==1){
                printf("Give amount through Bikash : ");
                scanf("%d", &i);
             }
             else if(n==2){
                printf("Give amount through Datch Bangla : ");
                scanf("%d", &j);
             }
             else if(n==3){
                printf("Give amount through Nogod : ");
                scanf("%d", &k);
             }

             printf("Your Serial booked successfully\nYour serial no is : %d\nYour Token No is : %d\n", serial, token);
             printf("Please Contact us for more information\nMobile : 01856-789465\n\n");
                }
            current = current->next;
    }
    if(a==0){
        printf("Oops, You enter a wrong id, Please try again with valid id\n\n");
        printf("Enter Doctor id for serial : ");
        scanf("%d", &ch);
        search(ch);
    }
}
void create()
{
    struct node *new_node, *current, *temp;
    int n,a,b;

    new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->doctor_name, "Dr.Mahfuzur Rahman");
    strcpy(new_node->disease_name, "Eye Specialist");
    strcpy(new_node->degree_name, "MBBS , Dhaka Medical College");
    strcpy(new_node->time, "Sat - Thu(8am - 10pm)");
    strcpy(new_node->fees, "500 tk");
    new_node->id = 110;


    head = new_node;
    current = new_node;

    new_node = (struct node*)malloc(sizeof(struct node));

    strcpy(new_node->doctor_name, "Dr. Mredul Hasan");
    strcpy(new_node->disease_name, "Cardiac Specialist");
    strcpy(new_node->degree_name, "MBBS , Dhaka Medical College");
    strcpy(new_node->time, "Sat - Mon(8am - 7pm)");
    strcpy(new_node->fees, "700 tk");
    new_node->id = 151;

    current->next = new_node;
    current = new_node;
    new_node->next = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));

    strcpy(new_node->doctor_name, "Dr. Asif Farhan");
    strcpy(new_node->disease_name, "Medicine");
    strcpy(new_node->degree_name, "MBBS, Dhaka Medical College");
    strcpy(new_node->time, "Sun - Thu(10am-5pm)");
    strcpy(new_node->fees, "700 tk");
    new_node->id = 211;

    current->next = new_node;
    new_node->next = NULL;
    current = new_node;

    new_node = (struct node*)malloc(sizeof(struct node));

    strcpy(new_node->doctor_name, "Dr. Niloy Kumar Sarkar");
    strcpy(new_node->disease_name, "Gastrology specialist");
    strcpy(new_node->degree_name, "MBBS, Dhaka Medical College");
    strcpy(new_node->time, "Sun-Thu(8am-7pm)");
    strcpy(new_node->fees, "500 tk");
    new_node->id = 251;

    current->next = new_node;
    new_node->next = NULL;
    current = new_node;


}

void display()
{
    struct node *current;

    current = head;

    while(current != NULL){
        printf("%s\n%s\n%s\n%s\nId = %d\nFees : %s\n",current->doctor_name, current->disease_name, current->degree_name, current->time, current->id, current->fees);

        printf("\n\n");
        current = current->next;
    }
}

int main()
{
    printf("\n    ----------------------->>>> Welcome to Bangladesh Hospital's Information Services <<<<------------------------\n");
    printf("                                           Powered by Code Breakers     \n\n");
    create();
    menu();
}
