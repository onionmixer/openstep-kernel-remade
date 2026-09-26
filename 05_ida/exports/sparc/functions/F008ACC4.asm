F008ACC4: 9de3bf98                 save    %sp, -0x68, %sp
F008ACC8: a0100018                 mov     %i0, %l0
F008ACCC: b0042034                 add     %l0, 0x34, %i0 ! '4'
F008ACD0: 7fff783d                 call    _lock_write
F008ACD4: 90100018                 mov     %i0, %o0
F008ACD8: d0042018                 ld      [%l0+0x18], %o0
F008ACDC: 80a22000                 cmp     %o0, 0
F008ACE0: 32800006                 bne,a   loc_F008ACF8
F008ACE4: d0042024                 ld      [%l0+0x24], %o0
F008ACE8: 7fff78d3                 call    _lock_done
F008ACEC: 90100018                 mov     %i0, %o0
F008ACF0: 10800046                 ba      locret_F008AE08
F008ACF4: b0103fff                 mov     -1, %i0
F008ACF8: 80a22000                 cmp     %o0, 0
F008ACFC: 16800003                 bge     loc_F008AD08
F008AD00: 96102000                 mov     0, %o3
F008AD04: 90022007                 inc     7, %o0
F008AD08: 993a2003                 sra     %o0, 3, %o4
F008AD0C: d2042014                 ld      [%l0+0x14], %o1
F008AD10: 90826007                 addcc   %o1, 7, %o0
F008AD14: 2c800002                 bneg,a  loc_F008AD1C
F008AD18: 9002600e                 add     %o1, 0xE, %o0
F008AD1C: 913a2003                 sra     %o0, 3, %o0
F008AD20: 80a30008                 cmp     %o4, %o0
F008AD24: 1680001b                 bge     loc_F008AD90
F008AD28: 912b2003                 sll     %o4, 3, %o0
F008AD2C: d0042010                 ld      [%l0+0x10], %o0
F008AD30: d00a000c                 ldub    [%o0+%o4], %o0
F008AD34: 80a220ff                 cmp     %o0, 0xFF
F008AD38: 22bffff6                 be,a    loc_F008AD10
F008AD3C: 98032001                 inc     %o4
F008AD40: 96102000                 mov     0, %o3
F008AD44: 80a2e000                 cmp     %o3, 0
F008AD48: 16800003                 bge     loc_F008AD54
F008AD4C: 9410000b                 mov     %o3, %o2
F008AD50: 9402e007                 add     %o3, 7, %o2
F008AD54: 953aa003                 sra     %o2, 3, %o2
F008AD58: d2042010                 ld      [%l0+0x10], %o1
F008AD5C: 912aa003                 sll     %o2, 3, %o0
F008AD60: 9202400c                 add     %o1, %o4, %o1
F008AD64: d24a400a                 ldsb    [%o1+%o2], %o1
F008AD68: 9022c008                 sub     %o3, %o0, %o0
F008AD6C: 933a4008                 sra     %o1, %o0, %o1
F008AD70: 808a6001                 btst    1, %o1
F008AD74: 22800007                 be,a    loc_F008AD90
F008AD78: 912b2003                 sll     %o4, 3, %o0
F008AD7C: 9602e001                 inc     %o3
F008AD80: 80a2e007                 cmp     %o3, 7
F008AD84: 04bffff1                 ble     loc_F008AD48
F008AD88: 80a2e000                 cmp     %o3, 0
F008AD8C: 912b2003                 sll     %o4, 3, %o0
F008AD90: d2042014                 ld      [%l0+0x14], %o1
F008AD94: b002000b                 add     %o0, %o3, %i0
F008AD98: 80a60009                 cmp     %i0, %o1
F008AD9C: 06800004                 bl      loc_F008ADAC
F008ADA0: 113c0447                 sethi   %hi(aVnodePagerAllo), %o0! "vnode_pager_allocpage"
F008ADA4: 7ffe28f3                 call    _panic
F008ADA8: 901222b0                 bset    %lo(aVnodePagerAllo), %o0! "vnode_pager_allocpage"
F008ADAC: d0042020                 ld      [%l0+0x20], %o0
F008ADB0: 80a60008                 cmp     %i0, %o0
F008ADB4: 34800002                 bg,a    loc_F008ADBC
F008ADB8: f0242020                 st      %i0, [%l0+0x20]
F008ADBC: 80a62000                 cmp     %i0, 0
F008ADC0: 16800003                 bge     loc_F008ADCC
F008ADC4: 98100018                 mov     %i0, %o4
F008ADC8: 98062007                 add     %i0, 7, %o4
F008ADCC: 90042034                 add     %l0, 0x34, %o0 ! '4'
F008ADD0: 993b2003                 sra     %o4, 3, %o4
F008ADD4: 972b2003                 sll     %o4, 3, %o3
F008ADD8: 9626000b                 sub     %i0, %o3, %o3
F008ADDC: da042010                 ld      [%l0+0x10], %o5
F008ADE0: 92102001                 mov     1, %o1
F008ADE4: d40b400c                 ldub    [%o5+%o4], %o2
F008ADE8: 932a400b                 sll     %o1, %o3, %o1
F008ADEC: 94128009                 bset    %o1, %o2
F008ADF0: d42b400c                 stb     %o2, [%o5+%o4]
F008ADF4: d2042018                 ld      [%l0+0x18], %o1
F008ADF8: f0242024                 st      %i0, [%l0+0x24]
F008ADFC: 92027fff                 inc     -1, %o1
F008AE00: 7fff788d                 call    _lock_done
F008AE04: d2242018                 st      %o1, [%l0+0x18]
F008AE08: 81c7e008                 ret
F008AE0C: 81e80000                 restore
