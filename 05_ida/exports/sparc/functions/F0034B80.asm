F0034B80: 9de3bf98                 save    %sp, -0x68, %sp
F0034B84: 153c04e9                 sethi   %hi(_tcp_debx), %o2! __n
F0034B88: d202a390                 ld      [%o2+%lo(_tcp_debx)], %o1
F0034B8C: 90026001                 add     %o1, 1, %o0
F0034B90: d022a390                 st      %o0, [%o2+%lo(_tcp_debx)]
F0034B94: 80a22064                 cmp     %o0, 0x64 ! 'd'
F0034B98: 912a6002                 sll     %o1, 2, %o0
F0034B9C: 90020009                 add     %o0, %o1, %o0
F0034BA0: 912a2003                 sll     %o0, 3, %o0
F0034BA4: 90020009                 add     %o0, %o1, %o0
F0034BA8: a32a2002                 sll     %o0, 2, %l1
F0034BAC: 113c04d9a4122380         set     _tcp_debug, %l2
F0034BB4: 12800003                 bne     loc_F0034BC0
F0034BB8: a0044012                 add     %l1, %l2, %l0
F0034BBC: c022a390                 clr     [%o2+%lo(_tcp_debx)]
F0034BC0: 7ffff3ad                 call    _iptime
F0034BC4: 01000000                 nop
F0034BC8: d0244012                 st      %o0, [%l1+%l2]
F0034BCC: f0342004                 sth     %i0, [%l0+4]
F0034BD0: f2342006                 sth     %i1, [%l0+6]
F0034BD4: 80a6a000                 cmp     %i2, 0
F0034BD8: 02800008                 be      loc_F0034BF8
F0034BDC: f4242008                 st      %i2, [%l0+8]
F0034BE0: 90042038                 add     %l0, 0x38, %o0 ! '8'! __dst
F0034BE4: 9210001a                 mov     %i2, %o1! size_t
F0034BE8: 7fff49ae                 call    _memcpy
F0034BEC: 9410206c                 mov     0x6C, %o2 ! 'l'
F0034BF0: 10800006                 ba      loc_F0034C08
F0034BF4: 80a6e000                 cmp     %i3, 0
F0034BF8: 90042038                 add     %l0, 0x38, %o0 ! '8'! void *
F0034BFC: 40018097                 call    _bzero
F0034C00: 9210206c                 mov     0x6C, %o1 ! 'l'! size_t
F0034C04: 80a6e000                 cmp     %i3, 0
F0034C08: 02800017                 be      loc_F0034C64
F0034C0C: 9004200c                 add     %l0, 0xC, %o0
F0034C10: d006c000                 ld      [%i3], %o0
F0034C14: d024200c                 st      %o0, [%l0+0xC]
F0034C18: d006e004                 ld      [%i3+4], %o0
F0034C1C: d0242010                 st      %o0, [%l0+0x10]
F0034C20: d006e008                 ld      [%i3+8], %o0
F0034C24: d0242014                 st      %o0, [%l0+0x14]
F0034C28: d006e00c                 ld      [%i3+0xC], %o0
F0034C2C: d0242018                 st      %o0, [%l0+0x18]
F0034C30: d006e010                 ld      [%i3+0x10], %o0
F0034C34: d024201c                 st      %o0, [%l0+0x1C]
F0034C38: d006e014                 ld      [%i3+0x14], %o0
F0034C3C: d0242020                 st      %o0, [%l0+0x20]
F0034C40: d006e018                 ld      [%i3+0x18], %o0
F0034C44: d0242024                 st      %o0, [%l0+0x24]
F0034C48: d006e01c                 ld      [%i3+0x1C], %o0
F0034C4C: d0242028                 st      %o0, [%l0+0x28]
F0034C50: d006e020                 ld      [%i3+0x20], %o0
F0034C54: d024202c                 st      %o0, [%l0+0x2C]
F0034C58: d006e024                 ld      [%i3+0x24], %o0! void *
F0034C5C: 10800004                 ba      loc_F0034C6C
F0034C60: d0242030                 st      %o0, [%l0+0x30]
F0034C64: 4001807d                 call    _bzero
F0034C68: 92102028                 mov     0x28, %o1 ! '('
F0034C6C: f8342034                 sth     %i4, [%l0+0x34]
F0034C70: 81c7e008                 ret
F0034C74: 81e80000                 restore
