#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "dims.h"



struct dims dim;

//--------------------------------------------------------------------------------------------------------
//----------------------------------------Функция создания массива----------------------------------------
//--------------------------------------------------------------------------------------------------------

void create_array(int n, int type) {
    int *A;
    float *B;
    int *pA=NULL;
    float *pB=NULL;
        if (type == 1) {
            A = (int *) malloc(n * sizeof(int));                //выделение памяти

            puts("  Enter array's elements (Use 'space' or 'enter' between elements.): \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &A[i]);
            }
            puts("  The array looks like this: \n");
            for (int i = 0; i < n; i++)
                printf("%d  ", A[i]);
            puts("\n");
            pA=A;
            dim.pdim=pA;
            dim.type=type;
            dim.num=n;
            dim.size=sizeof(int);
        }

        if (type == 2) {

            B = (float *) malloc(n * sizeof(float));            //выделение памяти
            puts("  Enter array's elements (Use 'space' or 'enter' between elements): \n");
            for (int i = 0; i < n; i++) {
                scanf("%f", &B[i]);
            }
            puts("  The array looks like this: \n");
            for (int i = 0; i < n; i++)
                printf("%f  ", B[i]);
            puts("\n");

            pB=B;
            dim.pdim=pB ;
            dim.type=type;
            dim.num=n;
            dim.size=sizeof(float);
        }

}

//--------------------------------------------------------------------------------------------------------
//-------------------------------------------Сортировка массива-------------------------------------------
//--------------------------------------------------------------------------------------------------------

void sort(int n, int sort_type, int type) {
    if (type == 1)
    {
        int *pA;

        pA=(int *)dim.pdim;
        int swapf;
        if (sort_type == 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int d = 0; d < n - 1; d++)
                {
                    //int x1 = *(int *)p +d;
                    //int x1 = *(int *)p +d =1;
                    if (*(pA +d+1) < *(pA +d))
                    {
                        swapf = *(pA +d);
                        *(pA +d) = *(pA +d + 1);
                        *(pA +d + 1) = swapf;
                    }
                }
            }
            puts("  Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%d  ", *(pA+i));
            puts("\n");
        }
        if (sort_type == 2)
        {
            for (int i = 0; i < n - 1; i++) {
                for (int d = 0; d < n - 1; d++) {
                    //int x1 = *(int *)p +d;
                    //int x1 = *(int *)p +d =1;
                    if (*(pA +d+1) > *(pA +d)) {
                        swapf = *(pA +d);
                        *(pA +d) = *(pA +d + 1);
                        *(pA +d + 1) = swapf;
                    }
                }
            }
            puts("  Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%d  ", *(pA+i));
            puts("\n");
        }
    }
    if (type == 2)
    {
        float *pA;
        pA=(float *)dim.pdim;
        float swapf;
        if (sort_type == 1)
        {
            for (int i = 0; i < n - 1; i++) {
                for (int d = 0; d < n - 1; d++) {
                    //int x1 = *(int *)p +d;
                    //int x1 = *(int *)p +d =1;
                    if (*(pA +d+1) < *(pA +d)) {
                        swapf = *(pA +d);
                        *(pA +d) = *(pA +d + 1);
                        *(pA +d + 1) = swapf;
                    }
                }
            }
            puts("  Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%f  ", *(pA+i));
            puts("\n");
        }
        if (sort_type == 2)
        {
            for (int i = 0; i < n - 1; i++) {
                for (int d = 0; d < n - 1; d++) {
                    //int x1 = *(int *)p +d;
                    //int x1 = *(int *)p +d =1;
                    if (*(pA +d+1) > *(pA +d)) {
                        swapf = *(pA +d);
                        *(pA +d) = *(pA +d + 1);
                        *(pA +d + 1) = swapf;
                    }
                }
            }
            puts("  Your sorted array looks like this:   ");
            for (int i = 0; i < n; i++)
                printf("%f  ", *(pA+i));
            puts("\n");
        }
    }
}

//-------------------------------------------------------------------------------------------------------
//-----------------------------------Функция конкатенации массивов---------------------------------------
//-------------------------------------------------------------------------------------------------------

