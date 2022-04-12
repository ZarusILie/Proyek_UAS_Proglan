/* Project Akhir Proglan-02
	Attendance List Management System
	Nama : Brian Samuel Matthew (1906381640) & Lazaruslie Karsono (1906300782)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

int jumlah;
int hadir=0;

// linked lis, pointer, stack and queue//
/* fungsi untuk menyimpan data nama, no.absen dan NPM 
	yang nantinya data tersebut disorting
	berdasarkan nama, no. absen dan NPM*/
struct node{
	char nama[100];
	int absen;
	int NPM;
	struct node *next;
	struct node *prev;
}*head,*tail,*curr;

/* fungsi untuk mendisplay 
	tampilan judul saat memasuki program utama*/
void display() {
	printf ("|========================================|\n");
	printf ("|             Attendance List 		 |\n");
	printf ("|            Management System           |\n");
	printf ("|        			         |\n");
	printf ("|========================================|\n");
	sleep(3);
	
}

/* fungsi untuk mereset data 
	yang sebelumnya sudah diisi*/
void bebas() {
	int n=1;
	hadir=0;
	head = (struct node*)malloc(n * sizeof(struct node));
	tail = (struct node*)malloc(n * sizeof(struct node));
	curr = (struct node*)malloc(n * sizeof(struct node));
	
	free(head);
	free(tail);
	free(curr);
}

/* fungsi untuk mengeprint hasil program
	berdasarkan hasil sorting nama atau no. absen atau NPM */
void cetak(){
	curr=head;
	while(curr!=NULL)
	{	
		printf("|====================================================|\n");
		printf("|Nama\t\tNo.Absen\t\tNPM\t\n");
		printf("|%s\t\t",curr->nama);
		printf("%d\t\t",curr->absen);
		printf("%d\t\t",curr->NPM);
		curr=curr->next;
		printf("\n");
	}
	if (curr==tail) return;
	 getch();
}

/* fung hasil print agar dapat disimpan dalam 
	bentuk file .txt*/
void cetakfile() {
	FILE * fp;
   
    fp = fopen ("data.txt","w");
	curr=head;
	while(curr!=NULL)
	{	
		
		fprintf(fp,"|====================================================|\n");
		fprintf(fp,"|Nama\t\tNo.Absen\t\tNPM\t\n");
		fprintf(fp,"|%s\t\t",curr->nama);
		fprintf(fp,"%d\t\t",curr->absen);
		fprintf(fp,"%d\t\t",curr->NPM);
		curr=curr->next;
		fprintf(fp,"\n");
	}

	printf("\n"); getchar();
	fclose (fp);
}

//sorting & searching, dynamic memory allocation//
/* fungsi untuk mensorting data ke depan */
void pushdpn(char tnama[100],int tabsen,int tNPM)
{
	curr= (struct node*)malloc(sizeof(struct node));
	strcpy(curr->nama,tnama);
	curr->absen = tabsen;
	curr->NPM = tNPM;
	if(head==NULL)
	{
		head=tail=curr;
	}
	else{
		curr->next=head;
		head->prev=curr;
		head=curr;
	}
	tail->next=NULL;
	head->prev=NULL;
}

//sorting & searching, dynamic memory allocation//
/* fungsi untuk mensorting data ke belakang */
void pushblk(char tnama[],int tabsen,int tNPM)
{
	curr= (struct node*)malloc(sizeof(struct node));
	strcpy(curr->nama,tnama);
	curr->absen = tabsen;
	curr->NPM = tNPM;
	if(head==NULL)
	{
		head=tail=curr;
	}
	else{
		tail->next=curr;
		curr->prev=tail;
		tail=curr;
	}
	head->prev=NULL;
	tail->next=NULL;
}

//sorting & searching, dynamic memory allocation, stack and queue//
/* fungsi untuk mengisi data nama, no.absen, NPM */
/* fungsi push berfungsi untuk menambahkan data ke dalam stack
	Jika stack sudah penuh maka data tersebut akan dieksekusi*/
void push(){
	char tnama[100];
	int tabsen,tNPM;
	
	system("cls");
	printf ("Nama      : \t"); scanf ("%s", &tnama);
	printf ("No. Absen : \t"); scanf ("%d", &tabsen);
	printf ("NPM       : \t"); scanf ("%d", &tNPM);
	
	if(head==NULL)pushdpn(tnama,tabsen,tNPM);
	else if(strcmp(tnama,head->nama)<=0) pushdpn(tnama,tabsen,tNPM);
	else if(strcmp(tnama,head->nama)>0) pushblk(tnama,tabsen,tNPM);
	
	else{
		curr= (struct node*)malloc(sizeof(struct node));
		strcpy(curr->nama,tnama);
		curr->absen = tabsen;
		curr->NPM = tNPM;
		
		struct node *temp,*temp2;
		temp=head;
		while(strcmp(temp->next->nama,tnama)<0)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=curr;
		curr->next=temp2;
		
		temp2->prev=curr;
		curr->prev=temp;
	}
	
}

