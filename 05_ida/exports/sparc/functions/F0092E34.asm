F0092E34: 9de3bf98                 save    %sp, -0x68, %sp
F0092E38: 840e20ff                 and     %i0, 0xFF, %g2
F0092E3C: 8730a003                 srl     %g2, 3, %g3
F0092E40: 80a0e00f                 cmp     %g3, 0xF
F0092E44: 14800005                 bg      loc_F0092E58
F0092E48: b20e2007                 and     %i0, 7, %i1
F0092E4C: 80a66007                 cmp     %i1, 7
F0092E50: 04800004                 ble     loc_F0092E60
F0092E54: 8528e003                 sll     %g3, 3, %g2
F0092E58: 10800014                 ba      locret_F0092EA8
F0092E5C: b0102000                 mov     0, %i0
F0092E60: 84008003                 add     %g2, %g3, %g2
F0092E64: b528a002                 sll     %g2, 2, %i2
F0092E68: 053c04c4b610a000         set     unk_F0131000, %i3
F0092E70: 1280000b                 bne     loc_F0092E9C
F0092E74: 8606801b                 add     %i2, %i3, %g3
F0092E78: 852e2010                 sll     %i0, 16, %g2
F0092E7C: 073c04c4                 sethi   %hi(dword_F0131240), %g3
F0092E80: c600e240                 ld      [%g3+%lo(dword_F0131240)], %g3
F0092E84: 8530a018                 srl     %g2, 24, %g2
F0092E88: 80a08003                 cmp     %g2, %g3
F0092E8C: 32800007                 bne,a   locret_F0092EA8
F0092E90: f006801b                 ld      [%i2+%i3], %i0
F0092E94: 10800005                 ba      locret_F0092EA8
F0092E98: b0102000                 mov     0, %i0
F0092E9C: 852e6002                 sll     %i1, 2, %g2
F0092EA0: 84008003                 add     %g2, %g3, %g2
F0092EA4: f000a004                 ld      [%g2+4], %i0
F0092EA8: 81c7e008                 ret
F0092EAC: 81e80000                 restore
