F00C08B8: 9de3bf90                 save    %sp, -0x70, %sp
F00C08BC: a0100018                 mov     %i0, %l0
F00C08C0: b0103d3e                 mov     -0x2C2, %i0
F00C08C4: 9010001b                 mov     %i3, %o0! __s1
F00C08C8: 133c0483                 sethi   %hi(aEvsSetmousesca), %o1! "Evs_SetMouseScaling"
F00C08CC: 7ffd1e38                 call    _strcmp
F00C08D0: 92126150                 bset    %lo(aEvsSetmousesca), %o1! "Evs_SetMouseScaling"
F00C08D4: 80a22000                 cmp     %o0, 0
F00C08D8: 32800010                 bne,a   loc_F00C0918
F00C08DC: 9010001b                 mov     %i3, %o0
F00C08E0: d4068000                 ld      [%i2], %o2
F00C08E4: 80a72029                 cmp     %i4, 0x29 ! ')'
F00C08E8: 912aa001                 sll     %o2, 1, %o0
F00C08EC: 18800035                 bgu     locret_F00C09C0
F00C08F0: 90022001                 inc     %o0
F00C08F4: 80a2001c                 cmp     %o0, %i4
F00C08F8: 18800032                 bgu     locret_F00C09C0
F00C08FC: 90100010                 mov     %l0, %o0! id
F00C0900: 133c0504                 sethi   %hi(paSetpointerscal), %o1
F00C0904: d20262e4                 ld      [%o1+%lo(paSetpointerscal)], %o1! SEL
F00C0908: 9606a004                 add     %i2, 4, %o3
F00C090C: 4000c3d9                 call    _objc_msgSend
F00C0910: b0102000                 mov     0, %i0
F00C0914: 3080002b                 ba,a    locret_F00C09C0
F00C0918: 133c0483                 sethi   %hi(aEvsSetmousehan), %o1! "Evs_SetMouseHandedness"
F00C091C: 7ffd1e24                 call    _strcmp
F00C0920: 92126168                 bset    %lo(aEvsSetmousehan), %o1! "Evs_SetMouseHandedness"
F00C0924: 80a22000                 cmp     %o0, 0
F00C0928: 32800010                 bne,a   loc_F00C0968
F00C092C: 9010001b                 mov     %i3, %o0
F00C0930: 80a72001                 cmp     %i4, 1
F00C0934: 12800023                 bne     locret_F00C09C0
F00C0938: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C093C: d0042124                 ld      [%l0+0x124], %o0! id
F00C0940: 4000c3cc                 call    _objc_msgSend
F00C0944: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C0948: d0042124                 ld      [%l0+0x124], %o0! id
F00C094C: b0102000                 mov     0, %i0
F00C0950: d4068000                 ld      [%i2], %o2
F00C0954: 133c0504                 sethi   %hi(paUnlock), %o1
F00C0958: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00C095C: 4000c3c5                 call    _objc_msgSend
F00C0960: d4242134                 st      %o2, [%l0+0x134]
F00C0964: 30800017                 ba,a    locret_F00C09C0
F00C0968: 133c0483                 sethi   %hi(aEvsResetmouse_0), %o1! "Evs_ResetMouse"
F00C096C: 7ffd1e10                 call    _strcmp
F00C0970: 92126180                 bset    %lo(aEvsResetmouse_0), %o1! "Evs_ResetMouse"
F00C0974: 80a22000                 cmp     %o0, 0
F00C0978: 32800004                 bne,a   loc_F00C0988
F00C097C: e027bff0                 st      %l0, [%fp+var_10]
F00C0980: 10800010                 ba      locret_F00C09C0
F00C0984: b0102000                 mov     0, %i0
F00C0988: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C098C: 9410001a                 mov     %i2, %o2
F00C0990: 133c0507                 sethi   %hi(stru_F0141D7C.super_class), %o1
F00C0994: d8026180                 ld      [%o1+%lo(stru_F0141D7C.super_class)], %o4
F00C0998: 9610001b                 mov     %i3, %o3
F00C099C: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00C09A0: d827bff4                 st      %o4, [%fp+var_C]
F00C09A4: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00C09A8: 4000c3f5                 call    _objc_msgSendSuper
F00C09AC: 9810001c                 mov     %i4, %o4
F00C09B0: b0100008                 mov     %o0, %i0
F00C09B4: 80a63d39                 cmp     %i0, -0x2C7
F00C09B8: 22800002                 be,a    locret_F00C09C0
F00C09BC: b0103d3e                 mov     -0x2C2, %i0
F00C09C0: 81c7e008                 ret
F00C09C4: 81e80000                 restore
