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
#include "Slave.h"
#include "Master.h"
#include "TestMasterSlave.h"

extern s_BOARD SlaveBoard;
/*****************************************************************************/
void TestSlave_heartbeatError(CO_Data* d, UNS8 heartbeatID)
{
	eprintf("TestSlave_heartbeatError %d\n", heartbeatID);
}

void TestSlave_initialisation(CO_Data* d)
{
	eprintf("TestSlave_initialisation\n");
}

void TestSlave_preOperational(CO_Data* d)
{
	eprintf("TestSlave_preOperational\n");
}

void TestSlave_operational(CO_Data* d)
{
	eprintf("TestSlave_operational\n");
}

void TestSlave_stopped(CO_Data* d)
{
	eprintf("TestSlave_stopped\n");
}

void TestSlave_post_sync(CO_Data* d)
{
     static int count = 0;
			if(count == 100){
			SlaveMap1 ^=1;
      SlaveMap2 ^=1;
      SlaveMap3 ^=1;
      SlaveMap4 ^=1;
      SlaveMap5 ^=1;
      SlaveMap6 ^=1;
      SlaveMap7 ^=1;
      SlaveMap8 ^=1;
      SlaveMap9 +=1;
      SlaveMap10 += 1;
      SlaveMap11 += 1;
			count = 0;
		}
    count += 1;  
}

void TestSlave_post_TPDO(CO_Data* d)
{
	
}

void TestSlave_storeODSubIndex(CO_Data* d, UNS16 wIndex, UNS8 bSubindex)
{
	/*TODO : 
	 * - call getODEntry for index and subindex, 
	 * - save content to file, database, flash, nvram, ...
	 * 
	 * To ease flash organisation, index of variable to store
	 * can be established by scanning d->objdict[d->ObjdictSize]
	 * for variables to store.
	 * 
	 * */
	eprintf("TestSlave_storeODSubIndex : %4.4x %2.2x\n", wIndex,  bSubindex);
}

void TestSlave_post_emcy(CO_Data* d, UNS8 nodeID, UNS16 errCode, UNS8 errReg)
{
	eprintf("Slave received EMCY message. Node: %2.2x  ErrorCode: %4.4x  ErrorRegister: %2.2x\n", nodeID, errCode, errReg);
}
