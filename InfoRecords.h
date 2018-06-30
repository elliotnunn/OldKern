/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * "Portions Copyright (c) 1999 Apple Computer, Inc.  All Rights
 * Reserved.  This file contains Original Code and/or Modifications of
 * Original Code as defined in and that are subject to the Apple Public
 * Source License Version 1.0 (the 'License').  You may not use this file
 * except in compliance with the License.  Please obtain a copy of the
 * License at http://www.apple.com/publicsource and read it before using
 * this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License."
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 	File:		PPCInfoRecordsPriv.h
 
 	Contains:	PowerPC information records created by hardware intialization and maintained by the NanoKernel.
 
 	Version:	Mac OS
 
 	DRI:		Jim Murphy
 
 	Copyright:	© 1997-1998 by Apple Computer, Inc., all rights reserved.
 
 	Warning:	*** APPLE INTERNAL USE ONLY ***
 				This file contains unreleased SPI's
 
 	BuildInfo:	Built by:			Naga Pappireddi
 				With Interfacer:	3.0d9 (PowerPC native)
 				From:				PPCInfoRecordsPriv.i
 					Revision:		18
 					Dated:			9/9/98
 					Last change by:	RAV
 					Last comment:	Set nanokernel info rev to 1.0.4. I'm reserving 2.0.0 for the
 
 	Bugs:		Report bugs to Radar component "System Interfaces", "Latest"
 				List the version information (from above) in the Problem Description.
 
*/

/*
  _______________________________________________________________________
  	Configuration Info Record
  	Used to pass Configuration information from the Boot Program to the
  	NanoKernel for data structure and address mapping initialization.
  _______________________________________________________________________
*/

struct NKConfigurationInfo {
																/*	Physical ROM Info*/
	unsigned int 							ROMCheckSumByte0;			/* ROM Checksum - Byte Lane 0*/
	unsigned int 							ROMCheckSumByte1;			/* ROM Checksum - Byte Lane 1*/
	unsigned int 							ROMCheckSumByte2;			/* ROM Checksum - Byte Lane 2*/
	unsigned int 							ROMCheckSumByte3;			/* ROM Checksum - Byte Lane 3*/
	unsigned int 							ROMCheckSumByte4;			/* ROM Checksum - Byte Lane 4*/
	unsigned int 							ROMCheckSumByte5;			/* ROM Checksum - Byte Lane 5*/
	unsigned int 							ROMCheckSumByte6;			/* ROM Checksum - Byte Lane 6*/
	unsigned int 							ROMCheckSumByte7;			/* ROM Checksum - Byte Lane 7*/
	unsigned int 							ROMCheckSum64;				/* ROM Checksum - 64 bit sum of doublewords*/
	unsigned int 							ROMCheckSum64_;				/* ROM Checksum - 64 bit sum of doublewords*/

	unsigned int 							ROMImageBaseOffset;			/* Offset of Base of total ROM image*/
	unsigned int 							ROMImageSize;				/* Number of bytes in ROM image*/
	unsigned int 							ROMImageVersion;			/* ROM Version number for entire ROM*/

																/*	ROM component Info (offsets are from base of ConfigInfo page)*/
	unsigned int 							Mac68KROMOffset;			/* Offset of base of Macintosh 68K ROM*/
	unsigned int 							Mac68KROMSize;				/* Number of bytes in Macintosh 68K ROM*/

	unsigned int 							ExceptionTableOffset;		/* Offset of base of PowerPC Exception Table Code*/
	unsigned int 							ExceptionTableSize;			/* Number of bytes in PowerPC Exception Table Code*/

	unsigned int 							HWInitCodeOffset;			/* Offset of base of Hardware Init Code*/
	unsigned int 							HWInitCodeSize;				/* Number of bytes in Hardware Init Code*/

