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

/**
 * @brief This file has the common type definitions and #defines used across the code
 * @file common_typedef.h
 * @ingroup group_source_common
 * @author Intel Corporation
 **/

#ifndef _COMMON_TYPEDEF_H_
#define _COMMON_TYPEDEF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef _WIN32
#ifndef _LTE_FAPI_
#ifndef NR5G_BS_PHY_STATS_PARSER
#include <rte_atomic.h>
#endif
#endif
#else
#ifdef _WIN32
#define __ATOMIC_RELEASE    0
#define __ATOMIC_ACQ_REL    1
#define rte_atomic32_t  int32_t
#define __assume_aligned

extern void rte_atomic32_clear(int32_t *pVar);
extern void rte_atomic32_inc(int32_t *pVar);
extern void rte_atomic32_dec(int32_t *pVar);
extern void __atomic_store_n(void *pPtr, int64_t val, int32_t memorder);
extern void __atomic_fetch_add(void *pPtr, int32_t val, int32_t memorder);
extern void __atomic_fetch_sub(void *pPtr, int32_t val, int32_t memorder);
#endif
#endif

#ifndef RESTRICT
#ifdef _WIN32
#define RESTRICT __restrict
#else
#if defined(__GNUC__) && !defined(__clang__) && !defined(__ICC)
#define RESTRICT __restrict__
#else
#define RESTRICT __restrict
#endif
#endif
#endif  /* RESTRICT */

#ifndef __align
#ifdef _WIN64
#define __align(x) __declspec(align(x))
#else
#define __align(x) __attribute__((aligned(x)))
#endif
#endif /* __align */

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC extern
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

#ifndef INLINE
#if defined (WIN32)
#define INLINE
#elif defined (_MSC_VER)
#define INLINE                      _inline
#else
#define INLINE                      inline
#endif
#endif /* #ifndef INLINE */

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

