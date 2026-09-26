F005F668: 9de3bf90                 save    %sp, -0x70, %sp
F005F66C: 90960000                 orcc    %i0, %g0, %o0
F005F670: 12800004                 bne     loc_F005F680
F005F674: 92100019                 mov     %i1, %o1
F005F678: 10800023                 ba      locret_F005F704
F005F67C: b0102010                 mov     0x10, %i0
F005F680: 94102001                 mov     1, %o2
F005F684: 7fffe816                 call    _ipc_object_translate
F005F688: 9607bff4                 add     %fp, var_C, %o3
F005F68C: 80a22000                 cmp     %o0, 0
F005F690: 1280001d                 bne     locret_F005F704
F005F694: b0100008                 mov     %o0, %i0
F005F698: d007bff4                 ld      [%fp+var_C], %o0
F005F69C: d402202c                 ld      [%o0+0x2C], %o2
F005F6A0: 80a2a000                 cmp     %o2, 0
F005F6A4: 32800005                 bne,a   loc_F005F6B8
F005F6A8: d002a004                 ld      [%o2+4], %o0
F005F6AC: 98102000                 mov     0, %o4
F005F6B0: 10800011                 ba      loc_F005F6F4
F005F6B4: 96102000                 mov     0, %o3
F005F6B8: 92102001                 mov     1, %o1
F005F6BC: d8020000                 ld      [%o0], %o4
F005F6C0: 80a2400c                 cmp     %o1, %o4
F005F6C4: 1a80000b                 bcc     loc_F005F6F0
F005F6C8: 96102000                 mov     0, %o3
F005F6CC: 9402a008                 inc     8, %o2
F005F6D0: d002a004                 ld      [%o2+4], %o0
F005F6D4: 80a22000                 cmp     %o0, 0
F005F6D8: 32800002                 bne,a   loc_F005F6E0
F005F6DC: 9602e001                 inc     %o3
F005F6E0: 92026001                 inc     %o1
F005F6E4: 80a2400c                 cmp     %o1, %o4
F005F6E8: 0abffffa                 bcs     loc_F005F6D0
F005F6EC: 9402a008                 inc     8, %o2
F005F6F0: d007bff4                 ld      [%fp+var_C], %o0
F005F6F4: b0102000                 mov     0, %i0
F005F6F8: c0220000                 clr     [%o0]
F005F6FC: d8268000                 st      %o4, [%i2]
F005F700: d626c000                 st      %o3, [%i3]
F005F704: 81c7e008                 ret
F005F708: 81e80000                 restore