	unsigned int 							KernelCodeOffset;			/* Offset of base of NanoKernel Code*/
	unsigned int 							KernelCodeSize;				/* Number of bytes in NanoKernel Code*/

	unsigned int 							EmulatorCodeOffset;			/* Offset of base of Emulator Code*/
	unsigned int 							EmulatorCodeSize;			/* Number of bytes in Emulator Code*/

	unsigned int 							OpcodeTableOffset;			/* Offset of base of Opcode Table*/
	unsigned int 							OpcodeTableSize;			/* Number of bytes in Opcode Table*/

																/*	Offsets within the Emulator Data Page.*/
	unsigned char 							BootstrapVersion[16];		/* Bootstrap loader version info*/
	unsigned int 							BootVersionOffset;			/* offset within EmulatorData of BootstrapVersion*/
	unsigned int 							ECBOffset;					/* offset within EmulatorData of ECB*/
	unsigned int 							IplValueOffset;				/* offset within EmulatorData of IplValue*/

																/*	Offsets within the Emulator Code.*/
	unsigned int 							EmulatorEntryOffset;		/* offset within Emulator Code of entry point*/
	unsigned int 							KernelTrapTableOffset;		/* offset within Emulator Code of KernelTrapTable*/

																/*	Interrupt Passing Masks.*/
	unsigned int 							TestIntMaskInit;			/* initial value for test interrupt mask*/
	unsigned int 							ClearIntMaskInit;			/* initial value for clear interrupt mask*/
	unsigned int 							PostIntMaskInit;			/* initial value for post interrupt mask*/
	unsigned int 							LA_InterruptCtl;			/* logical address of Interrupt Control I/O page*/
	unsigned char 							InterruptHandlerKind;		/* kind of handler to use*/
	unsigned char 							filler1;
	unsigned short 							filler2;

	unsigned int 							LA_InfoRecord;				/* logical address of InfoRecord page*/
	unsigned int 							LA_KernelData;				/* logical address of KernelData page*/
	unsigned int 							LA_EmulatorData;			/* logical address of EmulatorData page*/
	unsigned int 							LA_DispatchTable;			/* logical address of Dispatch Table*/
	unsigned int 							LA_EmulatorCode;			/* logical address of Emulator Code*/

	unsigned int 							MacLowMemInitOffset;		/* offset to list of LowMem addr/data values*/

																/*	Address Space Mapping.*/
	unsigned int 							PageAttributeInit;			/* default WIMG/PP settings for PTE creation*/
	unsigned int 							PageMapInitSize;			/* size of page mapping info*/
	unsigned int 							PageMapInitOffset;			/* offset to page mapping info (from base of ConfigInfo)*/
	unsigned int 							PageMapIRPOffset;			/* offset of InfoRecord map info (from base of PageMap)*/
	unsigned int 							PageMapKDPOffset;			/* offset of KernelData map info (from base of PageMap)*/
	unsigned int 							PageMapEDPOffset;			/* offset of EmulatorData map info (from base of PageMap)*/

	unsigned int 							SegMap32SupInit[32];		/* 32 bit mode Segment Map Supervisor space*/
	unsigned int 							SegMap32UsrInit[32];		/* 32 bit mode Segment Map User space*/
	unsigned int 							SegMap32CPUInit[32];		/* 32 bit mode Segment Map CPU space*/
	unsigned int 							SegMap32OvlInit[32];		/* 32 bit mode Segment Map Overlay mode*/

	unsigned int 							BATRangeInit[32];			/* BAT mapping ranges*/

	unsigned int 							BatMap32SupInit;			/* 32 bit mode BAT Map Supervisor space*/
	unsigned int 							BatMap32UsrInit;			/* 32 bit mode BAT Map User space*/
	unsigned int 							BatMap32CPUInit;			/* 32 bit mode BAT Map CPU space*/
	unsigned int 							BatMap32OvlInit;			/* 32 bit mode BAT Map Overlay mode*/

