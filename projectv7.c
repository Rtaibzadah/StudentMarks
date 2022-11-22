/***********************************************************************
 * project1.c
 * Roman Taibzadah
 * Candidate Number - 263038
 * version 7
 ***********************************************************************/

#include <stdio.h>

void space(void);
void emptyBuffer(void);
int printMenu(void);
void enterMarks(int option, int numStudents, char studentnames[76][30],
 int coursework1[75], int coursework2[75], int coursework3[75]);
void coursework1mark(int numStudents, char studentnames[76][30],
 int coursework1[75]);
void coursework2mark(int numStudents, char studentnames[76][30],
 int coursework2[75]);
void coursework3mark(int numStudents, char studentnames[76][30],
 int coursework3[75]);
int displaymarks(int numStudents, char studentnames[76][30],
 int coursework1[75], int coursework2[75], int coursework3[75]);
int correctionsC1(int numStudents, char studentnames[76][30],
 int coursework1[75]);
int correctionsC2(int numStudents, char studentnames[76][30],
 int coursework2[75]);
int correctionsC3(int numStudents, char studentnames[76][30],
 int coursework3[75]);
void supervisor(int numStudents, char studentnames[76][30],
 int coursework1[75], int coursework2[75], int coursework3[75]);
int numOfStudents();


int main(void)
{
    space();
    space();
    int coursework1[75] = {0};
    int coursework2[75] = {0};
    int coursework3[75] = {0};
    int numStudents = numOfStudents();
    char students[numStudents + 1][30];
    
    //Enter name of the students
    for(int i = 0; i < numStudents; i++)//enter student names
    {
        printf("\n enter student for index %d : ", i);
        scanf("%[^\n]%*c", students[i]);
        emptyBuffer();
    }
    for(int j = 0; j < numStudents; j++)//validation- print names
    {
        printf("\n index: %d student %s", j, students[j]);
    }
    //main program loop
    int option = 0;
    do
    {
        option = printMenu();
        if(option == 1)
        {
            // Display Menu
            enterMarks(option, numStudents, students, coursework1,
             coursework2, coursework3);
        }
        else if (option == 2)
        {
            // display marks//function
            printf("display marks!2 \n");
            displaymarks(numStudents, students, coursework1, coursework2
            , coursework3);
        }
        else if (option == 3)
        {
            // supervisor mode//function
            printf("supervisor mode!2 \n");
            supervisor(numStudents, students, coursework1, coursework2,
             coursework3);
        }
        else
        {   
            // exit program
            printf("Exit Program!2 \n");
            break;
        }
    }
    while(option != 4);
    printf("\n\n\n\n Program Has Ended \n");
    return 0;
}

