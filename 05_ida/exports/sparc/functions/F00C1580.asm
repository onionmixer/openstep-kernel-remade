F00C1580: 9de3bf98                 save    %sp, -0x68, %sp
F00C1584: b006001a                 add     %i0, %i2, %i0
F00C1588: b0063fff                 inc     -1, %i0
F00C158C: c02e0000                 clrb    [%i0]
F00C1590: 80a66000                 cmp     %i1, 0
F00C1594: b4102005                 mov     5, %i2
F00C1598: 113c0483                 sethi   %hi(a0123456789abcd_3), %o0! "0123456789abcdef"
F00C159C: 02800013                 be      locret_F00C15E8
F00C15A0: a2122290                 or      %o0, %lo(a0123456789abcd_3), %l1! "0123456789abcdef"
F00C15A4: a00e6001                 and     %i1, 1, %l0
F00C15A8: b3366001                 srl     %i1, 1, %i1
F00C15AC: b0063fff                 inc     -1, %i0
F00C15B0: 90100019                 mov     %i1, %o0
F00C15B4: 7ffd14bb                 call    _urem
F00C15B8: 9210001a                 mov     %i2, %o1
F00C15BC: 92100008                 mov     %o0, %o1
F00C15C0: 932a6001                 sll     %o1, 1, %o1
F00C15C4: 92024010                 add     %o1, %l0, %o1
F00C15C8: d40c4009                 ldub    [%l1+%o1], %o2
F00C15CC: 90100019                 mov     %i1, %o0
F00C15D0: 9210001a                 mov     %i2, %o1
F00C15D4: 7ffd140b                 call    _udiv
F00C15D8: d42e0000                 stb     %o2, [%i0]
F00C15DC: b2920000                 orcc    %o0, %g0, %i1
F00C15E0: 12bffff2                 bne     loc_F00C15A8
F00C15E4: a00e6001                 and     %i1, 1, %l0
F00C15E8: 81c7e008                 ret
F00C15EC: 81e80000                 restore
