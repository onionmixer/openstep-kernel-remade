F001D5F8: 9de3bf98                 save    %sp, -0x68, %sp
F001D5FC: 113c04d4                 sethi   %hi(_domains), %o0
F001D600: e20222b8                 ld      [%o0+%lo(_domains)], %l1
F001D604: 80a46000                 cmp     %l1, 0
F001D608: 02800017                 be      loc_F001D664
F001D60C: 113c043e                 sethi   -0xFEF0800, %o0
F001D610: e0046014                 ld      [%l1+0x14], %l0
F001D614: d0046018                 ld      [%l1+0x18], %o0
F001D618: 80a40008                 cmp     %l0, %o0
F001D61C: 3a80000e                 bcc,a   loc_F001D654
F001D620: e204601c                 ld      [%l1+0x1C], %l1
F001D624: d0042024                 ld      [%l0+0x24], %o0
F001D628: 80a22000                 cmp     %o0, 0
F001D62C: 22800005                 be,a    loc_F001D640
F001D630: d0046018                 ld      [%l1+0x18], %o0
F001D634: 9fc20000                 call    %o0
F001D638: 01000000                 nop
F001D63C: d0046018                 ld      [%l1+0x18], %o0
F001D640: a0042030                 inc     0x30, %l0 ! '0'
F001D644: 80a40008                 cmp     %l0, %o0
F001D648: 2abffff8                 bcs,a   loc_F001D628
F001D64C: d0042024                 ld      [%l0+0x24], %o0
F001D650: e204601c                 ld      [%l1+0x1C], %l1
F001D654: 80a46000                 cmp     %l1, 0
F001D658: 32bfffef                 bne,a   loc_F001D614
F001D65C: e0046014                 ld      [%l1+0x14], %l0
F001D660: 113c043e                 sethi   -0xFEF0800, %o0
F001D664: d00223e0                 ld      [%o0+0x3E0], %o0! int
F001D668: 92102005                 mov     5, %o1! int
F001D66C: 213c0075                 sethi   %hi(_pffasttimo), %l0
F001D670: 7fffa3e6                 call    _div
F001D674: a01421f8                 bset    %lo(_pffasttimo), %l0
F001D678: 94100008                 mov     %o0, %o2
F001D67C: 90100010                 mov     %l0, %o0! int
F001D680: 7fffb26a                 call    _timeout
F001D684: 92102000                 mov     0, %o1
F001D688: 81c7e008                 ret
F001D68C: 81e80000                 restore