/* option 3 from the menu - supervisor mode*/
void supervisor(int numStudents, char studentnames[76][30],
 int coursework1[75], int coursework2[75], int coursework3[75])
{
    int enterdPin = 0 ;
    int pin = 3333;
    printf("Supervisor Mode \n\n");
    printf("Enter Supervisor Mode PIN: ");
    scanf("%d", &enterdPin);
    // gives 4 tries to enter pin correctly
    for(int i = 1; i < 4;  i++)
    {
        if(enterdPin == pin)
        {
            i = 4;
            int option = 0;
            printf("Would you like to: \n");
            printf("  1) change the pin number. \n  2) change a particu"
            "lar mark. \n  3) add a student \n  4) correct a students "
            "name.\n");
            printf("Enter a option (1-4)\n");
            scanf("%d%*c", &option);
            if(option == 1)
            {
                printf("What would you like to change the pin number"
                " to? \n");
                scanf("%d", &pin);
                printf("\n\nyou have successfully change the pin number"
                " to %d\n", pin);
                break;
            }
            else if(option == 2)
            {
                printf("you have chosen to change a students mark \n");
                for(int i = 0; i < numStudents; i++)
                {
                    printf("      Student %d - %s \n", i,
                     studentnames[i]);
                }
                int studentIndex;
                printf("\n\n choose a student (0 - %d): "
                , numStudents-1);
                scanf("%d", &studentIndex);
                printf("you have chosen student %d - %s \n\n\n",
                studentIndex , studentnames[studentIndex]);
                printf("previous marks were:      CourseWork1: %d - "
                "CourseWork2: %d - CourseWork3: %d",
                 coursework1[studentIndex], coursework2[studentIndex],
                 coursework3[studentIndex]);
                printf("enter mark for Coursework1: ");
                scanf("%d", &coursework1[studentIndex]);
                printf("enter mark for Coursework2: ");
                scanf("%d", &coursework2[studentIndex]);
                printf("enter mark for Coursework3: ");
                scanf("%d", &coursework3[studentIndex]);
                printf("Updated Marks for studnet %s are CourseWork1:"
                " %d - CourseWork2: %d - CourseWork3: %d\n\n"
                ,studentnames[studentIndex], coursework1[studentIndex], 
                coursework2[studentIndex], coursework3[studentIndex]);
                printf("Tap Enter Key to continue");
                char enter;
                scanf("%c", &enter);
            }
            else if (option == 3)
            {
                //add a student
                printf("How many extra students would you like to add?"
                "\n");
                int num = numStudents;
                //to add the new anount of students
                numStudents += numOfStudents();
                for(int i = num; i < numStudents; i++ )
                {
                    printf("\n enter student for index %d : ", i);
                    scanf("%[^\n]%*c", studentnames[i]);
                    emptyBuffer();
                }
                //validation- print names
                for(int i = numStudents; i < num ; i++)
                {
                    printf("\n index: %d student %s", i,
                     studentnames[i]);
                }
            }
            else if (option == 4)
            {
                for(int i = 0; i < numStudents; i++)
                {
                    printf(" student %d - %s \n", i, studentnames[i]);
                }
                int student;
                printf("Which students name would you like to change?");
                printf("Enter a number (0-%d)", numStudents-1);
                scanf("%d", &student);
                printf(" this index has student %d - %s", student,
                         studentnames[student]);
            }
        }
        else
        {
            printf("Error: Incorrect pin has been entered \n");
            printf("%d more attempts left \n", 4-i);
            printf("Enter the Supervisor Mode PIN: ");
            scanf("%d", &enterdPin);
        }
    }
}

/*allows for corrections to be made to individual students in
coursework 1*/
int correctionsC1(int numStudents, char studentnames[76][30],
 int coursework1[75])//works
{
    char yesNo;
    printf("Would you like to make any corrections? ");
    //validation- checcking for yes no
        while( !((yesNo == 'y') || (yesNo == 'Y')))
        {
            printf("enter (y/n): \n");
            scanf("%c", &yesNo); 
            emptyBuffer();
            if((yesNo == 'n') || (yesNo == 'N'))
            {
                return yesNo; 
            }
            else if ((yesNo == 'y') || (yesNo == 'Y'))
            {
            }
            else
            {
                printf("Error: Invalid input");
            }
        }
    printf("\n\nMake Changes to coursework1: \n");
    printf("Student names are listed Below\n");
        // print studdent names and indexes
    for(int j = 0; j< numStudents; j++)
    {
        printf("%d. student %s - %d \n", j, studentnames[j],
                     coursework1[j]);
    }

    int index;
    //validating which student you want to edit
    printf("which student would you like to change marks for?\n");
    printf("Enter student (0 - %d): \n", numStudents-1);
    while((scanf("%d", &index))
             != 1 || index < 0 || index > numStudents)
    {
        printf("Error: Invalid input \n");
        printf("Enter a Number Between (0 - %d) \n\n", numStudents-1);
        emptyBuffer();
    }
    emptyBuffer();
    // validating the mark entered
    printf("Enter the number of marks: \n");
    while((scanf("%d", &coursework1[index]))
         != 1 || coursework1[index] < 0 || coursework1[index] > 100)
    {
        printf("Error: Invalid input \n");
        printf("Enter a Mark Between (0 - 100) \n\n");
        emptyBuffer();
    }
    emptyBuffer();
    //this for error checking
    printf(" studnet: %s got %d in coursework 1 \n",
    studentnames[index], coursework1[index]);
    //print studdent names and indexes
    for(int j = 0; j < numStudents; j++)
    {
        printf("new %d. student %s - %d \n", j, studentnames[j],
         coursework1[j]);
    }
    return yesNo;
}

