F0044A34: 9de3bf48                 save    %sp, -0xB8, %sp
F0044A38: 133c04eb                 sethi   %hi(_rqcred_head), %o1
F0044A3C: d0026068                 ld      [%o1+%lo(_rqcred_head)], %o0
F0044A40: 80a22000                 cmp     %o0, 0
F0044A44: 0280000b                 be      loc_F0044A70
F0044A48: a0100008                 mov     %o0, %l0
F0044A4C: d0040000                 ld      [%l0], %o0
F0044A50: 1080000b                 ba      loc_F0044A7C
F0044A54: d0226068                 st      %o0, [%o1+%lo(_rqcred_head)]
F0044A58: d0062008                 ld      [%i0+8], %o0
F0044A5C: d2022014                 ld      [%o0+0x14], %o1
F0044A60: 9fc24000                 call    %o1
F0044A64: 90100018                 mov     %i0, %o0
F0044A68: 10800061                 ba      loc_F0044BEC
F0044A6C: 133c04eb                 sethi   -0xFEC5400, %o1
F0044A70: 40008d80                 call    _kalloc
F0044A74: 901024b0                 mov     0x4B0, %o0
F0044A78: a0100008                 mov     %o0, %l0
F0044A7C: e027bfe4                 st      %l0, [%fp+var_1C]
F0044A80: 90042190                 add     %l0, 0x190, %o0
F0044A84: d027bff0                 st      %o0, [%fp+var_10]
F0044A88: 90042320                 add     %l0, 0x320, %o0
F0044A8C: d027bfc0                 st      %o0, [%fp+var_40]
F0044A90: a207bfc8                 add     %fp, var_38, %l1
F0044A94: d2062008                 ld      [%i0+8], %o1
F0044A98: d4024000                 ld      [%o1], %o2
F0044A9C: 90100018                 mov     %i0, %o0
F0044AA0: 9fc28000                 call    %o2
F0044AA4: 92100011                 mov     %l1, %o1
F0044AA8: 80a22000                 cmp     %o0, 0
F0044AAC: 02800046                 be      loc_F0044BC4
F0044AB0: 92100011                 mov     %l1, %o1! rpc_msg *
F0044AB4: f027bfc4                 st      %i0, [%fp+var_3C]
F0044AB8: d407bfd4                 ld      [%fp+var_2C], %o2
F0044ABC: 9007bfa8                 add     %fp, var_58, %o0! svc_req *
F0044AC0: d607bfd8                 ld      [%fp+var_28], %o3
F0044AC4: d807bfe4                 ld      [%fp+var_1C], %o4
F0044AC8: d43fbfa8                 std     %o2, [%fp+var_58]
F0044ACC: d407bfdc                 ld      [%fp+var_24], %o2
F0044AD0: d827bfb8                 st      %o4, [%fp+var_48]
F0044AD4: d607bfe0                 ld      [%fp+var_20], %o3
F0044AD8: d427bfb0                 st      %o2, [%fp+var_50]
F0044ADC: d407bfe8                 ld      [%fp+var_18], %o2
F0044AE0: d627bfb4                 st      %o3, [%fp+var_4C]
F0044AE4: 40000061                 call    __authenticate
F0044AE8: d427bfbc                 st      %o2, [%fp+var_44]
F0044AEC: 92920000                 orcc    %o0, %g0, %o1! auth_stat
F0044AF0: 02800006                 be      loc_F0044B08
F0044AF4: 98102000                 mov     0, %o4
F0044AF8: 7fffff95                 call    _svcerr_auth
F0044AFC: 90100018                 mov     %i0, %o0
F0044B00: 10800032                 ba      loc_F0044BC8
F0044B04: d0062008                 ld      [%i0+8], %o0
F0044B08: 92103fff                 mov     -1, %o1
F0044B0C: 113c04bd                 sethi   %hi(dword_F012F558), %o0
F0044B10: d6022158                 ld      [%o0+%lo(dword_F012F558)], %o3
F0044B14: 80a2e000                 cmp     %o3, 0
F0044B18: 02800016                 be      loc_F0044B70
F0044B1C: 94102000                 mov     0, %o2
F0044B20: c407bfa8                 ld      [%fp+var_58], %g2
F0044B24: da07bfac                 ld      [%fp+var_58+4], %o5
F0044B28: d002e004                 ld      [%o3+4], %o0
F0044B2C: 80a20002                 cmp     %o0, %g2
F0044B30: 3280000d                 bne,a   loc_F0044B64
F0044B34: d602c000                 ld      [%o3], %o3
F0044B38: d002e008                 ld      [%o3+8], %o0
F0044B3C: 80a2000d                 cmp     %o0, %o5
F0044B40: 02800013                 be      loc_F0044B8C
F0044B44: 80a20009                 cmp     %o0, %o1
F0044B48: 1a800003                 bcc     loc_F0044B54
F0044B4C: 98102001                 mov     1, %o4
F0044B50: 92100008                 mov     %o0, %o1! unsigned __int32
F0044B54: 80a2000a                 cmp     %o0, %o2
F0044B58: 38800002                 bgu,a   loc_F0044B60
F0044B5C: 94100008                 mov     %o0, %o2! unsigned __int32
F0044B60: d602c000                 ld      [%o3], %o3
F0044B64: 80a2e000                 cmp     %o3, 0
F0044B68: 32bffff1                 bne,a   loc_F0044B2C
F0044B6C: d002e004                 ld      [%o3+4], %o0! SVCXPRT *
F0044B70: 80a32000                 cmp     %o4, 0
F0044B74: 0280000c                 be      loc_F0044BA4
F0044B78: 01000000                 nop
F0044B7C: 7fffff99                 call    _svcerr_progvers
F0044B80: 90100018                 mov     %i0, %o0
F0044B84: 1080000b                 ba      loc_F0044BB0
F0044B88: d4062008                 ld      [%i0+8], %o2
F0044B8C: 9007bfa8                 add     %fp, var_58, %o0
F0044B90: d402e00c                 ld      [%o3+0xC], %o2
F0044B94: 9fc28000                 call    %o2
F0044B98: 92100018                 mov     %i0, %o1
F0044B9C: 1080000b                 ba      loc_F0044BC8
F0044BA0: d0062008                 ld      [%i0+8], %o0! SVCXPRT *
F0044BA4: 7fffff7d                 call    _svcerr_noprog
F0044BA8: 90100018                 mov     %i0, %o0
F0044BAC: d4062008                 ld      [%i0+8], %o2
F0044BB0: 90100018                 mov     %i0, %o0
F0044BB4: d602a010                 ld      [%o2+0x10], %o3
F0044BB8: 92102000                 mov     0, %o1
F0044BBC: 9fc2c000                 call    %o3
F0044BC0: 94102000                 mov     0, %o2
F0044BC4: d0062008                 ld      [%i0+8], %o0
F0044BC8: d2022004                 ld      [%o0+4], %o1
F0044BCC: 9fc24000                 call    %o1
F0044BD0: 90100018                 mov     %i0, %o0
F0044BD4: 80a22000                 cmp     %o0, 0
F0044BD8: 02bfffa0                 be      loc_F0044A58
F0044BDC: 80a22001                 cmp     %o0, 1
F0044BE0: 22bfffae                 be,a    loc_F0044A98
F0044BE4: d2062008                 ld      [%i0+8], %o1
F0044BE8: 133c04eb                 sethi   -0xFEC5400, %o1
F0044BEC: d0026068                 ld      [%o1+0x68], %o0
F0044BF0: d0240000                 st      %o0, [%l0]
F0044BF4: e0226068                 st      %l0, [%o1+0x68]
F0044BF8: 81c7e008                 ret
F0044BFC: 81e80000                 restore
