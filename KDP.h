#include "InfoRecords.h"

struct InfoRecord {
    long InfoRecordPtr;

    long Zero;

    long NKProcessorStatePtr;
    short NKProcessorStateVer;
    short NKProcessorStateLen;

    long NKHWInfoPtr;
    short NKHWInfoVer;
    short NKHWInfoLen;

    long NKProcessorInfoPtr;
    short NKProcessorInfoVer;
    short NKProcessorInfoLen;

    long NKNanoKernelInfoPtr;
    short NKNanoKernelInfoVer;
    short NKNanoKernelInfoLen;

    long NKDiagInfoPtr;
    short NKDiagInfoVer;
    short NKDiagInfoLen;

    long NKSystemInfoPtr;
    short NKSystemInfoVer;
    short NKSystemInfoLen;

    long NKProcessorInfoPtr2;
    short NKProcessorInfoVer2;
    short NKProcessorInfoLen2;
};

struct NanoKernelCallTable {
    long ReturnFromException;
    long RunAlternateContext;
    long ResetSystem;
    long VMDispatch;
    long PrioritizeInterrupts;
    long PowerDispatch;
    long RTASDispatch;
    long CacheDispatch;
    long MPDispatch;
    long _24;
    long _28;
    long _2c;
    long CallAdapterProcPPC;
    long _34;
    long CallAdapterProc68k;
    long Thud;
};

struct KDP {

    long r0;
    long r1;
    long r2;
    long r3;
    long r4;
    long r5;
    long r6;
    long r7;
    long r8;
    long r9;
    long r10;
    long r11;
    long r12;
    long r13;
    long r14;
    long r15;
    long r16;
    long r17;
    long r18;
    long r19;
    long r20;
    long r21;
    long r22;
    long r23;
    long r24;
    long r25;
    long r26;
    long r27;
    long r28;
    long r29;
    long r30;
    long r31;

    long SegMap32SupInit[32];                   // 080:100
    long SegMap32UsrInit[32];                   // 100:180
    long SegMap32CPUInit[32];                   // 180:200
    long SegMap32OvlInit[32];                   // 200:280
    long BATs[32];                          // 280:300


    char GAP[0x40];                         

    long NCBCacheLA0;                       // 340
    long NCBCachePA0;                       // 344
    long NCBCacheLA1;                       // 348
    long NCBCachePA1;                       // 34c
    long NCBCacheLA2;                       // 350
    long NCBCachePA2;                       // 354
    long NCBCacheLA3;                       // 358
    long NCBCachePA3;                       // 35c

    long VecBaseSystem[48];                 // 360:420 // when 68k emulator is running, *or* any MTask
    long VecBaseAlternate[48];              // 420:4e0 // native PowerPC in blue task
    long VecBaseMemRetry[48];                   // 4e0:5a0 // "FDP" instruction emulation
    long OldKDP;                            // 5a0 // gotten from the old SPRG0
    long OtherFreeThing;                    // 5a4
    long TopOfFreePages;                    // 5a8 // gotten from the old SPRG0
    long _5ac;                          // 5ac
    long PA_InterruptHandler;               // 5b0
    long LA_NCB;                            // 5b4 // most recent physical address found
    long HiLevelPerfMonitorBits;            // 5b8
    long _5bc;                          // 5bc
    long PerfMonitorBits;                   // 5c0
    long _5c4;                          // 5c4
    long SegMap32SupInitPtr;                // 5c8
    long BatMap32SupInit;                   // 5cc
    long SegMap32UsrInitPtr;                // 5d0
    long BatMap32UsrInit;                   // 5d4
    long SegMap32CPUInitPtr;                // 5d8
    long BatMap32CPUInit;                   // 5dc
    long SegMap32OvlInitPtr;                // 5e0
    long BatMap32OvlInit;                   // 5e4
    long _5e8;                          // 5e8
    long _5ec;                          // 5ec

    struct NanoKernelCallTable NanoKernelCallTable;                // 5f0:630