/*allows for corrections to be made to individual students in
coursework 2*/
int correctionsC2(int numStudents, char studentnames[76][30],
 int coursework2[75])//works
{
    char yesNo;
    printf("Would you like to make any corrections? ");
        while(!((yesNo== 'y') || (yesNo == 'Y')))
        {
            printf("enter (y/n): \n");
            scanf("%c", &yesNo); 
            emptyBuffer();
            if((yesNo == 'n') || (yesNo == 'N'))
            {
                printf("you have breaked \n");
                return yesNo; ///-- 
            }
            else if ((yesNo == 'y') || (yesNo == 'Y'))
            {
                printf("you have enterd yes \n");
            }
            else
            {
                printf("Error: Invalid input");
            }
            printf("you have left if\n");
        }
    // print studdent names and indexes
    for(int j = 0; j < numStudents; j++)
    {
        printf("%d. student %s - %d \n", j, studentnames[j],
                     coursework2[j]);
    }
    
    int index;
    //validating which student you want to edit
    printf("which student would you like to change marks for?\n");
    printf("Enter student (0 - %d): \n", numStudents-1);
    while((scanf("%d", &index))
             != 1 || index < 0 || index > numStudents)
    {
        printf("Error: Invalid input \n");
        printf("Enter a Number Between (0 - %d) \n\n", numStudents-1);
        emptyBuffer();
    }
    emptyBuffer();
    printf("Valid nnumber entered %d\n\n", index);//end
    // validating the mark entered
    printf("Enter the number of marks: \n");
    while((scanf("%d", &coursework2[index]))
             != 1 || coursework2[index] < 0 || coursework2[index] > 100)
    {
        printf("Error: Invalid input \n");
        printf("Enter a Mark Between (0 - 100) \n\n");
        emptyBuffer();
    }
    emptyBuffer();
    //this for error checking
    printf(" studnet: %s got %d in coursework 2 \n",
             studentnames[index], coursework2[index]);
    for(int j = 0; j < numStudents; j++)
    {
        printf("new %d. student %s - %d \n", j,
                     studentnames[j], coursework2[j]);
    }
    return yesNo;
}

/*allows for corrections to be made to individual students in
coursework 3*/
int correctionsC3(int numStudents, char studentnames[76][30],
 int coursework3[75])//works
{
    char yesNo;
    printf("Would you like to make any corrections? ");
        while(!((yesNo== 'y') || (yesNo == 'Y')))
        {
            printf("enter (y/n): \n");
            scanf("%c", &yesNo); 
            emptyBuffer();
            if((yesNo == 'n') || (yesNo == 'N'))
            {
                printf("you have breaked \n");
                    return yesNo;
            }
            else if ((yesNo == 'y') || (yesNo == 'Y'))
            {
                printf("you have enterd yes \n");
            }
            else
            {
                printf("Error: Invalid input");
            }
            printf("you have left if\n");
        }
    // print studdent names and indexes
    for(int j = 0; j < numStudents; j++)
    {
        printf("%d. student %s - %d \n", j, studentnames[j],
         coursework3[j]);
    }
    int index;
    printf("which student would you like to change marks for?\n");
    printf("Enter student (0 - %d): \n", numStudents-1);
    while((scanf("%d", &index))
             != 1 || index < 0 || index > numStudents)
    {
        printf("Error: Invalid input \n");
        printf("Enter a Number Between (0 - %d) \n\n", numStudents-1);
        emptyBuffer();
    }
    emptyBuffer();
    space();//end
    // validating the mark entered
    printf("Enter the number of marks: \n");
    while((scanf("%d", &coursework3[index]))
             != 1 || coursework3[index] < 0 || coursework3[index] > 100)
    {
        printf("Error: Invalid input \n");
        printf("Enter a Mark Between (0 - 100) \n\n");
        emptyBuffer();
    }
        emptyBuffer();
        printf(" studnet: %s got %d in coursework 3 \n",
        //this for error checking
         studentnames[index], coursework3[index]);
    for(int j = 0; j < numStudents; j++)
    {
        printf("new %d. student %s - %d \n", j, studentnames[j],
         coursework3[j]);
    }
    return yesNo;
}

