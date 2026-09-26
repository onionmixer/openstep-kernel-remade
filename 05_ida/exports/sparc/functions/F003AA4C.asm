F003AA4C: 9de3bf48                 save    %sp, -0xB8, %sp
F003AA50: c026604c                 clr     [%i1+0x4C]
F003AA54: c0266048                 clr     [%i1+0x48]
F003AA58: 90100018                 mov     %i0, %o0
F003AA5C: 40000571                 call    sub_F003C020
F003AA60: 9210001a                 mov     %i2, %o1
F003AA64: a2920000                 orcc    %o0, %g0, %l1
F003AA68: 32800005                 bne,a   loc_F003AA7C
F003AA6C: d0046028                 ld      [%l1+0x28], %o0
F003AA70: 90102046                 mov     0x46, %o0 ! 'F'
F003AA74: 10800069                 ba      locret_F003AC18
F003AA78: d0264000                 st      %o0, [%i1]
F003AA7C: 80a22001                 cmp     %o0, 1
F003AA80: 02800006                 be      loc_F003AA98
F003AA84: 113c0432                 sethi   %hi(aRfsReadAttempt), %o0! "rfs_read: attempt to read from non-file"...
F003AA88: 7fff66f4                 call    _printf
F003AA8C: 90122208                 bset    %lo(aRfsReadAttempt), %o0! "rfs_read: attempt to read from non-file"...
F003AA90: 1080000b                 ba      loc_F003AABC
F003AA94: b4102015                 mov     0x15, %i2
F003AA98: 113c04cf                 sethi   %hi(_active_u), %o0
F003AA9C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003AAA0: d204601c                 ld      [%l1+0x1C], %o1
F003AAA4: d402201c                 ld      [%o0+0x1C], %o2
F003AAA8: d6026014                 ld      [%o1+0x14], %o3
F003AAAC: 90100011                 mov     %l1, %o0
F003AAB0: 9fc2c000                 call    %o3
F003AAB4: 9207bfb8                 add     %fp, var_48, %o1
F003AAB8: b4100008                 mov     %o0, %i2
F003AABC: 80a6a000                 cmp     %i2, 0
F003AAC0: 12800049                 bne     loc_F003ABE4
F003AAC4: 213c04cf                 sethi   %hi(_active_u), %l0
F003AAC8: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F003AACC: d802201c                 ld      [%o0+0x1C], %o4
F003AAD0: d2532002                 ldsh    [%o4+2], %o1
F003AAD4: d057bfbe                 ldsh    [%fp+var_42], %o0
F003AAD8: 80a24008                 cmp     %o1, %o0
F003AADC: 02800013                 be      loc_F003AB28
F003AAE0: 90100011                 mov     %l1, %o0
F003AAE4: d404601c                 ld      [%l1+0x1C], %o2
F003AAE8: d602a01c                 ld      [%o2+0x1C], %o3
F003AAEC: 92102100                 mov     0x100, %o1
F003AAF0: 9fc2c000                 call    %o3
F003AAF4: 9410000c                 mov     %o4, %o2
F003AAF8: b4920000                 orcc    %o0, %g0, %i2
F003AAFC: 02800009                 be      loc_F003AB20
F003AB00: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F003AB04: d204601c                 ld      [%l1+0x1C], %o1
F003AB08: d402201c                 ld      [%o0+0x1C], %o2
F003AB0C: d602601c                 ld      [%o1+0x1C], %o3
F003AB10: 90100011                 mov     %l1, %o0
F003AB14: 9fc2c000                 call    %o3
F003AB18: 92102040                 mov     0x40, %o1 ! '@'
F003AB1C: b4920000                 orcc    %o0, %g0, %i2
F003AB20: 12800031                 bne     loc_F003ABE4
F003AB24: 01000000                 nop
F003AB28: d2062020                 ld      [%i0+0x20], %o1
F003AB2C: d007bfd0                 ld      [%fp+var_30], %o0
F003AB30: 80a24008                 cmp     %o1, %o0
F003AB34: 0a800007                 bcs     loc_F003AB50
F003AB38: 9007bfb8                 add     %fp, var_48, %o0
F003AB3C: c0266048                 clr     [%i1+0x48]
F003AB40: 7ffffc22                 call    _vattr_to_nattr
F003AB44: 92066004                 add     %i1, 4, %o1
F003AB48: 10800032                 ba      loc_F003AC10
F003AB4C: f4264000                 st      %i2, [%i1]
F003AB50: 4000b548                 call    _kalloc
F003AB54: d0062024                 ld      [%i0+0x24], %o0
F003AB58: d026604c                 st      %o0, [%i1+0x4C]
F003AB5C: d6062024                 ld      [%i0+0x24], %o3
F003AB60: 90102000                 mov     0, %o0
F003AB64: d406604c                 ld      [%i1+0x4C], %o2
F003AB68: d6267ffc                 st      %o3, [%i1-4]
F003AB6C: d6062024                 ld      [%i0+0x24], %o3
F003AB70: 92100011                 mov     %l1, %o1
F003AB74: d8062020                 ld      [%i0+0x20], %o4
F003AB78: 9a102004                 mov     4, %o5
F003AB7C: da23a05c                 st      %o5, [%sp+0xB8+var_5C]
F003AB80: 9a07bfb4                 add     %fp, var_4C, %o5
F003AB84: da23a060                 st      %o5, [%sp+0xB8+var_58]
F003AB88: 7fffb7b3                 call    _vn_rdwr
F003AB8C: 9a102001                 mov     1, %o5
F003AB90: b4920000                 orcc    %o0, %g0, %i2
F003AB94: 12800014                 bne     loc_F003ABE4
F003AB98: 113c04cf                 sethi   %hi(_active_u), %o0
F003AB9C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003ABA0: d204601c                 ld      [%l1+0x1C], %o1
F003ABA4: d402201c                 ld      [%o0+0x1C], %o2
F003ABA8: a007bfb8                 add     %fp, var_48, %l0
F003ABAC: d6026014                 ld      [%o1+0x14], %o3
F003ABB0: 90100011                 mov     %l1, %o0
F003ABB4: 9fc2c000                 call    %o3
F003ABB8: 92100010                 mov     %l0, %o1
F003ABBC: b4920000                 orcc    %o0, %g0, %i2
F003ABC0: 12800009                 bne     loc_F003ABE4
F003ABC4: 90100010                 mov     %l0, %o0
F003ABC8: 7ffffc00                 call    _vattr_to_nattr
F003ABCC: 92066004                 add     %i1, 4, %o1
F003ABD0: d0062024                 ld      [%i0+0x24], %o0
F003ABD4: d207bfb4                 ld      [%fp+var_4C], %o1
F003ABD8: 90220009                 sub     %o0, %o1, %o0
F003ABDC: d0266048                 st      %o0, [%i1+0x48]
F003ABE0: 80a6a000                 cmp     %i2, 0
F003ABE4: 2280000b                 be,a    loc_F003AC10
F003ABE8: f4264000                 st      %i2, [%i1]
F003ABEC: d006604c                 ld      [%i1+0x4C], %o0
F003ABF0: 80a22000                 cmp     %o0, 0
F003ABF4: 22800007                 be,a    loc_F003AC10
F003ABF8: f4264000                 st      %i2, [%i1]
F003ABFC: 4000b569                 call    _kfree
F003AC00: d2067ffc                 ld      [%i1-4], %o1
F003AC04: c026604c                 clr     [%i1+0x4C]
F003AC08: c0266048                 clr     [%i1+0x48]
F003AC0C: f4264000                 st      %i2, [%i1]
F003AC10: 7fffb7d5                 call    _vn_rele
F003AC14: 90100011                 mov     %l1, %o0
F003AC18: 81c7e008                 ret
F003AC1C: 81e80000                 restore
