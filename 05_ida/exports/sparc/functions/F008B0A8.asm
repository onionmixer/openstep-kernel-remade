F008B0A8: 9de3bf98                 save    %sp, -0x68, %sp
F008B0AC: 053c04f4                 sethi   %hi(_page_shift), %g2
F008B0B0: c400a348                 ld      [%g2+%lo(_page_shift)], %g2
F008B0B4: c6062010                 ld      [%i0+0x10], %g3
F008B0B8: b3364002                 srl     %i1, %g2, %i1
F008B0BC: 80a64003                 cmp     %i1, %g3
F008B0C0: 1a800018                 bcc     loc_F008B120
F008B0C4: 8528e002                 sll     %g3, 2, %g2
F008B0C8: 80a0a040                 cmp     %g2, 0x40 ! '@'
F008B0CC: 0880000f                 bleu    loc_F008B108
F008B0D0: 85366004                 srl     %i1, 4, %g2
F008B0D4: c6062008                 ld      [%i0+8], %g3
F008B0D8: 8528a002                 sll     %g2, 2, %g2
F008B0DC: c600c002                 ld      [%g3+%g2], %g3
F008B0E0: 80a0e000                 cmp     %g3, 0
F008B0E4: 0280000f                 be      loc_F008B120
F008B0E8: 840e600f                 and     %i1, 0xF, %g2
F008B0EC: b328a002                 sll     %g2, 2, %i1
F008B0F0: c408c019                 ldub    [%g3+%i1], %g2
F008B0F4: 80a0a000                 cmp     %g2, 0
F008B0F8: 0280000e                 be      locret_F008B130
F008B0FC: b0102000                 mov     0, %i0
F008B100: 1080000a                 ba      loc_F008B128
F008B104: c400c019                 ld      [%g3+%i1], %g2
F008B108: f0062008                 ld      [%i0+8], %i0
F008B10C: b32e6002                 sll     %i1, 2, %i1
F008B110: c40e0019                 ldub    [%i0+%i1], %g2
F008B114: 80a0a000                 cmp     %g2, 0
F008B118: 32800004                 bne,a   loc_F008B128
F008B11C: c4060019                 ld      [%i0+%i1], %g2
F008B120: 10800004                 ba      locret_F008B130
F008B124: b0102000                 mov     0, %i0
F008B128: c4268000                 st      %g2, [%i2]
F008B12C: b0102001                 mov     1, %i0
F008B130: 81c7e008                 ret
F008B134: 81e80000                 restore
