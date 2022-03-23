
/*########################################################################################
###   Copyright (2021) Intel Corporation.                                              ###
###                                                                                    ###
###   Redistribution. Redistribution and use in binary form, without modification,     ###
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
 * @file gnb_l1_l2_api.h
 * @ingroup group_source_nr5g_api
 * @author Intel Corporation
 **/

#ifndef _NR5G_PHYAPI_H_
#define _NR5G_PHYAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "common_typedef.h"

#define MAX_MIMO_GROUP_NUM          (16)

#define MAX_DL_PARIED_UE_NUM        (12)
#define MAX_UL_PARIED_UE_NUM        (12)
#define MAX_DL_PER_UE_CODEWORD_NUM  (2)
#define MAX_DL_RBG_BIT_NUM          (5)  // For resource allocation type 0.The maximum number is 138 with 275 RBs and RBG size 2.
#define MAX_UL_RBG_BIT_NUM          (5)  // 275/2
#define MAX_DL_PER_UE_DMRS_PORT_NUM (8)
#define MAX_UL_PER_UE_DMRS_PORT_NUM (4)
#define MAX_DL_PER_UE_PTRS_PORT_NUM (2)
#define MAX_UL_PER_UE_PTRS_PORT_NUM (2)

#define MAX_DCI_BIT_BYTE_LEN              (32)
#define MAX_UCI_BIT_BYTE_LEN              (256)
#define MAX_DL_INPUT_TRANSPORT_BYTE_SIZE  (175000)
#define MAX_NUM_DL_LAYERS                 (8)
#define MAX_DL_HARQ_PROCESS_ID            (16)
#define MAX_UL_PDU_NUM                    (200)
#define MAX_UL_INPUT_TRANSPORT_BYTE_SIZE  (131000)      //have to check this
#define MAX_UL_HARQ_PROCESS_ID            (16)          //have to check this
#define PRERESERVED_DATA_HEADER_LEN       (32)
#define MAX_TDD_PERIODICITY               (80)
#define MAX_NUM_OF_SYMBOL_PER_SLOT        (14)
#define MAX_TXRU_NUM                      (4)
#define MAX_RXRU_NUM                      (16)
#define MAX_NUM_ANT                       (64)
#define MAX_SRS_PORT_PER_UE               (2)
#define MAX_PANEL_NUM                     (4)
#define SINR_STEP_SIZE                    (256.0)

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
#define MSG_TYPE_PHY_RX_ULSCH_UCI_IND (0x30)

// WLS operation with PDSCH Payload
#define MSG_PHY_ZBC_BLOCK0_REQ        (30)
#define MSG_PHY_ZBC_BLOCK1_REQ        (31)

// WLS operation with PUSCH Payload
#define MSG_PHY_ZBC_BLOCK_IND         (32)

#define MSG_TYPE_PHY_DL_IQ_SAMPLES          (200)
#define MSG_TYPE_PHY_UL_IQ_SAMPLES          (201)
#define MSG_TYPE_PHY_UL_UNCODED_BITS        (202)
#define MSG_TYPE_PHY_ADD_REMOVE_CORE        (203)
#define MSG_TYPE_PHY_UL_PRACH_IQ_SAMPLES    (204)
#define MSG_TYPE_PHY_UL_MMIMO_SRS_IQ_SAMPLES    (205)

#define RUN_TIME_APIS_FROM_MAC   ((1<<MSG_TYPE_PHY_DL_CONFIG_REQ) | \
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

/******ERROR indication*******/
#define MSG_OK               (0x00)
#define MSG_INVALID_STATE    (0x01)
#define MSG_INVALID_CONFIG   (0x02)

//------------------------------------------------------------------------------------------------------------
// Linked list header prent at the top of all messages
typedef struct tMac2PhyApiQueueElem
{
    struct tMac2PhyApiQueueElem* pNext;          // 0-7 byte
    uint8_t  nMessageType;                       // 8
    uint32_t nMessageLen;                        // 9-12
    uint8_t  nNumMessageInBlock;                 // 13
    uint32_t nAlignOffset;                       // 14-17
    uint64_t nTimeStamp;                         // 18-25
    uint8_t  reserved[6];                        // 26-31
} MAC2PHY_QUEUE_EL, *PMAC2PHY_QUEUE_EL;

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
    uint32_t nCarrierIdx:5; // carrier index, 0->23
    uint32_t nSym:4;        // Symbol Number, 0->13
    uint32_t nRsv:4;
} SFN_SlotStruct, *PSFN_SlotStruct;