/*this function allosws for all the students marks in coursework 1 
to be entered*/
void coursework1mark(int numStudents, char studentnames[76][30],
 int coursework1[75])// validation works
{   
    int num;
    for (int i = 0; i < numStudents; i++)
    {
        printf("enter the mark (0- 100) for \nstudent num %d - %s \n\n",
        i ,studentnames[i]);
        while((scanf("%d", &coursework1[i]))
                 != 1 || coursework1[i] < 0 || coursework1[i] > 100)
        {
            printf("Error: Invalid input \n");
            printf("Enter a Mark Between (0 - 100) \n\n");
            emptyBuffer();
        }
        emptyBuffer();
        printf(" studnet: %s got %d in coursework 1 \n",
         studentnames[i], coursework1[i]);//this for error checking
    }
    for(int j = 0; j < numStudents; j++)
    {
        printf("%d. student %s - %d \n", j, studentnames[j],
         coursework1[j]);
    }
    correctionsC1(numStudents, studentnames, coursework1);
}

/*this function allosws for all the students marks in coursework 2
to be entered*/
void coursework2mark(int numStudents, char studentnames[76][30],
 int coursework2[75])// works 

{
    for (int i = 0; i < numStudents; i++)
    {
        printf("enter the mark (0- 100) for student num %d - %s \n\n",
        i ,studentnames[i]);

        while((scanf("%d", &coursework2[i]))
         != 1 || coursework2[i] < 0 || coursework2[i] > 100)
        {
            printf("Error: Invalid input \n");
            printf("Enter a Mark Between (0 - 100) \n\n");
            emptyBuffer();
        }
        emptyBuffer();
        
        printf(" studnet: %s got %d in coursework 2 \n",
         studentnames[i], coursework2[i]);//this for error checking

         
    }
    for(int j = 0; j < numStudents; j++){
        printf("%d. student %s - %d \n", j, studentnames[j],
         coursework2[j]);
    }
    correctionsC2(numStudents, studentnames, coursework2);
}

/*this function allosws for all the students marks in coursework 3 
to be entered*/
void coursework3mark(int numStudents, char studentnames[76][30],
 int coursework3[75])// works very well
{
    for (int i = 0; i < numStudents; i++)
    {
        printf("enter the mark (0- 100) for student num %d - %s \n\n",
                i ,studentnames[i]);

        while((scanf("%d", &coursework3[i]))
                 != 1 || coursework3[i] < 0 || coursework3[i] > 100)
        {
            printf("Error: Invalid input \n");
            printf("Enter a Mark Between (0 - 100) \n\n");
            emptyBuffer();
        }
        emptyBuffer();
        
        printf(" studnet: %s got %d in coursework 3 \n",
         studentnames[i], coursework3[i]);//this for error checking

    }
    for(int j = 0; j < numStudents; j++)
    {
        printf("%d. student %s - %d \n", j, studentnames[j],
         coursework3[j]);
    }
    correctionsC3(numStudents, studentnames, coursework3);
}

