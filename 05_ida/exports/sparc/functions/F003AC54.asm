F003AC54: 9de3bf38                 save    %sp, -0xC8, %sp
F003AC58: 90100018                 mov     %i0, %o0
F003AC5C: 400004f1                 call    sub_F003C020
F003AC60: 9210001a                 mov     %i2, %o1
F003AC64: a0920000                 orcc    %o0, %g0, %l0
F003AC68: 32800005                 bne,a   loc_F003AC7C
F003AC6C: d0068000                 ld      [%i2], %o0
F003AC70: 90102046                 mov     0x46, %o0 ! 'F'
F003AC74: 108000af                 ba      locret_F003AF30
F003AC78: d0264000                 st      %o0, [%i1]
F003AC7C: 808a2001                 btst    1, %o0
F003AC80: 3280001e                 bne,a   loc_F003ACF8
F003AC84: b410201e                 mov     0x1E, %i2
F003AC88: 808a2002                 btst    2, %o0
F003AC8C: 0280000a                 be      loc_F003ACB4
F003AC90: 9206a018                 add     %i2, 0x18, %o1
F003AC94: d006e01c                 ld      [%i3+0x1C], %o0
F003AC98: 40000509                 call    sub_F003C0BC
F003AC9C: 90022010                 inc     0x10, %o0
F003ACA0: 80a22000                 cmp     %o0, 0
F003ACA4: 32800005                 bne,a   loc_F003ACB8
F003ACA8: d0042028                 ld      [%l0+0x28], %o0
F003ACAC: 10800013                 ba      loc_F003ACF8
F003ACB0: b410201e                 mov     0x1E, %i2
F003ACB4: d0042028                 ld      [%l0+0x28], %o0
F003ACB8: 80a22001                 cmp     %o0, 1
F003ACBC: 02800006                 be      loc_F003ACD4
F003ACC0: 113c0432                 sethi   %hi(aRfsWriteAttemp), %o0! "rfs_write: attempt to write to non-file"...
F003ACC4: 7fff6665                 call    _printf
F003ACC8: 90122238                 bset    %lo(aRfsWriteAttemp), %o0! "rfs_write: attempt to write to non-file"...
F003ACCC: 1080000b                 ba      loc_F003ACF8
F003ACD0: b4102015                 mov     0x15, %i2
F003ACD4: 113c04cf                 sethi   %hi(_active_u), %o0
F003ACD8: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003ACDC: d204201c                 ld      [%l0+0x1C], %o1
F003ACE0: d402201c                 ld      [%o0+0x1C], %o2
F003ACE4: d6026014                 ld      [%o1+0x14], %o3
F003ACE8: 90100010                 mov     %l0, %o0
F003ACEC: 9fc2c000                 call    %o3
F003ACF0: 9207bfb8                 add     %fp, var_48, %o1
F003ACF4: b4100008                 mov     %o0, %i2
F003ACF8: 80a6a000                 cmp     %i2, 0
F003ACFC: 1280007b                 bne     loc_F003AEE8
F003AD00: 233c04cf                 sethi   %hi(_active_u), %l1
F003AD04: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F003AD08: d802201c                 ld      [%o0+0x1C], %o4
F003AD0C: d2532002                 ldsh    [%o4+2], %o1
F003AD10: d057bfbe                 ldsh    [%fp+var_42], %o0
F003AD14: 80a24008                 cmp     %o1, %o0
F003AD18: 02800008                 be      loc_F003AD38
F003AD1C: 90100010                 mov     %l0, %o0
F003AD20: d404201c                 ld      [%l0+0x1C], %o2
F003AD24: d602a01c                 ld      [%o2+0x1C], %o3
F003AD28: 92102080                 mov     0x80, %o1
F003AD2C: 9fc2c000                 call    %o3
F003AD30: 9410000c                 mov     %o4, %o2
F003AD34: b4100008                 mov     %o0, %i2
F003AD38: 80a6a000                 cmp     %i2, 0
F003AD3C: 12800076                 bne     loc_F003AF14
F003AD40: 01000000                 nop
F003AD44: d0062030                 ld      [%i0+0x30], %o0
F003AD48: 80a22000                 cmp     %o0, 0
F003AD4C: 2280002a                 be,a    loc_F003ADF4
F003AD50: d0062034                 ld      [%i0+0x34], %o0
F003AD54: d027bfb0                 st      %o0, [%fp+var_50]
F003AD58: d006202c                 ld      [%i0+0x2C], %o0
F003AD5C: d027bfb4                 st      %o0, [%fp+var_4C]
F003AD60: 9007bfb0                 add     %fp, var_50, %o0
F003AD64: d027bf98                 st      %o0, [%fp+var_68]
F003AD68: 90102001                 mov     1, %o0
F003AD6C: d027bf9c                 st      %o0, [%fp+var_64]
F003AD70: d027bfa4                 st      %o0, [%fp+var_5C]
F003AD74: d0062024                 ld      [%i0+0x24], %o0
F003AD78: d027bfa0                 st      %o0, [%fp+var_60]
F003AD7C: d006202c                 ld      [%i0+0x2C], %o0
F003AD80: d027bfac                 st      %o0, [%fp+var_54]
F003AD84: d0042028                 ld      [%l0+0x28], %o0
F003AD88: 80a22001                 cmp     %o0, 1
F003AD8C: 12800010                 bne     loc_F003ADCC
F003AD90: d20461d8                 ld      [%l1+0x1D8], %o1
F003AD94: 4000c558                 call    _map_vnode
F003AD98: 90100010                 mov     %l0, %o0
F003AD9C: 90100010                 mov     %l0, %o0
F003ADA0: d60461d8                 ld      [%l1+0x1D8], %o3
F003ADA4: 9207bf98                 add     %fp, var_68, %o1
F003ADA8: d802e01c                 ld      [%o3+0x1C], %o4
F003ADAC: 94102001                 mov     1, %o2
F003ADB0: 4000c7d3                 call    _mfs_io
F003ADB4: 96102004                 mov     4, %o3
F003ADB8: b4100008                 mov     %o0, %i2
F003ADBC: 4000c59c                 call    _unmap_vnode
F003ADC0: 90100010                 mov     %l0, %o0
F003ADC4: 10800042                 ba      loc_F003AECC
F003ADC8: 113c04cf                 sethi   -0xFECC400, %o0
F003ADCC: d604201c                 ld      [%l0+0x1C], %o3
F003ADD0: 90100010                 mov     %l0, %o0
F003ADD4: d802601c                 ld      [%o1+0x1C], %o4
F003ADD8: 94102001                 mov     1, %o2
F003ADDC: da02e008                 ld      [%o3+8], %o5
F003ADE0: 9207bf98                 add     %fp, var_68, %o1
F003ADE4: 9fc34000                 call    %o5
F003ADE8: 96102004                 mov     4, %o3
F003ADEC: 10800037                 ba      loc_F003AEC8
F003ADF0: b4100008                 mov     %o0, %i2
F003ADF4: 80a22000                 cmp     %o0, 0
F003ADF8: 02800006                 be      loc_F003AE10
F003ADFC: b6102000                 mov     0, %i3
F003AE00: d0020000                 ld      [%o0], %o0
F003AE04: 80a22000                 cmp     %o0, 0
F003AE08: 12bffffe                 bne     loc_F003AE00
F003AE0C: b606e001                 inc     %i3
F003AE10: 4000b498                 call    _kalloc
F003AE14: 912ee003                 sll     %i3, 3, %o0
F003AE18: a2100008                 mov     %o0, %l1
F003AE1C: d0062034                 ld      [%i0+0x34], %o0
F003AE20: 40000046                 call    sub_F003AF38
F003AE24: 92100011                 mov     %l1, %o1
F003AE28: e227bf98                 st      %l1, [%fp+var_68]
F003AE2C: f627bf9c                 st      %i3, [%fp+var_64]
F003AE30: 90102001                 mov     1, %o0
F003AE34: d027bfa4                 st      %o0, [%fp+var_5C]
F003AE38: d0062024                 ld      [%i0+0x24], %o0
F003AE3C: d027bfa0                 st      %o0, [%fp+var_60]
F003AE40: d006202c                 ld      [%i0+0x2C], %o0
F003AE44: d027bfac                 st      %o0, [%fp+var_54]
F003AE48: d0042028                 ld      [%l0+0x28], %o0
F003AE4C: 80a22001                 cmp     %o0, 1
F003AE50: 32800011                 bne,a   loc_F003AE94
F003AE54: 113c04cf                 sethi   -0xFECC400, %o0
F003AE58: 4000c527                 call    _map_vnode
F003AE5C: 90100010                 mov     %l0, %o0
F003AE60: 90100010                 mov     %l0, %o0
F003AE64: 153c04cf                 sethi   %hi(_active_u), %o2
F003AE68: d602a1d8                 ld      [%o2+%lo(_active_u)], %o3
F003AE6C: 9207bf98                 add     %fp, var_68, %o1
F003AE70: d802e01c                 ld      [%o3+0x1C], %o4
F003AE74: 94102001                 mov     1, %o2
F003AE78: 4000c7a1                 call    _mfs_io
F003AE7C: 96102004                 mov     4, %o3
F003AE80: b4100008                 mov     %o0, %i2
F003AE84: 4000c56a                 call    _unmap_vnode
F003AE88: 90100010                 mov     %l0, %o0
F003AE8C: 1080000d                 ba      loc_F003AEC0
F003AE90: 90100011                 mov     %l1, %o0
F003AE94: d20221d8                 ld      [%o0+0x1D8], %o1
F003AE98: d604201c                 ld      [%l0+0x1C], %o3
F003AE9C: 94102001                 mov     1, %o2
F003AEA0: d802601c                 ld      [%o1+0x1C], %o4
F003AEA4: 90100010                 mov     %l0, %o0
F003AEA8: da02e008                 ld      [%o3+8], %o5
F003AEAC: 9207bf98                 add     %fp, var_68, %o1
F003AEB0: 9fc34000                 call    %o5
F003AEB4: 96102004                 mov     4, %o3
F003AEB8: b4100008                 mov     %o0, %i2
F003AEBC: 90100011                 mov     %l1, %o0
F003AEC0: 4000b4b8                 call    _kfree
F003AEC4: 932ee003                 sll     %i3, 3, %o1
F003AEC8: 113c04cf                 sethi   -0xFECC400, %o0
F003AECC: d00221d8                 ld      [%o0+0x1D8], %o0
F003AED0: d202201c                 ld      [%o0+0x1C], %o1
F003AED4: d004201c                 ld      [%l0+0x1C], %o0
F003AED8: d4022048                 ld      [%o0+0x48], %o2
F003AEDC: 9fc28000                 call    %o2
F003AEE0: 90100010                 mov     %l0, %o0
F003AEE4: 80a6a000                 cmp     %i2, 0
F003AEE8: 1280000b                 bne     loc_F003AF14
F003AEEC: 80a6a000                 cmp     %i2, 0
F003AEF0: 113c04cf                 sethi   %hi(_active_u), %o0
F003AEF4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003AEF8: d204201c                 ld      [%l0+0x1C], %o1
F003AEFC: d402201c                 ld      [%o0+0x1C], %o2
F003AF00: d6026014                 ld      [%o1+0x14], %o3
F003AF04: 90100010                 mov     %l0, %o0
F003AF08: 9fc2c000                 call    %o3
F003AF0C: 9207bfb8                 add     %fp, var_48, %o1
F003AF10: b4920000                 orcc    %o0, %g0, %i2
F003AF14: 12800005                 bne     loc_F003AF28
F003AF18: f4264000                 st      %i2, [%i1]
F003AF1C: 9007bfb8                 add     %fp, var_48, %o0
F003AF20: 7ffffb2a                 call    _vattr_to_nattr
F003AF24: 92066004                 add     %i1, 4, %o1
F003AF28: 7fffb70f                 call    _vn_rele
F003AF2C: 90100010                 mov     %l0, %o0
F003AF30: 81c7e008                 ret
F003AF34: 81e80000                 restore
