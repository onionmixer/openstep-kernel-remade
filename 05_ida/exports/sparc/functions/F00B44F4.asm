F00B44F4: 9de3bf98                 save    %sp, -0x68, %sp
F00B44F8: 96100019                 mov     %i1, %o3
F00B44FC: b32e6010                 sll     %i1, 16, %i1
F00B4500: b33e6010                 sra     %i1, 16, %i1
F00B4504: 80a67fff                 cmp     %i1, -1
F00B4508: 12800003                 bne     loc_F00B4514
F00B450C: 94102000                 mov     0, %o2
F00B4510: 96102000                 mov     0, %o3
F00B4514: d2062084                 ld      [%i0+0x84], %o1
F00B4518: d0062088                 ld      [%i0+0x88], %o0
F00B451C: 80a24008                 cmp     %o1, %o0
F00B4520: 0880001e                 bleu    loc_F00B4598
F00B4524: b210000b                 mov     %o3, %i1
F00B4528: 912e6010                 sll     %i1, 16, %o0
F00B452C: 973a2010                 sra     %o0, 16, %o3
F00B4530: 912e6010                 sll     %i1, 16, %o0
F00B4534: 913a200e                 sra     %o0, 14, %o0
F00B4538: 90020018                 add     %o0, %i0, %o0
F00B453C: d80220b8                 ld      [%o0+0xB8], %o4
F00B4540: 80a32000                 cmp     %o4, 0
F00B4544: 02800008                 be      loc_F00B4564
F00B4548: 90066001                 add     %i1, 1, %o0
F00B454C: d013205c                 lduh    [%o4+0x5C], %o0
F00B4550: 808a2010                 btst    0x10, %o0
F00B4554: 12800004                 bne     loc_F00B4564
F00B4558: 90066001                 add     %i1, 1, %o0
F00B455C: 10800003                 ba      loc_F00B4568
F00B4560: 9402a001                 inc     %o2
F00B4564: b20a203f                 and     %o0, 0x3F, %i1
F00B4568: 912aa010                 sll     %o2, 16, %o0
F00B456C: 933a2010                 sra     %o0, 16, %o1
F00B4570: 80a26000                 cmp     %o1, 0
F00B4574: 12800007                 bne     loc_F00B4590
F00B4578: 912e6010                 sll     %i1, 16, %o0
F00B457C: 913a2010                 sra     %o0, 16, %o0
F00B4580: 80a2000b                 cmp     %o0, %o3
F00B4584: 12bfffec                 bne     loc_F00B4534
F00B4588: 912e6010                 sll     %i1, 16, %o0
F00B458C: 80a26000                 cmp     %o1, 0
F00B4590: 32800004                 bne,a   loc_F00B45A0
F00B4594: f23620b2                 sth     %i1, [%i0+0xB2]
F00B4598: 10800023                 ba      locret_F00B4624
F00B459C: b0102000                 mov     0, %i0
F00B45A0: d64b202b                 ldsb    [%o4+0x2B], %o3
F00B45A4: 80a2e000                 cmp     %o3, 0
F00B45A8: 0680001c                 bl      loc_F00B4618
F00B45AC: 133c04d1                 sethi   %hi(_dk_xfer), %o1
F00B45B0: 92126080                 bset    %lo(_dk_xfer), %o1
F00B45B4: 9b2ae002                 sll     %o3, 2, %o5
F00B45B8: d0034009                 ld      [%o5+%o1], %o0
F00B45BC: 153c04d0                 sethi   %hi(_dk_busy), %o2
F00B45C0: 90022001                 inc     %o0
F00B45C4: d0234009                 st      %o0, [%o5+%o1]
F00B45C8: 90102001                 mov     1, %o0
F00B45CC: d202a050                 ld      [%o2+%lo(_dk_busy)], %o1
F00B45D0: 912a000b                 sll     %o0, %o3, %o0
F00B45D4: 92124008                 bset    %o0, %o1
F00B45D8: d013205c                 lduh    [%o4+0x5C], %o0
F00B45DC: 808a2002                 btst    2, %o0
F00B45E0: 12800007                 bne     loc_F00B45FC
F00B45E4: d222a050                 st      %o1, [%o2+%lo(_dk_busy)]
F00B45E8: 133c04fb921261a0         set     _dk_read, %o1
F00B45F0: d0034009                 ld      [%o5+%o1], %o0
F00B45F4: 90022001                 inc     %o0
F00B45F8: d0234009                 st      %o0, [%o5+%o1]
F00B45FC: 153c04d1                 sethi   %hi(_dk_wds), %o2
F00B4600: d2032040                 ld      [%o4+0x40], %o1
F00B4604: 9412a000                 bset    %lo(_dk_wds), %o2
F00B4608: d003400a                 ld      [%o5+%o2], %o0
F00B460C: 93326006                 srl     %o1, 6, %o1
F00B4610: 90020009                 add     %o0, %o1, %o0
F00B4614: d023400a                 st      %o0, [%o5+%o2]
F00B4618: 40000005                 call    _esp_startcmd
F00B461C: 90100018                 mov     %i0, %o0
F00B4620: b0100008                 mov     %o0, %i0
F00B4624: 81c7e008                 ret
F00B4628: 81e80000                 restore
