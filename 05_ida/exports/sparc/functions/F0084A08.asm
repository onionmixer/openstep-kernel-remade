F0084A08: 9de3bf90                 save    %sp, -0x70, %sp
F0084A0C: 7fff90ee                 call    _lock_write
F0084A10: 90100018                 mov     %i0, %o0
F0084A14: d006204c                 ld      [%i0+0x4C], %o0
F0084A18: 90022001                 inc     %o0
F0084A1C: d026204c                 st      %o0, [%i0+0x4C]
F0084A20: d0062014                 ld      [%i0+0x14], %o0
F0084A24: 80a64008                 cmp     %i1, %o0
F0084A28: 2a800002                 bcs,a   loc_F0084A30
F0084A2C: b2100008                 mov     %o0, %i1
F0084A30: d0062018                 ld      [%i0+0x18], %o0
F0084A34: 80a68008                 cmp     %i2, %o0
F0084A38: 38800002                 bgu,a   loc_F0084A40
F0084A3C: b4100008                 mov     %o0, %i2
F0084A40: 80a6401a                 cmp     %i1, %i2
F0084A44: 38800002                 bgu,a   loc_F0084A4C
F0084A48: b210001a                 mov     %i2, %i1
F0084A4C: 90100018                 mov     %i0, %o0
F0084A50: 92100019                 mov     %i1, %o1
F0084A54: 7ffffe95                 call    _vm_map_lookup_entry
F0084A58: 9407bff4                 add     %fp, var_C, %o2
F0084A5C: 80a22000                 cmp     %o0, 0
F0084A60: 02800012                 be      loc_F0084AA8
F0084A64: d207bff4                 ld      [%fp+var_C], %o1
F0084A68: d0026008                 ld      [%o1+8], %o0
F0084A6C: 80a64008                 cmp     %i1, %o0
F0084A70: 08800011                 bleu    loc_F0084AB4
F0084A74: 9006200c                 add     %i0, 0xC, %o0
F0084A78: 7fffff26                 call    __vm_map_clip_start
F0084A7C: 94100019                 mov     %i1, %o2
F0084A80: 1080000e                 ba      loc_F0084AB8
F0084A84: f207bff4                 ld      [%fp+var_C], %i1
F0084A88: 7fff916b                 call    _lock_done
F0084A8C: 90100018                 mov     %i0, %o0
F0084A90: 10800090                 ba      locret_F0084CD0
F0084A94: b0102004                 mov     4, %i0
F0084A98: 7fff9167                 call    _lock_done
F0084A9C: 90100018                 mov     %i0, %o0
F0084AA0: 1080008c                 ba      locret_F0084CD0
F0084AA4: b0102002                 mov     2, %i0
F0084AA8: d007bff4                 ld      [%fp+var_C], %o0
F0084AAC: d0022004                 ld      [%o0+4], %o0
F0084AB0: d027bff4                 st      %o0, [%fp+var_C]
F0084AB4: f207bff4                 ld      [%fp+var_C], %i1
F0084AB8: 9006200c                 add     %i0, 0xC, %o0
F0084ABC: 80a64008                 cmp     %i1, %o0
F0084AC0: 22800017                 be,a    loc_F0084B1C
F0084AC4: f207bff4                 ld      [%fp+var_C], %i1
F0084AC8: 15080000                 sethi   0x20000000, %o2
F0084ACC: 92100008                 mov     %o0, %o1
F0084AD0: d0066008                 ld      [%i1+8], %o0
F0084AD4: 80a2001a                 cmp     %o0, %i2
F0084AD8: 3a800010                 bcc,a   loc_F0084B18
F0084ADC: f207bff4                 ld      [%fp+var_C], %i1
F0084AE0: d0066018                 ld      [%i1+0x18], %o0
F0084AE4: 808a000a                 btst    %o2, %o0
F0084AE8: 12bfffe8                 bne     loc_F0084A88
F0084AEC: 01000000                 nop
F0084AF0: d0066020                 ld      [%i1+0x20], %o0
F0084AF4: 900ec008                 and     %i3, %o0, %o0
F0084AF8: 80a2001b                 cmp     %o0, %i3
F0084AFC: 12bfffe7                 bne     loc_F0084A98
F0084B00: 01000000                 nop
F0084B04: f2066004                 ld      [%i1+4], %i1
F0084B08: 80a64009                 cmp     %i1, %o1
F0084B0C: 32bffff2                 bne,a   loc_F0084AD4
F0084B10: d0066008                 ld      [%i1+8], %o0
F0084B14: f207bff4                 ld      [%fp+var_C], %i1
F0084B18: 9006200c                 add     %i0, 0xC, %o0
F0084B1C: 80a64008                 cmp     %i1, %o0
F0084B20: 02800069                 be      loc_F0084CC4
F0084B24: 01000000                 nop
F0084B28: 23040000                 sethi   0x10000000, %l1
F0084B2C: d0066008                 ld      [%i1+8], %o0
F0084B30: 80a2001a                 cmp     %o0, %i2
F0084B34: 1a800064                 bcc     loc_F0084CC4
F0084B38: 01000000                 nop
F0084B3C: d006600c                 ld      [%i1+0xC], %o0
F0084B40: 80a68008                 cmp     %i2, %o0
F0084B44: 1a800005                 bcc     loc_F0084B58
F0084B48: 9006200c                 add     %i0, 0xC, %o0
F0084B4C: 92100019                 mov     %i1, %o1
F0084B50: 7fffff28                 call    __vm_map_clip_end
F0084B54: 9410001a                 mov     %i2, %o2
F0084B58: 80a72000                 cmp     %i4, 0
F0084B5C: 02800006                 be      loc_F0084B74
F0084B60: d206601c                 ld      [%i1+0x1C], %o1
F0084B64: f6266020                 st      %i3, [%i1+0x20]
F0084B68: 900ec009                 and     %i3, %o1, %o0
F0084B6C: 10800003                 ba      loc_F0084B78
F0084B70: d026601c                 st      %o0, [%i1+0x1C]
F0084B74: f626601c                 st      %i3, [%i1+0x1C]
F0084B78: d606601c                 ld      [%i1+0x1C], %o3
F0084B7C: 80a2c009                 cmp     %o3, %o1
F0084B80: 2280004d                 be,a    loc_F0084CB4
F0084B84: f2066004                 ld      [%i1+4], %i1
F0084B88: d0066018                 ld      [%i1+0x18], %o0
F0084B8C: 80a22000                 cmp     %o0, 0
F0084B90: 3680003d                 bge,a   loc_F0084C84
F0084B94: d8062024                 ld      [%i0+0x24], %o4
F0084B98: 7fff908b                 call    _lock_write
F0084B9C: d0066010                 ld      [%i1+0x10], %o0
F0084BA0: d2066010                 ld      [%i1+0x10], %o1
F0084BA4: d002604c                 ld      [%o1+0x4C], %o0
F0084BA8: 90022001                 inc     %o0
F0084BAC: d022604c                 st      %o0, [%o1+0x4C]
F0084BB0: d0066010                 ld      [%i1+0x10], %o0
F0084BB4: d2066014                 ld      [%i1+0x14], %o1
F0084BB8: 7ffffe3c                 call    _vm_map_lookup_entry
F0084BBC: 9407bff0                 add     %fp, var_10, %o2
F0084BC0: d206600c                 ld      [%i1+0xC], %o1
F0084BC4: d0066010                 ld      [%i1+0x10], %o0
F0084BC8: d407bff0                 ld      [%fp+var_10], %o2
F0084BCC: d6066008                 ld      [%i1+8], %o3
F0084BD0: 9002200c                 inc     0xC, %o0
F0084BD4: 80a28008                 cmp     %o2, %o0
F0084BD8: d0066014                 ld      [%i1+0x14], %o0
F0084BDC: 9222400b                 sub     %o1, %o3, %o1
F0084BE0: 02800025                 be      loc_F0084C74
F0084BE4: a0020009                 add     %o0, %o1, %l0
F0084BE8: da07bff0                 ld      [%fp+var_10], %o5
F0084BEC: d0036008                 ld      [%o5+8], %o0
F0084BF0: 80a20010                 cmp     %o0, %l0
F0084BF4: 1a800020                 bcc     loc_F0084C74
F0084BF8: 01000000                 nop
F0084BFC: d8066014                 ld      [%i1+0x14], %o4
F0084C00: 80a2000c                 cmp     %o0, %o4
F0084C04: 1a800003                 bcc     loc_F0084C10
F0084C08: c4062024                 ld      [%i0+0x24], %g2
F0084C0C: 9010000c                 mov     %o4, %o0
F0084C10: d603600c                 ld      [%o5+0xC], %o3
F0084C14: 9022000c                 sub     %o0, %o4, %o0
F0084C18: d4066008                 ld      [%i1+8], %o2
F0084C1C: 80a2c010                 cmp     %o3, %l0
F0084C20: 1a800003                 bcc     loc_F0084C2C
F0084C24: 9202000a                 add     %o0, %o2, %o1
F0084C28: 96100010                 mov     %l0, %o3
F0084C2C: d0036018                 ld      [%o5+0x18], %o0
F0084C30: 808a0011                 btst    %l1, %o0
F0084C34: 9022c00c                 sub     %o3, %o4, %o0
F0084C38: d606601c                 ld      [%i1+0x1C], %o3
F0084C3C: 02800004                 be      loc_F0084C4C
F0084C40: 9402000a                 add     %o0, %o2, %o2
F0084C44: 10800003                 ba      loc_F0084C50
F0084C48: 960afffd                 and     %o3, -3, %o3
F0084C4C: 960ae007                 and     %o3, 7, %o3
F0084C50: 4000675d                 call    _pmap_protect
F0084C54: 90100002                 mov     %g2, %o0
F0084C58: d007bff0                 ld      [%fp+var_10], %o0
F0084C5C: d2022004                 ld      [%o0+4], %o1
F0084C60: d0066010                 ld      [%i1+0x10], %o0
F0084C64: 9002200c                 inc     0xC, %o0
F0084C68: 80a24008                 cmp     %o1, %o0
F0084C6C: 12bfffdf                 bne     loc_F0084BE8
F0084C70: d227bff0                 st      %o1, [%fp+var_10]
F0084C74: 7fff90f0                 call    _lock_done
F0084C78: d0066010                 ld      [%i1+0x10], %o0
F0084C7C: 1080000e                 ba      loc_F0084CB4
F0084C80: f2066004                 ld      [%i1+4], %i1
F0084C84: d007bff4                 ld      [%fp+var_C], %o0
F0084C88: d2066008                 ld      [%i1+8], %o1
F0084C8C: d0022018                 ld      [%o0+0x18], %o0
F0084C90: 808a0011                 btst    %l1, %o0
F0084C94: 02800004                 be      loc_F0084CA4
F0084C98: d406600c                 ld      [%i1+0xC], %o2
F0084C9C: 10800003                 ba      loc_F0084CA8
F0084CA0: 960afffd                 and     %o3, -3, %o3
F0084CA4: 960ae007                 and     %o3, 7, %o3
F0084CA8: 40006747                 call    _pmap_protect
F0084CAC: 9010000c                 mov     %o4, %o0
F0084CB0: f2066004                 ld      [%i1+4], %i1
F0084CB4: 9006200c                 add     %i0, 0xC, %o0
F0084CB8: 80a64008                 cmp     %i1, %o0
F0084CBC: 32bfff9d                 bne,a   loc_F0084B30
F0084CC0: d0066008                 ld      [%i1+8], %o0
F0084CC4: 7fff90dc                 call    _lock_done
F0084CC8: 90100018                 mov     %i0, %o0
F0084CCC: b0102000                 mov     0, %i0
F0084CD0: 81c7e008                 ret
F0084CD4: 81e80000                 restore
