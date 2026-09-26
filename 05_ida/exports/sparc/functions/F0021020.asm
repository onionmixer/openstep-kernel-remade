F0021020: 9de3bf90                 save    %sp, -0x70, %sp! int
F0021024: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0021028: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F002102C: e4022024                 ld      [%o0+0x24], %l2
F0021030: d004a004                 ld      [%l2+4], %o0
F0021034: 80a22000                 cmp     %o0, 0
F0021038: 02800015                 be      loc_F002108C
F002103C: 9207bff4                 add     %fp, var_C, %o1! int
F0021040: d004a008                 ld      [%l2+8], %o0! int
F0021044: 4001dc05                 call    _copyin
F0021048: 94102004                 mov     4, %o2
F002104C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0021050: d02a6038                 stb     %o0, [%o1+0x38]
F0021054: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0021058: d04a2038                 ldsb    [%o0+0x38], %o0
F002105C: 80a22000                 cmp     %o0, 0
F0021060: 12800086                 bne     locret_F0021278
F0021064: d207bff4                 ld      [%fp+var_C], %o1
F0021068: d004a004                 ld      [%l2+4], %o0
F002106C: 4001a357                 call    _useracc
F0021070: 94102000                 mov     0, %o2
F0021074: 80a22000                 cmp     %o0, 0
F0021078: 12800005                 bne     loc_F002108C
F002107C: d20421dc                 ld      [%l0+0x1DC], %o1
F0021080: 9010200e                 mov     0xE, %o0
F0021084: 1080007d                 ba      locret_F0021278
F0021088: d02a6038                 stb     %o0, [%o1+0x38]
F002108C: 400004d1                 call    _getsock
F0021090: d0048000                 ld      [%l2], %o0
F0021094: a2920000                 orcc    %o0, %g0, %l1
F0021098: 02800078                 be      locret_F0021278
F002109C: 01000000                 nop
F00210A0: 4001d6fd                 call    _splnet
F00210A4: 01000000                 nop
F00210A8: e0046018                 ld      [%l1+0x18], %l0
F00210AC: d2142002                 lduh    [%l0+2], %o1
F00210B0: 808a6002                 btst    2, %o1
F00210B4: 12800007                 bne     loc_F00210D0
F00210B8: a6100008                 mov     %o0, %l3
F00210BC: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F00210C0: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F00210C4: 92102016                 mov     0x16, %o1
F00210C8: 1080006a                 ba      loc_F0021270
F00210CC: d22aa038                 stb     %o1, [%o2+0x38]
F00210D0: d0142006                 lduh    [%l0+6], %o0
F00210D4: 808a2100                 btst    0x100, %o0
F00210D8: 02800013                 be      loc_F0021124
F00210DC: d0542020                 ldsh    [%l0+0x20], %o0
F00210E0: 80a22000                 cmp     %o0, 0
F00210E4: 12800011                 bne     loc_F0021128
F00210E8: 90100013                 mov     %l3, %o0
F00210EC: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F00210F0: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F00210F4: 92102023                 mov     0x23, %o1 ! '#'
F00210F8: 1080005e                 ba      loc_F0021270
F00210FC: d22aa038                 stb     %o1, [%o2+0x38]
F0021100: 90102035                 mov     0x35, %o0 ! '5'
F0021104: 1080000f                 ba      loc_F0021140
F0021108: d0342056                 sth     %o0, [%l0+0x56]
F002110C: 808a2020                 btst    0x20, %o0 ! ' '
F0021110: 12bffffc                 bne     loc_F0021100
F0021114: 90042054                 add     %l0, 0x54, %o0 ! 'T'! unsigned int
F0021118: 7fffc558                 call    _sleep
F002111C: 9210201a                 mov     0x1A, %o1
F0021120: d0542020                 ldsh    [%l0+0x20], %o0
F0021124: 80a22000                 cmp     %o0, 0
F0021128: 32800007                 bne,a   loc_F0021144
F002112C: d4142056                 lduh    [%l0+0x56], %o2
F0021130: d0142056                 lduh    [%l0+0x56], %o0
F0021134: 80a22000                 cmp     %o0, 0
F0021138: 22bffff5                 be,a    loc_F002110C
F002113C: d0142006                 lduh    [%l0+6], %o0
F0021140: d4142056                 lduh    [%l0+0x56], %o2
F0021144: 80a2a000                 cmp     %o2, 0
F0021148: 02800007                 be      loc_F0021164
F002114C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0021150: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0021154: 90100013                 mov     %l3, %o0
F0021158: d42a6038                 stb     %o2, [%o1+0x38]
F002115C: 10800045                 ba      loc_F0021270
F0021160: c0342056                 clrh    [%l0+0x56]
F0021164: 7fffa8a0                 call    _falloc
F0021168: 01000000                 nop
F002116C: a2920000                 orcc    %o0, %g0, %l1
F0021170: 3280000c                 bne,a   loc_F00211A0
F0021174: e004201c                 ld      [%l0+0x1C], %l0
F0021178: 133c04cf901261d8         set     _active_u, %o0
F0021180: d0022004                 ld      [%o0+4], %o0
F0021184: d40261d8                 ld      [%o1+0x1D8], %o2
F0021188: d2022030                 ld      [%o0+0x30], %o1
F002118C: d402a14c                 ld      [%o2+0x14C], %o2
F0021190: 90100013                 mov     %l3, %o0
F0021194: 932a6002                 sll     %o1, 2, %o1
F0021198: 10800036                 ba      loc_F0021270
F002119C: c0228009                 clr     [%o2+%o1]
F00211A0: 92102001                 mov     1, %o1
F00211A4: 7ffffc2f                 call    _soqremque
F00211A8: 90100010                 mov     %l0, %o0
F00211AC: 80a22000                 cmp     %o0, 0
F00211B0: 32800006                 bne,a   loc_F00211C8
F00211B4: 90102002                 mov     2, %o0
F00211B8: 113c042f                 sethi   %hi(aAccept), %o0! "accept"
F00211BC: 7fffcfed                 call    _panic
F00211C0: 901220e8                 bset    %lo(aAccept), %o0! "accept"
F00211C4: 90102002                 mov     2, %o0
F00211C8: d034600c                 sth     %o0, [%l1+0xC]
F00211CC: 90102003                 mov     3, %o0
F00211D0: d0246008                 st      %o0, [%l1+8]
F00211D4: 113c042d90122190         set     _socketops, %o0
F00211DC: d0246014                 st      %o0, [%l1+0x14]
F00211E0: e0246018                 st      %l0, [%l1+0x18]
F00211E4: 113c04cf                 sethi   %hi(_active_u), %o0
F00211E8: d60221d8                 ld      [%o0+%lo(_active_u)], %o3
F00211EC: 901221d8                 bset    %lo(_active_u), %o0
F00211F0: d2022004                 ld      [%o0+4], %o1
F00211F4: d602e14c                 ld      [%o3+0x14C], %o3! int
F00211F8: d4026030                 ld      [%o1+0x30], %o2
F00211FC: 90102001                 mov     1, %o0
F0021200: 92102008                 mov     8, %o1
F0021204: 952aa002                 sll     %o2, 2, %o2
F0021208: 7ffff1d5                 call    _m_get
F002120C: e222c00a                 st      %l1, [%o3+%o2]
F0021210: a2100008                 mov     %o0, %l1
F0021214: 90100010                 mov     %l0, %o0
F0021218: 7ffff5ea                 call    _soaccept
F002121C: 92100011                 mov     %l1, %o1
F0021220: d004a004                 ld      [%l2+4], %o0
F0021224: 80a22000                 cmp     %o0, 0
F0021228: 0280000f                 be      loc_F0021264
F002122C: d007bff4                 ld      [%fp+var_C], %o0
F0021230: d2546008                 ldsh    [%l1+8], %o1
F0021234: 80a20009                 cmp     %o0, %o1
F0021238: 34800002                 bg,a    loc_F0021240
F002123C: d227bff4                 st      %o1, [%fp+var_C]
F0021240: d204a004                 ld      [%l2+4], %o1! int
F0021244: d0046004                 ld      [%l1+4], %o0! int
F0021248: d407bff4                 ld      [%fp+var_C], %o2! int
F002124C: 4001dba0                 call    _copyout
F0021250: 90044008                 add     %l1, %o0, %o0
F0021254: 9007bff4                 add     %fp, var_C, %o0! int
F0021258: d204a008                 ld      [%l2+8], %o1! int
F002125C: 4001db9c                 call    _copyout
F0021260: 94102004                 mov     4, %o2
F0021264: 7ffff280                 call    _m_freem
F0021268: 90100011                 mov     %l1, %o0
F002126C: 90100013                 mov     %l3, %o0
F0021270: 4001d6ad                 call    _splx
F0021274: 01000000                 nop
F0021278: 81c7e008                 ret
F002127C: 81e80000                 restore
