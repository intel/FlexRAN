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
 * @brief API Definitions exhanged between MAC and PHY
 * @file nr5g_mac_phy_api.h
 * @ingroup group_common_mac_phy_api
 * @author Intel Corporation
 **/

#ifndef _NR5G_MAC_PHY_API_H_
#define _NR5G_MAC_PHY_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack (4)

#include "common_typedef.h"
#include "common_mac_phy_api.h"

#define MAX_MIMO_GROUP_NUM          (32)

#define MAX_DL_PARIED_UE_NUM        (12)
#define MAX_UL_PARIED_UE_NUM        (12)
#define MAX_DL_PER_UE_CODEWORD_NUM  (2)
#define MAX_DL_RBG_BIT_NUM          (5)  // For resource allocation type 0.The maximum number is 138 with 275 RBs and RBG size 2.
#define MAX_UL_RBG_BIT_NUM          (5)  // 275/2
#define MAX_DL_PER_UE_DMRS_PORT_NUM (8)
#define MAX_UL_PER_UE_DMRS_PORT_NUM (4)
#define MAX_DL_PER_UE_PTRS_PORT_NUM (2)
#define MAX_UL_PER_UE_PTRS_PORT_NUM (2)
#define MAX_DL_REAL_PORTS           (16)

#define MAX_DCI_BIT_BYTE_LEN              (32)
#define MAX_UCI_BIT_BYTE_LEN              (256)
#define MAX_DL_INPUT_TRANSPORT_BYTE_SIZE_NR5G  (175000)
#define MAX_NUM_DL_LAYERS                 (8)
#define MAX_DL_HARQ_PROCESS_ID            (16)
#define MAX_UL_PDU_NUM                    (200)
#define MAX_UE_MANAGEMENT_NUM             ( 64 )
#define MAX_UL_INPUT_TRANSPORT_BYTE_SIZE_NR5G  (131000)      //have to check this
#define MAX_UL_HARQ_PROCESS_ID            (16)          //have to check this
#define PRERESERVED_DATA_HEADER_LEN       (32)
#define MAX_TDD_PERIODICITY               (80)
#define MAX_NUM_OF_SYMBOL_PER_SLOT        (14)
#define MAX_TXRU_NUM                      (4)
#define MAX_RXRU_NUM                      (16)
#define MAX_DL_CSIRS_PORT_NUM             (32)
#define MAX_RX_SRS_STREAM_NUM             (32)
#define MAX_NUM_ANT_NR5G                  (64)
#define MAX_UL_PORTS_PER_UE               (4)
#define MAX_PANEL_NUM                     (4)
#define SINR_STEP_SIZE                    (256.0)
#define PWR_INVALID                       (-128.0) // Indicator for invalid power values
#define MAX_REPORT_UL_PORTS               (8)
#define MAX_NUM_RBG                       (69)
#define MAX_NUM_PART1_PARAMS              (4)          // Maximum number of Part 1 parameters that influence the size of this part 2.
#define MAX_SIZE_CSI_PART2_MAP            (1<<12)      // Maximum depth of each UCI map
#define BWP_MIN_SIZE                      (20)
#define BWP_MAX_SIZE                      (275)
#define BWP_MAX_START                     (254)
#define MAX_PRACH_FRE_FDM                 (8)          // number of PRACH frequence  occations
#define MAX_PRACH_TIME_TDM                (7)          // number of PRACH time occations


// API Message Type Field coding definitions
#define MSG_TYPE_PHY_CONFIG_REQ       (0x1)
#define MSG_TYPE_PHY_CONFIG_RESP      (0x2)
#define MSG_TYPE_PHY_START_REQ        (0x3)
#define MSG_TYPE_PHY_START_RESP       (0x4)
#define MSG_TYPE_PHY_STOP_REQ         (0x5)
#define MSG_TYPE_PHY_STOP_RESP        (0x6)
#define MSG_TYPE_PHY_ERR_IND          (0x7)
#define MSG_TYPE_PHY_SHUTDOWN_REQ     (0x8)
#define MSG_TYPE_PHY_SHUTDOWN_RESP    (0x9)
#define MSG_TYPE_PHY_CELL_INFO_REQ    (0xa)
#define MSG_TYPE_PHY_EXIT_REQ         (0xb)

/* Using reserved message types Table 3-5 5G FAPI: PHY API specification 222.10.06*/
#define MSG_TYPE_PHY_OAM_REQ          (0xc)
#define MSG_TYPE_PHY_OAM_RESP         (0xd)
#define MSG_TYPE_PHY_OAM_NOTIFICATION (0xe)

#define MSG_TYPE_PHY_SLOT_IND         (0x10)
#define MSG_TYPE_PHY_DL_CONFIG_REQ    (0x11)
#define MSG_TYPE_PHY_UL_CONFIG_REQ    (0x12)
#define MSG_TYPE_PHY_UL_DCI_REQ       (0x13)
#define MSG_TYPE_PHY_TX_REQ           (0x14)
#define MSG_TYPE_PHY_CRC_IND          (0x15)
#define MSG_TYPE_PHY_RX_ULSCH_IND     (0x16)
#define MSG_TYPE_PHY_UCI_IND          (0x17)
#define MSG_TYPE_PHY_RX_RACH_IND      (0x18)
#define MSG_TYPE_PHY_RX_SRS_IND       (0x19)
#define MSG_TYPE_UE_MANAGEMENT_REQ    (0x20)
#define MSG_TYPE_PHY_RX_ULSCH_UCI_IND (0x30)

// WLS operation with PDSCH Payload
#define MSG_PHY_ZBC_BLOCK0_REQ        (30)
#define MSG_PHY_ZBC_BLOCK1_REQ        (31)

// WLS operation with PUSCH Payload
#define MSG_PHY_ZBC_BLOCK_IND         (32)


#define RUN_TIME_APIS_FROM_MAC_NR5G   ((1<<MSG_TYPE_PHY_DL_CONFIG_REQ) | \
                                       (1 << MSG_TYPE_PHY_UL_CONFIG_REQ) | \
                                       (1 << MSG_TYPE_PHY_UL_DCI_REQ) | \
                                       (1 << MSG_TYPE_PHY_TX_REQ))

/*****DL PDU type*******/
#define DL_PDU_TYPE_DCI       (0)
#define DL_PDU_TYPE_DLSCH     (1)
#define DL_PDU_TYPE_PBCH      (2)
#define DL_PDU_TYPE_CSIRS     (3)

/*****UL PDU type*******/
#define UL_PDU_TYPE_ULSCH     (4)
#define UL_PDU_TYPE_ULCCH_UCI (5)
#define UL_PDU_TYPE_ULSCH_UCI (6)
#define UL_PDU_TYPE_SRS       (7)
#define UL_PDU_TYPE_PRACH     (8)

#define UE_MANAGEMENT_PDU     (9)

/******ERROR indication*******/
#define MSG_OK                (0x00)
#define MSG_INVALID_STATE     (0x01)
#define MSG_INVALID_CONFIG    (0x02)
#define MSG_LATE_DL           (0x03)
#define MSG_LATE_UL           (0x04)
#define MSG_INVALID_DL_CONFIG (0x05)
#define MSG_INVALID_UL_CONFIG (0x06)

#define MAX_OAM_PDUS_PER_API 10
typedef enum nr5g_MacPhyOAMReqType {
    NR5G_MAC_PHY_OAM_MANAGE_LBM = 0,        // 0
    NR5G_MAC_PHY_OAM_FETCH_PM_STATS = 1,    // 1
    NR5G_MAC_PHY_OAM_MAX                    // 2
} nr5gMacPhyOAMReqType, nr5gMacPhyOAMRespType;

typedef enum nr5g_MacPhyOAMNotificationType {
    NR5G_MAC_PHY_OAM_NOTIFY_LBM_LINK_STATUS_CHANGE = 0,
    NR5G_MAC_PHY_OAM_NOTIFY_ERROR = 1,
    NR5G_MAC_PHY_OAM_NOTIFY_MAX
} nr5gMacPhyOAMMotificationType;

typedef enum nr5g_MacPhyOAMNotificationERRTYPE {
    NR5G_MAC_PHY_OAM_NOTIFY_FATALERR = 0, /* HW error and L1 not functioning, need HW reset */
    NR5G_MAC_PHY_OAM_NOTIFY_CRITICALERR, /* L1 not functioning, need specific recover scenario based on error code and OAM agreed scenario, e.g. cell delete */
    NR5G_MAC_PHY_OAM_NOTIFY_MAJORERR, /*  L1 is able to recover by itself, but in high risk, L2 needs to take action if continue receive this error in certain period */
    NR5G_MAC_PHY_OAM_NOTIFY_WARNING, /* L1 is able to recover by itself, may some risk. OAM need to be aware by warning, L2 needs to take action if continue receive this error in certain period */
    NR5G_MAC_PHY_OAM_NOTIFY_LOG, /* logging or other info exchange during run time */
    NR5G_MAC_PHY_OAM_NOTIFY_ERRTYPE_MAX
} nr5gMacPhyOAMMotificationErrType;

typedef enum nr5g_MacPhyOAMNotificationERRCODE {
    NR5G_MAC_PHY_OAM_NOTIFY_BBDEV_ERROR = 0,
    NR5G_MAC_PHY_OAM_NOTIFY_DL_LIST_NOT_COMPLETE,
    NR5G_MAC_PHY_OAM_NOTIFY_UL_LIST_NOT_COMPLETE,
    NR5G_MAC_PHY_OAM_NOTIFY_SRS_LIST_NOT_COMPLETE,
    NR5G_MAC_PHY_OAM_NOTIFY_LATE_API,
    NR5G_MAC_PHY_OAM_NOTIFY_MAX_SUCCESSIVE_NO_API,
    NR5G_MAC_PHY_OAM_NOTIFY_API_PARAM_ERROR,
    NR5G_MAC_PHY_OAM_NOTIFY_L1_MEM_ALLOC_ERROR,
    NR5G_MAC_PHY_OAM_NOTIFY_L1_THREAD_ERROR,
    NR5G_MAC_PHY_OAM_NOTIFY_ERRCODE_MAX
} nr5gMacPhyOAMMotificationErrCode;


// General Message header that is present at the top of each message
typedef struct tL1L2MessageHeader
{
    uint16_t nMessageType;
    uint16_t nMessageLen;
} L1L2MessageHdr, *PL1L2MessageHdr;

// Message header for Sfn and Slot Number Info
typedef struct tSfnSlot
{
    uint32_t nSFN:10;       // system frame number 0->1023
    uint32_t nSlot:9;       // slot number 0->319
    uint32_t nCarrierIdx:6; // carrier index, 0->63
    uint32_t nSym:4;        // Symbol Number, 0->13
    uint32_t nRsv:3;
} SFN_SlotStruct, *PSFN_SlotStruct;

//------------------------------------------------------------------------------------------------------------
typedef struct tSlotConfigReq
{
    uint8_t nSymbolType[MAX_NUM_OF_SYMBOL_PER_SLOT];    // Defines the Symbol type for all 14 symbols in a slot. 0: DL, 1: UL, 2: Guard
    uint8_t reserved[2];
} SLOTCONFIGStruct, *PSLOTCONFIGStruct;

typedef struct tCsiPart2SizeMap
{
    uint16_t   nPart2Size[MAX_SIZE_CSI_PART2_MAP];      //Array indicating the uci Part2 size, as a function the part1
}tCsiPart2SizeMapStruct;

