F00A77E0: 9de3bf90                 save    %sp, -0x70, %sp
F00A77E4: 1100000f                 sethi   0x3C00, %o0
F00A77E8: 808ec008                 btst    %o0, %i3
F00A77EC: 02800043                 be      locret_F00A78F8
F00A77F0: 1100000c                 sethi   0x3000, %o0
F00A77F4: 808ec008                 btst    %o0, %i3
F00A77F8: 02800040                 be      locret_F00A78F8
F00A77FC: 01000000                 nop
F00A7800: 7fffbccf                 call    _splaudio
F00A7804: 01000000                 nop
F00A7808: 9010001b                 mov     %i3, %o0
F00A780C: 7fffb879                 call    _vac_parity_chk_dis
F00A7810: 92102000                 mov     0, %o1
F00A7814: 80a22000                 cmp     %o0, 0
F00A7818: 02800004                 be      loc_F00A7828
F00A781C: 113c046e                 sethi   %hi(aModuleParityEr), %o0! "module parity error:\n"
F00A7820: 10800004                 ba      loc_F00A7830
F00A7824: 90122150                 bset    %lo(aModuleParityEr), %o0! "module parity error:\n"
F00A7828: 113c046e90122168         set     aFatalSystemFau_0, %o0! "fatal system fault:\n"
F00A7830: 7ffdb38a                 call    _printf
F00A7834: 01000000                 nop
F00A7838: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A783C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00A7840: d002200c                 ld      [%o0+0xC], %o0
F00A7844: d002200c                 ld      [%o0+0xC], %o0
F00A7848: 9210001a                 mov     %i2, %o1
F00A784C: d0022024                 ld      [%o0+0x24], %o0
F00A7850: 7fffd612                 call    _pmap_getpte
F00A7854: 9407bff4                 add     %fp, var_C, %o2
F00A7858: d407bff4                 ld      [%fp+var_C], %o2
F00A785C: 900aa003                 and     %o2, 3, %o0
F00A7860: 80a22002                 cmp     %o0, 2
F00A7864: 3280000c                 bne,a   loc_F00A7894
F00A7868: 113c046e                 sethi   -0xFEE4800, %o0
F00A786C: 9010001b                 mov     %i3, %o0
F00A7870: 92102000                 mov     0, %o1
F00A7874: 9532a008                 srl     %o2, 8, %o2
F00A7878: 952aa00c                 sll     %o2, 12, %o2
F00A787C: 960eafff                 and     %i2, 0xFFF, %o3
F00A7880: 9412800b                 bset    %o3, %o2
F00A7884: 7ffffc68                 call    _log_mem_err
F00A7888: 96102001                 mov     1, %o3
F00A788C: 10800006                 ba      loc_F00A78A4
F00A7890: 113c046e                 sethi   -0xFEE4800, %o0
F00A7894: 90122180                 bset    0x180, %o0! char *
F00A7898: 7ffdb370                 call    _printf
F00A789C: 9210001a                 mov     %i2, %o1
F00A78A0: 113c046e                 sethi   -0xFEE4800, %o0! char *
F00A78A4: 7ffdb36d                 call    _printf
F00A78A8: 90122198                 bset    0x198, %o0
F00A78AC: 80a72002                 cmp     %i4, 2
F00A78B0: 113c046e                 sethi   %hi(aSfsr0xXSFault), %o0! "\tsfsr = 0x%x, %s fault "
F00A78B4: 12800005                 bne     loc_F00A78C8
F00A78B8: 921221b0                 or      %o0, %lo(aSfsr0xXSFault), %o1! "\tsfsr = 0x%x, %s fault "
F00A78BC: 113c046e                 sethi   %hi(aWrite_0), %o0! "write"
F00A78C0: 10800004                 ba      loc_F00A78D0
F00A78C4: 941221c8                 or      %o0, %lo(aWrite_0), %o2! "write"
F00A78C8: 113c046e941221d0         set     aRead_0, %o2! "read"
F00A78D0: 90100009                 mov     %o1, %o0! char *
F00A78D4: 7ffdb361                 call    _printf
F00A78D8: 9210001b                 mov     %i3, %o1
F00A78DC: 113c046e901221d8         set     aAtVaddr0xX, %o0! "at vaddr 0x%x\n"
F00A78E4: 7ffdb35d                 call    _printf
F00A78E8: 9210001a                 mov     %i2, %o1
F00A78EC: 113c046e                 sethi   %hi(aMemoryError_0), %o0! "memory error"
F00A78F0: 7ffdb620                 call    _panic
F00A78F4: 901221e8                 bset    %lo(aMemoryError_0), %o0! "memory error"
F00A78F8: 81c7e008                 ret
F00A78FC: 81e80000                 restore
