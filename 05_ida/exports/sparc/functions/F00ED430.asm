F00ED430: 9de3bf88                 save    %sp, -0x78, %sp
F00ED434: 80a60019                 cmp     %i0, %i1
F00ED438: 2280001f                 be,a    locret_F00ED4B4
F00ED43C: b0102001                 mov     1, %i0
F00ED440: 40000069                 call    _NXCountHashTable
F00ED444: 90100018                 mov     %i0, %o0! table
F00ED448: a0100008                 mov     %o0, %l0
F00ED44C: 40000066                 call    _NXCountHashTable
F00ED450: 90100019                 mov     %i1, %o0
F00ED454: 80a40008                 cmp     %l0, %o0
F00ED458: 32800017                 bne,a   locret_F00ED4B4
F00ED45C: b0102000                 mov     0, %i0
F00ED460: 9007bff0                 add     %fp, var_10, %o0
F00ED464: d023a040                 st      %o0, [%sp+0x78+var_38]
F00ED468: 90100018                 mov     %i0, %o0! table
F00ED46C: 4000025e                 call    _NXInitHashState
F00ED470: 01000000                 nop
F00ED474: 00000008                 illtrap
F00ED478: 90100018                 mov     %i0, %o0! table
F00ED47C: 9207bff0                 add     %fp, var_10, %o1! state
F00ED480: 40000264                 call    _NXNextHashState
F00ED484: 9407bfec                 add     %fp, var_14, %o2
F00ED488: 80a22000                 cmp     %o0, 0
F00ED48C: 12800004                 bne     loc_F00ED49C
F00ED490: 90100019                 mov     %i1, %o0! table
F00ED494: 10800008                 ba      locret_F00ED4B4
F00ED498: b0102001                 mov     1, %i0
F00ED49C: 40000054                 call    _NXHashMember
F00ED4A0: d207bfec                 ld      [%fp+var_14], %o1
F00ED4A4: 80a22000                 cmp     %o0, 0
F00ED4A8: 12bffff5                 bne     loc_F00ED47C
F00ED4AC: 90100018                 mov     %i0, %o0
F00ED4B0: b0102000                 mov     0, %i0
F00ED4B4: 81c7e008                 ret
F00ED4B8: 81e80000                 restore
