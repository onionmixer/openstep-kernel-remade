F00ED4BC: 9de3bf88                 save    %sp, -0x78, %sp
F00ED4C0: 80a60019                 cmp     %i0, %i1
F00ED4C4: 2280001f                 be,a    locret_F00ED540
F00ED4C8: b0102001                 mov     1, %i0
F00ED4CC: 40000046                 call    _NXCountHashTable
F00ED4D0: 90100018                 mov     %i0, %o0! table
F00ED4D4: a0100008                 mov     %o0, %l0
F00ED4D8: 40000043                 call    _NXCountHashTable
F00ED4DC: 90100019                 mov     %i1, %o0
F00ED4E0: 80a40008                 cmp     %l0, %o0
F00ED4E4: 32800017                 bne,a   locret_F00ED540
F00ED4E8: b0102000                 mov     0, %i0
F00ED4EC: 9007bff0                 add     %fp, var_10, %o0
F00ED4F0: d023a040                 st      %o0, [%sp+0x78+var_38]
F00ED4F4: 90100018                 mov     %i0, %o0! table
F00ED4F8: 4000023b                 call    _NXInitHashState
F00ED4FC: 01000000                 nop
F00ED500: 00000008                 illtrap
F00ED504: 90100018                 mov     %i0, %o0! table
F00ED508: 9207bff0                 add     %fp, var_10, %o1! state
F00ED50C: 40000241                 call    _NXNextHashState
F00ED510: 9407bfec                 add     %fp, var_14, %o2
F00ED514: 80a22000                 cmp     %o0, 0
F00ED518: 12800004                 bne     loc_F00ED528
F00ED51C: 90100019                 mov     %i1, %o0! table
F00ED520: 10800008                 ba      locret_F00ED540
F00ED524: b0102001                 mov     1, %i0
F00ED528: 40000031                 call    _NXHashMember
F00ED52C: d207bfec                 ld      [%fp+var_14], %o1
F00ED530: 80a22000                 cmp     %o0, 0
F00ED534: 12bffff5                 bne     loc_F00ED508
F00ED538: 90100018                 mov     %i0, %o0
F00ED53C: b0102000                 mov     0, %i0
F00ED540: 81c7e008                 ret
F00ED544: 81e80000                 restore
