F00CD6FC: 9de3bf90                 save    %sp, -0x70, %sp
F00CD700: 9010001b                 mov     %i3, %o0! __s1
F00CD704: 133c03ec                 sethi   %hi(aIoscsicontroll_2), %o1! "IOSCSIControllerStatistics"
F00CD708: 7ffceaa9                 call    _strcmp
F00CD70C: 921262c8                 bset    %lo(aIoscsicontroll_2), %o1! "IOSCSIControllerStatistics"
F00CD710: 80a22000                 cmp     %o0, 0
F00CD714: 0280000e                 be      loc_F00CD74C
F00CD718: 133c0508                 sethi   %hi(stru_F014213C.super_class), %o1
F00CD71C: f027bff0                 st      %i0, [%fp+var_10]
F00CD720: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CD724: 9610001b                 mov     %i3, %o3
F00CD728: d4026140                 ld      [%o1+%lo(stru_F014213C.super_class)], %o2
F00CD72C: 9810001c                 mov     %i4, %o4
F00CD730: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00CD734: d427bff4                 st      %o2, [%fp+var_C]
F00CD738: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00CD73C: 40009090                 call    _objc_msgSendSuper
F00CD740: 9410001a                 mov     %i2, %o2
F00CD744: 10800007                 ba      locret_F00CD760
F00CD748: b0100008                 mov     %o0, %i0
F00CD74C: 113c0505                 sethi   %hi(paResetstats), %o0! id
F00CD750: d20223f0                 ld      [%o0+%lo(paResetstats)], %o1! SEL
F00CD754: 40009047                 call    _objc_msgSend
F00CD758: 90100018                 mov     %i0, %o0
F00CD75C: b0102000                 mov     0, %i0
F00CD760: 81c7e008                 ret
F00CD764: 81e80000                 restore
