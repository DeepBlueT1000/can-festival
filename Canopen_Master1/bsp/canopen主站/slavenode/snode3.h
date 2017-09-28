#ifndef __SNODE3_H
#define __SNODE3_H

#include "data.h"

extern volatile unsigned char SlaveNode3_States;

void Slave_Node3_Init(void);
void ConfigSlaveNode3(CO_Data* d, UNS8 nodeId);
void SlaveNode3_post_sync(CO_Data* d);
void SlaveNode3_post_TPDO(CO_Data* d);

#endif
