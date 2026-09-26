F0018F90: 9de3bf98                 save    %sp, -0x68, %sp
F0018F94: 40000855                 call    _ttynty
F0018F98: 90100019                 mov     %i1, %o0
F0018F9C: e206603c                 ld      [%i1+0x3C], %l1
F0018FA0: 1300080092126020         set     0x200020, %o1
F0018FA8: 808c4009                 btst    %o1, %l1
F0018FAC: 12800007                 bne     loc_F0018FC8
F0018FB0: a4100008                 mov     %o0, %l2
F0018FB4: d204a010                 ld      [%l2+0x10], %o1! FILE *
F0018FB8: 11040000                 sethi   0x10000000, %o0
F0018FBC: 808a4008                 btst    %o0, %o1
F0018FC0: 12800011                 bne     loc_F0019004
F0018FC4: 11008000                 sethi   0x2000000, %o0
F0018FC8: 11002000                 sethi   0x800000, %o0
F0018FCC: 808c4008                 btst    %o0, %l1
F0018FD0: 32800110                 bne,a   locret_F0019410
F0018FD4: b0103fff                 mov     -1, %i0
F0018FD8: 90100018                 mov     %i0, %o0! int
F0018FDC: 40000edd                 call    _putc
F0018FE0: 92066018                 add     %i1, 0x18, %o1
F0018FE4: 80a22000                 cmp     %o0, 0
F0018FE8: 1280010a                 bne     locret_F0019410
F0018FEC: 133c04d0                 sethi   %hi(_tk_nout), %o1
F0018FF0: d0026220                 ld      [%o1+%lo(_tk_nout)], %o0
F0018FF4: b0103fff                 mov     -1, %i0
F0018FF8: 90022001                 inc     %o0
F0018FFC: 10800105                 ba      locret_F0019410
F0019000: d0226220                 st      %o0, [%o1+%lo(_tk_nout)]
F0019004: 808c4008                 btst    %o0, %l1
F0019008: 32800007                 bne,a   loc_F0019024
F001900C: b00e20ff                 and     %i0, 0xFF, %i0
F0019010: 900a6300                 and     %o1, 0x300, %o0
F0019014: 80a22300                 cmp     %o0, 0x300
F0019018: 32800003                 bne,a   loc_F0019024
F001901C: b00e207f                 and     %i0, 0x7F, %i0
F0019020: b00e20ff                 and     %i0, 0xFF, %i0
F0019024: 80a62004                 cmp     %i0, 4
F0019028: 12800005                 bne     loc_F001903C
F001902C: 80a62009                 cmp     %i0, 9
F0019030: 808c6002                 btst    2, %l1
F0019034: 028000f6                 be      loc_F001940C
F0019038: 80a62009                 cmp     %i0, 9
F001903C: 1280002a                 bne     loc_F00190E4
F0019040: 133c04d0                 sethi   %hi(_tk_nout), %o1
F0019044: 900c6c00                 and     %l1, 0xC00, %o0
F0019048: 80a22c00                 cmp     %o0, 0xC00
F001904C: 12800027                 bne     loc_F00190E8
F0019050: d0026220                 ld      [%o1+%lo(_tk_nout)], %o0
F0019054: d2066040                 ld      [%i1+0x40], %o1
F0019058: 11001000                 sethi   0x400000, %o0
F001905C: 808a4008                 btst    %o0, %o1
F0019060: 12800021                 bne     loc_F00190E4
F0019064: 133c04d0                 sethi   -0xFECC000, %o1
F0019068: d00e6048                 ldub    [%i1+0x48], %o0
F001906C: 13002000                 sethi   0x800000, %o1
F0019070: 808c4009                 btst    %o1, %l1
F0019074: 92102008                 mov     8, %o1
F0019078: 900a2007                 and     %o0, 7, %o0
F001907C: 12800011                 bne     loc_F00190C0
F0019080: b0224008                 sub     %o1, %o0, %i0
F0019084: 4001f6cd                 call    _spltty
F0019088: 01000000                 nop
F001908C: a0100008                 mov     %o0, %l0
F0019090: 113c042e90122080         set     asc_F010B880, %o0! "        "
F0019098: 92100018                 mov     %i0, %o1
F001909C: 40000ef8                 call    _b_to_q
F00190A0: 94066018                 add     %i1, 0x18, %o2
F00190A4: b0260008                 sub     %i0, %o0, %i0
F00190A8: 153c04d0                 sethi   %hi(_tk_nout), %o2
F00190AC: d202a220                 ld      [%o2+%lo(_tk_nout)], %o1
F00190B0: 90100010                 mov     %l0, %o0
F00190B4: 92024018                 add     %o1, %i0, %o1
F00190B8: 4001f71b                 call    _splx
F00190BC: d222a220                 st      %o1, [%o2+%lo(_tk_nout)]
F00190C0: 80a62000                 cmp     %i0, 0
F00190C4: d00e6048                 ldub    [%i1+0x48], %o0
F00190C8: 92102009                 mov     9, %o1
F00190CC: 90020018                 add     %o0, %i0, %o0
F00190D0: 02800003                 be      loc_F00190DC
F00190D4: d02e6048                 stb     %o0, [%i1+0x48]
F00190D8: 92103fff                 mov     -1, %o1
F00190DC: 108000cd                 ba      locret_F0019410
F00190E0: b0100009                 mov     %o1, %i0
F00190E4: d0026220                 ld      [%o1+0x220], %o0
F00190E8: 808c6004                 btst    4, %l1
F00190EC: 90022001                 inc     %o0
F00190F0: 02800024                 be      loc_F0019180
F00190F4: d0226220                 st      %o0, [%o1+0x220]
F00190F8: 113c042ea0122090         set     asc_F010B890, %l0! "({)}!|^~'`"
F0019100: 1080000f                 ba      loc_F001913C
F0019104: d04a2090                 ldsb    [%o0+0x90], %o0
F0019108: d04c0000                 ldsb    [%l0], %o0
F001910C: 80a60008                 cmp     %i0, %o0
F0019110: 1280000a                 bne     loc_F0019138
F0019114: a0042001                 inc     %l0
F0019118: 9010205c                 mov     0x5C, %o0 ! '\'
F001911C: 7fffff9d                 call    _ttyoutput
F0019120: 92100019                 mov     %i1, %o1
F0019124: 80a22000                 cmp     %o0, 0
F0019128: 168000ba                 bge     locret_F0019410
F001912C: 01000000                 nop
F0019130: 10800006                 ba      loc_F0019148
F0019134: f04c3ffe                 ldsb    [%l0-2], %i0
F0019138: d04c0000                 ldsb    [%l0], %o0
F001913C: 80a22000                 cmp     %o0, 0
F0019140: 12bffff2                 bne     loc_F0019108
F0019144: a0042001                 inc     %l0
F0019148: 90063fbf                 add     %i0, -0x41, %o0
F001914C: 80a22019                 cmp     %o0, 0x19
F0019150: 18800008                 bgu     loc_F0019170
F0019154: 9010205c                 mov     0x5C, %o0 ! '\'
F0019158: 7fffff8e                 call    _ttyoutput
F001915C: 92100019                 mov     %i1, %o1
F0019160: 80a22000                 cmp     %o0, 0
F0019164: 06800008                 bl      loc_F0019184
F0019168: 80a6200a                 cmp     %i0, 0xA
F001916C: 308000a9                 ba,a    locret_F0019410
F0019170: 90063f9f                 add     %i0, -0x61, %o0
F0019174: 80a22019                 cmp     %o0, 0x19
F0019178: 28800002                 bleu,a  loc_F0019180
F001917C: b0063fe0                 inc     -0x20, %i0
F0019180: 80a6200a                 cmp     %i0, 0xA
F0019184: 12800012                 bne     loc_F00191CC
F0019188: 11002000                 sethi   0x800000, %o0
F001918C: 808c6010                 btst    0x10, %l1
F0019190: 12800007                 bne     loc_F00191AC
F0019194: 9010200d                 mov     0xD, %o0
F0019198: d204a010                 ld      [%l2+0x10], %o1
F001919C: 11080000                 sethi   0x20000000, %o0
F00191A0: 808a4008                 btst    %o0, %o1
F00191A4: 02800009                 be      loc_F00191C8
F00191A8: 9010200d                 mov     0xD, %o0
F00191AC: 7fffff79                 call    _ttyoutput
F00191B0: 92100019                 mov     %i1, %o1! FILE *
F00191B4: 80a22000                 cmp     %o0, 0
F00191B8: 06800005                 bl      loc_F00191CC
F00191BC: 11002000                 sethi   0x800000, %o0
F00191C0: 10800094                 ba      locret_F0019410
F00191C4: b010200a                 mov     0xA, %i0
F00191C8: 11002000                 sethi   0x800000, %o0
F00191CC: 808c4008                 btst    %o0, %l1
F00191D0: 12800008                 bne     loc_F00191F0
F00191D4: 113c042d                 sethi   -0xFEF4C00, %o0
F00191D8: 90100018                 mov     %i0, %o0! int
F00191DC: 40000e5d                 call    _putc
F00191E0: 92066018                 add     %i1, 0x18, %o1
F00191E4: 80a22000                 cmp     %o0, 0
F00191E8: 1280008a                 bne     locret_F0019410
F00191EC: 113c042d                 sethi   -0xFEF4C00, %o0
F00191F0: 901221a0                 bset    0x1A0, %o0
F00191F4: d00e0008                 ldub    [%i0+%o0], %o0
F00191F8: a0102000                 mov     0, %l0
F00191FC: 920a203f                 and     %o0, 0x3F, %o1
F0019200: 80a26006                 cmp     %o1, 6! switch 7 cases
F0019204: 18800073                 bgu     def_F001921C! jumptable F001921C default case, case 1
F0019208: d44e6048                 ldsb    [%i1+0x48], %o2
F001920C: 113c006490122224         set     jpt_F001921C, %o0
F0019214: 932a6002                 sll     %o1, 2, %o1
F0019218: d0024008                 ld      [%o1+%o0], %o0
F001921C: 81c20000                 jmp     %o0! switch jump
F0019220: 01000000                 nop
F0019240: 10800064                 ba      def_F001921C! jumptable F001921C case 0
F0019244: 9402a001                 inc     %o2
F0019248: 80a2a000                 cmp     %o2, 0! jumptable F001921C case 2
F001924C: 34800061                 bg,a    def_F001921C! jumptable F001921C default case, case 1
F0019250: 9402bfff                 inc     -1, %o2
F0019254: 10800060                 ba      loc_F00193D4
F0019258: 80a42000                 cmp     %l0, 0
F001925C: 913c6008                 sra     %l1, 8, %o0! jumptable F001921C case 3
F0019260: 900a2003                 and     %o0, 3, %o0
F0019264: 80a22001                 cmp     %o0, 1
F0019268: 02800006                 be      loc_F0019280
F001926C: 80a22002                 cmp     %o0, 2
F0019270: 0280000d                 be      loc_F00192A4
F0019274: 113c043e                 sethi   -0xFEF0800, %o0
F0019278: 10800056                 ba      def_F001921C! jumptable F001921C default case, case 1
F001927C: 94102000                 mov     0, %o2
F0019280: 80a2a000                 cmp     %o2, 0
F0019284: 04800052                 ble     loc_F00193CC
F0019288: 9132a004                 srl     %o2, 4, %o0
F001928C: a0022003                 add     %o0, 3, %l0
F0019290: 80a42006                 cmp     %l0, 6
F0019294: 3880004e                 bgu,a   loc_F00193CC
F0019298: a0102006                 mov     6, %l0
F001929C: 1080004d                 ba      def_F001921C! jumptable F001921C default case, case 1
F00192A0: 94102000                 mov     0, %o2
F00192A4: d20223e0                 ld      [%o0+0x3E0], %o1
F00192A8: 912a6001                 sll     %o1, 1, %o0
F00192AC: 90020009                 add     %o0, %o1, %o0
F00192B0: 912a2003                 sll     %o0, 3, %o0
F00192B4: 90020009                 add     %o0, %o1, %o0
F00192B8: 912a2002                 sll     %o0, 2, %o0
F00192BC: 10800044                 ba      loc_F00193CC
F00192C0: a13a200a                 sra     %o0, 10, %l0
F00192C4: 900c6c00                 and     %l1, 0xC00, %o0! jumptable F001921C case 4
F00192C8: 80a22400                 cmp     %o0, 0x400
F00192CC: 12800009                 bne     loc_F00192F0
F00192D0: 9002a008                 add     %o2, 8, %o0
F00192D4: 9212bff8                 or      %o2, -8, %o1
F00192D8: 90102001                 mov     1, %o0
F00192DC: a0220009                 sub     %o0, %o1, %l0
F00192E0: 80a42004                 cmp     %l0, 4
F00192E4: 24800002                 ble,a   loc_F00192EC
F00192E8: a0102000                 mov     0, %l0
F00192EC: 9002a008                 add     %o2, 8, %o0
F00192F0: 10800038                 ba      def_F001921C! jumptable F001921C default case, case 1
F00192F4: 940a3ff8                 and     %o0, -8, %o2
F00192F8: 11000010                 sethi   0x4000, %o0! jumptable F001921C case 5
F00192FC: 808c4008                 btst    %o0, %l1
F0019300: 32800034                 bne,a   def_F001921C! jumptable F001921C default case, case 1
F0019304: a010207f                 mov     0x7F, %l0
F0019308: 10800033                 ba      loc_F00193D4
F001930C: 80a42000                 cmp     %l0, 0
F0019310: d006603c                 ld      [%i1+0x3C], %o0! jumptable F001921C case 6
F0019314: 913a200c                 sra     %o0, 12, %o0
F0019318: 900a2003                 and     %o0, 3, %o0
F001931C: 80a22002                 cmp     %o0, 2
F0019320: 22800016                 be,a    loc_F0019378
F0019324: 113c043e                 sethi   -0xFEF0800, %o0
F0019328: 14800007                 bg      loc_F0019344
F001932C: 80a22003                 cmp     %o0, 3
F0019330: 80a22001                 cmp     %o0, 1
F0019334: 02800008                 be      loc_F0019354
F0019338: 113c043e                 sethi   -0xFEF0800, %o0
F001933C: 10800025                 ba      def_F001921C! jumptable F001921C default case, case 1
F0019340: 94102000                 mov     0, %o2
F0019344: 22800015                 be,a    loc_F0019398
F0019348: a010000a                 mov     %o2, %l0
F001934C: 10800021                 ba      def_F001921C! jumptable F001921C default case, case 1
F0019350: 94102000                 mov     0, %o2
F0019354: d20223e0                 ld      [%o0+0x3E0], %o1
F0019358: 912a6002                 sll     %o1, 2, %o0
F001935C: 90020009                 add     %o0, %o1, %o0
F0019360: 912a2002                 sll     %o0, 2, %o0
F0019364: 90020009                 add     %o0, %o1, %o0
F0019368: 912a2002                 sll     %o0, 2, %o0
F001936C: 90220009                 sub     %o0, %o1, %o0
F0019370: 10800017                 ba      loc_F00193CC
F0019374: a13a200a                 sra     %o0, 10, %l0
F0019378: d40223e0                 ld      [%o0+0x3E0], %o2
F001937C: 912aa002                 sll     %o2, 2, %o0
F0019380: 9002000a                 add     %o0, %o2, %o0
F0019384: 932a2005                 sll     %o0, 5, %o1! FILE *
F0019388: 90020009                 add     %o0, %o1, %o0
F001938C: 9002000a                 add     %o0, %o2, %o0
F0019390: 1080000f                 ba      loc_F00193CC
F0019394: a13a200a                 sra     %o0, 10, %l0
F0019398: 80a42000                 cmp     %l0, 0
F001939C: 0680000b                 bl      loc_F00193C8
F00193A0: 80a42008                 cmp     %l0, 8
F00193A4: 3480000a                 bg,a    loc_F00193CC
F00193A8: a0102000                 mov     0, %l0
F00193AC: 9010207f                 mov     0x7F, %o0! int
F00193B0: 40000de8                 call    _putc
F00193B4: 92066018                 add     %i1, 0x18, %o1
F00193B8: a0042001                 inc     %l0
F00193BC: 80a42008                 cmp     %l0, 8
F00193C0: 04bffffc                 ble     loc_F00193B0
F00193C4: 9010207f                 mov     0x7F, %o0
F00193C8: a0102000                 mov     0, %l0
F00193CC: 94102000                 mov     0, %o2
F00193D0: 80a42000                 cmp     %l0, 0! jumptable F001921C default case, case 1
F00193D4: 0280000e                 be      loc_F001940C
F00193D8: d42e6048                 stb     %o2, [%i1+0x48]
F00193DC: d206603c                 ld      [%i1+0x3C], %o1! FILE *
F00193E0: 1100a000                 sethi   0x2800000, %o0
F00193E4: 808a4008                 btst    %o0, %o1
F00193E8: 1280000a                 bne     locret_F0019410
F00193EC: b0103fff                 mov     -1, %i0
F00193F0: d004a010                 ld      [%l2+0x10], %o0
F00193F4: 900a2300                 and     %o0, 0x300, %o0
F00193F8: 80a22300                 cmp     %o0, 0x300
F00193FC: 02800005                 be      locret_F0019410
F0019400: 90142080                 or      %l0, 0x80, %o0! int
F0019404: 40000dd3                 call    _putc
F0019408: 92066018                 add     %i1, 0x18, %o1
F001940C: b0103fff                 mov     -1, %i0
F0019410: 81c7e008                 ret
F0019414: 81e80000                 restore
