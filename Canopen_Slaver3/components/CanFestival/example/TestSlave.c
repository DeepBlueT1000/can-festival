
/* File generated by gen_cfile.py. Should not be modified. */

#include "TestSlave.h"

/**************************************************************************/
/* Declaration of the mapped variables                                    */
/**************************************************************************/
INTEGER16 SlaveMap12 = 0x00;		/* Mapped at index 0x200B, subindex 0x00 */
INTEGER16 SlaveMap13 = 0x4D2;		/* Mapped at index 0x200C, subindex 0x00 */

/**************************************************************************/
/* Declaration of the value range types                                   */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 TestSlave_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 TestSlave_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 TestSlave_iam_a_slave = 1;

TIMER_HANDLE TestSlave_heartBeatTimers[1];

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 TestSlave_obj1000 = 0x12D;	/* 301 */
                    subindex TestSlave_Index1000[] = 
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1000 }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 TestSlave_obj1001 = 0x0;	/* 0 */
                    subindex TestSlave_Index1001[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_obj1001 }
                     };

/* index 0x1003 :   Pre-defined Error Field. */
                    UNS8 TestSlave_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1003[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    ODCallback_t TestSlave_Index1003_callbacks[] = 
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex TestSlave_Index1003[] = 
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1003 },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[0] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[1] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[2] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[3] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[4] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[5] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[6] },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1003[7] }
                     };

/* index 0x1005 :   SYNC COB ID. */
                    UNS32 TestSlave_obj1005 = 0x80;	/* 128 */
                    ODCallback_t TestSlave_Index1005_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex TestSlave_Index1005[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1005 }
                     };

/* index 0x1006 :   Communication / Cycle Period. */
                    UNS32 TestSlave_obj1006 = 0x0;	/* 0 */
                    ODCallback_t TestSlave_Index1006_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex TestSlave_Index1006[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1006 }
                     };

/* index 0x1010 :   Store parameters. */
                    UNS8 TestSlave_highestSubIndex_obj1010 = 4; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1010_Save_All_Parameters = 0x0;	/* 0 */
                    UNS32 TestSlave_obj1010_Save_Communication_Parameters = 0x0;	/* 0 */
                    UNS32 TestSlave_obj1010_Save_Application_Parameters = 0x0;	/* 0 */
                    UNS32 TestSlave_obj1010_Save_Manufacturer_Parameters = 0x0;	/* 0 */
                    ODCallback_t TestSlave_Index1010_callbacks[] = 
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex TestSlave_Index1010[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1010 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1010_Save_All_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1010_Save_Communication_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1010_Save_Application_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1010_Save_Manufacturer_Parameters }
                     };

/* index 0x1011 :   Restore Default Parameters. */
                    UNS8 TestSlave_highestSubIndex_obj1011 = 4; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1011_Restore_All_Default_Parameters = 0x0;	/* 0 */
                    UNS32 TestSlave_obj1011_Restore_Communication_Default_Parameters = 0x0;	/* 0 */
                    UNS32 TestSlave_obj1011_Restore_Application_Default_Parameters = 0x0;	/* 0 */
                    UNS32 TestSlave_obj1011_Restore_Manufacturer_Default_Parameters = 0x0;	/* 0 */
                    ODCallback_t TestSlave_Index1011_callbacks[] = 
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex TestSlave_Index1011[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1011 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1011_Restore_All_Default_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1011_Restore_Communication_Default_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1011_Restore_Application_Default_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1011_Restore_Manufacturer_Default_Parameters }
                     };

/* index 0x1014 :   Emergency COB ID. */
                    UNS32 TestSlave_obj1014 = 0x80;	/* 128 */
                    subindex TestSlave_Index1014[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1014 }
                     };

/* index 0x1016 :   Consumer Heartbeat Time */
                    UNS8 TestSlave_highestSubIndex_obj1016 = 0;
                    UNS32 TestSlave_obj1016[]={0};

/* index 0x1017 :   Producer Heartbeat Time. */
                    UNS16 TestSlave_obj1017 = 0x30;	/* 0 */
                    ODCallback_t TestSlave_Index1017_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex TestSlave_Index1017[] = 
                     {
                       { RW, uint16, sizeof (UNS16), (void*)&TestSlave_obj1017 }
                     };

/* index 0x1018 :   Identity. */
                    UNS8 TestSlave_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1018_Vendor_ID = 0x12345678;	/* 305419896 */
                    UNS32 TestSlave_obj1018_Product_Code = 0x90123456;	/* 2417112150 */
                    UNS32 TestSlave_obj1018_Revision_Number = 0x78901234;	/* 2022707764 */
                    UNS32 TestSlave_obj1018_Serial_Number = 0x56789012;	/* 1450741778 */
                    subindex TestSlave_Index1018[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1018 },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1018_Vendor_ID },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1018_Product_Code },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1018_Revision_Number },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1018_Serial_Number }
                     };