																/*	Only needed for Smurf*/
	unsigned int 							SharedMemoryAddr;			/* physical address of Mac/Smurf shared message mem*/

	unsigned int 							PA_RelocatedLowMemInit;		/* physical address of RelocatedLowMem*/

	unsigned int 							OpenFWBundleOffset;			/* Offset of base of OpenFirmware PEF Bundle*/
	unsigned int 							OpenFWBundleSize;			/* Number of bytes in OpenFirmware PEF Bundle*/

	unsigned int 							LA_OpenFirmware;			/* logical address of Open Firmware*/
	unsigned int 							PA_OpenFirmware;			/* physical address of Open Firmware*/
	unsigned int 							LA_HardwarePriv;			/* logical address of HardwarePriv callback*/

	unsigned int 							filler3[2];					/* pad structure size out to a cache block*/
};

/*
  _______________________________________________________________________
  	System Info Record
  	Used to pass System information from the NanoKernel to user mode
  	software.
  _______________________________________________________________________
*/


enum {
	nkSystemInfoPtr				= 0x5FFFEFF0,					/* logical address of SystemInfo record*/
	nkSystemInfoVer				= 0x5FFFEFF4,					/* version number of SystemInfo record*/
	nkSystemInfoLen				= 0x5FFFEFF6					/* length of SystemInfo record*/
};


struct NKSystemInfo {
	unsigned int 							PhysicalMemorySize;			/* Number of bytes in Physical RAM*/
	unsigned int 							UsableMemorySize;			/* Number of bytes in Usable RAM*/
	unsigned int 							LogicalMemorySize;			/* Number of bytes in Logical RAM*/
	unsigned int 							HashTableSize;				/* Number of bytes in Memory Hash Table*/

	unsigned int 							L2DataCacheTotalSize;		/* number of bytes in the L2 Data Cache*/
	unsigned int 							L2InstCacheTotalSize;		/* number of bytes in the L2 Instruction Cache*/
	unsigned short 							L2CombinedCaches;			/* 1 <- combined or no cache, 0 <- split cache*/
	unsigned short 							L2InstCacheBlockSize;		/* number of bytes in a Block of the L2 Instruction Cache*/
	unsigned short 							L2DataCacheBlockSize;		/* number of bytes in a Block of the L2 Data Cache*/
	unsigned short 							L2InstCacheAssociativity;	/* Associativity of the L2 Instruction Cache*/
	unsigned short 							L2DataCacheAssociativity;	/* Associativity of the L2 Data Cache*/
	unsigned short 							unused_1;					/* unused*/

	unsigned short 							unused_2;					/* unused*/
	unsigned char 							FlashManufacturerCode;		/* Flash ROM Manufacturer code*/
	unsigned char 							FlashDeviceCode;			/* Flash ROM Device code*/
	unsigned int 							FlashStart;					/* Starting address of Flash ROM*/
	unsigned int 							FlashSize;					/* Number of bytes in  Flash ROM*/



/* 0x30 */


