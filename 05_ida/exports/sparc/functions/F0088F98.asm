F0088F98: 9de3bf98                 save    %sp, -0x68, %sp
F0088F9C: a2100018                 mov     %i0, %l1
F0088FA0: 113c04f4                 sethi   %hi(_page_shift), %o0
F0088FA4: 153c04f6                 sethi   %hi(_vm_page_buckets), %o2
F0088FA8: d0022348                 ld      [%o0+%lo(_page_shift)], %o0
F0088FAC: 133c04f6                 sethi   %hi(_vm_page_hash_mask), %o1
F0088FB0: d2026140                 ld      [%o1+%lo(_vm_page_hash_mask)], %o1
F0088FB4: 91364008                 srl     %i1, %o0, %o0
F0088FB8: 90044008                 add     %l1, %o0, %o0
F0088FBC: 900a0009                 and     %o0, %o1, %o0
F0088FC0: d202a138                 ld      [%o2+%lo(_vm_page_buckets)], %o1
F0088FC4: 912a2003                 sll     %o0, 3, %o0
F0088FC8: 400036fc                 call    _spltty
F0088FCC: a0024008                 add     %o1, %o0, %l0
F0088FD0: a4100008                 mov     %o0, %l2
F0088FD4: d0040000                 ld      [%l0], %o0
F0088FD8: 80a22000                 cmp     %o0, 0
F0088FDC: 12bffffe                 bne     loc_F0088FD4
F0088FE0: 01000000                 nop
F0088FE4: 400037b1                 call    _simple_lock_try
F0088FE8: 90100010                 mov     %l0, %o0
F0088FEC: 80a22000                 cmp     %o0, 0
F0088FF0: 02bffff9                 be      loc_F0088FD4
F0088FF4: 01000000                 nop
F0088FF8: f0042004                 ld      [%l0+4], %i0
F0088FFC: 80a62000                 cmp     %i0, 0
F0089000: 0280000e                 be      loc_F0089038
F0089004: 01000000                 nop
F0089008: d0062014                 ld      [%i0+0x14], %o0
F008900C: 80a20011                 cmp     %o0, %l1
F0089010: 32800007                 bne,a   loc_F008902C
F0089014: f0062010                 ld      [%i0+0x10], %i0
F0089018: d0062018                 ld      [%i0+0x18], %o0
F008901C: 80a20019                 cmp     %o0, %i1
F0089020: 02800006                 be      loc_F0089038
F0089024: 01000000                 nop
F0089028: f0062010                 ld      [%i0+0x10], %i0
F008902C: 80a62000                 cmp     %i0, 0
F0089030: 32bffff7                 bne,a   loc_F008900C
F0089034: d0062014                 ld      [%i0+0x14], %o0
F0089038: c0240000                 clr     [%l0]
F008903C: 4000373a                 call    _splx
F0089040: 90100012                 mov     %l2, %o0
F0089044: 81c7e008                 ret
F0089048: 81e80000                 restore
