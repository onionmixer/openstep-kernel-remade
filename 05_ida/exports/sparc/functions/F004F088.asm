F004F088: 9de3bf98                 save    %sp, -0x68, %sp
F004F08C: 10800007                 ba      loc_F004F0A8
F004F090: d0162044                 lduh    [%i0+0x44], %o0
F004F094: d0362044                 sth     %o0, [%i0+0x44]
F004F098: 90100018                 mov     %i0, %o0! unsigned int
F004F09C: 7fff0d77                 call    _sleep
F004F0A0: 9210200a                 mov     0xA, %o1
F004F0A4: d0162044                 lduh    [%i0+0x44], %o0
F004F0A8: 808a2001                 btst    1, %o0
F004F0AC: 12bffffa                 bne     loc_F004F094
F004F0B0: 90122010                 bset    0x10, %o0
F004F0B4: d0162044                 lduh    [%i0+0x44], %o0
F004F0B8: 90122001                 bset    1, %o0
F004F0BC: d0362044                 sth     %o0, [%i0+0x44]
F004F0C0: 81c7e008                 ret
F004F0C4: 81e80000                 restore
