F0084CD8: 9de3bf90                 save    %sp, -0x70, %sp
F0084CDC: 80a6e002                 cmp     %i3, 2
F0084CE0: 34800041                 bg,a    locret_F0084DE4
F0084CE4: b0102004                 mov     4, %i0
F0084CE8: 80a6e000                 cmp     %i3, 0
F0084CEC: 16800004                 bge     loc_F0084CFC
F0084CF0: 01000000                 nop
F0084CF4: 1080003c                 ba      locret_F0084DE4
F0084CF8: b0102004                 mov     4, %i0
F0084CFC: 7fff9032                 call    _lock_write
F0084D00: 90100018                 mov     %i0, %o0
F0084D04: d006204c                 ld      [%i0+0x4C], %o0
F0084D08: 90022001                 inc     %o0
F0084D0C: d026204c                 st      %o0, [%i0+0x4C]
F0084D10: d0062014                 ld      [%i0+0x14], %o0
F0084D14: 80a64008                 cmp     %i1, %o0
F0084D18: 2a800002                 bcs,a   loc_F0084D20
F0084D1C: b2100008                 mov     %o0, %i1
F0084D20: d0062018                 ld      [%i0+0x18], %o0
F0084D24: 80a68008                 cmp     %i2, %o0
F0084D28: 38800002                 bgu,a   loc_F0084D30
F0084D2C: b4100008                 mov     %o0, %i2
F0084D30: 80a6401a                 cmp     %i1, %i2
F0084D34: 38800002                 bgu,a   loc_F0084D3C
F0084D38: b210001a                 mov     %i2, %i1
F0084D3C: 90100018                 mov     %i0, %o0
F0084D40: 92100019                 mov     %i1, %o1
F0084D44: 7ffffdd9                 call    _vm_map_lookup_entry
F0084D48: 9407bff4                 add     %fp, var_C, %o2
F0084D4C: 80a22000                 cmp     %o0, 0
F0084D50: 0280000b                 be      loc_F0084D7C
F0084D54: e007bff4                 ld      [%fp+var_C], %l0
F0084D58: d0042008                 ld      [%l0+8], %o0
F0084D5C: 80a64008                 cmp     %i1, %o0
F0084D60: 08800009                 bleu    loc_F0084D84
F0084D64: 9006200c                 add     %i0, 0xC, %o0
F0084D68: 92100010                 mov     %l0, %o1
F0084D6C: 7ffffe69                 call    __vm_map_clip_start
F0084D70: 94100019                 mov     %i1, %o2
F0084D74: 10800005                 ba      loc_F0084D88
F0084D78: 9006200c                 add     %i0, 0xC, %o0
F0084D7C: d007bff4                 ld      [%fp+var_C], %o0
F0084D80: e0022004                 ld      [%o0+4], %l0
F0084D84: 9006200c                 add     %i0, 0xC, %o0
F0084D88: 80a40008                 cmp     %l0, %o0
F0084D8C: 02800013                 be      loc_F0084DD8
F0084D90: 01000000                 nop
F0084D94: b2100008                 mov     %o0, %i1
F0084D98: d0042008                 ld      [%l0+8], %o0
F0084D9C: 80a2001a                 cmp     %o0, %i2
F0084DA0: 1a80000e                 bcc     loc_F0084DD8
F0084DA4: 01000000                 nop
F0084DA8: d004200c                 ld      [%l0+0xC], %o0
F0084DAC: 80a68008                 cmp     %i2, %o0
F0084DB0: 1a800005                 bcc     loc_F0084DC4
F0084DB4: 9006200c                 add     %i0, 0xC, %o0
F0084DB8: 92100010                 mov     %l0, %o1
F0084DBC: 7ffffe8d                 call    __vm_map_clip_end
F0084DC0: 9410001a                 mov     %i2, %o2
F0084DC4: f6242024                 st      %i3, [%l0+0x24]
F0084DC8: e0042004                 ld      [%l0+4], %l0
F0084DCC: 80a40019                 cmp     %l0, %i1
F0084DD0: 32bffff3                 bne,a   loc_F0084D9C
F0084DD4: d0042008                 ld      [%l0+8], %o0
F0084DD8: 7fff9097                 call    _lock_done
F0084DDC: 90100018                 mov     %i0, %o0
F0084DE0: b0102000                 mov     0, %i0
F0084DE4: 81c7e008                 ret
F0084DE8: 81e80000                 restore
