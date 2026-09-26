F00439F8: 9de3bf98                 save    %sp, -0x68, %sp
F00439FC: d0060000                 ld      [%i0], %o0
F0043A00: 80a22000                 cmp     %o0, 0
F0043A04: 1280004b                 bne     loc_F0043B30
F0043A08: 80a22001                 cmp     %o0, 1
F0043A0C: d4066020                 ld      [%i1+0x20], %o2
F0043A10: 80a2a190                 cmp     %o2, 0x190
F0043A14: 388000fb                 bgu,a   locret_F0043E00
F0043A18: b0102000                 mov     0, %i0
F0043A1C: d206602c                 ld      [%i1+0x2C], %o1
F0043A20: 80a26190                 cmp     %o1, 0x190
F0043A24: 188000f6                 bgu     loc_F0043DFC
F0043A28: 90100018                 mov     %i0, %o0
F0043A2C: 9402a003                 inc     3, %o2
F0043A30: 940abffc                 and     %o2, -4, %o2
F0043A34: 92026003                 inc     3, %o1
F0043A38: 920a7ffc                 and     %o1, -4, %o1
F0043A3C: d6062004                 ld      [%i0+4], %o3
F0043A40: 92026028                 inc     0x28, %o1 ! '('
F0043A44: d602e018                 ld      [%o3+0x18], %o3
F0043A48: 9fc2c000                 call    %o3
F0043A4C: 92028009                 add     %o2, %o1, %o1! void *
F0043A50: a0920000                 orcc    %o0, %g0, %l0
F0043A54: 22800036                 be,a    loc_F0043B2C
F0043A58: d0060000                 ld      [%i0], %o0
F0043A5C: d0064000                 ld      [%i1], %o0
F0043A60: d0240000                 st      %o0, [%l0]
F0043A64: d0066004                 ld      [%i1+4], %o0
F0043A68: a0042004                 inc     4, %l0
F0043A6C: d0240000                 st      %o0, [%l0]
F0043A70: d0066004                 ld      [%i1+4], %o0
F0043A74: 80a22000                 cmp     %o0, 0
F0043A78: 128000e1                 bne     loc_F0043DFC
F0043A7C: a0042004                 inc     4, %l0
F0043A80: d0066008                 ld      [%i1+8], %o0
F0043A84: d0240000                 st      %o0, [%l0]
F0043A88: d0066008                 ld      [%i1+8], %o0
F0043A8C: 80a22002                 cmp     %o0, 2
F0043A90: 128000db                 bne     loc_F0043DFC
F0043A94: a0042004                 inc     4, %l0
F0043A98: d006600c                 ld      [%i1+0xC], %o0
F0043A9C: d0240000                 st      %o0, [%l0]
F0043AA0: d0066010                 ld      [%i1+0x10], %o0
F0043AA4: a0042004                 inc     4, %l0
F0043AA8: d0240000                 st      %o0, [%l0]
F0043AAC: d0066014                 ld      [%i1+0x14], %o0
F0043AB0: a0042004                 inc     4, %l0
F0043AB4: d0240000                 st      %o0, [%l0]
F0043AB8: d0066018                 ld      [%i1+0x18], %o0
F0043ABC: a0042004                 inc     4, %l0
F0043AC0: d0240000                 st      %o0, [%l0]
F0043AC4: d0066020                 ld      [%i1+0x20], %o0
F0043AC8: a0042004                 inc     4, %l0
F0043ACC: d0240000                 st      %o0, [%l0]
F0043AD0: d4066020                 ld      [%i1+0x20], %o2! size_t
F0043AD4: 80a2a000                 cmp     %o2, 0
F0043AD8: 02800009                 be      loc_F0043AFC
F0043ADC: a0042004                 inc     4, %l0
F0043AE0: d006601c                 ld      [%i1+0x1C], %o0! void *
F0043AE4: 4001440b                 call    _bcopy
F0043AE8: 92100010                 mov     %l0, %o1
F0043AEC: d0066020                 ld      [%i1+0x20], %o0
F0043AF0: 90022003                 inc     3, %o0
F0043AF4: 900a3ffc                 and     %o0, -4, %o0
F0043AF8: a0040008                 add     %l0, %o0, %l0
F0043AFC: d0066024                 ld      [%i1+0x24], %o0
F0043B00: d0240000                 st      %o0, [%l0]
F0043B04: d006602c                 ld      [%i1+0x2C], %o0
F0043B08: a0042004                 inc     4, %l0
F0043B0C: d0240000                 st      %o0, [%l0]
F0043B10: d406602c                 ld      [%i1+0x2C], %o2
F0043B14: 80a2a000                 cmp     %o2, 0
F0043B18: 02800086                 be      loc_F0043D30
F0043B1C: a0042004                 inc     4, %l0
F0043B20: d0066028                 ld      [%i1+0x28], %o0
F0043B24: 10800081                 ba      loc_F0043D28
F0043B28: 92100010                 mov     %l0, %o1
F0043B2C: 80a22001                 cmp     %o0, 1
F0043B30: 12800082                 bne     loc_F0043D38
F0043B34: 90100018                 mov     %i0, %o0
F0043B38: d2062004                 ld      [%i0+4], %o1
F0043B3C: d4026018                 ld      [%o1+0x18], %o2
F0043B40: 9fc28000                 call    %o2
F0043B44: 92102020                 mov     0x20, %o1 ! ' '
F0043B48: a0920000                 orcc    %o0, %g0, %l0
F0043B4C: 0280007b                 be      loc_F0043D38
F0043B50: 90100018                 mov     %i0, %o0
F0043B54: d0040000                 ld      [%l0], %o0
F0043B58: d0264000                 st      %o0, [%i1]
F0043B5C: a0042004                 inc     4, %l0
F0043B60: d0040000                 ld      [%l0], %o0
F0043B64: d0266004                 st      %o0, [%i1+4]
F0043B68: 80a22000                 cmp     %o0, 0
F0043B6C: 128000a4                 bne     loc_F0043DFC
F0043B70: a0042004                 inc     4, %l0
F0043B74: d0040000                 ld      [%l0], %o0
F0043B78: d0266008                 st      %o0, [%i1+8]
F0043B7C: 80a22002                 cmp     %o0, 2
F0043B80: 1280009f                 bne     loc_F0043DFC
F0043B84: a0042004                 inc     4, %l0
F0043B88: d0040000                 ld      [%l0], %o0
F0043B8C: d026600c                 st      %o0, [%i1+0xC]
F0043B90: a0042004                 inc     4, %l0
F0043B94: d0040000                 ld      [%l0], %o0
F0043B98: d0266010                 st      %o0, [%i1+0x10]
F0043B9C: a0042004                 inc     4, %l0
F0043BA0: d0040000                 ld      [%l0], %o0
F0043BA4: d0266014                 st      %o0, [%i1+0x14]
F0043BA8: a0042004                 inc     4, %l0
F0043BAC: d0040000                 ld      [%l0], %o0
F0043BB0: d0266018                 st      %o0, [%i1+0x18]
F0043BB4: d2042004                 ld      [%l0+4], %o1
F0043BB8: 80a26000                 cmp     %o1, 0
F0043BBC: 02800021                 be      loc_F0043C40
F0043BC0: d2266020                 st      %o1, [%i1+0x20]
F0043BC4: 80a26190                 cmp     %o1, 0x190
F0043BC8: 3880008e                 bgu,a   locret_F0043E00
F0043BCC: b0102000                 mov     0, %i0
F0043BD0: d006601c                 ld      [%i1+0x1C], %o0
F0043BD4: 80a22000                 cmp     %o0, 0
F0043BD8: 32800006                 bne,a   loc_F0043BF0
F0043BDC: d2066020                 ld      [%i1+0x20], %o1
F0043BE0: 40009124                 call    _kalloc
F0043BE4: 90100009                 mov     %o1, %o0
F0043BE8: d026601c                 st      %o0, [%i1+0x1C]
F0043BEC: d2066020                 ld      [%i1+0x20], %o1
F0043BF0: 90100018                 mov     %i0, %o0! XDR *
F0043BF4: d4062004                 ld      [%i0+4], %o2
F0043BF8: 92026003                 inc     3, %o1
F0043BFC: d402a018                 ld      [%o2+0x18], %o2
F0043C00: 9fc28000                 call    %o2
F0043C04: 920a7ffc                 and     %o1, -4, %o1
F0043C08: a0920000                 orcc    %o0, %g0, %l0
F0043C0C: 1280000a                 bne     loc_F0043C34
F0043C10: d206601c                 ld      [%i1+0x1C], %o1! char *
F0043C14: d4066020                 ld      [%i1+0x20], %o2! unsigned int
F0043C18: 400006d2                 call    _xdr_opaque
F0043C1C: 90100018                 mov     %i0, %o0! void *
F0043C20: 80a22000                 cmp     %o0, 0
F0043C24: 32800008                 bne,a   loc_F0043C44
F0043C28: d2062004                 ld      [%i0+4], %o1! void *
F0043C2C: 10800075                 ba      locret_F0043E00
F0043C30: b0102000                 mov     0, %i0
F0043C34: d4066020                 ld      [%i1+0x20], %o2! size_t
F0043C38: 400143b6                 call    _bcopy
F0043C3C: 90100010                 mov     %l0, %o0
F0043C40: d2062004                 ld      [%i0+4], %o1
F0043C44: d4026018                 ld      [%o1+0x18], %o2
F0043C48: 90100018                 mov     %i0, %o0
F0043C4C: 9fc28000                 call    %o2
F0043C50: 92102008                 mov     8, %o1! int *
F0043C54: a0920000                 orcc    %o0, %g0, %l0
F0043C58: 1280000f                 bne     loc_F0043C94
F0043C5C: a2066024                 add     %i1, 0x24, %l1 ! '$'
F0043C60: 90100018                 mov     %i0, %o0! XDR *
F0043C64: 400006b9                 call    _xdr_enum
F0043C68: 92100011                 mov     %l1, %o1! unsigned int *
F0043C6C: 80a22000                 cmp     %o0, 0
F0043C70: 02800063                 be      loc_F0043DFC
F0043C74: 90100018                 mov     %i0, %o0! XDR *
F0043C78: 400005fd                 call    _xdr_u_int
F0043C7C: 9206602c                 add     %i1, 0x2C, %o1 ! ','
F0043C80: 80a22000                 cmp     %o0, 0
F0043C84: 32800009                 bne,a   loc_F0043CA8
F0043C88: d2046008                 ld      [%l1+8], %o1
F0043C8C: 1080005d                 ba      locret_F0043E00
F0043C90: b0102000                 mov     0, %i0
F0043C94: d0040000                 ld      [%l0], %o0
F0043C98: d0266024                 st      %o0, [%i1+0x24]
F0043C9C: d0042004                 ld      [%l0+4], %o0
F0043CA0: d026602c                 st      %o0, [%i1+0x2C]
F0043CA4: d2046008                 ld      [%l1+8], %o1
F0043CA8: 80a26000                 cmp     %o1, 0
F0043CAC: 02800021                 be      loc_F0043D30
F0043CB0: 80a26190                 cmp     %o1, 0x190
F0043CB4: 38800053                 bgu,a   locret_F0043E00
F0043CB8: b0102000                 mov     0, %i0
F0043CBC: d0046004                 ld      [%l1+4], %o0
F0043CC0: 80a22000                 cmp     %o0, 0
F0043CC4: 32800006                 bne,a   loc_F0043CDC
F0043CC8: d2046008                 ld      [%l1+8], %o1
F0043CCC: 400090e9                 call    _kalloc
F0043CD0: 90100009                 mov     %o1, %o0
F0043CD4: d0246004                 st      %o0, [%l1+4]
F0043CD8: d2046008                 ld      [%l1+8], %o1
F0043CDC: 90100018                 mov     %i0, %o0! XDR *
F0043CE0: d4062004                 ld      [%i0+4], %o2
F0043CE4: 92026003                 inc     3, %o1
F0043CE8: d402a018                 ld      [%o2+0x18], %o2
F0043CEC: 9fc28000                 call    %o2
F0043CF0: 920a7ffc                 and     %o1, -4, %o1
F0043CF4: a0920000                 orcc    %o0, %g0, %l0
F0043CF8: 1280000a                 bne     loc_F0043D20
F0043CFC: d2046004                 ld      [%l1+4], %o1! void *
F0043D00: d4046008                 ld      [%l1+8], %o2! unsigned int
F0043D04: 40000697                 call    _xdr_opaque
F0043D08: 90100018                 mov     %i0, %o0
F0043D0C: 80a22000                 cmp     %o0, 0
F0043D10: 1280003c                 bne     locret_F0043E00
F0043D14: b0102001                 mov     1, %i0
F0043D18: 1080003a                 ba      locret_F0043E00
F0043D1C: b0102000                 mov     0, %i0
F0043D20: d4046008                 ld      [%l1+8], %o2! size_t
F0043D24: 90100010                 mov     %l0, %o0! void *
F0043D28: 4001437a                 call    _bcopy
F0043D2C: 01000000                 nop
F0043D30: 10800034                 ba      locret_F0043E00
F0043D34: b0102001                 mov     1, %i0
F0043D38: 400005ed                 call    _xdr_u_long
F0043D3C: 92100019                 mov     %i1, %o1! int *
F0043D40: 80a22000                 cmp     %o0, 0
F0043D44: 0280002e                 be      loc_F0043DFC
F0043D48: 90100018                 mov     %i0, %o0! XDR *
F0043D4C: 4000067f                 call    _xdr_enum
F0043D50: 92066004                 add     %i1, 4, %o1! unsigned __int32 *
F0043D54: 80a22000                 cmp     %o0, 0
F0043D58: 2280002a                 be,a    locret_F0043E00
F0043D5C: b0102000                 mov     0, %i0
F0043D60: d0066004                 ld      [%i1+4], %o0
F0043D64: 80a22000                 cmp     %o0, 0
F0043D68: 32800026                 bne,a   locret_F0043E00
F0043D6C: b0102000                 mov     0, %i0
F0043D70: 90100018                 mov     %i0, %o0! XDR *
F0043D74: 400005de                 call    _xdr_u_long
F0043D78: 92066008                 add     %i1, 8, %o1! unsigned __int32 *
F0043D7C: 80a22000                 cmp     %o0, 0
F0043D80: 22800020                 be,a    locret_F0043E00
F0043D84: b0102000                 mov     0, %i0
F0043D88: d0066008                 ld      [%i1+8], %o0
F0043D8C: 80a22002                 cmp     %o0, 2
F0043D90: 3280001c                 bne,a   locret_F0043E00
F0043D94: b0102000                 mov     0, %i0
F0043D98: 90100018                 mov     %i0, %o0! XDR *
F0043D9C: 400005d4                 call    _xdr_u_long
F0043DA0: 9206600c                 add     %i1, 0xC, %o1! unsigned __int32 *
F0043DA4: 80a22000                 cmp     %o0, 0
F0043DA8: 02800015                 be      loc_F0043DFC
F0043DAC: 90100018                 mov     %i0, %o0! XDR *
F0043DB0: 400005cf                 call    _xdr_u_long
F0043DB4: 92066010                 add     %i1, 0x10, %o1! unsigned __int32 *
F0043DB8: 80a22000                 cmp     %o0, 0
F0043DBC: 02800010                 be      loc_F0043DFC
F0043DC0: 90100018                 mov     %i0, %o0! XDR *
F0043DC4: 400005ca                 call    _xdr_u_long
F0043DC8: 92066014                 add     %i1, 0x14, %o1
F0043DCC: 80a22000                 cmp     %o0, 0
F0043DD0: 0280000b                 be      loc_F0043DFC
F0043DD4: 90100018                 mov     %i0, %o0
F0043DD8: 4000000c                 call    _xdr_opaque_auth
F0043DDC: 92066018                 add     %i1, 0x18, %o1
F0043DE0: 80a22000                 cmp     %o0, 0
F0043DE4: 02800006                 be      loc_F0043DFC
F0043DE8: 90100018                 mov     %i0, %o0
F0043DEC: 40000007                 call    _xdr_opaque_auth
F0043DF0: 92066024                 add     %i1, 0x24, %o1 ! '$'
F0043DF4: 10800003                 ba      locret_F0043E00
F0043DF8: b0100008                 mov     %o0, %i0
F0043DFC: b0102000                 mov     0, %i0
F0043E00: 81c7e008                 ret
F0043E04: 81e80000                 restore
