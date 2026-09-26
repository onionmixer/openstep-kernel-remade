F00D4250: 9de3bf90                 save    %sp, -0x70, %sp
F00D4254: d0062188                 ld      [%i0+0x188], %o0
F00D4258: a0102000                 mov     0, %l0
F00D425C: 80a40008                 cmp     %l0, %o0
F00D4260: 1680000c                 bge     locret_F00D4290
F00D4264: 233c0505                 sethi   -0xFEBEC00, %l1
F00D4268: 90100018                 mov     %i0, %o0! id
F00D426C: 94100010                 mov     %l0, %o2
F00D4270: d2046290                 ld      [%l1+0x290], %o1! SEL
F00D4274: 4000757f                 call    _objc_msgSend
F00D4278: 96102004                 mov     4, %o3
F00D427C: d0062188                 ld      [%i0+0x188], %o0
F00D4280: a0042001                 inc     %l0
F00D4284: 80a40008                 cmp     %l0, %o0
F00D4288: 06bffff9                 bl      loc_F00D426C
F00D428C: 90100018                 mov     %i0, %o0
F00D4290: 81c7e008                 ret
F00D4294: 81e80000                 restore