	unsigned int 							Bank0Start;					/* Starting address of RAM bank 0*/
	unsigned int 							Bank0Size;					/* Number of bytes in  RAM bank 0*/
	unsigned int 							Bank1Start;					/* Starting address of RAM bank 1*/
	unsigned int 							Bank1Size;					/* Number of bytes in  RAM bank 1*/
	unsigned int 							Bank2Start;					/* Starting address of RAM bank 2*/
	unsigned int 							Bank2Size;					/* Number of bytes in  RAM bank 2*/
	unsigned int 							Bank3Start;					/* Starting address of RAM bank 3*/
	unsigned int 							Bank3Size;					/* Number of bytes in  RAM bank 3*/
	unsigned int 							Bank4Start;					/* Starting address of RAM bank 4*/
	unsigned int 							Bank4Size;					/* Number of bytes in  RAM bank 4*/
	unsigned int 							Bank5Start;					/* Starting address of RAM bank 5*/
	unsigned int 							Bank5Size;					/* Number of bytes in  RAM bank 5*/
	unsigned int 							Bank6Start;					/* Starting address of RAM bank 6*/
	unsigned int 							Bank6Size;					/* Number of bytes in  RAM bank 6*/
	unsigned int 							Bank7Start;					/* Starting address of RAM bank 7*/
	unsigned int 							Bank7Size;					/* Number of bytes in  RAM bank 7*/
	unsigned int 							Bank8Start;					/* Starting address of RAM bank 8*/
	unsigned int 							Bank8Size;					/* Number of bytes in  RAM bank 8*/
	unsigned int 							Bank9Start;					/* Starting address of RAM bank 9*/
	unsigned int 							Bank9Size;					/* Number of bytes in  RAM bank 9*/
	unsigned int 							Bank10Start;				/* Starting address of RAM bank 10*/
	unsigned int 							Bank10Size;					/* Number of bytes in  RAM bank 10*/
	unsigned int 							Bank11Start;				/* Starting address of RAM bank 11*/
	unsigned int 							Bank11Size;					/* Number of bytes in  RAM bank 11*/
	unsigned int 							Bank12Start;				/* Starting address of RAM bank 12*/
	unsigned int 							Bank12Size;					/* Number of bytes in  RAM bank 12*/
	unsigned int 							Bank13Start;				/* Starting address of RAM bank 13*/
	unsigned int 							Bank13Size;					/* Number of bytes in  RAM bank 13*/
	unsigned int 							Bank14Start;				/* Starting address of RAM bank 14*/
	unsigned int 							Bank14Size;					/* Number of bytes in  RAM bank 14*/
	unsigned int 							Bank15Start;				/* Starting address of RAM bank 15*/
	unsigned int 							Bank15Size;					/* Number of bytes in  RAM bank 15*/
	unsigned int 							Bank16Start;				/* Starting address of RAM bank 16*/
	unsigned int 							Bank16Size;					/* Number of bytes in  RAM bank 16*/
	unsigned int 							Bank17Start;				/* Starting address of RAM bank 17*/
	unsigned int 							Bank17Size;					/* Number of bytes in  RAM bank 17*/
};

enum {
	kMaxBanks					= 26,							/* 6 banks, 0É25*/
	kSystemInfoVersion			= 0x0105						/* 1.0.5*/
};


/*
  _______________________________________________________________________
  	Diagnostic Info Record
  	Used to pass Diagnostic information from the power on Diagnostics to
  	the NanoKernel, and from the NanoKernel to user mode software.
  _______________________________________________________________________
*/


enum {
	nkDiagnosticInfoPtr			= 0x5FFFEFE8,					/* logical address of DiagnosticInfo record*/
	nkDiagnosticInfoVer			= 0x5FFFEFEC,					/* version number of DiagnosticInfo record*/
	nkDiagnosticInfoLen			= 0x5FFFEFEE					/* length of DiagnosticInfo record*/
};


struct NKDiagnosticInfo {
	unsigned int 							BankMBFailOffset;			/* Mother Board RAM failure code*/
	unsigned int 							BankAFailOffset;			/* Bank A RAM failure code*/
	unsigned int 							BankBFailOffset;			/* Bank B RAM failure code*/
	unsigned int 							BankCFailOffset;			/* Bank C RAM failure code*/

	unsigned int 							BankDFailOffset;			/* Bank D RAM failure code*/
	unsigned int 							BankEFailOffset;			/* Bank E RAM failure code*/
	unsigned int 							BankFFailOffset;			/* Bank F RAM failure code*/
	unsigned int 							BankGFailOffset;			/* Bank G RAM failure code*/

	unsigned int 							BankHFailOffset;			/* Bank H RAM failure code*/
	unsigned int 							CacheFailOffset;			/* cache failure code*/
	unsigned int 							LongBootParamOffset;		/* on longBoot this is where the params will be*/
	unsigned int 							POSTTraceOffset;			/* this tells us what route the POST took*/

