F00F276C: 9de3bf90                 save    %sp, -0x70, %sp
F00F2770: 90100018                 mov     %i0, %o0
F00F2774: 133c03f4921260c8         set     aObjc, %o1! "__OBJC"
F00F277C: 153c03f49412a0d0         set     aClsRefs, %o2! "__cls_refs"
F00F2784: 7ffffd18                 call    _getsectdatafromheaderinfo
F00F2788: 9607bff4                 add     %fp, name, %o3
F00F278C: a2920000                 orcc    %o0, %g0, %l1
F00F2790: 0280000d                 be      locret_F00F27C4
F00F2794: b0102000                 mov     0, %i0
F00F2798: 10800007                 ba      loc_F00F27B4
F00F279C: d007bff4                 ld      [%fp+name], %o0! name
F00F27A0: 7ffffd6f                 call    _objc_lookUpClass
F00F27A4: d0044010                 ld      [%l1+%l0], %o0
F00F27A8: d0244010                 st      %o0, [%l1+%l0]
F00F27AC: b0062001                 inc     %i0
F00F27B0: d007bff4                 ld      [%fp+name], %o0
F00F27B4: 91322002                 srl     %o0, 2, %o0
F00F27B8: 80a60008                 cmp     %i0, %o0
F00F27BC: 0abffff9                 bcs     loc_F00F27A0
F00F27C0: a12e2002                 sll     %i0, 2, %l0
F00F27C4: 81c7e008                 ret
F00F27C8: 81e80000                 restore
