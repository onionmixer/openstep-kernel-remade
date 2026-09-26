F00576A0: 9de3bf80                 save    %sp, -0x80, %sp
F00576A4: d0062014                 ld      [%i0+0x14], %o0
F00576A8: d027bfe0                 st      %o0, [%fp+var_20]
F00576AC: d0062018                 ld      [%i0+0x18], %o0
F00576B0: d027bfe4                 st      %o0, [%fp+var_1C]
F00576B4: d006201c                 ld      [%i0+0x1C], %o0
F00576B8: d027bfe8                 st      %o0, [%fp+var_18]
F00576BC: d6062020                 ld      [%i0+0x20], %o3
F00576C0: 92102013                 mov     0x13, %o1
F00576C4: d627bfec                 st      %o3, [%fp+var_14]
F00576C8: d0062024                 ld      [%i0+0x24], %o0
F00576CC: a210000b                 mov     %o3, %l1
F00576D0: d027bff0                 st      %o0, [%fp+var_10]
F00576D4: b2100008                 mov     %o0, %i1
F00576D8: d4062028                 ld      [%i0+0x28], %o2
F00576DC: 40000908                 call    _ipc_object_copyin_from_kernel
F00576E0: d427bff4                 st      %o2, [%fp+var_C]
F00576E4: 80a46000                 cmp     %l1, 0
F00576E8: 02800007                 be      loc_F0057704
F00576EC: 80a47fff                 cmp     %l1, -1
F00576F0: 02800005                 be      loc_F0057704
F00576F4: 01000000                 nop
F00576F8: 90100011                 mov     %l1, %o0
F00576FC: 40000900                 call    _ipc_object_copyin_from_kernel
F0057700: 92102014                 mov     0x14, %o1
F0057704: 400008ae                 call    _ipc_object_copyin_type
F0057708: 90102013                 mov     0x13, %o0
F005770C: a0100008                 mov     %o0, %l0
F0057710: 400008ab                 call    _ipc_object_copyin_type
F0057714: 90102014                 mov     0x14, %o0
F0057718: 912a2008                 sll     %o0, 8, %o0
F005771C: a0140008                 bset    %o0, %l0
F0057720: e0262014                 st      %l0, [%i0+0x14]
F0057724: d007bfe4                 ld      [%fp+var_1C], %o0
F0057728: d0262018                 st      %o0, [%i0+0x18]
F005772C: f226201c                 st      %i1, [%i0+0x1C]
F0057730: e2262020                 st      %l1, [%i0+0x20]
F0057734: d007bfe8                 ld      [%fp+var_18], %o0
F0057738: d0262024                 st      %o0, [%i0+0x24]
F005773C: d007bff4                 ld      [%fp+var_C], %o0
F0057740: d0262028                 st      %o0, [%i0+0x28]
F0057744: d00fbfe3                 ldub    [%fp+var_20+3], %o0
F0057748: 80a22000                 cmp     %o0, 0
F005774C: 1280006e                 bne     locret_F0057904
F0057750: a206202c                 add     %i0, 0x2C, %l1 ! ','
F0057754: d0062018                 ld      [%i0+0x18], %o0
F0057758: 90022014                 inc     0x14, %o0
F005775C: b4060008                 add     %i0, %o0, %i2
F0057760: 80a4401a                 cmp     %l1, %i2
F0057764: 1a800062                 bcc     loc_F00578EC
F0057768: ae102000                 mov     0, %l7
F005776C: 113fffc0b812200f         set     -0xFFF1, %i4
F0057774: 37100000                 sethi   0x40000000, %i3
F0057778: d0044000                 ld      [%l1], %o0
F005777C: a0100011                 mov     %l1, %l0
F0057780: a7322003                 srl     %o0, 3, %l3
F0057784: a9322002                 srl     %o0, 2, %l4
F0057788: a88d2001                 andcc   %l4, 1, %l4
F005778C: 02800007                 be      loc_F00577A8
F0057790: a60ce001                 and     %l3, 1, %l3
F0057794: ec146004                 lduh    [%l1+4], %l6
F0057798: d2146006                 lduh    [%l1+6], %o1
F005779C: ea046008                 ld      [%l1+8], %l5
F00577A0: 10800008                 ba      loc_F00577C0
F00577A4: a204600c                 inc     0xC, %l1
F00577A8: ec0c4000                 ldub    [%l1], %l6
F00577AC: 93322010                 srl     %o0, 16, %o1
F00577B0: 920a60ff                 and     %o1, 0xFF, %o1
F00577B4: ab322004                 srl     %o0, 4, %l5
F00577B8: aa0d6fff                 and     %l5, 0xFFF, %l5
F00577BC: a2046004                 inc     4, %l1
F00577C0: a405bffb                 add     %l6, -5, %l2
F00577C4: 80a4a001                 cmp     %l2, 1
F00577C8: 28800003                 bleu,a  loc_F00577D4
F00577CC: a4102001                 mov     1, %l2
F00577D0: a4102000                 mov     0, %l2
F00577D4: d0040000                 ld      [%l0], %o0
F00577D8: 80a52000                 cmp     %l4, 0
F00577DC: 900a3ffe                 and     %o0, -2, %o0
F00577E0: 02800007                 be      loc_F00577FC
F00577E4: d0240000                 st      %o0, [%l0]
F00577E8: c02c0000                 clrb    [%l0]
F00577EC: c02c2001                 clrb    [%l0+1]
F00577F0: d0040000                 ld      [%l0], %o0
F00577F4: 900a001c                 and     %o0, %i4, %o0
F00577F8: d0240000                 st      %o0, [%l0]
F00577FC: 7ffebb41                 call    _umul
F0057800: 90100015                 mov     %l5, %o0
F0057804: 80a4e000                 cmp     %l3, 0
F0057808: 90022007                 inc     7, %o0
F005780C: 02800007                 be      loc_F0057828
F0057810: 91322003                 srl     %o0, 3, %o0
F0057814: a6100011                 mov     %l1, %l3
F0057818: 90022003                 inc     3, %o0
F005781C: 900a3ffc                 and     %o0, -4, %o0
F0057820: 10800005                 ba      loc_F0057834
F0057824: a2044008                 add     %l1, %o0, %l1
F0057828: e6044000                 ld      [%l1], %l3
F005782C: ae102001                 mov     1, %l7
F0057830: a2046004                 inc     4, %l1
F0057834: 80a4a000                 cmp     %l2, 0
F0057838: 0280002b                 be      loc_F00578E4
F005783C: 80a4401a                 cmp     %l1, %i2
F0057840: 4000085f                 call    _ipc_object_copyin_type
F0057844: 90100016                 mov     %l6, %o0
F0057848: 80a52000                 cmp     %l4, 0
F005784C: a8100008                 mov     %o0, %l4
F0057850: 02800004                 be      loc_F0057860
F0057854: ae100013                 mov     %l3, %l7
F0057858: 10800003                 ba      loc_F0057864
F005785C: e8342004                 sth     %l4, [%l0+4]
F0057860: e82c0000                 stb     %l4, [%l0]
F0057864: a4102000                 mov     0, %l2
F0057868: 80a48015                 cmp     %l2, %l5
F005786C: 3a80001d                 bcc,a   loc_F00578E0
F0057870: ae102001                 mov     1, %l7
F0057874: a6102000                 mov     0, %l3
F0057878: e004c017                 ld      [%l3+%l7], %l0
F005787C: 80a42000                 cmp     %l0, 0
F0057880: 22800014                 be,a    loc_F00578D0
F0057884: a404a001                 inc     %l2
F0057888: 80a43fff                 cmp     %l0, -1
F005788C: 22800011                 be,a    loc_F00578D0
F0057890: a404a001                 inc     %l2
F0057894: 90100010                 mov     %l0, %o0
F0057898: 40000899                 call    _ipc_object_copyin_from_kernel
F005789C: 92100016                 mov     %l6, %o1
F00578A0: 80a52010                 cmp     %l4, 0x10
F00578A4: 3280000b                 bne,a   loc_F00578D0
F00578A8: a404a001                 inc     %l2
F00578AC: 90100010                 mov     %l0, %o0
F00578B0: 40000d45                 call    _ipc_port_check_circularity
F00578B4: 92100019                 mov     %i1, %o1
F00578B8: 80a22000                 cmp     %o0, 0
F00578BC: 02800005                 be      loc_F00578D0
F00578C0: a404a001                 inc     %l2
F00578C4: d0062014                 ld      [%i0+0x14], %o0
F00578C8: 9012001b                 bset    %i3, %o0
F00578CC: d0262014                 st      %o0, [%i0+0x14]
F00578D0: 80a48015                 cmp     %l2, %l5
F00578D4: 0abfffe9                 bcs     loc_F0057878
F00578D8: a604e004                 inc     4, %l3
F00578DC: ae102001                 mov     1, %l7
F00578E0: 80a4401a                 cmp     %l1, %i2
F00578E4: 2abfffa6                 bcs,a   loc_F005777C
F00578E8: d0044000                 ld      [%l1], %o0
F00578EC: 80a5e000                 cmp     %l7, 0
F00578F0: 02800005                 be      locret_F0057904
F00578F4: 13200000                 sethi   0x80000000, %o1
F00578F8: d0062014                 ld      [%i0+0x14], %o0
F00578FC: 90120009                 bset    %o1, %o0
F0057900: d0262014                 st      %o0, [%i0+0x14]
F0057904: 81c7e008                 ret
F0057908: 81e80000                 restore
