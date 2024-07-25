/*########################################################################################
###   Copyright (2021) Intel Corporation.                                              ###
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
 *
 * @brief API Definitions exhanged between MAC and PHY (LTE and NR5G)
 * @file mac_phy_api.h
 * @ingroup group_common_mac_phy_api
 * @author Intel Corporation
 **/

#ifndef _COMMON_MAC_PHY_API_H_
#define _COMMON_MAC_PHY_API_H_

#include "common_typedef.h"

// Message Types for debugging with 5GNR Test App and Test MAC only
#define MSG_TYPE_PHY_DL_IQ_SAMPLES              (200)
#define MSG_TYPE_PHY_UL_IQ_SAMPLES              (201)
#define MSG_TYPE_PHY_UL_UNCODED_BITS            (202)
#define MSG_TYPE_PHY_ADD_REMOVE_CORE            (203)
#define MSG_TYPE_PHY_UL_PRACH_IQ_SAMPLES        (204)
#define MSG_TYPE_PHY_UL_MMIMO_SRS_IQ_SAMPLES    (205)
#define MSG_TYPE_PHY_RX_CHAN_EST_OUTPUT_IND     (206)
#define MSG_TYPE_PHY_DL_BEAM_WEIGHTS            (207)
#define MSG_TYPE_PHY_UL_BEAM_WEIGHTS            (208)
#define MSG_TYPE_PHY_TEST_CONFIG_INFO           (209)

//------------------------------------------------------------------------------------------------------------
typedef struct tMac2PhyApiQueueElem
{
    struct tMac2PhyApiQueueElem* pNext;         // 0-7 byte
    uint8_t  nMessageType;                       // 8
    uint32_t nMessageLen;                        // 9-12
    uint8_t  nNumMessageInBlock;                 // 13
    uint32_t nAlignOffset;                       // 14-17
    uint64_t nTimeStamp;                         // 18-25
    uint8_t  reserved[6];                        // 26-31
} MAC2PHY_QUEUE_EL, *PMAC2PHY_QUEUE_EL;
//------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_ADD_REMOVE_CORE message
typedef enum
{
    CELL_MASK = 0,
    SRS_MASK,
    DLBEAM_MASK,
    URLLC_MASK,
    MAX_MASK_OPTIONS
} CORE_MASK_OPTIONS;

typedef enum
{
    PDSCH_SPLIT = 0,
    PDSCH_PROC_TYPE,
    PDSCH_DL_WEIGHT_SPLIT,
    PUSCH_CHANEST_SPLIT,
    PUSCH_RNN_SPLIT,
    PUSCH_MMSE_SPLIT,
    PUSCH_LLR_RX_SPLIT,
    PUSCH_UL_WEIGHT_SPLIT,
    PUCCH_SPLIT,
    SRS_SPLIT,
    FEC_ENC_SPLIT,
    FEC_DEC_SPLIT,
    FEC_DEC_NUM_ITER,
    FEC_DEC_EARLY_TERM_DISABLE,
    TIMER_MODE_MULTI_CELL_DELAY,
    BBUPOOL_SLEEP_ENABLE,
    CE_INTERP_METHOD,
    LINEAR_INTERP_ENABLE,
    DFT_BF_WEIGHT_GEN_ENABLE,
    RX_ANT_VERTICAL,
    RX_ANT_HORIZONTAL,
    RX_ANT_POLARIZATION,
    IRC_ENABLE_THRESHOLD,
    IRC_MMSE_SWITCHING_ENABLE,
    REMOVE_MEMCPY_MEMSET,
    EBBU_POOL_NUM_QUEUE,
    EBBU_POOL_QUEUE_SIZE,
    EBBU_POOL_NUM_CONTEXT,
    EBBU_POOL_MAX_CONTEXT_FETCH,
    BF_WEIGHT_GEN_GRANULARITY,
    SPR_PIPRLINE,
    SRS_FFT_FLAG_ENABLE_FLUSH,
    PRACH_MAX_COMBINE_TYPE,
    PRACH_THRESHOLD_METHOD,
    PRACH_IFFT_FLAG_ENABLE_FLUSH,
    PUSCH_IRC_FORCE,
    SRS_BYPASS,
    EBBU_POOL_FEC_ONLY_LIST,
    SRS_AGC_FLAG_ENABLE_FLUSH,
    SRS_AGC_TARGET_SET_FLUSH,
    SRS_DFT_CE_FILL_FULL_BAND,
    PUCCH_AGC_TARGET_SET_FLUSH,     /*! [R22.11] Add for PUCCH AGC */
    PUCCH_F0_SPRCVT_SCALE_SET_FLUSH,
    PUCCH_F1_SPRCVT_SCALE_SET_FLUSH,
    PUCCH_F2_SPRCVT_SCALE_SET_FLUSH,
    PUCCH_F3_SPRCVT_SCALE_SET_FLUSH,
    PUCCH_F4_SPRCVT_SCALE_SET_FLUSH,
    SRS_AGC_METHOD_CHOOSE,
    SRS_SPR_CVT_SCALE_SET_FLUSH,    /*! [R23.07] Add for SRS SPR ORAN */
    SRS_MMIMO_PROC_OFFSET,
    SRS_TOC_BYPASS_FLUSH,           /*! [R23.07] Add for SRS TOC */
    PUCCH_F234_DECODER,
    LTE_TIMER_MODE_FREQ_DOMAIN_INOUT,
    PUSCH_FOC_ENABLE,
    NUM_SPLIT_OPTIONS
} CHANNEL_SPLIT_OPTIONS;

