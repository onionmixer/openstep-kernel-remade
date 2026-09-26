F006E944: 9de3bf98                 save    %sp, -0x68, %sp
F006E948: 113c04d490122170         set     _realhost, %o0
F006E950: 80a60008                 cmp     %i0, %o0
F006E954: 12800005                 bne     locret_F006E968
F006E958: b0102016                 mov     0x16, %i0
F006E95C: 400097e9                 call    _PMGetPowerStatus
F006E960: 90100019                 mov     %i1, %o0
F006E964: b0100008                 mov     %o0, %i0
F006E968: 81c7e008                 ret
F006E96C: 81e80000                 restore
