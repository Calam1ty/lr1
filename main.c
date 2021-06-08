#include <stdio.h>
#include "dims.h"
#include "functions.c"
#define or ||



struct dims dim;

int map_type=0, map_num=0;
int where_type=0, where_num=0;
float where_numf=0;
int array_is_created = 0;   // Массив существует?
int n;
int type;
int number = 0;
float map_numf=0;



//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------MAIN--------------------------------------------------
//-------------------------------------------------------------------------------------------------------

int main() {

    while (number != 6)
    {
        puts("   1 - Enter a new array \n"
             "   2 - Sort an array \n"
             "   3 - Concatenation \n"
             "   4 - Map \n"
             "   5 - Where \n"
             "   6 - Exit \n");
        scanf("%d", &number);
        if(number==1)                       // создание массива
        {
                type=0;
                n = 0;
                while (n <= 0)
                {
                    puts("  Input array size \n");
                    scanf("%d", &n);
                    if (n <= 0)
                        puts("  Size should be greater than 0. Please, enter a valid size  \n");
                }
                while (type != 1 && type != 2)
                {
                    puts("  Please, input array data type:  \n"
                         "  1 for integer,  \n"
                         "  2 for float. \n");
                    scanf("%d", &type);
                    if (type != 1 && type != 2)
                        puts("  Please, enter a valid data type. \n");
                }
                array_is_created = 1;
                create_array(n, type);


        }
        if (number == 2)                     //сортировка
        {
            if (array_is_created == 0) {
                puts("  You dont have an array yet. \n"
                     "  Returning to the main menu \n");
            }
            else
                {
                int sort_type = 0;
                while (sort_type != 1 && sort_type != 2 && sort_type != 3) {
                    puts("  Choose a sorting method: \n"
                         "  1 - Lowest to highest \n"
                         "  2 - Highest to lowest \n"
                         "  3 - Exit to main menu \n");
                    scanf("%d", &sort_type);
                    if(sort_type != 1 && sort_type != 2 && sort_type != 3)
                        puts("  Please choose a valid option \n");
                }
                if (sort_type==1 or sort_type==2)
                    sort(n, sort_type, dim.type);
            }
        }
        if(number == 3)                     //конкатенация
        {
            int choice=0;
            if(dim.type==1)
            {
                int lenght;
                while (choice != 1 && choice != 2) {
                puts("  Right now you can only concatenate with another Integer-type array. If you want to interact with Float-type array, \n"
                     "  please  return to the main menu \n"
                     "  If you want to continue input 1. \n"
                     "  If you want to go back to the main menu, input 2.  \n");
                scanf("%d", &choice);
                if(choice==1)
                {

                    puts("  Input the size of the 2nd array: \n");
                    scanf("%d", &lenght);
                    concatenate(lenght);
                }
                if(choice==2)
                {
                    puts("Returning to the main menu...");
                }
                if (choice != 1 && choice != 2)
                    puts("Please, enter a valid number \n");
            }
            }

            if(dim.type==2) {
                int lenght;
                while (choice != 1 && choice != 2) {
                    puts("  Right now you can only concatenate with another Float-type array. If you want to interact with Float-type array, \n"
                         "  please  return to the main menu \n"
                         "  If you want to continue input 1. \n"
                         "  If you want to go back to the main menu, input 2.  \n");
                    scanf("%d", &choice);
                    if (choice == 1) {

                        puts("  Input the size of the 2nd array: \n");
                        scanf("%d", &lenght);
                        concatenate(lenght);
                    }
                    if (choice == 2) {
                        puts("Returning to the main menu...");
                    }
                    if (choice != 1 && choice != 2)
                        puts("Please, enter a valid number \n");
                }
            }
        }
        if(number==4)                                   //мап
        {
            map_type = 0;
            map_num = 0;
            while (map_type != 1 && map_type != 2 && map_type != 3) {
                puts("  You can choose these 'maps' : \n"
                     "  1 - add N to all array elements \n"
                     "  2 - multiply all array elements by N \n"
                     "  3 - exit to main menu \n");
                scanf("%d", &map_type);
                if (map_type != 1 && map_type != 2 && map_type != 3)
                    puts("Input a valid value \n");
            }
            if (map_type == 1 or map_type == 2)
            {
                puts("  You can only interact by using integer numbers \n"
                     "  Please, input N ( it has to be integer) \n");
                scanf("%d", &map_num);
                map(map_type, map_num);
            }
        }

        if (number == 5)
        {
            while (where_type!=1 && where_type!=2 && where_type!=3 && where_type!= 4) {
                puts("   Choose 'where' option: \n"
                     "   1 - print all the elements, which are greater than N \n"
                     "   2 - print all the elements, which are equal to N \n"
                     "   3 - print all the elements, which are smaller than N \n"
                     "   4 - exit to main menu \n");

                scanf("%d", &where_type);
                if (where_type != 1 && where_type != 2 && where_type != 3 && where_type != 4)
                    puts("Please input a valid value \n");
                if(where_type==4)
                {

                }
                else {
                    puts("Input N. It has to be integer. \n");
                        scanf("%d", &where_num);

                    where(where_type, where_num);
                }
            }
            where_type=0;
            where_num=0;
        }

    }
}



