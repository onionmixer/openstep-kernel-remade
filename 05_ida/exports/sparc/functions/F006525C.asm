F006525C: 9de3bf98                 save    %sp, -0x68, %sp
F0065260: 80a62000                 cmp     %i0, 0
F0065264: 02800007                 be      loc_F0065280
F0065268: 113c04d3                 sethi   %hi(_default_pset), %o0
F006526C: 901223c0                 bset    %lo(_default_pset), %o0
F0065270: 400027cb                 call    _pset_reference
F0065274: d0264000                 st      %o0, [%i1]
F0065278: 10800003                 ba      locret_F0065284
F006527C: b0102000                 mov     0, %i0
F0065280: b0102004                 mov     4, %i0
F0065284: 81c7e008                 ret
F0065288: 81e80000                 restore
