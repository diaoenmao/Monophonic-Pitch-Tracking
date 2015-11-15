/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Administrator
 *
 * Created on November 13, 2015, 11:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Add.h"
#include "Add_types.h"
/*
 * 
 */
int main(int argc, char** argv) {
    puts("!!!Hello World!!!"); // prints !!!Hello World!!! 
    Add_initialize();
    double arr[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double out[5];
    double b = 1;
    Add(arr,b,out);
    int i;
    for(i=0;i<5;i++){
        printf("%f\n",out[i]);
    }
    return (EXIT_SUCCESS);
}

