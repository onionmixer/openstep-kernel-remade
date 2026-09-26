F006E918: 9de3bf98                 save    %sp, -0x68, %sp
F006E91C: 113c04d490122170         set     _realhost, %o0
F006E924: 80a60008                 cmp     %i0, %o0
F006E928: 12800005                 bne     locret_F006E93C
F006E92C: b0102016                 mov     0x16, %i0
F006E930: 7fffff79                 call    sub_F006E714
F006E934: 90100019                 mov     %i1, %o0
F006E938: b0100008                 mov     %o0, %i0
F006E93C: 81c7e008                 ret
F006E940: 81e80000                 restore
