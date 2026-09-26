F00AF04C: 9de3bf98                 save    %sp, -0x68, %sp
F00AF050: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF054: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF058: 80a22000                 cmp     %o0, 0
F00AF05C: 1280000d                 bne     loc_F00AF090
F00AF060: 92100018                 mov     %i0, %o1
F00AF064: 80a26000                 cmp     %o1, 0
F00AF068: 32800005                 bne,a   loc_F00AF07C
F00AF06C: 113c000c                 sethi   -0xFFFD000, %o0
F00AF070: 113c0470                 sethi   %hi(aNoticeNoObpV0C), %o0! "NOTICE: No OBP V0 CB handler registered"...
F00AF074: 10800011                 ba      loc_F00AF0B8
F00AF078: 90122180                 bset    %lo(aNoticeNoObpV0C), %o0! "NOTICE: No OBP V0 CB handler registered"...
F00AF07C: d0022030                 ld      [%o0+0x30], %o0
F00AF080: d0022078                 ld      [%o0+0x78], %o0
F00AF084: b0102000                 mov     0, %i0
F00AF088: 1080000e                 ba      locret_F00AF0C0
F00AF08C: d2220000                 st      %o1, [%o0]
F00AF090: 80a66000                 cmp     %i1, 0
F00AF094: 02800007                 be      loc_F00AF0B0
F00AF098: 113c000c                 sethi   %hi(_romp), %o0
F00AF09C: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF0A0: d0022078                 ld      [%o0+0x78], %o0
F00AF0A4: b0102000                 mov     0, %i0
F00AF0A8: 10800006                 ba      locret_F00AF0C0
F00AF0AC: f2220000                 st      %i1, [%o0]
F00AF0B0: 113c0470901221b0         set     aNoticeNoObpV2C, %o0! "NOTICE: No OBP V2 CB handler registered"...
F00AF0B8: 400001b0                 call    _prom_printf
F00AF0BC: b0103fff                 mov     -1, %i0
F00AF0C0: 81c7e008                 ret
F00AF0C4: 81e80000                 restore