	unsigned int 							POSTOldWarmOffset;			/* logged address of old warmstart flag*/
	unsigned int 							POSTOldLongOffset;			/* logged address of old long boot flag*/
	unsigned int 							POSTOldGlobbOffset;			/* logged address of old Diagnostic Info Record*/
	unsigned int 							POSTOldParamOffset;			/* the params from the old diag globb*/

	unsigned int 							POSTStartRTCUOffset;		/* PPC Real Time Clock Upper at start of POST*/
	unsigned int 							POSTStartRTCLOffset;		/* PPC Real Time Clock Lower at start of POST*/
	unsigned int 							POSTEndRTCUOffset;			/* PPC Real Time Clock Upper at end of POST*/
	unsigned int 							POSTEndRTCLOffset;			/* PPC Real Time Clock Lower at end of POST*/

	unsigned int 							POSTTestTypeOffset;			/* when long RAM tests fail test type which failed is put here*/
	unsigned int 							POSTError2Offset;			/* result codes from tests*/
	unsigned int 							POSTError3Offset;			/* result codes from tests*/
	unsigned int 							POSTError4Offset;			/* result codes from tests*/

	unsigned char 							RegistersStore[140];		/* store all 60x registers here, still fit into 256 bytes size.*/

	unsigned int 							DiagPOSTResult2;			/* POST results*/
	unsigned int 							DiagPOSTResult1;			/* POST results*/
	unsigned int 							DiagLongBootSig;			/* Burn in restart flag*/
	unsigned int 							DiagWarmStartHigh;			/* First long of native warm start  (WLSC)		<SM44>*/
	unsigned int 							DiagWarmStartLow;			/* Second long of native warm start (SamB)		<SM44>*/
};

enum {
	kDiagnosticInfoVersion		= 0x0100						/* 1.0.0*/
};


/*
  _______________________________________________________________________
  	NanoKernel Info Record
  	Used to pass NanoKernel statistics from the NanoKernel to user mode
  	software.
  _______________________________________________________________________
*/


enum {
	nkNanoKernelInfoPtr			= 0x5FFFEFE0,					/* logical address of NanoKernelInfo record*/
	nkNanoKernelInfoVer			= 0x5FFFEFE4,					/* version number of NanoKernelInfo record*/
	nkNanoKernelInfoLen			= 0x5FFFEFE6					/* length of NanoKernelInfo record*/
};


struct NKNanoKernelInfo {
	unsigned int 							ExceptionCauseCounts[32];	/* counters per exception cause*/
	unsigned int 							NanoKernelCallCounts[16];	/* counters per NanoKernel call*/
	unsigned int 							ExternalIntCount;			/* count of External Interrupts*/
	unsigned int 							MisalignmentCount;			/* count of Misalignment Interrupts*/
	unsigned int 							FPUReloadCount;				/* count of FPU reloads on demand*/
	unsigned int 							DecrementerIntCount;		/* count of Decrementer Interrupts*/
	unsigned int 							QuietWriteCount;			/* count of Writes to Quiet Read-Only memory*/
	unsigned int 							HashTableCreateCount;		/* count of Hash Table Entry creations*/
	unsigned int 							HashTableDeleteCount;		/* count of Hash Table Entry deletions*/
	unsigned int 							HashTableOverflowCount;		/* count of Hash Table Entry overflows*/
	unsigned int 							EmulatedUnimpInstCount;		/* count of Emulated unimplemented instructions*/
	unsigned int 							NCBPtrCacheMissCount;		/* count of NCB Pointer cache misses*/
	unsigned int 							ExceptionPropagateCount;	/* count of Exceptions propagated to system*/
	unsigned int 							ExceptionForcedCount;		/* count of Exceptions forced to system*/
	unsigned int 							SysContextCpuTime;			/* CPU Time used by System Context*/
	unsigned int 							SysContextCpuTime_;			/* CPU Time used by System Context*/
	unsigned int 							AltContextCpuTime;			/* CPU Time used by Alternate Context*/
	unsigned int 							AltContextCpuTime_;			/* CPU Time used by Alternate Context*/
};

