#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


int *A, *A1, *AA1;          //указатели на int массивы
float *B, *B1, *BB1;        //указатели на float массивы
int type=0, map_type=0;     //служебные переменные для выбора операций
float swapf;                //служебная переменная для sort`а
int n=0, n1=0, n2=0;        // счетчики элементов массивов
int array_is_created = 0;   // Массив существует?
int where_type=0;           //Выбор при использовании where
//--------------------------------------------------------------------------------------------------------
//----------------------------------------Функция создания массива----------------------------------------
//--------------------------------------------------------------------------------------------------------

void create_array() {

    type = 0;
    puts("Please, input array size. \n");
    scanf("%d", &n);

    if (n < 0) {
        puts("You cant have negative size!");
    }
    if (n > 0) {
        array_is_created = 1;
        while (type != 1 && type != 2) {
            puts("Please, input array data type: 1 for integer, 2 for float. \n");
            scanf("%d", &type);

        }

        if (type == 1) {
            A = (int *) malloc(n * sizeof(int));                //выделение памяти

            puts("Enter array's elements (Use 'space' or 'enter' between elements.): \n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &A[i]);
            }
            puts("The array looks like this: \n");
            for (int i = 0; i < n; i++)
                printf("%d  ", A[i]);
            puts("\n");
        }

        if (type == 2) {

            B = (float *) malloc(n * sizeof(float));            //выделение памяти
            puts("Enter array's elements (Use 'space' or 'enter' between elements): \n");
            for (int i = 0; i < n; i++) {
                scanf("%f", &B[i]);
            }
            puts("The array looks like this: \n");
            for (int i = 0; i < n; i++)
                printf("%f  ", B[i]);
            puts("\n");
        }
    }
}
//--------------------------------------------------------------------------------------------------------
//---------------------------------------Функции сравнения для qsort--------------------------------------
//--------------------------------------------------------------------------------------------------------

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
    {
        return ( *(int*)x1 - *(int*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
    }

int compare_neg(const void * x1, const void * x2)   // функция сравнения элементов массива (neg) (так то то же самое, что и обычный compare,
                                                    // но так как нужно было сортировать "в другом направлении" решил просто поменять x1 и x2)
    {
        return (*(int*)x2 - *(int*)x1);              // если результат вычитания равен 0, то числа равны, > 0: x1 < x2; < 0: x1 > x2
    }

//--------------------------------------------------------------------------------------------------------
//-------------------------------------------Сортировка массива-------------------------------------------
//--------------------------------------------------------------------------------------------------------

void sort()
{
    int sort_type = 0;                                          // выбор сортировки
    while (sort_type != 1 && sort_type != 2 && sort_type != 3) {
        puts("How do u want to sort the array: \n"
             "1)lowest to highest \n"
             "2) highest to lowest. \n"
             "3) Exit to the main menu. \n");
        scanf("%d", &sort_type);
    }

    if (type == 1) {

        if (sort_type == 1)
        {
            qsort(A, n, sizeof(int), compare);                   //qsort(массив, кол-во элементов, размер элементов в байтах и функция сравнения)
            puts("Your sorted array looks like this:   ");  //qsort сортирует элементы, используя данную ему функцию.
            for (int i = 0; i < n; i++)
                printf("%d  ", A[i]);
            puts("\n");
        }
        if (sort_type == 2)
        {
            qsort(A, n, sizeof(int), compare_neg);
            puts("Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%d  ", A[i]);
            puts("\n");
        }
        if (sort_type==3)
        {

        }

    }
    if (type == 2) {
        if (sort_type == 1) {
            for (int i = 0; i < n - 1; i++) {
                for (int d = 0; d < n - 1; d++) {
                    if (B[d + 1] < B[d]) /* For decreasing order use '<' instead of '>' */
                    {
                        swapf = B[d];
                        B[d] = B[d + 1];
                        B[d + 1] = swapf;
                    }
                }
            }
            puts("Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%f  ", B[i]);
            puts("\n");
        }

        if (sort_type == 2) {
            for (int i = 0; i < n - 1; i++) {
                for (int d = 0; d < n - 1; d++) {
                    if (B[d + 1] > B[d]) /* For decreasing order use '<' instead of '>' */
                    {
                        swapf = B[d];
                        B[d] = B[d + 1];
                        B[d + 1] = swapf;
                    }
                }
            }
            puts("Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%f  ", B[i]);
            puts("\n");
        }
    }
}

//-------------------------------------------------------------------------------------------------------
//-----------------------------------Функция конкатенации массивов----------------------------------------------
//-------------------------------------------------------------------------------------------------------

void concatenate()
{
    if (type==1)
    {
        int choice=0;
        puts("Right now you can only concatenate with another Integer-type array. If you want to interact with Float-type array,"
             "please  return to the main menu"
             "If you want to continue input 1. "
             "If you want to go back to the main menu, input 2.  \n");
        scanf("%d", &choice);
        if(choice==1)
        {
            puts("Please, input the size of the second array. \n");
            scanf("%d", &n1);
            A1 = (int *) malloc(n1 * sizeof(int));
            puts("Enter second array's elements (use space between elements): \n");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &A1[i]);
            }
            puts("The second array looks like this: \n");
            for (int i = 0; i < n1; i++)
                printf("%d  ", A1[i]);
            puts("\n");

            n2=n+n1;
            AA1 = (int *) malloc(n2 * sizeof(int));
            for (int i = 0; i < n; i++)
            {
                AA1[i]=A[i];
            }
            for (int i=n; i<n2; i++)
            {
                AA1[i]=A1[i-n];
            }
            puts("Your concatenated array looks like this:  \n");
            for (int i=0; i<n2; i++)
                printf("%d ",AA1[i] );

            puts("\n");
        }
        if(choice ==2){}
    }
    if (type==2)
    {
        int choice=0;
        puts("Right now you can only concatenate with another Float-type array. If you want to interact with Integer-type array,please"
             " return to the main menu"
             "If you want to continue input 1."
             "If you want to go back to the main menu, input 2  \n");
        scanf("%d", &choice);
        if(choice==1)
        {
            puts("Please, input the size of the second array. \n");
            scanf("%d", &n1);
            B1 = (float *) malloc(n1 * sizeof(float));
            puts("Enter array's elements (use space between elements): \n");
            for (int i = 0; i < n1; i++) {
                scanf("%f", &B1[i]);
            }
            puts("The array looks like this: \n");
            for (int i = 0; i < n1; i++)
                printf("%f  ", B1[i]);
            puts("\n");

            n2=n+n1;
            BB1 = (float *) malloc(n2 * sizeof(float));
            for (int i = 0; i < n; i++)
            {
                BB1[i]=B[i];
            }
            for (int i=n; i<n2; i++)
            {
                BB1[i]=B1[i-n];
            }
            puts("Your concatenated array looks like this:  \n");
            for (int i=0; i<n2; i++)
                printf("%f ",BB1[i] );

            puts("\n");
        }
        if(choice ==2) {}
    }

}

