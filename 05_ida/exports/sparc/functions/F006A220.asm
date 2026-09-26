F006A220: 9de3bf98                 save    %sp, -0x68, %sp
F006A224: a0100018                 mov     %i0, %l0
F006A228: 113c000090122000         set     dword_F0000000, %o0
F006A230: 4000000b                 call    _nextsegfromheader
F006A234: 92100010                 mov     %l0, %o1
F006A238: b0920000                 orcc    %o0, %g0, %i0
F006A23C: 12800006                 bne     locret_F006A254
F006A240: 113c04f0                 sethi   %hi(_fvm_seg), %o0
F006A244: d00220f0                 ld      [%o0+%lo(_fvm_seg)], %o0
F006A248: 80a40008                 cmp     %l0, %o0
F006A24C: 32800002                 bne,a   locret_F006A254
F006A250: b0100008                 mov     %o0, %i0
F006A254: 81c7e008                 ret
F006A258: 81e80000                 restore