/* index 0x1200 :   Server SDO Parameter. */
                    UNS8 TestSlave_highestSubIndex_obj1200 = 2; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1200_COB_ID_Client_to_Server_Receive_SDO = 0x600;	/* 1536 */
                    UNS32 TestSlave_obj1200_COB_ID_Server_to_Client_Transmit_SDO = 0x580;	/* 1408 */
                    subindex TestSlave_Index1200[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1200 },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1200_COB_ID_Client_to_Server_Receive_SDO },
                       { RO, uint32, sizeof (UNS32), (void*)&TestSlave_obj1200_COB_ID_Server_to_Client_Transmit_SDO }
                     };

/* index 0x1802 :   Transmit PDO 3 Parameter. */
                    UNS8 TestSlave_highestSubIndex_obj1802 = 5; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1802_COB_ID_used_by_PDO = 0x383;	/* 896 */
                    UNS8 TestSlave_obj1802_Transmission_Type = 0xFF;	/* 255 */
                    UNS16 TestSlave_obj1802_Inhibit_Time = 0x1388;	/* 5000 */
                    UNS8 TestSlave_obj1802_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 TestSlave_obj1802_Event_Timer = 0x3E8;	/* 1000 */
                    ODCallback_t TestSlave_Index1802_callbacks[] = 
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex TestSlave_Index1802[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1802 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1802_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&TestSlave_obj1802_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&TestSlave_obj1802_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&TestSlave_obj1802_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&TestSlave_obj1802_Event_Timer }
                     };

/* index 0x1803 :   Transmit PDO 4 Parameter. */
                    UNS8 TestSlave_highestSubIndex_obj1803 = 5; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1803_COB_ID_used_by_PDO = 0x483;	/* 1152 */
                    UNS8 TestSlave_obj1803_Transmission_Type = 0xFD;	/* 253 */
                    UNS16 TestSlave_obj1803_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 TestSlave_obj1803_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 TestSlave_obj1803_Event_Timer = 0x0;	/* 0 */
                    ODCallback_t TestSlave_Index1803_callbacks[] = 
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex TestSlave_Index1803[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1803 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1803_COB_ID_used_by_PDO },
                       { RW|TO_BE_SAVE, uint8, sizeof (UNS8), (void*)&TestSlave_obj1803_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&TestSlave_obj1803_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&TestSlave_obj1803_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&TestSlave_obj1803_Event_Timer }
                     };

/* index 0x1A02 :   Transmit PDO 3 Mapping. */
                    UNS8 TestSlave_highestSubIndex_obj1A02 = 1; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1A02[] = 
                    {
                      0x200B0010	/* 537591824 */
                    };
                    subindex TestSlave_Index1A02[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1A02 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1A02[0] }
                     };

/* index 0x1A03 :   Transmit PDO 4 Mapping. */
                    UNS8 TestSlave_highestSubIndex_obj1A03 = 1; /* number of subindex - 1*/
                    UNS32 TestSlave_obj1A03[] = 
                    {
                      0x200C0010	/* 537657360 */
                    };
                    subindex TestSlave_Index1A03[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&TestSlave_highestSubIndex_obj1A03 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestSlave_obj1A03[0] }
                     };

/* index 0x200B :   Mapped variable SlaveMap12 */
                    subindex TestSlave_Index200B[] = 
                     {
                       { RW, int16, sizeof (INTEGER16), (void*)&SlaveMap12 }
                     };

/* index 0x200C :   Mapped variable SlaveMap13 */
                    subindex TestSlave_Index200C[] = 
                     {
                       { RW, int16, sizeof (INTEGER16), (void*)&SlaveMap13 }
                     };

