F00F2D6C: 9de3bf90                 save    %sp, -0x70, %sp
F00F2D70: d006200c                 ld      [%i0+0xC], %o0
F00F2D74: 80a22000                 cmp     %o0, 0
F00F2D78: 02800017                 be      locret_F00F2DD4
F00F2D7C: a007bff4                 add     %fp, var_C, %l0
F00F2D80: 90100018                 mov     %i0, %o0
F00F2D84: 233c03f4921460c8         set     aObjc, %o1! "__OBJC"
F00F2D8C: 153c03f49412a228         set     aMethVarNames, %o2! "__meth_var_names"
F00F2D94: 7ffffb94                 call    _getsectdatafromheaderinfo
F00F2D98: 96100010                 mov     %l0, %o3
F00F2D9C: 92920000                 orcc    %o0, %g0, %o1
F00F2DA0: 3280000a                 bne,a   loc_F00F2DC8
F00F2DA4: d0060000                 ld      [%i0], %o0
F00F2DA8: 90100018                 mov     %i0, %o0
F00F2DAC: 921460c8                 or      %l1, 0xC8, %o1
F00F2DB0: 153c03f49412a240         set     aSelectorStrs, %o2! "__selector_strs"
F00F2DB8: 7ffffb8b                 call    _getsectdatafromheaderinfo
F00F2DBC: 96100010                 mov     %l0, %o3
F00F2DC0: 92100008                 mov     %o0, %o1
F00F2DC4: d0060000                 ld      [%i0], %o0
F00F2DC8: d407bff4                 ld      [%fp+var_C], %o2
F00F2DCC: 40000340                 call    __sel_init
F00F2DD0: d606200c                 ld      [%i0+0xC], %o3
F00F2DD4: 81c7e008                 ret
F00F2DD8: 81e80000                 restore
