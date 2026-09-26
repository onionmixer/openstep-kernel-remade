F00F0CC0: 9de3bf90                 save    %sp, -0x70, %sp
F00F0CC4: 90100018                 mov     %i0, %o0! mhp
F00F0CC8: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F0CD0: 153c03f49412a1b0         set     aStringObject, %o2! "__string_object"
F00F0CD8: 7ffde4d7                 call    _getsectdatafromheader
F00F0CDC: 9607bff4                 add     %fp, var_C, %o3
F00F0CE0: a0920000                 orcc    %o0, %g0, %l0
F00F0CE4: 02800014                 be      locret_F00F0D34
F00F0CE8: d007bff4                 ld      [%fp+var_C], %o0
F00F0CEC: 80a22000                 cmp     %o0, 0
F00F0CF0: 02800011                 be      locret_F00F0D34
F00F0CF4: 113c03f4                 sethi   %hi(aNxconstantstri), %o0! "NXConstantString"
F00F0CF8: 40000403                 call    _objc_getClass
F00F0CFC: 901221c0                 bset    %lo(aNxconstantstri), %o0! "NXConstantString"
F00F0D00: a2100008                 mov     %o0, %l1
F00F0D04: b0102000                 mov     0, %i0
F00F0D08: d007bff4                 ld      [%fp+var_C], %o0
F00F0D0C: 7ffc563d                 call    _udiv
F00F0D10: 9210200c                 mov     0xC, %o1
F00F0D14: 80a60008                 cmp     %i0, %o0
F00F0D18: 1a800007                 bcc     locret_F00F0D34
F00F0D1C: 912e2001                 sll     %i0, 1, %o0
F00F0D20: 90020018                 add     %o0, %i0, %o0
F00F0D24: 912a2002                 sll     %o0, 2, %o0
F00F0D28: e2240008                 st      %l1, [%l0+%o0]
F00F0D2C: 10bffff7                 ba      loc_F00F0D08
F00F0D30: b0062001                 inc     %i0
F00F0D34: 81c7e008                 ret
F00F0D38: 81e80000                 restore
