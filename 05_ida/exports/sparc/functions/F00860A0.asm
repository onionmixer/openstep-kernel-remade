F00860A0: 9de3bf98                 save    %sp, -0x68, %sp
F00860A4: a0100018                 mov     %i0, %l0
F00860A8: d0042014                 ld      [%l0+0x14], %o0
F00860AC: 80a64008                 cmp     %i1, %o0
F00860B0: 0a800006                 bcs     loc_F00860C8
F00860B4: 9006401a                 add     %i1, %i2, %o0
F00860B8: d2042018                 ld      [%l0+0x18], %o1
F00860BC: 80a20009                 cmp     %o0, %o1
F00860C0: 08800004                 bleu    loc_F00860D0
F00860C4: 01000000                 nop
F00860C8: 10800010                 ba      locret_F0086108
F00860CC: b0102004                 mov     4, %i0
F00860D0: 7fff8b3d                 call    _lock_write
F00860D4: 90100010                 mov     %l0, %o0
F00860D8: d004204c                 ld      [%l0+0x4C], %o0
F00860DC: 90022001                 inc     %o0
F00860E0: d024204c                 st      %o0, [%l0+0x4C]
F00860E4: d0042024                 ld      [%l0+0x24], %o0
F00860E8: 92100019                 mov     %i1, %o1
F00860EC: 9410001a                 mov     %i2, %o2
F00860F0: 9610001b                 mov     %i3, %o3
F00860F4: 40006c21                 call    _pmap_attribute
F00860F8: 9810001c                 mov     %i4, %o4
F00860FC: b0100008                 mov     %o0, %i0
F0086100: 7fff8bcd                 call    _lock_done
F0086104: 90100010                 mov     %l0, %o0
F0086108: 81c7e008                 ret
F008610C: 81e80000                 restore
