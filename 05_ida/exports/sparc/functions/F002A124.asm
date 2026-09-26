F002A124: 9de3bf98                 save    %sp, -0x68, %sp
F002A128: a0102000                 mov     0, %l0
F002A12C: 90100019                 mov     %i1, %o0! __s1
F002A130: 133c03d3                 sethi   %hi(_IFCONTROL_SETADDR), %o1! "setaddr"
F002A134: 7fff781e                 call    _strcmp
F002A138: 921260e0                 bset    %lo(_IFCONTROL_SETADDR), %o1! "setaddr"
F002A13C: 80a22000                 cmp     %o0, 0
F002A140: 12800008                 bne     loc_F002A160
F002A144: 90100019                 mov     %i1, %o0
F002A148: 4000073f                 call    _if_flags
F002A14C: 90100018                 mov     %i0, %o0
F002A150: 92122041                 or      %o0, 0x41, %o1! __s2
F002A154: 40000754                 call    _if_flags_set
F002A158: 90100018                 mov     %i0, %o0! __s1
F002A15C: 30800011                 ba,a    locret_F002A1A0
F002A160: 133c03d3b0126130         set     _IFCONTROL_ADDMULTICAST, %i0! "add-multicast"
F002A168: 7fff7811                 call    _strcmp
F002A16C: 92100018                 mov     %i0, %o1! __s2
F002A170: 80a22000                 cmp     %o0, 0
F002A174: 02800007                 be      loc_F002A190
F002A178: 90100019                 mov     %i1, %o0! __s1
F002A17C: 7fff780c                 call    _strcmp
F002A180: 92100018                 mov     %i0, %o1
F002A184: 80a22000                 cmp     %o0, 0
F002A188: 32800006                 bne,a   locret_F002A1A0
F002A18C: a0102016                 mov     0x16, %l0
F002A190: d016a010                 lduh    [%i2+0x10], %o0
F002A194: 80a22002                 cmp     %o0, 2
F002A198: 32800002                 bne,a   locret_F002A1A0
F002A19C: a010202f                 mov     0x2F, %l0 ! '/'
F002A1A0: 81c7e008                 ret
F002A1A4: 91e80010                 restore %g0, %l0, %o0
