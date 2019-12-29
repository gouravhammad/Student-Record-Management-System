#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Student
{
     int  rollNo;
     char studentName[30];
     char fatherName[30];
     char motherName[30];
     char email[40];
     char gender[10];
     char dateOfBirth[15];
     char mobileNo[15];
     char address[50];
     char activeStatus[3];
     struct Student* next;
};

void string_copy(char* outputstring, char* inputstring, int sizeofstring)
{
    int charcount = 0;

    for( ; *inputstring != '\0'; inputstring++,outputstring++)
    {
        *outputstring = *inputstring;
        charcount++;
    }

    for(int i=0; i<sizeofstring-charcount-1; i++)
    {
        *outputstring = ' ';
        outputstring++;
    }

    *outputstring = '\0';
}

void inputDetails(struct Student* temp, int rollNumber, FILE* writeptr)
{
    char student_Name[30];
    char father_Name[30];
    char mother_Name[30];
    char email_Id[40];
    char gender_input[10];
    char date_Of_Birth[15];
    char mobile_No[15];
    char address_input[50];
    char  x = 205, x1 = 186, x2 = 187, x3 = 188, x4 = 200, x5 = 201;

    temp->rollNo = rollNumber;
    string_copy(temp->activeStatus,"Yes",3);

    cout << "\n\n\t" << x5 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x2 << endl;
    cout << "\t" << x1 << " ROLL NUMBER            : " << temp->rollNo << "  " << x1 << endl;
    cout << "\t" << x4 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x3 << endl;

    cout << "\n\tEnter Student Name       : ";
    gets(student_Name);
    string_copy(temp->studentName,student_Name,30);

    cout << "\tEnter your Father Name   : ";
    gets(father_Name);
    string_copy(temp->fatherName,father_Name,30);

    cout << "\tEnter your Mother Name   : ";
    gets(mother_Name);
    string_copy(temp->motherName,mother_Name,30);

    cout << "\tEnter your Email ID      : ";
    gets(email_Id);
    string_copy(temp->email,email_Id,40);

    cout << "\tEnter your Gender(F/M/O) : ";
    gets(gender_input);
    string_copy(temp->gender,gender_input,10);

    cout << "\tEnter D.O.B (DD/MM/YY)   : ";
    gets(date_Of_Birth);
    string_copy(temp->dateOfBirth,date_Of_Birth,15);

    cout << "\tEnter your Mobile Number : ";
    gets(mobile_No);
    string_copy(temp->mobileNo,mobile_No,15);

    cout << "\tEnter your Address       : ";
    gets(address_input);
    string_copy(temp->address,address_input,50);

    cout << "\n\tRecord added Successfully! " << endl;

    fprintf(writeptr,"\n%d,%s,%s,%s,%s,%s,%s,%s,%s,%s",temp->rollNo,temp->studentName,temp->fatherName,temp->motherName,temp->email,temp->gender,temp->dateOfBirth,temp->mobileNo,temp->address,temp->activeStatus);
}

struct Student* add_Initial_Student_Record(struct Student* start, int rollNumber, FILE* writeptr)
{
    if(NULL != start)
    {
        cout << "\n\tCritical Error! Improper Memory Allocation! " << endl;

        return start;
    }

    struct Student* temp = NULL;
    temp = new struct Student;

    inputDetails(temp,rollNumber,writeptr);

    temp->next = NULL;
    start = temp;

    return start;
};

struct Student* add_Student_Record(struct Student* start, int rollNumber, FILE* writeptr)
{
    if(NULL == start)
    {
        cout << "\n\tCritical Error! Improper Memory Allocation! " << endl;

        return start;
    }

    struct Student* temp = NULL;
    temp = new struct Student;
    struct Student* basepointer = start;

    while(NULL != basepointer->next)
    {
        basepointer = basepointer->next;
    }

    basepointer->next = temp;

    inputDetails(temp,rollNumber,writeptr);

    temp->next = NULL;

    return start;
};

 void display_Single_Record(struct Student* basepointer)
 {
     if(NULL == basepointer)
     {
         cout << "\n\tNo Records to Display! " << endl;

         return ;
     }

     cout << "\n\tROLL NUMBER   : " << basepointer->rollNo << endl;
     cout << "\tStudent Name  : " << basepointer->studentName << endl;
     cout << "\tFather Name   : " << basepointer->fatherName << endl;
     cout << "\tMother Name   : " << basepointer->motherName << endl;
     cout << "\tEmail ID      : " << basepointer->email << endl;
     cout << "\tGender        : " << basepointer->gender << endl;
     cout << "\tDate of Birth : " << basepointer->dateOfBirth << endl;
     cout << "\tMobile Number : " << basepointer->mobileNo << endl;
     cout << "\tAddress       : " << basepointer->address << endl;
 }

