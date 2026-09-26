F0098BA0: 9de3bf98                 save    %sp, -0x68, %sp
F0098BA4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0098BA8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0098BAC: d4062284                 ld      [%i0+0x284], %o2! size_t
F0098BB0: d2022028                 ld      [%o0+0x28], %o1
F0098BB4: 80a2a000                 cmp     %o2, 0
F0098BB8: 0280001a                 be      locret_F0098C20
F0098BBC: a0026234                 add     %o1, 0x234, %l0
F0098BC0: 113c044a                 sethi   %hi(_fpu_exists), %o0
F0098BC4: d00220c8                 ld      [%o0+%lo(_fpu_exists)], %o0
F0098BC8: 80a22000                 cmp     %o0, 0
F0098BCC: 02800008                 be      loc_F0098BEC
F0098BD0: 11000004                 sethi   0x1000, %o0
F0098BD4: d2026234                 ld      [%o1+0x234], %o1
F0098BD8: 808a4008                 btst    %o0, %o1
F0098BDC: 02800004                 be      loc_F0098BEC
F0098BE0: 01000000                 nop
F0098BE4: 7ffff1aa                 call    _fp_dumpregs
F0098BE8: 9010000a                 mov     %o2, %o0
F0098BEC: 7fffffb1                 call    _fpu_ctxalloc
F0098BF0: 01000000                 nop
F0098BF4: 92100008                 mov     %o0, %o1! void *
F0098BF8: d2266284                 st      %o1, [%i1+0x284]
F0098BFC: d0062284                 ld      [%i0+0x284], %o0! void *
F0098C00: 7fffefc4                 call    _bcopy
F0098C04: 94102110                 mov     0x110, %o2
F0098C08: 113c044d                 sethi   %hi(_fp_ctxp), %o0
F0098C0C: c0222078                 clr     [%o0+%lo(_fp_ctxp)]
F0098C10: d2040000                 ld      [%l0], %o1
F0098C14: 11000004                 sethi   0x1000, %o0
F0098C18: 902a4008                 andn    %o1, %o0, %o0
F0098C1C: d0240000                 st      %o0, [%l0]
F0098C20: 81c7e008                 ret
F0098C24: 81e80000                 restore
