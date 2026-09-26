F006E9AC: 9de3bf98                 save    %sp, -0x68, %sp
F006E9B0: 113c04d490122170         set     _realhost, %o0
F006E9B8: 80a60008                 cmp     %i0, %o0
F006E9BC: 12800005                 bne     locret_F006E9D0
F006E9C0: b0102016                 mov     0x16, %i0
F006E9C4: 400097d9                 call    _PMRestoreDefaults
F006E9C8: 01000000                 nop
F006E9CC: b0100008                 mov     %o0, %i0
F006E9D0: 81c7e008                 ret
F006E9D4: 81e80000                 restore
