F00C5D84: 9de3bf98                 save    %sp, -0x68, %sp
F00C5D88: f40e0000                 ldub    [%i0], %i2
F00C5D8C: c40e4000                 ldub    [%i1], %g2
F00C5D90: 872ea018                 sll     %i2, 24, %g3
F00C5D94: 80a0e000                 cmp     %g3, 0
F00C5D98: 02800022                 be      loc_F00C5E20
F00C5D9C: b0062001                 inc     %i0
F00C5DA0: 8528a018                 sll     %g2, 24, %g2
F00C5DA4: 8338a018                 sra     %g2, 24, %g1
F00C5DA8: 8538e018                 sra     %g3, 24, %g2
F00C5DAC: 80a08001                 cmp     %g2, %g1
F00C5DB0: 32800018                 bne,a   loc_F00C5E10
F00C5DB4: f40e0000                 ldub    [%i0], %i2
F00C5DB8: ba066002                 add     %i1, 2, %i5
F00C5DBC: f40e6001                 ldub    [%i1+1], %i2
F00C5DC0: b8062001                 add     %i0, 1, %i4
F00C5DC4: c64e0000                 ldsb    [%i0], %g3
F00C5DC8: 10800009                 ba      loc_F00C5DEC
F00C5DCC: b72ea018                 sll     %i2, 24, %i3
F00C5DD0: 0280000c                 be      loc_F00C5E00
F00C5DD4: 80a6a000                 cmp     %i2, 0
F00C5DD8: f40f4000                 ldub    [%i5], %i2
F00C5DDC: c64f0000                 ldsb    [%i4], %g3
F00C5DE0: b72ea018                 sll     %i2, 24, %i3
F00C5DE4: ba076001                 inc     %i5
F00C5DE8: b8072001                 inc     %i4
F00C5DEC: 853ee018                 sra     %i3, 24, %g2
F00C5DF0: 80a0c002                 cmp     %g3, %g2
F00C5DF4: 02bffff7                 be      loc_F00C5DD0
F00C5DF8: 80a6e000                 cmp     %i3, 0
F00C5DFC: 80a6a000                 cmp     %i2, 0
F00C5E00: 32800004                 bne,a   loc_F00C5E10
F00C5E04: f40e0000                 ldub    [%i0], %i2
F00C5E08: 10800007                 ba      locret_F00C5E24
F00C5E0C: b0063fff                 inc     -1, %i0
F00C5E10: 872ea018                 sll     %i2, 24, %g3
F00C5E14: 80a0e000                 cmp     %g3, 0
F00C5E18: 12bfffe4                 bne     loc_F00C5DA8
F00C5E1C: b0062001                 inc     %i0
F00C5E20: b0102000                 mov     0, %i0
F00C5E24: 81c7e008                 ret
F00C5E28: 81e80000                 restore
