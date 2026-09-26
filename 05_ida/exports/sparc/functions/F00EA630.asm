F00EA630: 9de3bf90                 save    %sp, -0x70, %sp
F00EA634: 113c0504921220f8         set     paFreekeysValues, %o1! SEL
F00EA63C: d0062008                 ld      [%i0+8], %o0
F00EA640: d04a0000                 ldsb    [%o0], %o0
F00EA644: 80a22040                 cmp     %o0, 0x40 ! '@'
F00EA648: 12800005                 bne     loc_F00EA65C
F00EA64C: 96100018                 mov     %i0, %o3
F00EA650: 113c03a8                 sethi   %hi(sub_F00EA3AC), %o0
F00EA654: 10800004                 ba      loc_F00EA664
F00EA658: 941223ac                 or      %o0, %lo(sub_F00EA3AC), %o2
F00EA65C: 113c03a8941223c8         set     nullsub_1, %o2
F00EA664: d002e00c                 ld      [%o3+0xC], %o0
F00EA668: d04a0000                 ldsb    [%o0], %o0
F00EA66C: 80a22040                 cmp     %o0, 0x40 ! '@'
F00EA670: 12800005                 bne     loc_F00EA684
F00EA674: 113c03a8                 sethi   -0xFF16000, %o0
F00EA678: 113c03a8                 sethi   %hi(sub_F00EA3AC), %o0
F00EA67C: 10800003                 ba      loc_F00EA688
F00EA680: 961223ac                 or      %o0, %lo(sub_F00EA3AC), %o3
F00EA684: 961223c8                 or      %o0, 0x3C8, %o3
F00EA688: 90100018                 mov     %i0, %o0! id
F00EA68C: 40001c79                 call    _objc_msgSend
F00EA690: d2024000                 ld      [%o1], %o1
F00EA694: 81c7e008                 ret
F00EA698: 91e80008                 restore %g0, %o0, %o0