//ORAN config info, 36 bytes
typedef struct ORANRFCfg_tag
{
    uint8_t nRUPortNum;                  /* the number of RU used eth points. 1 or 2*/
    uint8_t nCCID;                       /* vaulue 0 - 15. use for multi carrier per Radio*/
    uint8_t RadioTypeIndex;              /* which can detail the radio configuration in future, eg: cata-a, cata-b, … detail compression, PRPCH… in xml file */
    uint8_t nRsv[3];

    uint16_t TadvCpDl;                   /* cp adv up time in microsecond */
    uint16_t T1aMaxCpDl;                 /* the max t1a time value in microsecond ,for downlink cp message. for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t T1aMinCpDl;                 /* the min t1a time value in microsecond ,for downlink cp message. for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t T1aMaxCpUl;                 /* the max t1a time value in microsecond ,for uplink cp message. for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t T1aMinCpUl;                 /* the min t1a time value in microsecond ,for uplink cp message. for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t T1aMaxUp;                   /* the max t1a time value in microsecond ,for downlink up message. for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t T1aMinUp;                   /* the min t1a time value in microsecond ,for downlink up message. for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t Ta4Max;                     /* the max ta4 time value in microsecond . for value 0, this field is not vaild,use default config in the xml.*/
    uint16_t Ta4Min;                     /* the min ta4 time value in microsecond . for value 0, this field is not vaild,use default config in the xml.*/
    uint8_t nSrcPrimMacAddress[6];     /* the major mac addr of the local VF. */
    uint8_t nSrcSecMacAddress[6];      /* the secondary mac addr of the local VF,is used only for nRUPortNum is 2. */
    uint8_t nRFDesPrimMacAddress[6];     /* the major mac addr of the RU. */
    uint8_t nRFDesSecMacAddress[6];      /* the secondary mac addr of the RU,is used only for nRUPortNum is 2. */
} ORANRFCfgStruct, *PORANRFCfgStruct;


// Payload for MSG_TYPE_PHY_CONFIG_REQ message
typedef struct tConfigReq
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    /*Serving Cell  index in the given sector,Value: 0->15*/
    uint8_t      nCarrierIdx;
    /*dmrs-TypeA-Position    2 : pos2, 3: pos3*/
    uint8_t      nDMRSTypeAPos;
    /*Cell ID for this carrier*/
    uint16_t     nPhyCellId;

    /**** word 3,4 *****/
    /*RF config*/
    /*absolute Frequency of  pointA in KHz
     Value: 450000->52600000*/
    uint32_t     nDLAbsFrePointA;
    uint32_t     nULAbsFrePointA;

    /**** word 5 *****/
    /*Carrier bandwidth for DL in MHz
    Value: 5->400*/
    uint16_t     nDLBandwidth;
    uint16_t     nULBandwidth;

    /**** word 6 *****/
    /* ifft/fft size for DL and UL
    Value: 512, 1024, 2048, 4096 */
    uint16_t     nDLFftSize;
    uint16_t     nULFftSize;

    /**** word 7 *****/
    /*SSB config*/
    /*SSB block powerValue :1->110000,0.001 dB step, -60 to 50 dB offset to default value*/
    uint32_t     nSSBPwr;
    /*absoluteFrequencySSB in KHz*/
    uint32_t     nSSBAbsFre;

    /**** word 9-11 *****/
    /*SSB periodicity in msec, Value:0->5
    0: ms5,   1: ms10    2: ms20
    3: ms40   4: ms80    5: ms160 */
    uint8_t      nSSBPeriod;
    /*SS/PBCH block Subcarrier spacing, Value :0->4
    0: Case A 15kHz, 1: Case B 30kHz
    2: Case C 30kHz, 3: Case D 120kHz
    4: Case E 240kHz*/
    uint8_t      nSSBSubcSpacing;
    /*ssb-subcarrierOffset  */
    uint8_t      nSSBSubcOffset;
    /*ssb-PrbOffset  */
    uint8_t      nSSBPrbOffset;
    /*MIB content*/
    uint8_t      nMIB[3];
    /*L1 parameter k0 for DL(see 38.211, section 5.3.1) */
    uint8_t      nDLK0;
    uint8_t      nULK0;
    uint8_t      rsv1[3];
    /**** word 12,13 *****/
    /*Bitmap for actually transmitted SSB. */
    uint32_t     nSSBMask[2];

    /**** word 14 *****/
    /*Number of transmission antennas*/
    uint8_t      nNrOfTxAnt;
     /*Number of receiving antennas */
    uint8_t      nNrOfRxAnt;

    /* Max Number of transmission ports (1 - 16) */
    uint8_t      nNrOfDLPorts;
    /* Max Number of receiving Virtual ports (1 - 16). There maybe more than 1 virtual port mapped to a physical port transmitted by UE */
    uint8_t      nNrOfULPorts;

    /**** word 15 *****/
    /*Number of total carriers present*/
    uint8_t      nCarrierAggregationLevel;
    /*Frame Duplex type:  0 -> FDD, 1 -> TDD*/
    uint8_t      nFrameDuplexType;
    /*subCarrierSpacingCommon = numerology, Value: 0 -> 4 */
    /* 0 : 15kHz, 1: 30kHz, 2: 60khz, 3: 120khz, 4:240khz */
    uint8_t      nSubcCommon;
    /* TDD Period - If nFrameDuplexType = TDD(1), then this config defines the TDD periodicity */
    uint8_t      nTddPeriod;

    /**** word 16 - 336 *****/
    /* TDD Slot configuration - If nFrameDuplexType = TDD(1), then this config defines the slot config type for each slot.*/
    /* The number of slots need to be equal to nTddPeriod */
    SLOTCONFIGStruct sSlotConfig[MAX_TDD_PERIODICITY];

    /**** word 337 - 433 *****/
    /*According to SSB Mask, beam index filled. For example, if SSB mask bit 26 set to 1, then nBeamId[26] will be used to indicate beam ID of SSB 26.
    value: 0~63*/
    uint8_t nBeamId[MAX_NUM_ANT_NR5G];
    /*According to nBeamId[MAX_NUM_ANT_NR5G], if nBeamId[26] is used, nNrofTxRUPerBeam[26] indicates the number of TxRU.
    Value: 1~4*/
    uint8_t nNrofTxRUPerBeam[MAX_NUM_ANT_NR5G];
    /*TxRU index for SSB beam, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3
    value:0~15*/
    uint8_t nTxRUIdx[MAX_NUM_ANT_NR5G][MAX_TXRU_NUM];

    /**** word 434 *****/
    /* PRACH config*/
    /*PRACH Configuration Index, vale = 0 to MAX_PRACH_CONFIG_IDX */
    uint8_t      nPrachConfIdx;
    /*PRACH Subcarrier spacing
    Value:0->4
    0: 15KHz, 1: 30KHz, 2: 60KHz, 3: 120KHz, 4: 1.25KHz
    For below 6GHz the values indicate 15kHz or 30kHz or 1.25KHz
    For above 6GHz the values indicate 60kHz or 120kHz*/
    /*PRACH subcarrier spacing */
    uint8_t      nPrachSubcSpacing;
    /*PRACH zeroCorrelationZoneConfig, value = 0 to MAX_PRACH_ZERO_ZONE_CONFIG */
    uint8_t      nPrachZeroCorrConf;
    /*PRACH restrictedSetConfig, value = 0 or 1 */
    uint8_t      nPrachRestrictSet;

    /**** word 435 *****/
    /*PRACH Root Sequence Index, value = 0 to MAX_PRACH_ROOT_SEQ_IDX */
    uint16_t     nPrachRootSeqIdx;
    /*PRACH prach-frequency-start  (in RBs)*/
    uint16_t     nPrachFreqStart;

    /**** word 436 *****/
    /*PRACH-FDM Range: 1->8*/
    uint8_t      nPrachFdm;
    /*PRACH SSB-per-rach-occasion  */
    uint8_t      nPrachSsbRach;
    /* Number of Prach RxRU value:1~4*/
    uint8_t      nPrachNrofRxRU;
    /*0 for normal, 1 for extended cyclic prefix*/
    uint8_t      nCyclicPrefix;

    /**** word 437 *****/
    /* group hopping flag, Value: 0 or 1*/
    uint8_t    nGroupHopFlag;
    /* sequence hopping flag, Value: 0 or 1 */
    uint8_t    nSequenceHopFlag;
    /* nID used for group and sequence hopping[38.211&6.3.2.2.1]Valid for format 0,1,3,4, Value:0~1023*/
    uint16_t   nHoppingId;

    /**** word 438 *****/
    /* If 1, then this cell is a URLLC cell */
    uint16_t   nUrllcCapable;
    /* Bit Mask (14 Bits) which indicate which symbol numbers to send SLOT_IND to L2 */
    uint16_t   nUrllcMiniSlotMask;

    /**** word 439 - 448 *****/
    /* Radio management Info */
    uint8_t RFInfoVal; /* RU configure vaild flag. 0: not vaild; 1: the ru configure vaild */
    uint8_t rsv[3];
    ORANRFCfgStruct stOranCfgInfo; /* only used when the RFInfoVal field is 1*/


    /**** word 449 *****/
    /* Number of UCI maps indicating how a set of UCI part1 parameters map to a length of a corresponding UCI part2 */
    uint16_t   nUci2Maps;
    uint8_t nNrOfDLCSIRSPorts;
    uint8_t    rsv2[1];

    /**** word 450 - 2498 *****/
    /* UCI maps csi-part1 params -> csi-part2 size. Array dimension is nUci2Maps */
    /* this empty array should be the last in CONFIGREQUESTStruct */
    tCsiPart2SizeMapStruct  sPart2SizeMap[];

} CONFIGREQUESTStruct, *PCONFIGREQUESTStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for PHY_CONFIG_RESP message
typedef struct tConfigInd
{
    L1L2MessageHdr sMsgHdr;
    /*Serving Cell  index in the given sector,Value: 0->15*/
    uint8_t        nCarrierIdx;
    uint8_t        nStatus; // MSG_OK or MSG_INVALID_STATE or MSG_INVALID_CONFIG
    uint8_t        rsv1[2];
} CONFIGRESPONSEStruct, *PCONFIGRESPONSEStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_START_REQ message
typedef struct tStartReq
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint32_t nMode;             // 0 = Radio (non-oran compliant), 1 = timer mode, 4 = Radio (oran/xran compliant)
    uint32_t nCount;
    uint32_t nPeriod;
} STARTREQUESTStruct, *PSTARTREQUESTStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_START_RESP message
typedef struct tStartResponseStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint8_t      nStatus;
    uint8_t      rsv1[3];
} STARTRESPONSEStruct, *PSTARTRESPONSEStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_STOP_REQ message
typedef struct tStopRequestStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
} STOPREQUESTStruct, *PSTOPREQUESTStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_STOP_RESP message
typedef struct tStopResponseStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint8_t      nStatus;
    uint8_t      rsv1[3];
} STOPRESPONSEStruct, *PSTOPRESPONSEStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_SHUTDOWN_REQ message
typedef struct tShutdownRequestStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint32_t nTestType;
} SHUTDOWNREQUESTStruct, *PSHUTDOWNREQUESTStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_SHUTDOWN_REQ message
typedef struct tShutdownResponseStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint32_t nStatus;
} SHUTDOWNRESPONSEStruct, *PSHUTDOWNRESPONSEStruct;