enum {
	kNanoKernelInfoVersion		= 0x0104						/* 1.0.4*/
};



/*
  _______________________________________________________________________
  	Processor Info Record
  	Used to pass Processor information from the NanoKernel to user mode
  	software.
  _______________________________________________________________________
*/


enum {
	nkProcessorInfoPtr			= 0x5FFFEFD8,					/* logical address of ProcessorInfo record*/
	nkProcessorInfoVer			= 0x5FFFEFDC,					/* version number of ProcessorInfo record*/
	nkProcessorInfoLen			= 0x5FFFEFDE					/* length of ProcessorInfo record*/
};


struct NKProcessorInfo {
	unsigned int 							ProcessorVersionReg;		/* contents of the PVR special purpose register*/
	unsigned int 							CpuClockRateHz;				/* CPU Clock frequency*/
	unsigned int 							BusClockRateHz;				/* Bus Clock frequency*/
	unsigned int 							DecClockRateHz;				/* Decrementer Clock frequency*/
	unsigned int 							PageSize;					/* number of bytes in a memory page*/
	unsigned int 							DataCacheTotalSize;			/* number of bytes in the Data Cache*/
	unsigned int 							InstCacheTotalSize;			/* number of bytes in the Instruction Cache*/
	unsigned short 							CoherencyBlockSize;			/* number of bytes in a Coherency Block*/
	unsigned short 							ReservationGranuleSize;		/* number of bytes in a Reservation Granule*/
	unsigned short 							CombinedCaches;				/* 1 <- combined or no cache, 0 <- split cache*/
	unsigned short 							InstCacheLineSize;			/* number of bytes in a Line of the Instruction Cache*/
	unsigned short 							DataCacheLineSize;			/* number of bytes in a Line of the Data Cache*/
	unsigned short 							DataCacheBlockSizeTouch;	/* number of bytes in a Block for DCBT DCBTST*/
	unsigned short 							InstCacheBlockSize;			/* number of bytes in a Block of the Instruction Cache*/
	unsigned short 							DataCacheBlockSize;			/* number of bytes in a Block of the Data Cache*/
	unsigned short 							InstCacheAssociativity;		/* Associativity of the Instruction Cache*/
	unsigned short 							DataCacheAssociativity;		/* Associativity of the Data Cache*/

	unsigned short 							TransCacheTotalSize;		/* number of entries in the Translation Cache*/
	unsigned short 							TransCacheAssociativity;	/* Associativity of the Translation Cache*/

	char filler[12];
};
/*
   ProcessorFlags - Definitions for the processor flags field. These are bit positions,
  					as in Ò1 << hasVMXÓ, and not masks.
*/

enum {
	hasL2CR						= 0,
	hasPLRUL1					= 1,
	hasTAU						= 2,
	hasVMX						= 3
};



enum {
	kProcessorInfoVersion		= 0x0101						/* 1.0.1*/
};


/*
  _______________________________________________________________________
  	Hardware Info Record
  	Used to pass hardware information from the NanoKernel to user mode
  	software.
  _______________________________________________________________________
*/


enum {
	nkHWInfoPtr					= 0x5FFFEFD0,					/* logical address of HWInfo record*/
	nkHWInfoVer					= 0x5FFFEFD4,					/* version number of HWInfo record*/
	nkHWInfoLen					= 0x5FFFEFD6					/* length of HWInfo record*/
};


