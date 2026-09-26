F0005484: 9de3bf98                 save    %sp, -0x68, %sp
F0005488: a0102000                 mov     0, %l0
F000548C: 40000ac8                 call    _ffs
F0005490: 90100019                 mov     %i1, %o0! int
F0005494: a2920000                 orcc    %o0, %g0, %l1
F0005498: 12800007                 bne     loc_F00054B4
F000549C: 01000000                 nop
F00054A0: 40000ac3                 call    _ffs
F00054A4: 90100018                 mov     %i0, %o0
F00054A8: a2920000                 orcc    %o0, %g0, %l1
F00054AC: 32800002                 bne,a   loc_F00054B4
F00054B0: a2046020                 inc     0x20, %l1 ! ' '
F00054B4: b0100010                 mov     %l0, %i0
F00054B8: b2100011                 mov     %l1, %i1
F00054BC: 81c7e008                 ret
F00054C0: 81e80000                 restore
