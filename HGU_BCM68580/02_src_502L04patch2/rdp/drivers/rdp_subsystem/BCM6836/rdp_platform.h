/*
    <:copyright-BRCM:2015:DUAL/GPL:standard
    
       Copyright (c) 2015 Broadcom 
       All Rights Reserved
    
    Unless you and Broadcom execute a separate written software license
    agreement governing use of this software, this software is licensed
    to you under the terms of the GNU General Public License version 2
    (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
    with the following added to such license:
    
       As a special exception, the copyright holders of this software give
       you permission to link this software with independent modules, and
       to copy and distribute the resulting executable under terms of your
       choice, provided that you also meet, for each linked independent
       module, the terms and conditions of the license of that module.
       An independent module is a module which is not derived from this
       software.  The special exception does not apply to any modifications
       of the software.
    
    Not withstanding the above, under no circumstances may you combine
    this software in any way with any other Broadcom software provided
    under a license other than the GPL, without Broadcom's express prior
    written consent.
    
    :>
*/

#ifndef RDP_PLATFORM_H_INCLUDED
#define RDP_PLATFORM_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif

#define RNR_FREQ_IN_MHZ 1400
#define UBUS_SLV_FREQ_IN_MHZ 500

/* TODO: implement */
#define IS_WAN_TX_PORT(bbh_id) (bbh_id == BBH_TX_WAN_ID)
#define IS_WAN_RX_PORT(bbh_id) (bbh_id == BBH_ID_PON)
#define IS_SDMA(dma_id)  (dma_id > DMA0_ID)
#define IS_DMA(dma_id)   (dma_id <= DMA0_ID)
#define IS_PROCESSING_RUNNER_IMAGE(i)  ((rdp_core_to_image_map[i] == processing0_runner_image) || (rdp_core_to_image_map[i] == processing1_runner_image) || (rdp_core_to_image_map[i] == processing2_runner_image) || (rdp_core_to_image_map[i] == processing3_runner_image))
#define IS_DS_TM_RUNNER_IMAGE(i)  (rdp_core_to_image_map[i] == ds_tm_runner_image)
#define IS_US_TM_RUNNER_IMAGE(i)  (rdp_core_to_image_map[i] == us_tm_runner_image)

#define MAX_NUM_OF_LLID 32
#define MAX_NUM_OF_QUEUES_IN_SCHED 32

/* NATC */
#define NATC_CACHE_ENTRIES_NUM   512

/* DISP CONGESTION */
#define DIS_REOR_CONGESTION_THRESHOLD    200
#define DIS_REOR_LINKED_LIST_BUFFER_NUM  512
#define NUM_OF_PROCESSING_TASKS          32

/* SBPM */
#define SBPM_BASE_ADDRESS                   0
#define SBPM_INIT_OFFSET                    0x000005ff
#define SBPM_UG1_EXCL_LOW_THRESHOLD         0x200
#define SBPM_UG1_EXCL_LOW_HIST              0x14

/* BBH_RX */
#define DRV_BBH_RX_MAXIMAL_PACKET_HEADER_OFFSET 63
#define BBH_FREQUENCY (500*1000000) /* 500 MHz */

/* BBH_TX */
#define BBH_TX_DS_PD_FIFO_SIZE_0 7
#define BBH_TX_DS_PD_FIFO_SIZE_1 7

/* HASH */
#define HASH_NUM_OF_ENGINES           2
#define HASH_NUM_OF_ENGINES_LOG2      1
#define HASH_NUM_OF_EFFECTIVE_ENGINES 2

/* Bridge and VLAN */
#define HASH_TABLE_BRIDGE_AND_VLAN_LKP_SIZE_PER_ENGINE  hash_max_64_entries_per_engine

/* TCAM table size (entries) */
#define RDP_TCAM_TABLE_SIZE     256
/* Number of TCAM engines */
#define RDP_TCAM_NUM_ENGINES    2

/* Max number of queues supported by QM */
#define QM_NUM_QUEUES           160
/* Max number of EPON queues supported by QM */
#define QM_NUM_EPON_QUEUES      96
/* Max number of reported queues supported by QM */
#define QM_NUM_REPORTED_QUEUES  128

/*GPON DEFS*/
/* size of each one of FIFOs 0-7 - value is size + 1*/
#define BBH_TX_GPON_PD_FIFO_SIZE_0_7 5
#define BBH_TX_GPON_PD_FIFO_SIZE_8_15 5
#define BBH_TX_GPON_PD_FIFO_SIZE_16_23 5
#define BBH_TX_GPON_PD_FIFO_SIZE_24_31 5
#define BBH_TX_GPON_PD_FIFO_SIZE_32_39 5

/*EPON DEFS*/
/* size of each one of FIFOs 8-15 */
/* size of each one of FIFOs 8-15 */
#define BBH_TX_EPON_PD_FIFO_SIZE_0_7 7
#define BBH_TX_EPON_PD_FIFO_SIZE_8_15 7
#define BBH_TX_EPON_PD_FIFO_SIZE_16_23 7
#define BBH_TX_EPON_PD_FIFO_SIZE_24_31 7
#define BBH_TX_EPON_PD_FIFO_SIZE_32_39 7

typedef enum bbh_id_e
{
    BBH_ID_0 = 0,
    BBH_ID_1,
    BBH_ID_2,
    BBH_ID_3,
    BBH_ID_4,
    BBH_ID_5,
    BBH_ID_PON,
    BBH_ID_NUM,
    BBH_ID_FIRST = BBH_ID_0,
    BBH_ID_LAST = BBH_ID_PON,
    BBH_ID_NULL = BBH_ID_NUM
} bbh_id_e;

typedef enum dma_id_e
{
    DMA0_ID = 0,
    SDMA0_ID,
    DMA_NUM,
    DMA_ID_FIRST = DMA0_ID,
} dma_id_e;

typedef enum rnr_quad_id_e
{
    RNR_QUAD0_ID = 0,
    RNR_QUAD_ID_LAST = RNR_QUAD0_ID,
    NUM_OF_RNR_QUADS = RNR_QUAD_ID_LAST + 1,
} rnr_quad_id_e;

#define NUM_OF_CORES_IN_QUAD                        6
#define DRV_PARSER_DA_FILTER_NUM                    8
#define NUM_OF_RNR_WITH_PROFILING                   6

#endif