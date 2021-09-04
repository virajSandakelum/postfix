
/* Include Header file */

#include<stdio.h>   //include standard input and output
#pragma GCC diagnostic ignored "-Wwrite-strings"    //ignored for the GCC compiler warning

int denominationCount(int employeeSalary,char *type);    //prototype of the denominationCount function

                                                        // type argument means "Rs" or "Total"




int totalSalary = 0;        // define total Salary of employees as global variable


/* add employees details */

void employee(){


    printf("Input:\n");

    printf("No of employees :");
    int employeeNum;
    scanf("%d",&employeeNum);       //get number of employees of the organization



    while(employeeNum!=0){      //check and get all employees details


        printf("\n\n\nGive employee name:");
        char employeeName[20];

        scanf("%s",&employeeName);      //input employee name

        printf("Give the salary of %s :",employeeName);
        int salary;
        scanf("%d",&salary);        //input employee salary


        printf("Output:\n");

        printf("%s\n",employeeName);    //display the employee name

        printf("Salary: Rs.%d\n",salary);   //display the employee salary

        printf("Coin analysis:\n");

        denominationCount(salary,"RS");        //call to denominationCount function for coin analysis

        totalSalary  = totalSalary + salary;    //total salary of the employees

        employeeNum--;          //number of employee decrement by 1


    }

}



/* Get the denomination of the SriLanka currencies */

int denominationCount(int employeeSalary,char *type){


    int notes_coins[10] = {5000,1000,500,100,50,20,10,5,2,1}; //denomination currencies of SriLanka(notes and coins)
    int noteCounter[10] = {0};      // notes counter array variable for the add notes of employees salary

    int i=0;

    for(i=0;i<10;i++){

        if(employeeSalary >=notes_coins[i]){         // check employee salary with denomination currencies of Sri Lanka

            noteCounter[i]  = employeeSalary / notes_coins[i];      // add note count accordingly with denomination currencies

            employeeSalary = employeeSalary % notes_coins[i];       // get modular of employee salary  with denomination currencies
        }
    }


    for(i=0;i<10;i++){


        if(noteCounter[i]!=0){  // check the note counter is equal to 0 or not


            printf("%s %ds : %d\n",type,notes_coins[i],noteCounter[i]);     //display amount of money for each denomination.
                                                                            // type means "Rs" or "Total"

        }
    }


}





/* driver function */

int main(){


    employee();     //call to employee function for the add employee details

    printf("\n\n\nSummary:\n\n");

    printf("VirajTech Organization (virajsandakelum8811@gamil.com)\n\n");

    printf("Total salary :%d\n",totalSalary);       // get total salary of all employees of the Organization

    denominationCount(totalSalary,"Total");         //call to denominationCount function for required in each denomination of employees total salary


return 0;
}
