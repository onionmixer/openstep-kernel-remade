F002C660: 9de3bf98                 save    %sp, -0x68, %sp
F002C664: 9206200c                 add     %i0, 0xC, %o1! void *
F002C668: d0066004                 ld      [%i1+4], %o0! void *
F002C66C: 94102010                 mov     0x10, %o2! size_t
F002C670: 4001a128                 call    _bcopy
F002C674: 90064008                 add     %i1, %o0, %o0
F002C678: d016204c                 lduh    [%i0+0x4C], %o0
F002C67C: 90122002                 bset    2, %o0
F002C680: d036204c                 sth     %o0, [%i0+0x4C]
F002C684: 81c7e008                 ret
F002C688: 81e80000                 restore