//sorting & searching, struct, pointer//
/* fungsi untuk mensorting data no.absen*/ 
void sortabsen(struct node *head){
	int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 

    if (head == NULL) return;
    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->absen > ptr1->next->absen)
            {
            	char tnama[100];
            	int tabsen,tNPM;
            	
            	tabsen=ptr1->next->absen;
                strcpy(tnama,ptr1->next->nama);
                tNPM=ptr1->next->NPM;
            	ptr1->next->absen=ptr1->absen;
                strcpy(ptr1->next->nama,ptr1->nama);
                ptr1->next->NPM=ptr1->NPM;
                
                ptr1->absen=tabsen;
                strcpy(ptr1->nama,tnama);
                ptr1->NPM=tNPM;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    
}

//sorting & searching, struct, pointer//
/* fungsi untuk mensorting data NPM */
void sortnpm(struct node *head){
	int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 

    if (head == NULL) return;
    do
    {
    	swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->NPM > ptr1->next->NPM)
            {
            	char tnama[100];
            	int tabsen,tNPM;
            	
            	tabsen=ptr1->next->absen;
                strcpy(tnama,ptr1->next->nama);
                tNPM=ptr1->next->NPM;
            	ptr1->next->absen=ptr1->absen;
                strcpy(ptr1->next->nama,ptr1->nama);
                ptr1->next->NPM=ptr1->NPM;
                
                ptr1->absen=tabsen;
                strcpy(ptr1->nama,tnama);
                ptr1->NPM=tNPM;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    
}

/* fungsi untuk menampilkan fitur help 
	atau deskripsi program */
void help() {
	printf ("\nHelp\n");
	sleep(1);
	printf( "==================================================\n");
	sleep(2);
	printf ("Attendance List Management System merupakan\n");
	sleep(2);
	printf ("sebuah program untuk membuat daftar absensi mahasiswa\n");
	sleep(2);
	printf ("yang hadir pada suatu kelas\n");
	sleep(2);
	printf ("dalam kurun waktu satu hari.\n");
	sleep(2);
	printf ("Program ini memiliki fitur seperti : \n");
	sleep (2);
	printf ("mesorting berdasarkan\n");
	sleep(2);
	printf ("nama,");
	sleep(1);
	printf ("no absen,");
	sleep (1);
	printf ("dan NPM.\n");
	sleep (1);
	printf ("Program ini juga dilengkapi fitur untuk\n");
	sleep (2);
	printf ("menghitung jumlah mahasiswa yang hadir\n");
	sleep (2);
	printf ("dan yang tidak hadir.\n");
	sleep(1);
	printf( "==================================================\n");
	sleep(1);
	printf("Tekan apa saja untuk kembali ke Menu\n");
	getch();
	system("cls");
}

/* main program */
int main(){
	int opsi;
	display();
	do{
		system ("cls");
		printf ("==================================================\n");
		printf ("Attendance List Management System\n");
		printf (" ______\n");
		printf ("|______|\n");
		printf ("|_|__|_|\n");
		printf ("|      |\n");
		printf ("|______|\n");
		printf ("Menu : \n");
		printf ("1. Program utama\n");
		printf ("2. Help\n");
		printf ("3. Exit\n");
		printf ("Input : "); scanf ("%d", &opsi);
	
		switch (opsi) {
			case 1 :
				system ("cls");
				bebas();
				system ("cls");
				printf ("Jumlah Mahasiswa : "); scanf ("%d", &jumlah);
				sleep(1);

				int i,s;
				
				for(i=0;i<jumlah;i++){
					hadir++;
					push();
					printf ("1.Lanjut Mengisi\n");
					printf ("2.Berhenti Mengisi\n");
					printf ("Input : ");
					scanf ("%d", &s);
					
					if(s==2)break;
				}
				int x;
				do{
					system ("cls");
					printf ("1. Sort berdasarkan Nama\n");
					printf ("2. Sort berdasarkan No. Absen\n");
					printf ("3. Sort berdasarkan NPM\n");
					printf ("4. Jumlah mahasiswa yang hadir\n");
					printf ("5. Exit\n");
					printf ("Input : ");
					scanf ("%d", &x);
					switch (x) {
						case 1 :
							cetak();
							cetakfile();
							break;
						case 2 :
							sortabsen(head);
							cetak();
							cetakfile();
							break;
						case 3 :
							sortnpm(head);
							cetak();
							cetakfile();
							break;
						case 4 :
							printf("Jumlah mahasiswa yang hadir: %d / %d\n",hadir,jumlah);
							getch();
							break;
						
					}
							
				}while(x!=5);
				getchar();
				break;
				
				case 2 :
				system ("cls");
				display();
				help();
				break;
		}
			
				
	}while(opsi!=3);
	system ("cls");
	printf ("Terima Kasih");
	return 0;
}