    long PA_ConfigInfo;                 // 630
    long PA_EmulatorData;                   // 634
    long KernelMemoryBase;              // 638
    long KernelMemoryEnd;                   // 63c // Top of HTAB (and entire kernel reserved area). Set by Init.s
    long PA_RelocatedLowMemInit;            // 640 // From ConfigInfo. Ptr to Mac LowMem vars, which Init.s sets up
    long SharedMemoryAddr;              // 644 // From ConfigInfo. Not sure what latest use is.
    long LA_EmulatorKernelTrapTable;        // 648 // Calculated from ConfigInfo.
    long PA_NanoKernelCode;             // 64c // Calculated by NanoKernel itself.
    long PA_FDP;                            // 650 // See notes in NanoKernel. Very interesting.
    long LA_ECB;                            // 654 // Logical ptr into EDP.
    long PA_ECB;                            // 658 // gets called "system context"
    long PA_ECB_Old;                        // 65c // copied from NKv<=01.01 to EWA.PA_ContextBlock.
    long _660;                          // 660
    long _664;                          // 664
    long _668;                          // 668
    long PA_PageMapEnd;                 // 66c // Set at the same time as PA_PageMapStart below...
    long TestIntMaskInit;                   // 670 // These are all copied from ConfigInfo...
    long PostIntMaskInit;                   // 674
    long ClearIntMaskInit;              // 678
    long PA_EmulatorIplValue;               // 67c // Physical ptr into EDP
    long SharedMemoryAddrPlus;          // 680 // Really not sure
    long PA_PageMapStart;                   // 684 // Physical ptr to PageMap (= KDP+0x920)
    long PageAttributeInit;             // 688 // defaults for page table entries (see ConfigInfo)
    long _68c;                          // 68c
    long _690;                          // 690
    long _694;                          // 694
    long _698;                          // 698
    long _69c;                          // 69c
    long PTEGMask;                      // 6a0
    long HTABORG;                           // 6a4
    long VMLogicalPages;                    // 6a8 // set at init and changed by VMInit
    long TotalPhysicalPages;                // 6ac // does not take into acct maximum MacOS memory
    long FlatPageListPtr;                   // 6b0 // VM puts this in system heap
    long VMMaxVirtualPages;             // 6b4 // always 5fffe000, even with VM on
    char CpuSpecificByte1;              // 6b8 // seems to contain flags (set from PVR & tbl by Init.s)
    char CpuSpecificByte2;              // 6b9 // probably not flags (set in same way)
    char _6ba;                          // 6ba
    char _6bb;                          // 6bb
    long _6bc;                          // 6bc
    long FlatPageListSegPtrs[16];                // 6c0

    //StartOfPanicArea                    // PROTECTED BY THUD LOCK
    long ThudSavedR0;                       // 700
    long ThudSavedR1;                       // 704 // via SPRG1
    long ThudSavedR2;                       // 708
    long ThudSavedR3;                       // 70c
    long ThudSavedR4;                       // 710
    long ThudSavedR5;                       // 714
    long ThudSavedR6;                       // 718
    long ThudSavedR7;                       // 71c
    long ThudSavedR8;                       // 720
    long ThudSavedR9;                       // 724
    long ThudSavedR10;                  // 728
    long ThudSavedR11;                  // 72c
    long ThudSavedR12;                  // 730
    long ThudSavedR13;                  // 734
    long ThudSavedR14;                  // 738
    long ThudSavedR15;                  // 73c
    long ThudSavedR16;                  // 740
    long ThudSavedR17;                  // 744
    long ThudSavedR18;                  // 748
    long ThudSavedR19;                  // 74c
    long ThudSavedR20;                  // 750
    long ThudSavedR21;                  // 754
    long ThudSavedR22;                  // 758
    long ThudSavedR23;                  // 75c
    long ThudSavedR24;                  // 760
    long ThudSavedR25;                  // 764
    long ThudSavedR26;                  // 768
    long ThudSavedR27;                  // 76c
    long ThudSavedR28;                  // 770
    long ThudSavedR29;                  // 774
    long ThudSavedR30;                  // 778
    long ThudSavedR31;                  // 77c
    long ThudSavedCR;                       // 780
    long ThudSavedMQ;                       // 784
    long ThudSavedXER;                  // 788
    long ThudSavedSPRG2;                    // 78c // 'LR'
    long ThudSavedCTR;                  // 790
    long ThudSavedPVR;                  // 794
    long ThudSavedDSISR;                    // 798
    long ThudSavedDAR;                  // 79c
    long ThudSavedTBU;                  // 7a0 // RTCU on 601
    long ThudSavedTB;                       // 7a4 // RTCL on 601
    long ThudSavedDEC;                  // 7a8
    long ThudSavedHID0;                 // 7ac
    long ThudSavedSDR;                  // 7b0
    long ThudSavedSRR0;                 // 7b4
    long ThudSavedSRR;                  // 7b8
    long ThudSavedMSR;                  // 7bc
    long ThudSavedSR0;                  // 7c0
    long ThudSavedSR1;                  // 7c4
    long ThudSavedSR2;                  // 7c8
    long ThudSavedSR3;                  // 7cc
    long ThudSavedSR4;                  // 7d0
    long ThudSavedSR5;                  // 7d4
    long ThudSavedSR6;                  // 7d8
    long ThudSavedSR7;                  // 7dc
    long ThudSavedSR8;                  // 7e0
    long ThudSavedSR9;                  // 7e4
    long ThudSavedSR10;                 // 7e8
    long ThudSavedSR11;                  // 7ec
    long ThudSavedSR12;                 // 7f0
    long ThudSavedSR13;                 // 7f4
    long ThudSavedSR14;                 // 7f8
    long ThudSavedSR15;                 // 7fc

