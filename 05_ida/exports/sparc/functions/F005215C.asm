F005215C: 9de3bf98                 save    %sp, -0x68, %sp
F0052160: 10800006                 ba      loc_F0052178
F0052164: e0062030                 ld      [%i0+0x30], %l0
F0052168: d0342044                 sth     %o0, [%l0+0x44]
F005216C: 90100010                 mov     %l0, %o0! unsigned int
F0052170: 7fff0142                 call    _sleep
F0052174: 9210200a                 mov     0xA, %o1
F0052178: d0142044                 lduh    [%l0+0x44], %o0
F005217C: 808a2001                 btst    1, %o0
F0052180: 32bffffa                 bne,a   loc_F0052168
F0052184: 90122010                 bset    0x10, %o0
F0052188: 90100010                 mov     %l0, %o0
F005218C: d4142044                 lduh    [%l0+0x44], %o2
F0052190: 92100019                 mov     %i1, %o1
F0052194: 9412a001                 bset    1, %o2
F0052198: 7ffff3dc                 call    _iaccess
F005219C: d4342044                 sth     %o2, [%l0+0x44]
F00521A0: b0100008                 mov     %o0, %i0
F00521A4: 7ffff3c9                 call    _iunlock
F00521A8: 90100010                 mov     %l0, %o0
F00521AC: 81c7e008                 ret
F00521B0: 81e80000                 restore
