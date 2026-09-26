F006E970: 9de3bf90                 save    %sp, -0x70, %sp
F006E974: f2064000                 ld      [%i1], %i1
F006E978: 113c04d490122170         set     _realhost, %o0
F006E980: 80a60008                 cmp     %i0, %o0
F006E984: 12800007                 bne     loc_F006E9A0
F006E988: 9210001a                 mov     %i2, %o1
F006E98C: f227bff4                 st      %i1, [%fp+var_C]
F006E990: 400097e3                 call    _PMSetPowerManagement
F006E994: 9007bff4                 add     %fp, var_C, %o0
F006E998: 10800003                 ba      locret_F006E9A4
F006E99C: b0100008                 mov     %o0, %i0
F006E9A0: b0102016                 mov     0x16, %i0
F006E9A4: 81c7e008                 ret
F006E9A8: 81e80000                 restore
