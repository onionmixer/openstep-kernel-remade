F0026680: 9de3bf80                 save    %sp, -0x80, %sp
F0026684: f027bfec                 st      %i0, [%fp+var_14]
F0026688: d0062008                 ld      [%i0+8], %o0
F002668C: 808a2100                 btst    0x100, %o0
F0026690: 02800005                 be      loc_F00266A4
F0026694: f227a048                 st      %i1, [%fp+arg_48]
F0026698: 808e6002                 btst    2, %i1
F002669C: 12800087                 bne     locret_F00268B8
F00266A0: b0102000                 mov     0, %i0
F00266A4: 808a2080                 btst    0x80, %o0
F00266A8: 02800004                 be      loc_F00266B8
F00266AC: 808e6001                 btst    1, %i1
F00266B0: 12800082                 bne     locret_F00268B8
F00266B4: b0102000                 mov     0, %i0
F00266B8: d207a048                 ld      [%fp+arg_48], %o1
F00266BC: 90102023                 mov     0x23, %o0 ! '#'
F00266C0: d607bfec                 ld      [%fp+var_14], %o3
F00266C4: d027bff4                 st      %o0, [%fp+var_C]
F00266C8: d602e018                 ld      [%o3+0x18], %o3
F00266CC: 808a6002                 btst    2, %o1
F00266D0: 12800006                 bne     loc_F00266E8
F00266D4: d627bfe4                 st      %o3, [%fp+var_1C]
F00266D8: d007bff4                 ld      [%fp+var_C], %o0
F00266DC: 90022001                 inc     %o0
F00266E0: d027bff4                 st      %o0, [%fp+var_C]
F00266E4: d007bff4                 ld      [%fp+var_C], %o0
F00266E8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00266EC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F00266F0: 4001c199                 call    _setjmp
F00266F4: 90022028                 inc     0x28, %o0 ! '('
F00266F8: 80a22000                 cmp     %o0, 0
F00266FC: 02800027                 be      loc_F0026798
F0026700: d607bfe4                 ld      [%fp+var_1C], %o3
F0026704: 153c04cf                 sethi   %hi(_active_u), %o2
F0026708: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F002670C: d0024000                 ld      [%o1], %o0
F0026710: d04a2017                 ldsb    [%o0+0x17], %o0
F0026714: d202613c                 ld      [%o1+0x13C], %o1
F0026718: 90023fff                 inc     -1, %o0
F002671C: 933a4008                 sra     %o1, %o0, %o1
F0026720: 808a6001                 btst    1, %o1
F0026724: 02800004                 be      loc_F0026734
F0026728: 9412a1d8                 bset    %lo(_active_u), %o2
F002672C: 10800063                 ba      locret_F00268B8
F0026730: b0102004                 mov     4, %i0
F0026734: b0102000                 mov     0, %i0
F0026738: d202a004                 ld      [%o2+4], %o1
F002673C: 90102002                 mov     2, %o0
F0026740: 1080005e                 ba      locret_F00268B8
F0026744: d02a6039                 stb     %o0, [%o1+0x39]
F0026748: d002e008                 ld      [%o3+8], %o0
F002674C: 808a2100                 btst    0x100, %o0
F0026750: 02800006                 be      loc_F0026768
F0026754: d007bfec                 ld      [%fp+var_14], %o0
F0026758: 4000005a                 call    _vno_bsd_unlock
F002675C: 92102100                 mov     0x100, %o1
F0026760: 1080000e                 ba      loc_F0026798
F0026764: d607bfe4                 ld      [%fp+var_1C], %o3
F0026768: d007a048                 ld      [%fp+arg_48], %o0
F002676C: 808a2004                 btst    4, %o0
F0026770: 12800021                 bne     loc_F00267F4
F0026774: d607bfe4                 ld      [%fp+var_1C], %o3
F0026778: d207bff4                 ld      [%fp+var_C], %o1
F002677C: d412e004                 lduh    [%o3+4], %o2
F0026780: 9002e00a                 add     %o3, 0xA, %o0! unsigned int
F0026784: 9412a010                 bset    0x10, %o2
F0026788: d432e004                 sth     %o2, [%o3+4]
F002678C: 7fffafbb                 call    _sleep
F0026790: 01000000                 nop
F0026794: d607bfe4                 ld      [%fp+var_1C], %o3
F0026798: d012e004                 lduh    [%o3+4], %o0
F002679C: 808a2004                 btst    4, %o0
F00267A0: 32bfffea                 bne,a   loc_F0026748
F00267A4: d607bfec                 ld      [%fp+var_14], %o3
F00267A8: d407a048                 ld      [%fp+arg_48], %o2
F00267AC: 808aa002                 btst    2, %o2
F00267B0: 02800018                 be      loc_F0026810
F00267B4: d607bfe4                 ld      [%fp+var_1C], %o3
F00267B8: d212e004                 lduh    [%o3+4], %o1
F00267BC: 808a6008                 btst    8, %o1
F00267C0: 02800014                 be      loc_F0026810
F00267C4: d607bfec                 ld      [%fp+var_14], %o3
F00267C8: d002e008                 ld      [%o3+8], %o0
F00267CC: 808a2080                 btst    0x80, %o0
F00267D0: 02800006                 be      loc_F00267E8
F00267D4: d007bfec                 ld      [%fp+var_14], %o0
F00267D8: 4000003a                 call    _vno_bsd_unlock
F00267DC: 92102080                 mov     0x80, %o1
F00267E0: 10bfffee                 ba      loc_F0026798
F00267E4: d607bfe4                 ld      [%fp+var_1C], %o3
F00267E8: 808aa004                 btst    4, %o2
F00267EC: 02800004                 be      loc_F00267FC
F00267F0: 90126010                 or      %o1, 0x10, %o0
F00267F4: 10800031                 ba      locret_F00268B8
F00267F8: b0102023                 mov     0x23, %i0 ! '#'
F00267FC: d607bfe4                 ld      [%fp+var_1C], %o3
F0026800: 92102023                 mov     0x23, %o1 ! '#'
F0026804: d032e004                 sth     %o0, [%o3+4]
F0026808: 10bfffe1                 ba      loc_F002678C
F002680C: 9002e008                 add     %o3, 8, %o0
F0026810: d607bfec                 ld      [%fp+var_14], %o3
F0026814: d002e008                 ld      [%o3+8], %o0
F0026818: 808a2100                 btst    0x100, %o0
F002681C: 02800004                 be      loc_F002682C
F0026820: 113c0430                 sethi   %hi(aVnoBsdLock), %o0! "vno_bsd_lock"
F0026824: 7fffba53                 call    _panic
F0026828: 901220c0                 bset    %lo(aVnoBsdLock), %o0! "vno_bsd_lock"
F002682C: d007a048                 ld      [%fp+arg_48], %o0
F0026830: 808a2002                 btst    2, %o0
F0026834: 0280000f                 be      loc_F0026870
F0026838: 808a2001                 btst    1, %o0
F002683C: d607bfe4                 ld      [%fp+var_1C], %o3
F0026840: d012e00a                 lduh    [%o3+0xA], %o0
F0026844: d212e004                 lduh    [%o3+4], %o1
F0026848: 90022001                 inc     %o0
F002684C: d032e00a                 sth     %o0, [%o3+0xA]
F0026850: 92126004                 bset    4, %o1
F0026854: d232e004                 sth     %o1, [%o3+4]
F0026858: d607bfec                 ld      [%fp+var_14], %o3
F002685C: d002e008                 ld      [%o3+8], %o0
F0026860: 90122100                 bset    0x100, %o0
F0026864: d022e008                 st      %o0, [%o3+8]
F0026868: d007a048                 ld      [%fp+arg_48], %o0
F002686C: 808a2001                 btst    1, %o0
F0026870: 02800012                 be      locret_F00268B8
F0026874: b0102000                 mov     0, %i0
F0026878: d607bfec                 ld      [%fp+var_14], %o3
F002687C: d002e008                 ld      [%o3+8], %o0
F0026880: 808a2080                 btst    0x80, %o0
F0026884: 1280000d                 bne     locret_F00268B8
F0026888: d607bfe4                 ld      [%fp+var_1C], %o3
F002688C: d012e008                 lduh    [%o3+8], %o0
F0026890: d212e004                 lduh    [%o3+4], %o1
F0026894: 90022001                 inc     %o0
F0026898: d032e008                 sth     %o0, [%o3+8]
F002689C: 92126008                 bset    8, %o1
F00268A0: d232e004                 sth     %o1, [%o3+4]
F00268A4: d607bfec                 ld      [%fp+var_14], %o3
F00268A8: d002e008                 ld      [%o3+8], %o0
F00268AC: 90122080                 bset    0x80, %o0
F00268B0: d022e008                 st      %o0, [%o3+8]
F00268B4: b0102000                 mov     0, %i0
F00268B8: 81c7e008                 ret
F00268BC: 81e80000                 restore
