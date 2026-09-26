F0068BF4: 9de3bf98                 save    %sp, -0x68, %sp
F0068BF8: 4000cca6                 call    _stack_detach
F0068BFC: 90100018                 mov     %i0, %o0
F0068C00: d2062030                 ld      [%i0+0x30], %o1
F0068C04: 80a20009                 cmp     %o0, %o1
F0068C08: 02800004                 be      locret_F0068C18
F0068C0C: 01000000                 nop
F0068C10: 7ffffe46                 call    _freeStack
F0068C14: 01000000                 nop
F0068C18: 81c7e008                 ret
F0068C1C: 81e80000                 restore
