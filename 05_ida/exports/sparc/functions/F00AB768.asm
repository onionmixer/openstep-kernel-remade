F00AB768: 9de3bf88                 save    %sp, -0x78, %sp
F00AB76C: d0064000                 ld      [%i1], %o0
F00AB770: d026c000                 st      %o0, [%i3]
F00AB774: d0066004                 ld      [%i1+4], %o0
F00AB778: d026e004                 st      %o0, [%i3+4]
F00AB77C: d0066008                 ld      [%i1+8], %o0
F00AB780: d026e008                 st      %o0, [%i3+8]
F00AB784: d006600c                 ld      [%i1+0xC], %o0
F00AB788: d026e00c                 st      %o0, [%i3+0xC]
F00AB78C: d0066010                 ld      [%i1+0x10], %o0
F00AB790: d026e010                 st      %o0, [%i3+0x10]
F00AB794: d0066014                 ld      [%i1+0x14], %o0
F00AB798: d026e014                 st      %o0, [%i3+0x14]
F00AB79C: d0066018                 ld      [%i1+0x18], %o0
F00AB7A0: d026e018                 st      %o0, [%i3+0x18]
F00AB7A4: d006601c                 ld      [%i1+0x1C], %o0
F00AB7A8: d026e01c                 st      %o0, [%i3+0x1C]
F00AB7AC: d0066020                 ld      [%i1+0x20], %o0
F00AB7B0: d026e020                 st      %o0, [%i3+0x20]
F00AB7B4: d206a004                 ld      [%i2+4], %o1
F00AB7B8: 80a26003                 cmp     %o1, 3
F00AB7BC: 14800005                 bg      loc_F00AB7D0
F00AB7C0: d0066004                 ld      [%i1+4], %o0
F00AB7C4: 80a22003                 cmp     %o0, 3
F00AB7C8: 24800018                 ble,a   loc_F00AB828
F00AB7CC: d0064000                 ld      [%i1], %o0
F00AB7D0: 80a24008                 cmp     %o1, %o0
F00AB7D4: 0480014a                 ble     locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00AB7D8: 01000000                 nop
F00AB7DC: d0068000                 ld      [%i2], %o0
F00AB7E0: d026c000                 st      %o0, [%i3]
F00AB7E4: d006a004                 ld      [%i2+4], %o0
F00AB7E8: d026e004                 st      %o0, [%i3+4]
F00AB7EC: d006a008                 ld      [%i2+8], %o0
F00AB7F0: d026e008                 st      %o0, [%i3+8]
F00AB7F4: d006a00c                 ld      [%i2+0xC], %o0
F00AB7F8: d026e00c                 st      %o0, [%i3+0xC]
F00AB7FC: d006a010                 ld      [%i2+0x10], %o0
F00AB800: d026e010                 st      %o0, [%i3+0x10]
F00AB804: d006a014                 ld      [%i2+0x14], %o0
F00AB808: d026e014                 st      %o0, [%i3+0x14]
F00AB80C: d006a018                 ld      [%i2+0x18], %o0
F00AB810: d026e018                 st      %o0, [%i3+0x18]
F00AB814: d006a01c                 ld      [%i2+0x1C], %o0
F00AB818: d026e01c                 st      %o0, [%i3+0x1C]
F00AB81C: d006a020                 ld      [%i2+0x20], %o0
F00AB820: 10800137                 ba      locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00AB824: d026e020                 st      %o0, [%i3+0x20]
F00AB828: d2068000                 ld      [%i2], %o1
F00AB82C: 901a0009                 btog    %o1, %o0
F00AB830: d026c000                 st      %o0, [%i3]
F00AB834: d2066004                 ld      [%i1+4], %o1
F00AB838: 80a26005                 cmp     %o1, 5! switch 6 cases
F00AB83C: 18800025                 bgu     def_F00AB850! jumptable F00AB850 default case, case 3
F00AB840: 113c02ae                 sethi   %hi(jpt_F00AB850), %o0
F00AB844: 90122058                 bset    %lo(jpt_F00AB850), %o0
F00AB848: 932a6002                 sll     %o1, 2, %o1
F00AB84C: d0024008                 ld      [%o1+%o0], %o0
F00AB850: 81c20000                 jmp     %o0! switch jump
F00AB854: 01000000                 nop
F00AB870: d2066004                 ld      [%i1+4], %o1! jumptable F00AB850 cases 0,2
F00AB874: d006a004                 ld      [%i2+4], %o0
F00AB878: 80a24008                 cmp     %o1, %o0
F00AB87C: 12800120                 bne     locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00AB880: 90100018                 mov     %i0, %o0
F00AB884: 40000c98                 call    _fpu_error_nan
F00AB888: 9210001b                 mov     %i3, %o1
F00AB88C: 90102004                 mov     4, %o0
F00AB890: 1080011b                 ba      locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00AB894: d026e004                 st      %o0, [%i3+4]
F00AB898: d006a004                 ld      [%i2+4], %o0! jumptable F00AB850 case 1
F00AB89C: 80a22000                 cmp     %o0, 0
F00AB8A0: 02800006                 be      loc_F00AB8B8
F00AB8A4: 80a22002                 cmp     %o0, 2
F00AB8A8: 22800115                 be,a    locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00AB8AC: c026e004                 clr     [%i3+4]
F00AB8B0: 10800009                 ba      loc_F00AB8D4
F00AB8B4: d006600c                 ld      [%i1+0xC], %o0
F00AB8B8: 90100018                 mov     %i0, %o0
F00AB8BC: 40000c82                 call    _fpu_set_exception
F00AB8C0: 92102001                 mov     1, %o1
F00AB8C4: 90102002                 mov     2, %o0
F00AB8C8: 1080010d                 ba      locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00AB8CC: d026e004                 st      %o0, [%i3+4]
F00AB8D0: d006600c                 ld      [%i1+0xC], %o0! jumptable F00AB850 default case, case 3
F00AB8D4: a006a00c                 add     %i2, 0xC, %l0
F00AB8D8: d027bfe8                 st      %o0, [%fp+var_18]
F00AB8DC: d2066010                 ld      [%i1+0x10], %o1
F00AB8E0: 9007bfe8                 add     %fp, var_18, %o0
F00AB8E4: d227bfec                 st      %o1, [%fp+var_18+4]
F00AB8E8: d4066014                 ld      [%i1+0x14], %o2
F00AB8EC: 92100010                 mov     %l0, %o1
F00AB8F0: d427bff0                 st      %o2, [%fp+var_10]
F00AB8F4: d6066018                 ld      [%i1+0x18], %o3
F00AB8F8: 94102004                 mov     4, %o2
F00AB8FC: 40000cb1                 call    _fpu_cmpli
F00AB900: d627bff4                 st      %o3, [%fp+var_C]
F00AB904: 80a22000                 cmp     %o0, 0
F00AB908: 06800005                 bl      loc_F00AB91C
F00AB90C: d0066008                 ld      [%i1+8], %o0
F00AB910: d206a008                 ld      [%i2+8], %o1
F00AB914: 10800005                 ba      loc_F00AB928
F00AB918: 90220009                 sub     %o0, %o1, %o0
F00AB91C: d206a008                 ld      [%i2+8], %o1
F00AB920: 90220009                 sub     %o0, %o1, %o0
F00AB924: 90023fff                 inc     -1, %o0
F00AB928: d026e008                 st      %o0, [%i3+8]
F00AB92C: b0102000                 mov     0, %i0
F00AB930: b407bfe8                 add     %fp, var_18, %i2
F00AB934: 23200000                 sethi   0x80000000, %l1
F00AB938: 1100003fb21223ff         set     0xFFFF, %i1
F00AB940: b12e2001                 sll     %i0, 1, %i0
F00AB944: 9010001a                 mov     %i2, %o0
F00AB948: 92100010                 mov     %l0, %o1
F00AB94C: 40000c9d                 call    _fpu_cmpli
F00AB950: 94102004                 mov     4, %o2
F00AB954: 80a22000                 cmp     %o0, 0
F00AB958: 06800016                 bl      loc_F00AB9B0
F00AB95C: d207bff4                 ld      [%fp+var_C], %o1
F00AB960: b0062001                 inc     %i0
F00AB964: 9007bff4                 add     %fp, var_C, %o0
F00AB968: d404200c                 ld      [%l0+0xC], %o2
F00AB96C: 40000c7a                 call    _fpu_sub3wc
F00AB970: 96102000                 mov     0, %o3
F00AB974: d207bff0                 ld      [%fp+var_10], %o1
F00AB978: 96100008                 mov     %o0, %o3
F00AB97C: d4042008                 ld      [%l0+8], %o2
F00AB980: 40000c75                 call    _fpu_sub3wc
F00AB984: 9007bff0                 add     %fp, var_10, %o0
F00AB988: d207bfec                 ld      [%fp+var_18+4], %o1
F00AB98C: 96100008                 mov     %o0, %o3
F00AB990: d4042004                 ld      [%l0+4], %o2
F00AB994: 40000c70                 call    _fpu_sub3wc
F00AB998: 9007bfec                 add     %fp, var_18+4, %o0
F00AB99C: d207bfe8                 ld      [%fp+var_18], %o1
F00AB9A0: 96100008                 mov     %o0, %o3
F00AB9A4: d4040000                 ld      [%l0], %o2
F00AB9A8: 40000c6b                 call    _fpu_sub3wc
F00AB9AC: 9010001a                 mov     %i2, %o0
F00AB9B0: d207bfe8                 ld      [%fp+var_18], %o1
F00AB9B4: d407bfec                 ld      [%fp+var_18+4], %o2
F00AB9B8: 80a60019                 cmp     %i0, %i1
F00AB9BC: d607bff0                 ld      [%fp+var_10], %o3
F00AB9C0: 932a6001                 sll     %o1, 1, %o1
F00AB9C4: 900a8011                 and     %o2, %l1, %o0
F00AB9C8: 9132201f                 srl     %o0, 31, %o0
F00AB9CC: 92124008                 bset    %o0, %o1
F00AB9D0: d227bfe8                 st      %o1, [%fp+var_18]
F00AB9D4: 952aa001                 sll     %o2, 1, %o2
F00AB9D8: 900ac011                 and     %o3, %l1, %o0
F00AB9DC: 9132201f                 srl     %o0, 31, %o0
F00AB9E0: 94128008                 bset    %o0, %o2
F00AB9E4: d427bfec                 st      %o2, [%fp+var_18+4]
F00AB9E8: d207bff4                 ld      [%fp+var_C], %o1
F00AB9EC: 972ae001                 sll     %o3, 1, %o3
F00AB9F0: 900a4011                 and     %o1, %l1, %o0
F00AB9F4: 9132201f                 srl     %o0, 31, %o0
F00AB9F8: 9612c008                 bset    %o0, %o3
F00AB9FC: d627bff0                 st      %o3, [%fp+var_10]
F00ABA00: 932a6001                 sll     %o1, 1, %o1
F00ABA04: 08bfffcf                 bleu    loc_F00AB940
F00ABA08: d227bff4                 st      %o1, [%fp+var_C]
F00ABA0C: f026e00c                 st      %i0, [%i3+0xC]
F00ABA10: b0102000                 mov     0, %i0
F00ABA14: b210201f                 mov     0x1F, %i1
F00ABA18: 23200000                 sethi   0x80000000, %l1
F00ABA1C: b12e2001                 sll     %i0, 1, %i0
F00ABA20: 9010001a                 mov     %i2, %o0
F00ABA24: 92100010                 mov     %l0, %o1
F00ABA28: 40000c66                 call    _fpu_cmpli
F00ABA2C: 94102004                 mov     4, %o2
F00ABA30: 80a22000                 cmp     %o0, 0
F00ABA34: 06800016                 bl      loc_F00ABA8C
F00ABA38: d207bff4                 ld      [%fp+var_C], %o1
F00ABA3C: b0062001                 inc     %i0
F00ABA40: 9007bff4                 add     %fp, var_C, %o0
F00ABA44: d404200c                 ld      [%l0+0xC], %o2
F00ABA48: 40000c43                 call    _fpu_sub3wc
F00ABA4C: 96102000                 mov     0, %o3
F00ABA50: d207bff0                 ld      [%fp+var_10], %o1
F00ABA54: 96100008                 mov     %o0, %o3
F00ABA58: d4042008                 ld      [%l0+8], %o2
F00ABA5C: 40000c3e                 call    _fpu_sub3wc
F00ABA60: 9007bff0                 add     %fp, var_10, %o0
F00ABA64: d207bfec                 ld      [%fp+var_18+4], %o1
F00ABA68: 96100008                 mov     %o0, %o3
F00ABA6C: d4042004                 ld      [%l0+4], %o2
F00ABA70: 40000c39                 call    _fpu_sub3wc
F00ABA74: 9007bfec                 add     %fp, var_18+4, %o0
F00ABA78: d207bfe8                 ld      [%fp+var_18], %o1
F00ABA7C: 96100008                 mov     %o0, %o3
F00ABA80: d4040000                 ld      [%l0], %o2
F00ABA84: 40000c34                 call    _fpu_sub3wc
F00ABA88: 9010001a                 mov     %i2, %o0
F00ABA8C: d207bfe8                 ld      [%fp+var_18], %o1
F00ABA90: b2067fff                 inc     -1, %i1
F00ABA94: d407bfec                 ld      [%fp+var_18+4], %o2
F00ABA98: 80a67fff                 cmp     %i1, -1
F00ABA9C: d607bff0                 ld      [%fp+var_10], %o3
F00ABAA0: 932a6001                 sll     %o1, 1, %o1
F00ABAA4: 900a8011                 and     %o2, %l1, %o0
F00ABAA8: 9132201f                 srl     %o0, 31, %o0
F00ABAAC: 92124008                 bset    %o0, %o1
F00ABAB0: d227bfe8                 st      %o1, [%fp+var_18]
F00ABAB4: 952aa001                 sll     %o2, 1, %o2
F00ABAB8: 900ac011                 and     %o3, %l1, %o0
F00ABABC: 9132201f                 srl     %o0, 31, %o0
F00ABAC0: 94128008                 bset    %o0, %o2
F00ABAC4: d427bfec                 st      %o2, [%fp+var_18+4]
F00ABAC8: d207bff4                 ld      [%fp+var_C], %o1
F00ABACC: 972ae001                 sll     %o3, 1, %o3
F00ABAD0: 900a4011                 and     %o1, %l1, %o0
F00ABAD4: 9132201f                 srl     %o0, 31, %o0
F00ABAD8: 9612c008                 bset    %o0, %o3
F00ABADC: d627bff0                 st      %o3, [%fp+var_10]
F00ABAE0: 932a6001                 sll     %o1, 1, %o1
F00ABAE4: 12bfffce                 bne     loc_F00ABA1C
F00ABAE8: d227bff4                 st      %o1, [%fp+var_C]
F00ABAEC: f026e010                 st      %i0, [%i3+0x10]
F00ABAF0: b0102000                 mov     0, %i0
F00ABAF4: b210201f                 mov     0x1F, %i1
F00ABAF8: 23200000                 sethi   0x80000000, %l1
F00ABAFC: b12e2001                 sll     %i0, 1, %i0
F00ABB00: 9010001a                 mov     %i2, %o0
F00ABB04: 92100010                 mov     %l0, %o1
F00ABB08: 40000c2e                 call    _fpu_cmpli
F00ABB0C: 94102004                 mov     4, %o2
F00ABB10: 80a22000                 cmp     %o0, 0
F00ABB14: 06800016                 bl      loc_F00ABB6C
F00ABB18: d207bff4                 ld      [%fp+var_C], %o1
F00ABB1C: b0062001                 inc     %i0
F00ABB20: 9007bff4                 add     %fp, var_C, %o0
F00ABB24: d404200c                 ld      [%l0+0xC], %o2
F00ABB28: 40000c0b                 call    _fpu_sub3wc
F00ABB2C: 96102000                 mov     0, %o3
F00ABB30: d207bff0                 ld      [%fp+var_10], %o1
F00ABB34: 96100008                 mov     %o0, %o3
F00ABB38: d4042008                 ld      [%l0+8], %o2
F00ABB3C: 40000c06                 call    _fpu_sub3wc
F00ABB40: 9007bff0                 add     %fp, var_10, %o0
F00ABB44: d207bfec                 ld      [%fp+var_18+4], %o1
F00ABB48: 96100008                 mov     %o0, %o3
F00ABB4C: d4042004                 ld      [%l0+4], %o2
F00ABB50: 40000c01                 call    _fpu_sub3wc
F00ABB54: 9007bfec                 add     %fp, var_18+4, %o0
F00ABB58: d207bfe8                 ld      [%fp+var_18], %o1
F00ABB5C: 96100008                 mov     %o0, %o3
F00ABB60: d4040000                 ld      [%l0], %o2
F00ABB64: 40000bfc                 call    _fpu_sub3wc
F00ABB68: 9010001a                 mov     %i2, %o0
F00ABB6C: d207bfe8                 ld      [%fp+var_18], %o1
F00ABB70: b2067fff                 inc     -1, %i1
F00ABB74: d407bfec                 ld      [%fp+var_18+4], %o2
F00ABB78: 80a67fff                 cmp     %i1, -1
F00ABB7C: d607bff0                 ld      [%fp+var_10], %o3
F00ABB80: 932a6001                 sll     %o1, 1, %o1
F00ABB84: 900a8011                 and     %o2, %l1, %o0
F00ABB88: 9132201f                 srl     %o0, 31, %o0
F00ABB8C: 92124008                 bset    %o0, %o1
F00ABB90: d227bfe8                 st      %o1, [%fp+var_18]
F00ABB94: 952aa001                 sll     %o2, 1, %o2
F00ABB98: 900ac011                 and     %o3, %l1, %o0
F00ABB9C: 9132201f                 srl     %o0, 31, %o0
F00ABBA0: 94128008                 bset    %o0, %o2
F00ABBA4: d427bfec                 st      %o2, [%fp+var_18+4]
F00ABBA8: d207bff4                 ld      [%fp+var_C], %o1
F00ABBAC: 972ae001                 sll     %o3, 1, %o3
F00ABBB0: 900a4011                 and     %o1, %l1, %o0
F00ABBB4: 9132201f                 srl     %o0, 31, %o0
F00ABBB8: 9612c008                 bset    %o0, %o3
F00ABBBC: d627bff0                 st      %o3, [%fp+var_10]
F00ABBC0: 932a6001                 sll     %o1, 1, %o1
F00ABBC4: 12bfffce                 bne     loc_F00ABAFC
F00ABBC8: d227bff4                 st      %o1, [%fp+var_C]
F00ABBCC: f026e014                 st      %i0, [%i3+0x14]
F00ABBD0: b0102000                 mov     0, %i0
F00ABBD4: b210201f                 mov     0x1F, %i1
F00ABBD8: 23200000                 sethi   0x80000000, %l1
F00ABBDC: b12e2001                 sll     %i0, 1, %i0
F00ABBE0: 9010001a                 mov     %i2, %o0
F00ABBE4: 92100010                 mov     %l0, %o1
F00ABBE8: 40000bf6                 call    _fpu_cmpli
F00ABBEC: 94102004                 mov     4, %o2
F00ABBF0: 80a22000                 cmp     %o0, 0
F00ABBF4: 06800016                 bl      loc_F00ABC4C
F00ABBF8: d207bff4                 ld      [%fp+var_C], %o1
F00ABBFC: b0062001                 inc     %i0
F00ABC00: 9007bff4                 add     %fp, var_C, %o0
F00ABC04: d404200c                 ld      [%l0+0xC], %o2
F00ABC08: 40000bd3                 call    _fpu_sub3wc
F00ABC0C: 96102000                 mov     0, %o3
F00ABC10: d207bff0                 ld      [%fp+var_10], %o1
F00ABC14: 96100008                 mov     %o0, %o3
F00ABC18: d4042008                 ld      [%l0+8], %o2
F00ABC1C: 40000bce                 call    _fpu_sub3wc
F00ABC20: 9007bff0                 add     %fp, var_10, %o0
F00ABC24: d207bfec                 ld      [%fp+var_18+4], %o1
F00ABC28: 96100008                 mov     %o0, %o3
F00ABC2C: d4042004                 ld      [%l0+4], %o2
F00ABC30: 40000bc9                 call    _fpu_sub3wc
F00ABC34: 9007bfec                 add     %fp, var_18+4, %o0
F00ABC38: d207bfe8                 ld      [%fp+var_18], %o1
F00ABC3C: 96100008                 mov     %o0, %o3
F00ABC40: d4040000                 ld      [%l0], %o2
F00ABC44: 40000bc4                 call    _fpu_sub3wc
F00ABC48: 9010001a                 mov     %i2, %o0
F00ABC4C: d207bfe8                 ld      [%fp+var_18], %o1
F00ABC50: b2067fff                 inc     -1, %i1
F00ABC54: d407bfec                 ld      [%fp+var_18+4], %o2
F00ABC58: 80a67fff                 cmp     %i1, -1
F00ABC5C: d607bff0                 ld      [%fp+var_10], %o3
F00ABC60: 932a6001                 sll     %o1, 1, %o1
F00ABC64: 900a8011                 and     %o2, %l1, %o0
F00ABC68: 9132201f                 srl     %o0, 31, %o0
F00ABC6C: 92124008                 bset    %o0, %o1
F00ABC70: d227bfe8                 st      %o1, [%fp+var_18]
F00ABC74: 952aa001                 sll     %o2, 1, %o2
F00ABC78: 900ac011                 and     %o3, %l1, %o0
F00ABC7C: 9132201f                 srl     %o0, 31, %o0
F00ABC80: 94128008                 bset    %o0, %o2
F00ABC84: d427bfec                 st      %o2, [%fp+var_18+4]
F00ABC88: d207bff4                 ld      [%fp+var_C], %o1
F00ABC8C: 972ae001                 sll     %o3, 1, %o3
F00ABC90: 900a4011                 and     %o1, %l1, %o0
F00ABC94: 9132201f                 srl     %o0, 31, %o0
F00ABC98: 9612c008                 bset    %o0, %o3
F00ABC9C: d627bff0                 st      %o3, [%fp+var_10]
F00ABCA0: 932a6001                 sll     %o1, 1, %o1
F00ABCA4: 12bfffce                 bne     loc_F00ABBDC
F00ABCA8: d227bff4                 st      %o1, [%fp+var_C]
F00ABCAC: f026e018                 st      %i0, [%i3+0x18]
F00ABCB0: d01fbfe8                 ldd     [%fp+var_18], %o0
F00ABCB4: d407bff0                 ld      [%fp+var_10], %o2
F00ABCB8: 90120009                 bset    %o1, %o0
F00ABCBC: d207bff4                 ld      [%fp+var_C], %o1
F00ABCC0: 9012000a                 bset    %o2, %o0
F00ABCC4: 80920009                 orcc    %o0, %o1, %g0
F00ABCC8: 12800005                 bne     loc_F00ABCDC
F00ABCCC: b0102001                 mov     1, %i0
F00ABCD0: c026e01c                 clr     [%i3+0x1C]
F00ABCD4: 1080000a                 ba      locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00ABCD8: c026e020                 clr     [%i3+0x20]
F00ABCDC: f026e020                 st      %i0, [%i3+0x20]
F00ABCE0: 9010001a                 mov     %i2, %o0
F00ABCE4: 92100010                 mov     %l0, %o1
F00ABCE8: 40000bb6                 call    _fpu_cmpli
F00ABCEC: 94102004                 mov     4, %o2
F00ABCF0: 80a22000                 cmp     %o0, 0
F00ABCF4: 36800002                 bge,a   locret_F00ABCFC! jumptable F00AB850 cases 4,5
F00ABCF8: f026e01c                 st      %i0, [%i3+0x1C]
F00ABCFC: 81c7e008                 ret! jumptable F00AB850 cases 4,5
F00ABD00: 81e80000                 restore