//------------------------------------------------------------------------------------------------------------
// Structures for MSG_TYPE_PHY_CELL_INFO_REQ message
typedef struct tCellInfoPdu
{
    uint16_t nNumPdsch;
    uint16_t nNumPdcch;
    uint16_t nNumPbch;
    uint16_t nNumCsiRs;
    uint16_t nNumPusch;
    uint16_t nNumPuschUci;
    uint16_t nNumPucch;
    uint16_t nNumSrs;
    uint16_t nNumPrach;
    uint32_t nPdschTput;   // in bytes / TTI
    uint32_t nPuschTput;   // in bytes / TTI
    uint32_t nTotalPdschRBs;
    uint32_t nTotalPuschRBs;
    uint16_t nPdschLayers;
    uint16_t nPuschLayers;
} CellInfoPdu, *PCellInfoPdu;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_EXIT_REQ message
typedef struct tExitRequestStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
} EXITREQUESTStruct, *PEXITREQUESTStruct;

//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_CELL_INFO_REQ message
typedef struct tCellInfoRequestStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint32_t nNumCells;

    // CellInfoPdu for multiple(nNumCells) Cells.
    CellInfoPdu    sCellInfoPDU[];
} CELLINFOREQUESTStruct, *PCELLINFOREQUESTStruct;

//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_ERR_IND message
typedef struct tErrorIndicationStruct
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint8_t      nStatus;
    uint8_t      rsv1[3];
} ERRORIndicationStruct, *PERRORIndicationStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_SLOT_IND message
typedef struct tPhyMsgSlotInd
{
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
} SlotIndicationStruct, *PSlotIndicationStruct;

/*PDU header*/
/*PDUStruct is a kind of TLV structure. the length is variable , depends on different PDU type*/
/*The PDU content resides right after the item nPDUSize, in the specific, it starts from 5th bytes in this structure */
/*The nPDUType of next PDU can be got at the adress calculated by previous PDU address plus an offset nPDUSize*/
typedef struct tPduStruct
{
    uint16_t nPDUType;
    uint16_t nPDUSize;//Size of the PDU control information (in bytes). This length value includes the 4 bytes required for the PDU type and PDU size parameters.
} PDUStruct, *PPDUStruct;

//------------------------------------------------------------------------------------------------------------
// MSG_TYPE_PHY_OAM_REQ message
typedef struct tPhyOAMReqMsg {
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint8_t        nPDU;    /** Number of PDUs that are included in this message., */
    uint8_t        resv[3];
    PDUStruct      sPDUHdr[]; /** nr5gMacPhyOAMReqType values are supported in sPDUHdr->nPDUType **/
} PHY_OAM_REQ_MSG, *PPHY_OAM_REQ_MSG;

//------------------------------------------------------------------------------------------------------------
// nPDUType NR5G_MAC_PHY_OAM_MANAGE_LBM
typedef struct tPhyOAMReq_ManageLBMPDU {
    PDUStruct      sPDUHdr;
    uint8_t   vfId;      /** VF-ID to disable LBM for */
    uint8_t   lbmEnable; /** 0/1 Disable/Enable LBM **/
    uint8_t   resv[2];
} PHY_OAM_REQ_MANAGE_LBM_PDU, *PPHY_OAM_REQ_MANAGE_LBM_PDU;

//------------------------------------------------------------------------------------------------------------
// nPDUType NR5G_MAC_PHY_OAM_FETCH_PM_STATS
typedef struct tPhyOAMReq_FetchPMStatsPDU {
    PDUStruct      sPDUHdr;
    uint8_t   ruID;    /** RU ID to fetch PM stats for **/
    uint8_t   resv[3];
} PHY_OAM_REQ_FETCH_PM_STATS_PDU, *PPHY_OAM_REQ_FETCH_PM_STATS_PDU;

//------------------------------------------------------------------------------------------------------------
// MSG_TYPE_PHY_OAM_RESP message
typedef struct tPhyOAMRespMsg {
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint8_t        nPDU;    /** Number of PDUs that are included in this message */
    uint8_t        resv[3];
    PDUStruct      sPDUHdr[]; /** nr5gMacPhyOAMRespType values are supported in nPDUType of sMsgHdr*/
} PHY_OAM_RESP_MSG, *PPHY_OAM_RESP_MSG;

//------------------------------------------------------------------------------------------------------------
// NR5G_MAC_PHY_OAM_MANAGE_LBM message
typedef struct tPhyOAMRespLBMManagePDU {
    PDUStruct      sPDUHdr;
    uint8_t   vfId;   /** VF-ID response sent for */
    uint8_t   status; /** Status of the OAM request 0/1 Success/Fail */
    uint8_t   resv[2];
} PHY_OAM_RESP_LBM_MANAGE_PDU, *PPHY_OAM_RESP_LBM_MANAGE_PDU;

//------------------------------------------------------------------------------------------------------------
// NR5G_MAC_PHY_OAM_FETCH_PM_STATS message
typedef struct tPhyOAMRespPMCountersPDU{
    PDUStruct      sPDUHdr;
    uint8_t   ruID;           /** O-RU ID PM stats fetched for */
    uint8_t   status;         /* Status of the OAM request 0/1 Success/Fail */
    uint8_t   resv[2];
    uint32_t  xRANpktsOnTime; /** PM stats */
    uint32_t  xRANpktsEarly;  /** PM stats */
    uint32_t  xRANpktsLate;   /** PM stats */
} PHY_OAM_RESP_PM_COUNTERS_PDU, *PPHY_OAM_RESP_PM_COUNTERS_PDU;

// MSG_TYPE_PHY_OAM_NOTIFICATION message
typedef struct tPhyOAMNotifyMsg {
    L1L2MessageHdr sMsgHdr;
    SFN_SlotStruct sSFN_Slot;
    uint8_t        nPDU;    /** Number of PDUs that are included in this message */
    uint8_t        resv[3];
    PDUStruct      sPDUHdr[]; /** nr5gMacPhyOAMMotificationType values are supported in nPDUType of sMsgHdr*/
} PHY_OAM_NOTIFY_MSG, *PPHY_OAM_NOTIFY_MSG;

//------------------------------------------------------------------------------------------------------------
// NR5G_MAC_PHY_OAM_NOTIFY_LBM_LINK_STATUS_CHANGE message
typedef struct tPhyOAMNotifyLBMLinkStatusPDU {
    PDUStruct      sPDUHdr;
    uint8_t vfId;   /** VF-ID response sent for */
    uint8_t prevState;
    uint8_t currState;
    uint8_t resv;
} PHY_OAM_NOTIFY_LBM_LINK_STATUS_PDU, *PPHY_OAM_NOTIFY_LBM_LINK_STATUS_PDU;

typedef struct tPhyOAMNotifyErrorPDU {
    PDUStruct      sPDUHdr;
    uint8_t nErrorType;   /* Error Type, defined in nr5gMacPhyOAMMotificationErrType  */
    uint8_t ErrorCode; /*error code*/
    uint8_t ModelID; /* Model who generates this error */
    uint8_t SequenceID; /* unit Id, easy to find where this error generated in code from l1 */
    char    errorInf[512];/* string */
} PHY_OAM_NOTIFY_Error_PDU, *PPHY_OAM_NOTIFY_Error_PDU;


//------------------------------------------------------------------------------------------------------------
// Structures for BeamMatrix
typedef struct
{
    int8_t  nType;/*0:pmi based mimo 1:srs algo1 based mimo , or any others*/
    int8_t  nMatrixBeamID; /* 0:L1 create beamID with matrix input,1: use both beamId and matrix input, 2: use beamID only without matrix*/
    int8_t  nrsv[2];
    int16_t nNumPRG;/* the number of Matrix pre layer,
                       when wideband nNumPRG is 1
                       when subband,
                            if pdsch rb allocation used type 0, the nNumPRG need same as the number RBG(nRPG) which is scheduled
                            if pdsch rb allocation used type 1, nPRG is alloc start the floor(rbstart/nPRGSize)*nPRGSize rb*/
    int16_t nPRGSize;/* number of prb for bundling.
                      if pdsch rb allocation used type 0, it needs to equal the nRBG size */
    int16_t *pMatrixBeamID; /* pMatrixBeamID is a physical address
                               NULL if nMatrixBeamID = 0 ,
                               point to the buffer i16MatrixBeamID[nNrOfLayers][nNumPRG]
                               nNumPRG is  the number of Matrix pre layer,
                                nNrOfLayers is the layer number of pdsch*/
    int32_t *pMatrixBuff; /* pMatrixBuff is a physical address,
                             point to 32bit data buffer(16bits real + 16bits image) ,
                             point to the buffer u32MatrixBuff[nNrOfLayers][nNumPRG][AntEle],
                             AntEle is the ant number of DLlink
                             nNumPRG is  the number of Matrix pre layer,
                             nNrOfLayers is the layer number of pdsch*/
} BeamMatrixStruct, *PBeamMatrixStruct;

