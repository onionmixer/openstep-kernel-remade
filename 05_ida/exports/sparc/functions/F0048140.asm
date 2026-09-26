F0048140: 9de3bf98                 save    %sp, -0x68, %sp
F0048144: d0062028                 ld      [%i0+0x28], %o0
F0048148: 80a22004                 cmp     %o0, 4
F004814C: 02800005                 be      loc_F0048160
F0048150: f0062030                 ld      [%i0+0x30], %i0
F0048154: 113c0439                 sethi   %hi(aSpecIoctl), %o0! "spec_ioctl"
F0048158: 7fff3406                 call    _panic
F004815C: 901220a8                 bset    %lo(aSpecIoctl), %o0! "spec_ioctl"
F0048160: d2162042                 lduh    [%i0+0x42], %o1
F0048164: 9410001a                 mov     %i2, %o2
F0048168: 932a6010                 sll     %o1, 16, %o1
F004816C: 913a6010                 sra     %o1, 16, %o0
F0048170: 93326018                 srl     %o1, 24, %o1
F0048174: 972a6001                 sll     %o1, 1, %o3
F0048178: 9602c009                 add     %o3, %o1, %o3
F004817C: 972ae002                 sll     %o3, 2, %o3
F0048180: 9622c009                 sub     %o3, %o1, %o3
F0048184: 972ae002                 sll     %o3, 2, %o3
F0048188: 133c0472921261f0         set     _cdevsw, %o1
F0048190: 9602c009                 add     %o3, %o1, %o3
F0048194: d802e010                 ld      [%o3+0x10], %o4
F0048198: 92100019                 mov     %i1, %o1
F004819C: 9fc30000                 call    %o4
F00481A0: 9610001b                 mov     %i3, %o3
F00481A4: 81c7e008                 ret
F00481A8: 91e80008                 restore %g0, %o0, %o0
