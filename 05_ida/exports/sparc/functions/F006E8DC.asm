F006E8DC: 9de3bf90                 save    %sp, -0x70, %sp
F006E8E0: f2064000                 ld      [%i1], %i1
F006E8E4: 113c04d490122170         set     _realhost, %o0
F006E8EC: 80a60008                 cmp     %i0, %o0
F006E8F0: 12800007                 bne     loc_F006E90C
F006E8F4: 9210001a                 mov     %i2, %o1
F006E8F8: f227bff4                 st      %i1, [%fp+var_C]
F006E8FC: 400097f7                 call    _PMSetPowerState
F006E900: 9007bff4                 add     %fp, var_C, %o0
F006E904: 10800003                 ba      locret_F006E910
F006E908: b0100008                 mov     %o0, %i0
F006E90C: b0102016                 mov     0x16, %i0
F006E910: 81c7e008                 ret
F006E914: 81e80000                 restore