// Structures for MSG_TYPE_PHY_DL_CONFIG_REQ message
typedef struct tDlSchPdu
{
    /**** word 1 *****/
    PDUStruct sPDUHdr;

    /**** word 2 *****/
    uint16_t  nRNTI;                            // The RNTI used for identifying the UE when receiving the PDU,Value: 1 -> 65535.
    uint16_t  nUEId;                            // UE index in the sector,Value:0 -> 1199

    /**** word 3 *****/
    uint16_t  nBWPSize;                         // bandwidth part size,Value: 20->275
    uint16_t  nBWPStart;                        // bandwidth part start RB index,Value: 0->254

    /**** word 4 *****/
    uint8_t   nSubcSpacing;                     // subcarrierSpacing value:0->4
    uint8_t   nCpType;                          // Cyclic prefix type  0: Normal; 1: Extended
    uint8_t   nMcsTable;                        // MCS-Table-PDSCH0: not set to '256QAM' 1: set to '256QAM'
    uint8_t   nNrOfCodeWords;                   // Up to 2 codewords,Value: 1 -> 2

    /**** word 5 *****/
    uint8_t   nMCS[MAX_DL_PER_UE_CODEWORD_NUM]; // MCS index value: 0->31
    uint8_t   nRV[MAX_DL_PER_UE_CODEWORD_NUM];  // Redundancy version,Value : 0->3

    /**** word 6 *****/
    uint8_t   nNDI[MAX_DL_PER_UE_CODEWORD_NUM]; // New data indication,0: retransmission,1: new data
    uint8_t   nNrOfLayers;                      // Layer number,Value : 1->8,single user, up to 8 layers,multi-user, up to 4 layers
    uint8_t   nNrOfAntennaPorts;                // Number of antenna ports Value : 1->8,

    /**** word 7, 8 *****/
    uint32_t  nTBSize[MAX_DL_PER_UE_CODEWORD_NUM];    // transmit block size (in bytes)

    /**** word 9, 10 *****/
    uint8_t   nPortIndex[MAX_DL_REAL_PORTS];// 0: port 1000,1: port 1001 . 11: port 1011

    /**** word 11 *****/
    uint8_t   nHARQID;           //HARQ Process number, 0->15
    uint8_t   nSCID;             // For DMRS generatio Value : 0->1
    uint16_t  nNIDnSCID;         // DL-DMRS-Scrambling-ID, For DMRS generation Value : 0->65535

    /**** word 12 *****/
    uint8_t   nVRBtoPRB;         // VRB-to-PRB-mapping 0: non-interleaved VRB-to-PRB mapping 1: interleaved VRB-to-PRB mapping
    uint8_t   nRBBundleSize;     // Resource block bundle size L, refer to section 7.3.1.6 in [2]
    uint8_t   nStartSymbolIndex; // start symbol index of PDSCH mapping Value: 0, 2 or 3 for PDSCH mapping type A:  [2 or 3] for PDSCH mapping type B:  [0]
    uint8_t   nNrOfSymbols;      // PDSCH duration in symbols Value: 1->14

    /**** word 13 *****/
    uint16_t  nRBStart;          //For resource allocation type 0.The starting resource block for this ULSCH allocation.
    uint16_t  nRBSize;           //For resource allocation type 0.The number of resource block allocated to this DLSCH grant.,This should match the value sent in the DL DCI,PDU which allocated this grant.

    /**** word 14 *****/
    uint8_t   nResourceAllocType;//resource allocation type,0: type 0,1: type 1
    uint8_t   nNrOfRBGs;         //For resource allocation type 1.Number of RBGs
    uint8_t   nRBGSize;          //For resource allocation type 1.RBG size,Value: 2,4,8,16
    /* DMRS reference point for k, 38.211 7.4.1.1.2 */
    uint8_t   nRefPoint;         // 0 - refence point is subcarrier 0 in common resource block 0, 1 - refence point is subcarrier 0 of the lowest-numbered resource block in CORESET 0


    /**** word 15 *****/
    uint32_t  nRBGIndex;//For resource allocation type 0.RBG index allocated for this DLSCH. The maximum number is 138 with 275 RBs and RBG size 2.

    /**** word 16 *****/
    uint8_t   nMappingType;      // PDSCH mapping Type, 0: mapping type A, 1: mapping type B
    uint8_t   nDMRSConfigType;   // DL DMRS config type,0: type 1,1: type2
    uint8_t   nNrOfCDMs;         // Number of DM-RS CDM groups without data
    uint8_t   nNrOfDMRSSymbols;  // DL DMRS symbol number,1: single symbol,2: double symbol

    /**** word 17 *****/
    uint8_t   nDMRSAddPos;       // DL additional DMRS position,DL-DMRS-add-pos,Value: 0->3
    uint8_t   nPTRSPresent;      // DL-PTRS-present,0: PT-RS is not present,1: PT-RS is present
    uint8_t   nNrOfPTRSPorts;    // Up to 2 ports,DL-PTRS-ports.Value: 1->2
    uint8_t   nPTRSTimeDensity;  // PT-RS time density,Value: 0,1, 2 or 4,0 means PT-RS is not present

    /**** word 18 *****/
    uint8_t   nPTRSPortIndex[MAX_DL_PER_UE_PTRS_PORT_NUM];  //0: port 1000,1: port 1001. 11: port 1011
    uint8_t   nNrOfDMRSAssPTRS[MAX_DL_PER_UE_PTRS_PORT_NUM];//The number of DM-RS ports associated to PT-RS  Value: 1->6

    /**** word 19 *****/
    uint8_t   nPTRSFreqDensity;         // PT-RS frequency density,Value: 0, 2 or 4,0 means PT-RS is not present
    uint8_t   nPTRSReOffset;            // DL-PTRS-RE-offset,
    uint8_t   nEpreRatioOfPDSCHToPTRS;
    uint8_t   nMMimoMode;               // 0->non Massive Mimo PDU, 1-> beamID + matrix mode,wideband+subband,  Beam Matrix generated by L1 , 2-> beamID + matrix mode, wideband+subband, Beam Matrix generated by L2

    /**** word 20 *****/
    uint8_t   nTransmissionScheme;      // 0: static precoder; 1: codebook-based transmission
    uint8_t   nCodebookType;            // 0: single-panel type1;1: multi-panel type1;2: type2;3: port selection port2;
    uint8_t   nCodebookMode;            // 0: codebook mode 1; 1: codebook mode 2
    uint8_t   nPMI;                     // pmi, maximun 63 for 4 ports Tx

    /**** word 21 *****/
    uint16_t  n1n2;                     // n1_n2=n1<<8+n2,n1 n2 values are according to table 5.2.2.2.1-2 in 38.214
    uint16_t  nEpreRatioOfDmrsToSSB;    // ratio of PDSCH EPRE to DMRS EPRE,Value :1->20000,0.001 dB step, -6dB to 14 dB

    /**** word 22 *****/
    uint16_t   nNid;                    // Data-scrambling-IdentityValue : 0->1023
    uint8_t    nRev;
    /*Number of TxRU value:1~4*/
    uint8_t    nNrofTxRU;

    /**** word 23 *****/
    /*ratio of PDSCH EPRE to DATA EPRE,Value :1->20000,0.001 dB step, -6dB to 14 dB */
    uint16_t   nEpreRatioOfPDSCHToSSB;
    /* Bit ID for SRS Chan Est ports to be for beam weight generation.  bit0=port0, bit1=port1, bit2=port2, bit3=port3 */
    uint8_t    nPortInfoBitMap;
    /* SRS Channel Estimation Buffer Index to be used for beam weight generation */
    uint8_t    nSRSChanEstBufferIndx;

    /**** word 24 *****/
    uint8_t    nWeightnorm;
    uint8_t    npadding[3];

    /**** word 25 *****/
    /*TxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~15*/
    uint8_t    nTxRUIdx[MAX_DL_REAL_PORTS];

    /**** word 26 ****/
    /* TBSlbrm 3GPP TS38.212, section 5.4.2-1 unit (bit)*/
    uint32_t    nTBSlbrm;

    /**** word 27-28 ****/
    /* beamID table, only for nMMimoMode = 0 */
    int16_t  nBeamId[MAX_TXRU_NUM];

    /**** word 29 *****/
    uint32_t  nRsvForBeamMatrixStruct;// for stBeamMatrixInfo 8 bytes alain !!!!!

    /**** word 30-35 ****/
    /* valid when nMMimoMode = 1 or nMMimoMode = 2 */
    BeamMatrixStruct stBeamMatrixInfo;

} DLSCHPDUStruct, *PDLSCHPDUStruct;

typedef struct tDciPduStruct
{
    /**** word 1 *****/
    PDUStruct    sPDUHdr;

    /**** word 2 *****/
    uint16_t     nRNTI;
    uint16_t     nBWPSize;

    /**** word 3 *****/
    uint16_t     nBWPStart;
    uint8_t      nSubcSpacing;   // subcarrierSpacing value:0->4
    uint8_t      nCpType;        // Cyclic prefix type  0: Normal; 1: Extended

    /**** word 4, 5 *****/
    /*CORESET-freq-dom */
    /*The bits of the bitmap have a one-to-one mapping with non-overlapping groups of 6 PRBs*/
    /*The maximum number is 45 with 275/6.*/
    uint32_t     nFreqDomain[2];

    /**** word 6 *****/
    /*Starting OFDM symbol for the CORESET*/
    /*Value: 0-13*/
    uint8_t      nStartSymbolIndex;
    /*Contiguous time duration of the CORESET in number of symbols*/
    uint8_t      nNrOfSymbols;
    /*CORESET-CCE-to-REG-mapping-type*/
    /*0: non-interleaved CCE-to-REG mapping*/
    /*1: interleaved CCE-to-REG mapping*/
    uint8_t      nCCEToREGType;
    /*CORESET-REG-bundle-size, Variable R in section 7.3.2.3 [2]*/
    /*Value: 2,3,6*/
    uint8_t      nREGBundleSize;

    /**** word 7 *****/
    /*CORESET-shift-index*/
    /*Value: 0->273*/
    uint16_t     nShift;
    /*PDCCH-DMRS-Scrambling-ID ????*/
    uint16_t      nScid;

    /**** word 8 *****/
    uint8_t      nCCEStartIndex;
    uint8_t      nAggrLvl;
    /*CORESET-interleaver-size*/
    /*Value: 2,3,6*/
    uint8_t      nInterleaveSize;
    uint8_t      nCoreSetType;

    /**** word 9 *****/
    /*for scrmbling*/
    uint16_t      nRNTIScramb;
    /*The total DCI length including padding bits*/
    uint16_t      nTotalBits;

    /**** word 10 *****/
    /*PDCCH data EPRE*/
    uint16_t     nEpreRatioOfPDCCHToSSB;
    /*PDCCH DMRS EPRE*/
    uint16_t     nEpreRatioOfDmrsToSSB;

    /**** word 11-18 *****/
    /*The total DCI length including padding bits*/
    uint8_t      nDciBits[MAX_DCI_BIT_BYTE_LEN];

    /**** word 19 *****/
    uint8_t      nRsv0;
    /*According to nBeamId[64], if nBeamId[26] is used, nNrofTxRUPerBeam[26] indicates the number of TxRU Value: 1~4*/
    uint8_t      nNrofTxRU;
    /* nID range 0 to 65535, equals the higher-layer parameter pdcch-DMRS-ScramblingID if configured. otherwise equal to Cell ID*/
    uint16_t     nID;

    /**** word 20 *****/
    /* TxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 Value:0~15 */
    uint8_t      nTxRUIdx[MAX_TXRU_NUM];

    /**** word 21 *****/
    int16_t      nBeamId;/* beamID for DCI. Value:0~4095*/
    int16_t      nRsv1;

} DCIPDUStruct, *PDCIPDUStruct;

typedef struct tUeManagementPduStruct
{
    /**** word 1 *****/
    PDUStruct  sPDUHdr;

    /**** word 2 *****/
    uint16_t   nRnti;       /* RNTI for UE whose SRS buffers and context to be cleared */
    uint16_t   nRsv;
} UEMANAGEMENTPDUStruct,*PUEMANAGEMENTPDUStruct;

