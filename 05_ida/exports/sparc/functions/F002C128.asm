F002C128: 9de3bf98                 save    %sp, -0x68, %sp
F002C12C: 213c04bda2142014         set     dword_F012F414, %l1
F002C134: 4000efcf                 call    _kalloc
F002C138: 9010200c                 mov     0xC, %o0
F002C13C: 94100008                 mov     %o0, %o2
F002C140: f0228000                 st      %i0, [%o2]
F002C144: f222a004                 st      %i1, [%o2+4]
F002C148: d0042014                 ld      [%l0+0x14], %o0
F002C14C: 80a22000                 cmp     %o0, 0
F002C150: 02800007                 be      loc_F002C16C
F002C154: c022a008                 clr     [%o2+8]
F002C158: d0044000                 ld      [%l1], %o0
F002C15C: d2022008                 ld      [%o0+8], %o1
F002C160: 80a26000                 cmp     %o1, 0
F002C164: 12bffffd                 bne     loc_F002C158
F002C168: a2022008                 add     %o0, 8, %l1
F002C16C: d4244000                 st      %o2, [%l1]
F002C170: 113c04d0                 sethi   %hi(_ifnet), %o0
F002C174: e00220b8                 ld      [%o0+%lo(_ifnet)], %l0
F002C178: 80a42000                 cmp     %l0, 0
F002C17C: 0280000d                 be      locret_F002C1B0
F002C180: 01000000                 nop
F002C184: d0042014                 ld      [%l0+0x14], %o0
F002C188: 80a22000                 cmp     %o0, 0
F002C18C: 32800006                 bne,a   loc_F002C1A4
F002C190: e004205c                 ld      [%l0+0x5C], %l0
F002C194: 90100019                 mov     %i1, %o0
F002C198: 9fc60000                 call    %i0
F002C19C: 92100010                 mov     %l0, %o1
F002C1A0: e004205c                 ld      [%l0+0x5C], %l0
F002C1A4: 80a42000                 cmp     %l0, 0
F002C1A8: 32bffff8                 bne,a   loc_F002C188
F002C1AC: d0042014                 ld      [%l0+0x14], %o0
F002C1B0: 81c7e008                 ret
F002C1B4: 81e80000                 restore
