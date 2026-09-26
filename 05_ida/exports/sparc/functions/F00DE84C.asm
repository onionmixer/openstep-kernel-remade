F00DE84C: 9de3bf90                 save    %sp, -0x70, %sp
F00DE850: 80a62000                 cmp     %i0, 0
F00DE854: 12800004                 bne     loc_F00DE864
F00DE858: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DE85C: 1080003a                 ba      locret_F00DE944
F00DE860: b01020ca                 mov     0xCA, %i0
F00DE864: d2022058                 ld      [%o0+0x58], %o1! SEL
F00DE868: 40004c02                 call    _objc_msgSend
F00DE86C: 90100018                 mov     %i0, %o0
F00DE870: a2100008                 mov     %o0, %l1
F00DE874: 113c0505                 sethi   %hi(paCheckowner), %o0! id
F00DE878: e0022018                 ld      [%o0+%lo(paCheckowner)], %l0
F00DE87C: 133c0505                 sethi   %hi(paOwnerport), %o1
F00DE880: d20260b0                 ld      [%o1+%lo(paOwnerport)], %o1! SEL
F00DE884: 40004bfb                 call    _objc_msgSend
F00DE888: 90100018                 mov     %i0, %o0
F00DE88C: 94100008                 mov     %o0, %o2
F00DE890: 90100011                 mov     %l1, %o0! id
F00DE894: 40004bf7                 call    _objc_msgSend
F00DE898: 92100010                 mov     %l0, %o1
F00DE89C: 912a2018                 sll     %o0, 24, %o0
F00DE8A0: 80a22000                 cmp     %o0, 0
F00DE8A4: 12800004                 bne     loc_F00DE8B4
F00DE8A8: 80a66001                 cmp     %i1, 1
F00DE8AC: 10800026                 ba      locret_F00DE944
F00DE8B0: b01020c8                 mov     0xC8, %i0
F00DE8B4: 02800014                 be      loc_F00DE904
F00DE8B8: 80a66001                 cmp     %i1, 1
F00DE8BC: 14800007                 bg      loc_F00DE8D8
F00DE8C0: 80a66002                 cmp     %i1, 2
F00DE8C4: 80a66000                 cmp     %i1, 0
F00DE8C8: 0280000d                 be      loc_F00DE8FC
F00DE8CC: 90100018                 mov     %i0, %o0
F00DE8D0: 1080001d                 ba      locret_F00DE944
F00DE8D4: b01020ce                 mov     0xCE, %i0
F00DE8D8: 02800006                 be      loc_F00DE8F0
F00DE8DC: 80a66003                 cmp     %i1, 3
F00DE8E0: 02800015                 be      loc_F00DE934
F00DE8E4: 113c0505                 sethi   -0xFEBEC00, %o0
F00DE8E8: 10800017                 ba      locret_F00DE944
F00DE8EC: b01020ce                 mov     0xCE, %i0
F00DE8F0: 90100018                 mov     %i0, %o0
F00DE8F4: 10800006                 ba      loc_F00DE90C
F00DE8F8: 94102002                 mov     2, %o2
F00DE8FC: 10800004                 ba      loc_F00DE90C
F00DE900: 94102000                 mov     0, %o2
F00DE904: 90100018                 mov     %i0, %o0! id
F00DE908: 94102001                 mov     1, %o2
F00DE90C: d2068000                 ld      [%i2], %o1
F00DE910: 9607bff0                 add     %fp, var_10, %o3
F00DE914: d227bff0                 st      %o1, [%fp+var_10]
F00DE918: d806a004                 ld      [%i2+4], %o4
F00DE91C: 133c0505                 sethi   %hi(paControlAttime), %o1
F00DE920: d202604c                 ld      [%o1+%lo(paControlAttime)], %o1! SEL
F00DE924: 40004bd3                 call    _objc_msgSend
F00DE928: d827bff4                 st      %o4, [%fp+var_C]
F00DE92C: 10800006                 ba      locret_F00DE944
F00DE930: b0102000                 mov     0, %i0
F00DE934: d2022034                 ld      [%o0+0x34], %o1! SEL
F00DE938: 40004bce                 call    _objc_msgSend
F00DE93C: 90100018                 mov     %i0, %o0
F00DE940: b0102000                 mov     0, %i0
F00DE944: 81c7e008                 ret
F00DE948: 81e80000                 restore