//------------------------------------------------------------------------------------------------------------
typedef struct tSlotConfigReq
{
    uint8_t nSymbolType[MAX_NUM_OF_SYMBOL_PER_SLOT];    // Defines the Symbol type for all 14 symbols in a slot. 0: DL, 1: UL, 2: Guard
    uint8_t reserved[2];
} SLOTCONFIGStruct, *PSLOTCONFIGStruct;

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
    /*SSB block powerValue :1->110000,0.001 dB step, -60 to 50 dBm*/
    uint32_t     nSSBPwr;
    /*absoluteFrequencySSB in KHz*/
    uint32_t     nSSBAbsFre;

    /**** word 9,10 *****/
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
    /**** word 11,12 *****/
    /*Bitmap for actually transmitted SSB. */
    uint32_t     nSSBMask[2];

    /**** word 13 *****/
    /*Number of transmission antennas*/
    uint8_t      nNrOfTxAnt;
     /*Number of receiving antennas */
    uint8_t      nNrOfRxAnt;

     /* Max Number of transmission ports (1 - 16) */
     uint8_t      nNrOfDLPorts;
     /* Max Number of receiving Virtual ports (1 - 16). There maybe more than 1 virtual port mapped to a physical port transmitted by UE */
     uint8_t      nNrOfULPorts;

    /**** word 14 *****/
    /*Number of total carriers present*/
    uint8_t      nCarrierAggregationLevel;
    /*Frame Duplex type:  0 -> FDD, 1 -> TDD*/
    uint8_t      nFrameDuplexType;
    /*subCarrierSpacingCommon = numerology, Value: 0 -> 4 */
    /* 0 : 15kHz, 1: 30kHz, 2: 60khz, 3: 120khz, 4:240khz */
    uint8_t      nSubcCommon;
    /* TDD Period - If nFrameDuplexType = TDD(1), then this config defines the TDD periodicity */
    uint8_t      nTddPeriod;

    /**** word 15 - 335 *****/
    /* TDD Slot configuration - If nFrameDuplexType = TDD(1), then this config defines the slot config type for each slot.*/
    /* The number of slots need to be equal to nTddPeriod */
    SLOTCONFIGStruct sSlotConfig[MAX_TDD_PERIODICITY];

    /**** word 336 - 432 *****/
    /*According to SSB Mask, beam index filled. For example, if SSB mask bit 26 set to 1, then nBeamId[26] will be used to indicate beam ID of SSB 26.
    value: 0~63*/
    uint8_t nBeamId[MAX_NUM_ANT];
    /*According to nBeamId[MAX_NUM_ANT], if nBeamId[26] is used, nNrofTxRUPerBeam[26] indicates the number of TxRU.
    Value: 1~4*/
    uint8_t nNrofTxRUPerBeam[MAX_NUM_ANT];
    /*TxRU index for SSB beam, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3
    value:0~15*/
    uint8_t nTxRUIdx[MAX_NUM_ANT][MAX_TXRU_NUM];

    /**** word 433 *****/
    /* PRACH config*/
    /*PRACH Configuration Index*/
    uint8_t      nPrachConfIdx;
    /*PRACH Subcarrier spacing
    Value:0->1
    For below 6GHz the values indicate 15kHz or 30kHz
    For above 6GHz the values indicate 60kHz or 120kHz*/
    /*PRACH subcarrier spacing */
    uint8_t      nPrachSubcSpacing;
    /*PRACH zeroCorrelationZoneConfig */
    uint8_t      nPrachZeroCorrConf;
    /*PRACH restrictedSetConfig */
    uint8_t      nPrachRestrictSet;

    /**** word 434 *****/
    /*PRACH Root Sequence Index */
    uint16_t     nPrachRootSeqIdx;
    /*PRACH prach-frequency-start  (in RBs)*/
    uint16_t     nPrachFreqStart;

    /**** word 435 *****/
    /*PRACH-FDM Range: 1->8*/
    uint8_t      nPrachFdm;
    /*PRACH SSB-per-rach-occasion  */
    uint8_t      nPrachSsbRach;
    /* Number of Prach RxRU value:1~4*/
    uint8_t      nPrachNrofRxRU;
    /*0 for normal, 1 for extended cyclic prefix*/
    uint8_t      nCyclicPrefix;

    /**** word 436 *****/
    /* group hopping flag, Value: 0 or 1*/
    uint8_t    nGroupHopFlag;
    /**** word 436 *****/
    /* sequence hopping flag, Value: 0 or 1 */
    uint8_t    nSequenceHopFlag;
    /* Cell-Specific scrambling ID for group hopping and sequence hopping*/
    uint16_t   nHoppingId;

    /* If 1, then this cell is a URLLC cell */
    uint16_t   nUrllcCapable;
    /* Bit Mask (14 Bits) which indicate which symbol numbers to send SLOT_IND to L2 */
    uint16_t   nUrllcMiniSlotMask;
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
    uint32_t nMode;             // 0 = Radio (non-oran compliant), 1 = timer mode, 3 = Radio (with ferrybridge front haul), 4 = Radio (oran/xran compliant)
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
    uint8_t   nNrOfAntennaPorts;                // Number of antenna ports Value : 1->8, for DL, the nuuber of ports is equal to the number of layers

    /**** word 7, 8 *****/
    uint32_t  nTBSize[MAX_DL_PER_UE_CODEWORD_NUM];    // transmit block size (in bytes)

    /**** word 9, 10 *****/
    uint8_t   nPortIndex[MAX_DL_PER_UE_DMRS_PORT_NUM];// 0: port 1000,1: port 1001 . 11: port 1011

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
    uint8_t   rsv;


    /**** word 15 -> 19 *****/
    uint32_t  nRBGIndex[MAX_DL_RBG_BIT_NUM];//For resource allocation type 0.RBG index allocated for this DLSCH.	The maximum number is 138 with 275 RBs and RBG size 2.

    /**** word 20 *****/
    uint8_t   nMappingType;      // PDSCH mapping Type,	0: mapping type A,	1: mapping type B
    uint8_t   nDMRSConfigType;   // DL DMRS config type,0: type 1,1: type2
    uint8_t   nNrOfCDMs;         // Number of DM-RS CDM groups without data
    uint8_t   nNrOfDMRSSymbols;  // DL DMRS symbol number,1: single symbol,2: double symbol

    /**** word 21 *****/
    uint8_t   nDMRSAddPos;       // DL additional DMRS position,DL-DMRS-add-pos,Value: 0->3
    uint8_t   nPTRSPresent;      // DL-PTRS-present,0: PT-RS is not present,1: PT-RS is present
    uint8_t   nNrOfPTRSPorts;    // Up to 2 ports,DL-PTRS-ports.Value: 1->2
    uint8_t   nPTRSTimeDensity;  // PT-RS time density,Value: 0,1, 2 or 4,0 means PT-RS is not present

    /**** word 22 *****/
    uint8_t   nPTRSPortIndex[MAX_DL_PER_UE_PTRS_PORT_NUM];  //0: port 1000,1: port 1001. 11: port 1011
    uint8_t   nNrOfDMRSAssPTRS[MAX_DL_PER_UE_PTRS_PORT_NUM];//The number of DM-RS ports associated to PT-RS  Value: 1->6

    /**** word 23 *****/
    uint8_t   nPTRSFreqDensity;  // PT-RS frequency density,Value: 0, 2 or 4,0 means PT-RS is not present
    uint8_t   nPTRSReOffset;     // DL-PTRS-RE-offset,
    uint8_t   nEpreRatioOfPDSCHToPTRS;
    uint8_t   rv1;

    /**** word 24 *****/
    uint8_t   nTransmissionScheme; // 0: static precoder; 1: codebook-based transmission
    uint8_t   nCodebookType;     // 0: single-panel type1;1: multi-panel type1;2: type2;3: port selection port2;
    uint8_t   nCodebookMode;     // 0: codebook mode 1; 1: codebook mode 2
    uint8_t   nPMI;              // pmi, maximun 63 for 4 ports Tx

    /**** word 25 *****/
    uint16_t  n1n2;             // n1_n2=n1<<8+n2,n1 n2 values are according to table 5.2.2.2.1-2 in 38.214
    uint16_t  nEpreRatioOfDmrsToSSB;  // ratio of PDSCH EPRE to DMRS EPRE,Value :1->20000,0.001 dB step, -6dB to 14 dB

    /**** word 26 *****/
    uint16_t   nNid;             // Data-scrambling-IdentityValue : 0->1023
    /* Beam index value:0~63 */
    uint8_t    nBeamId;
    /*Number of TxRU value:1~4*/
    uint8_t    nNrofTxRU;

    /**** word 27 *****/
    uint16_t  nEpreRatioOfPDSCHToSSB;    //ratio of PDSCH EPRE to DATA EPRE,Value :1->20000,0.001 dB step, -6dB to 14 dB
    uint16_t  rv2;

    /**** word 28-32 *****/
    /*TxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~15*/
    uint8_t    nTxRUIdx[MAX_TXRU_NUM];

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

    /**** word 11-19 *****/
    /*The total DCI length including padding bits*/
    uint8_t      nDciBits[MAX_DCI_BIT_BYTE_LEN];

    /**** word 20 *****/
    /* Beam index that UE DL DCI used Value:0~63*/
    uint8_t      nBeamId;
    /*According to nBeamId[64], if nBeamId[26] is used, nNrofTxRUPerBeam[26] indicates the number of TxRU Value: 1~4*/
    uint8_t      nNrofTxRU;
    /* nID range 0 to 65535, equals the higher-layer parameter pdcch-DMRS-ScramblingID if configured. otherwise equal to Cell ID*/
    uint16_t     nID;

    /**** word 21-25 *****/
    /* TxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 Value:0~15 */
    uint8_t      nTxRUIdx[MAX_TXRU_NUM];
} DCIPDUStruct, *PDCIPDUStruct;

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
    uint8_t    nNrOfSrsPorts;           /* port number could be {1,2,4}*/
    uint8_t    nCyclicShift;            /* Cyclic Shift, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 11 */

    /**** word 6 *****/
    uint8_t    nBsrs;                   /* b-SRS, SRS bandwidth index, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 3 */
    uint8_t    nCsrs;                   /* c-SRS, SRS bandwidth config index, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 63 */
    uint8_t    nBHop;                   /* b-hop, freqHopping, 3GPP 38.211, Sec 6.4.1.4.3, Table 2.  Values: 0 -> 3 */
    uint8_t    nHopping;                /* groupOrSequenceHopping, value:0->2, 0: neither, 1: groupHopping, 2: sequenceHopping*/

    /**** word 7 *****/
    uint8_t    nFreqPos;                /* RRC Config message, SRS-Resource.freqDomainPosition, n_rrc  value: 0 -> 67 */
    uint8_t    nResourceType;           /* 0: aperiodic, 1: semi-persistent, 2: periodic*/
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
    /*Beam index value:0~63*/
    uint8_t    nBeamId;
    /* Number of RxRU value:1~4*/
    uint8_t    nNrofRxRU;
    uint8_t    rsv2[2];

    /**** word 11 *****/
    /*RxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~15*/
    uint8_t    nRxRUIdx[MAX_RXRU_NUM];
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
    /* MIB payload */
    uint8_t      nMIB[3];

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
    /* Beam index Value:0~63*/
    uint8_t      nBeamId;
    /*TxRU number Value:1~2*/
    uint8_t      nNrofTxRU;
    uint8_t      rsv[2];

    /**** word 9-13 *****/
    /*TxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 Value:0~15*/
    uint8_t      nTxRUIdx[MAX_TXRU_NUM];
} CSIRSPDUStruct, *PCSIRSPDUStruct;

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
    uint8_t    nNrOfLayers;         // number of layers,Value: 1,2,4

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

    /**** word 11 -> 15 *****/
    uint32_t   nRBGIndex[MAX_UL_RBG_BIT_NUM];//For resource allocation type 1.RBG index allocated for this ULSCH.The maximum number is 138 with 275 RBs and RBG size 4.

    /**** word 16 *****/
    uint32_t   nTBSize;             // transmit block size (in bytes)

    /**** word 17 *****/
    uint8_t    nRBGSize;            // For resource allocation type 1.RBG size,Value: 2,4,8,16
    uint8_t    nRV;                 // Redundancy version,Value: 0 -> 3
    uint8_t    nHARQID;             // HARQ Process number.
    uint8_t    nNDI;                // Specify whether this received PUSCH is a new transmission from UE. This should match the value sent in the DCI Format 0 PDU which allocated this grant.

    /**** word 18 *****/
    uint8_t    nMappingType;        //.PUSCH mapping Type,0: mapping type A,1: mapping type B
    uint8_t    nDMRSConfigType;     // UL DMRS config type,0: type 1,1: type2
    uint8_t    nNrOfCDMs;           //Number of DM-RS CDM groups without data, it determines the ratio of PUSCH EPRE to DM-RS EPRE.  refer to Table 6.2.2-1 in [5]
    uint8_t    nNrOfDMRSSymbols;    // Number of UL DMRS symbols,1: single symbol,2: double symbol

    /**** word 19 *****/
    uint8_t    nDMRSAddPos;         // UL additional DMRS position,UL-DMRS-add-pos,Value: 0->3
    uint8_t    nPTRSPresent;        //.UL-PTRS-present,0: PT-RS is not present,1: PT-RS is present
    uint8_t    nNrOfPTRSPorts;      //.UL-PTRS-ports. Up to 2 ports,Value: 1->2
    uint8_t    nPTRSTimeDensity;    //.PT-RS time density,Value: 0,1, 2 or 4,0 means PT-RS is not present

    /**** word 20 *****/
    uint8_t    nPTRSPortIndex[MAX_UL_PER_UE_PTRS_PORT_NUM];//0: port 1000,1: port 1001 . 11: port 1011
    uint8_t    nPTRSFreqDensity;    // PT-RS frequency density,Value: 0, 2 or 4,0 means PT-RS is not present
    uint8_t    nPTRSReOffset;       // UL-PTRS-RE-offset , refer to Table 6.4.1.2.2.1-1 in [2] Value: 0->3
    uint8_t    nTpPi2BPSK;          //TP with Pi2BPSK .0 : TpPi2BPSK disable ,1 : TpPi2BPSK enable

    /**** word 21 *****/
    uint16_t   nNid;                // Data-scrambling-IdentityValue : 0->1023
    uint8_t    nAlphaScaling;       // configured by higher parameter scaling, ENUMERATED for UCI-onPUSCH RRC { f0p5, f0p65, f0p8, f1 }, Value 0->3
    uint8_t    nBetaOffsetACKIndex; // BetaoffsetAck index

    /**** word 22 *****/
    uint16_t   nAck;        //number of HARQ bits
    uint8_t    nBetaOffsetCSIP1Index;   // BetaoffsetCsi-part1 index
    uint8_t    nBetaOffsetCSIP2Index;   // BetaoffsetCsi-part2 index

    /**** word 23 *****/
    uint16_t   nCSIPart1;             // number of CSI part1 bits
    uint16_t   nCSIPart2;             // number of CSI part2 bits

    /**** word 24 *****/
    uint8_t    nBeamId;               // Beam index value:0~63
    uint8_t    nNrofRxRU;             // Number of RxRU value:1~4*/
    uint16_t   nTPPuschID;           //nPUSCH-Identity

    /**** word 25 *****/
    uint8_t    nRxRUIdx[MAX_RXRU_NUM];
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
    uint16_t   nID;                 // Data scrambling ID if high layer configured, otherwise is cellID, Value: 0~1023, valid for format2/3/4
    uint16_t   nScramID;            // Using for reference signal scrambling, Value:0~65535, valid for format2

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
    uint8_t    rsv;
    uint8_t    nFmt1OrthCCodeIdx;   // An index of an orthogonal cover code in case of PUCCH format 1, Value: 0~6
    uint8_t    nFmt4OrthCCodeIdx;   // An index of an orthogonal cover code in case of PUCCH format 4, Value: 0~3

    /**** word 10 *****/
    uint8_t    nFmt4OrthCCodeLength;// A length of an orthogonal cover code in case of PUCCH format 4, Value: 2 or 4
    uint8_t    modType;             // Modulation type for PUCCH format 3 and 4, Value: 1-pi/2 BPSK or 2-QPSK
    uint16_t   nBitLenUci;          // Bit length of UCI payload for format1/2/3/4 or bit length of UCI payload exclude SR for format0

    /**** word 11 *****/
    /*Beam index value:0~63*/
    uint8_t    nBeamId;
    /*Number of RxRU value:1~4*/
    uint8_t    nNrofRxRU;
    uint16_t   nGroupId;

    /**** word 12-16 *****/
    /* RxRU index, refer to spec 36.897, section 5.2.2-1 and API doc section 3.1.3 value:0~15*/
    uint8_t    nRxRUIdx[MAX_RXRU_NUM];
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
    uint8_t        nRsv[1];

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

    /**** word 2 *****/
    int16_t  nSNR;          // Reported SNR in 1/256 dB steps, estimated by this PUSCH
    int16_t  nTA;           // Reported Timing advance value in samples ,estimated by this PUSCH

    /**** word 3 *****/
    uint8_t  nCrcFlag;      //CRC flag to indicate if error detected:0: CRC error ,1: CRC correct
    uint8_t  nChanDetected; //Channel Detected flag. 0: possible DTX detected for channel, 1: channel detected
    uint8_t  nDtxDetected;  //DTX detected.  0: channel present, 1: DTX detected for channel
    uint8_t  rsv1[1];
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
    uint8_t   rsv1[3];

    ULSCHPDUDataStruct sULSCHPDUDataStruct[];
} RXULSCHIndicationStruct, *PRXULSCHIndicationStruct;

