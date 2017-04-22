#include<stdio.h>
#include<mysql.h>
#include<stdlib.h>
#include<string.h>


  char query[100];
  char q2[50];
  

  MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "localhost"; // localhost for accessing local mysql
   char *user = "root";// root for students
   char *password = ""; /* set me first - pwd : iiitdm123 */ 
   char *database = ""; // Here you need to enter the database name if you have already other wise leave it free.

  
  
  
void CompanyDatabase()
{
   system("clear");
   int op=1,op1,flag;
   
   
   
   printf("\n\n\n\n Company Schema");
   
    mysql_query(conn,"use Company;"); // change database
 
      strcpy(query,"");
      strcpy(q2,"");
      flag=0;
      printf("\n\n 1)Enter command\n 3)Exit\nEnter option no :");
      scanf("%d",&op);
      if(op==3)
        return;
      printf("\nEnter Query  (give ; after space) : ");
       scanf("%s",q2);
                    while(strcmp(q2,";")!=0)
                    {
                        strcat(query,q2);
                        strcat(query," ");
                        scanf("%s",q2);
                    }
                    
  
   
   strcat(query,";");
   printf("\nCommand Entered:  %s\n",query);
   printf("\n\n\n");
   if (mysql_query(conn,query)) 
   {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);

   unsigned long *lengths;
   unsigned int num_fields;


         while ((row = mysql_fetch_row(res)) != NULL)
          {
            num_fields = mysql_num_fields(res);
            lengths = mysql_fetch_lengths(res);
            for(int i = 0; i < num_fields; i++)
            {
               //printf("%d  ",(int)lengths[i]);
               //printf("%s\t",row[i]);
               printf("%18.*s ", (int) lengths[i],row[i] ? row[i] : "NULL");
               // printf("Column %u is %lu bytes in length.\n",i, lengths[i]);
               	//printf("%s \n", row[i]);
            }
            printf("\n");
         }
   
 

   
   

   mysql_free_result(res);

   

}  
  
  
  
  

void SPPDatabase()
{


   int op=1,op1,flag;
   
  printf("\n\n\n\n Spp Schema");
   
   mysql_query(conn,"use SPP;");  //change database here
   

      strcpy(query,"");
      strcpy(q2,"");
      flag=0;
      printf("\n\n 1)Enter command \n 3)Exit\nEnter option no :");
      scanf("%d",&op);
      if(op==3)
        return;
      printf("\nEnter Query (give ; after a space): ");
       scanf("%s",q2);
                    while(strcmp(q2,";")!=0)
                    {
                        if(strcmp(q2,"select")==0)
                           flag=1;
                        strcat(query,q2);
                        strcat(query," ");
                        scanf("%s",q2);
                    }
                    
  
   
   strcat(query,";");
   printf("\nCommand Entered:  %s\n",query);
   printf("\n\n\n");
   if (mysql_query(conn,query)) 
   {
      fprintf(stderr, "%s\n", mysql_error(conn));
      return;
   }
   res = mysql_use_result(conn);

   unsigned long *lengths;
   unsigned int num_fields;



         while ((row = mysql_fetch_row(res)) != NULL)
          {
            num_fields = mysql_num_fields(res);
            lengths = mysql_fetch_lengths(res);
            for(int i = 0; i < num_fields; i++)
            {
               //printf("%d  ",(int)lengths[i]);
               //printf("%s\t",row[i]);
               printf("%18.*s ", (int) lengths[i],row[i] ? row[i] : "NULL");
               // printf("Column %u is %lu bytes in length.\n",i, lengths[i]);
               	//printf("%s \n", row[i]);
            }
            printf("\n");
         }
 
 

   
   

   mysql_free_result(res);

}




int main()
{
 
   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   
   
 
CompanyDatabase();
SPPDatabase();

  mysql_close(conn);
return 0;
}
