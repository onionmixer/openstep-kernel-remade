F00EFBA0: 9de3bf98                 save    %sp, -0x68, %sp
F00EFBA4: 40000345                 call    __objc_create_zone
F00EFBA8: a2100018                 mov     %i0, %l1
F00EFBAC: 40000343                 call    __objc_create_zone
F00EFBB0: a0100008                 mov     %o0, %l0
F00EFBB4: d4042004                 ld      [%l0+4], %o2
F00EFBB8: 9fc28000                 call    %o2
F00EFBBC: 92100011                 mov     %l1, %o1
F00EFBC0: b0920000                 orcc    %o0, %g0, %i0
F00EFBC4: 12800006                 bne     locret_F00EFBDC
F00EFBC8: 80a46000                 cmp     %l1, 0
F00EFBCC: 02800004                 be      locret_F00EFBDC
F00EFBD0: 113c03f4                 sethi   %hi(aUnableToAlloca), %o0! "unable to allocate space"
F00EFBD4: 4000038d                 call    __objc_fatal
F00EFBD8: 90122110                 bset    %lo(aUnableToAlloca), %o0! "unable to allocate space"
F00EFBDC: 81c7e008                 ret
F00EFBE0: 81e80000                 restore
