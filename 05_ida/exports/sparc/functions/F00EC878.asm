F00EC878: 9de3bf98                 save    %sp, -0x68, %sp
F00EC87C: a2100018                 mov     %i0, %l1
F00EC880: 113c04bca0122060         set     dword_F012F060, %l0
F00EC888: d0040000                 ld      [%l0], %o0
F00EC88C: 80a22000                 cmp     %o0, 0
F00EC890: 12bffffe                 bne     loc_F00EC888
F00EC894: 01000000                 nop
F00EC898: 7ffea984                 call    _simple_lock_try
F00EC89C: 90100010                 mov     %l0, %o0
F00EC8A0: 80a22000                 cmp     %o0, 0
F00EC8A4: 02bffff9                 be      loc_F00EC888
F00EC8A8: 113c04bc                 sethi   %hi(unk_F012F048), %o0
F00EC8AC: b0122048                 or      %o0, %lo(unk_F012F048), %i0
F00EC8B0: 80a62000                 cmp     %i0, 0
F00EC8B4: 0280000c                 be      loc_F00EC8E4
F00EC8B8: 133c04bc                 sethi   -0xFED1000, %o1! __size
F00EC8BC: d0062010                 ld      [%i0+0x10], %o0
F00EC8C0: 80a22000                 cmp     %o0, 0
F00EC8C4: 32800005                 bne,a   loc_F00EC8D8
F00EC8C8: f0062014                 ld      [%i0+0x14], %i0
F00EC8CC: e2262010                 st      %l1, [%i0+0x10]
F00EC8D0: c0226060                 clr     [%o1+0x60]
F00EC8D4: 3080000f                 ba,a    locret_F00EC910
F00EC8D8: 80a62000                 cmp     %i0, 0
F00EC8DC: 32bffff9                 bne,a   loc_F00EC8C0
F00EC8E0: d0062010                 ld      [%i0+0x10], %o0
F00EC8E4: 90102018                 mov     0x18, %o0! __count
F00EC8E8: 7ffdee5f                 call    _calloc
F00EC8EC: 92102001                 mov     1, %o1
F00EC8F0: b0100008                 mov     %o0, %i0
F00EC8F4: e2262010                 st      %l1, [%i0+0x10]
F00EC8F8: 113c04bc                 sethi   %hi(dword_F012F05C), %o0
F00EC8FC: d202205c                 ld      [%o0+%lo(dword_F012F05C)], %o1
F00EC900: d2262014                 st      %o1, [%i0+0x14]
F00EC904: f022205c                 st      %i0, [%o0+%lo(dword_F012F05C)]
F00EC908: 113c04bc                 sethi   %hi(dword_F012F060), %o0
F00EC90C: c0222060                 clr     [%o0+%lo(dword_F012F060)]
F00EC910: 81c7e008                 ret
F00EC914: 81e80000                 restore
