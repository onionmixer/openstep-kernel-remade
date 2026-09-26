F0069948: 9de3bf98                 save    %sp, -0x68, %sp
F006994C: 4000b48f                 call    _splusclock
F0069950: 01000000                 nop
F0069954: a4100008                 mov     %o0, %l2
F0069958: 113c04bda0122280         set     dword_F012F680, %l0
F0069960: d0040000                 ld      [%l0], %o0
F0069964: 80a22000                 cmp     %o0, 0
F0069968: 12bffffe                 bne     loc_F0069960
F006996C: 01000000                 nop
F0069970: 4000b54e                 call    _simple_lock_try
F0069974: 90100010                 mov     %l0, %o0
F0069978: 80a22000                 cmp     %o0, 0
F006997C: 02bffff9                 be      loc_F0069960
F0069980: 90100012                 mov     %l2, %o0
F0069984: c0262034                 clr     [%i0+0x34]
F0069988: e2062028                 ld      [%i0+0x28], %l1
F006998C: e006202c                 ld      [%i0+0x2C], %l0
F0069990: 133c04bd                 sethi   %hi(dword_F012F680), %o1
F0069994: c0226280                 clr     [%o1+%lo(dword_F012F680)]
F0069998: 4000b4e3                 call    _splx
F006999C: 01000000                 nop
F00699A0: 9fc44000                 call    %l1
F00699A4: 90100010                 mov     %l0, %o0
F00699A8: 81c7e008                 ret
F00699AC: 81e80000                 restore