struct Student* displayAllRecords(struct Student* start)
{
    if(NULL == start)
    {
        cout << "\n\tNo Records to Display! " << endl;

        return start;
    }

    struct Student* basepointer = start;

    while(NULL != basepointer->next)
    {
        display_Single_Record(basepointer);

        basepointer = basepointer->next;
    }

    display_Single_Record(basepointer);

    return start;
};

struct Student* search_Student_Record(struct Student* start, int rollNumber)
{
    int check = 0;
    struct Student* basepointer = start;

    if(NULL == start)
    {
        cout << "\n\tNo Record Found! " << endl;

        return start;
    }

    while(NULL != basepointer->next)
    {
        if(basepointer->rollNo == rollNumber)
        {
            display_Single_Record(basepointer);
            check = 1;
        }

        basepointer = basepointer->next;
    }

    if(basepointer->rollNo == rollNumber)
    {
        display_Single_Record(basepointer);
        check = 1;
    }

    if(0 == check)
    {
        cout << "\n\tNo Record Found! " << endl;
    }

    return start;
}

struct Student* delete_Student_Record(struct Student* start, int rollNumber)
{
    int check = 0;
    struct Student* basepointer = start;
    struct Student* temp = NULL;

    if(NULL == start)
    {
        cout << "\n\tNo Record Found!" << endl;

        return start;
    }

    if((NULL == basepointer->next) && (basepointer->rollNo == rollNumber))
    {
        temp = basepointer;
        string_copy(temp->activeStatus,"No",3);
        delete temp;
        start = NULL;

        cout << "\n\tRecord Deleted! " << endl;
        return start;
    }

    while(NULL != basepointer->next)
    {
        if(basepointer->rollNo == rollNumber)
        {
            temp = basepointer;
            start = start->next;
            string_copy(temp->activeStatus,"No",3);
            delete temp;
            check = 1;

            cout << "\n\tRecord Deleted! " << endl;
            break;
        }

        if(basepointer->next->rollNo == rollNumber)
        {
            temp = basepointer->next;
            basepointer->next = temp->next;
            string_copy(temp->activeStatus,"No",3);
            delete temp;
            check = 1;

            cout << "\n\tRecord Deleted! " << endl;
            break;
        }

        if((NULL == basepointer->next->next) && (basepointer->next->rollNo == rollNumber))
        {
            temp = basepointer->next;
            basepointer->next = NULL;
            string_copy(temp->activeStatus,"No",3);
            delete temp;
            check = 1;

            cout << "\n\tRecord Deleted! " << endl;
            break;
        }

        basepointer = basepointer->next;
    }

    if(0 == check)
    {
        cout << "\n\tNo Record Found! " << endl;
    }

    return start;
}

struct Student* update_Student_Record(struct Student* start, int rollNumber)
{
    char choice[20];
    int  check = 0;
    char updated_s_Name[30];
    char updated_f_Name[30];
    char updated_m_Name[30];
    char updated_email_Id[40];
    char updated_mobile_No[15];
    char updated_address_input[50];

    struct Student* basepointer = start;
    struct Student* temp = NULL;

    if(NULL == start)
    {
        cout << "\n\tNo Record Found! Therefore Update Operation can't be Performed " << endl;

        return start;
    }

    while(NULL != basepointer->next)
    {
        if(basepointer->rollNo == rollNumber)
        {
            check = 1;
            temp = basepointer;
        }

        basepointer = basepointer->next;
    }

    if(basepointer->rollNo == rollNumber)
    {
        check = 1;
        temp = basepointer;
    }

    if(0 == check)
    {
        cout << "\n\tNo Record Found! Therefore Update Operation can't be Performed " << endl;
    }

    if(1 == check)
    {
        cout << "\n\tWhat you want to Update ? " << endl;
        cout << "\t1. Student Name " << endl;
        cout << "\t2. Father Name " << endl;
        cout << "\t3. Mother Name " << endl;
        cout << "\t4. Email ID " << endl;
        cout << "\t5. Mobile Number " << endl;
        cout << "\t6. Address " << endl;

        cout << "\n\tPlease Enter your Choice (1/2/3/4/5/6) [*NOTE* : First character will be taken as input] : ";
        gets(choice);

        switch(choice[0])
        {
               case '1' :   cout << "\n\tEnter Updated Student's Name : ";
                            gets(updated_s_Name);
                            string_copy(temp->studentName,updated_s_Name,30);

                            cout << "\n\tStudent's Name Updated! \n" << endl;
                            break;

               case '2' :   cout << "\n\tEnter Updated Father's Name : ";
                            gets(updated_f_Name);
                            string_copy(temp->fatherName,updated_f_Name,30);

                            cout << "\n\tFather's Name Updated! \n" << endl;
                            break;

               case '3' :   cout << "\n\tEnter Updated Mother's Name : ";
                            gets(updated_m_Name);
                            string_copy(temp->motherName,updated_m_Name,30);

                            cout << "\n\tMother's Name Updated! \n" << endl;
                            break;

               case '4' :   cout << "\n\tEnter Updated Email Id : ";
                            gets(updated_email_Id);
                            string_copy(temp->email,updated_email_Id,40);

                            cout << "\n\tEmail ID Updated! \n" << endl;
                            break;

               case '5' :   cout << "\n\tEnter Updated Mobile No. : ";
                            gets(updated_mobile_No);
                            string_copy(temp->mobileNo,updated_mobile_No,15);

                            cout << "\n\tMobile No. Updated! \n" << endl;
                            break;

               case '6' :   cout << "\n\tEnter Updated Address : ";
                            gets(updated_address_input);
                            string_copy(temp->address,updated_address_input,50);

                            cout << "\n\tAddress Updated!\n" << endl;
                            break;

               default  :   cout << "\n\tInvalid Input! Again Perform Operation. \n" << endl;
                            break;
        }
    }

