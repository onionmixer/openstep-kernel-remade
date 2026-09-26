F008BDCC: 9de3bf58                 save    %sp, -0xA8, %sp
F008BDD0: 113c04c3                 sethi   %hi(unk_F0130F70), %o0
F008BDD4: d4060000                 ld      [%i0], %o2
F008BDD8: 90122370                 bset    %lo(unk_F0130F70), %o0
F008BDDC: 9332a018                 srl     %o2, 24, %o1
F008BDE0: 932a6002                 sll     %o1, 2, %o1
F008BDE4: f0024008                 ld      [%o1+%o0], %i0
F008BDE8: 113fc000                 sethi   -0x1000000, %o0
F008BDEC: d2062020                 ld      [%i0+0x20], %o1
F008BDF0: a02a8008                 andn    %o2, %o0, %l0
F008BDF4: 80a40009                 cmp     %l0, %o1
F008BDF8: 06800045                 bl      locret_F008BF0C
F008BDFC: e4062008                 ld      [%i0+8], %l2
F008BE00: 7fff73f1                 call    _lock_write
F008BE04: 90062034                 add     %i0, 0x34, %o0 ! '4'
F008BE08: 96843fff                 addcc   %l0, -1, %o3
F008BE0C: 2c800013                 bneg,a  loc_F008BE58
F008BE10: d206201c                 ld      [%i0+0x1C], %o1
F008BE14: 80a2e000                 cmp     %o3, 0
F008BE18: 16800003                 bge     loc_F008BE24
F008BE1C: 9210000b                 mov     %o3, %o1
F008BE20: 9202e007                 add     %o3, 7, %o1
F008BE24: 933a6003                 sra     %o1, 3, %o1
F008BE28: d4062010                 ld      [%i0+0x10], %o2
F008BE2C: 912a6003                 sll     %o1, 3, %o0
F008BE30: d24a8009                 ldsb    [%o2+%o1], %o1
F008BE34: 9022c008                 sub     %o3, %o0, %o0
F008BE38: 933a4008                 sra     %o1, %o0, %o1
F008BE3C: 808a6001                 btst    1, %o1
F008BE40: 32800005                 bne,a   loc_F008BE54
F008BE44: d6262020                 st      %o3, [%i0+0x20]
F008BE48: 9682ffff                 inccc   -1, %o3
F008BE4C: 1cbffff3                 bpos    loc_F008BE18
F008BE50: 80a2e000                 cmp     %o3, 0
F008BE54: d206201c                 ld      [%i0+0x1C], %o1
F008BE58: d0062020                 ld      [%i0+0x20], %o0
F008BE5C: 80a26000                 cmp     %o1, 0
F008BE60: 0280000c                 be      loc_F008BE90
F008BE64: a2022001                 add     %o0, 1, %l1
F008BE68: 80a44009                 cmp     %l1, %o1
F008BE6C: 04800009                 ble     loc_F008BE90
F008BE70: 273c04f4                 sethi   %hi(_page_shift), %l3
F008BE74: d0048000                 ld      [%l2], %o0
F008BE78: d204e348                 ld      [%l3+%lo(_page_shift)], %o1
F008BE7C: d0022014                 ld      [%o0+0x14], %o0
F008BE80: 932c4009                 sll     %l1, %o1, %o1
F008BE84: 80a20009                 cmp     %o0, %o1
F008BE88: 1a800004                 bcc     loc_F008BE98
F008BE8C: a007bfb8                 add     %fp, var_48, %l0
F008BE90: 1080001d                 ba      loc_F008BF04
F008BE94: 90062034                 add     %i0, 0x34, %o0 ! '4'
F008BE98: 7ffe757f                 call    _vattr_null
F008BE9C: 90100010                 mov     %l0, %o0
F008BEA0: d004e348                 ld      [%l3+0x348], %o0
F008BEA4: 912c4008                 sll     %l1, %o0, %o0
F008BEA8: d027bfd0                 st      %o0, [%fp+var_30]
F008BEAC: d2048000                 ld      [%l2], %o1
F008BEB0: 273c04cf                 sethi   %hi(_active_u), %l3
F008BEB4: d004e1d8                 ld      [%l3+%lo(_active_u)], %o0
F008BEB8: d2026030                 ld      [%o1+0x30], %o1
F008BEBC: e202201c                 ld      [%o0+0x1C], %l1
F008BEC0: d222201c                 st      %o1, [%o0+0x1C]
F008BEC4: d0048000                 ld      [%l2], %o0
F008BEC8: d204a01c                 ld      [%l2+0x1C], %o1
F008BECC: d4022030                 ld      [%o0+0x30], %o2
F008BED0: d6026018                 ld      [%o1+0x18], %o3
F008BED4: 90100012                 mov     %l2, %o0
F008BED8: 9fc2c000                 call    %o3
F008BEDC: 92100010                 mov     %l0, %o1
F008BEE0: 94920000                 orcc    %o0, %g0, %o2
F008BEE4: 02800005                 be      loc_F008BEF8
F008BEE8: 113c0447                 sethi   %hi(aVnodeDeallocpa), %o0! "vnode_deallocpage: error truncating %s,"...
F008BEEC: d2062028                 ld      [%i0+0x28], %o1
F008BEF0: 7ffe21da                 call    _printf
F008BEF4: 90122348                 bset    %lo(aVnodeDeallocpa), %o0! "vnode_deallocpage: error truncating %s,"...
F008BEF8: d204e1d8                 ld      [%l3+0x1D8], %o1
F008BEFC: 90062034                 add     %i0, 0x34, %o0 ! '4'
F008BF00: e222601c                 st      %l1, [%o1+0x1C]
F008BF04: 7fff744c                 call    _lock_done
F008BF08: 01000000                 nop
F008BF0C: 81c7e008                 ret
F008BF10: 81e80000                 restore
