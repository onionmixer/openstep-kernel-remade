F00D0208: 9de3bf90                 save    %sp, -0x70, %sp
F00D020C: 113c0506                 sethi   %hi(paLastreadystate_0), %o0! id
F00D0210: d202217c                 ld      [%o0+%lo(paLastreadystate_0)], %o1! SEL
F00D0214: 40008597                 call    _objc_msgSend
F00D0218: 90100018                 mov     %i0, %o0
F00D021C: d40621b0                 ld      [%i0+0x1B0], %o2
F00D0220: 920621b0                 add     %i0, 0x1B0, %o1
F00D0224: 80a2400a                 cmp     %o1, %o2
F00D0228: 1280000e                 bne     loc_F00D0260
F00D022C: 94100008                 mov     %o0, %o2
F00D0230: d20621a8                 ld      [%i0+0x1A8], %o1
F00D0234: 900621a8                 add     %i0, 0x1A8, %o0
F00D0238: 80a20009                 cmp     %o0, %o1
F00D023C: 0280000b                 be      loc_F00D0268
F00D0240: 9002bffe                 add     %o2, -2, %o0
F00D0244: 80a22001                 cmp     %o0, 1
F00D0248: 08800009                 bleu    loc_F00D026C
F00D024C: a0102000                 mov     0, %l0
F00D0250: d04e21c8                 ldsb    [%i0+0x1C8], %o0
F00D0254: 80a22000                 cmp     %o0, 0
F00D0258: 32800006                 bne,a   loc_F00D0270
F00D025C: d00621b8                 ld      [%i0+0x1B8], %o0
F00D0260: 10800003                 ba      loc_F00D026C
F00D0264: a0102001                 mov     1, %l0
F00D0268: a0102000                 mov     0, %l0
F00D026C: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00D0270: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00D0274: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00D0278: 4000857e                 call    _objc_msgSend
F00D027C: 94100010                 mov     %l0, %o2
F00D0280: 80a42001                 cmp     %l0, 1
F00D0284: 12800004                 bne     locret_F00D0294
F00D0288: 01000000                 nop
F00D028C: 7ffe890d                 call    _thread_block
F00D0290: 01000000                 nop
F00D0294: 81c7e008                 ret
F00D0298: 81e80000                 restore
