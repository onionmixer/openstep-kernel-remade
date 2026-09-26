F00AB218: 9de3bf98                 save    %sp, -0x68, %sp
F00AB21C: d2066004                 ld      [%i1+4], %o1
F00AB220: d006a004                 ld      [%i2+4], %o0
F00AB224: 80a24008                 cmp     %o1, %o0
F00AB228: 36800006                 bge,a   loc_F00AB240
F00AB22C: d0064000                 ld      [%i1], %o0
F00AB230: 9010001a                 mov     %i2, %o0
F00AB234: b4100019                 mov     %i1, %i2
F00AB238: b2100008                 mov     %o0, %i1
F00AB23C: d0064000                 ld      [%i1], %o0
F00AB240: d026c000                 st      %o0, [%i3]
F00AB244: d0066004                 ld      [%i1+4], %o0
F00AB248: d026e004                 st      %o0, [%i3+4]
F00AB24C: d0066008                 ld      [%i1+8], %o0
F00AB250: d026e008                 st      %o0, [%i3+8]
F00AB254: d006600c                 ld      [%i1+0xC], %o0
F00AB258: d026e00c                 st      %o0, [%i3+0xC]
F00AB25C: d0066010                 ld      [%i1+0x10], %o0
F00AB260: d026e010                 st      %o0, [%i3+0x10]
F00AB264: d0066014                 ld      [%i1+0x14], %o0
F00AB268: d026e014                 st      %o0, [%i3+0x14]
F00AB26C: d0066018                 ld      [%i1+0x18], %o0
F00AB270: d026e018                 st      %o0, [%i3+0x18]
F00AB274: d006601c                 ld      [%i1+0x1C], %o0
F00AB278: d206e004                 ld      [%i3+4], %o1
F00AB27C: d026e01c                 st      %o0, [%i3+0x1C]
F00AB280: d0066020                 ld      [%i1+0x20], %o0
F00AB284: 80a26002                 cmp     %o1, 2
F00AB288: 0280000f                 be      loc_F00AB2C4
F00AB28C: d026e020                 st      %o0, [%i3+0x20]
F00AB290: 80a26002                 cmp     %o1, 2
F00AB294: 18800006                 bgu     loc_F00AB2AC
F00AB298: 80a26000                 cmp     %o1, 0
F00AB29C: 22800013                 be,a    loc_F00AB2E8
F00AB2A0: d0062004                 ld      [%i0+4], %o0
F00AB2A4: 10800017                 ba      loc_F00AB300
F00AB2A8: d006a004                 ld      [%i2+4], %o0
F00AB2AC: 80a26005                 cmp     %o1, 5
F00AB2B0: 18800013                 bgu     loc_F00AB2FC
F00AB2B4: 80a26004                 cmp     %o1, 4
F00AB2B8: 2a800012                 bcs,a   loc_F00AB300
F00AB2BC: d006a004                 ld      [%i2+4], %o0
F00AB2C0: 308000b9                 ba,a    locret_F00AB5A4
F00AB2C4: d006a004                 ld      [%i2+4], %o0
F00AB2C8: 80a22002                 cmp     %o0, 2
F00AB2CC: 128000b6                 bne     locret_F00AB5A4
F00AB2D0: 90100018                 mov     %i0, %o0
F00AB2D4: 40000e04                 call    _fpu_error_nan
F00AB2D8: 9210001b                 mov     %i3, %o1
F00AB2DC: 90102004                 mov     4, %o0
F00AB2E0: 108000b1                 ba      locret_F00AB5A4
F00AB2E4: d026e004                 st      %o0, [%i3+4]
F00AB2E8: 901a2003                 btog    3, %o0
F00AB2EC: 80a00008                 cmp     %g0, %o0
F00AB2F0: 90603fff                 subc    %g0, -1, %o0
F00AB2F4: 108000ac                 ba      locret_F00AB5A4
F00AB2F8: d026c000                 st      %o0, [%i3]
F00AB2FC: d006a004                 ld      [%i2+4], %o0
F00AB300: 80a22000                 cmp     %o0, 0
F00AB304: 028000a8                 be      locret_F00AB5A4
F00AB308: 01000000                 nop
F00AB30C: d2066008                 ld      [%i1+8], %o1
F00AB310: d006a008                 ld      [%i2+8], %o0
F00AB314: 80a24008                 cmp     %o1, %o0
F00AB318: 36800006                 bge,a   loc_F00AB330
F00AB31C: d0066004                 ld      [%i1+4], %o0
F00AB320: 9010001a                 mov     %i2, %o0
F00AB324: b4100019                 mov     %i1, %i2
F00AB328: b2100008                 mov     %o0, %i1
F00AB32C: d0066004                 ld      [%i1+4], %o0
F00AB330: d026e004                 st      %o0, [%i3+4]
F00AB334: d0064000                 ld      [%i1], %o0
F00AB338: d026c000                 st      %o0, [%i3]
F00AB33C: d0066008                 ld      [%i1+8], %o0
F00AB340: d026e008                 st      %o0, [%i3+8]
F00AB344: c026e01c                 clr     [%i3+0x1C]
F00AB348: c026e020                 clr     [%i3+0x20]
F00AB34C: d0066008                 ld      [%i1+8], %o0
F00AB350: d406a008                 ld      [%i2+8], %o2
F00AB354: 80a2000a                 cmp     %o0, %o2
F00AB358: 12800042                 bne     loc_F00AB460
F00AB35C: a606e00c                 add     %i3, 0xC, %l3
F00AB360: a206e018                 add     %i3, 0x18, %l1
F00AB364: d2066018                 ld      [%i1+0x18], %o1
F00AB368: 90100011                 mov     %l1, %o0
F00AB36C: d406a018                 ld      [%i2+0x18], %o2
F00AB370: 40000df9                 call    _fpu_sub3wc
F00AB374: 96102000                 mov     0, %o3
F00AB378: 96100008                 mov     %o0, %o3
F00AB37C: d2066014                 ld      [%i1+0x14], %o1
F00AB380: a406e014                 add     %i3, 0x14, %l2
F00AB384: d406a014                 ld      [%i2+0x14], %o2
F00AB388: 40000df3                 call    _fpu_sub3wc
F00AB38C: 90100012                 mov     %l2, %o0
F00AB390: 96100008                 mov     %o0, %o3
F00AB394: d2066010                 ld      [%i1+0x10], %o1
F00AB398: a006e010                 add     %i3, 0x10, %l0
F00AB39C: d406a010                 ld      [%i2+0x10], %o2
F00AB3A0: 40000ded                 call    _fpu_sub3wc
F00AB3A4: 90100010                 mov     %l0, %o0
F00AB3A8: d206600c                 ld      [%i1+0xC], %o1
F00AB3AC: 96100008                 mov     %o0, %o3
F00AB3B0: d406a00c                 ld      [%i2+0xC], %o2
F00AB3B4: 40000de8                 call    _fpu_sub3wc
F00AB3B8: 90100013                 mov     %l3, %o0
F00AB3BC: d606e00c                 ld      [%i3+0xC], %o3
F00AB3C0: d006e010                 ld      [%i3+0x10], %o0
F00AB3C4: d406e014                 ld      [%i3+0x14], %o2
F00AB3C8: d206e018                 ld      [%i3+0x18], %o1
F00AB3CC: 9012c008                 bset    %o3, %o0
F00AB3D0: 9012000a                 bset    %o2, %o0
F00AB3D4: 80920009                 orcc    %o0, %o1, %g0
F00AB3D8: 12800009                 bne     loc_F00AB3FC
F00AB3DC: 1100007f                 sethi   0x1FC00, %o0
F00AB3E0: d0062004                 ld      [%i0+4], %o0
F00AB3E4: 901a2003                 btog    3, %o0
F00AB3E8: 80a00008                 cmp     %g0, %o0
F00AB3EC: 90603fff                 subc    %g0, -1, %o0
F00AB3F0: d026c000                 st      %o0, [%i3]
F00AB3F4: 1080006c                 ba      locret_F00AB5A4
F00AB3F8: c026e004                 clr     [%i3+4]
F00AB3FC: 901223ff                 bset    0x3FF, %o0
F00AB400: 80a2c008                 cmp     %o3, %o0
F00AB404: 08800066                 bleu    loc_F00AB59C
F00AB408: 90100011                 mov     %l1, %o0
F00AB40C: d6068000                 ld      [%i2], %o3
F00AB410: 94102000                 mov     0, %o2
F00AB414: d206e018                 ld      [%i3+0x18], %o1
F00AB418: 40000ddd                 call    _fpu_neg2wc
F00AB41C: d626c000                 st      %o3, [%i3]
F00AB420: 96100008                 mov     %o0, %o3
F00AB424: 90100012                 mov     %l2, %o0
F00AB428: d206e014                 ld      [%i3+0x14], %o1
F00AB42C: 40000dd8                 call    _fpu_neg2wc
F00AB430: 9410000b                 mov     %o3, %o2
F00AB434: 96100008                 mov     %o0, %o3
F00AB438: 90100010                 mov     %l0, %o0
F00AB43C: d206e010                 ld      [%i3+0x10], %o1
F00AB440: 40000dd3                 call    _fpu_neg2wc
F00AB444: 9410000b                 mov     %o3, %o2
F00AB448: 96100008                 mov     %o0, %o3
F00AB44C: 90100013                 mov     %l3, %o0
F00AB450: d206e00c                 ld      [%i3+0xC], %o1
F00AB454: 40000dce                 call    _fpu_neg2wc
F00AB458: 9410000b                 mov     %o3, %o2
F00AB45C: 30800050                 ba,a    loc_F00AB59C
F00AB460: d206e008                 ld      [%i3+8], %o1
F00AB464: 9010001a                 mov     %i2, %o0
F00AB468: 9222400a                 sub     %o1, %o2, %o1
F00AB46C: 40000d3d                 call    _fpu_rightshift
F00AB470: 92027fff                 inc     -1, %o1
F00AB474: f006a01c                 ld      [%i2+0x1C], %i0
F00AB478: 9010001a                 mov     %i2, %o0
F00AB47C: e006a020                 ld      [%i2+0x20], %l0
F00AB480: 40000d38                 call    _fpu_rightshift
F00AB484: 92102001                 mov     1, %o1
F00AB488: 80a42000                 cmp     %l0, 0
F00AB48C: 02800004                 be      loc_F00AB49C
F00AB490: e206a01c                 ld      [%i2+0x1C], %l1
F00AB494: 80a00018                 cmp     %g0, %i0
F00AB498: b0603fff                 subc    %g0, -1, %i0
F00AB49C: a4960010                 orcc    %i0, %l0, %l2
F00AB4A0: 02800003                 be      loc_F00AB4AC
F00AB4A4: 80a00011                 cmp     %g0, %l1
F00AB4A8: a2603fff                 subc    %g0, -1, %l1
F00AB4AC: 90144018                 or      %l1, %i0, %o0
F00AB4B0: 96120010                 or      %o0, %l0, %o3
F00AB4B4: 9006e018                 add     %i3, 0x18, %o0
F00AB4B8: d2066018                 ld      [%i1+0x18], %o1
F00AB4BC: 80a0000b                 cmp     %g0, %o3
F00AB4C0: d406a018                 ld      [%i2+0x18], %o2
F00AB4C4: 40000da4                 call    _fpu_sub3wc
F00AB4C8: 96402000                 addc    %g0, 0, %o3
F00AB4CC: d2066014                 ld      [%i1+0x14], %o1
F00AB4D0: 96100008                 mov     %o0, %o3
F00AB4D4: d406a014                 ld      [%i2+0x14], %o2
F00AB4D8: 40000d9f                 call    _fpu_sub3wc
F00AB4DC: 9006e014                 add     %i3, 0x14, %o0
F00AB4E0: d2066010                 ld      [%i1+0x10], %o1
F00AB4E4: 96100008                 mov     %o0, %o3
F00AB4E8: d406a010                 ld      [%i2+0x10], %o2
F00AB4EC: 40000d9a                 call    _fpu_sub3wc
F00AB4F0: 9006e010                 add     %i3, 0x10, %o0
F00AB4F4: d206600c                 ld      [%i1+0xC], %o1
F00AB4F8: 96100008                 mov     %o0, %o3
F00AB4FC: d406a00c                 ld      [%i2+0xC], %o2
F00AB500: 40000d95                 call    _fpu_sub3wc
F00AB504: 90100013                 mov     %l3, %o0
F00AB508: 1100003f                 sethi   0xFC00, %o0
F00AB50C: d206e00c                 ld      [%i3+0xC], %o1
F00AB510: 961223ff                 or      %o0, 0x3FF, %o3
F00AB514: 80a2400b                 cmp     %o1, %o3
F00AB518: 28800005                 bleu,a  loc_F00AB52C
F00AB51C: e026e020                 st      %l0, [%i3+0x20]
F00AB520: e426e020                 st      %l2, [%i3+0x20]
F00AB524: 10800020                 ba      locret_F00AB5A4
F00AB528: e226e01c                 st      %l1, [%i3+0x1C]
F00AB52C: d006e010                 ld      [%i3+0x10], %o0
F00AB530: f026e01c                 st      %i0, [%i3+0x1C]
F00AB534: d406e010                 ld      [%i3+0x10], %o2
F00AB538: 932a6001                 sll     %o1, 1, %o1
F00AB53C: 9132201f                 srl     %o0, 31, %o0
F00AB540: 92124008                 bset    %o0, %o1
F00AB544: d226e00c                 st      %o1, [%i3+0xC]
F00AB548: d006e014                 ld      [%i3+0x14], %o0
F00AB54C: 952aa001                 sll     %o2, 1, %o2
F00AB550: d206e014                 ld      [%i3+0x14], %o1
F00AB554: 9132201f                 srl     %o0, 31, %o0
F00AB558: 94128008                 bset    %o0, %o2
F00AB55C: d426e010                 st      %o2, [%i3+0x10]
F00AB560: d006e018                 ld      [%i3+0x18], %o0
F00AB564: 932a6001                 sll     %o1, 1, %o1
F00AB568: 9132201f                 srl     %o0, 31, %o0
F00AB56C: 92124008                 bset    %o0, %o1
F00AB570: d006e018                 ld      [%i3+0x18], %o0
F00AB574: d226e014                 st      %o1, [%i3+0x14]
F00AB578: d206e008                 ld      [%i3+8], %o1
F00AB57C: 912a2001                 sll     %o0, 1, %o0
F00AB580: 90120011                 bset    %l1, %o0
F00AB584: d026e018                 st      %o0, [%i3+0x18]
F00AB588: 92027fff                 inc     -1, %o1
F00AB58C: d006e00c                 ld      [%i3+0xC], %o0
F00AB590: 80a2000b                 cmp     %o0, %o3
F00AB594: 18800004                 bgu     locret_F00AB5A4
F00AB598: d226e008                 st      %o1, [%i3+8]
F00AB59C: 40000c8f                 call    _fpu_normalize
F00AB5A0: 9010001b                 mov     %i3, %o0
F00AB5A4: 81c7e008                 ret
F00AB5A8: 81e80000                 restore
