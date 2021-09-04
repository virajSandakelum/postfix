
#include<stdio.h>   //include input output operations
#include<string.h>  //include string handling function
#include<stdlib.h>  // include standard library
#include<conio.h>   //include console input output


#define MAX 15      // define the stack size


int stack[MAX];     // stack declaration

int top =-1;    // global variable definition



/* characters push to the stack */

void push(char  data){

    if(top == MAX-1){           // check the last index and top of the stack is equal
        printf("OVERFLOW");
    }
    else{

         stack[++top] = data;      // top increment by one and then store the data in the stack
    }

}



/* characters pop from the stack */

char  pop(){

    if(top==-1){                    // check the stack is empty
        printf("UNDERFLOW");
    }
    else{

        return stack[top--];        //return the character from the stack and top decrement by one
    }

}



/* driver function */

int main(){

/* get postfix expression from the user */

printf("Enter the postfix expression :");
char expression[10] ; //char array for the stored to postfix expression
scanf("%s",expression);


printf("\n\n");  // add 2 new lines

int i=0;          // index of the expression
char temp = 't';  // temporary variable for the store the answer of the register
int numOfTemp = 0;   // number of the temporary variable



while(expression[i]!= '\0'){   // check the expression from 1st character to null terminal character

  if(expression[i]>='A' && expression[i]<='Z'){   // check the operands of the expression


            char x = expression[i];     //operands stored the x variable
            push(x);                    // push to the stack that found operands


        }



  if(expression[i]=='/' || expression[i] == '*'|| expression[i]== '+' || expression[i] == '-' ){      //check the operators of the expression



        char firstPop = pop();   //pop the top character from the stack
        char secondPop = pop();  //pop the second character from the stack


        if(expression[i]=='/'){     // check the '/' operator has in the expression

             if(secondPop == 't'){              //check the second pop character is  pre-stored in temporary variable or not

                printf("LD TEMP%d\n",numOfTemp-1);  //then temporary variable count decrease by one
            }
             else{
                printf("LD %c\n",secondPop);

            }


            if(firstPop=='t'){               //check the first pop character is pre- stored in temporary variable or not

                printf("DV TEMP%d\n",numOfTemp);

             }else{

                printf("DV %c\n",firstPop);
             }


            /* subject to the calculation */

            temp = secondPop*firstPop;  //stored the value in the temp variable
            numOfTemp++;                 //number of the temporary variable increment by one
            push('t');                     //temp variable push to the stack
            printf("ST TEMP%d\n",numOfTemp);


        }



        /* likewise check the other operators */


        else if(expression[i]=='*'){        // check the '*' operator has in the expression


             if(secondPop == 't'){

                printf("LD TEMP%d\n",numOfTemp-1);
            }
            else{
                printf("LD %c\n",secondPop);

            }


             if(firstPop=='t'){

                printf("ML TEMP%d\n",numOfTemp);

             }else{

                printf("ML %c\n",firstPop);
             }



            temp = secondPop*firstPop;
            numOfTemp++;
            push('t');
            printf("ST TEMP%d\n",numOfTemp);



        }




       else if(expression[i]=='+'){         // check the '+' operator has in the expression

             if(secondPop == 't'){

                printf("LD TEMP%d\n",numOfTemp-1);
            }
            else{
                printf("LD %c\n",secondPop);

            }


             if(firstPop=='t'){

                printf("AD TEMP%d\n",numOfTemp);

             }else{

                printf("AD %c\n",firstPop);
             }




            temp = secondPop+firstPop;
            numOfTemp++;
            push('t');
            printf("ST TEMP%d\n",numOfTemp);



        }





       else if(expression[i]=='-'){     // check the '-' operator has in the expression

            if(secondPop == 't'){

                printf("LD TEMP%d\n",numOfTemp-1);
            }
            else{
                printf("LD %c\n",secondPop);

            }



            if(firstPop=='t'){

                printf("SB TEMP%d\n",numOfTemp);

             }else{

                printf("SB %c\n",firstPop);
             }



            temp = secondPop-firstPop;
            numOfTemp++;
            push('t');
            printf("ST TEMP%d\n",numOfTemp);


            }

    }


i++;        //position increment by one in the expression

}

getch();
return 0;
}


