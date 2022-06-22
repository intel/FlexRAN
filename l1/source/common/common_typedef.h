
/*########################################################################################
###   Copyright (2019) Intel Corporation.                                              ###
###                                                                                    ###
###   Redistribution. Redistribution and use in binary form, without modification,     ## 
###   are permitted provided that the following conditions are met:                    ###
###                                                                                    ###
###    * Redistributions must reproduce the above copyright notice and the following   ###
###      disclaimer in the documentation and/or other materials provided with the      ###
###      distribution.                                                                 ###
###    * Neither the name of Intel Corporation nor the names of its suppliers may be   ###
###      used to endorse or promote products derived from this software                ###
###      without specific prior written permission.                                    ###
###    * No reverse engineering, decompilation, or disassembly of this software is     ###
###      permitted.                                                                    ###
###                                                                                    ###
###   Limited patent license.  Intel Corporation grants a world-wide, royalty-free,    ###
###   non-exclusive license under patents it now or hereafter owns or controls to make,###
###   have made, use, import, offer to sell and sell ("Utilize") this software, but    ###
###   solely to the extent that any                                                    ###
###   such patent is necessary to Utilize the software in the form provided by Intel.  ###
###   The patent license shall not apply to any combinations which include this        ###
###   software.  No hardware per se is licensed hereunder.                             ###
#########################################################################################*/
/*
 * @file common_typedef.h
 * @ingroup group_source_common
 * @author Intel Corporation
 **/

#ifndef _COMMON_TYPEDEF_H_
#define _COMMON_TYPEDEF_H_

#ifdef __cplusplus

#ifndef _RESTRICT_
#define _RESTRICT_
#define RESTRICT __restrict__
#endif  /* _RESTRICT_ */

extern "C" {
#endif

#include <stdint.h>

#ifndef _RESTRICT_
#define _RESTRICT_
#define RESTRICT restrict
#endif  /* _RESTRICT_ */

#ifndef _ALIGN_
#define _ALIGN_
#ifdef _WIN64
#define __align(x) __declspec(align(x))
#else
#define __align(x) __attribute__((aligned(x)))
#endif
#endif /* _ALIGN_ */

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#ifndef TRUE
/** TRUE = 1 */
#define TRUE 1
#endif /* #ifndef TRUE */

#ifndef FALSE
/** FALSE = 0 */
#define FALSE 0
#endif /* #ifndef FALSE */


#ifndef SUCCESS
/** SUCCESS = 0 */
#define SUCCESS     0
#endif /* #ifndef SUCCESS */

#ifndef FAILURE
/** FAILURE = 1 */
#define FAILURE     1
#endif /* #ifndef FAILURE */

#ifndef __INLINE__
#define __INLINE__
#if defined (WIN32)
#define INLINE
#elif defined (_MSC_VER)
#define INLINE                      _inline
#else
#define INLINE                      inline
#endif
#endif /* #ifndef __INLINE__ */

#ifndef _atomic_t_
#define _atomic_t_
/** atomic */
typedef volatile unsigned long atomic_t;
#endif /* #ifndef _atomic_t_ */

#ifdef _WIN64
#define ALIGN64 __declspec(align(64))
#else
#define ALIGN64 __attribute__((aligned(64)))
#endif


#ifndef _COMMON_TYPEDEF_SDK_H_
#define _COMMON_TYPEDEF_SDK_H_

/** complex type for int16_t */
typedef struct {
    int8_t re;                      /**< real part */
    int8_t im;                      /**< imaginary  part */
}complex_int8_t;

/** complex type for int16_t */
typedef struct {
    int16_t re; /*!< 16-bit real part */
    int16_t im; /*!< 16-bit image part */
}complex_int16_t;


/** complex type for int32_t */
typedef struct {
    int32_t re; /*!< 32-bit real part */
    int32_t im; /*!< 32-bit image part */
}complex_int32_t;

/** complex type for float */
typedef struct {
    float re; /*!< 32-bit real part */
    float im; /*!< 32-bit image part */
}complex_float;

/** complex type for double */
typedef struct {
    double re; /*!< 64-bit real part */
    double im; /*!< 64-bit image part */
}complex_double;

#endif /* #ifndef _COMMON_TYPEDEF_SDK_H_ */


#ifdef PHY_GCC
#define IVDEP "GCC ivdep"
#define __assume_aligned(x,y) x=__builtin_assume_aligned(x,y)
#else
#define IVDEP "ivdep"
#endif

#ifdef __cplusplus
    }
#endif
#endif /* #ifndef _COMMON_TYPEDEF_H_ */

