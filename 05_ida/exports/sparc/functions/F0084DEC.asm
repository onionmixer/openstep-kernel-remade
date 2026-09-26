F0084DEC: 9de3bf90                 save    %sp, -0x70, %sp
F0084DF0: a2102001                 mov     1, %l1
F0084DF4: 7fff8ff4                 call    _lock_write
F0084DF8: 90100018                 mov     %i0, %o0
F0084DFC: d006204c                 ld      [%i0+0x4C], %o0
F0084E00: 90022001                 inc     %o0
F0084E04: d026204c                 st      %o0, [%i0+0x4C]
F0084E08: d0062014                 ld      [%i0+0x14], %o0
F0084E0C: 80a64008                 cmp     %i1, %o0
F0084E10: 2a800002                 bcs,a   loc_F0084E18
F0084E14: b2100008                 mov     %o0, %i1
F0084E18: d0062018                 ld      [%i0+0x18], %o0
F0084E1C: 80a68008                 cmp     %i2, %o0
F0084E20: 38800002                 bgu,a   loc_F0084E28
F0084E24: b4100008                 mov     %o0, %i2
F0084E28: 80a6401a                 cmp     %i1, %i2
F0084E2C: 38800002                 bgu,a   loc_F0084E34
F0084E30: b210001a                 mov     %i2, %i1
F0084E34: 90100018                 mov     %i0, %o0
F0084E38: 92100019                 mov     %i1, %o1
F0084E3C: 7ffffd9b                 call    _vm_map_lookup_entry
F0084E40: 9407bff4                 add     %fp, var_C, %o2
F0084E44: 80a22000                 cmp     %o0, 0
F0084E48: 0280000b                 be      loc_F0084E74
F0084E4C: e007bff4                 ld      [%fp+var_C], %l0
F0084E50: d0042008                 ld      [%l0+8], %o0
F0084E54: 80a64008                 cmp     %i1, %o0
F0084E58: 08800009                 bleu    loc_F0084E7C
F0084E5C: 9006200c                 add     %i0, 0xC, %o0
F0084E60: 92100010                 mov     %l0, %o1
F0084E64: 7ffffe2b                 call    __vm_map_clip_start
F0084E68: 94100019                 mov     %i1, %o2
F0084E6C: 10800005                 ba      loc_F0084E80
F0084E70: 80a6e000                 cmp     %i3, 0
F0084E74: d007bff4                 ld      [%fp+var_C], %o0
F0084E78: e0022004                 ld      [%o0+4], %l0
F0084E7C: 80a6e000                 cmp     %i3, 0
F0084E80: 02800034                 be      loc_F0084F50
F0084E84: e027bff4                 st      %l0, [%fp+var_C]
F0084E88: 9006200c                 add     %i0, 0xC, %o0
F0084E8C: 80a40008                 cmp     %l0, %o0
F0084E90: 22800011                 be,a    loc_F0084ED4
F0084E94: e007bff4                 ld      [%fp+var_C], %l0
F0084E98: 92100008                 mov     %o0, %o1
F0084E9C: d0042008                 ld      [%l0+8], %o0
F0084EA0: 80a2001a                 cmp     %o0, %i2
F0084EA4: 3a80000b                 bcc,a   loc_F0084ED0
F0084EA8: e007bff4                 ld      [%fp+var_C], %l0
F0084EAC: d0142028                 lduh    [%l0+0x28], %o0
F0084EB0: 80a22000                 cmp     %o0, 0
F0084EB4: 0280006d                 be      loc_F0085068
F0084EB8: 01000000                 nop
F0084EBC: e0042004                 ld      [%l0+4], %l0
F0084EC0: 80a40009                 cmp     %l0, %o1
F0084EC4: 32bffff7                 bne,a   loc_F0084EA0
F0084EC8: d0042008                 ld      [%l0+8], %o0
F0084ECC: e007bff4                 ld      [%fp+var_C], %l0
F0084ED0: 9006200c                 add     %i0, 0xC, %o0
F0084ED4: 80a40008                 cmp     %l0, %o0
F0084ED8: 02800087                 be      loc_F00850F4
F0084EDC: 80a46000                 cmp     %l1, 0
F0084EE0: b2100008                 mov     %o0, %i1
F0084EE4: d0042008                 ld      [%l0+8], %o0
F0084EE8: 80a2001a                 cmp     %o0, %i2
F0084EEC: 1a800082                 bcc     loc_F00850F4
F0084EF0: 80a46000                 cmp     %l1, 0
F0084EF4: d004200c                 ld      [%l0+0xC], %o0
F0084EF8: 80a68008                 cmp     %i2, %o0
F0084EFC: 1a800005                 bcc     loc_F0084F10
F0084F00: 9006200c                 add     %i0, 0xC, %o0
F0084F04: 92100010                 mov     %l0, %o1
F0084F08: 7ffffe3a                 call    __vm_map_clip_end
F0084F0C: 9410001a                 mov     %i2, %o2
F0084F10: d0142028                 lduh    [%l0+0x28], %o0
F0084F14: 90023fff                 inc     -1, %o0
F0084F18: d0342028                 sth     %o0, [%l0+0x28]
F0084F1C: 912a2010                 sll     %o0, 16, %o0
F0084F20: 80a22000                 cmp     %o0, 0
F0084F24: 32800006                 bne,a   loc_F0084F3C
F0084F28: e0042004                 ld      [%l0+4], %l0
F0084F2C: 90100018                 mov     %i0, %o0
F0084F30: 7ffff805                 call    _vm_fault_unwire
F0084F34: 92100010                 mov     %l0, %o1
F0084F38: e0042004                 ld      [%l0+4], %l0
F0084F3C: 80a40019                 cmp     %l0, %i1
F0084F40: 0280006d                 be      loc_F00850F4
F0084F44: 80a46000                 cmp     %l1, 0
F0084F48: 10bfffe8                 ba      loc_F0084EE8
F0084F4C: d0042008                 ld      [%l0+8], %o0
F0084F50: e007bff4                 ld      [%fp+var_C], %l0
F0084F54: 9006200c                 add     %i0, 0xC, %o0
F0084F58: 80a40008                 cmp     %l0, %o0
F0084F5C: 02800039                 be      loc_F0085040
F0084F60: 113f7fff                 sethi   -0x2000400, %o0
F0084F64: b21223ff                 or      %o0, 0x3FF, %i1
F0084F68: d0042008                 ld      [%l0+8], %o0
F0084F6C: 80a2001a                 cmp     %o0, %i2
F0084F70: 1a800035                 bcc     loc_F0085044
F0084F74: 113c04d1                 sethi   -0xFECBC00, %o0
F0084F78: d004200c                 ld      [%l0+0xC], %o0
F0084F7C: 80a68008                 cmp     %i2, %o0
F0084F80: 1a800005                 bcc     loc_F0084F94
F0084F84: 9006200c                 add     %i0, 0xC, %o0
F0084F88: 92100010                 mov     %l0, %o1
F0084F8C: 7ffffe19                 call    __vm_map_clip_end
F0084F90: 9410001a                 mov     %i2, %o2
F0084F94: d0142028                 lduh    [%l0+0x28], %o0
F0084F98: 90022001                 inc     %o0
F0084F9C: d0342028                 sth     %o0, [%l0+0x28]
F0084FA0: 912a2010                 sll     %o0, 16, %o0
F0084FA4: 91322010                 srl     %o0, 16, %o0
F0084FA8: 80a22001                 cmp     %o0, 1
F0084FAC: 32800021                 bne,a   loc_F0085030
F0084FB0: e0042004                 ld      [%l0+4], %l0
F0084FB4: d2042018                 ld      [%l0+0x18], %o1
F0084FB8: 80a26000                 cmp     %o1, 0
F0084FBC: 0680001c                 bl      loc_F008502C
F0084FC0: 11008000                 sethi   0x2000000, %o0
F0084FC4: 808a4008                 btst    %o0, %o1
F0084FC8: 22800010                 be,a    loc_F0085008
F0084FCC: d0042010                 ld      [%l0+0x10], %o0
F0084FD0: d004201c                 ld      [%l0+0x1C], %o0
F0084FD4: 808a2002                 btst    2, %o0
F0084FD8: 0280000b                 be      loc_F0085004
F0084FDC: 90042010                 add     %l0, 0x10, %o0
F0084FE0: d604200c                 ld      [%l0+0xC], %o3
F0084FE4: d4042008                 ld      [%l0+8], %o2
F0084FE8: 92042014                 add     %l0, 0x14, %o1
F0084FEC: 400008ba                 call    _vm_object_shadow
F0084FF0: 9422c00a                 sub     %o3, %o2, %o2
F0084FF4: d0042018                 ld      [%l0+0x18], %o0
F0084FF8: 900a0019                 and     %o0, %i1, %o0
F0084FFC: 1080000c                 ba      loc_F008502C
F0085000: d0242018                 st      %o0, [%l0+0x18]
F0085004: d0042010                 ld      [%l0+0x10], %o0
F0085008: 80a22000                 cmp     %o0, 0
F008500C: 32800009                 bne,a   loc_F0085030
F0085010: e0042004                 ld      [%l0+4], %l0
F0085014: d204200c                 ld      [%l0+0xC], %o1
F0085018: d0042008                 ld      [%l0+8], %o0
F008501C: 400005e1                 call    _vm_object_allocate
F0085020: 90224008                 sub     %o1, %o0, %o0
F0085024: d0242010                 st      %o0, [%l0+0x10]
F0085028: c0242014                 clr     [%l0+0x14]
F008502C: e0042004                 ld      [%l0+4], %l0
F0085030: 9006200c                 add     %i0, 0xC, %o0
F0085034: 80a40008                 cmp     %l0, %o0
F0085038: 32bfffcd                 bne,a   loc_F0084F6C
F008503C: d0042008                 ld      [%l0+8], %o0
F0085040: 113c04d1                 sethi   -0xFECBC00, %o0
F0085044: d0022340                 ld      [%o0+0x340], %o0
F0085048: 80a60008                 cmp     %i0, %o0
F008504C: 1280000b                 bne     loc_F0085078
F0085050: 01000000                 nop
F0085054: a2102000                 mov     0, %l1
F0085058: 7fff8ff7                 call    _lock_done
F008505C: 90100018                 mov     %i0, %o0
F0085060: 1080000b                 ba      loc_F008508C
F0085064: e007bff4                 ld      [%fp+var_C], %l0
F0085068: 7fff8ff3                 call    _lock_done
F008506C: 90100018                 mov     %i0, %o0
F0085070: 10800026                 ba      locret_F0085108
F0085074: b0102004                 mov     4, %i0
F0085078: 7fff919e                 call    _lock_set_recursive
F008507C: 90100018                 mov     %i0, %o0
F0085080: 7fff90e5                 call    _lock_write_to_read
F0085084: 90100018                 mov     %i0, %o0
F0085088: e007bff4                 ld      [%fp+var_C], %l0
F008508C: 9006200c                 add     %i0, 0xC, %o0
F0085090: 80a40008                 cmp     %l0, %o0
F0085094: 02800013                 be      loc_F00850E0
F0085098: 80a46000                 cmp     %l1, 0
F008509C: b2100008                 mov     %o0, %i1
F00850A0: d0042008                 ld      [%l0+8], %o0
F00850A4: 80a2001a                 cmp     %o0, %i2
F00850A8: 1a80000e                 bcc     loc_F00850E0
F00850AC: 80a46000                 cmp     %l1, 0
F00850B0: d0142028                 lduh    [%l0+0x28], %o0
F00850B4: 80a22001                 cmp     %o0, 1
F00850B8: 32800006                 bne,a   loc_F00850D0
F00850BC: e0042004                 ld      [%l0+4], %l0
F00850C0: 90100018                 mov     %i0, %o0
F00850C4: 7ffff781                 call    _vm_fault_wire
F00850C8: 92100010                 mov     %l0, %o1
F00850CC: e0042004                 ld      [%l0+4], %l0
F00850D0: 80a40019                 cmp     %l0, %i1
F00850D4: 32bffff4                 bne,a   loc_F00850A4
F00850D8: d0042008                 ld      [%l0+8], %o0
F00850DC: 80a46000                 cmp     %l1, 0
F00850E0: 02800005                 be      loc_F00850F4
F00850E4: 80a46000                 cmp     %l1, 0
F00850E8: 7fff919a                 call    _lock_clear_recursive
F00850EC: 90100018                 mov     %i0, %o0
F00850F0: 80a46000                 cmp     %l1, 0
F00850F4: 22800005                 be,a    locret_F0085108
F00850F8: b0102000                 mov     0, %i0
F00850FC: 7fff8fce                 call    _lock_done
F0085100: 90100018                 mov     %i0, %o0
F0085104: b0102000                 mov     0, %i0
F0085108: 81c7e008                 ret
F008510C: 81e80000                 restore
