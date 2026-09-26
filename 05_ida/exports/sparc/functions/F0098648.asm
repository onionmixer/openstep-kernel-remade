F0098648: 9de3bf70                 save    %sp, -0x90, %sp
F009864C: 40005b94                 call    _prom_childnode
F0098650: 90100018                 mov     %i0, %o0
F0098654: 10800007                 ba      loc_F0098670
F0098658: a0100008                 mov     %o0, %l0
F009865C: 7ffffffb                 call    _fill_node
F0098660: 90100010                 mov     %l0, %o0
F0098664: 40005b85                 call    _prom_nextnode
F0098668: 90100010                 mov     %l0, %o0
F009866C: a0100008                 mov     %o0, %l0
F0098670: 80a42000                 cmp     %l0, 0
F0098674: 12bffffa                 bne     loc_F009865C
F0098678: 9407bfd0                 add     %fp, var_30, %o2
F009867C: 92102027                 mov     0x27, %o1 ! '''
F0098680: c02a8000                 clrb    [%o2]
F0098684: 9402a001                 inc     %o2
F0098688: 90924000                 orcc    %o1, %g0, %o0
F009868C: 14bffffd                 bg      loc_F0098680
F0098690: 92027fff                 inc     -1, %o1
F0098694: 90100018                 mov     %i0, %o0
F0098698: 133c044b92126148         set     _psname, %o1! "name"
F00986A0: 40005a59                 call    _prom_getprop
F00986A4: 9407bfd0                 add     %fp, var_30, %o2
F00986A8: 80a23fff                 cmp     %o0, -1
F00986AC: 02800038                 be      locret_F009878C
F00986B0: 113c044c                 sethi   %hi(unk_F01133F8), %o0
F00986B4: a01223f8                 or      %o0, %lo(unk_F01133F8), %l0
F00986B8: 90042050                 add     %l0, 0x50, %o0 ! 'P'
F00986BC: 80a40008                 cmp     %l0, %o0
F00986C0: 1a800012                 bcc     loc_F0098708
F00986C4: 9407bfd0                 add     %fp, var_30, %o2
F00986C8: a2100008                 mov     %o0, %l1
F00986CC: d0040000                 ld      [%l0], %o0! __s1
F00986D0: d4042004                 ld      [%l0+4], %o2! __n
F00986D4: 7ffdbf85                 call    _strncmp
F00986D8: 9207bfd0                 add     %fp, var_30, %o1
F00986DC: 80a22000                 cmp     %o0, 0
F00986E0: 32800006                 bne,a   loc_F00986F8
F00986E4: a0042014                 inc     0x14, %l0
F00986E8: 90100018                 mov     %i0, %o0
F00986EC: 4000002a                 call    _fill_nodeinfo
F00986F0: 92100010                 mov     %l0, %o1
F00986F4: 30800026                 ba,a    locret_F009878C
F00986F8: 80a40011                 cmp     %l0, %l1
F00986FC: 2abffff5                 bcs,a   loc_F00986D0
F0098700: d0040000                 ld      [%l0], %o0
F0098704: 9407bfd0                 add     %fp, var_30, %o2
F0098708: 92102027                 mov     0x27, %o1 ! '''
F009870C: c02a8000                 clrb    [%o2]
F0098710: 9402a001                 inc     %o2
F0098714: 90924000                 orcc    %o1, %g0, %o0
F0098718: 14bffffd                 bg      loc_F009870C
F009871C: 92027fff                 inc     -1, %o1
F0098720: 90100018                 mov     %i0, %o0
F0098724: 133c044b92126150         set     _psdevtype, %o1! "device_type"
F009872C: 40005a36                 call    _prom_getprop
F0098730: 9407bfd0                 add     %fp, var_30, %o2
F0098734: 80a23fff                 cmp     %o0, -1
F0098738: 02800015                 be      locret_F009878C
F009873C: 113c044d                 sethi   %hi(unk_F0113448), %o0
F0098740: a0122048                 or      %o0, %lo(unk_F0113448), %l0
F0098744: 90042028                 add     %l0, 0x28, %o0 ! '('
F0098748: 80a40008                 cmp     %l0, %o0
F009874C: 1a800010                 bcc     locret_F009878C
F0098750: a2100008                 mov     %o0, %l1
F0098754: d0040000                 ld      [%l0], %o0! __s1
F0098758: d4042004                 ld      [%l0+4], %o2! __n
F009875C: 7ffdbf63                 call    _strncmp
F0098760: 9207bfd0                 add     %fp, var_30, %o1
F0098764: 80a22000                 cmp     %o0, 0
F0098768: 32800006                 bne,a   loc_F0098780
F009876C: a0042014                 inc     0x14, %l0
F0098770: 90100018                 mov     %i0, %o0
F0098774: 40000034                 call    _fill_modinfo
F0098778: 92100010                 mov     %l0, %o1
F009877C: 30800004                 ba,a    locret_F009878C
F0098780: 80a40011                 cmp     %l0, %l1
F0098784: 2abffff5                 bcs,a   loc_F0098758
F0098788: d0040000                 ld      [%l0], %o0
F009878C: 81c7e008                 ret
F0098790: 81e80000                 restore