typedef struct  tSrsPduStruct
{
    /**** word 1 *****/
    PDUStruct  sPDUHdr;

    /**** word 2 *****/
    uint16_t   nRNTI;                   /* The RNTI used for identifying the UE when receiving the PDU,Value: 1 -> 65535. */
    uint16_t   nUEId;                   /* UE index in the sector,Value:0 -> 1199 */

    /**** word 3 *****/
    uint16_t   nBWPSize;                /* bandwidth part size,Value: 20->275 */
    uint16_t   nBWPStart;               /* bandwidth part start RB index,Value: 0->254 */

    /**** word 4 *****/
    uint8_t    nSubcSpacing;            /* subcarrierSpacing value:0->4 */
    uint8_t    nCpType;                 /* Cyclic prefix type  0: Normal; 1: Extended */
    uint8_t    nStartPos;               /* Starting position in time domain, l_offset, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 5 */
    uint8_t    nNrOfSymbols;            /* Number of SRS symbols, Value: 1 ,2 ,4 */

    /**** word 5 *****/
    uint8_t    nComb;                   /* Transmission Comb, KTC , 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 2, 4 */
    uint8_t    nCombOffset;             /* Comb Offset, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 3 */
    uint8_t    nNrOfSrsPorts;           /* port number could be {1,2,4} */
    uint8_t    nCyclicShift;            /* Cyclic Shift, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 11 */

    /**** word 6 *****/
    uint8_t    nBsrs;                   /* b-SRS, SRS bandwidth index, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 3 */
    uint8_t    nCsrs;                   /* c-SRS, SRS bandwidth config index, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 63 */
    uint8_t    nBHop;                   /* b-hop, freqHopping, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 3 */
    uint8_t    nHopping;                /* groupOrSequenceHopping, value:0->2, 0: neither, 1: groupHopping, 2: sequenceHopping */

    /**** word 7 *****/
    uint8_t    nFreqPos;                /* RRC Config message, SRS-Resource.freqDomainPosition, n_rrc  value: 0 -> 67 */
    uint8_t    nResourceType;           /* 0: aperiodic, 1: semi-persistent, 2: periodic */
    uint16_t   nFreqShift;              /* RRC config message, SRS-Resource.freqDomainShift, nShift   value: 0 -> 268 */

    /**** word 8 *****/
    uint16_t   nSrsId;                  /* RRC Config message, SRS-Resource.sequenceID, nSRSid srs sequence identity is assigned by high layer,  value = 0->1023 */
    uint8_t    nRepetition;             /* repetitionFactor, Value: 1 ,2 ,4 */
    uint8_t    rsv1;

    /**** word 9 *****/
    uint16_t   nTsrs;                   /* SRS-Periodicity in slots, of type 'periodicityAndOffset-p' RRC Config Message */
                                        /* Values = 1,2,4,5,8,10,16,20,32,40,64,80.160,320,640,1280,2560 */
    uint16_t   nToffset;                /* SRS-Periodicity offset in slots, of type 'periodicityAndOffset-p' RRC Config Message */
                                        /* Values = 0 -> (nTsrs - 1), for example, if nTsrs = 160, valid value = 0 -> 159 */
    /**** word 10 *****/
    uint8_t    nrsv0;
    /* Number of RxRU value:1~32*/
    uint8_t    nNrofRxRU;
    /* Bit ID for SRS ports to be updated.  bit0=port0, bit1=port1, bit2=port2, bit3=port3 */
    uint8_t    nPortInfoBitMap;
    uint8_t    rsv2[1];

    /**** word 11 *****/
    /*RxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~31*/
    uint8_t    nRxRUIdx[MAX_RX_SRS_STREAM_NUM];

    /**** word 10 - 25 *****/
    int16_t     nBeamId[MAX_RX_SRS_STREAM_NUM];/* Beamid table for each SRS iq stream */
}SRSPDUStruct,*PSRSPDUStruct;

typedef struct  tPrachPduStruct
{
    /**** word 1 *****/
    PDUStruct  sPDUHdr;

    /**** word 2 *****/
    /* Number of PRACH occasion per slot.   Value: 1~7,according to spec, max to 7 PRACH occasions per slot */
    uint8_t     nNrofPrachOcas;
    /* Number of beams per PRACH Occasion.  Value: from 1 to 4 */
    uint8_t     nNrofBeamPerOcas;
    uint8_t     rsv[2];

    /**** word 3 *****/
    /* Beam index per slot, MAX_PANEL_NUM is set to 4.  Value: from 0 to 63 */
    uint8_t     nBeamIdPerSlot[MAX_PANEL_NUM];

    /**** word 4 *****/
    /* RxRU number per beam.  Value: from 1 to 4 */
    uint8_t     nNrofRxRuPerBeam [MAX_PANEL_NUM];

    /**** word 5 -> 8*****/
    /*RxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~15*/
    uint8_t     nRxRUIdx[MAX_PANEL_NUM][MAX_RXRU_NUM];
}PRACHPDUStruct,*PPRACHPDUStruct;

typedef struct tDlBchPdu
{
    /**** word 1 *****/
    PDUStruct  sPDUHdr;

    /**** word 2 *****/
    /*ssb-subcarrierOffset  value: 0->23*/
    uint8_t      nSSBSubcOffset;
    /*ssb-PrbOffset  */
    uint8_t      nSSBPrbOffset;
    uint8_t      nrsv[2];

    /**** word 3 *****/
    /* MIB payload */
    uint8_t      nMIB[3];
    /* value： 0,1, refer to spec 213, 4.1 chapter, if =0, 0dB, if =1, 3dB */
    uint8_t      nPssEpreOffset;

    /**** word 4 *****/
    /*Beam index value:0~63*/
    /*max support 4 ssb with ssb beamid in one slot if ssb scs == common scs + 1*/
    int16_t    nBeamId[4];

} BCHPDUStruct, *PBCHPDUStruct;

typedef struct tCsiRsPduStruct
{
    /**** word 1 *****/
    PDUStruct    sPDUHdr;

    /**** word 2 *****/
    uint16_t     nBWPStart;
    uint16_t     nBWPSize;

    /**** word 3 *****/
    uint8_t      nSubcSpacing;   // subcarrierSpacing value:0->4
    uint8_t      nCpType;        // Cyclic prefix type  0: Normal; 1: Extended
    uint16_t     nStartRB;       // PRB where this CSI resource starts, Only multiples of 4 are allowed

    /**** word 4 *****/
    uint16_t     nNrOfRBs;       // Number of PRBs across which this CSI resource spans. Only multiples of 4 are allowed
    /*0:TRS 1:CSI-RS 2:CSI-IM NZP 3:CSI-IM ZP*/
    uint8_t      nCSIType;
    /*The row in table 7.4.1.5.3-1 of 38.211 Value: 1-18*/
    uint8_t      nRow;

    /**** word 5 *****/
    /*frequencyDomainAllocation*/
    uint16_t     nFreqDomain;
    uint8_t      nNrOfPorts;
    /*cdm-Type 0: noCDM, 1: fd-CDM2, 2: cdm4-FD2-TD2, 3: cdm8-FD2-TD4*/
    uint8_t      nCDMType;

    /**** word 6 *****/
    /*firstOFDMSymbolInTimeDomain*/
    uint8_t      nSymbL0;
    uint8_t      nSymbL1;
    /*CSI-RS-Density 0: dot5, 1: one, 2: three*/
    uint8_t      nFreqDensity;
    /*RB level comb offset only if CSI-RS-Density Is dot5 0: even RB , 1: odd RB*/
    uint8_t      nCombOffset;

    /**** word 7 *****/
    /*ScramblingID */
    uint16_t     nScrambId;
    /*powerControlOffsetSS  Value: 0 means using default, from 1 to 20000 0.001 dB step, -6dB to 14 dB*/
    uint16_t      nEpreRatioToSSB;

    /**** word 8 *****/
    uint8_t      rsv0;
    /*TxRU number Value:1~2*/
    uint8_t      nNrofTxRU;
    uint8_t      rsv[2];

    /**** word 9 *****/
    /*TxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 Value:0~15*/
    uint8_t      nTxRUIdx[MAX_TXRU_NUM];

    /**** word 10 - 25 *****/
    /* Beam index Value:0~63*/
    int16_t     nBeamId[MAX_DL_CSIRS_PORT_NUM];
} CSIRSPDUStruct, *PCSIRSPDUStruct;

typedef struct tUlSchCsiPart2Info
{
    uint16_t  nPriority;                                   //Priority of the part 2 report;L2 shall signal part2 parameters in increasing order of priorities.
    uint16_t  nPart2SizeMapIndex;                          //Index of one of the maps for determining the size of a part2, from the part 1 parameter values.
    uint8_t   nPart2SizeMapScope;                          // 0: nPart2SizeMapIndex shall be looked up in common map(cell0) in PHY_CONFIG_REQ shared by all cells; 1: nPart2SizeMapIndex shall be looked up PHY_CONFIG_REQ in this cell.
    uint8_t   nPart1Params;                                //Number of Part 1 parameters that influence the size of this part 2.
    uint8_t   rsv[2];
    uint8_t   nPart1ParamSize[MAX_NUM_PART1_PARAMS];       //Bitsizes of part 1 param in the same order as nPart1ParamOffsets, sum(nPart1ParamSize[*]) shall not exceed 12
    uint16_t  nPart1ParamOffsets[MAX_NUM_PART1_PARAMS];    //Ordered list of parameter offsets (offset from 0 = first bit of part1)
} CsiPart2InfoStruct;


