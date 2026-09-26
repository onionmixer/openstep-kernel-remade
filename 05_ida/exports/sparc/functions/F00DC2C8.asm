F00DC2C8: 9de3bf90                 save    %sp, -0x70, %sp
F00DC2CC: d006a008                 ld      [%i2+8], %o0
F00DC2D0: da06a00c                 ld      [%i2+0xC], %o5
F00DC2D4: 80a72000                 cmp     %i4, 0
F00DC2D8: 02800040                 be      loc_F00DC3D8
F00DC2DC: a022000d                 sub     %o0, %o5, %l0
F00DC2E0: 80a42000                 cmp     %l0, 0
F00DC2E4: 2280003e                 be,a    loc_F00DC3DC
F00DC2E8: d006a024                 ld      [%i2+0x24], %o0
F00DC2EC: d4074000                 ld      [%i5], %o2
F00DC2F0: 90028010                 add     %o2, %l0, %o0
F00DC2F4: 80a2001c                 cmp     %o0, %i4
F00DC2F8: 38800002                 bgu,a   loc_F00DC300
F00DC2FC: a027000a                 sub     %i4, %o2, %l0
F00DC300: d006e004                 ld      [%i3+4], %o0
F00DC304: 9810000d                 mov     %o5, %o4
F00DC308: d6062068                 ld      [%i0+0x68], %o3
F00DC30C: 80a2e000                 cmp     %o3, 0
F00DC310: 1280000f                 bne     loc_F00DC34C
F00DC314: 9202000a                 add     %o0, %o2, %o1
F00DC318: 9b342001                 srl     %l0, 1, %o5
F00DC31C: 80a2c00d                 cmp     %o3, %o5
F00DC320: 1a800025                 bcc     loc_F00DC3B4
F00DC324: 94102000                 mov     0, %o2
F00DC328: 9402a001                 inc     %o2
F00DC32C: d0124000                 lduh    [%o1], %o0
F00DC330: 80a2800d                 cmp     %o2, %o5
F00DC334: 92026002                 inc     2, %o1
F00DC338: d0330000                 sth     %o0, [%o4]
F00DC33C: 0abffffb                 bcs     loc_F00DC328
F00DC340: 98032002                 inc     2, %o4
F00DC344: 1080001d                 ba      loc_F00DC3B8
F00DC348: d0074000                 ld      [%i5], %o0
F00DC34C: 80a2e003                 cmp     %o3, 3
F00DC350: 12800013                 bne     loc_F00DC39C
F00DC354: 80a2e001                 cmp     %o3, 1
F00DC358: 98100009                 mov     %o1, %o4
F00DC35C: 94102000                 mov     0, %o2! size_t
F00DC360: 80a28010                 cmp     %o2, %l0
F00DC364: 1a800014                 bcc     loc_F00DC3B4
F00DC368: 9610000d                 mov     %o5, %o3
F00DC36C: 9402a001                 inc     %o2
F00DC370: d20b0000                 ldub    [%o4], %o1
F00DC374: 80a28010                 cmp     %o2, %l0
F00DC378: 901a7f80                 xor     %o1, -0x80, %o0
F00DC37C: 920a607f                 and     %o1, 0x7F, %o1
F00DC380: 90120009                 bset    %o1, %o0
F00DC384: d02ac000                 stb     %o0, [%o3]
F00DC388: 9602e001                 inc     %o3
F00DC38C: 0abffff8                 bcs     loc_F00DC36C
F00DC390: 98032001                 inc     %o4
F00DC394: 10800009                 ba      loc_F00DC3B8
F00DC398: d0074000                 ld      [%i5], %o0
F00DC39C: 32800007                 bne,a   loc_F00DC3B8
F00DC3A0: d0074000                 ld      [%i5], %o0
F00DC3A4: 90100009                 mov     %o1, %o0! void *
F00DC3A8: 9210000d                 mov     %o5, %o1! void *
F00DC3AC: 7ffee1d9                 call    _bcopy
F00DC3B0: 94100010                 mov     %l0, %o2
F00DC3B4: d0074000                 ld      [%i5], %o0
F00DC3B8: 90020010                 add     %o0, %l0, %o0
F00DC3BC: d0274000                 st      %o0, [%i5]
F00DC3C0: d006a00c                 ld      [%i2+0xC], %o0
F00DC3C4: 90020010                 add     %o0, %l0, %o0
F00DC3C8: d026a00c                 st      %o0, [%i2+0xC]
F00DC3CC: d0062020                 ld      [%i0+0x20], %o0
F00DC3D0: 90020010                 add     %o0, %l0, %o0
F00DC3D4: d0262020                 st      %o0, [%i0+0x20]
F00DC3D8: d006a024                 ld      [%i2+0x24], %o0
F00DC3DC: 80a2001b                 cmp     %o0, %i3
F00DC3E0: 02800006                 be      loc_F00DC3F8
F00DC3E4: 90100018                 mov     %i0, %o0
F00DC3E8: d006a030                 ld      [%i2+0x30], %o0
F00DC3EC: 80a22000                 cmp     %o0, 0
F00DC3F0: 02800006                 be      locret_F00DC408
F00DC3F4: 90100018                 mov     %i0, %o0! id
F00DC3F8: 133c0505                 sethi   %hi(paSendrecordedda), %o1
F00DC3FC: d2026038                 ld      [%o1+%lo(paSendrecordedda)], %o1! SEL
F00DC400: 4000551c                 call    _objc_msgSend
F00DC404: 9410001a                 mov     %i2, %o2
F00DC408: 81c7e008                 ret
F00DC40C: 81e80000                 restore
