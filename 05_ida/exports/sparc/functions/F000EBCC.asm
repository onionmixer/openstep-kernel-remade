F000EBCC: 9de3bf98                 save    %sp, -0x68, %sp
F000EBD0: 860e603f                 and     %i1, 0x3F, %g3
F000EBD4: 053c04d28410a0b0         set     _posix_proc_hash, %g2
F000EBDC: 8728e002                 sll     %g3, 2, %g3
F000EBE0: c600c002                 ld      [%g3+%g2], %g3
F000EBE4: 80a0e000                 cmp     %g3, 0
F000EBE8: 0280000b                 be      loc_F000EC14
F000EBEC: b4100018                 mov     %i0, %i2
F000EBF0: c400c000                 ld      [%g3], %g2
F000EBF4: 80a08019                 cmp     %g2, %i1
F000EBF8: 32800004                 bne,a   loc_F000EC08
F000EBFC: c600e01c                 ld      [%g3+0x1C], %g3
F000EC00: 1080000e                 ba      locret_F000EC38
F000EC04: b0102000                 mov     0, %i0
F000EC08: 80a0e000                 cmp     %g3, 0
F000EC0C: 32bffffa                 bne,a   loc_F000EBF4
F000EC10: c400c000                 ld      [%g3], %g2
F000EC14: f2268000                 st      %i1, [%i2]
F000EC18: 840e603f                 and     %i1, 0x3F, %g2
F000EC1C: 073c04d28610e0b0         set     _posix_proc_hash, %g3
F000EC24: 8528a002                 sll     %g2, 2, %g2
F000EC28: f2008003                 ld      [%g2+%g3], %i1
F000EC2C: b0102001                 mov     1, %i0
F000EC30: f226a01c                 st      %i1, [%i2+0x1C]
F000EC34: f4208003                 st      %i2, [%g2+%g3]
F000EC38: 81c7e008                 ret
F000EC3C: 81e80000                 restore
