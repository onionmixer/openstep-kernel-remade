F00ED78C: 9de3bf88                 save    %sp, -0x78, %sp
F00ED790: 40000cf2                 call    _NXZoneFromPtr
F00ED794: 90100018                 mov     %i0, %o0
F00ED798: a0100008                 mov     %o0, %l0
F00ED79C: d4042004                 ld      [%l0+4], %o2
F00ED7A0: 9fc28000                 call    %o2
F00ED7A4: 92102014                 mov     0x14, %o1
F00ED7A8: a2100008                 mov     %o0, %l1
F00ED7AC: d0060000                 ld      [%i0], %o0
F00ED7B0: d0244000                 st      %o0, [%l1]
F00ED7B4: d0062004                 ld      [%i0+4], %o0
F00ED7B8: d0246004                 st      %o0, [%l1+4]
F00ED7BC: d0062008                 ld      [%i0+8], %o0
F00ED7C0: d0246008                 st      %o0, [%l1+8]
F00ED7C4: d006200c                 ld      [%i0+0xC], %o0
F00ED7C8: d024600c                 st      %o0, [%l1+0xC]
F00ED7CC: d2062008                 ld      [%i0+8], %o1
F00ED7D0: 90026001                 add     %o1, 1, %o0
F00ED7D4: 90020009                 add     %o0, %o1, %o0
F00ED7D8: d0262008                 st      %o0, [%i0+8]
F00ED7DC: c0262004                 clr     [%i0+4]
F00ED7E0: 90100010                 mov     %l0, %o0
F00ED7E4: d2062008                 ld      [%i0+8], %o1
F00ED7E8: 40000ce4                 call    _NXZoneCalloc
F00ED7EC: 94102008                 mov     8, %o2! data
F00ED7F0: d026200c                 st      %o0, [%i0+0xC]
F00ED7F4: 9007bff0                 add     %fp, var_10, %o0
F00ED7F8: d023a040                 st      %o0, [%sp+0x78+var_38]
F00ED7FC: 90100011                 mov     %l1, %o0! table
F00ED800: 40000179                 call    _NXInitHashState
F00ED804: 01000000                 nop
F00ED808: 00000008                 illtrap
F00ED80C: 90100011                 mov     %l1, %o0! table
F00ED810: 9207bff0                 add     %fp, var_10, %o1! state
F00ED814: 4000017f                 call    _NXNextHashState
F00ED818: 9407bfec                 add     %fp, var_14, %o2
F00ED81C: 80a22000                 cmp     %o0, 0
F00ED820: 02800006                 be      loc_F00ED838
F00ED824: 90100018                 mov     %i0, %o0! table
F00ED828: 40000014                 call    _NXHashInsert
F00ED82C: d207bfec                 ld      [%fp+var_14], %o1
F00ED830: 10bffff8                 ba      loc_F00ED810
F00ED834: 90100011                 mov     %l1, %o0
F00ED838: 90100011                 mov     %l1, %o0
F00ED83C: 7ffffec7                 call    sub_F00ED358
F00ED840: 92102000                 mov     0, %o1
F00ED844: d2046004                 ld      [%l1+4], %o1
F00ED848: d0062004                 ld      [%i0+4], %o0
F00ED84C: 80a24008                 cmp     %o1, %o0
F00ED850: 02800004                 be      loc_F00ED860
F00ED854: 113c03f3                 sethi   %hi(aHashtableCount), %o0! "*** hashtable: count differs after reha"...
F00ED858: 40000c3c                 call    __NXLogError
F00ED85C: 90122288                 bset    %lo(aHashtableCount), %o0! "*** hashtable: count differs after reha"...
F00ED860: 7ffdeaa8                 call    _free
F00ED864: d004600c                 ld      [%l1+0xC], %o0! void *
F00ED868: 7ffdeaa6                 call    _free
F00ED86C: 90100011                 mov     %l1, %o0
F00ED870: 81c7e008                 ret
F00ED874: 81e80000                 restore
