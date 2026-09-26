F006522C: 9de3bf98                 save    %sp, -0x68, %sp
F0065230: 80a62000                 cmp     %i0, 0
F0065234: 02800007                 be      loc_F0065250
F0065238: 113c04d3                 sethi   %hi(_default_pset), %o0
F006523C: 901223c0                 bset    %lo(_default_pset), %o0
F0065240: 400027d7                 call    _pset_reference
F0065244: d0264000                 st      %o0, [%i1]
F0065248: 10800003                 ba      locret_F0065254
F006524C: b0102000                 mov     0, %i0
F0065250: b0102004                 mov     4, %i0
F0065254: 81c7e008                 ret
F0065258: 81e80000                 restore
