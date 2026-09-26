F003BBE8: 9de3bf98                 save    %sp, -0x68, %sp
F003BBEC: 133c0432                 sethi   %hi(_rfssize), %o1
F003BBF0: d00261f4                 ld      [%o1+%lo(_rfssize)], %o0
F003BBF4: 80a22000                 cmp     %o0, 0
F003BBF8: 32800024                 bne,a   loc_F003BC88
F003BBFC: 133c0432                 sethi   -0xFEF3800, %o1
F003BC00: 9e100009                 mov     %o1, %o7
F003BC04: 84102000                 mov     0, %g2
F003BC08: 113c0432b0122294         set     _rfsdisptab, %i0
F003BC10: 9a0621b0                 add     %i0, 0x1B0, %o5
F003BC14: 8210000d                 mov     %o5, %g1
F003BC18: 98008018                 add     %g2, %i0, %o4
F003BC1C: 80a3000d                 cmp     %o4, %o5
F003BC20: 1a800015                 bcc     loc_F003BC74
F003BC24: 113c0433                 sethi   %hi(_nfs_portmon), %o0
F003BC28: 90122044                 bset    %lo(_nfs_portmon), %o0
F003BC2C: 86008008                 add     %g2, %o0, %g3
F003BC30: 96032010                 add     %o4, 0x10, %o3
F003BC34: d203e1f4                 ld      [%o7+0x1F4], %o1
F003BC38: d002fff8                 ld      [%o3-8], %o0
F003BC3C: 80a24008                 cmp     %o1, %o0
F003BC40: 26800002                 bl,a    loc_F003BC48
F003BC44: 92100008                 mov     %o0, %o1
F003BC48: d223e1f4                 st      %o1, [%o7+0x1F4]
F003BC4C: d402c000                 ld      [%o3], %o2
F003BC50: 90100009                 mov     %o1, %o0
F003BC54: 80a2000a                 cmp     %o0, %o2
F003BC58: 26800002                 bl,a    loc_F003BC60
F003BC5C: 9010000a                 mov     %o2, %o0
F003BC60: d023e1f4                 st      %o0, [%o7+0x1F4]
F003BC64: 98032018                 inc     0x18, %o4
F003BC68: 80a30003                 cmp     %o4, %g3
F003BC6C: 0abffff2                 bcs     loc_F003BC34
F003BC70: 9602e018                 inc     0x18, %o3
F003BC74: 9a0361b0                 inc     0x1B0, %o5
F003BC78: 80a34001                 cmp     %o5, %g1
F003BC7C: 04bfffe7                 ble     loc_F003BC18
F003BC80: 8400a1b0                 inc     0x1B0, %g2
F003BC84: 133c0432                 sethi   -0xFEF3800, %o1
F003BC88: f00261f0                 ld      [%o1+0x1F0], %i0
F003BC8C: 80a62000                 cmp     %i0, 0
F003BC90: 02800005                 be      loc_F003BCA4
F003BC94: 113c0432                 sethi   -0xFEF3800, %o0
F003BC98: d0060000                 ld      [%i0], %o0
F003BC9C: 10800006                 ba      locret_F003BCB4
F003BCA0: d02261f0                 st      %o0, [%o1+0x1F0]
F003BCA4: d00221f4                 ld      [%o0+0x1F4], %o0
F003BCA8: 4000b0f2                 call    _kalloc
F003BCAC: 90022004                 inc     4, %o0
F003BCB0: b0022004                 add     %o0, 4, %i0
F003BCB4: 81c7e008                 ret
F003BCB8: 81e80000                 restore
