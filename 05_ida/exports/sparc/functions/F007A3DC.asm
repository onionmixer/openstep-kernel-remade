F007A3DC: 9de3bf98                 save    %sp, -0x68, %sp
F007A3E0: a0100018                 mov     %i0, %l0
F007A3E4: d20664b4                 ld      [%i1+0x4B4], %o1
F007A3E8: 80a66000                 cmp     %i1, 0
F007A3EC: 12800004                 bne     loc_F007A3FC
F007A3F0: b0103f38                 mov     -0xC8, %i0
F007A3F4: 10800027                 ba      locret_F007A490
F007A3F8: b0103ed1                 mov     -0x12F, %i0
F007A3FC: d404200c                 ld      [%l0+0xC], %o2
F007A400: d00664ac                 ld      [%i1+0x4AC], %o0
F007A404: 80a28008                 cmp     %o2, %o0
F007A408: 32800004                 bne,a   loc_F007A418
F007A40C: d00664b0                 ld      [%i1+0x4B0], %o0
F007A410: 1080001a                 ba      loc_F007A478
F007A414: b0103ed1                 mov     -0x12F, %i0
F007A418: 80a28008                 cmp     %o2, %o0
F007A41C: 02800011                 be      loc_F007A460
F007A420: 9610000a                 mov     %o2, %o3
F007A424: 92102000                 mov     0, %o1
F007A428: 94100019                 mov     %i1, %o2
F007A42C: d002a18c                 ld      [%o2+0x18C], %o0
F007A430: 80a2000b                 cmp     %o0, %o3
F007A434: 02800007                 be      loc_F007A450
F007A438: 80a26032                 cmp     %o1, 0x32 ! '2'
F007A43C: 92026001                 inc     %o1
F007A440: 80a26031                 cmp     %o1, 0x31 ! '1'
F007A444: 04bffffa                 ble     loc_F007A42C
F007A448: 9402a010                 inc     0x10, %o2
F007A44C: 80a26032                 cmp     %o1, 0x32 ! '2'
F007A450: 0280000b                 be      loc_F007A47C
F007A454: 80a63f38                 cmp     %i0, -0xC8
F007A458: d62664b0                 st      %o3, [%i1+0x4B0]
F007A45C: d22664b4                 st      %o1, [%i1+0x4B4]
F007A460: 90100010                 mov     %l0, %o0
F007A464: 932a6004                 sll     %o1, 4, %o1
F007A468: 9202618c                 inc     0x18C, %o1
F007A46C: 7fffffb9                 call    sub_F007A350
F007A470: 92064009                 add     %i1, %o1, %o1
F007A474: b0100008                 mov     %o0, %i0
F007A478: 80a63f38                 cmp     %i0, -0xC8
F007A47C: 12800005                 bne     locret_F007A490
F007A480: 01000000                 nop
F007A484: d004200c                 ld      [%l0+0xC], %o0
F007A488: b0103ed1                 mov     -0x12F, %i0
F007A48C: d02664ac                 st      %o0, [%i1+0x4AC]
F007A490: 81c7e008                 ret
F007A494: 81e80000                 restore
