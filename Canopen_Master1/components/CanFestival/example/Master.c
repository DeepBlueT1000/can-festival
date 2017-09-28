/*
This file is part of CanFestival, a library implementing CanOpen Stack. 

Copyright (C): Edouard TISSERANT and Francis DUPIN

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include <stm32f10x.h>
#include <stdbool.h>
#include "Master.h"
#include "Slave.h"
#include "TestMasterSlave.h"
#include "snode2.h"
#include "snode3.h"

extern s_BOARD MasterBoard;

extern void Exit(CO_Data* d, UNS32 id);

//static uint8_t  SlaveNode2_State = 0;

/*****************************************************************************/
void TestMaster_heartbeatError(CO_Data* d, UNS8 heartbeatID)
{
	
	if(d->nodeState == Operational){
		eprintf("the slaver node %d outline,the line will be stoped\n", heartbeatID);
		d->NMTable[heartbeatID] = Unknown_state;
//		DelAlarm(d->ConsumerHeartBeatTimers[heartbeatID]);
		if(heartbeatID == 0x02)
		{	
				SlaveNode2_States = 0;
		}else if(heartbeatID == 0x03){
				SlaveNode3_States = 0;
		}
	}
}

/********************************************************
 * ConfigureSlaveNode is responsible to
 *  - setup master RPDO 1 to receive TPDO 1 from id 2
 *  - setup master RPDO 2 to receive TPDO 2 from id 2
 ********************************************************/
void TestMaster_initialisation(CO_Data* d)
{
	eprintf("TestMaster_initialisation\n");
}

static void ConfigureSlaveNode(CO_Data* d, UNS8 nodeId)
{
		switch(nodeId){
			case 0x02:
				ConfigSlaveNode2(d,nodeId);
				break;
			case 0x03:
				ConfigSlaveNode3(d,nodeId);
			 break;
		}
}

/**/
void CheckSDOCallbackAndContinue(CO_Data* d, UNS8 nodeId)
{
	UNS32 abortCode;	
	if(getWriteResultNetworkDict (d, nodeId, &abortCode) != SDO_FINISHED)
		eprintf("Master : Failed in initializing slave %2.2x,  AbortCode :%4.4x \n", nodeId, abortCode);

	/* Finalise last SDO transfer with this node */
	closeSDOtransfer(&TestMaster_Data, nodeId, SDO_CLIENT);

	ConfigureSlaveNode(d, nodeId);
}

void TestMaster_preOperational(CO_Data* d)
{
	eprintf("TestMaster_preOperational\n");
}

void TestMaster_operational(CO_Data* d)
{
	eprintf("TestMaster_operational\n");
}

void TestMaster_stopped(CO_Data* d)
{
	eprintf("TestMaster_stopped\n");
}

void TestMaster_post_sync(CO_Data* d)
{
	if(SlaveNode2_States){
		SlaveNode2_post_sync(d);
	}
	if(SlaveNode3_States){
		SlaveNode3_post_sync(d);
	}
}

void TestMaster_post_emcy(CO_Data* d, UNS8 nodeID, UNS16 errCode, UNS8 errReg)
{
	eprintf("received EMCY message from Node: %2.2x  ErrorCode: %4.4x  ErrorRegister: %2.2x\n", nodeID, errCode, errReg);
}


void CheckSDOCallback(CO_Data* d, UNS8 nodeId)
{
	UNS32 abortCode;
	
	if(getWriteResultNetworkDict (d, nodeId, &abortCode) != SDO_FINISHED)
	{
		eprintf("Master : Failed in changing Slave's transmit type AbortCode :%4.4x \n", abortCode);
	}
	closeSDOtransfer(&TestMaster_Data, nodeId, SDO_CLIENT);
}

void TestMaster_post_TPDO(CO_Data* d)
{			
	if(SlaveNode2_States){
		SlaveNode2_post_TPDO(d);
	}
	if(SlaveNode3_States){
		SlaveNode3_post_TPDO(d);
	}
}

void TestMaster_post_SlaveBootup(CO_Data* d, UNS8 nodeid)
{
	eprintf("TestMaster_post_SlaveBootup %x\n", nodeid);
	
	ConfigureSlaveNode(d, nodeid);
}