void concatenate(int n) {

    if (dim.type == 1) {
        int *pA;
        pA=(int *)dim.pdim;
        int *A1;
        A1 = (int *) malloc(n * sizeof(int));                //выделение памяти

        puts("  Enter 2nd array's elements (Use 'space' or 'enter' between elements.): \n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &A1[i]);
        }
        puts("  The 2nd array looks like this: \n");
        for (int i = 0; i < n; i++)
            printf("%d  ", A1[i]);
        puts("\n");


        int *AA1;
        AA1=(int *) malloc((dim.num+n)*sizeof(int));

        for (int i=0; i<dim.num;i++)
            AA1[i] = *(pA+i);

        for (int i=dim.num; i<n+dim.num; i++)
            AA1[i]=A1[i-dim.num];

        puts("  Your concatenated array looks like this: \n");

        for (int i=0; i<n+dim.num; i++)
            printf("%d ", AA1[i]);

        free(A1);
        free(AA1);

        puts("\n");
    }
    if (dim.type == 2) {
        float *pA;
        pA=(float *)dim.pdim;
        float *A1;
        A1 = (float *) malloc(n * sizeof(float));                //выделение памяти

        puts("  Enter 2nd array's elements (Use 'space' or 'enter' between elements.): \n");
        for (int i = 0; i < n; i++) {
            scanf("%f", &A1[i]);
        }
        puts("  The 2nd array looks like this: \n");
        for (int i = 0; i < n; i++)
            printf("%f  ", A1[i]);
        puts("\n");


        float *AA1;
        AA1=(float *) malloc((dim.num+n)*sizeof(float));

        for (int i=0; i<dim.num;i++)
            AA1[i] = *(pA+i);

        for (int i=dim.num; i<n+dim.num; i++)
            AA1[i]=A1[i-dim.num];

        puts("  Your concatenated array looks like this: \n");

        for (int i=0; i<n+dim.num; i++)
            printf("%f ", AA1[i]);

        free(A1);
        free(AA1);

        puts("\n");

    }


}

//-------------------------------------------------------------------------------------------------------
//----------------------------------------------Функция MAP----------------------------------------------
//-------------------------------------------------------------------------------------------------------

void map(int map_type, int map_num)
{
    if (dim.type==1) {
        int *pA;
        pA = (int *) dim.pdim;
        puts("Your 'mapped' array looks like this: \n");

        if (map_type == 1) {
            for (int i = 0; i < dim.size - 1; ++i) {
                *(pA + i) = *(pA + i) + map_num;
                printf("%d ", *(pA + i));
            }
            puts("\n");
        }
        if (map_type == 2) {
            for (int i = 0; i < dim.size - 1; ++i) {
                *(pA + i) = *(pA + i) * map_num;
                printf("%d ", *(pA + i));
            }
            puts("\n");
        }
        if (map_type == 3) {

        }
    }
    if (dim.type==2) {
        float *pA;
        pA = (float *) dim.pdim;
        puts("Your 'mapped' array looks like this: \n");

        if (map_type == 1) {
            for (int i = 0; i < dim.size - 1; ++i) {
                *(pA + i) = *(pA + i) + map_num;
                printf("%f ", *(pA + i));
            }
            puts("\n");
        }
        if (map_type == 2) {
            for (int i = 0; i < dim.size - 1; ++i) {
                *(pA + i) = *(pA + i) * map_num;
                printf("%f ", *(pA + i));
            }
            puts("\n");
        }
        if (map_type == 3) {

        }
    }
}

//-------------------------------------------------------------------------------------------------------
//---------------------------------------------Функция WHERE---------------------------------------------
//-------------------------------------------------------------------------------------------------------

void where(int where_type, int where_num) {
    int where_count=0;
    if (dim.type == 1) {
        int *pA;
        pA=(int *)dim.pdim;
        if (where_type == 1) {
            for (int i = 0; i < dim.size - 1; ++i) {
                if (*(pA + i) > where_num){
                    printf("A[%d] = %d ", i, *(pA + i));
                where_count++;
                }
            }
            if (where_count==0)
            {
                puts("There are no such elements in the array \n");
            }
        }
        if (where_type ==2)
        {
            for (int i = 0; i < dim.size - 1; ++i) {
                if (*(pA + i) == where_num){
                    printf("A[%d] = %d ", i, *(pA + i));
                where_count++;
                }
            }
            if (where_count==0)
            {
                puts("There are no such elements in the array \n");
            }
        }
        if (where_type==3)
        {
            for (int i = 0; i < dim.size - 1; ++i) {
                if (*(pA + i) < where_num) {
                    printf("A[%d] = %d ", i, *(pA + i));
                    where_count++;
                }
            }
            if (where_count==0)
            {
                puts("There are no such elements in the array \n");
            }
        }
    }

    if (dim.type == 2) {
        float numf;
        numf=where_num;
        float *pA;
        double epsilon;
        epsilon=0.00001;
        pA=(float *)dim.pdim;
        if (where_type == 1) {
            for (int i = 0; i < dim.size - 1; ++i) {
                if ((*(pA + i) - numf) > epsilon) {
                    printf("A[%d] = %f ", i, *(pA + i));
                    where_count++;
                }
            }
            if (where_count==0)
            {
                puts("There are no such elements in the array \n");
            }
        }
        if (where_type ==2)
        {
            for (int i = 0; i < dim.size - 1; ++i) {
                if ((*(pA + i) - numf) == 0) {
                    printf("A[%d] = %f ", i, *(pA + i));
                    where_count++;
                }
            }
            if (where_count==0)
            {
                puts("There are no such elements in the array \n");
            }
        }
        if (where_type==3)
        {
            for (int i = 0; i < dim.size - 1; ++i) {
                if ((*(pA + i) - numf) < epsilon) {
                    printf("A[%d] = %f ", i, *(pA + i));
                    where_count++;
                }
            }
            if (where_count==0)
            {
                puts("There are no such elements in the array \n");
            }
        }
    }

    puts("\n");
}