//-------------------------------------------------------------------------------------------------------
//----------------------------------------------Функция MAP----------------------------------------------
//-------------------------------------------------------------------------------------------------------

void map()
{

    puts("What do you want to do: \n"
         "1)Multiply every array element by '-1' \n"
         "2)Add 10 to every array element \n"
         "3)Change every even number to '0' and every odd number to '1' \n"
         "4)Exit to the main menu. \n");
    scanf("%d", &map_type);
    if (map_type==4)
    {

    }

    if(type==1)
    {
        if (map_type == 1)
        {
            for (int i = 0; i < n; i++)
            {
                A[i]= -1*A[i];
            }
            puts("Your mapped array looks like this: \n");
            for (int i=0; i<n; i++)
                printf("%d ",A[i] );
            puts("\n");
        }
        if (map_type == 2)
        {
            for (int i = 0; i < n; i++)
            {
                A[i]=A[i]+10;
            }
            puts("Your mapped array looks like this: \n");
            for (int i=0; i<n; i++)
                printf("%d ",A[i] );
            puts("\n");

        }
        if (map_type == 3)
        {
            for (int i = 0; i < n; i++)
            {
                if(A[i]%2==0)
                    A[i]=0;
                else
                    A[i]=1;
            }
            puts("Your mapped array looks like this: \n");
            for (int i=0; i<n; i++)
                printf("%d ",A[i] );
            puts("\n");
        }
    }
    if(type==2)
    {
        if (map_type == 1)
        {
            for (int i = 0; i < n; i++)
            {
                B[i]= -1*B[i];
            }
            puts("Your mapped array looks like this: \n");
            for (int i=0; i<n; i++)
                printf("%f ",B[i] );
            puts("\n");

        }
        if (map_type == 2)
        {
            for (int i = 0; i < n; i++)
            {
                B[i]=B[i]+10;
            }
            puts("Your mapped array looks like this: \n");
            for (int i=0; i<n; i++)
                printf("%f ",B[i] );
            puts("\n");

        }
        if (map_type == 3)
        {
           puts("Your array type is float, therefore we cant check if the numbers are even or odd");
        }
    }
}

