// Password for admin is abc

#include<stdio.h>
#include<mysql.h>
#include<stdlib.h>
#include<string.h>


  char query[100];
  char q2[50];
  

   MYSQL *conn,*conn1;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "localhost"; // localhost for accessing local mysql
   char *user = "root";// root for students
   char *password = "ocean"; /* set me first - pwd : iiitdm123 */ 
   char *database = ""; // Here you need to enter the database name if you have already other wise leave it free.




void Job()
{
    conn = mysql_init(NULL);
    system ("clear");
    char val;
    char jid[3];
    
    
    if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    
    mysql_query(conn,"use Admin;");
  
    if (mysql_query(conn,"select CID,JobId from Offers where Verified='P'")) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      return;
    }
    
   res = mysql_use_result(conn);

   printf("%44.*s",50,"\n\n               CID                 JobID\n");
   unsigned long *lengths;
   unsigned int num_fields;

         while ((row = mysql_fetch_row(res)) != NULL)
          {
            num_fields = mysql_num_fields(res);
            lengths = mysql_fetch_lengths(res);
            for(int i = 0; i < num_fields; i++)
                printf("%18.*s ", (int) lengths[i],row[i] ? row[i] : "NULL");
              
        
            printf("\n");
         }
 
 
   mysql_free_result(res);
   printf("\n\nValidate JobIDs?(y/n) : ");
   scanf(" %c",&val);
   
   
   while(val=='y' || val=='Y')
   {
        printf("\n\n  Enter JobId: ");
        scanf("%s",jid);
        strcat(query,"UPDATE Offers SET Verified='Y' where JobId=");
        strcat(query,jid);
        strcat(query," ;");
        
        if (mysql_query(conn,query)) 
        {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return;
        }
        
        printf("Validate JobIDs?(y/n) : ");
        scanf(" %c",&val);
   
   }
   

  
    mysql_close(conn);

}




void Companies()
{

    conn = mysql_init(NULL);
    system ("clear");
    char val;
    char jid[3];
    
    
    if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    
    mysql_query(conn,"use Admin;");
  
    if (mysql_query(conn,"select Username from CompanyUsers ")) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      return;
    }
    
   res = mysql_use_result(conn);

   printf("%44.*s",50,"\n\n               CID\n");
   unsigned long *lengths;
   unsigned int num_fields;

         while ((row = mysql_fetch_row(res)) != NULL)
          {
            num_fields = mysql_num_fields(res);
            lengths = mysql_fetch_lengths(res);
            for(int i = 0; i < num_fields; i++)
                printf("%18.*s ", (int) lengths[i],row[i] ? row[i] : "NULL");
              
        
            printf("\n");
         }
 
 
   mysql_free_result(res);
   
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n Press any key to go back ");
   scanf(" %c",&query[0]);
   

}



void AdminSchema()
{
    int op;
    
   
    while (1)
    {
        system("clear");
        printf("\n\n \t\t\t\t\tADMIN MENU\n\n");
        printf("__________________________________________________________________________________________________________________________________________________________________");
        
        printf("\n\n\n\n\n\t 1)Check for new Job Requests\n\t 2)Display Companies\n\t 3)Exit\n\tEnter your choice:  ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: Job();break;
            case 2: Companies();break;
            case 3:return;
        }
    } 
}




 
 void AdminLogin(int n)
 {
    char pass[10];
    system ("clear");
     printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  -----------------------------");
     printf("                  \n\t\t\t\t\t\t\t\t  |                           |");
     printf("                  \n\t\t\t\t\t\t\t\t  |         Admin Mode        |");
     printf("                  \n\t\t\t\t\t\t\t\t  |                           |");
     printf("                  \n\t\t\t\t\t\t\t\t  -----------------------------");
     
     if(n)
        printf("\n\n\t\t\t\t\t\t\t\t   Invalid Password!!!! Enter again!\n");
     printf("\n\n\t\t\t\t\t\t\t\t   Enter Password: ");
     
     scanf("%s",pass);
     if(strcmp(pass,"abc")==0)
        AdminSchema();
     else
        {
         AdminLogin(1);        
        }
 
 }
 

  
   


int main()
{
    AdminLogin(0);

 
    //CompanyDatabase();
    //SPPDatabase();


return 0;
}