const indextable TestSlave_objdict[] = 
{
  { (subindex*)TestSlave_Index1000,sizeof(TestSlave_Index1000)/sizeof(TestSlave_Index1000[0]), 0x1000},
  { (subindex*)TestSlave_Index1001,sizeof(TestSlave_Index1001)/sizeof(TestSlave_Index1001[0]), 0x1001},
  { (subindex*)TestSlave_Index1003,sizeof(TestSlave_Index1003)/sizeof(TestSlave_Index1003[0]), 0x1003},
  { (subindex*)TestSlave_Index1005,sizeof(TestSlave_Index1005)/sizeof(TestSlave_Index1005[0]), 0x1005},
  { (subindex*)TestSlave_Index1006,sizeof(TestSlave_Index1006)/sizeof(TestSlave_Index1006[0]), 0x1006},
  { (subindex*)TestSlave_Index1010,sizeof(TestSlave_Index1010)/sizeof(TestSlave_Index1010[0]), 0x1010},
  { (subindex*)TestSlave_Index1011,sizeof(TestSlave_Index1011)/sizeof(TestSlave_Index1011[0]), 0x1011},
  { (subindex*)TestSlave_Index1014,sizeof(TestSlave_Index1014)/sizeof(TestSlave_Index1014[0]), 0x1014},
  { (subindex*)TestSlave_Index1017,sizeof(TestSlave_Index1017)/sizeof(TestSlave_Index1017[0]), 0x1017},
  { (subindex*)TestSlave_Index1018,sizeof(TestSlave_Index1018)/sizeof(TestSlave_Index1018[0]), 0x1018},
  { (subindex*)TestSlave_Index1200,sizeof(TestSlave_Index1200)/sizeof(TestSlave_Index1200[0]), 0x1200},

  { (subindex*)TestSlave_Index1802,sizeof(TestSlave_Index1802)/sizeof(TestSlave_Index1802[0]), 0x1802},
  { (subindex*)TestSlave_Index1803,sizeof(TestSlave_Index1803)/sizeof(TestSlave_Index1803[0]), 0x1803},
//  { (subindex*)TestSlave_Index1804,sizeof(TestSlave_Index1804)/sizeof(TestSlave_Index1804[0]), 0x1804},

  { (subindex*)TestSlave_Index1A02,sizeof(TestSlave_Index1A02)/sizeof(TestSlave_Index1A02[0]), 0x1A02},
  { (subindex*)TestSlave_Index1A03,sizeof(TestSlave_Index1A03)/sizeof(TestSlave_Index1A03[0]), 0x1A03},
//  { (subindex*)TestSlave_Index1A04,sizeof(TestSlave_Index1A04)/sizeof(TestSlave_Index1A04[0]), 0x1A04},

  { (subindex*)TestSlave_Index200B,sizeof(TestSlave_Index200B)/sizeof(TestSlave_Index200B[0]), 0x200B},
  { (subindex*)TestSlave_Index200C,sizeof(TestSlave_Index200C)/sizeof(TestSlave_Index200C[0]), 0x200C},
};

const indextable * TestSlave_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks)
{
	int i;
	*callbacks = NULL;
	switch(wIndex){
		case 0x1000: i = 0;break;
		case 0x1001: i = 1;break;
		case 0x1003: i = 2;*callbacks = TestSlave_Index1003_callbacks; break;
		case 0x1005: i = 3;*callbacks = TestSlave_Index1005_callbacks; break;
		case 0x1006: i = 4;*callbacks = TestSlave_Index1006_callbacks; break;
		case 0x1010: i = 5;*callbacks = TestSlave_Index1010_callbacks; break;
		case 0x1011: i = 6;*callbacks = TestSlave_Index1011_callbacks; break;
		case 0x1014: i = 7;break;
		case 0x1017: i = 8;*callbacks = TestSlave_Index1017_callbacks; break;
		case 0x1018: i = 9;break;
		case 0x1200: i = 10;break;
		
		case 0x1802: i = 11;*callbacks = TestSlave_Index1802_callbacks; break;
		case 0x1803: i = 12;*callbacks = TestSlave_Index1803_callbacks; break;
		
		case 0x1A02: i = 13;break;
		case 0x1A03: i = 14;break;
		
		case 0x200B: i = 15;break;
		case 0x200C: i = 16;break;
		default:
			*errorCode = OD_NO_SUCH_OBJECT;
			return NULL;
	}
	*errorCode = OD_SUCCESSFUL;
	return &TestSlave_objdict[i];
}

/* 
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status TestSlave_PDO_status[5] = {s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer};

quick_index TestSlave_firstIndex = {
  10, /* SDO_SVR */
  0, /* SDO_CLT */
  0, /* PDO_RCV */
  0, /* PDO_RCV_MAP */
  11, /* PDO_TRS */
  13 /* PDO_TRS_MAP */
};

quick_index TestSlave_lastIndex = {
  10, /* SDO_SVR */
  0, /* SDO_CLT */
  0, /* PDO_RCV */
  0, /* PDO_RCV_MAP */
  12, /* PDO_TRS */
  14 /* PDO_TRS_MAP */
};

UNS16 TestSlave_ObjdictSize = sizeof(TestSlave_objdict)/sizeof(TestSlave_objdict[0]); 


CO_Data TestSlave_Data = CANOPEN_NODE_DATA_INITIALIZER(TestSlave);
