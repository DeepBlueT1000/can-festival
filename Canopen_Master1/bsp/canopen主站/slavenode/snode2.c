#include "snode2.h"

#include <stm32f10x.h>
#include <stdbool.h>
#include "Master.h"
#include "Slave.h"
#include "TestMasterSlave.h"

unsigned char SlaveNode2_States = 0;

void Slave_Node2_Init(void)
{
	UNS32 PDO1_COBID = 0x0182;  // TPDO
	UNS32 PDO2_COBID = 0x0282;  // TPDO
	UNS32 size = sizeof(UNS32); 
	/*****************************************
	 * Define RPDOs to match slave ID=2 TPDOs*
	 *****************************************/
	writeLocalDict( &TestMaster_Data, /*CO_Data* d*/
			0x1400, /*UNS16 index*/   //PRDO
			0x01, /*UNS8 subind*/ 
			&PDO1_COBID, /*void * pSourceData,*/ 
			&size, /* UNS8 * pExpectedSize*/
			RW);  /* UNS8 checkAccess */
			
	writeLocalDict( &TestMaster_Data, /*CO_Data* d*/
			0x1401, /*UNS16 index*/  //RPDO
			0x01, /*UNS8 subind*/ 
			&PDO2_COBID, /*void * pSourceData,*/ 
			&size, /* UNS8 * pExpectedSize*/
			RW);  /* UNS8 checkAccess */
}

void ConfigSlaveNode2(CO_Data* d, UNS8 nodeId)
{
	static uint8_t step = 0;
	UNS8 Transmission_Type = 0x00;
	switch(++step){
		case 1: 
					Slave_Node2_Init();
			    writeNetworkDictCallBack (d, /*CO_Data* d*/
					nodeId, /*UNS8 nodeId*/
					0x1800, /*UNS16 index*/
					0x02, /*UNS8 subindex*/
					1, /*UNS8 count*/
					0, /*UNS8 dataType*/
					&Transmission_Type,/*void *data*/
					CheckSDOCallbackAndContinue, /*SDOCallback_t Callback*/
                    0); /* use block mode */
					break;
		
		case 2:	/*Second step*/
					Transmission_Type = 50;
					writeNetworkDictCallBack (d, /*CO_Data* d*/
					nodeId, /*UNS8 nodeId*/
					0x1801, /*UNS16 index*/
					0x02, /*UNS16 index*/
					1, /*UNS8 count*/
					0, /*UNS8 dataType*/
					&Transmission_Type,/*void *data*/
					CheckSDOCallbackAndContinue, /*SDOCallback_t Callback*/
                    0); /* use block mode */
					break;
		case 3: 
		
		/****************************** START *******************************/
			/* Put the master in operational mode */
			setState(d, Operational);
		 
			/* Ask slave node to go in operational mode */
			masterSendNMTstateChange (d, nodeId, NMT_Start_Node);
			
			SlaveNode2_States = 1;
		
			eprintf("the slaver node 2 config finished\n");
			step  = 0;
			break;
	}
}

void SlaveNode2_post_sync(CO_Data* d)
{
	static int count = 0;
	if(count == 100){
		eprintf("TestMaster_post_sync\n");
		eprintf("Master: %d %d %d %d %d %d %d %d %d %x %x\n",
			MasterMap1,
			MasterMap2,
			MasterMap3, 
			MasterMap4,
			MasterMap5,
			MasterMap6,
			MasterMap7,
			MasterMap8,
			MasterMap9,
			MasterMap10,
			MasterMap11);
		count = 0;
	}
	count ++;
}

void SlaveNode2_post_TPDO(CO_Data* d)
{
//	  static int MasterSyncCount = 0;
////	eprintf("TestMaster_post_TPDO MasterSyncCount = %d \n", MasterSyncCount);

//	if(MasterSyncCount % 50 == 0){
////		eprintf("Master : Ask RTR PDO (0x1402)\n");
//		sendPDOrequest(&TestMaster_Data, 0x1402 );
//		sendPDOrequest(&TestMaster_Data, 0x1403 );
//	}
//	if(MasterSyncCount == 500){
//		UNS8 transmitiontype;
////		eprintf("Master : Change slave's transmit type to 0xFF\n");
//		transmitiontype = 252;
//		writeNetworkDictCallBack (&TestMaster_Data, /*CO_Data* d*/
//					2, 								/*UNS8 nodeId*/
//					0x1802, 					/*UNS16 index*/
//					0x02, 						/*UNS16 index*/
//					1, 								/*UNS8 count*/
//					0, 								/*UNS8 dataType*/
//					&transmitiontype,	/*void *data*/
//					CheckSDOCallback, 				/*SDOCallback_t Callback*/
//          0); 							/* use block mode */
//	}   
//	if(MasterSyncCount == 1000){
//		UNS8 transmitiontype = 255;
////		eprintf("Master : Change slave's transmit type to 0x00\n");
//		writeNetworkDictCallBack (&TestMaster_Data, /*CO_Data* d*/
//					2, /*UNS8 nodeId*/
//					0x1802, /*UNS16 index*/
//					0x02, /*UNS16 index*/
//					1, /*UNS8 count*/
//					0, /*UNS8 dataType*/
//					&transmitiontype,/*void *data*/
//					CheckSDOCallback, /*SDOCallback_t Callback*/
//          0); /* use block mode */
//		MasterSyncCount = 0;
//	}
//	MasterSyncCount++;
}
