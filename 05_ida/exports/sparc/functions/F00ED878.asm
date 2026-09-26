F00ED878: 9de3bf98                 save    %sp, -0x68, %sp
F00ED87C: d0060000                 ld      [%i0], %o0
F00ED880: d4020000                 ld      [%o0], %o2
F00ED884: d0062010                 ld      [%i0+0x10], %o0
F00ED888: 9fc28000                 call    %o2
F00ED88C: 92100019                 mov     %i1, %o1
F00ED890: 7ffc6404                 call    _urem
F00ED894: d2062008                 ld      [%i0+8], %o1
F00ED898: a52a2003                 sll     %o0, 3, %l2
F00ED89C: e006200c                 ld      [%i0+0xC], %l0
F00ED8A0: a6048010                 add     %l2, %l0, %l3
F00ED8A4: e2048010                 ld      [%l2+%l0], %l1
F00ED8A8: 40000cac                 call    _NXZoneFromPtr
F00ED8AC: 90100018                 mov     %i0, %o0
F00ED8B0: 80a46000                 cmp     %l1, 0
F00ED8B4: 1280000a                 bne     loc_F00ED8DC
F00ED8B8: a8100008                 mov     %o0, %l4
F00ED8BC: d0048010                 ld      [%l2+%l0], %o0
F00ED8C0: 90022001                 inc     %o0
F00ED8C4: d0248010                 st      %o0, [%l2+%l0]
F00ED8C8: f224e004                 st      %i1, [%l3+4]
F00ED8CC: d0062004                 ld      [%i0+4], %o0
F00ED8D0: 90022001                 inc     %o0
F00ED8D4: 1080004b                 ba      loc_F00EDA00
F00ED8D8: d0262004                 st      %o0, [%i0+4]
F00ED8DC: 80a46001                 cmp     %l1, 1
F00ED8E0: 32800027                 bne,a   loc_F00ED97C
F00ED8E4: e004e004                 ld      [%l3+4], %l0
F00ED8E8: d404e004                 ld      [%l3+4], %o2
F00ED8EC: 80a6400a                 cmp     %i1, %o2
F00ED8F0: 2280000b                 be,a    loc_F00ED91C
F00ED8F4: f004e004                 ld      [%l3+4], %i0
F00ED8F8: d0060000                 ld      [%i0], %o0
F00ED8FC: d6022004                 ld      [%o0+4], %o3
F00ED900: d0062010                 ld      [%i0+0x10], %o0
F00ED904: 9fc2c000                 call    %o3
F00ED908: 92100019                 mov     %i1, %o1
F00ED90C: 80a22000                 cmp     %o0, 0
F00ED910: 02800005                 be      loc_F00ED924
F00ED914: 90100014                 mov     %l4, %o0
F00ED918: f004e004                 ld      [%l3+4], %i0
F00ED91C: 1080003a                 ba      locret_F00EDA04
F00ED920: f224e004                 st      %i1, [%l3+4]
F00ED924: 92102002                 mov     2, %o1
F00ED928: 40000c94                 call    _NXZoneCalloc
F00ED92C: 94102004                 mov     4, %o2
F00ED930: a0100008                 mov     %o0, %l0
F00ED934: d004e004                 ld      [%l3+4], %o0
F00ED938: d0242004                 st      %o0, [%l0+4]
F00ED93C: 10800024                 ba      loc_F00ED9CC
F00ED940: f2240000                 st      %i1, [%l0]
F00ED944: 80a6400a                 cmp     %i1, %o2
F00ED948: 2280000b                 be,a    loc_F00ED974
F00ED94C: f0040000                 ld      [%l0], %i0
F00ED950: d0060000                 ld      [%i0], %o0
F00ED954: d6022004                 ld      [%o0+4], %o3
F00ED958: d0062010                 ld      [%i0+0x10], %o0
F00ED95C: 9fc2c000                 call    %o3
F00ED960: 92100019                 mov     %i1, %o1
F00ED964: 80a22000                 cmp     %o0, 0
F00ED968: 22800005                 be,a    loc_F00ED97C
F00ED96C: a0042004                 inc     4, %l0
F00ED970: f0040000                 ld      [%l0], %i0
F00ED974: 10800024                 ba      locret_F00EDA04
F00ED978: f2240000                 st      %i1, [%l0]
F00ED97C: a2047fff                 inc     -1, %l1
F00ED980: 80a47fff                 cmp     %l1, -1
F00ED984: 32bffff0                 bne,a   loc_F00ED944
F00ED988: d4040000                 ld      [%l0], %o2
F00ED98C: d204c000                 ld      [%l3], %o1
F00ED990: 90100014                 mov     %l4, %o0
F00ED994: 92026001                 inc     %o1
F00ED998: 40000c78                 call    _NXZoneCalloc
F00ED99C: 94102004                 mov     4, %o2
F00ED9A0: d404c000                 ld      [%l3], %o2! __len
F00ED9A4: 80a2a000                 cmp     %o2, 0
F00ED9A8: 02800006                 be      loc_F00ED9C0
F00ED9AC: a0100008                 mov     %o0, %l0
F00ED9B0: 90042004                 add     %l0, 4, %o0! void *
F00ED9B4: d204e004                 ld      [%l3+4], %o1! __src
F00ED9B8: 7ffc6986                 call    _memmove
F00ED9BC: 952aa002                 sll     %o2, 2, %o2
F00ED9C0: f2240000                 st      %i1, [%l0]
F00ED9C4: 7ffdea4f                 call    _free
F00ED9C8: d004e004                 ld      [%l3+4], %o0
F00ED9CC: d004c000                 ld      [%l3], %o0
F00ED9D0: 90022001                 inc     %o0
F00ED9D4: d024c000                 st      %o0, [%l3]
F00ED9D8: e024e004                 st      %l0, [%l3+4]
F00ED9DC: d0062004                 ld      [%i0+4], %o0
F00ED9E0: 90022001                 inc     %o0
F00ED9E4: d0262004                 st      %o0, [%i0+4]
F00ED9E8: d2062008                 ld      [%i0+8], %o1
F00ED9EC: 80a20009                 cmp     %o0, %o1
F00ED9F0: 28800005                 bleu,a  locret_F00EDA04
F00ED9F4: b0102000                 mov     0, %i0
F00ED9F8: 7fffff65                 call    sub_F00ED78C
F00ED9FC: 90100018                 mov     %i0, %o0
F00EDA00: b0102000                 mov     0, %i0
F00EDA04: 81c7e008                 ret
F00EDA08: 81e80000                 restore