enum {
	nkHWInfoFlagSlowMESH		= 1,							/* set if fast MESH doesn't work on this box*/
	nkHWInfoFlagAsynchMESH		= 2,							/* set if Synchronous MESH doesn't work on this box*/
	nkHWInfoFlagNoCopySWTLB		= 4								/* set if the software TLB walk code for 603 should NOT be copied*/
};


struct NKHWInfo {
	unsigned int 							MacROM_Base;				/* base address (physical) of Mac ROM*/
	unsigned int 							DeviceTreeBase;				/* base address of the copied device tree properties*/
	unsigned int 							UniversalInfoTableBase;		/* base address of the Universal Info Table*/
	unsigned int 							ConfigInfoTableBase;		/* base address of the Config Info Table*/
	unsigned short *						VectorLookupTable;			/* base address of the interrupt vector lookup table*/
	unsigned int *						VectorMaskTable;			/* base address of the interrupt vector mask table*/

	unsigned int 							OpenPICBaseAddr;			/* OpenPIC base address*/

	unsigned char *							ISAMaster8259;				/* ISA Master 8259 ports*/
	unsigned char *							ISASlave8259;				/* ISA Slave 8259 ports*/
	unsigned int *						InterruptAck8259;			/* address to read to ack 8259 interrupt*/

																/* interrupt pending bits (actively changing)*/

	unsigned int 							PendingInts[2];				/* 64 bits of pending interrupts*/

																/* some Mac I/O device base addresses*/

	unsigned int 							ADB_Base;					/* base address of ADB*/
	unsigned int 							SCSI_DMA_Base;				/* base address of SCSI DMA registers*/

																/* RTAS related stuff*/

	unsigned int 							RTAS_PrivDataArea;			/* RTAS private data area */
	unsigned int 							MacOS_NVRAM_Offset;			/* offset into nvram to MacOS data*/

	unsigned int 							RTAS_NVRAM_Fetch;			/* token for RTAS NVRAM fetch*/
	unsigned int 							RTAS_NVRAM_Store;			/* token for RTAS NVRAM store*/
	unsigned int 							RTAS_Get_Clock;				/* token for RTAS clock get*/
	unsigned int 							RTAS_Set_Clock;				/* token for RTAS clock set*/
	unsigned int 							RTAS_Restart;				/* token for RTAS Restart*/
	unsigned int 							RTAS_Shutdown;				/* token for RTAS Shutdown*/
	unsigned int 							RTAS_Restart_At;			/* token for RTAS system startup at specified time*/
	unsigned int 							RTAS_EventScan;				/* token for RTAS event scan*/
	unsigned int 							RTAS_Check_Exception;		/* token for RTAS check exception*/
	unsigned int 							RTAS_Read_PCI_Config;		/* token for RTAS read PCI config*/
	unsigned int 							RTAS_Write_PCI_Config;		/* token for RTAS write PCI config*/

																/* SIO interrupt source numbers for the MPIC*/

	unsigned short 							SIOIntVect;					/* SIO (8259 cascade vector) vector number*/
	unsigned short 							SIOIntBit;					/* SIO (8259 cascade vector) bit number*/

	unsigned int 							Signature;					/* signature for this record ('Hnfo')*/

																/* more interrupt source numbers*/

	unsigned short 							SpuriousIntVect;			/* spurious vector number*/

	unsigned short 							CPU_ID;						/* the ID of this CPU (universal-tables-related)*/

	unsigned short 							SCCAIntVect;				/* SCC A (non-DMA) vector number*/
	unsigned short 							SCCBIntVect;				/* SCC B (non-DMA) vector number*/
	unsigned short 							SCSIIntVect;				/* SCSI vector number*/
	unsigned short 							SCSIDMAIntVect;				/* SCSI DMA vector number*/
	unsigned short 							VIAIntVect;					/* VIA vector number*/
	unsigned short 							VIAIntBit;					/* VIA bit number*/
	unsigned short 							ADBIntVect;					/* ADB vector number*/
	unsigned short 							NMIIntVect;					/* NMI vector number*/
	unsigned short 							NMIIntBit;					/* NMI bit number*/

