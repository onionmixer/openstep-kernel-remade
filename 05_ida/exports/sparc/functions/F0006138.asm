F0006138: 80a20009                 cmp     %o0, %o1
F000613C: 02800030                 be      locret_F00061FC
F0006140: 80a2a007                 cmp     %o2, 7
F0006144: 24800024                 ble,a   loc_F00061D4
F0006148: 92224008                 sub     %o1, %o0, %o1
F000614C: 968a2003                 andcc   %o0, 3, %o3
F0006150: 22800045                 be,a    loc_F0006264
F0006154: 988a6003                 andcc   %o1, 3, %o4
F0006158: 80a2e002                 cmp     %o3, 2
F000615C: 0280000c                 be      loc_F000618C
F0006160: 80a2e003                 cmp     %o3, 3
F0006164: d84a0000                 ldsb    [%o0], %o4
F0006168: 90022001                 inc     %o0
F000616C: da4a4000                 ldsb    [%o1], %o5
F0006170: 92026001                 inc     %o1
F0006174: 9422a001                 dec     %o2
F0006178: 02800014                 be      loc_F00061C8
F000617C: 80a3000d                 cmp     %o4, %o5
F0006180: 02800003                 be      loc_F000618C
F0006184: 01000000                 nop
F0006188: 30800035                 ba,a    locret_F000625C
F000618C: d8520000                 ldsh    [%o0], %o4
F0006190: 90022002                 inc     2, %o0
F0006194: da4a4000                 ldsb    [%o1], %o5
F0006198: 92026001                 inc     %o1
F000619C: 973b2008                 sra     %o4, 8, %o3
F00061A0: 80a2c00d                 cmp     %o3, %o5
F00061A4: 22800004                 be,a    loc_F00061B4
F00061A8: da4a4000                 ldsb    [%o1], %o5
F00061AC: 1080002c                 ba      locret_F000625C
F00061B0: 9810000b                 mov     %o3, %o4
F00061B4: 92026001                 inc     %o1
F00061B8: 9422a002                 dec     2, %o2
F00061BC: 992b2018                 sll     %o4, 24, %o4
F00061C0: 993b2018                 sra     %o4, 24, %o4
F00061C4: 80a3000d                 cmp     %o4, %o5
F00061C8: 22800027                 be,a    loc_F0006264
F00061CC: 988a6003                 andcc   %o1, 3, %o4
F00061D0: 30800023                 ba,a    locret_F000625C
F00061D4: 10800008                 ba      loc_F00061F4
F00061D8: 94a2a001                 deccc   %o2
F00061DC: da4a0009                 ldsb    [%o0+%o1], %o5
F00061E0: 90022001                 inc     %o0
F00061E4: 80a3000d                 cmp     %o4, %o5
F00061E8: 22800003                 be,a    loc_F00061F4
F00061EC: 94a2a001                 deccc   %o2
F00061F0: 3080001b                 ba,a    locret_F000625C
F00061F4: 36bffffa                 bge,a   loc_F00061DC
F00061F8: d84a0000                 ldsb    [%o0], %o4
F00061FC: 81c3e008                 retl
F0006200: 90100000                 clr     %o0
F0006204: 933b2018                 sra     %o4, 24, %o1
F0006208: 953b6018                 sra     %o5, 24, %o2
F000620C: 80a2400a                 cmp     %o1, %o2
F0006210: 12800011                 bne     locret_F0006254
F0006214: 992b2008                 sll     %o4, 8, %o4
F0006218: 9b2b6008                 sll     %o5, 8, %o5
F000621C: 933b2018                 sra     %o4, 24, %o1
F0006220: 953b6018                 sra     %o5, 24, %o2
F0006224: 80a2400a                 cmp     %o1, %o2
F0006228: 1280000b                 bne     locret_F0006254
F000622C: 992b2008                 sll     %o4, 8, %o4
F0006230: 9b2b6008                 sll     %o5, 8, %o5
F0006234: 933b2018                 sra     %o4, 24, %o1
F0006238: 953b6018                 sra     %o5, 24, %o2
F000623C: 80a2400a                 cmp     %o1, %o2
F0006240: 12800005                 bne     locret_F0006254
F0006244: 992b2008                 sll     %o4, 8, %o4
F0006248: 9b2b6008                 sll     %o5, 8, %o5
F000624C: 933b2018                 sra     %o4, 24, %o1
F0006250: 953b6018                 sra     %o5, 24, %o2
F0006254: 81c3e008                 retl
F0006258: 9022400a                 sub     %o1, %o2, %o0
F000625C: 81c3e008                 retl
F0006260: 9023000d                 sub     %o4, %o5, %o0
F0006264: 962aa003                 andn    %o2, 3, %o3
F0006268: 940aa003                 and     %o2, 3, %o2
F000626C: 02800039                 be      loc_F0006350
F0006270: 80a32002                 cmp     %o4, 2
F0006274: 02800026                 be      loc_F000630C
F0006278: 80a32001                 cmp     %o4, 1
F000627C: c20a4000                 ldub    [%o1], %g1
F0006280: 92026001                 inc     %o1
F0006284: 02800010                 be      loc_F00062C4
F0006288: 9b286018                 sll     %g1, 24, %o5
F000628C: 92224008                 sub     %o1, %o0, %o1
F0006290: c2020009                 ld      [%o0+%o1], %g1
F0006294: d8020000                 ld      [%o0], %o4
F0006298: 90022004                 inc     4, %o0
F000629C: 85306008                 srl     %g1, 8, %g2
F00062A0: 9a10800d                 bset    %g2, %o5
F00062A4: 80a3000d                 cmp     %o4, %o5
F00062A8: 12bfffd7                 bne     loc_F0006204
F00062AC: 96a2e004                 deccc   4, %o3
F00062B0: 12bffff8                 bne     loc_F0006290
F00062B4: 9b286018                 sll     %g1, 24, %o5
F00062B8: 92226001                 dec     %o1
F00062BC: 10bfffce                 ba      loc_F00061F4
F00062C0: 94a2a001                 deccc   %o2
F00062C4: c2124000                 lduh    [%o1], %g1
F00062C8: 92026002                 inc     2, %o1
F00062CC: 85286008                 sll     %g1, 8, %g2
F00062D0: 9a134002                 bset    %g2, %o5
F00062D4: 92224008                 sub     %o1, %o0, %o1
F00062D8: c2020009                 ld      [%o0+%o1], %g1
F00062DC: d8020000                 ld      [%o0], %o4
F00062E0: 90022004                 inc     4, %o0
F00062E4: 85306018                 srl     %g1, 24, %g2
F00062E8: 9a10800d                 bset    %g2, %o5
F00062EC: 80a3000d                 cmp     %o4, %o5
F00062F0: 12bfffc5                 bne     loc_F0006204
F00062F4: 96a2e004                 deccc   4, %o3
F00062F8: 12bffff8                 bne     loc_F00062D8
F00062FC: 9b286008                 sll     %g1, 8, %o5
F0006300: 92226003                 dec     3, %o1
F0006304: 10bfffbc                 ba      loc_F00061F4
F0006308: 94a2a001                 deccc   %o2
F000630C: c2124000                 lduh    [%o1], %g1
F0006310: 92026002                 inc     2, %o1
F0006314: 9b286010                 sll     %g1, 16, %o5
F0006318: 92224008                 sub     %o1, %o0, %o1
F000631C: c2020009                 ld      [%o0+%o1], %g1
F0006320: d8020000                 ld      [%o0], %o4
F0006324: 90022004                 inc     4, %o0
F0006328: 85306010                 srl     %g1, 16, %g2
F000632C: 9a10800d                 bset    %g2, %o5
F0006330: 80a3000d                 cmp     %o4, %o5
F0006334: 12bfffb4                 bne     loc_F0006204
F0006338: 96a2e004                 deccc   4, %o3
F000633C: 12bffff8                 bne     loc_F000631C
F0006340: 9b286010                 sll     %g1, 16, %o5
F0006344: 92226002                 dec     2, %o1
F0006348: 10bfffab                 ba      loc_F00061F4
F000634C: 94a2a001                 deccc   %o2
F0006350: 92224008                 sub     %o1, %o0, %o1
F0006354: da020009                 ld      [%o0+%o1], %o5
F0006358: d8020000                 ld      [%o0], %o4
F000635C: 90022004                 inc     4, %o0
F0006360: 80a3000d                 cmp     %o4, %o5
F0006364: 12bfffa8                 bne     loc_F0006204
F0006368: 96a2e004                 deccc   4, %o3
F000636C: 32bffffb                 bne,a   loc_F0006358
F0006370: da020009                 ld      [%o0+%o1], %o5
F0006374: 10bfffa0                 ba      loc_F00061F4
F0006378: 94a2a001                 deccc   %o2
