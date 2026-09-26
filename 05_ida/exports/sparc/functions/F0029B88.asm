F0029B88: 9de3bf98                 save    %sp, -0x68, %sp
F0029B8C: a2100018                 mov     %i0, %l1
F0029B90: 92046010                 add     %l1, 0x10, %o1
F0029B94: 80a44009                 cmp     %l1, %o1
F0029B98: 1a80000e                 bcc     loc_F0029BD0
F0029B9C: a0100011                 mov     %l1, %l0
F0029BA0: d04c0000                 ldsb    [%l0], %o0
F0029BA4: 80a22000                 cmp     %o0, 0
F0029BA8: 0280000a                 be      loc_F0029BD0
F0029BAC: 90023fd0                 inc     -0x30, %o0
F0029BB0: 900a20ff                 and     %o0, 0xFF, %o0
F0029BB4: 80a22009                 cmp     %o0, 9
F0029BB8: 28800007                 bleu,a  loc_F0029BD4
F0029BBC: d24c0000                 ldsb    [%l0], %o1
F0029BC0: a0042001                 inc     %l0
F0029BC4: 80a40009                 cmp     %l0, %o1
F0029BC8: 2abffff7                 bcs,a   loc_F0029BA4
F0029BCC: d04c0000                 ldsb    [%l0], %o0
F0029BD0: d24c0000                 ldsb    [%l0], %o1
F0029BD4: 80a26000                 cmp     %o1, 0
F0029BD8: 02800005                 be      loc_F0029BEC
F0029BDC: 90046010                 add     %l1, 0x10, %o0
F0029BE0: 80a40008                 cmp     %l0, %o0
F0029BE4: 12800004                 bne     loc_F0029BF4
F0029BE8: 113c04d0                 sethi   -0xFECC000, %o0
F0029BEC: 1080001a                 ba      locret_F0029C54
F0029BF0: b0102000                 mov     0, %i0
F0029BF4: f00220b8                 ld      [%o0+0xB8], %i0
F0029BF8: 80a62000                 cmp     %i0, 0
F0029BFC: 02800016                 be      locret_F0029C54
F0029C00: a4027fd0                 add     %o1, -0x30, %l2
F0029C04: 27000004                 sethi   0x1000, %l3
F0029C08: d0060000                 ld      [%i0], %o0! void *
F0029C0C: 92100011                 mov     %l1, %o1! void *
F0029C10: 7fff70d3                 call    _bcmp
F0029C14: 94240011                 sub     %l0, %l1, %o2
F0029C18: 80a22000                 cmp     %o0, 0
F0029C1C: 3280000b                 bne,a   loc_F0029C48
F0029C20: f006205c                 ld      [%i0+0x5C], %i0
F0029C24: d0062014                 ld      [%i0+0x14], %o0
F0029C28: 80a20013                 cmp     %o0, %l3
F0029C2C: 32800007                 bne,a   loc_F0029C48
F0029C30: f006205c                 ld      [%i0+0x5C], %i0
F0029C34: d0562008                 ldsh    [%i0+8], %o0
F0029C38: 80a48008                 cmp     %l2, %o0
F0029C3C: 02800006                 be      locret_F0029C54
F0029C40: 01000000                 nop
F0029C44: f006205c                 ld      [%i0+0x5C], %i0
F0029C48: 80a62000                 cmp     %i0, 0
F0029C4C: 32bffff0                 bne,a   loc_F0029C0C
F0029C50: d0060000                 ld      [%i0], %o0
F0029C54: 81c7e008                 ret
F0029C58: 81e80000                 restore
