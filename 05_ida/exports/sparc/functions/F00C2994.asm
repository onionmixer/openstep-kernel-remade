F00C2994: 9de3bf98                 save    %sp, -0x68, %sp
F00C2998: 113c0484                 sethi   %hi(_ms_speedlimit), %o0
F00C299C: d802211c                 ld      [%o0+%lo(_ms_speedlimit)], %o4
F00C29A0: e0060000                 ld      [%i0], %l0
F00C29A4: d0062018                 ld      [%i0+0x18], %o0
F00C29A8: a8100018                 mov     %i0, %l4
F00C29AC: 80a42000                 cmp     %l0, 0
F00C29B0: 02800083                 be      locret_F00C2BBC
F00C29B4: ea022034                 ld      [%o0+0x34], %l5
F00C29B8: d2542002                 ldsh    [%l0+2], %o1
F00C29BC: 912a6001                 sll     %o1, 1, %o0
F00C29C0: 90020009                 add     %o0, %o1, %o0
F00C29C4: 912a2002                 sll     %o0, 2, %o0
F00C29C8: 92022004                 add     %o0, 4, %o1
F00C29CC: 113c0484                 sethi   %hi(_ms_speedlaw), %o0
F00C29D0: d0022120                 ld      [%o0+%lo(_ms_speedlaw)], %o0
F00C29D4: 80a22000                 cmp     %o0, 0
F00C29D8: 0280003f                 be      loc_F00C2AD4
F00C29DC: 96040009                 add     %l0, %o1, %o3
F00C29E0: d056201c                 ldsh    [%i0+0x1C], %o0
F00C29E4: 80a22000                 cmp     %o0, 0
F00C29E8: 32800002                 bne,a   loc_F00C29F0
F00C29EC: 992b2001                 sll     %o4, 1, %o4
F00C29F0: d44c0009                 ldsb    [%l0+%o1], %o2
F00C29F4: 80a2a000                 cmp     %o2, 0
F00C29F8: 26800002                 bl,a    loc_F00C2A00
F00C29FC: 9420000a                 neg     %o2
F00C2A00: da4ae001                 ldsb    [%o3+1], %o5
F00C2A04: 80a36000                 cmp     %o5, 0
F00C2A08: 26800002                 bl,a    loc_F00C2A10
F00C2A0C: 9a20000d                 neg     %o5
F00C2A10: 80a2800c                 cmp     %o2, %o4
F00C2A14: 14800005                 bg      loc_F00C2A28
F00C2A18: 133c04fd                 sethi   -0xFEC0C00, %o1
F00C2A1C: 80a3400c                 cmp     %o5, %o4
F00C2A20: 04800006                 ble     loc_F00C2A38
F00C2A24: 80a2800c                 cmp     %o2, %o4
F00C2A28: d0026340                 ld      [%o1+0x340], %o0
F00C2A2C: 90022001                 inc     %o0
F00C2A30: d0226340                 st      %o0, [%o1+0x340]
F00C2A34: 80a2800c                 cmp     %o2, %o4
F00C2A38: 04800013                 ble     loc_F00C2A84
F00C2A3C: 9022800c                 sub     %o2, %o4, %o0
F00C2A40: d44ac000                 ldsb    [%o3], %o2
F00C2A44: 80a2a000                 cmp     %o2, 0
F00C2A48: 04800004                 ble     loc_F00C2A58
F00C2A4C: 933a2001                 sra     %o0, 1, %o1
F00C2A50: 10800003                 ba      loc_F00C2A5C
F00C2A54: 92228009                 sub     %o2, %o1, %o1
F00C2A58: 9202400a                 add     %o1, %o2, %o1
F00C2A5C: 113c0484                 sethi   %hi(_ms_maxspeed), %o0
F00C2A60: d0022124                 ld      [%o0+%lo(_ms_maxspeed)], %o0
F00C2A64: 80a24008                 cmp     %o1, %o0
F00C2A68: 34800007                 bg,a    loc_F00C2A84
F00C2A6C: d02ac000                 stb     %o0, [%o3]
F00C2A70: 90200008                 neg     %o0
F00C2A74: 80a24008                 cmp     %o1, %o0
F00C2A78: 36800002                 bge,a   loc_F00C2A80
F00C2A7C: 90100009                 mov     %o1, %o0
F00C2A80: d02ac000                 stb     %o0, [%o3]
F00C2A84: 80a3400c                 cmp     %o5, %o4
F00C2A88: 04800013                 ble     loc_F00C2AD4
F00C2A8C: 9023400c                 sub     %o5, %o4, %o0
F00C2A90: d44ae001                 ldsb    [%o3+1], %o2
F00C2A94: 80a2a000                 cmp     %o2, 0
F00C2A98: 04800004                 ble     loc_F00C2AA8
F00C2A9C: 933a2001                 sra     %o0, 1, %o1
F00C2AA0: 10800003                 ba      loc_F00C2AAC
F00C2AA4: 92228009                 sub     %o2, %o1, %o1
F00C2AA8: 9202400a                 add     %o1, %o2, %o1
F00C2AAC: 113c0484                 sethi   %hi(_ms_maxspeed), %o0
F00C2AB0: d0022124                 ld      [%o0+%lo(_ms_maxspeed)], %o0
F00C2AB4: 80a24008                 cmp     %o1, %o0
F00C2AB8: 34800007                 bg,a    loc_F00C2AD4
F00C2ABC: d02ae001                 stb     %o0, [%o3+1]
F00C2AC0: 90200008                 neg     %o0
F00C2AC4: 80a24008                 cmp     %o1, %o0
F00C2AC8: 36800002                 bge,a   loc_F00C2AD0
F00C2ACC: 90100009                 mov     %o1, %o0
F00C2AD0: d02ae001                 stb     %o0, [%o3+1]
F00C2AD4: d055201c                 ldsh    [%l4+0x1C], %o0
F00C2AD8: 80a22000                 cmp     %o0, 0
F00C2ADC: 0280000e                 be      loc_F00C2B14
F00C2AE0: e60ae002                 ldub    [%o3+2], %l3
F00C2AE4: d00ac000                 ldub    [%o3], %o0
F00C2AE8: d20ae001                 ldub    [%o3+1], %o1
F00C2AEC: a20a2001                 and     %o0, 1, %l1
F00C2AF0: a40a6001                 and     %o1, 1, %l2
F00C2AF4: 912a2018                 sll     %o0, 24, %o0
F00C2AF8: 913a2019                 sra     %o0, 25, %o0
F00C2AFC: d20ae001                 ldub    [%o3+1], %o1
F00C2B00: d02ac000                 stb     %o0, [%o3]
F00C2B04: 932a6018                 sll     %o1, 24, %o1
F00C2B08: 933a6019                 sra     %o1, 25, %o1
F00C2B0C: 10800004                 ba      loc_F00C2B1C
F00C2B10: d22ae001                 stb     %o1, [%o3+1]
F00C2B14: a4102000                 mov     0, %l2
F00C2B18: a2102000                 mov     0, %l1
F00C2B1C: d0142002                 lduh    [%l0+2], %o0
F00C2B20: d2540000                 ldsh    [%l0], %o1
F00C2B24: 90022001                 inc     %o0
F00C2B28: d0342002                 sth     %o0, [%l0+2]
F00C2B2C: 912a2010                 sll     %o0, 16, %o0
F00C2B30: 913a2010                 sra     %o0, 16, %o0
F00C2B34: 80a20009                 cmp     %o0, %o1
F00C2B38: 06800004                 bl      loc_F00C2B48
F00C2B3C: 9602e00c                 inc     0xC, %o3
F00C2B40: c0342002                 clrh    [%l0+2]
F00C2B44: 96042004                 add     %l0, 4, %o3
F00C2B48: d2542002                 ldsh    [%l0+2], %o1
F00C2B4C: d0562008                 ldsh    [%i0+8], %o0
F00C2B50: 80a24008                 cmp     %o1, %o0
F00C2B54: 32800011                 bne,a   loc_F00C2B98
F00C2B58: e62ae002                 stb     %l3, [%o3+2]
F00C2B5C: 113c04fd                 sethi   %hi(_ms_overrun_msg), %o0
F00C2B60: d0022338                 ld      [%o0+%lo(_ms_overrun_msg)], %o0
F00C2B64: 80a22000                 cmp     %o0, 0
F00C2B68: 02800004                 be      loc_F00C2B78
F00C2B6C: 113c0484                 sethi   %hi(aMouseBufferFlu), %o0! "Mouse buffer flushed when overrun.\n"
F00C2B70: 7ffd46ba                 call    _printf
F00C2B74: 90122288                 bset    %lo(aMouseBufferFlu), %o0! "Mouse buffer flushed when overrun.\n"
F00C2B78: 7ffffec8                 call    sub_F00C2698
F00C2B7C: 90100014                 mov     %l4, %o0
F00C2B80: 133c04fd                 sethi   %hi(_ms_overrun_cnt), %o1
F00C2B84: d0026330                 ld      [%o1+%lo(_ms_overrun_cnt)], %o0
F00C2B88: 96042004                 add     %l0, 4, %o3
F00C2B8C: 90022001                 inc     %o0
F00C2B90: d0226330                 st      %o0, [%o1+%lo(_ms_overrun_cnt)]
F00C2B94: e62ae002                 stb     %l3, [%o3+2]
F00C2B98: e22ac000                 stb     %l1, [%o3]
F00C2B9C: e42ae001                 stb     %l2, [%o3+1]
F00C2BA0: d0056034                 ld      [%l5+0x34], %o0
F00C2BA4: 80a22000                 cmp     %o0, 0
F00C2BA8: 02800005                 be      locret_F00C2BBC
F00C2BAC: 01000000                 nop
F00C2BB0: d2056038                 ld      [%l5+0x38], %o1
F00C2BB4: 7ffffd0d                 call    _MouseIntHandler
F00C2BB8: 94100018                 mov     %i0, %o2
F00C2BBC: 81c7e008                 ret
F00C2BC0: 81e80000                 restore
