F00F26F0: 9de3bf90                 save    %sp, -0x70, %sp
F00F26F4: 90100018                 mov     %i0, %o0
F00F26F8: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F2700: 153c03f49412a1b0         set     aStringObject, %o2! "__string_object"
F00F2708: 7ffffd37                 call    _getsectdatafromheaderinfo
F00F270C: 9607bff4                 add     %fp, var_C, %o3
F00F2710: a0920000                 orcc    %o0, %g0, %l0
F00F2714: 02800014                 be      locret_F00F2764
F00F2718: d007bff4                 ld      [%fp+var_C], %o0
F00F271C: 80a22000                 cmp     %o0, 0
F00F2720: 02800011                 be      locret_F00F2764
F00F2724: 113c03f4                 sethi   %hi(aNxconstantstri), %o0! "NXConstantString"
F00F2728: 7ffffd77                 call    _objc_getClass
F00F272C: 901221c0                 bset    %lo(aNxconstantstri), %o0! "NXConstantString"
F00F2730: a2100008                 mov     %o0, %l1
F00F2734: b0102000                 mov     0, %i0
F00F2738: d007bff4                 ld      [%fp+var_C], %o0
F00F273C: 7ffc4fb1                 call    _udiv
F00F2740: 9210200c                 mov     0xC, %o1
F00F2744: 80a60008                 cmp     %i0, %o0
F00F2748: 1a800007                 bcc     locret_F00F2764
F00F274C: 912e2001                 sll     %i0, 1, %o0
F00F2750: 90020018                 add     %o0, %i0, %o0
F00F2754: 912a2002                 sll     %o0, 2, %o0
F00F2758: e2240008                 st      %l1, [%l0+%o0]
F00F275C: 10bffff7                 ba      loc_F00F2738
F00F2760: b0062001                 inc     %i0
F00F2764: 81c7e008                 ret
F00F2768: 81e80000                 restore