//------------------------------------------------------------------------------------------------------------
// Structures for PHY_UL_CONFIG_REQ message
typedef struct tUlSchPduInfo
{
    /**** word 1 *****/
    PDUStruct  sPDUHdr;

    /**** word 2 *****/
    uint16_t   nRNTI;               // The RNTI used for identifying the UE when receiving the PDU,Value: 1 -> 65535.
    uint16_t   nUEId;               // UE index in the sector,Value:0 -> 1199

    /**** word 3 *****/
    uint16_t   nBWPSize;            // bandwidth part size,Value: 20->275
    uint16_t   nBWPStart;           // bandwidth part start RB index,Value: 0->254

    /**** word 4 *****/
    uint8_t    nSubcSpacing;        // subcarrierSpacing value:0->4
    uint8_t    nCpType;             // Cyclic prefix type  0: Normal; 1: Extended
    uint8_t    nULType;             // 0: NR UL ; 1: supplementary UL
    uint8_t    nMcsTable;           // MCS-Table-PUSCH 0: not set to '256QAM' 1: set to '256QAM'

    /**** word 5 *****/
    uint8_t    nMCS;                // MCS index value: 0->31
    uint8_t    nTransPrecode;       // 0: transform precoding disabled,1: transform precoding enabled
    uint8_t    nTransmissionScheme; // 0: non-codebook-based transmission,1: codebook-based transmission
    uint8_t    nNrOfLayers;         // number of layers,Value: 1,2

    /**** word 6 *****/
    uint8_t    nPortIndex[MAX_UL_PER_UE_DMRS_PORT_NUM];//Up to 4 ports,0: port 1000,1: port 1001 . 11: port 1011

    /**** word 7 *****/
    uint8_t    rsv1;
    uint8_t    nSCID;               // For DMRS generatio Value : 0->1
    uint16_t   nNIDnSCID;           // DL-DMRS-Scrambling-ID, For DMRS generation Value : 0->65535

    /**** word 8 *****/
    uint8_t    nNrOfAntennaPorts;   //number of antenna ports,Value: 1,2,4
    uint8_t    nVRBtoPRB;           // VRB-to-PRB-mapping 0: non-interleaved VRB-to-PRB mapping 1: interleaved VRB-to-PRB mapping
    uint8_t    nRBBundleSize;       // Resource block bundle size L, refer to section 7.3.1.6 in [2]
    uint8_t    nPMI;                // Precoding matrix indicator,Value: 0->27

    /**** word 9 *****/
    uint8_t    nStartSymbolIndex;   // start symbol index of PUSCH mapping  Value: 0, 2 or 3 for PUSCH mapping type A:  [2 or 3] for PUSCH mapping type B:  [0]
    uint8_t    nNrOfSymbols;        // PUSCH duration in symbols Value: 1->14
    uint8_t    nResourceAllocType;  // resource allocation type,0: type 0,1: type 1
    uint8_t    nNrOfRBGs;           // For resource allocation type 1.Number of RBGs

    /**** word 10 *****/
    uint16_t   nRBStart;            // For resource allocation type 0.The starting resource block for this ULSCH allocation.
    uint16_t   nRBSize;             // For resource allocation type 0.The number of resource block allocated to this ULSCH grant.This should match the value sent in the DCI Format 0 PDU which allocated this grant.

    /**** word 11 *****/
    uint32_t   nRBGIndex;//For resource allocation type 1.RBG index allocated for this ULSCH.The maximum number is 138 with 275 RBs and RBG size 4.

    /**** word 12 *****/
    uint32_t   nTBSize;             // transmit block size (in bytes)

    /**** word 13 *****/
    uint8_t    nRBGSize;            // For resource allocation type 1.RBG size,Value: 2,4,8,16
    uint8_t    nRV;                 // Redundancy version,Value: 0 -> 3
    uint8_t    nHARQID;             // HARQ Process number.
    uint8_t    nNDI;                // Specify whether this received PUSCH is a new transmission from UE. This should match the value sent in the DCI Format 0 PDU which allocated this grant.

    /**** word 14 *****/
    uint8_t    nMappingType;        //.PUSCH mapping Type,0: mapping type A,1: mapping type B
    uint8_t    nDMRSConfigType;     // UL DMRS config type,0: type 1,1: type2
    uint8_t    nNrOfCDMs;           // Number of DM-RS CDM groups without data, it determines the ratio of PUSCH EPRE to DM-RS EPRE.  refer to Table 6.2.2-1 in [5]
    uint8_t    nNrOfDMRSSymbols;    // Number of UL DMRS symbols,1: single symbol,2: double symbol

    /**** word 15 *****/
    uint8_t    nDMRSAddPos;         // UL additional DMRS position,UL-DMRS-add-pos,Value: 0->3
    uint8_t    nPTRSPresent;        //.UL-PTRS-present,0: PT-RS is not present,1: PT-RS is present
    uint8_t    nNrOfPTRSPorts;      //.UL-PTRS-ports. Up to 2 ports,Value: 1->2
    uint8_t    nPTRSTimeDensity;    //.PT-RS time density,Value: 0,1, 2 or 4,0 means PT-RS is not present

    /**** word 16 *****/
    uint8_t    nPTRSPortIndex[MAX_UL_PER_UE_PTRS_PORT_NUM];//0: port 1000,1: port 1001 . 11: port 1011
    uint8_t    nPTRSFreqDensity;    // PT-RS frequency density,Value: 0, 2 or 4,0 means PT-RS is not present
    uint8_t    nPTRSReOffset;       // UL-PTRS-RE-offset , refer to Table 6.4.1.2.2.1-1 in [2] Value: 0->3

    /**** word 17 *****/
    uint8_t    nTpPi2BPSK;          //TP with Pi2BPSK .0 : TpPi2BPSK disable ,1 : TpPi2BPSK enable
    uint8_t    nrsv;
    int16_t    nHisTaNs;  // Historical TA for this UE, for pre-TA correction in PHY. value is in NanoSecond. 0: disabled

    /**** word 18 *****/
    uint16_t   nNid;                // Data-scrambling-IdentityValue : 0->1023
    uint8_t    nAlphaScaling;       // configured by higher parameter scaling, ENUMERATED for UCI-onPUSCH RRC { f0p5, f0p65, f0p8, f1 }, Value 0->3
    uint8_t    nBetaOffsetACKIndex; // BetaoffsetAck index

    /**** word 19 *****/
    uint16_t   nAck;                    // number of HARQ bits
    uint8_t    nBetaOffsetCSIP1Index;   // BetaoffsetCsi-part1 index
    uint8_t    nBetaOffsetCSIP2Index;   // BetaoffsetCsi-part2 index

    /**** word 20 *****/
    uint16_t   nCSIPart1;             // number of CSI part1 bits
    uint16_t   nCSIPart2;             // Number of CSI part2, Value: 0 -> No CSI part 2, others -> Number of CSI part2

    /**** word 21 *****/
    uint8_t    nrsv0;
    uint8_t    nNrofRxRU;             // Number of RxRU value:1~4*/
    uint16_t   nTPPuschID;            // nRSID, refer to 38.211 6.4.1.1.1.2

    /**** word 22 *****/
    uint8_t   nMMimoMode;             // 0->non Massive Mimo PDU, 1-> beamID + matrix mode,wideband+subband,  Beam Matrix generated by L1 ,using SRS, 2-> beamID + matrix mode, wideband+subband, Beam Matrix generated by L2
    /* Bit ID for SRS Chan Est ports to be for beam weight generation.  bit0=port0, bit1=port1, bit2=port2, bit3=port3 */
    uint8_t    nPortInfoBitMap;
    /* SRS Channel Estimation Buffer Index to be used for beam weight generation */
    uint8_t    nSRSChanEstBufferIndx;
    uint8_t    nDmrsGroupSeqHop;     //groupOrSequenceHopping for transform precoding, value:0->2, 0: neither, 1: groupHopping, 2: sequenceHopping

    /**** word 23-26 *****/
    uint8_t    nRxRUIdx[MAX_RXRU_NUM];

    /**** word 27-28 ****/
    /** TBSlbrm 3GPP TS38.212 section 5.4.2.1 **/
    uint32_t    isLBRMSupp;
    uint32_t    nTBSlbrm;


    /**** word 29-36 ****/
    /* beamID table, only for nMMimoMode = 0 */
    int16_t    nBeamId[MAX_RXRU_NUM];

    /**** word 37 *****/
    uint32_t  nRsvForBeamMatrixStruct;// for stBeamMatrixInfo 8 bytes alain !!!!!

    /**** word 38-43 ****/
    /* valid when nMMimoMode = 1 or nMMimoMode = 2 */
    BeamMatrixStruct stBeamMatrixInfo;

    /**** word 44-45 *****/
    /* Maps info for determining the size of a part2, from the part 1 parameter values,dimension is nCSIPart2*/
    CsiPart2InfoStruct sCSIPart2[];
} ULSCHPDUStruct, *PULSCHPDUStruct;

typedef struct tUlUcchPduInfo
{
    /**** word 1 *****/
    PDUStruct  sPDUHdr;

    /**** word 2 *****/
    uint16_t   nRNTI;               // The RNTI used for identifying the UE when receiving the PDU,Value: 1 -> 65535.
    uint16_t   nUEId;               // UE index in the sector,Value:0 -> 1199

    /**** word 3 *****/
    uint16_t   nBWPSize;            // bandwidth part size,Value: 20->275
    uint16_t   nBWPStart;           // bandwidth part start RB index,Value: 0->254

    /**** word 4 *****/
    uint8_t    nSubcSpacing;        // subcarrierSpacing value:0->4
    uint8_t    nCpType;             // Cyclic prefix type  0: Normal; 1: Extended
    uint8_t    nULType;             // 0: NR UL ; 1: supplementary UL
    uint8_t    nFormat;             // PUCCH format, Value:0~4

    /**** word 5 *****/
    uint16_t   nID;                 // nID used for data scrambling[38.211&6.3.2.5.1/6.3.2.6.1].Valid for format2/3/4, Value:0~1023
    uint16_t   nScramID;            // nID0 used for reference signal scrambling[38.211&6.4.1.3.2.1].Valid for format2, Value:0~65535

    /**** word 6 *****/
    uint8_t    nSRPriodAriv;        // whether SR period arrived, Value:0 or 1, valid for format0
    uint8_t    nStartSymbolx;       // index of first symbol, Value: 0~13
    uint16_t   nStartPRB;           // Index of the first PRB prior to frequency hopping or no-hopping, Value: 0~272

    /**** word 7 *****/
    uint16_t   n2ndHopPRB;          // Index of the first PRB after frequency hopping, Value: 0~272
    uint16_t   nPRBs;               // A number of PRBs, Value: 1~273, valid for format2/3

    /**** word 8 *****/
    uint8_t    nSymbols;            // Number of symbols, Value:1,2,4~14
    uint8_t    nFreqHopFlag;        // Frequency hopping for a PUCCH resource enabled or disabled, Value: 0 or 1, valid for format1/3/4
    uint16_t   nM0;                 // Initial Cyclic Shift Value: 0~11, valid for format0/1


    /**** word 9 *****/
    uint8_t    nAddDmrsFlag;        // Flag for additional DMRS, Value: 0 or 1, valid for format3/4
    uint8_t    nMaxCodeRate;        // Max coding rate to determine how to feedback UCI on PUCCH for format 3 or 4, Value 0 -> 6: max code rate per Table 9.2.5.2-1 of 3GPP TS 28.213. 255: not applicable (e.g., formats 0 or 1)
    uint8_t    nFmt1OrthCCodeIdx;   // An index of an orthogonal cover code in case of PUCCH format 1, Value: 0~6
    uint8_t    nFmt4OrthCCodeIdx;   // An index of an orthogonal cover code in case of PUCCH format 4, Value: 0~3

    /**** word 10 *****/
    uint8_t    nFmt4OrthCCodeLength;// A length of an orthogonal cover code in case of PUCCH format 4, Value: 2 or 4
    uint8_t    modType;             // Modulation type for PUCCH format 3 and 4, Value: 1-pi/2 BPSK or 2-QPSK
    uint16_t   nBitLenUci;          // Bit length of UCI payload for format1/2/3/4 or bit length of UCI payload exclude SR for format0

    /**** word 11 *****/
    uint8_t    nRsv;
    /*Number of RxRU value:1~4*/
    uint8_t    nNrofRxRU;
    uint16_t   nGroupId;           // Index to identify the group of UEs sharing same resources. Value: 0~199

    /**** word 12-15*****/
    /* RxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~15*/
    uint8_t    nRxRUIdx[MAX_RXRU_NUM];

    /**** word 16-23 ****/
    int16_t    nBeamId[MAX_RXRU_NUM];// beamID table for each pucch iq-stream

    /**** word 24 *****/
    uint16_t nCSIPart2;              // Number of CSI part2, Value: 0 -> No CSI part 2, others -> Number of CSI part2
    uint8_t rsv2[2];

    /**** word 25-28 *****/
    CsiPart2InfoStruct sCSIPart2[];  // Maps info for determining the size of a part2, from the part 1 parameter values, dimension is nCSIPart2

} ULCCHUCIPDUStruct, *PULCCHUCIPDUStruct;

typedef struct tPdschGroupInfoStruct
{
    uint8_t  nUE;//Number of UE in this group,For SU-MIMO, one group includes one UE only. For MU-MIMO, one group includes up to 6 UEs.
    uint8_t  rsv1[3];
    uint8_t  nPduIdx[MAX_DL_PARIED_UE_NUM];//This value is an index for number of PDU identified by nPDU in this message
} PDSCHGroupInfoStruct, *PPDSCHGroupInfoStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_DL_CONFIG_REQ message
typedef struct tDlConfigRequestStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t        nDCI;                //Number of DCIs that are included in this message.,
    uint8_t        nPDU;                //Number of PDUs that are included in this message.,
    uint8_t        nGroup;              //Number of UE Groups included in this message.
    uint8_t        nLte_CRS_Present;    //LTE 4G being transmitted concurrently on this slot, 0 = no 4g, 1 = lte present, only valid for mu = 0

    //RateMatchPatternLTE-CRS parameters, lte-CRS-ToMatchAround in ServingCellConfigCommon
    uint16_t       nLte_CRS_carrierFreqDL;      //LTE 4G Downlink Center frequency (0 ... 16383)
    uint8_t        nLte_CRS_carrierBandwidthDL; //LTE 4G bandwidth, number of resource blocks {n6, n15, n25, n50, n75, n100, spare2, spare1}
    uint8_t        nLte_CRS_nrofCRS_Ports;      //LTE 4G, number of Tx Antennas {n1, n2, n4}

    uint8_t        nLte_CRS_v_shift;            //LTE 4G vShift = nPhyCellId % 6.  {n0, n1, n2, n3, n4, n5}

    /* Enable Precoder for DL and UL DCI. Setting this field will run precoder on DL / UL DCI resource map and fill all the antenna */
    uint8_t        nPdcchPrecoderEn;
    /* Enable Precoder for SSB. Setting this field will run precoder on SSB resource map and fill all the antenna */
    uint8_t        nSSBPrecoderEn;
    uint8_t        nTestMode;            //Enable or disable FR1 Test Models per spec 38.141 sec4.9.2.2. Value 0 - Disabled and Value 1 - Test Mode Enabled

    PDSCHGroupInfoStruct sPDSCHGroupInfoStruct[MAX_MIMO_GROUP_NUM];
    // PDUStruct  for multiple(nPDU) PDU.
    PDUStruct      sDLPDU[];
} DLConfigRequestStruct, *PDLConfigRequestStruct;