    return start;
}

int main()
{
   bool  fileHeader = false;
   bool  answer = true;
   char  yesno[20];
   char  choice[20];
   int   check = 0;
   int   rollNumber = 2;
   int   copyrollNumber = 2;
   char  x = 205, x1 = 186, x2 = 187, x3 = 188, x4 = 200, x5 = 201, x6 = 219, x7 = 185, x8 = 204;

   struct Student* start = NULL;

   FILE* readptr = fopen("G:\Project.txt","r");

   if(NULL == readptr)
   {
       fileHeader = true;
   }

   else
   {
       fileHeader = false;
       fclose(readptr);
   }

   FILE* writeptr = fopen("G:\Project.txt","a+");

   if(true == fileHeader)
   {
       fprintf(writeptr,"Roll Number,Student Name,Father Name,Mother Name,Email ID,Gender,Date Of Birth,Mobile Number,Address,Active Status");
   }

   cout << "\n\t\t\t\t\t" << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << endl;
   cout << "\t\t\t\t\t" << x6 << x6 << x6 << " " << x5 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x2 << " " << x6 << x6 << x6 << endl;
   cout << "\t\t\t\t\t" << x6 << x6 << x6 << " " << x1 << " WELCOME TO HAMMAD COLLEGE " << x1 << " " << x6 << x6 << x6 << endl;
   cout << "\t\t\t\t\t" << x6 << x6 << x6 << " " << x4 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x3 << " " << x6 << x6 << x6 << endl;
   cout << "\t\t\t\t\t" << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << x6 << endl;

   while(answer)
   {
      if(0 == check)
      {
          start = add_Initial_Student_Record(start,1,writeptr);
          check++;

          cout << "\n\tDo you Want to Add More Student (y/Y/n/N) ? [*NOTE* : First character will be taken as input] : ";
          gets(yesno);

          if(yesno[0] == 'n' || yesno[0] == 'N')
          {
              system("CLS");
              cout << "\n\tThanks for your Input, All Records added Successfully!" << endl;
              break;
          }

          else if(yesno[0] == 'y' || yesno[0] == 'Y')
          {
              continue;
          }

          else
          {
              while(answer)
              {
                    cout << "\n\tInvalid Input! Please Choose either y/Y or n/N " << endl;
                    cout << "\n\tDo you Want to Add More Student (y/Y/n/N) ? [*NOTE* : First character will be taken as input] : ";
                    gets(yesno);

                    if(yesno[0] == 'y' || yesno[0] == 'Y' )
                    {
                        break;
                    }

                    else if(yesno[0] == 'n' || yesno[0] == 'N')
                    {
                        system("CLS");
                        cout << "\n\tThanks for your Input, All Records added Successfully!" << endl;
                        answer = false;
                        break;
                    }

                    else
                    {
                        answer = true;
                    }
              }
          }
      }

      if(false == answer)
      {
          break;
      }

      system("CLS");
      start = add_Student_Record(start,rollNumber,writeptr);
      rollNumber++;
      copyrollNumber = rollNumber;

      cout << "\n\tDo you Want to Add More Student (y/Y/n/N) ? [*NOTE* : First character will be taken as input] : ";
      gets(yesno);

      if(yesno[0] == 'n' || yesno[0] == 'N')
      {
          system("CLS");
          cout << "\n\tThanks for your Input, All Records added Successfully!" << endl;
          break;
      }

      else if(yesno[0] == 'y' || yesno[0] == 'Y')
      {
          continue;
      }

      else
      {
          while(answer)
          {
                cout << "\n\tInvalid Input! Please Choose either y/Y or n/N " << endl;
                cout << "\n\tDo you Want to Add More Student (y/Y/n/N) ? [*NOTE* : First character will be taken as input] : ";
                gets(yesno);

                if(yesno[0] == 'y' || yesno[0] == 'Y' )
                {
                    break;
                }

                else if(yesno[0] == 'n' || yesno[0] == 'N')
                {

                    system("CLS");
                    cout << "\n\tThanks for your Input, All Records added Successfully!" << endl;
                    answer = false;
                    break;
                }

                else
                {
                    answer = true;
                }
          }
      }
   }

   answer = true;

   while(answer)
   {
       cout << "\n\t" << x5 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x2 << endl;
       cout << "\t" << x1 << x5 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x2 << x1 << endl;
       cout << "\t" << x1 << x1 << " What Operation Do You Want To Perform " << x1 << x1 <<endl;
       cout << "\t" << x1 << x8 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x7 << x1 << endl;
       cout << "\t" << x1 << x1 << " 1. Search Student Record              " << x1 << x1 << endl;
       cout << "\t" << x1 << x8 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x7 << x1 << endl;
       cout << "\t" << x1 << x1 << " 2. Delete Student Record              " << x1 << x1 << endl;
       cout << "\t" << x1 << x8 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x7<< x1 << endl;
       cout << "\t" << x1 << x1 << " 3. Update Student Record              " << x1 << x1 << endl;
       cout << "\t" << x1 << x8 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x7 << x1 << endl;
       cout << "\t" << x1 << x1 << " 4. Display All Students Record        " << x1 << x1 << endl;
       cout << "\t" << x1 << x8 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x7 << x1 << endl;
       cout << "\t" << x1 << x1 << " 5. Add Student Record                 " << x1 << x1 << endl;
       cout << "\t" << x1 << x8 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x7 << x1 << endl;
       cout << "\t" << x1 << x1 << " 6. No Operation                       " << x1 << x1 << endl;
       cout << "\t" << x1 << x4 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x3 << x1 << endl;
       cout << "\t" << x4 << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x3 << endl;

       cout << "\n\tPlease Enter your Choice (1/2/3/4/5) [*NOTE* : First character will be taken as input] : ";
       gets(choice);

       switch(choice[0])
       {
                   case '1' :   system("CLS");
                                cout << "\n\tEnter the Roll No. to be Searched : ";
                                cin >> rollNumber;
                                cin.ignore();

                                start = search_Student_Record(start,rollNumber);
                                break;

                   case '2' :   system("CLS");
                                cout << "\n\tEnter the Roll No. whose Record is to be Deleted : ";
                                cin >> rollNumber;
                                cin.ignore();

                                start = delete_Student_Record(start,rollNumber);
                                break;

                   case '3' :   system("CLS");
                                cout << "\n\tEnter the Roll No. whose Record is to be Updated : ";
                                cin >> rollNumber;
                                cin.ignore();

                                start = update_Student_Record(start,rollNumber);
                                break;

                   case '4' :   system("CLS");
                                cout << "\n\tAll Records are : " << endl;

                                start = displayAllRecords(start);
                                break;

                   case '5' :   system("CLS");
                                cout << "\n\tPlease Enter the Details of Student : ";

                                if(NULL == start)
                                {
                                    start = add_Initial_Student_Record(start,copyrollNumber,writeptr);
                                    copyrollNumber++;
                                }

                                else
                                {
                                    start = add_Student_Record(start,copyrollNumber,writeptr);
                                    copyrollNumber++;
                                }

                                break;

                   case '6' :   system("CLS");
                                cout << "\n\tThanks For Your Input! Visit Next Time " << endl;

                                answer = false;
                                break;

                   default  :   cout << "\n\tInvalid Input! Please Choose any one (1/2/3/4/5/6) [*NOTE* : First character will be taken as input] : " << endl;
       }

      cout << "\n\tDo you Want to again Perform Operations (y/Y/n/N) ? [*NOTE* : First character will be taken as input] : ";
      gets(yesno);

      if(yesno[0] == 'n' || yesno[0] == 'N')
      {
          cout << "\n\tThanks for your Input, Visit Next Time!" << endl;
          break;
      }

      else if(yesno[0] == 'y' || yesno[0] == 'Y')
      {
          system("CLS");
          continue;
      }

      else
      {
          while(answer)
          {
                cout << "\n\tInvalid Input! Please Choose either y/Y or n/N " << endl;
                cout << "\n\tDo you Want to again Perform Operations (y/Y/n/N) ? [*NOTE* : First character will be taken as input] : ";
                gets(yesno);

                if(yesno[0] == 'y' || yesno[0] == 'Y' )
                {
                    system("CLS");
                    break;
                }

                else if(yesno[0] == 'n' || yesno[0] == 'N')
                {
                    cout << "\n\tThanks for your Input, Visit Next Time" << endl;
                    answer = false;
                    break;
                }

                else
                {
                    answer = true;
                }
          }
      }
   }

   fclose(writeptr);

   return 0;
}




