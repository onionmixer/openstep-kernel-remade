F00AF778: 9de3bf80                 save    %sp, -0x80, %sp
F00AF77C: f227a048                 st      %i1, [%fp+arg_48]
F00AF780: f427a04c                 st      %i2, [%fp+arg_4C]
F00AF784: f627a050                 st      %i3, [%fp+arg_50]
F00AF788: f827a054                 st      %i4, [%fp+arg_54]
F00AF78C: fa27a058                 st      %i5, [%fp+arg_58]
F00AF790: b807a048                 add     %fp, arg_48, %i4
F00AF794: f24e0000                 ldsb    [%i0], %i1! jumptable F00AF814 cases 1-30,32-41,43-50,52-61,64-70,72,73,75-77,79,81,82
F00AF798: 1080000c                 ba      loc_F00AF7C8! jumptable F00AF814 default case
F00AF79C: b4102000                 mov     0, %i2
F00AF7A0: 80a66000                 cmp     %i1, 0
F00AF7A4: 028000a7                 be      locret_F00AFA40
F00AF7A8: 80a6600a                 cmp     %i1, 0xA
F00AF7AC: 12800004                 bne     loc_F00AF7BC
F00AF7B0: 01000000                 nop
F00AF7B4: 400000d2                 call    _prom_putchar
F00AF7B8: 9010200d                 mov     0xD, %o0
F00AF7BC: 400000d0                 call    _prom_putchar
F00AF7C0: 90100019                 mov     %i1, %o0
F00AF7C4: f24e0000                 ldsb    [%i0], %i1
F00AF7C8: 80a66025                 cmp     %i1, 0x25 ! '%'
F00AF7CC: 12bffff5                 bne     loc_F00AF7A0
F00AF7D0: b0062001                 inc     %i0
F00AF7D4: f24e0000                 ldsb    [%i0], %i1! jumptable F00AF814 case 71
F00AF7D8: 90067fce                 add     %i1, -0x32, %o0
F00AF7DC: 80a22007                 cmp     %o0, 7
F00AF7E0: 18800005                 bgu     loc_F00AF7F4
F00AF7E4: b0062001                 inc     %i0
F00AF7E8: b4067fd0                 add     %i1, -0x30, %i2
F00AF7EC: f24e0000                 ldsb    [%i0], %i1
F00AF7F0: b0062001                 inc     %i0
F00AF7F4: 92067fdb                 add     %i1, -0x25, %o1
F00AF7F8: 80a26053                 cmp     %o1, 0x53 ! 'S'! switch 84 cases
F00AF7FC: 38bfffe7                 bgu,a   def_F00AF814! jumptable F00AF814 default case
F00AF800: f24e0000                 ldsb    [%i0], %i1
F00AF804: 113c02be9012201c         set     jpt_F00AF814, %o0
F00AF80C: 932a6002                 sll     %o1, 2, %o1
F00AF810: d0024008                 ld      [%o1+%o0], %o0
F00AF814: 81c20000                 jmp     %o0! switch jump
F00AF818: 01000000                 nop
F00AF96C: 10800005                 ba      loc_F00AF980! jumptable F00AF814 cases 51,83
F00AF970: b6102010                 mov     0x10, %i3
F00AF974: 10800003                 ba      loc_F00AF980! jumptable F00AF814 cases 31,63,80
F00AF978: b610200a                 mov     0xA, %i3
F00AF97C: b6102008                 mov     8, %i3! jumptable F00AF814 cases 42,74
F00AF980: b8072004                 inc     4, %i4
F00AF984: d0073ffc                 ld      [%i4-4], %o0
F00AF988: 9210001b                 mov     %i3, %o1
F00AF98C: 4000002f                 call    _prom_printn
F00AF990: 9410001a                 mov     %i2, %o2
F00AF994: 10bfff81                 ba      def_F00AF814! jumptable F00AF814 default case
F00AF998: f24e0000                 ldsb    [%i0], %i1
F00AF99C: b8072004                 inc     4, %i4! jumptable F00AF814 case 62
F00AF9A0: f6073ffc                 ld      [%i4-4], %i3
F00AF9A4: b4102018                 mov     0x18, %i2
F00AF9A8: 913ec01a                 sra     %i3, %i2, %o0
F00AF9AC: b28a207f                 andcc   %o0, 0x7F, %i1
F00AF9B0: 02800008                 be      loc_F00AF9D0
F00AF9B4: 80a6600a                 cmp     %i1, 0xA
F00AF9B8: 12800004                 bne     loc_F00AF9C8
F00AF9BC: 01000000                 nop
F00AF9C0: 4000004f                 call    _prom_putchar
F00AF9C4: 9010200d                 mov     0xD, %o0
F00AF9C8: 4000004d                 call    _prom_putchar
F00AF9CC: 90100019                 mov     %i1, %o0
F00AF9D0: b486bff8                 inccc   -8, %i2
F00AF9D4: 1cbffff6                 bpos    loc_F00AF9AC
F00AF9D8: 913ec01a                 sra     %i3, %i2, %o0
F00AF9DC: 10bfff6f                 ba      def_F00AF814! jumptable F00AF814 default case
F00AF9E0: f24e0000                 ldsb    [%i0], %i1
F00AF9E4: b8072004                 inc     4, %i4! jumptable F00AF814 case 78
F00AF9E8: f4073ffc                 ld      [%i4-4], %i2
F00AF9EC: f24e8000                 ldsb    [%i2], %i1
F00AF9F0: 80a66000                 cmp     %i1, 0
F00AF9F4: 02bfff68                 be      loc_F00AF794! jumptable F00AF814 cases 1-30,32-41,43-50,52-61,64-70,72,73,75-77,79,81,82
F00AF9F8: b406a001                 inc     %i2
F00AF9FC: 80a6600a                 cmp     %i1, 0xA
F00AFA00: 12800004                 bne     loc_F00AFA10
F00AFA04: 01000000                 nop
F00AFA08: 4000003d                 call    _prom_putchar
F00AFA0C: 9010200d                 mov     0xD, %o0
F00AFA10: 4000003b                 call    _prom_putchar
F00AFA14: 90100019                 mov     %i1, %o0
F00AFA18: f24e8000                 ldsb    [%i2], %i1
F00AFA1C: 80a66000                 cmp     %i1, 0
F00AFA20: 12bffff7                 bne     loc_F00AF9FC
F00AFA24: b406a001                 inc     %i2
F00AFA28: 10bfff5c                 ba      def_F00AF814! jumptable F00AF814 default case
F00AFA2C: f24e0000                 ldsb    [%i0], %i1
F00AFA30: 40000033                 call    _prom_putchar! jumptable F00AF814 case 0
F00AFA34: 90102025                 mov     0x25, %o0 ! '%'
F00AFA38: 10bfff58                 ba      def_F00AF814! jumptable F00AF814 default case
F00AFA3C: f24e0000                 ldsb    [%i0], %i1
F00AFA40: 81c7e008                 ret
F00AFA44: 81e80000                 restore
