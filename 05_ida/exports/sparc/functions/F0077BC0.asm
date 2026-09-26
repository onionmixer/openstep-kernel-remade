F0077BC0: 9de3bf98                 save    %sp, -0x68, %sp
F0077BC4: c4066004                 ld      [%i1+4], %g2
F0077BC8: c6062010                 ld      [%i0+0x10], %g3
F0077BCC: fa062018                 ld      [%i0+0x18], %i5
F0077BD0: 85308003                 srl     %g2, %g3, %g2
F0077BD4: 80a0801d                 cmp     %g2, %i5
F0077BD8: 04800003                 ble     loc_F0077BE4
F0077BDC: 82100002                 mov     %g2, %g1
F0077BE0: 8210001d                 mov     %i5, %g1
F0077BE4: 85368003                 srl     %i2, %g3, %g2
F0077BE8: 80a0801d                 cmp     %g2, %i5
F0077BEC: 04800003                 ble     loc_F0077BF8
F0077BF0: b8100002                 mov     %g2, %i4
F0077BF4: b810001d                 mov     %i5, %i4
F0077BF8: 80a70001                 cmp     %i4, %g1
F0077BFC: c6062014                 ld      [%i0+0x14], %g3
F0077C00: 852f2004                 sll     %i4, 4, %g2
F0077C04: 8600c002                 add     %g3, %g2, %g3
F0077C08: 0280002e                 be      loc_F0077CC0
F0077C0C: 8800fff0                 add     %g3, -0x10, %g4
F0077C10: c400fff0                 ld      [%g3-0x10], %g2
F0077C14: 80a6c002                 cmp     %i3, %g2
F0077C18: 32800020                 bne,a   loc_F0077C98
F0077C1C: c6062014                 ld      [%i0+0x14], %g3
F0077C20: 80a7001d                 cmp     %i4, %i5
F0077C24: 1680000f                 bge     loc_F0077C60
F0077C28: c6064000                 ld      [%i1], %g3
F0077C2C: 80a0e000                 cmp     %g3, 0
F0077C30: 22800019                 be,a    loc_F0077C94
F0077C34: c6210000                 st      %g3, [%g4]
F0077C38: c400e004                 ld      [%g3+4], %g2
F0077C3C: 80a0801a                 cmp     %g2, %i2
F0077C40: 22800015                 be,a    loc_F0077C94
F0077C44: c6210000                 st      %g3, [%g4]
F0077C48: c600c000                 ld      [%g3], %g3
F0077C4C: 80a0e000                 cmp     %g3, 0
F0077C50: 32bffffb                 bne,a   loc_F0077C3C
F0077C54: c400e004                 ld      [%g3+4], %g2
F0077C58: 1080000f                 ba      loc_F0077C94
F0077C5C: c6210000                 st      %g3, [%g4]
F0077C60: 80a0e000                 cmp     %g3, 0
F0077C64: 2280000c                 be,a    loc_F0077C94
F0077C68: c6210000                 st      %g3, [%g4]
F0077C6C: f4062004                 ld      [%i0+4], %i2
F0077C70: c400e004                 ld      [%g3+4], %g2
F0077C74: 80a0801a                 cmp     %g2, %i2
F0077C78: 3a800007                 bcc,a   loc_F0077C94
F0077C7C: c6210000                 st      %g3, [%g4]
F0077C80: c600c000                 ld      [%g3], %g3
F0077C84: 80a0e000                 cmp     %g3, 0
F0077C88: 32bffffb                 bne,a   loc_F0077C74
F0077C8C: c400e004                 ld      [%g3+4], %g2
F0077C90: c6210000                 st      %g3, [%g4]
F0077C94: c6062014                 ld      [%i0+0x14], %g3
F0077C98: 85286004                 sll     %g1, 4, %g2
F0077C9C: 8600c002                 add     %g3, %g2, %g3
F0077CA0: c400fff0                 ld      [%g3-0x10], %g2
F0077CA4: 80a0a000                 cmp     %g2, 0
F0077CA8: 0280000a                 be      loc_F0077CD0
F0077CAC: 80a64002                 cmp     %i1, %g2
F0077CB0: 1a800009                 bcc     locret_F0077CD4
F0077CB4: 01000000                 nop
F0077CB8: 10800007                 ba      locret_F0077CD4
F0077CBC: f220fff0                 st      %i1, [%g3-0x10]
F0077CC0: c400fff0                 ld      [%g3-0x10], %g2
F0077CC4: 80a6c002                 cmp     %i3, %g2
F0077CC8: 12800003                 bne     locret_F0077CD4
F0077CCC: 01000000                 nop
F0077CD0: f220fff0                 st      %i1, [%g3-0x10]
F0077CD4: 81c7e008                 ret
F0077CD8: 81e80000                 restore