/* this function is enter marks it asks user to enter which coursework 
they want to enter marks for then it calls that fuction */
void enterMarks(int option, int numStudents, char studentnames[76][30],
 int coursework1[75], int coursework2[75], int coursework3[75])//works
{

    if (option == 1)
    {
        // enterMarks//enter marks function
        printf("which courseWork would you like to enter marks for?");
        int option;
        do
        {
            printf("courseWorks: \n\n 1. Coursework 1 \n 2. Coursework "
                    "2 \n 3. Coursework 3 \n ");
            printf("\nSelect a Option (1-3): ");
            scanf("%d%*c", &option);
            emptyBuffer();
            printf("\n\n\n\n\n\n\n\n");
            if (option == 1)
            {
                printf("Course work 1 \n");
                for(int j =0; j < numStudents; j++){
                printf(" student %d -  %s \n", j, studentnames[j]);
                } 
                coursework1mark(numStudents,studentnames, coursework1);
            }
            else if (option == 2)
            {
                printf("Course work 2 \n");
                coursework2mark(numStudents,studentnames, coursework2);
            }
            else if (option == 3)
            {
                printf("course work 3 \n");
                coursework3mark(numStudents,studentnames, coursework3);
            }
            else
            {
                printf("Error: input is not valid \n");
            }
        }
        while (option > 4 || option < 1);
    }
    else if (option == 2)
    {
        // display marks//function
        printf("display marks!");
    }
    else if (option == 3)
    {
        // supervisor mode//function
        printf("supervisor mode!");
    }
    else
    {
        // exit program//function
        printf("Exit Program!");
    }
}

int displaymarks(int numStudents, char studentnames[76][30],
 int coursework1[75], int coursework2[75], int coursework3[75])
 {
    printf("which students marks would you like to know? \n");
    for(int i = 0; i < numStudents; i++)
    {
        printf("student %d - %s \n", i, studentnames[i]);
    }

    int student;
    do
    {
        printf("Enter student from list (0-%d): \n", numStudents-1);
        while((scanf("%d", &student))
                     != 1 || student < 0 || student > 100)
        {
            printf("Error: Invalid input \n\n");
            printf("Enter a student  (0 - %d) \n\n", numStudents-1);
            emptyBuffer();
        }
        emptyBuffer();
        printf("You entered %d \n\n", student); //test
        printf("Coursework 1: %d   Coursework 2: %d   Coursework 3: "
        "%d \n", coursework1[student], coursework2[student],
         coursework3[student]);
        printf("Overall grade: %g %% \n\n",
         (coursework1[student]*0.2)+(coursework2[student]*0.3)
         +(coursework3[student]*0.5));
        char pauseScreen;
        scanf("%c", &pauseScreen);
    }while(student < 0 || student > numStudents);
    return 0;
}

/* prints the menu to user and returns the option back to menu so that
the appropiote function can be called*/
int printMenu(void)//works (DO NOT TOUCH !!!!)
{
    int option;
    do
    {
        printf("\nMenu: \n\n 1. Enter Marks \n 2. Display Particular"
        " Studnet Marks \n 3. Supervisor Mode \n 4. Exit Program \n");
        printf("\nSelect a Option (1-4): ");
        scanf("%d%*c", &option);
        emptyBuffer();
        printf("\n\n\n\n\n\n\n\n");
        if (option == 1)
        {
            printf("Option 1 - Enter Marks \n");
        }
        else if (option == 2)
        {
            printf("Option 2 - Display student marks \n");
        }
        else if (option == 3)
        {
            printf("Option 3 - supervisor mode \n");
        }
        else if (option == 4)
        {
            printf("Option 4 - Exit program \n");
        }
        else
        {
            printf("Error: input is not valid \n");
        }
    }
    while (option > 4 || option < 1);
    return option;
}

/*returns a user input for the number of students*/
int numOfStudents()
{
    int numStudents;
    do
    {
        printf("Enter the number of students: \n");;
            scanf("%d%*c", &numStudents);
            emptyBuffer();
        if(numStudents >= 1 && numStudents <= 75)
        {
            printf("You are storing %d student names \n", numStudents);
            return numStudents;
        }
        else
            {
            printf("Error: Invalid Input \n\n\n");
        }
    }
    while(numStudents > 75 || numStudents < 1);
    return numStudents;
}

// resets stdin
void emptyBuffer(void) 
{ 
    while(getchar() != '\n') 
    { 
        ; 
    } 
} 

/*Extra Space*/
void space(void)
{
    printf("\n\n\n\n\n\n\n\n");
}