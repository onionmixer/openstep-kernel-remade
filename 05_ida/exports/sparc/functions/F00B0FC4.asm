F00B0FC4: 9de3bf98                 save    %sp, -0x68, %sp
F00B0FC8: 80a63fff                 cmp     %i0, -1
F00B0FCC: 12800005                 bne     loc_F00B0FE0
F00B0FD0: 94100019                 mov     %i1, %o2
F00B0FD4: 113c0471                 sethi   %hi(aVirtual), %o0! "virtual"
F00B0FD8: 1080002f                 ba      loc_F00B1094
F00B0FDC: 96122220                 or      %o0, %lo(aVirtual), %o3! "virtual"
F00B0FE0: 113c047190122218         set     _ukbuf, %o0! "space #"
F00B0FE8: 96100008                 mov     %o0, %o3
F00B0FEC: 920e200f                 and     %i0, 0xF, %o1
F00B0FF0: 113c047190122228         set     a0123456789abcd_1, %o0! "0123456789ABCDEF"
F00B0FF8: d20a4008                 ldub    [%o1+%o0], %o1
F00B0FFC: 113c04f8                 sethi   %hi(_cpu), %o0
F00B1000: d0022120                 ld      [%o0+%lo(_cpu)], %o0
F00B1004: 80a22072                 cmp     %o0, 0x72 ! 'r'
F00B1008: 12800023                 bne     loc_F00B1094
F00B100C: d22ae006                 stb     %o1, [%o3+6]
F00B1010: 80a6200e                 cmp     %i0, 0xE
F00B1014: 2280000d                 be,a    loc_F00B1048
F00B1018: 113c0471                 sethi   -0xFEE3C00, %o0
F00B101C: 18800006                 bgu     loc_F00B1034
F00B1020: 80a62000                 cmp     %i0, 0
F00B1024: 02800009                 be      loc_F00B1048
F00B1028: 113c0471                 sethi   -0xFEE3C00, %o0
F00B102C: 1080001b                 ba      loc_F00B1098
F00B1030: 113c0471                 sethi   -0xFEE3C00, %o0
F00B1034: 80a6200f                 cmp     %i0, 0xF
F00B1038: 0280000d                 be      loc_F00B106C
F00B103C: 113c3fff                 sethi   -0xF000400, %o0
F00B1040: 10800016                 ba      loc_F00B1098
F00B1044: 113c0471                 sethi   -0xFEE3C00, %o0
F00B1048: 96122248                 or      %o0, 0x248, %o3
F00B104C: 9332a01c                 srl     %o2, 28, %o1
F00B1050: 113c047190122258         set     a0123456789abcd_2, %o0! "0123456789abcdef"
F00B1058: d20a4008                 ldub    [%o1+%o0], %o1
F00B105C: 113c0000                 sethi   -0x10000000, %o0
F00B1060: 942a8008                 bclr    %o0, %o2
F00B1064: 1080000c                 ba      loc_F00B1094
F00B1068: d22ae00a                 stb     %o1, [%o3+0xA]
F00B106C: 901223ff                 bset    0x3FF, %o0
F00B1070: 80a28008                 cmp     %o2, %o0
F00B1074: 18800004                 bgu     loc_F00B1084
F00B1078: 113c0471                 sethi   %hi(aSys), %o0! "sys"
F00B107C: 10800006                 ba      loc_F00B1094
F00B1080: 96122270                 or      %o0, %lo(aSys), %o3! "sys"
F00B1084: 113c047196122278         set     aObio_0, %o3! "obio"
F00B108C: 1103c000                 sethi   0xF000000, %o0
F00B1090: 94028008                 add     %o2, %o0, %o2
F00B1094: 113c0471                 sethi   -0xFEE3C00, %o0
F00B1098: 90122280                 bset    0x280, %o0! char *
F00B109C: 7ffd8d6f                 call    _printf
F00B10A0: 9210000b                 mov     %o3, %o1
F00B10A4: 81c7e008                 ret
F00B10A8: 81e80000                 restore