    long ThudSavedF0[2];                     // KDP.BATs + 0xa0
    long ThudSavedF1[2];                     // 808
    long ThudSavedF2[2];                     // 810
    long ThudSavedF3[2];                     // 818
    long ThudSavedF4[2];                     // 820
    long ThudSavedF5[2];                     // 828
    long ThudSavedF6[2];                     // 830
    long ThudSavedF7[2];                     // 838
    long ThudSavedF8[2];                     // 840
    long ThudSavedF9[2];                     // 848
    long ThudSavedF10[2];                    // 850
    long ThudSavedF11[2];                    // 858
    long ThudSavedF12[2];                    // 860
    long ThudSavedF13[2];                    // 868
    long ThudSavedF14[2];                    // 870
    long ThudSavedF15[2];                    // 878
    long ThudSavedF16[2];                    // 880
    long ThudSavedF17[2];                    // 888
    long ThudSavedF18[2];                    // 890
    long ThudSavedF19[2];                    // 898
    long ThudSavedF20[2];                    // 8a0
    long ThudSavedF21[2];                    // 8a8
    long ThudSavedF22[2];                    // 8b0
    long ThudSavedF23[2];                    // 8b8
    long ThudSavedF24[2];                    // 8c0
    long ThudSavedF25[2];                    // 8c8
    long ThudSavedF26[2];                    // 8d0
    long ThudSavedF27[2];                    // 8d8
    long ThudSavedF28[2];                    // 8e0
    long ThudSavedF29[2];                    // 8e8
    long ThudSavedF30[2];                    // 8f0
    long ThudSavedF31[2];                    // 8f8

    long SomethingSerial;                   // 900 // 'fpscr'
    long ThudSavedLR;                       // 904 // 'caller'
    long RTAS_Proc;                     // 908 // r8 on kernel entry

    long RTAS_PrivDataArea;             // 90c // copied from HWInfo
    long ZeroWord;                      // 910 // Only NewWorld and Unknown PIHes touch this
    long _914;                          // 914
    long _918;                          // 918
    long _91c;                          // 91c

    char pageMapFiller[0x3a0]; //  920:cc0
    struct NKSystemInfo SystemInfo; // cc0:d80
    struct NKDiagnosticInfo DiagInfo; // d80:e80
    struct NKNanoKernelInfo NanoKernelInfo; // e80:f80
    struct NKProcessorInfo ProcessorInfo; // f80:fc0
    struct InfoRecord InfoRecord; // fc0:1000

    // char PageMap[184];                      // 920:dc0
    // char NanoKernelInfo[352];                   // dc0:f20 // see NKNanoKernelInfo in PPCInfoRecordsPriv
    // char ProcessorInfo[60];                 // f20:fc0
    // char InfoRecord[64];                        // fc0:1000 // was main copy in NKv1, now vestigial?
};
