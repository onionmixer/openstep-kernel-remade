F003C774: 9de3bf68                 save    %sp, -0x98, %sp
F003C778: 133c04ea921261b0         set     _clstat, %o1
F003C780: d0026008                 ld      [%o1+8], %o0
F003C784: 952e6002                 sll     %i1, 2, %o2
F003C788: 90022001                 inc     %o0
F003C78C: d0226008                 st      %o0, [%o1+8]
F003C790: 92026010                 inc     0x10, %o1
F003C794: d0028009                 ld      [%o2+%o1], %o0
F003C798: f427bfd4                 st      %i2, [%fp+var_2C]
F003C79C: 90022001                 inc     %o0
F003C7A0: d0228009                 st      %o0, [%o2+%o1]
F003C7A4: c027bfec                 clr     [%fp+var_14]
F003C7A8: c027bfe8                 clr     [%fp+var_18]
F003C7AC: 113c04339012230e         set     unk_F010CF0E, %o0
F003C7B4: 932e6001                 sll     %i1, 1, %o1
F003C7B8: d2524008                 ldsh    [%o1+%o0], %o1
F003C7BC: aa102000                 mov     0, %l5
F003C7C0: d006202c                 ld      [%i0+0x2C], %o0
F003C7C4: ae102000                 mov     0, %l7
F003C7C8: ec07a05c                 ld      [%fp+arg_5C], %l6
F003C7CC: a72a0009                 sll     %o0, %o1, %l3
F003C7D0: 90100018                 mov     %i0, %o0
F003C7D4: 7ffffef6                 call    sub_F003C3AC
F003C7D8: 92100016                 mov     %l6, %o1
F003C7DC: 80a66009                 cmp     %i1, 9
F003C7E0: 12800004                 bne     loc_F003C7F0
F003C7E4: a8100008                 mov     %o0, %l4
F003C7E8: 4000184a                 call    _clntkudp_once
F003C7EC: 92102001                 mov     1, %o1! int
F003C7F0: 35100000                 sethi   0x40000000, %i2
F003C7F4: a2102000                 mov     0, %l1
F003C7F8: 90100013                 mov     %l3, %o0! int
F003C7FC: 7fff2783                 call    _div
F003C800: 9210200a                 mov     0xA, %o1
F003C804: a0100008                 mov     %o0, %l0
F003C808: e027bfe0                 st      %l0, [%fp+var_20]
F003C80C: 90100013                 mov     %l3, %o0
F003C810: 7fff2826                 call    _rem
F003C814: 9210200a                 mov     0xA, %o1
F003C818: 932a2001                 sll     %o0, 1, %o1
F003C81C: 92024008                 add     %o1, %o0, %o1
F003C820: 952a6006                 sll     %o1, 6, %o2
F003C824: 9202400a                 add     %o1, %o2, %o1
F003C828: 932a6002                 sll     %o1, 2, %o1
F003C82C: 92024008                 add     %o1, %o0, %o1
F003C830: 932a6002                 sll     %o1, 2, %o1
F003C834: 92024008                 add     %o1, %o0, %o1
F003C838: 932a6005                 sll     %o1, 5, %o1
F003C83C: d227bfe4                 st      %o1, [%fp+var_1C]
F003C840: e027bfd8                 st      %l0, [%fp+var_28]
F003C844: d227bfdc                 st      %o1, [%fp+var_24]
F003C848: 90100014                 mov     %l4, %o0
F003C84C: 92100019                 mov     %i1, %o1
F003C850: d407bfd4                 ld      [%fp+var_2C], %o2
F003C854: 9610001b                 mov     %i3, %o3
F003C858: da052004                 ld      [%l4+4], %o5
F003C85C: 9807bfd8                 add     %fp, var_28, %o4
F003C860: d823a05c                 st      %o4, [%sp+0x98+var_3C]
F003C864: c4034000                 ld      [%o5], %g2
F003C868: 9810001c                 mov     %i4, %o4
F003C86C: 9fc08000                 call    %g2
F003C870: 9a10001d                 mov     %i5, %o5
F003C874: a4100008                 mov     %o0, %l2
F003C878: 80a4a00b                 cmp     %l2, 0xB! switch 12 cases
F003C87C: 18800013                 bgu     def_F003C890! jumptable F003C890 default case, cases 3-5,8,10
F003C880: 912ca002                 sll     %l2, 2, %o0
F003C884: 073c00f28610e098         set     jpt_F003C890, %g3
F003C88C: d0020003                 ld      [%o0+%g3], %o0
F003C890: 81c20000                 jmp     %o0! switch jump
F003C894: 01000000                 nop
F003C8C8: 80a4a012                 cmp     %l2, 0x12! jumptable F003C890 default case, cases 3-5,8,10
F003C8CC: 3280000f                 bne,a   loc_F003C908
F003C8D0: d0062014                 ld      [%i0+0x14], %o0
F003C8D4: d2062014                 ld      [%i0+0x14], %o1
F003C8D8: 11280000                 sethi   -0x60000000, %o0
F003C8DC: a20a4008                 and     %o1, %o0, %l1
F003C8E0: 11200000                 sethi   0x80000000, %o0
F003C8E4: 901c4008                 btog    %l1, %o0
F003C8E8: 80a00008                 cmp     %g0, %o0
F003C8EC: a2603fff                 subc    %g0, -1, %l1
F003C8F0: 80a46000                 cmp     %l1, 0
F003C8F4: 12800026                 bne     loc_F003C98C
F003C8F8: 90102004                 mov     4, %o0
F003C8FC: e427bfe8                 st      %l2, [%fp+var_18]
F003C900: 10800004                 ba      loc_F003C910
F003C904: d027bfec                 st      %o0, [%fp+var_14]
F003C908: a332201f                 srl     %o0, 31, %l1
F003C90C: 80a46000                 cmp     %l1, 0
F003C910: 0280001f                 be      loc_F003C98C
F003C914: 01000000                 nop
F003C918: 932ce002                 sll     %l3, 2, %o1
F003C91C: 80a2612c                 cmp     %o1, 0x12C
F003C920: 14800003                 bg      loc_F003C92C
F003C924: 9010212c                 mov     0x12C, %o0
F003C928: 90100009                 mov     %o1, %o0
F003C92C: d2062014                 ld      [%i0+0x14], %o1
F003C930: 808a401a                 btst    %i2, %o1
F003C934: 12800008                 bne     loc_F003C954
F003C938: a6100008                 mov     %o0, %l3
F003C93C: 9012401a                 or      %o1, %i2, %o0
F003C940: d0262014                 st      %o0, [%i0+0x14]
F003C944: 113c043390122338         set     aNfsServerSNotR, %o0! "NFS server %s not responding still tryi"...
F003C94C: 7fff5f43                 call    _printf
F003C950: 92062034                 add     %i0, 0x34, %o1 ! '4'
F003C954: 80a5e000                 cmp     %l7, 0
F003C958: 1280000d                 bne     loc_F003C98C
F003C95C: 80a46000                 cmp     %l1, 0
F003C960: 113c04cf                 sethi   %hi(_active_u), %o0
F003C964: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003C968: d0022164                 ld      [%o0+0x164], %o0
F003C96C: 80a22000                 cmp     %o0, 0
F003C970: 02800006                 be      loc_F003C988! jumptable F003C890 cases 0-2,6,7,9,11
F003C974: 113c0433                 sethi   %hi(aNfsServerSNotR_0), %o0! "NFS server %s not responding still tryi"...
F003C978: ae102001                 mov     1, %l7
F003C97C: 90122368                 bset    %lo(aNfsServerSNotR_0), %o0! "NFS server %s not responding still tryi"...
F003C980: 7fff5f48                 call    _uprintf
F003C984: 92062034                 add     %i0, 0x34, %o1 ! '4'
F003C988: 80a46000                 cmp     %l1, 0! jumptable F003C890 cases 0-2,6,7,9,11
F003C98C: 12bfff9b                 bne     loc_F003C7F8
F003C990: a2102000                 mov     0, %l1
F003C994: 90100014                 mov     %l4, %o0
F003C998: 400017de                 call    _clntkudp_once
F003C99C: 92102000                 mov     0, %o1
F003C9A0: 80a4a000                 cmp     %l2, 0
F003C9A4: 0280002d                 be      loc_F003CA58
F003C9A8: 133c04ea                 sethi   %hi(_clstat), %o1
F003C9AC: 921261b0                 bset    %lo(_clstat), %o1
F003C9B0: d002600c                 ld      [%o1+0xC], %o0
F003C9B4: 80a4a012                 cmp     %l2, 0x12
F003C9B8: 90022001                 inc     %o0
F003C9BC: d022600c                 st      %o0, [%o1+0xC]
F003C9C0: d0062014                 ld      [%i0+0x14], %o0
F003C9C4: 13040000                 sethi   0x10000000, %o1
F003C9C8: 90120009                 bset    %o1, %o0
F003C9CC: 02800056                 be      loc_F003CB24
F003C9D0: d0262014                 st      %o0, [%i0+0x14]
F003C9D4: e427bfe8                 st      %l2, [%fp+var_18]
F003C9D8: 90102016                 mov     0x16, %o0
F003C9DC: d027bfec                 st      %o0, [%fp+var_14]
F003C9E0: 90100012                 mov     %l2, %o0! clnt_stat
F003C9E4: 213c0433                 sethi   %hi(aNfsSFailedForS), %l0! "NFS %s failed for server %s: %s\n"
F003C9E8: 133c0433a612622c         set     _rfsnames, %l3
F003C9F0: b32e6002                 sll     %i1, 2, %i1
F003C9F4: e2064013                 ld      [%i1+%l3], %l1
F003C9F8: 40001aec                 call    _clnt_sperrno
F003C9FC: a0142398                 bset    %lo(aNfsSFailedForS), %l0! "NFS %s failed for server %s: %s\n"
F003CA00: 96100008                 mov     %o0, %o3
F003CA04: 90100010                 mov     %l0, %o0! char *
F003CA08: 92100011                 mov     %l1, %o1
F003CA0C: b0062034                 inc     0x34, %i0 ! '4'
F003CA10: 7fff5f12                 call    _printf
F003CA14: 94100018                 mov     %i0, %o2
F003CA18: 113c04cf                 sethi   %hi(_active_u), %o0
F003CA1C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003CA20: d0022164                 ld      [%o0+0x164], %o0
F003CA24: 80a22000                 cmp     %o0, 0
F003CA28: 0280003f                 be      loc_F003CB24
F003CA2C: 90100012                 mov     %l2, %o0! clnt_stat
F003CA30: 213c0433                 sethi   %hi(aNfsSFailedForS_0), %l0! "NFS %s failed for server %s: %s\n"
F003CA34: e2064013                 ld      [%i1+%l3], %l1
F003CA38: 40001adc                 call    _clnt_sperrno
F003CA3C: a01423c0                 bset    %lo(aNfsSFailedForS_0), %l0! "NFS %s failed for server %s: %s\n"
F003CA40: 96100008                 mov     %o0, %o3
F003CA44: 90100010                 mov     %l0, %o0
F003CA48: 92100011                 mov     %l1, %o1
F003CA4C: 7fff5f15                 call    _uprintf
F003CA50: 94100018                 mov     %i0, %o2
F003CA54: 30800034                 ba,a    loc_F003CB24
F003CA58: 80a76000                 cmp     %i5, 0
F003CA5C: 2280001b                 be,a    loc_F003CAC8
F003CA60: d2062014                 ld      [%i0+0x14], %o1
F003CA64: d0074000                 ld      [%i5], %o0
F003CA68: 80a2200d                 cmp     %o0, 0xD
F003CA6C: 32800017                 bne,a   loc_F003CAC8
F003CA70: d2062014                 ld      [%i0+0x14], %o1
F003CA74: 80a56000                 cmp     %l5, 0
F003CA78: 32800014                 bne,a   loc_F003CAC8
F003CA7C: d2062014                 ld      [%i0+0x14], %o1
F003CA80: d055a002                 ldsh    [%l6+2], %o0
F003CA84: 80a22000                 cmp     %o0, 0
F003CA88: 32800010                 bne,a   loc_F003CAC8
F003CA8C: d2062014                 ld      [%i0+0x14], %o1
F003CA90: d055a006                 ldsh    [%l6+6], %o0
F003CA94: 80a22000                 cmp     %o0, 0
F003CA98: 2280000c                 be,a    loc_F003CAC8
F003CA9C: d2062014                 ld      [%i0+0x14], %o1
F003CAA0: 7fff4c01                 call    _crdup
F003CAA4: 90100016                 mov     %l6, %o0
F003CAA8: aa100008                 mov     %o0, %l5
F003CAAC: ac100015                 mov     %l5, %l6
F003CAB0: d2156006                 lduh    [%l5+6], %o1
F003CAB4: 90100014                 mov     %l4, %o0
F003CAB8: 7fffff0e                 call    sub_F003C6F0
F003CABC: d2356002                 sth     %o1, [%l5+2]
F003CAC0: 10bfff45                 ba      loc_F003C7D4
F003CAC4: 90100018                 mov     %i0, %o0
F003CAC8: 80a26000                 cmp     %o1, 0
F003CACC: 16800014                 bge     loc_F003CB1C
F003CAD0: 11040000                 sethi   0x10000000, %o0
F003CAD4: 11100000                 sethi   0x40000000, %o0
F003CAD8: 808a4008                 btst    %o0, %o1
F003CADC: 02800009                 be      loc_F003CB00
F003CAE0: 113c0433                 sethi   %hi(aNfsServerSOk), %o0! "NFS server %s ok\n"
F003CAE4: 901223e8                 bset    %lo(aNfsServerSOk), %o0! "NFS server %s ok\n"
F003CAE8: 7fff5edc                 call    _printf
F003CAEC: 92062034                 add     %i0, 0x34, %o1 ! '4'
F003CAF0: d2062014                 ld      [%i0+0x14], %o1
F003CAF4: 11100000                 sethi   0x40000000, %o0
F003CAF8: 902a4008                 andn    %o1, %o0, %o0
F003CAFC: d0262014                 st      %o0, [%i0+0x14]
F003CB00: 80a5e000                 cmp     %l7, 0
F003CB04: 02800008                 be      loc_F003CB24
F003CB08: 113c0434                 sethi   %hi(aNfsServerSOk_0), %o0! "NFS server %s ok\n"
F003CB0C: 90122000                 bset    %lo(aNfsServerSOk_0), %o0! "NFS server %s ok\n"
F003CB10: 7fff5ee4                 call    _uprintf
F003CB14: 92062034                 add     %i0, 0x34, %o1 ! '4'
F003CB18: 30800003                 ba,a    loc_F003CB24
F003CB1C: 902a4008                 andn    %o1, %o0, %o0
F003CB20: d0262014                 st      %o0, [%i0+0x14]
F003CB24: 7ffffef3                 call    sub_F003C6F0
F003CB28: 90100014                 mov     %l4, %o0
F003CB2C: 80a56000                 cmp     %l5, 0
F003CB30: 02800005                 be      loc_F003CB44
F003CB34: d207bfe8                 ld      [%fp+var_18], %o1
F003CB38: 7fff4bb8                 call    _crfree
F003CB3C: 90100015                 mov     %l5, %o0
F003CB40: d207bfe8                 ld      [%fp+var_18], %o1
F003CB44: 80a26000                 cmp     %o1, 0
F003CB48: 0280000c                 be      locret_F003CB78
F003CB4C: f007bfec                 ld      [%fp+var_14], %i0
F003CB50: d007bfec                 ld      [%fp+var_14], %o0
F003CB54: 80a22000                 cmp     %o0, 0
F003CB58: 12800008                 bne     locret_F003CB78
F003CB5C: 113c0434                 sethi   %hi(aRfscallReStatu), %o0! "rfscall:  re_status %d, re_errno 0\n"
F003CB60: 7fff5ebe                 call    _printf
F003CB64: 90122018                 bset    %lo(aRfscallReStatu), %o0! "rfscall:  re_status %d, re_errno 0\n"
F003CB68: 113c0434                 sethi   %hi(aRfscall), %o0! "rfscall"
F003CB6C: 7fff6181                 call    _panic
F003CB70: 90122040                 bset    %lo(aRfscall), %o0! "rfscall"
F003CB74: f007bfec                 ld      [%fp+var_14], %i0
F003CB78: 81c7e008                 ret
F003CB7C: 81e80000                 restore
