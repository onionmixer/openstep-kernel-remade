F009CBE8: 9de3bf98                 save    %sp, -0x68, %sp
F009CBEC: 9210001a                 mov     %i2, %o1
F009CBF0: d227a04c                 st      %o1, [%fp+arg_4C]
F009CBF4: 90100018                 mov     %i0, %o0
F009CBF8: f2064000                 ld      [%i1], %i1
F009CBFC: 40001757                 call    _pmap_alloc_seg_entry
F009CC00: 94102003                 mov     3, %o2
F009CC04: 7fffe83e                 call    _splvm
F009CC08: b0100008                 mov     %o0, %i0
F009CC0C: b4100008                 mov     %o0, %i2
F009CC10: f2262020                 st      %i1, [%i0+0x20]
F009CC14: d8060000                 ld      [%i0], %o4
F009CC18: 96102000                 mov     0, %o3
F009CC1C: d017a04c                 lduh    [%fp+arg_4C], %o0
F009CC20: 94102000                 mov     0, %o2
F009CC24: d2064000                 ld      [%i1], %o1
F009CC28: 900a20fc                 and     %o0, 0xFC, %o0
F009CC2C: d2024008                 ld      [%o1+%o0], %o1
F009CC30: d222800c                 st      %o1, [%o2+%o4]
F009CC34: 900a7f00                 and     %o1, -0x100, %o0
F009CC38: 920a60ff                 and     %o1, 0xFF, %o1
F009CC3C: 90022100                 inc     0x100, %o0
F009CC40: 92124008                 bset    %o0, %o1
F009CC44: 9602e001                 inc     %o3
F009CC48: 80a2e03f                 cmp     %o3, 0x3F ! '?'
F009CC4C: 04bffff9                 ble     loc_F009CC30
F009CC50: 9402a004                 inc     4, %o2
F009CC54: 113c04f7                 sethi   %hi(_pmap_info), %o0! int
F009CC58: d2122270                 lduh    [%o0+%lo(_pmap_info)], %o1! int
F009CC5C: 7ffda66b                 call    _div
F009CC60: 90102040                 mov     0x40, %o0 ! '@'
F009CC64: d02e200f                 stb     %o0, [%i0+0xF]
F009CC68: 113c04f8                 sethi   %hi(_wmap0), %o0
F009CC6C: d2022030                 ld      [%o0+%lo(_wmap0)], %o1
F009CC70: 113c04f8                 sethi   %hi(_wmap1), %o0
F009CC74: d0022038                 ld      [%o0+%lo(_wmap1)], %o0
F009CC78: d2262010                 st      %o1, [%i0+0x10]
F009CC7C: d0262014                 st      %o0, [%i0+0x14]
F009CC80: d00e600d                 ldub    [%i1+0xD], %o0
F009CC84: 80a22003                 cmp     %o0, 3
F009CC88: 1280000a                 bne     loc_F009CCB0
F009CC8C: 80a22002                 cmp     %o0, 2
F009CC90: d407a04c                 ld      [%fp+arg_4C], %o2
F009CC94: 90102001                 mov     1, %o0
F009CC98: 9532a00c                 srl     %o2, 12, %o2
F009CC9C: 9332a003                 srl     %o2, 3, %o1
F009CCA0: 920a6004                 and     %o1, 4, %o1
F009CCA4: 92024019                 add     %o1, %i1, %o1
F009CCA8: 1080000b                 ba      loc_F009CCD4
F009CCAC: 940aa01e                 and     %o2, 0x1E, %o2
F009CCB0: 12800010                 bne     loc_F009CCF0
F009CCB4: d40fa04c                 ldub    [%fp+arg_4C], %o2
F009CCB8: d407a04c                 ld      [%fp+arg_4C], %o2
F009CCBC: 90102001                 mov     1, %o0
F009CCC0: 9532a012                 srl     %o2, 18, %o2
F009CCC4: 9332a003                 srl     %o2, 3, %o1
F009CCC8: 920a6004                 and     %o1, 4, %o1
F009CCCC: 92024019                 add     %o1, %i1, %o1
F009CCD0: 940aa01f                 and     %o2, 0x1F, %o2
F009CCD4: d2026018                 ld      [%o1+0x18], %o1
F009CCD8: 912a000a                 sll     %o0, %o2, %o0
F009CCDC: 808a4008                 btst    %o0, %o1
F009CCE0: 1280000e                 bne     loc_F009CD18
F009CCE4: 113c04f7                 sethi   -0xFEC2400, %o0
F009CCE8: 10800035                 ba      loc_F009CDBC
F009CCEC: d207a04c                 ld      [%fp+arg_4C], %o1
F009CCF0: 90102001                 mov     1, %o0
F009CCF4: 9332a005                 srl     %o2, 5, %o1
F009CCF8: 932a6002                 sll     %o1, 2, %o1
F009CCFC: 92024019                 add     %o1, %i1, %o1
F009CD00: 940aa01f                 and     %o2, 0x1F, %o2
F009CD04: d2026030                 ld      [%o1+0x30], %o1
F009CD08: 912a000a                 sll     %o0, %o2, %o0
F009CD0C: 808a4008                 btst    %o0, %o1
F009CD10: 0280002a                 be      loc_F009CDB8
F009CD14: 113c04f7                 sethi   -0xFEC2400, %o0
F009CD18: d2022250                 ld      [%o0+0x250], %o1
F009CD1C: 113c04f7                 sethi   %hi(_mmap1), %o0
F009CD20: d0022258                 ld      [%o0+%lo(_mmap1)], %o0
F009CD24: d2262018                 st      %o1, [%i0+0x18]
F009CD28: d026201c                 st      %o0, [%i0+0x1C]
F009CD2C: d00e600d                 ldub    [%i1+0xD], %o0
F009CD30: 80a22003                 cmp     %o0, 3
F009CD34: 1280000a                 bne     loc_F009CD5C
F009CD38: 80a22002                 cmp     %o0, 2
F009CD3C: d207a04c                 ld      [%fp+arg_4C], %o1
F009CD40: 90102001                 mov     1, %o0
F009CD44: 9332600c                 srl     %o1, 12, %o1
F009CD48: 95326003                 srl     %o1, 3, %o2
F009CD4C: 940aa004                 and     %o2, 4, %o2
F009CD50: 94028019                 add     %o2, %i1, %o2
F009CD54: 1080000b                 ba      loc_F009CD80
F009CD58: 920a601e                 and     %o1, 0x1E, %o1
F009CD5C: 3280000e                 bne,a   loc_F009CD94
F009CD60: d40fa04c                 ldub    [%fp+arg_4C], %o2
F009CD64: d207a04c                 ld      [%fp+arg_4C], %o1
F009CD68: 90102001                 mov     1, %o0
F009CD6C: 93326012                 srl     %o1, 18, %o1
F009CD70: 95326003                 srl     %o1, 3, %o2
F009CD74: 940aa004                 and     %o2, 4, %o2
F009CD78: 94028019                 add     %o2, %i1, %o2
F009CD7C: 920a601f                 and     %o1, 0x1F, %o1
F009CD80: d602a018                 ld      [%o2+0x18], %o3
F009CD84: 912a0009                 sll     %o0, %o1, %o0
F009CD88: 902ac008                 andn    %o3, %o0, %o0
F009CD8C: 1080000b                 ba      loc_F009CDB8
F009CD90: d022a018                 st      %o0, [%o2+0x18]
F009CD94: 90102001                 mov     1, %o0
F009CD98: 9332a005                 srl     %o2, 5, %o1
F009CD9C: 932a6002                 sll     %o1, 2, %o1
F009CDA0: 92024019                 add     %o1, %i1, %o1
F009CDA4: 940aa01f                 and     %o2, 0x1F, %o2
F009CDA8: d6026030                 ld      [%o1+0x30], %o3
F009CDAC: 912a000a                 sll     %o0, %o2, %o0
F009CDB0: 902ac008                 andn    %o3, %o0, %o0
F009CDB4: d0226030                 st      %o0, [%o1+0x30]
F009CDB8: d207a04c                 ld      [%fp+arg_4C], %o1
F009CDBC: d6062004                 ld      [%i0+4], %o3
F009CDC0: d40e200e                 ldub    [%i0+0xE], %o2
F009CDC4: 90100019                 mov     %i1, %o0
F009CDC8: d602e004                 ld      [%o3+4], %o3
F009CDCC: 952aa008                 sll     %o2, 8, %o2
F009CDD0: 4000134d                 call    _set_ptp
F009CDD4: 9402c00a                 add     %o3, %o2, %o2
F009CDD8: d20e600f                 ldub    [%i1+0xF], %o1
F009CDDC: 9010001a                 mov     %i2, %o0
F009CDE0: 92027fff                 inc     -1, %o1
F009CDE4: 7fffe7d0                 call    _splx
F009CDE8: d22e600f                 stb     %o1, [%i1+0xF]
F009CDEC: 81c7e008                 ret
F009CDF0: 81e80000                 restore
