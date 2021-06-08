#ifndef MAIN_C_DIM_H
#define MAIN_C_DIM_H

struct dims
{

    void *pdim;
    int type;
    int num;
    size_t size;

};
//прототипы функций:

//--------------------------------------------------------------------------------------------------------
//----------------------------------------Функция создания массива----------------------------------------
//--------------------------------------------------------------------------------------------------------

void create_array(int, int);

//--------------------------------------------------------------------------------------------------------
//---------------------------------------Функция сортировки-----------------------------------------------
//--------------------------------------------------------------------------------------------------------

void sort(int, int, int);

//-------------------------------------------------------------------------------------------------------
//-----------------------------------Функция конкатенации массивов---------------------------------------
//-------------------------------------------------------------------------------------------------------

void concatenate(int);

//-------------------------------------------------------------------------------------------------------
//----------------------------------------------Функция MAP----------------------------------------------
//-------------------------------------------------------------------------------------------------------

void map(int, int);

//-------------------------------------------------------------------------------------------------------
//---------------------------------------------Функция WHERE---------------------------------------------
//-------------------------------------------------------------------------------------------------------


void where(int, int);








//pamagiti((

#endif //MAIN_C_DIM_H