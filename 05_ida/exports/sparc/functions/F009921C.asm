F009921C: 9de3bf98                 save    %sp, -0x68, %sp
F0099220: d0062008                 ld      [%i0+8], %o0! __s1
F0099224: 80a22000                 cmp     %o0, 0
F0099228: 12800004                 bne     loc_F0099238
F009922C: 01000000                 nop
F0099230: 1080000e                 ba      loc_F0099268
F0099234: f2262008                 st      %i1, [%i0+8]
F0099238: 7ffdbbdd                 call    _strcmp
F009923C: 92100019                 mov     %i1, %o1
F0099240: 80a22000                 cmp     %o0, 0
F0099244: 02800009                 be      loc_F0099268
F0099248: 113c045b                 sethi   %hi(aAddionameCanTC), %o0! "addioname: can't change %s to %s!\n"
F009924C: 90122340                 bset    %lo(aAddionameCanTC), %o0! "addioname: can't change %s to %s!\n"
F0099250: d2062008                 ld      [%i0+8], %o1
F0099254: 7ffded01                 call    _printf
F0099258: 94100019                 mov     %i1, %o2
F009925C: 113c045b                 sethi   %hi(aAddioname), %o0! "addioname"
F0099260: 7ffdefc4                 call    _panic
F0099264: 90122368                 bset    %lo(aAddioname), %o0! "addioname"
F0099268: d006200c                 ld      [%i0+0xC], %o0
F009926C: 90022001                 inc     %o0
F0099270: d026200c                 st      %o0, [%i0+0xC]
F0099274: 81c7e008                 ret
F0099278: 81e80000                 restore