																/* current (actively changing) interrupt handling variables*/

	unsigned short 							ISAPendingInt;				/* currently pending ISA/8259 interrupt*/
	unsigned char 							CompletedInts[8];			/* completed interrupts*/

	unsigned int 							HardwareInfoFlags;			/* 32 bits of flags (see enum above)*/

	unsigned int 							RTAS_Get_PowerOn_Time;		/* token for RTAS getting time for system startup*/

	unsigned int 							filler1[1];					/* pad to cache block alignment*/
};

enum {
	kHWInfoVersion				= 0x0103						/* 1.0.3*/
};


/*
  _______________________________________________________________________
  	Processor State Record
  	Used to save the state of the processor across sleep.
  _______________________________________________________________________
*/


enum {
	nkProcessorStatePtr			= 0x5FFFEFC8,					/* logical address of ProcessorState record*/
	nkProcessorStateVer			= 0x5FFFEFCC,					/* version number of ProcessorState record*/
	nkProcessorStateLen			= 0x5FFFEFCE					/* length of ProcessorState record*/
};


struct NKProcessorState {
	unsigned int 							saveDBAT0u;					/* place to store DBAT0U*/
	unsigned int 							saveDBAT0l;					/* place to store DBAT0L*/
	unsigned int 							saveDBAT1u;					/* place to store DBAT1U*/
	unsigned int 							saveDBAT1l;					/* place to store DBAT1L*/
	unsigned int 							saveDBAT2u;					/* place to store DBAT2U*/
	unsigned int 							saveDBAT2l;					/* place to store DBAT2L*/
	unsigned int 							saveDBAT3u;					/* place to store DBAT3U*/
	unsigned int 							saveDBAT3l;					/* place to store DBAT3L*/

	unsigned int 							saveIBAT0u;					/* place to store IBAT0U*/
	unsigned int 							saveIBAT0l;					/* place to store IBAT0L*/
	unsigned int 							saveIBAT1u;					/* place to store IBAT1U*/
	unsigned int 							saveIBAT1l;					/* place to store IBAT1L*/
	unsigned int 							saveIBAT2u;					/* place to store IBAT2U*/
	unsigned int 							saveIBAT2l;					/* place to store IBAT2L*/
	unsigned int 							saveIBAT3u;					/* place to store IBAT3U*/
	unsigned int 							saveIBAT3l;					/* place to store IBAT3L*/

	unsigned int 							saveSPRG0;					/* place to store SPRG0*/
	unsigned int 							saveSPRG1;					/* place to store SPRG1*/
	unsigned int 							saveSPRG2;					/* place to store SPRG2*/
	unsigned int 							saveSPRG3;					/* place to store SPRG3*/

	unsigned int 							saveL2CR;					/* place to store Arthur's L2CR*/

	unsigned int 							saveSRR0;					/* place to store SRR0*/
	unsigned int 							saveSRR1;					/* place to store SRR1*/
	unsigned int 							saveTBU;					/* place to store TBU*/
	unsigned int 							saveTBL;					/* place to store TBL*/
	unsigned int 							saveHID0;					/* place to store HID0*/
	unsigned int 							saveDEC;					/* place to store DEC*/
	unsigned int 							saveMSR;					/* place to store MSR*/
	unsigned int 							saveSDR1;					/* place to store SDR1*/

																/* saveKernelDataPtr needs to always be right after saveReturnAddr*/
																/* because of how the code works.  DO NOT CHANGE THIS ORDERING!*/

	unsigned int 							saveReturnAddr;				/* place to store the addr to jump to.*/
	unsigned int 							saveKernelDataPtr;			/* place to store the KernelDataPtr*/
	unsigned int 							saveContextPtr;				/* place to store the ContextPtr*/
};
