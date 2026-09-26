F001329C: 9de3bf80                 save    %sp, -0x80, %sp! int
F00132A0: 293c04cf                 sethi   %hi(dword_F0133DDC), %l4
F00132A4: d40521dc                 ld      [%l4+%lo(dword_F0133DDC)], %o2! int
F00132A8: aa1521dc                 or      %l4, %lo(dword_F0133DDC), %l5
F00132AC: d0057ffc                 ld      [%l5-4], %o0
F00132B0: e202a024                 ld      [%o2+0x24], %l1
F00132B4: d2044000                 ld      [%l1], %o1! itimerval *
F00132B8: 80a26002                 cmp     %o1, 2
F00132BC: 08800005                 bleu    loc_F00132D0
F00132C0: e4020000                 ld      [%o0], %l2
F00132C4: 90102016                 mov     0x16, %o0
F00132C8: 10800057                 ba      locret_F0013424
F00132CC: d02aa038                 stb     %o0, [%o2+0x38]
F00132D0: d0046008                 ld      [%l1+8], %o0! int
F00132D4: 80a22000                 cmp     %o0, 0
F00132D8: 02800004                 be      loc_F00132E8
F00132DC: e0046004                 ld      [%l1+4], %l0
F00132E0: 7fffffa7                 call    _getitimer
F00132E4: d0246004                 st      %o0, [%l1+4]
F00132E8: 80a42000                 cmp     %l0, 0
F00132EC: 0280004e                 be      locret_F0013424
F00132F0: 90100010                 mov     %l0, %o0! int
F00132F4: a607bfe8                 add     %fp, var_18, %l3
F00132F8: 92100013                 mov     %l3, %o1! int
F00132FC: 40021357                 call    _copyin
F0013300: 94102010                 mov     0x10, %o2
F0013304: d20521dc                 ld      [%l4+0x1DC], %o1
F0013308: d02a6038                 stb     %o0, [%o1+0x38]
F001330C: d00521dc                 ld      [%l4+0x1DC], %o0
F0013310: d04a2038                 ldsb    [%o0+0x38], %o0
F0013314: 80a22000                 cmp     %o0, 0
F0013318: 12800043                 bne     locret_F0013424
F001331C: a007bff0                 add     %fp, var_10, %l0
F0013320: 40000089                 call    _itimerfix
F0013324: 90100010                 mov     %l0, %o0
F0013328: 80a22000                 cmp     %o0, 0
F001332C: 12800007                 bne     loc_F0013348
F0013330: d20521dc                 ld      [%l4+0x1DC], %o1
F0013334: 40000084                 call    _itimerfix
F0013338: 90100013                 mov     %l3, %o0
F001333C: 80a22000                 cmp     %o0, 0
F0013340: 02800005                 be      loc_F0013354
F0013344: d20521dc                 ld      [%l4+0x1DC], %o1
F0013348: 90102016                 mov     0x16, %o0
F001334C: 10800036                 ba      locret_F0013424
F0013350: d02a6038                 stb     %o0, [%o1+0x38]
F0013354: 40020e19                 call    _spltty
F0013358: 01000000                 nop
F001335C: d2044000                 ld      [%l1], %o1
F0013360: 80a26000                 cmp     %o1, 0
F0013364: 12800023                 bne     loc_F00133F0
F0013368: a8100008                 mov     %o0, %l4
F001336C: a207bfe0                 add     %fp, var_20, %l1
F0013370: 7fffff07                 call    _getthetime
F0013374: 90100011                 mov     %l1, %o0
F0013378: 113c004da612202c         set     _realitexpire, %l3
F0013380: 90100013                 mov     %l3, %o0
F0013384: 7fffdb34                 call    _untimeout
F0013388: 92100012                 mov     %l2, %o1
F001338C: d007bff0                 ld      [%fp+var_10], %o0
F0013390: 80a22000                 cmp     %o0, 0
F0013394: 12800006                 bne     loc_F00133AC
F0013398: 90100010                 mov     %l0, %o0
F001339C: d007bff4                 ld      [%fp+var_C], %o0
F00133A0: 80a22000                 cmp     %o0, 0
F00133A4: 0280000a                 be      loc_F00133CC
F00133A8: 90100010                 mov     %l0, %o0
F00133AC: 400000b4                 call    _timevaladd
F00133B0: 92100011                 mov     %l1, %o1
F00133B4: 7fffdb2e                 call    _hzto
F00133B8: 90100010                 mov     %l0, %o0
F00133BC: 94100008                 mov     %o0, %o2
F00133C0: 90100013                 mov     %l3, %o0! int
F00133C4: 7fffdb19                 call    _timeout
F00133C8: 92100012                 mov     %l2, %o1
F00133CC: d007bfe8                 ld      [%fp+var_18], %o0
F00133D0: d024a054                 st      %o0, [%l2+0x54]
F00133D4: d007bfec                 ld      [%fp+var_14], %o0
F00133D8: d024a058                 st      %o0, [%l2+0x58]
F00133DC: d007bff0                 ld      [%fp+var_10], %o0
F00133E0: d024a05c                 st      %o0, [%l2+0x5C]
F00133E4: d007bff4                 ld      [%fp+var_C], %o0
F00133E8: 1080000d                 ba      loc_F001341C
F00133EC: d024a060                 st      %o0, [%l2+0x60]
F00133F0: d4057ffc                 ld      [%l5-4], %o2
F00133F4: 932a6004                 sll     %o1, 4, %o1
F00133F8: d007bfe8                 ld      [%fp+var_18], %o0
F00133FC: 9202400a                 add     %o1, %o2, %o1
F0013400: d02261fc                 st      %o0, [%o1+0x1FC]
F0013404: d007bfec                 ld      [%fp+var_14], %o0
F0013408: d0226200                 st      %o0, [%o1+0x200]
F001340C: d007bff0                 ld      [%fp+var_10], %o0
F0013410: d0226204                 st      %o0, [%o1+0x204]
F0013414: d007bff4                 ld      [%fp+var_C], %o0
F0013418: d0226208                 st      %o0, [%o1+0x208]
F001341C: 40020e42                 call    _splx
F0013420: 90100014                 mov     %l4, %o0
F0013424: 81c7e008                 ret
F0013428: 81e80000                 restore
