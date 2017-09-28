#ifndef __SNODE2_H
#define __SNODE2_H

#include "data.h"

extern unsigned char SlaveNode2_States;

void Slave_Node2_Init(void);
void ConfigSlaveNode2(CO_Data* d, UNS8 nodeId);
void SlaveNode2_post_sync(CO_Data* d);
void SlaveNode2_post_TPDO(CO_Data* d);

#endif