typedef struct tPuschGroupInfoStruct
{
    uint8_t  nUE;                          // Number of UE in this group,For SU-MIMO, one group includes one UE only. For MU-MIMO, one group includes up to 6 UEs.Value: 1-6
    uint8_t  rsv1[3];
    uint8_t nPduIdx[MAX_UL_PARIED_UE_NUM];// This value is an index for number of PDU identified by nPDU in this message
} PUSCHGroupInfoStruct, *PPUSCHGroupInfoStruct;

//------------------------------------------------------------------------------------------------------------
// Structures for MSG_TYPE_PHY_UL_CONFIG_REQ message
typedef struct tUlConfigRequestStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;//A 32-bit value where,[24:9] SFN, range 0 -> 1023,[8:0] SF, range 0 -> 319

    /**** word 3 *****/
    uint16_t   nPDU;         // Number of PDUs that are included in this message.Range 0 -> 255
    uint8_t    nGroup;       // Number of UE Groups included in this message. Value: 1-8
    uint8_t    nUlsch;       // Number of ULSCH that are included in this message.

    /**** word 4 *****/
    uint16_t    nUlcch;      // Number of ULCCH that are included in this message.
    uint8_t     nRachPresent;
    uint8_t     nUlsrs;      // Number of UL SRS that are included in this message


    PUSCHGroupInfoStruct sPUSCHGroupInfoStruct[MAX_MIMO_GROUP_NUM];
    // PDUStruct content for multiple(nPDU) PDU.
    PDUStruct sULPDU[];
} ULConfigRequestStruct, *PULConfigRequestStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_UL_DCI_REQ message
typedef struct tUlDciRequestStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;//A 32-bit value where,[24:9] SFN, range 0 -> 1023,[8:0] SF, range 0 -> 319

    /**** word 3 *****/
    uint8_t   nDCI;          // Number of DCIs that are included in this message.,
    uint8_t   rsv1[3];

    DCIPDUStruct sULDCIPDU[];
} ULDCIRequestStruct, *PULDCIRequestStruct;

//------------------------------------------------------------------------------------------------------------
// Structures for MSG_TYPE_UE_MANAGEMENT_REQ message
typedef struct tUeManagementRequestStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;   //A 32-bit value where,[24:9] SFN, range 0 -> 1023,[8:0] SF, range 0 -> 319

    /**** word 3 *****/
    uint16_t   nNumUEs;         // Number of UEs that are included in this message.Range 0 -> MAX_UE_MANAGEMENT_NUM
    uint16_t   nRsv;

    UEMANAGEMENTPDUStruct sUeManagement[];
} UEManagementRequestStruct, *PUEManagementRequestStruct;

typedef struct tDlPduDataStruct
{
    /**** word 1 *****/
    uint8_t   nPduIdx;      // This value is an index for number of PDU identified by nPDU in DL_CONFIG.request message
    uint8_t   rsv1[3];

    /**** word 2,3 *****/
    uint32_t  nPduLen1;     // length of first transport block in byte
    uint32_t  nPduLen2;     // length of second transport block in byte

    /**** word 4,5 *****/
    uint8_t   *pPayload1;   // Content of first transport block, the first PRERESERVED_DATA_HEADER_LEN bytes are reserved for SW-FPGA header
    uint8_t   *pPayload2;   // Content of second transport block in case of 2 TBs,the first PRERESERVED_DATA_HEADER_LEN bytes are reserved for SW-FPGA header
} DLPDUDataStruct, *PDLPDUDataStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_TX_REQ message
typedef struct tTxRequestStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t    nPDU;        // Number of PDUs that are included in this message.Range 0 -> 514
    uint8_t    rsv1[3];

    DLPDUDataStruct sDLPDUDataStruct[];
} TXRequestStruct, *PTXRequestStruct;

/*CRC.indication*/
typedef struct tUlCrcStruct
{
    /**** word 1 *****/
    uint16_t nUEId;         // UE index in the sector;Value:0 -> 1199
    uint16_t nRNTI;         // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2-3 *****/
    int16_t  nSNR;          // Reported SNR in 1/256 dB steps, estimated by this PUSCH
    uint8_t  nConfLvl;      // the level of confidence for Timing advance measure. value is 0-1. 0 is low, 1 is high.
    uint8_t  nTA;           // Reported Timing advance value 0 -> 63 ,estimated by this PUSCH,  unit is 16 * 64 / 2^u Tc
    int16_t  nTANanos;      // Reported Timing advance in nanoseconds. value -16800 -> 16800 nanoseconds。0xFFFF is not vaild this field.
    uint8_t  rsv0[2];

    /**** word 4 *****/
    uint8_t  nCrcFlag;      //CRC flag to indicate if error detected:0: CRC error ,1: CRC correct
    uint8_t  nChanDetected; //Channel Detected flag. 0: possible DTX detected for channel, 1: channel detected
    uint8_t  nDtxDetected;  //DTX detected.  0: channel present, 1: DTX detected for channel
    uint8_t  rsv1[1];

    /**** word 5 *****/
    int16_t  nDMRSPwrDBFS;  //receive DMRS amplitude in dBFS, 0.01 dB step
    uint8_t  rsv2[2];

    /**** word 6 - 9 *****/
    int16_t  nSigPwr[MAX_REPORT_UL_PORTS];  // 8 received signal power from antennas in 1/256 dBm steps

    /**** word 10 *****/
    int16_t  nTotalSigPwr;  // Sum of received signal power from all antennas in 1/256 dBm steps
    uint8_t  rsv3[2];

    /**** word 11 -12*****/
    int16_t nPostSNR[MAX_UL_PORTS_PER_UE]; // Reported Post_SNR per Layer in 1/256 dB steps, estimated by this PUSCH, target accuracy < 1db
} ULCRCStruct, *PULCRCStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_CRC_IND message
typedef struct tCrcIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    uint8_t    nCrc;        // Number of CRCs included in this message:Value: 0->255
    uint8_t    rsv1[3];

    /**** word 3*****/
    int16_t    nIntfNoisePwr[MAX_NUM_RBG]; // Subband granularity for RBG size of 4
    uint8_t    rsv2[2];

    ULCRCStruct sULCRCStruct[];
} CRCIndicationStruct, *PCRCIndicationStruct;

/*RX_ULSCH.indication*/
typedef struct tUlSchPduDataStruct
{
    /**** word 1 *****/
    uint16_t  nUEId;        // UE index in the sector;Value:0 -> 1199
    uint16_t  nRNTI;        // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2 *****/
    uint32_t  nPduLen;      // The total length (in bytes) of PDU payload, without the padding bytes.
    /**** word 3 *****/
    uint8_t   *pPayload;    // Contents of the ULSCH PDU, should be only a buffer address in current implementation,the first PRERESERVED_DATA_HEADER_LEN bytes are reserved for SW-FPGA header
} ULSCHPDUDataStruct, *PULSCHPDUDataStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_RX_ULSCH_IND message
typedef struct tRxUlSchIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t   nUlsch;       // Number of ULSCH PDUs included in this message. Value: 0->255
    uint8_t   rsv1[3];      // rsv1[0] is reserved to indicate using PUSCH float16 or not: 0 fixed-point datatype, 1 float16 datatype.

    ULSCHPDUDataStruct sULSCHPDUDataStruct[];
} RXULSCHIndicationStruct, *PRXULSCHIndicationStruct;

/*RX_ULSCH_UCI.indication*/
typedef struct tUlSchUciPduDataStruct
{
    /**** word 1 *****/
    uint16_t nUEId;        // UE index in the sector;Value:0 -> 1199
    uint16_t nRNTI;        // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2 *****/
    uint16_t nPduUciAckLen;         // The total length (in bits) of UlSch UCI Ack/Nack PDU payload, without the padding bytes.
    uint8_t  nUciDetected;          // Indicates if L1 was able to decode Ack UCI or not (0- detected / 1 - dtx ), for sizes < 11
    uint8_t  nUciCrc;               // for polar coded Ack UCI, CRC flag to indicate if error detected:0: CRC error ,1: CRC correct

    /**** word 3 *****/
    uint16_t nPduUciCsiP1Len;       // The total length (in bits) of UlSch UCI CsiP1 PDU payload, without the padding bytes.
    uint8_t  nUciCsiP1Detected;     // Indicates if L1 was able to decode UCI or not (1- detected / 0 - dtx ), for sizes < 11
    uint8_t  nUciCsiP1Crc;          // for polar coded Csi Part 1, UCI, CRC flag to indicate if error detected:0: CRC error ,1: CRC correct

    /**** word 4 *****/
    uint16_t nPduUciCsiP2Len;       // The total length (in bits) of UlSch UCI CsiP2 PDU payload, without the padding bytes.
    uint8_t  nUciCsiP2Detected;     // Indicates if L1 was able to decode UCI or not (1- detected / 0 - dtx ), for sizes < 11
    uint8_t  nUciCsiP2Crc;          // for polar coded Csi Part 2, UCI, CRC flag to indicate if error detected:0: CRC error ,1: CRC correct

    /**** word 5 *****/
    uint8_t nUciAckBits[MAX_UCI_BIT_BYTE_LEN];      //buffer for ACK/NACK bits in UCI over PUSCH
    uint8_t nUciCsiP1Bits[MAX_UCI_BIT_BYTE_LEN];    //buffer for CSI Part 1 bits in UCI over PUSCH
    uint8_t nUciCsiP2Bits[MAX_UCI_BIT_BYTE_LEN];    //buffer for CSI Part 2 bits in UCI over PUSCH
} ULSCHUCIPDUDataStruct, *PULSCHUCIPDUDataStruct;

// Payload for MSG_TYPE_PHY_RX_ULSCH_UCI_IND message
typedef struct tRxUlSchUciIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t   nUlschUci; // Number of ULSCH UCI PDUs included in this message. Value: 0->255
    uint8_t   rsv1[3];

    ULSCHUCIPDUDataStruct sULSCHUCIPDUDataStruct[];
} RXULSCHUCIIndicationStruct, *PRXULSCHUCIIndicationStruct;