//-------------------------------------------------------------------------------------------------------
//---------------------------------------------Функция WHERE---------------------------------------------
//-------------------------------------------------------------------------------------------------------

void where()
{
    puts("These following procedures are available: \n"
         "1)Positive array elements. \n"
         "2)Array elements that are greater than 100. \n"
         "3)Array elements that greater than the previous ones. \n"
         "4)Exit to main menu. \n");
    scanf("%d", &where_type);

    if(where_type==4)
    {
        puts("Returning to the main menu...");
    }

    if(type==1)
    {
        if (where_type == 1)
        {
            puts("Positive elements of the array: \n");
            for (int i = 0; i < n; i++)
            {
                if (A[i] > 0)
                    printf("A[%d] = %d, ", i, A[i]);
            }
            puts("\n");
        }
        if (where_type==2)
        {
            for (int i=0; i < n; i++)
            {
                if (A[i]>100)
                    printf("A[%d] = %d, ", i, A[i]);
            }
            puts("\n");
        }
        if(where_type==3)
        {
            for (int i=1; i < n; i++)
            {
                if(A[i]>A[i-1])
                    printf("A[%d] = %d, ", i, A[i]);
            }
            puts("\n");
        }
    }
    if(type==2)
    {
        if (where_type == 1)
        {
            puts("Positive elements of the array: \n");
            for (int i = 0; i < n; i++)
            {
                if (A[i] > 0)
                    printf("A[%d] = %f, ", i, B[i]);
            }
            puts("\n");
        }
        if (where_type==2)
        {
            for (int i=0; i < n; i++)
            {
                if (A[i]>100)
                    printf("A[%d] = %F, ", i, B[i]);
            }
            puts("\n");
        }
        if(where_type==3)
        {
            for (int i=1; i < n; i++)
            {
                if(A[i]>A[i-1])
                    printf("A[%d] = %F, ", i, B[i]);
            }
            puts("\n");
        }
    }

    }


//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------MAIN--------------------------------------------------
//-------------------------------------------------------------------------------------------------------

int main() {

    int number = 0;
    while (number != 6) {
        puts("   1)Enter a new array \n"
               "   2)Sort an array \n"
               "   3)Concatenation of 2 arrays \n"
               "   4)Map \n"
               "   5)Where \n"
               "   6)Exit \n");
        scanf("%d", &number);
        if (number == 1)      //создание и печать массива
        {
            create_array();
        }


        if (number == 2)     //сортировка данного массива
        {
            if (array_is_created==0)
            {
                puts(" There are no array to sort! \n"
                     " Returning to the main menu... \n");
            }
            else
                sort();
        }

        if (number == 3)
        {
            if (array_is_created==0)
            {
                puts("You dont have an array yet.  \n");
            }
            else
                concatenate();
        }

        if(number == 4)
        {
            if (array_is_created==0)
            {
                puts(" There are no array to map! \n"
                     " Returning to the main menu... \n");
            }
            else
            map();
        }

        if(number == 5)
        {
            if (array_is_created==0)
            {
                puts(" There are no array to use 'where' on! \n"
                     " Returning to the main menu... \n");
            }
            else
            where();
        }

        if (number == 6)
        {
            puts("Exiting now... ");
            return 0;
        }

        if(number != 1 && number != 2 && number != 3 && number != 4 && number != 5 && number != 6)
        {
            puts("You entered an invalid value. Please try again.   \n");
        }

        }
        number=0;
    }