/*RX_ULSCH_UCI.indication*/
typedef struct tUlSchUciPduDataStruct
{
    /**** word 1 *****/
    uint16_t nUEId;        // UE index in the sector;Value:0 -> 1199
    uint16_t nRNTI;        // The RNTI associated with the UE,Value: 1 -> 65535

    /**** word 2 *****/
    uint16_t nPduUciAckLen;      // The total length (in bits) of UlSch UCI Ack/Nack PDU payload, without the padding bytes.
    uint8_t  nUciDetected;          // Indicates if L1 was able to decode Ack UCI or not (0- detected / 1 - dtx ), for sizes < 11
    uint8_t  nUciCrc;               // for polar coded Ack UCI, CRC flag to indicate if error detected:0: CRC error ,1: CRC correct

    /**** word 3 *****/
    uint16_t nPduUciCsiP1Len;       // The total length (in bits) of UlSch UCI CsiP1 PDU payload, without the padding bytes.
    uint8_t  nUciCsiP1Detected;     // Indicates if L1 was able to decode UCI or not (0- detected / 1 - dtx ), for sizes < 11
    uint8_t  nUciCsiP1Crc;          // for polar coded Csi Part 1, UCI, CRC flag to indicate if error detected:0: CRC error ,1: CRC correct

    /**** word 4 *****/
    uint16_t nPduUciCsiP2Len;       // The total length (in bits) of UlSch UCI CsiP2 PDU payload, without the padding bytes.
    uint8_t  nUciCsiP2Detected;     // Indicates if L1 was able to decode UCI or not (0- detected / 1 - dtx ), for sizes < 11
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
    int16_t  nTA;           // Reported Timing advance value in samples ,estimated by this PUCCH

    uint8_t   nUciBits[MAX_UCI_BIT_BYTE_LEN];//Contents of the ULUCI PDU
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
    /*Receiving power Value :0->170000, 0.001 dB step, -140 to 30 dBm*/
    uint32_t    nPreambPwr;

    /**** word 4 *****/
    /*the UL carrier used for Msg1 transmission
    0 : normal carrier
    1 : SUL carrier*/
    uint8_t     nUlCarrier;
    uint8_t     rsv1[3];
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
    uint16_t  nNrOfRbs;          // Number of RBs based on numerology and bandwidth for this user
    uint8_t   nIsChanEstPres;    // If 1, then pSrsChanEst is filled with valid pointers. Will be 0 for non-massive MIMO scenarios
    int8_t    nWideBandSNR[4];   // SNR in db measured within configured SRS bandwidth on each symbols, up to 4 symbols can be configured
    int8_t    nBlockSNR[4][68];  // SNR in db measured within 4 RBs on each symbols, up to 68 blocks in case of SRS bandwidth 272 RBs
    int16_t   *pSrsChanEst[MAX_SRS_PORT_PER_UE][MAX_NUM_ANT];  // Pointer to SRS Channel Estimates for Massive MIMO Configurations
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
    uint8_t    rsv1[3];

    ULSRSEstStruct    sULSRSEstStruct[];

} RXSRSIndicationStruct, *PRXSRSIndicationStruct;

