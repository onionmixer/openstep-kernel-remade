F00C8324: 9de3bf98                 save    %sp, -0x68, %sp
F00C8328: 113c0506                 sethi   %hi(paIsphysical_0), %o0! id
F00C832C: d202218c                 ld      [%o0+%lo(paIsphysical_0)], %o1! SEL
F00C8330: 4000a550                 call    _objc_msgSend
F00C8334: 90100018                 mov     %i0, %o0
F00C8338: 912a2018                 sll     %o0, 24, %o0
F00C833C: 80a22000                 cmp     %o0, 0
F00C8340: 1280000c                 bne     loc_F00C8370
F00C8344: 90102000                 mov     0, %o0
F00C8348: 90100018                 mov     %i0, %o0! id
F00C834C: 133c0504                 sethi   %hi(paName), %o1
F00C8350: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C8354: 213c03eb                 sethi   %hi(aVolcheckregist), %l0! "volCheckRegister: %s is not a physical "...
F00C8358: 4000a546                 call    _objc_msgSend
F00C835C: a0142348                 bset    %lo(aVolcheckregist), %l0! "volCheckRegister: %s is not a physical "...
F00C8360: 92100008                 mov     %o0, %o1
F00C8364: 7ffff764                 call    _IOLog
F00C8368: 90100010                 mov     %l0, %o0
F00C836C: 30800008                 ba,a    locret_F00C838C
F00C8370: 92100018                 mov     %i0, %o1
F00C8374: 972e6010                 sll     %i1, 16, %o3
F00C8378: 992ea010                 sll     %i2, 16, %o4
F00C837C: 94102000                 mov     0, %o2
F00C8380: 973ae010                 sra     %o3, 16, %o3
F00C8384: 40000028                 call    sub_F00C8424
F00C8388: 993b2010                 sra     %o4, 16, %o4
F00C838C: 81c7e008                 ret
F00C8390: 81e80000                 restore
