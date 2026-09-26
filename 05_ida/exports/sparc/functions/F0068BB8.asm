F0068BB8: 9de3bf98                 save    %sp, -0x68, %sp
F0068BBC: 7ffffeb6                 call    _allocStack
F0068BC0: 01000000                 nop
F0068BC4: a0920000                 orcc    %o0, %g0, %l0
F0068BC8: 32800006                 bne,a   loc_F0068BE0
F0068BCC: 90100018                 mov     %i0, %o0
F0068BD0: 113c043e                 sethi   %hi(aStackAlloc), %o0! "stack_alloc"
F0068BD4: 7ffeb167                 call    _panic
F0068BD8: 90122370                 bset    %lo(aStackAlloc), %o0! "stack_alloc"
F0068BDC: 90100018                 mov     %i0, %o0
F0068BE0: 92100010                 mov     %l0, %o1
F0068BE4: 4000cc9c                 call    _stack_attach
F0068BE8: 94100019                 mov     %i1, %o2
F0068BEC: 81c7e008                 ret
F0068BF0: 81e80000                 restore
