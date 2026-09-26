F006A374: 9de3bf98                 save    %sp, -0x68, %sp
F006A378: 7ffffff4                 call    _firstsect
F006A37C: 90100018                 mov     %i0, %o0
F006A380: 90264008                 sub     %i1, %o0, %o0
F006A384: 932a2004                 sll     %o0, 4, %o1
F006A388: 92224008                 sub     %o1, %o0, %o1
F006A38C: 912a6008                 sll     %o1, 8, %o0
F006A390: 92024008                 add     %o1, %o0, %o1
F006A394: 912a6010                 sll     %o1, 16, %o0
F006A398: 92024008                 add     %o1, %o0, %o1
F006A39C: 92200009                 neg     %o1
F006A3A0: d0062030                 ld      [%i0+0x30], %o0
F006A3A4: 933a6002                 sra     %o1, 2, %o1
F006A3A8: 90023fff                 inc     -1, %o0
F006A3AC: 80a24008                 cmp     %o1, %o0
F006A3B0: 1a800003                 bcc     locret_F006A3BC
F006A3B4: b0102000                 mov     0, %i0
F006A3B8: b0066044                 add     %i1, 0x44, %i0 ! 'D'
F006A3BC: 81c7e008                 ret
F006A3C0: 81e80000                 restore