typedef enum
{
    BBU_CORE_ADD = 0,  /*! add core(s) to BBU Pool */
    BBU_CORE_REMOVE,   /*! remove core(s) to BBU Pool */
    BBU_CORE_SUSPEND,  /*! suspend core(s) that are already added to BBU Pool */
    BBU_CORE_RESUME,   /*! wake up core(s) that have been suspended */
    BBU_CORE_SET_CORE, /*! wake up core(s) that have been suspended */
} BBUPOOL_CORE_OPERATION;


#define MAX_NUM_CELLS (64)
#define MAX_NUM_SET_CORE_MASK ( 4 )
#define MAX_GROUP_NUM (32)

typedef struct tAddRemoveBbuCoresStruct
{
    BBUPOOL_CORE_OPERATION eOption;
    uint64_t nCoreMask[MAX_MASK_OPTIONS][MAX_NUM_SET_CORE_MASK];
    uint32_t nMacOptions[NUM_SPLIT_OPTIONS];
    uint64_t nMacOptionsCellMask[NUM_SPLIT_OPTIONS];
    uint8_t nPuschInterOptions[MAX_NUM_CELLS][MAX_GROUP_NUM];
} ADD_REMOVE_BBU_CORES, *PADD_REMOVE_BBU_CORES;

typedef struct tTestFileConfig
{
    char sTestFileName[512];
} TEST_FILE_CONFIG, *PTEST_FILE_CONFIG;

//------------------------------------------------------------------------------------------------------------

#define MAX_UL_IQ_SAMPLE_PORTS            ( 16 )
#define MAX_UL_IQ_SAMPLE_ANT              ( 64 )
#define MAX_DL_IQ_SAMPLE_PORTS            ( 16 )
#define MAX_DL_UL_IQ_FILE_NAME_LEN        ( 576 )

typedef struct tDlUlIqSamplesStruct
{
    uint32_t carrNum;
    uint32_t numSubframes;
    uint32_t nIsRadioMode;
    uint32_t TimerModeFreqDomain;
    uint32_t TimerModeFreqDomainInOut;
    uint32_t PhaseCompensationEnable;
    uint32_t nStartFrameNum;
    uint32_t nStartSlotNum;
    uint32_t nStartSymNum;
    char filename_test_case[MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_in_ul_iq[MAX_UL_IQ_SAMPLE_PORTS][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_in_ul_iq_compressed[MAX_UL_IQ_SAMPLE_PORTS][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_in_prach_iq[MAX_UL_IQ_SAMPLE_PORTS][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_in_srs_iq[MAX_UL_IQ_SAMPLE_ANT][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_out_dl_iq[MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_out_dl_beam[MAX_DL_IQ_SAMPLE_PORTS][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_out_ul_beam[MAX_UL_IQ_SAMPLE_PORTS][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_out_ul_pucch_beam[MAX_UL_IQ_SAMPLE_PORTS][MAX_DL_UL_IQ_FILE_NAME_LEN];
    char filename_out_dl_iq_compressed[MAX_DL_UL_IQ_FILE_NAME_LEN];

    /* DL Compression add */
    uint16_t nDLCompressionIdx;
    uint16_t nDLCompiqWidth;
    uint16_t nDLCompScaleFactor;
    uint16_t nDLCompreMask;

    /*nULDecompressionIdx, determine the UL Decompression method, Value:0->4*/
    /*0:NONE,  1:BLKFLOAT,  2:BLKSCALE,  3:ULAW,  4:MODULATION*/
    uint16_t nULDecompressionIdx;
    uint16_t nULDecompiqWidth;

    uint32_t nAvgDLRbs;
    uint32_t nAvgDLRbLayers;
    uint64_t nAvgDLTput;
    uint32_t nAvgULRbs;
    uint32_t nAvgULRbLayers;
    uint64_t nAvgULTput;

    uint8_t buffer[4096];
} PHY_DL_UL_IQ_SAMPLES, *PPHY_DL_UL_IQ_SAMPLES;


int32_t gnb_l1_init(int32_t argc, char *argv[]);
int32_t gnb_l1_release();
int32_t gnb_l1_stop();
int32_t gnb_l1_ebbupool_handler_set(void *pHandler);


#endif  /* #ifndef _COMMON_MAC_PHY_API_H_ */