enum FrTypDuplex
{
    FDD = 0, TDD
};

enum CyclicPrefixTypeOptions
{
    NORMAL = 0, EXTENDED
};

enum ChBwOptions
{
    BW_5_0_MHZ = 5,   BW_10_0_MHZ = 10, BW_15_0_MHZ = 15, BW_20_0_MHZ = 20, BW_25_0_MHZ = 25,
    BW_30_0_MHZ = 30, BW_40_0_MHZ = 40, BW_50_0_MHZ = 50, BW_60_0_MHZ = 60, BW_70_0_MHZ = 70,
    BW_80_0_MHZ = 80, BW_90_0_MHZ = 90, BW_100_0_MHZ = 100, BW_200_0_MHZ = 200, BW_400_0_MHZ = 400
};

enum PhyResBw
{
    PRB_12 = 12, PRB_24 = 24
};

enum ModulationOptions
{
    BPSK, QPSK, QAM16, QAM64, QAM256
};

enum Direction
{
    DL = 0, UL, SPECIAL
};

enum PucchFormatOptions
{
    FORMAT1 = 0, FORMAT1A, FORMAT1B, FORMAT2, FORMAT2A, FORMAT2B, SPATIALBUNDLING, FORMAT3
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

enum TddSymbolType
{
    SYMBOL_TYPE_DL = 0, SYMBOL_TYPE_UL = 1, SYMBOL_TYPE_GUARD = 2
};

//------------------------------------------------------------------------------------------------------------
typedef enum
{
    BBU_CORE_ADD = 0,  /*! add core(s) to BBU Pool */
    BBU_CORE_REMOVE,   /*! remove core(s) to BBU Pool */
    BBU_CORE_SUSPEND,  /*! suspend core(s) that are already added to BBU Pool */
    BBU_CORE_RESUME,   /*! wake up core(s) that have been suspended */
    BBU_CORE_SET_CORE, /*! wake up core(s) that have been suspended */
} BBUPOOL_CORE_OPERATION;

//------------------------------------------------------------------------------------------------------------
// Payload for MSG_TYPE_PHY_ADD_REMOVE_CORE message
#define MAX_NUM_SET_CORE_MASK ( 4 )
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
    PDSCH_OFDM_SPLT_ENABLE,
    PDSCH_DL_WEIGHT_SPLIT,
    PUSCH_DECOMP_SPLIT,
    PUSCH_CHANEST_SPLIT,
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
    EBBU_POOL_NUM_QUEUE,
    EBBU_POOL_QUEUE_SIZE,
    EBBU_POOL_NUM_CONTEXT,
    EBBU_POOL_MAX_CONTEXT_FETCH,
    NUM_SPLIT_OPTIONS
} CHANNEL_SPLIT_OPTIONS;

typedef struct tAddRemoveBbuCores
{
    /**** word 1 *****/
    L1L2MessageHdr sMsgHdr;

    /**** word 2 *****/
    SFN_SlotStruct sSFN_Slot;

    BBUPOOL_CORE_OPERATION eOption;
    uint64_t nCoreMask[MAX_MASK_OPTIONS][MAX_NUM_SET_CORE_MASK];
    uint32_t nMacOptions[NUM_SPLIT_OPTIONS];
} ADD_REMOVE_BBU_CORES, *PADD_REMOVE_BBU_CORES;
//------------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef _NR5G_PHYAPI_H_ */