// Only used for 5GNR Test App for debugging purposes to gather statistics
typedef struct tUlPuschChanEstStruct
{
    /**** word 1 *****/
    uint16_t  nUEId;             // UE index in the sector;Value:0 -> 1199
    uint16_t  nRNTI;             // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2 *****/
    uint8_t   nNrOfSymbols;      // Number of DMRS symbols
    uint8_t   nNrOfUePort;       // Number of UE ports or number of layers for this user
    uint8_t   nNrOfRxPort;       // Number of Rx Ports programmed by MAC for this user
    uint8_t   nLinearInterMode;  // Linear interpolation granularity

    /**** word 3 *****/
    uint16_t  nNrOfRbs;          // Number of RBs based on numerology and bandwidth for this user
    uint16_t  nChanAlignOffset;  // Offset in bytes to the next DMRS ChanEst for each layer,port index

    /**** word 4-5 *****/
    uint16_t  nDmrsSymbolIdx[MAX_UL_PER_UE_DMRS_PORT_NUM];  //dmrs symbol indexes

    /**** word 6 - *****/
    int16_t   *pPuschChanEst[MAX_UL_PORTS_PER_UE][MAX_RXRU_NUM];  // Pointer to PUSCH Channel Estimates, each buffer contains ChanEst for all DMRS
} ULPUSCHChanEstStruct, *PULPUSCHChanEstStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_RX_CHAN_EST_OUTPUT_IND message
// Only used for 5GNR Test App for debugging purposes to gather statistics
typedef struct tRxPuschChanEstIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t    nUlsch;     // Number of Pusch
    uint8_t    rsv1[3];

    ULPUSCHChanEstStruct    sULPuschChanEstStruct[];
} RXPUSCHChanEstIndicationStruct, *PRXPUSCHChanEstIndicationStruct;

typedef struct tUlUciPduDataStruct
{
    /**** word 1 *****/
    uint16_t  nUEId;        // UE index in the sector;Value:0 -> 1199
    uint16_t  nRNTI;        // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2 *****/
    uint8_t   nSRPresent;    // Whether SR present, Value 0~1, valid for format0
    uint8_t   pucchDetected; // Indicates if L1 was able to decode PUCCH or not (0 - CRC fail / 1 - CRC pass / 2 - DTX / 3 - UE has left the cell)
    uint16_t  nPduBitLen;    // The total length (in bits) of PDU Payload, Value: 0~640?

    /**** word 3 *****/
    int16_t  nSNR;          // Reported SNR in 1/256 dB steps, estimated by this PUCCH
    int16_t  nTA;           // Reported Timing advance value 0 -> 63 ,estimated by this PUCCH, unit is 16 * 64 / 2^u Tc

    /**** word 4 *****/
    int16_t   nTotalSigPwr;      // Received total signal power for all ports in 1/256 dBm steps
    int8_t   nSrBitLen;    // Indicate if valid bit length in nSRPresent field for format0
    uint8_t    rsv1[1];

    /**** word 5 *****/
    uint16_t nPduPart2BitLen;       // The total length (in bits) of Ulcch UCI CsiP2 PDU payload, without the padding bytes.
    uint8_t    rsv2[2];

    /**** word 6+ *****/
    uint8_t   nUciBits[MAX_UCI_BIT_BYTE_LEN];//Contents of the ULUCI PDU
    uint8_t   nUciPart2Bits[MAX_UCI_BIT_BYTE_LEN];//Contents of the ULUCI PDU, CSI part2
} ULUCIPDUDataStruct, *PULUCIPDUDataStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_UCI_IND message
typedef struct tRxUciIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 2 *****/
    uint8_t   nUCI;         // Number of UCI PDUs included in this message. Value: 0->255
    uint8_t   rsv1[3];

    ULUCIPDUDataStruct sULUCIPDUDataStruct[];
} RXUCIIndicationStruct, *PRXUCIIndicationStruct;

typedef struct tPreambleStruct
{
    /**** word 1 *****/
    uint16_t    nTa;            // Timing advance
    uint8_t     nPreambIdx;     // Preamble index
    uint8_t     nStartSymbIdx;  // the index of the first OFDM symbol of the specified PRACH

    /**** word 2 *****/
    /*the index of the first slot of the specified PRACH in a system frame*/
    uint16_t    nStartSlotdx;
    /*the index of the specified PRACH in the frequency domain */
    uint16_t    nFreqIdx;

    /**** word 3 *****/
    /*Receiving preamble power, in 1/256 dBm step*/
    int32_t    nPreambPwr;

    /**** word 4 *****/
    /*the UL carrier used for Msg1 transmission
    0 : normal carrier
    1 : SUL carrier*/
    uint8_t     nUlCarrier;
    /*the occasion ID of PRACH detected*/
    uint8_t     nOccasionId;
    uint8_t     rsv1[2];
} PreambleStruct, *PPreambleStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_RX_RACH_IND message
typedef struct tRxPrachIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t    nNrOfPreamb;     // Number of preambles detected.
    uint8_t    rsv1[3];

    /**** word 4 - word 32 *****/
    int16_t    nPrachRssi[MAX_PRACH_FRE_FDM][MAX_PRACH_TIME_TDM];  // RSSI per PRB,  in 0.01 dBm steps

    PreambleStruct    sPreambleStruct[];
} RXRACHIndicationStruct, *PRXRACHIndicationStruct;

typedef struct tUlSrsEstStruct
{
    /**** word 1 *****/
    uint16_t  nUEId;             // UE index in the sector;Value:0 -> 1199
    uint16_t  nRNTI;             // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2 *****/
    uint8_t   nNrOfSymbols;      // Number of symbols
    uint8_t   nNrOfBlocks;       // Number of frequency sub block, one sub block covers 4 RBs
    uint8_t   nNrOfPort;         // Number of SRS ports programmed by MAC for this user
    uint8_t   nNrOfRxAnt;        // Number of Rx Ant programmed by MAC for this user

    /**** word 3 *****/
    uint16_t  nNrOfRbs;                 // Number of RBs based on numerology and bandwidth for this user
    uint8_t   nIsChanEstPres;           // If 1, then pSrsChanEst is filled with valid pointers.
    uint8_t   nSRSChanEstBufferIndx;    // SRS Channel Estimation Buffer Index updated

    /**** word 4 -> *****/
    int8_t    nWideBandSNR[4];   // SNR in db measured within configured SRS bandwidth on each symbols, up to 4 symbols can be configured
    int8_t    nBlockSNR[4][68];  // SNR in db measured within 4 RBs on each symbols, up to 68 blocks in case of SRS bandwidth 272 RBs
    int16_t   *pSrsChanEst[MAX_UL_PORTS_PER_UE][MAX_NUM_ANT_NR5G];  // Pointer to SRS Channel Estimates

    /**** word 5 -> *****/
    uint8_t    nRi;               // Selected RI based on SRS, range 1-4 for UE using layer 1-4
    uint8_t    nTpmi;              // Selected TPMI based on SRS, same as spec defined
    uint8_t    rsv1[2];
    int16_t    nSubBandSNR[68];   // Subband (with size of 4 PRB) post MMSE SNR in dB based on the selected RI and PMI (averaged by RI in linear scale)

} ULSRSEstStruct, *PULSRSEstStruct;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_RX_SRS_IND message
typedef struct tRxSrsIndicationStruct
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    /**** word 3 *****/
    uint8_t    nNrOfSrs;     // Number of SRS
    uint8_t    nFloatSrsEst; // SRS est channel: 0 fixed-point datatype, 1 float16 datatype.
    uint16_t   nSprCvtScale; // int16 to fp16 conversion scale //[23.07] Add configurable scale

    ULSRSEstStruct    sULSRSEstStruct[];
} RXSRSIndicationStruct, *PRXSRSIndicationStruct;

enum FrTypDuplexNr5g
{
    NR5G_FDD = 0, NR5G_TDD, NR5G_TDD_DL
};

enum CyclicPrefixTypeOptionsNr5g
{
    NR5G_NORMAL = 0, NR5G_EXTENDED
};

enum
{
    NUMEROLOGY_0 = 0, NUMEROLOGY_1 = 1, NUMEROLOGY_2 = 2, NUMEROLOGY_3 = 3, NUMEROLOGY_4 = 4, NUMEROLOGY_MAX
};

enum ChBwOptionsNr5g
{
    NR5G_BW_5_0_MHZ = 5,   NR5G_BW_10_0_MHZ = 10, NR5G_BW_15_0_MHZ = 15, NR5G_BW_20_0_MHZ = 20, NR5G_BW_25_0_MHZ = 25,
    NR5G_BW_30_0_MHZ = 30, NR5G_BW_40_0_MHZ = 40, NR5G_BW_50_0_MHZ = 50, NR5G_BW_60_0_MHZ = 60, NR5G_BW_70_0_MHZ = 70,
    NR5G_BW_80_0_MHZ = 80, NR5G_BW_90_0_MHZ = 90, NR5G_BW_100_0_MHZ = 100, NR5G_BW_200_0_MHZ = 200, NR5G_BW_400_0_MHZ = 400
};

enum PhyResBwNr5g
{
    NR5G_PRB_12 = 12, NR5G_PRB_24 = 24
};

enum ModulationOptionsNr5g
{
    NR5G_BPSK, NR5G_QPSK, NR5G_QAM16, NR5G_QAM64, NR5G_QAM256
};

enum DirectionNr5g
{
    NR5G_DL = 0, NR5G_UL, NR5G_SPECIAL
};

enum PucchFormatOptionsNr5g
{
    NR5G_FORMAT0 = 0, NR5G_FORMAT1, NR5G_FORMAT2, NR5G_FORMAT3, NR5G_FORMAT4
};

enum BchPeriodOptions
{
    BCH_MS5 = 0, BCH_MS10, BCH_MS20, BCH_MS40, BCH_MS80, BCH_MS160
};

enum PucchFormatType
{
    PUCCH_FORMAT0 = 0, PUCCH_FORMAT1, PUCCH_FORMAT2, PUCCH_FORMAT3, PUCCH_FORMAT4
};

enum SrsResourceType
{
    SRS_APERIODIC = 0, SRS_SEMI_PERSISTENT = 1, SRS_PERIODIC = 2
};

enum SrsHopping
{
    SRS_NEITHER_HOPPING = 0, SRS_GROUP_HOPPING = 1, SRS_SEQUENCE_HOPPING = 2
};

enum PrachSubCarrierSpacing
{
    NR5G_PRACH_15KHZ = 0, NR5G_PRACH_30KHZ, NR5G_PRACH_60KHZ, NR5G_PRACH_120KHZ,
    NR5G_PRACH_1_25KHZ, NR5G_PRACH_5KHZ
};

enum TddSymbolType
{
    SYMBOL_TYPE_DL = 0, SYMBOL_TYPE_UL = 1, SYMBOL_TYPE_GUARD = 2
};

typedef struct tAddRemoveBbuCoresNr5g
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    ADD_REMOVE_BBU_CORES sAddRemoveBbuCores;
} ADD_REMOVE_BBU_CORES_NR5G, *PADD_REMOVE_BBU_CORES_NR5G;

typedef struct tTestFileConfigNr5g
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    TEST_FILE_CONFIG sTestFileConfig;
} TEST_FILE_CONFIG_NR5G, *PTEST_FILE_CONFIG_NR5G;

typedef struct tDlUlIqSamplesNr5g
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    PHY_DL_UL_IQ_SAMPLES sDlUlIqSamples;
} PHY_DL_UL_IQ_SAMPLES_NR5G, *PPHY_DL_UL_IQ_SAMPLES_NR5G;


#pragma pack()

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef _NR5G_MAC_PHY_API_H_ */

