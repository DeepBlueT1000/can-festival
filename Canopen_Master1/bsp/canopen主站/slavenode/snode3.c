#include "snode3.h"

#include <stm32f10x.h>
#include <stdbool.h>
#include "Master.h"
#include "Slave.h"
#include "TestMasterSlave.h"

volatile unsigned char SlaveNode3_States = 0;

void Slave_Node3_Init(void)
{
	UNS32 PDO2_COBID = 0x0383;  // TPDO
	UNS32 PDO3_COBID = 0x0483;  // TPDO
	UNS32 size = sizeof(UNS32); 
	/*****************************************
	 * Define RPDOs to match slave ID=2 TPDOs*
	 *****************************************/
	writeLocalDict( &TestMaster_Data, /*CO_Data* d*/
			0x1402, /*UNS16 index*/   //PRDO
			0x01, /*UNS8 subind*/ 
			&PDO2_COBID, /*void * pSourceData,*/ 
			&size, /* UNS8 * pExpectedSize*/
			RW);  /* UNS8 checkAccess */
			
	writeLocalDict( &TestMaster_Data, /*CO_Data* d*/
			0x1403, /*UNS16 index*/  //RPDO
			0x01, /*UNS8 subind*/ 
			&PDO3_COBID, /*void * pSourceData,*/ 
			&size, /* UNS8 * pExpectedSize*/
			RW);  /* UNS8 checkAccess */
}

void ConfigSlaveNode3(CO_Data* d, UNS8 nodeId)
{
	static uint8_t step = 0;
	UNS8 Transmission_Type = 0x32;
	switch(++step){
		case 1: 
					Slave_Node3_Init();
					/*First step : setup Slave's TPDO 1 to be transmitted on SYNC*/
			    writeNetworkDictCallBack (d, /*CO_Data* d*/
					nodeId, /*UNS8 nodeId*/
					0x1802, /*UNS16 index*/
					0x02, /*UNS8 subindex*/
					1, /*UNS8 count*/
					0, /*UNS8 dataType*/
					&Transmission_Type,/*void *data*/
					CheckSDOCallbackAndContinue, /*SDOCallback_t Callback*/
                    0); /* use block mode */
					break;
		
//		case 2:	/*Second step*/
//					Transmission_Type = 252;
//					writeNetworkDictCallBack (d, /*CO_Data* d*/
//					nodeId, /*UNS8 nodeId*/
//					0x1803, /*UNS16 index*/
//					0x02, /*UNS16 index*/
//					1, /*UNS8 count*/
//					0, /*UNS8 dataType*/
//					&Transmission_Type,/*void *data*/
//					CheckSDOCallbackAndContinue, /*SDOCallback_t Callback*/
//                    0); /* use block mode */
//					break;
		case 2: 
		
		/****************************** START *******************************/
			/* Put the master in operational mode */
			setState(d, Operational);
		 
			/* Ask slave node to go in operational mode */
			masterSendNMTstateChange (d, nodeId, NMT_Start_Node);
			
			SlaveNode3_States = 1;
			eprintf("the slaver node 3 config finished\n");
			step  = 0;
			break;
	}
}

void SlaveNode3_post_sync(CO_Data* d)
{
	static int count = 0;
	if(count == 100){
		eprintf("TestMaster_post_sync\n");
		eprintf("Master: %d %d\n",
			MasterMap12,
			MasterMap13);
		count = 0;
	}
	count ++;
}

void SlaveNode3_post_TPDO(CO_Data* d)
{
	  static int MasterSyncCount = 0;

	if(MasterSyncCount % 50 == 0){
		sendPDOrequest(&TestMaster_Data, 0x1402 );
		sendPDOrequest(&TestMaster_Data, 0x1403 );
	}
	if(MasterSyncCount == 500){
		UNS8 transmitiontype;
		transmitiontype = 253;
		writeNetworkDictCallBack (&TestMaster_Data, /*CO_Data* d*/
					3, 								/*UNS8 nodeId*/
					0x1802, 					/*UNS16 index*/
					0x02, 						/*UNS16 index*/
					1, 								/*UNS8 count*/
					0, 								/*UNS8 dataType*/
					&transmitiontype,	/*void *data*/
					CheckSDOCallback, 				/*SDOCallback_t Callback*/
          0); 							/* use block mode */
	}   
	if(MasterSyncCount == 1000){
		UNS8 transmitiontype = 255;
		writeNetworkDictCallBack (&TestMaster_Data, /*CO_Data* d*/
					3, /*UNS8 nodeId*/
					0x1802, /*UNS16 index*/
					0x02, /*UNS16 index*/
					1, /*UNS8 count*/
					0, /*UNS8 dataType*/
					&transmitiontype,/*void *data*/
					CheckSDOCallback, /*SDOCallback_t Callback*/
          0); /* use block mode */
		MasterSyncCount = 0;
	}
	MasterSyncCount++;
}
