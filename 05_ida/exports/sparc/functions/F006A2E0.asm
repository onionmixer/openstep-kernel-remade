F006A2E0: 9de3bf98                 save    %sp, -0x68, %sp
F006A2E4: a0100018                 mov     %i0, %l0
F006A2E8: 113c000090122000         set     dword_F0000000, %o0
F006A2F0: 7fffff97                 call    _getsegbynamefromheader
F006A2F4: 92100010                 mov     %l0, %o1
F006A2F8: b0920000                 orcc    %o0, %g0, %i0
F006A2FC: 12800009                 bne     locret_F006A320
F006A300: 233c04f0                 sethi   %hi(_fvm_seg), %l1
F006A304: d20460f0                 ld      [%l1+%lo(_fvm_seg)], %o1! __s2
F006A308: 90100010                 mov     %l0, %o0! __s1
F006A30C: 7ffe77a8                 call    _strcmp
F006A310: 92026008                 inc     8, %o1
F006A314: 80a22000                 cmp     %o0, 0
F006A318: 22800002                 be,a    locret_F006A320
F006A31C: f00460f0                 ld      [%l1+%lo(_fvm_seg)], %i0
F006A320: 81c7e008                 ret
F006A324: 81e80000                 restore
