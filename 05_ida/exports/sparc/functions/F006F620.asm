F006F620: 9de3bf98                 save    %sp, -0x68, %sp
F006F624: 80a62000                 cmp     %i0, 0
F006F628: 12800004                 bne     loc_F006F638
F006F62C: aa102000                 mov     0, %l5
F006F630: 108000a9                 ba      locret_F006F8D4
F006F634: b0102004                 mov     4, %i0
F006F638: a8102000                 mov     0, %l4
F006F63C: a0062158                 add     %i0, 0x158, %l0
F006F640: d0040000                 ld      [%l0], %o0
F006F644: 80a22000                 cmp     %o0, 0
F006F648: 12bffffe                 bne     loc_F006F640
F006F64C: 01000000                 nop
F006F650: 40009e16                 call    _simple_lock_try
F006F654: 90100010                 mov     %l0, %o0
F006F658: 80a22000                 cmp     %o0, 0
F006F65C: 02bffff9                 be      loc_F006F640
F006F660: 01000000                 nop
F006F664: d0062154                 ld      [%i0+0x154], %o0
F006F668: 80a22000                 cmp     %o0, 0
F006F66C: 0280008c                 be      loc_F006F89C
F006F670: 80a6e000                 cmp     %i3, 0
F006F674: 32800003                 bne,a   loc_F006F680
F006F678: e6062140                 ld      [%i0+0x140], %l3
F006F67C: e6062134                 ld      [%i0+0x134], %l3
F006F680: ad2ce002                 sll     %l3, 2, %l6
F006F684: 80a58015                 cmp     %l6, %l5
F006F688: 08800010                 bleu    loc_F006F6C8
F006F68C: 80a6e000                 cmp     %i3, 0
F006F690: c0262158                 clr     [%i0+0x158]
F006F694: 80a56000                 cmp     %l5, 0
F006F698: 02800004                 be      loc_F006F6A8
F006F69C: 90100014                 mov     %l4, %o0
F006F6A0: 7fffe2c0                 call    _kfree
F006F6A4: 92100015                 mov     %l5, %o1
F006F6A8: aa100016                 mov     %l6, %l5
F006F6AC: 7fffe271                 call    _kalloc
F006F6B0: 90100015                 mov     %l5, %o0
F006F6B4: a8920000                 orcc    %o0, %g0, %l4
F006F6B8: 12bfffe2                 bne     loc_F006F640
F006F6BC: 01000000                 nop
F006F6C0: 10800085                 ba      locret_F006F8D4
F006F6C4: b0102006                 mov     6, %i0
F006F6C8: 02800005                 be      loc_F006F6DC
F006F6CC: 80a6e001                 cmp     %i3, 1
F006F6D0: 02800012                 be      loc_F006F718
F006F6D4: a0102000                 mov     0, %l0
F006F6D8: 3080001d                 ba,a    loc_F006F74C
F006F6DC: a0102000                 mov     0, %l0
F006F6E0: e206212c                 ld      [%i0+0x12C], %l1
F006F6E4: 80a40013                 cmp     %l0, %l3
F006F6E8: 1a800019                 bcc     loc_F006F74C
F006F6EC: ae100014                 mov     %l4, %l7
F006F6F0: a4102000                 mov     0, %l2
F006F6F4: 40000e9c                 call    _task_reference
F006F6F8: 90100011                 mov     %l1, %o0
F006F6FC: e2248017                 st      %l1, [%l2+%l7]
F006F700: a404a004                 inc     4, %l2
F006F704: a0042001                 inc     %l0
F006F708: 80a40013                 cmp     %l0, %l3
F006F70C: 0abffffa                 bcs     loc_F006F6F4
F006F710: e2046010                 ld      [%l1+0x10], %l1
F006F714: 3080000e                 ba,a    loc_F006F74C
F006F718: e2062138                 ld      [%i0+0x138], %l1
F006F71C: 80a40013                 cmp     %l0, %l3
F006F720: 1a80000b                 bcc     loc_F006F74C
F006F724: ae100014                 mov     %l4, %l7
F006F728: a4102000                 mov     0, %l2
F006F72C: 40001442                 call    _thread_reference
F006F730: 90100011                 mov     %l1, %o0
F006F734: e2248017                 st      %l1, [%l2+%l7]
F006F738: a404a004                 inc     4, %l2
F006F73C: a0042001                 inc     %l0
F006F740: 80a40013                 cmp     %l0, %l3
F006F744: 0abffffa                 bcs     loc_F006F72C
F006F748: e2046018                 ld      [%l1+0x18], %l1
F006F74C: c0262158                 clr     [%i0+0x158]
F006F750: 80a4e000                 cmp     %l3, 0
F006F754: 1280000b                 bne     loc_F006F780
F006F758: 80a58015                 cmp     %l6, %l5
F006F75C: c0264000                 clr     [%i1]
F006F760: 80a56000                 cmp     %l5, 0
F006F764: 0280005b                 be      loc_F006F8D0
F006F768: c0268000                 clr     [%i2]
F006F76C: 90100014                 mov     %l4, %o0
F006F770: 7fffe28c                 call    _kfree
F006F774: 92100015                 mov     %l5, %o1
F006F778: 10800057                 ba      locret_F006F8D4
F006F77C: b0102000                 mov     0, %i0
F006F780: 3a800032                 bcc,a   loc_F006F848
F006F784: e8264000                 st      %l4, [%i1]
F006F788: 7fffe23a                 call    _kalloc
F006F78C: 90100016                 mov     %l6, %o0
F006F790: a0920000                 orcc    %o0, %g0, %l0
F006F794: 32800025                 bne,a   loc_F006F828
F006F798: 90100014                 mov     %l4, %o0
F006F79C: 80a6e000                 cmp     %i3, 0
F006F7A0: 02800006                 be      loc_F006F7B8
F006F7A4: 80a6e001                 cmp     %i3, 1
F006F7A8: 02800011                 be      loc_F006F7EC
F006F7AC: a0102000                 mov     0, %l0
F006F7B0: 1080001a                 ba      loc_F006F818
F006F7B4: 90100014                 mov     %l4, %o0
F006F7B8: a0102000                 mov     0, %l0
F006F7BC: 80a40013                 cmp     %l0, %l3
F006F7C0: 1a800015                 bcc     loc_F006F814
F006F7C4: a4100014                 mov     %l4, %l2
F006F7C8: a2102000                 mov     0, %l1
F006F7CC: d0044012                 ld      [%l1+%l2], %o0
F006F7D0: 40000e36                 call    _task_deallocate
F006F7D4: a0042001                 inc     %l0
F006F7D8: 80a40013                 cmp     %l0, %l3
F006F7DC: 0abffffc                 bcs     loc_F006F7CC
F006F7E0: a2046004                 inc     4, %l1
F006F7E4: 1080000d                 ba      loc_F006F818
F006F7E8: 90100014                 mov     %l4, %o0
F006F7EC: 80a40013                 cmp     %l0, %l3
F006F7F0: 1a800009                 bcc     loc_F006F814
F006F7F4: a4100014                 mov     %l4, %l2
F006F7F8: a2102000                 mov     0, %l1
F006F7FC: d0044012                 ld      [%l1+%l2], %o0
F006F800: 400012eb                 call    _thread_deallocate
F006F804: a0042001                 inc     %l0
F006F808: 80a40013                 cmp     %l0, %l3
F006F80C: 0abffffc                 bcs     loc_F006F7FC
F006F810: a2046004                 inc     4, %l1
F006F814: 90100014                 mov     %l4, %o0! void *
F006F818: 7fffe262                 call    _kfree
F006F81C: 92100015                 mov     %l5, %o1
F006F820: 1080002d                 ba      locret_F006F8D4
F006F824: b0102006                 mov     6, %i0
F006F828: 92100010                 mov     %l0, %o1! void *
F006F82C: 400094b9                 call    _bcopy
F006F830: 94100016                 mov     %l6, %o2
F006F834: 90100014                 mov     %l4, %o0
F006F838: 7fffe25a                 call    _kfree
F006F83C: 92100015                 mov     %l5, %o1
F006F840: a8100010                 mov     %l0, %l4
F006F844: e8264000                 st      %l4, [%i1]
F006F848: 80a6e000                 cmp     %i3, 0
F006F84C: 02800007                 be      loc_F006F868
F006F850: e6268000                 st      %l3, [%i2]
F006F854: 80a6e001                 cmp     %i3, 1
F006F858: 02800014                 be      loc_F006F8A8
F006F85C: a0102000                 mov     0, %l0
F006F860: 1080001d                 ba      locret_F006F8D4
F006F864: b0102000                 mov     0, %i0
F006F868: a0102000                 mov     0, %l0
F006F86C: 80a40013                 cmp     %l0, %l3
F006F870: 1a800018                 bcc     loc_F006F8D0
F006F874: b0100014                 mov     %l4, %i0
F006F878: d0060000                 ld      [%i0], %o0
F006F87C: 7fffe0a0                 call    _convert_task_to_port
F006F880: a0042001                 inc     %l0
F006F884: d0260000                 st      %o0, [%i0]
F006F888: 80a40013                 cmp     %l0, %l3
F006F88C: 0abffffb                 bcs     loc_F006F878
F006F890: b0062004                 inc     4, %i0
F006F894: 10800010                 ba      locret_F006F8D4
F006F898: b0102000                 mov     0, %i0
F006F89C: c0262158                 clr     [%i0+0x158]
F006F8A0: 1080000d                 ba      locret_F006F8D4
F006F8A4: b0102005                 mov     5, %i0
F006F8A8: 80a40013                 cmp     %l0, %l3
F006F8AC: 1a800009                 bcc     loc_F006F8D0
F006F8B0: b0100014                 mov     %l4, %i0
F006F8B4: d0060000                 ld      [%i0], %o0
F006F8B8: 7fffe0a8                 call    _convert_thread_to_port
F006F8BC: a0042001                 inc     %l0
F006F8C0: d0260000                 st      %o0, [%i0]
F006F8C4: 80a40013                 cmp     %l0, %l3
F006F8C8: 0abffffb                 bcs     loc_F006F8B4
F006F8CC: b0062004                 inc     4, %i0
F006F8D0: b0102000                 mov     0, %i0
F006F8D4: 81c7e008                 ret
F006F8D8: 81e80000                 restore
