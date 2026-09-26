F00481AC: 9de3bf98                 save    %sp, -0x68, %sp
F00481B0: d0062028                 ld      [%i0+0x28], %o0
F00481B4: 80a22004                 cmp     %o0, 4
F00481B8: 02800005                 be      loc_F00481CC
F00481BC: f0062030                 ld      [%i0+0x30], %i0
F00481C0: 113c0439                 sethi   %hi(aSpecSelect), %o0! "spec_select"
F00481C4: 7fff33eb                 call    _panic
F00481C8: 901220b8                 bset    %lo(aSpecSelect), %o0! "spec_select"
F00481CC: d4162042                 lduh    [%i0+0x42], %o2
F00481D0: 952aa010                 sll     %o2, 16, %o2
F00481D4: 913aa010                 sra     %o2, 16, %o0
F00481D8: 9532a018                 srl     %o2, 24, %o2
F00481DC: 932aa001                 sll     %o2, 1, %o1
F00481E0: 9202400a                 add     %o1, %o2, %o1
F00481E4: 932a6002                 sll     %o1, 2, %o1
F00481E8: 9222400a                 sub     %o1, %o2, %o1
F00481EC: 932a6002                 sll     %o1, 2, %o1
F00481F0: 153c04729412a1f0         set     _cdevsw, %o2
F00481F8: 9202400a                 add     %o1, %o2, %o1
F00481FC: d402601c                 ld      [%o1+0x1C], %o2
F0048200: 9fc28000                 call    %o2
F0048204: 92100019                 mov     %i1, %o1
F0048208: 81c7e008                 ret
F004820C: 91e80008                 restore %g0, %o0, %o0
