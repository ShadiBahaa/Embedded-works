/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : BIT_MATH.h    ****************/
/******** Date       : 17/9/2022     ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_
#define SET_BIT(var,bit_num) var=var|(1<<bit_num)
#define CLR_BIT(var,bit_num) var=var&~(1<<bit_num)
#define TOGGLE_BIT(var,bit_num) var=var^(1<<bit_num)
#define GET_BIT(var,bit_num) (var>>bit_num)&1
#endif // _BIT_MATH_H_
