F006A498: 9de3bf98                 save    %sp, -0x68, %sp
F006A49C: a0100018                 mov     %i0, %l0
F006A4A0: b0102000                 mov     0, %i0
F006A4A4: 7fffff4b                 call    _firstsegfromheader
F006A4A8: 90100010                 mov     %l0, %o0
F006A4AC: 1080000b                 ba      loc_F006A4D8
F006A4B0: 94100008                 mov     %o0, %o2
F006A4B4: d002a024                 ld      [%o2+0x24], %o0
F006A4B8: 92024008                 add     %o1, %o0, %o1
F006A4BC: 80a24018                 cmp     %o1, %i0
F006A4C0: 38800002                 bgu,a   loc_F006A4C8
F006A4C4: b0100009                 mov     %o1, %i0
F006A4C8: 90100010                 mov     %l0, %o0
F006A4CC: 7fffff64                 call    _nextsegfromheader
F006A4D0: 9210000a                 mov     %o2, %o1
F006A4D4: 94100008                 mov     %o0, %o2
F006A4D8: 80a2a000                 cmp     %o2, 0
F006A4DC: 32bffff6                 bne,a   loc_F006A4B4
F006A4E0: d202a020                 ld      [%o2+0x20], %o1
F006A4E4: 81c7e008                 ret
F006A4E8: 81e80000                 restore
