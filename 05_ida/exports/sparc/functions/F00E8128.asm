F00E8128: 9de3bf28                 save    %sp, -0xD8, %sp
F00E812C: f027bfc4                 st      %i0, [%fp+var_3C]
F00E8130: c20621fc                 ld      [%i0+0x1FC], %g1
F00E8134: c227bfbc                 st      %g1, [%fp+var_44]
F00E8138: 7fff6b46                 call    _ev_try_lock
F00E813C: 90006004                 add     %g1, 4, %o0
F00E8140: 80a22000                 cmp     %o0, 0
F00E8144: 02800508                 be      loc_F00E9564
F00E8148: c607bfbc                 ld      [%fp+var_44], %g3
F00E814C: f620c000                 st      %i3, [%g3]
F00E8150: d0168000                 lduh    [%i2], %o0
F00E8154: d030e01c                 sth     %o0, [%g3+0x1C]
F00E8158: d016a002                 lduh    [%i2+2], %o0
F00E815C: d030e01e                 sth     %o0, [%g3+0x1E]
F00E8160: d008e00a                 ldub    [%g3+0xA], %o0
F00E8164: 80a22000                 cmp     %o0, 0
F00E8168: 028002ed                 be      loc_F00E8D1C
F00E816C: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8170: d80061fc                 ld      [%g1+0x1FC], %o4
F00E8174: d0030000                 ld      [%o4], %o0
F00E8178: 912a2002                 sll     %o0, 2, %o0
F00E817C: 9002000c                 add     %o0, %o4, %o0
F00E8180: d4122038                 lduh    [%o0+0x38], %o2
F00E8184: d437bfe8                 sth     %o2, [%fp+var_18]
F00E8188: d612203a                 lduh    [%o0+0x3A], %o3
F00E818C: d637bfea                 sth     %o3, [%fp+var_16]
F00E8190: d213201c                 lduh    [%o4+0x1C], %o1
F00E8194: 9a102000                 mov     0, %o5
F00E8198: 9222400a                 sub     %o1, %o2, %o1
F00E819C: d237bfe0                 sth     %o1, [%fp+var_20]
F00E81A0: 84026010                 add     %o1, 0x10, %g2
F00E81A4: c437bfe2                 sth     %g2, [%fp+var_1E]
F00E81A8: d013201e                 lduh    [%o4+0x1E], %o0
F00E81AC: 932a6010                 sll     %o1, 16, %o1
F00E81B0: 9422000b                 sub     %o0, %o3, %o2
F00E81B4: d437bfe4                 sth     %o2, [%fp+var_1C]
F00E81B8: 9602a010                 add     %o2, 0x10, %o3
F00E81BC: d637bfe6                 sth     %o3, [%fp+var_1A]
F00E81C0: d0132016                 lduh    [%o4+0x16], %o0
F00E81C4: 933a6010                 sra     %o1, 16, %o1
F00E81C8: 912a2010                 sll     %o0, 16, %o0
F00E81CC: 913a2010                 sra     %o0, 16, %o0
F00E81D0: 80a24008                 cmp     %o1, %o0
F00E81D4: 1680001b                 bge     loc_F00E8240
F00E81D8: 01000000                 nop
F00E81DC: d2132014                 lduh    [%o4+0x14], %o1
F00E81E0: 9128a010                 sll     %g2, 16, %o0
F00E81E4: 913a2010                 sra     %o0, 16, %o0
F00E81E8: 932a6010                 sll     %o1, 16, %o1
F00E81EC: 933a6010                 sra     %o1, 16, %o1
F00E81F0: 80a24008                 cmp     %o1, %o0
F00E81F4: 16800013                 bge     loc_F00E8240
F00E81F8: 01000000                 nop
F00E81FC: d013201a                 lduh    [%o4+0x1A], %o0
F00E8200: 932aa010                 sll     %o2, 16, %o1
F00E8204: 933a6010                 sra     %o1, 16, %o1
F00E8208: 912a2010                 sll     %o0, 16, %o0
F00E820C: 913a2010                 sra     %o0, 16, %o0
F00E8210: 80a24008                 cmp     %o1, %o0
F00E8214: 1680000b                 bge     loc_F00E8240
F00E8218: 01000000                 nop
F00E821C: d2132018                 lduh    [%o4+0x18], %o1
F00E8220: 912ae010                 sll     %o3, 16, %o0
F00E8224: 913a2010                 sra     %o0, 16, %o0
F00E8228: 932a6010                 sll     %o1, 16, %o1
F00E822C: 933a6010                 sra     %o1, 16, %o1
F00E8230: 80a24008                 cmp     %o1, %o0
F00E8234: 26800003                 bl,a    loc_F00E8240
F00E8238: 9a102001                 mov     1, %o5
F00E823C: 9a102000                 mov     0, %o5
F00E8240: d00b200b                 ldub    [%o4+0xB], %o0
F00E8244: 912a2018                 sll     %o0, 24, %o0
F00E8248: 913a2018                 sra     %o0, 24, %o0
F00E824C: 80a34008                 cmp     %o5, %o0
F00E8250: 228002b4                 be,a    loc_F00E8D20
F00E8254: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8258: da2b200b                 stb     %o5, [%o4+0xB]
F00E825C: d00b200b                 ldub    [%o4+0xB], %o0
F00E8260: 80a22000                 cmp     %o0, 0
F00E8264: 028000a1                 be      loc_F00E84E8
F00E8268: c607bfc4                 ld      [%fp+var_3C], %g3
F00E826C: d000e1fc                 ld      [%g3+0x1FC], %o0! id
F00E8270: d40a2008                 ldub    [%o0+8], %o2
F00E8274: 9202a001                 add     %o2, 1, %o1
F00E8278: d22a2008                 stb     %o1, [%o0+8]
F00E827C: 80a2a000                 cmp     %o2, 0
F00E8280: 128002a8                 bne     loc_F00E8D20
F00E8284: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8288: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E828C: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E8290: 40002578                 call    _objc_msgSend
F00E8294: d007bfc4                 ld      [%fp+var_3C], %o0
F00E8298: d0022018                 ld      [%o0+0x18], %o0! id
F00E829C: 80a22003                 cmp     %o0, 3
F00E82A0: 18800008                 bgu     loc_F00E82C0
F00E82A4: 80a22002                 cmp     %o0, 2
F00E82A8: 1a80029d                 bcc     loc_F00E8D1C
F00E82AC: 80a22001                 cmp     %o0, 1
F00E82B0: 02800009                 be      loc_F00E82D4
F00E82B4: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1
F00E82B8: 1080029a                 ba      loc_F00E8D20
F00E82BC: c207bfc4                 ld      [%fp+var_3C], %g1
F00E82C0: 80a22004                 cmp     %o0, 4
F00E82C4: 0280004b                 be      loc_F00E83F0
F00E82C8: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E82CC: 10800295                 ba      loc_F00E8D20
F00E82D0: c207bfc4                 ld      [%fp+var_3C], %g1
F00E82D4: 40002567                 call    _objc_msgSend
F00E82D8: d007bfc4                 ld      [%fp+var_3C], %o0
F00E82DC: c207bfc4                 ld      [%fp+var_3C], %g1
F00E82E0: e00061fc                 ld      [%g1+0x1FC], %l0
F00E82E4: d214200c                 lduh    [%l0+0xC], %o1
F00E82E8: d237bfd8                 sth     %o1, [%fp+var_28]
F00E82EC: d214200e                 lduh    [%l0+0xE], %o1
F00E82F0: d237bfda                 sth     %o1, [%fp+var_26]
F00E82F4: d4142010                 lduh    [%l0+0x10], %o2
F00E82F8: a2100008                 mov     %o0, %l1
F00E82FC: d437bfdc                 sth     %o2, [%fp+var_24]
F00E8300: d2142012                 lduh    [%l0+0x12], %o1
F00E8304: 952aa010                 sll     %o2, 16, %o2
F00E8308: d237bfde                 sth     %o1, [%fp+var_22]
F00E830C: e4046008                 ld      [%l1+8], %l2
F00E8310: 953aa010                 sra     %o2, 16, %o2
F00E8314: d2142034                 lduh    [%l0+0x34], %o1
F00E8318: 90100012                 mov     %l2, %o0
F00E831C: 932a6010                 sll     %o1, 16, %o1
F00E8320: 933a6010                 sra     %o1, 16, %o1
F00E8324: 7ffc7877                 call    _umul
F00E8328: 92228009                 sub     %o2, %o1, %o1
F00E832C: d4046014                 ld      [%l1+0x14], %o2
F00E8330: d2142030                 lduh    [%l0+0x30], %o1
F00E8334: 9a042848                 add     %l0, 0x848, %o5
F00E8338: d617bfda                 lduh    [%fp+var_26], %o3
F00E833C: 94028008                 add     %o2, %o0, %o2
F00E8340: 932a6010                 sll     %o1, 16, %o1
F00E8344: d057bfd8                 ldsh    [%fp+var_28], %o0
F00E8348: 933a6010                 sra     %o1, 16, %o1
F00E834C: 92220009                 sub     %o0, %o1, %o1
F00E8350: 98028009                 add     %o2, %o1, %o4
F00E8354: 9622c008                 sub     %o3, %o0, %o3
F00E8358: 932ae010                 sll     %o3, 16, %o1
F00E835C: 933a6010                 sra     %o1, 16, %o1
F00E8360: d017bfde                 lduh    [%fp+var_22], %o0
F00E8364: d417bfdc                 lduh    [%fp+var_24], %o2
F00E8368: 9022000a                 sub     %o0, %o2, %o0
F00E836C: 90023fff                 inc     -1, %o0
F00E8370: 84100008                 mov     %o0, %g2
F00E8374: 912a2010                 sll     %o0, 16, %o0
F00E8378: 913a2010                 sra     %o0, 16, %o0
F00E837C: 80a23fff                 cmp     %o0, -1
F00E8380: 02800267                 be      loc_F00E8D1C
F00E8384: a4248009                 sub     %l2, %o1, %l2
F00E8388: 9002ffff                 add     %o3, -1, %o0
F00E838C: 94100008                 mov     %o0, %o2
F00E8390: 912a2010                 sll     %o0, 16, %o0
F00E8394: 913a2010                 sra     %o0, 16, %o0
F00E8398: 80a23fff                 cmp     %o0, -1
F00E839C: 0280000d                 be      loc_F00E83D0
F00E83A0: 9000bfff                 add     %g2, -1, %o0
F00E83A4: 9002bfff                 add     %o2, -1, %o0
F00E83A8: 94100008                 mov     %o0, %o2
F00E83AC: d20b4000                 ldub    [%o5], %o1! SEL
F00E83B0: 912a2010                 sll     %o0, 16, %o0
F00E83B4: 913a2010                 sra     %o0, 16, %o0
F00E83B8: 80a23fff                 cmp     %o0, -1
F00E83BC: d22b0000                 stb     %o1, [%o4]
F00E83C0: 9a036001                 inc     %o5
F00E83C4: 12bffff8                 bne     loc_F00E83A4
F00E83C8: 98032001                 inc     %o4
F00E83CC: 9000bfff                 add     %g2, -1, %o0
F00E83D0: 84100008                 mov     %o0, %g2
F00E83D4: 912a2010                 sll     %o0, 16, %o0
F00E83D8: 913a2010                 sra     %o0, 16, %o0! id
F00E83DC: 80a23fff                 cmp     %o0, -1
F00E83E0: 12bfffea                 bne     loc_F00E8388
F00E83E4: 98030012                 add     %o4, %l2, %o4
F00E83E8: 1080024e                 ba      loc_F00E8D20
F00E83EC: c207bfc4                 ld      [%fp+var_3C], %g1
F00E83F0: 40002520                 call    _objc_msgSend
F00E83F4: d007bfc4                 ld      [%fp+var_3C], %o0
F00E83F8: c607bfc4                 ld      [%fp+var_3C], %g3
F00E83FC: e000e1fc                 ld      [%g3+0x1FC], %l0
F00E8400: d214200c                 lduh    [%l0+0xC], %o1
F00E8404: d237bfd8                 sth     %o1, [%fp+var_28]
F00E8408: d214200e                 lduh    [%l0+0xE], %o1
F00E840C: d237bfda                 sth     %o1, [%fp+var_26]
F00E8410: d4142010                 lduh    [%l0+0x10], %o2
F00E8414: a2100008                 mov     %o0, %l1
F00E8418: d437bfdc                 sth     %o2, [%fp+var_24]
F00E841C: d2142012                 lduh    [%l0+0x12], %o1
F00E8420: 952aa010                 sll     %o2, 16, %o2
F00E8424: d237bfde                 sth     %o1, [%fp+var_22]
F00E8428: e4046008                 ld      [%l1+8], %l2
F00E842C: 953aa010                 sra     %o2, 16, %o2
F00E8430: d2142034                 lduh    [%l0+0x34], %o1
F00E8434: 90100012                 mov     %l2, %o0
F00E8438: 932a6010                 sll     %o1, 16, %o1
F00E843C: 933a6010                 sra     %o1, 16, %o1
F00E8440: 7ffc7830                 call    _umul
F00E8444: 92228009                 sub     %o2, %o1, %o1
F00E8448: 1300000492126048         set     0x1048, %o1
F00E8450: d4046014                 ld      [%l1+0x14], %o2
F00E8454: 98040009                 add     %l0, %o1, %o4
F00E8458: d2142030                 lduh    [%l0+0x30], %o1
F00E845C: 912a2002                 sll     %o0, 2, %o0
F00E8460: d657bfd8                 ldsh    [%fp+var_28], %o3
F00E8464: 94028008                 add     %o2, %o0, %o2
F00E8468: 932a6010                 sll     %o1, 16, %o1
F00E846C: 933a6010                 sra     %o1, 16, %o1
F00E8470: 9222c009                 sub     %o3, %o1, %o1
F00E8474: 932a6002                 sll     %o1, 2, %o1
F00E8478: d057bfda                 ldsh    [%fp+var_26], %o0
F00E847C: 94028009                 add     %o2, %o1, %o2
F00E8480: d257bfde                 ldsh    [%fp+var_22], %o1
F00E8484: 9a22000b                 sub     %o0, %o3, %o5
F00E8488: d057bfdc                 ldsh    [%fp+var_24], %o0
F00E848C: 92224008                 sub     %o1, %o0, %o1
F00E8490: 92027fff                 inc     -1, %o1
F00E8494: 80a27fff                 cmp     %o1, -1
F00E8498: 02800221                 be      loc_F00E8D1C
F00E849C: a424800d                 sub     %l2, %o5, %l2
F00E84A0: 852ca002                 sll     %l2, 2, %g2
F00E84A4: 96037fff                 add     %o5, -1, %o3
F00E84A8: 80a2ffff                 cmp     %o3, -1
F00E84AC: 2280000a                 be,a    loc_F00E84D4
F00E84B0: 92027fff                 inc     -1, %o1
F00E84B4: 9602ffff                 inc     -1, %o3
F00E84B8: d0030000                 ld      [%o4], %o0
F00E84BC: 80a2ffff                 cmp     %o3, -1
F00E84C0: d0228000                 st      %o0, [%o2]
F00E84C4: 98032004                 inc     4, %o4
F00E84C8: 12bffffb                 bne     loc_F00E84B4
F00E84CC: 9402a004                 inc     4, %o2
F00E84D0: 92027fff                 inc     -1, %o1
F00E84D4: 80a27fff                 cmp     %o1, -1
F00E84D8: 12bffff3                 bne     loc_F00E84A4
F00E84DC: 94028002                 add     %o2, %g2, %o2
F00E84E0: 10800210                 ba      loc_F00E8D20
F00E84E4: c207bfc4                 ld      [%fp+var_3C], %g1
F00E84E8: c207bfc4                 ld      [%fp+var_3C], %g1
F00E84EC: d20061fc                 ld      [%g1+0x1FC], %o1
F00E84F0: d00a6008                 ldub    [%o1+8], %o0
F00E84F4: 80a22000                 cmp     %o0, 0
F00E84F8: 0280020b                 be      loc_F00E8D24
F00E84FC: 01000000                 nop
F00E8500: d00a6008                 ldub    [%o1+8], %o0
F00E8504: 90023fff                 inc     -1, %o0
F00E8508: d02a6008                 stb     %o0, [%o1+8]
F00E850C: d00a6008                 ldub    [%o1+8], %o0
F00E8510: 80a22000                 cmp     %o0, 0
F00E8514: 32800203                 bne,a   loc_F00E8D20
F00E8518: c207bfc4                 ld      [%fp+var_3C], %g1
F00E851C: c60061fc                 ld      [%g1+0x1FC], %g3
F00E8520: d000c000                 ld      [%g3], %o0
F00E8524: 912a2002                 sll     %o0, 2, %o0
F00E8528: 90020003                 add     %o0, %g3, %o0
F00E852C: d2122038                 lduh    [%o0+0x38], %o1
F00E8530: d237bfd0                 sth     %o1, [%fp+var_30]
F00E8534: d012203a                 lduh    [%o0+0x3A], %o0
F00E8538: d037bfd2                 sth     %o0, [%fp+var_2E]
F00E853C: d010e01c                 lduh    [%g3+0x1C], %o0
F00E8540: 90220009                 sub     %o0, %o1, %o0
F00E8544: d030e020                 sth     %o0, [%g3+0x20]
F00E8548: d010e020                 lduh    [%g3+0x20], %o0
F00E854C: 90022010                 inc     0x10, %o0
F00E8550: d030e022                 sth     %o0, [%g3+0x22]
F00E8554: d210e01e                 lduh    [%g3+0x1E], %o1
F00E8558: d417bfd2                 lduh    [%fp+var_2E], %o2
F00E855C: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E8560: d007bfc4                 ld      [%fp+var_3C], %o0! id
F00E8564: 9222400a                 sub     %o1, %o2, %o1
F00E8568: d230e024                 sth     %o1, [%g3+0x24]
F00E856C: d410e024                 lduh    [%g3+0x24], %o2
F00E8570: c627bfb4                 st      %g3, [%fp+var_4C]
F00E8574: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E8578: 9402a010                 inc     0x10, %o2
F00E857C: d430e026                 sth     %o2, [%g3+0x26]
F00E8580: 400024bc                 call    _objc_msgSend
F00E8584: 01000000                 nop
F00E8588: d0022018                 ld      [%o0+0x18], %o0! id
F00E858C: 80a22003                 cmp     %o0, 3
F00E8590: 18800008                 bgu     loc_F00E85B0
F00E8594: 80a22002                 cmp     %o0, 2
F00E8598: 1a8001d8                 bcc     loc_F00E8CF8
F00E859C: 80a22001                 cmp     %o0, 1
F00E85A0: 02800009                 be      loc_F00E85C4
F00E85A4: d20423ac                 ld      [%l0+0x3AC], %o1
F00E85A8: 108001d5                 ba      loc_F00E8CFC
F00E85AC: c607bfb4                 ld      [%fp+var_4C], %g3
F00E85B0: 80a22004                 cmp     %o0, 4
F00E85B4: 028000f2                 be      loc_F00E897C
F00E85B8: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E85BC: 108001d0                 ba      loc_F00E8CFC
F00E85C0: c607bfb4                 ld      [%fp+var_4C], %g3
F00E85C4: 400024ab                 call    _objc_msgSend
F00E85C8: d007bfc4                 ld      [%fp+var_3C], %o0
F00E85CC: c207bfc4                 ld      [%fp+var_3C], %g1
F00E85D0: e00061fc                 ld      [%g1+0x1FC], %l0
F00E85D4: d8142020                 lduh    [%l0+0x20], %o4
F00E85D8: d837bfc8                 sth     %o4, [%fp+var_38]
F00E85DC: da142022                 lduh    [%l0+0x22], %o5
F00E85E0: da37bfca                 sth     %o5, [%fp+var_36]
F00E85E4: d4142024                 lduh    [%l0+0x24], %o2
F00E85E8: a2100008                 mov     %o0, %l1
F00E85EC: d437bfcc                 sth     %o2, [%fp+var_34]
F00E85F0: d6142026                 lduh    [%l0+0x26], %o3
F00E85F4: 952aa010                 sll     %o2, 16, %o2
F00E85F8: d637bfce                 sth     %o3, [%fp+var_32]
F00E85FC: d2142034                 lduh    [%l0+0x34], %o1
F00E8600: 953aa010                 sra     %o2, 16, %o2
F00E8604: 932a6010                 sll     %o1, 16, %o1
F00E8608: 933a6010                 sra     %o1, 16, %o1
F00E860C: 80a28009                 cmp     %o2, %o1
F00E8610: 16800004                 bge     loc_F00E8620
F00E8614: 01000000                 nop
F00E8618: d0142034                 lduh    [%l0+0x34], %o0
F00E861C: d037bfcc                 sth     %o0, [%fp+var_34]
F00E8620: d0142036                 lduh    [%l0+0x36], %o0
F00E8624: 932ae010                 sll     %o3, 16, %o1
F00E8628: 933a6010                 sra     %o1, 16, %o1
F00E862C: 912a2010                 sll     %o0, 16, %o0
F00E8630: 913a2010                 sra     %o0, 16, %o0
F00E8634: 80a24008                 cmp     %o1, %o0
F00E8638: 04800004                 ble     loc_F00E8648
F00E863C: 01000000                 nop
F00E8640: d0142036                 lduh    [%l0+0x36], %o0
F00E8644: d037bfce                 sth     %o0, [%fp+var_32]
F00E8648: d0142030                 lduh    [%l0+0x30], %o0
F00E864C: 932b2010                 sll     %o4, 16, %o1
F00E8650: 933a6010                 sra     %o1, 16, %o1
F00E8654: 912a2010                 sll     %o0, 16, %o0
F00E8658: 913a2010                 sra     %o0, 16, %o0
F00E865C: 80a24008                 cmp     %o1, %o0
F00E8660: 16800004                 bge     loc_F00E8670
F00E8664: 01000000                 nop
F00E8668: d0142030                 lduh    [%l0+0x30], %o0
F00E866C: d037bfc8                 sth     %o0, [%fp+var_38]
F00E8670: d0142032                 lduh    [%l0+0x32], %o0
F00E8674: 932b6010                 sll     %o5, 16, %o1
F00E8678: 933a6010                 sra     %o1, 16, %o1
F00E867C: 912a2010                 sll     %o0, 16, %o0
F00E8680: 913a2010                 sra     %o0, 16, %o0
F00E8684: 80a24008                 cmp     %o1, %o0
F00E8688: 04800005                 ble     loc_F00E869C
F00E868C: d017bfc8                 lduh    [%fp+var_38], %o0
F00E8690: d0142032                 lduh    [%l0+0x32], %o0
F00E8694: d037bfca                 sth     %o0, [%fp+var_36]
F00E8698: d017bfc8                 lduh    [%fp+var_38], %o0
F00E869C: d034200c                 sth     %o0, [%l0+0xC]
F00E86A0: d017bfca                 lduh    [%fp+var_36], %o0
F00E86A4: d034200e                 sth     %o0, [%l0+0xE]
F00E86A8: d017bfcc                 lduh    [%fp+var_34], %o0
F00E86AC: d0342010                 sth     %o0, [%l0+0x10]
F00E86B0: d017bfce                 lduh    [%fp+var_32], %o0
F00E86B4: d0342012                 sth     %o0, [%l0+0x12]
F00E86B8: c6046008                 ld      [%l1+8], %g3
F00E86BC: d2142034                 lduh    [%l0+0x34], %o1
F00E86C0: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E86C4: c627bfac                 st      %g3, [%fp+var_54]
F00E86C8: 932a6010                 sll     %o1, 16, %o1
F00E86CC: 933a6010                 sra     %o1, 16, %o1
F00E86D0: d007bfac                 ld      [%fp+var_54], %o0
F00E86D4: 7ffc778b                 call    _umul
F00E86D8: 92228009                 sub     %o2, %o1, %o1
F00E86DC: d4046014                 ld      [%l1+0x14], %o2
F00E86E0: d2142030                 lduh    [%l0+0x30], %o1
F00E86E4: d657bfc8                 ldsh    [%fp+var_38], %o3
F00E86E8: ae042848                 add     %l0, 0x848, %l7
F00E86EC: c207bfac                 ld      [%fp+var_54], %g1
F00E86F0: 94028008                 add     %o2, %o0, %o2
F00E86F4: 932a6010                 sll     %o1, 16, %o1
F00E86F8: 933a6010                 sra     %o1, 16, %o1
F00E86FC: 9222c009                 sub     %o3, %o1, %o1
F00E8700: d057bfca                 ldsh    [%fp+var_36], %o0
F00E8704: b4028009                 add     %o2, %o1, %i2
F00E8708: d204601c                 ld      [%l1+0x1C], %o1
F00E870C: 9022000b                 sub     %o0, %o3, %o0
F00E8710: d027bfa4                 st      %o0, [%fp+var_5C]
F00E8714: 82204008                 sub     %g1, %o0, %g1
F00E8718: c227bfac                 st      %g1, [%fp+var_54]
F00E871C: d0040000                 ld      [%l0], %o0
F00E8720: 80a26001                 cmp     %o1, 1
F00E8724: c607bfa4                 ld      [%fp+var_5C], %g3
F00E8728: 912a2008                 sll     %o0, 8, %o0
F00E872C: 90022048                 inc     0x48, %o0 ! 'H'
F00E8730: d4040000                 ld      [%l0], %o2
F00E8734: a8040008                 add     %l0, %o0, %l4
F00E8738: 952aa008                 sll     %o2, 8, %o2
F00E873C: 9402a448                 inc     0x448, %o2
F00E8740: d2142024                 lduh    [%l0+0x24], %o1
F00E8744: b604000a                 add     %l0, %o2, %i3
F00E8748: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E874C: 932a6010                 sll     %o1, 16, %o1
F00E8750: 933a6010                 sra     %o1, 16, %o1
F00E8754: 92228009                 sub     %o2, %o1, %o1
F00E8758: d0142020                 lduh    [%l0+0x20], %o0
F00E875C: 932a6004                 sll     %o1, 4, %o1
F00E8760: 912a2010                 sll     %o0, 16, %o0
F00E8764: 913a2010                 sra     %o0, 16, %o0
F00E8768: 9622c008                 sub     %o3, %o0, %o3
F00E876C: aa02400b                 add     %o1, %o3, %l5
F00E8770: a8050015                 add     %l4, %l5, %l4
F00E8774: d057bfce                 ldsh    [%fp+var_32], %o0
F00E8778: b606c015                 add     %i3, %l5, %i3
F00E877C: 9222000a                 sub     %o0, %o2, %o1
F00E8780: 90102010                 mov     0x10, %o0
F00E8784: 12800023                 bne     loc_F00E8810
F00E8788: b2220003                 sub     %o0, %g3, %i1
F00E878C: aa827fff                 addcc   %o1, -1, %l5
F00E8790: 0c80015a                 bneg    loc_F00E8CF8
F00E8794: a21020ff                 mov     0xFF, %l1
F00E8798: c207bfa4                 ld      [%fp+var_5C], %g1
F00E879C: a4807fff                 addcc   %g1, -1, %l2
F00E87A0: 2c800015                 bneg,a  loc_F00E87F4
F00E87A4: a8050019                 add     %l4, %i1, %l4
F00E87A8: d00e8000                 ldub    [%i2], %o0
F00E87AC: d02dc000                 stb     %o0, [%l7]
F00E87B0: ae05e001                 inc     %l7
F00E87B4: e00d0000                 ldub    [%l4], %l0
F00E87B8: d20ec000                 ldub    [%i3], %o1
F00E87BC: a8052001                 inc     %l4
F00E87C0: 7ffc7750                 call    _umul
F00E87C4: 92244009                 sub     %l1, %o1, %o1
F00E87C8: b606e001                 inc     %i3
F00E87CC: 933a2008                 sra     %o0, 8, %o1
F00E87D0: 90020009                 add     %o0, %o1, %o0
F00E87D4: 90022001                 inc     %o0
F00E87D8: 913a2008                 sra     %o0, 8, %o0
F00E87DC: a0040008                 add     %l0, %o0, %l0
F00E87E0: e02e8000                 stb     %l0, [%i2]
F00E87E4: a484bfff                 inccc   -1, %l2
F00E87E8: 1cbffff0                 bpos    loc_F00E87A8
F00E87EC: b406a001                 inc     %i2
F00E87F0: a8050019                 add     %l4, %i1, %l4
F00E87F4: b606c019                 add     %i3, %i1, %i3
F00E87F8: c607bfac                 ld      [%fp+var_54], %g3
F00E87FC: aa857fff                 inccc   -1, %l5
F00E8800: 1cbfffe6                 bpos    loc_F00E8798
F00E8804: b4068003                 add     %i2, %g3, %i2
F00E8808: 1080013d                 ba      loc_F00E8CFC
F00E880C: c607bfb4                 ld      [%fp+var_4C], %g3
F00E8810: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8814: fa006208                 ld      [%g1+0x208], %i5
F00E8818: aa827fff                 addcc   %o1, -1, %l5
F00E881C: 0c800137                 bneg    loc_F00E8CF8
F00E8820: ec00620c                 ld      [%g1+0x20C], %l6
F00E8824: 113fc03fb0122300         set     -0xFF0100, %i0
F00E882C: c607bfa4                 ld      [%fp+var_5C], %g3
F00E8830: a480ffff                 addcc   %g3, -1, %l2
F00E8834: 0c80004a                 bneg    loc_F00E895C
F00E8838: 11003fc0                 sethi   0xFF0000, %o0
F00E883C: b81220ff                 or      %o0, 0xFF, %i4
F00E8840: d00e8000                 ldub    [%i2], %o0
F00E8844: d02dc000                 stb     %o0, [%l7]
F00E8848: e00ec000                 ldub    [%i3], %l0
F00E884C: 80a42000                 cmp     %l0, 0
F00E8850: 2280003e                 be,a    loc_F00E8948
F00E8854: ae05e001                 inc     %l7
F00E8858: e60d0000                 ldub    [%l4], %l3
F00E885C: 90380010                 xnor    %g0, %l0, %o0
F00E8860: 808a20ff                 btst    0xFF, %o0
F00E8864: 02800037                 be      loc_F00E8940
F00E8868: a0100008                 mov     %o0, %l0
F00E886C: d00e8000                 ldub    [%i2], %o0
F00E8870: a00c20ff                 and     %l0, 0xFF, %l0
F00E8874: 912a2002                 sll     %o0, 2, %o0
F00E8878: e2074008                 ld      [%i5+%o0], %l1
F00E887C: 92100010                 mov     %l0, %o1
F00E8880: 900c4018                 and     %l1, %i0, %o0
F00E8884: 7ffc771f                 call    _umul
F00E8888: 91322008                 srl     %o0, 8, %o0
F00E888C: 94100008                 mov     %o0, %o2
F00E8890: 900c401c                 and     %l1, %i4, %o0
F00E8894: 92100010                 mov     %l0, %o1
F00E8898: 0300004082106001         set     0x10001, %g1
F00E88A0: a0028001                 add     %o2, %g1, %l0
F00E88A4: 940a8018                 and     %o2, %i0, %o2
F00E88A8: 9532a008                 srl     %o2, 8, %o2
F00E88AC: 7ffc7715                 call    _umul
F00E88B0: a004000a                 add     %l0, %o2, %l0
F00E88B4: 070000408610e001         set     0x10001, %g3
F00E88BC: 92020003                 add     %o0, %g3, %o1
F00E88C0: 900a0018                 and     %o0, %i0, %o0
F00E88C4: 91322008                 srl     %o0, 8, %o0
F00E88C8: 92024008                 add     %o1, %o0, %o1
F00E88CC: a00c0018                 and     %l0, %i0, %l0
F00E88D0: 93326008                 srl     %o1, 8, %o1
F00E88D4: 920a401c                 and     %o1, %i4, %o1
F00E88D8: 912ce002                 sll     %l3, 2, %o0
F00E88DC: a0140009                 bset    %o1, %l0
F00E88E0: 03003fff                 sethi   0xFFFC00, %g1
F00E88E4: d0074008                 ld      [%i5+%o0], %o0
F00E88E8: 82106300                 bset    0x300, %g1
F00E88EC: 900a3f00                 and     %o0, -0x100, %o0
F00E88F0: a2020010                 add     %o0, %l0, %l1
F00E88F4: 97346008                 srl     %l1, 8, %o3
F00E88F8: 901c400b                 xor     %l1, %o3, %o0
F00E88FC: 808a0001                 btst    %g1, %o0
F00E8900: 0280000d                 be      loc_F00E8934
F00E8904: 93346018                 srl     %l1, 24, %o1
F00E8908: 91346010                 srl     %l1, 16, %o0
F00E890C: 900a20ff                 and     %o0, 0xFF, %o0
F00E8910: d40d8009                 ldub    [%l6+%o1], %o2
F00E8914: 90020016                 add     %o0, %l6, %o0
F00E8918: 920ae0ff                 and     %o3, 0xFF, %o1
F00E891C: d60a2100                 ldub    [%o0+0x100], %o3
F00E8920: 92024016                 add     %o1, %l6, %o1! SEL
F00E8924: d00a6200                 ldub    [%o1+0x200], %o0
F00E8928: 9402800b                 add     %o2, %o3, %o2
F00E892C: 10800005                 ba      loc_F00E8940
F00E8930: a602000a                 add     %o0, %o2, %l3
F00E8934: 91346018                 srl     %l1, 24, %o0
F00E8938: 90020016                 add     %o0, %l6, %o0! id
F00E893C: e60a2300                 ldub    [%o0+0x300], %l3
F00E8940: e62e8000                 stb     %l3, [%i2]
F00E8944: ae05e001                 inc     %l7
F00E8948: b606e001                 inc     %i3
F00E894C: a8052001                 inc     %l4
F00E8950: a484bfff                 inccc   -1, %l2
F00E8954: 1cbfffbb                 bpos    loc_F00E8840
F00E8958: b406a001                 inc     %i2
F00E895C: a8050019                 add     %l4, %i1, %l4
F00E8960: b606c019                 add     %i3, %i1, %i3
F00E8964: c607bfac                 ld      [%fp+var_54], %g3
F00E8968: aa857fff                 inccc   -1, %l5
F00E896C: 1cbfffb0                 bpos    loc_F00E882C
F00E8970: b4068003                 add     %i2, %g3, %i2
F00E8974: 108000e2                 ba      loc_F00E8CFC
F00E8978: c607bfb4                 ld      [%fp+var_4C], %g3
F00E897C: 400023bd                 call    _objc_msgSend
F00E8980: d007bfc4                 ld      [%fp+var_3C], %o0
F00E8984: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8988: e00061fc                 ld      [%g1+0x1FC], %l0
F00E898C: d8142020                 lduh    [%l0+0x20], %o4
F00E8990: d837bfc8                 sth     %o4, [%fp+var_38]
F00E8994: da142022                 lduh    [%l0+0x22], %o5
F00E8998: da37bfca                 sth     %o5, [%fp+var_36]
F00E899C: d4142024                 lduh    [%l0+0x24], %o2
F00E89A0: a2100008                 mov     %o0, %l1
F00E89A4: d437bfcc                 sth     %o2, [%fp+var_34]
F00E89A8: d6142026                 lduh    [%l0+0x26], %o3
F00E89AC: 952aa010                 sll     %o2, 16, %o2
F00E89B0: d637bfce                 sth     %o3, [%fp+var_32]
F00E89B4: d2142034                 lduh    [%l0+0x34], %o1
F00E89B8: 953aa010                 sra     %o2, 16, %o2
F00E89BC: 932a6010                 sll     %o1, 16, %o1
F00E89C0: 933a6010                 sra     %o1, 16, %o1
F00E89C4: 80a28009                 cmp     %o2, %o1
F00E89C8: 16800004                 bge     loc_F00E89D8
F00E89CC: 01000000                 nop
F00E89D0: d0142034                 lduh    [%l0+0x34], %o0
F00E89D4: d037bfcc                 sth     %o0, [%fp+var_34]
F00E89D8: d0142036                 lduh    [%l0+0x36], %o0
F00E89DC: 932ae010                 sll     %o3, 16, %o1
F00E89E0: 933a6010                 sra     %o1, 16, %o1
F00E89E4: 912a2010                 sll     %o0, 16, %o0
F00E89E8: 913a2010                 sra     %o0, 16, %o0
F00E89EC: 80a24008                 cmp     %o1, %o0
F00E89F0: 04800004                 ble     loc_F00E8A00
F00E89F4: 01000000                 nop
F00E89F8: d0142036                 lduh    [%l0+0x36], %o0
F00E89FC: d037bfce                 sth     %o0, [%fp+var_32]
F00E8A00: d0142030                 lduh    [%l0+0x30], %o0
F00E8A04: 932b2010                 sll     %o4, 16, %o1
F00E8A08: 933a6010                 sra     %o1, 16, %o1
F00E8A0C: 912a2010                 sll     %o0, 16, %o0
F00E8A10: 913a2010                 sra     %o0, 16, %o0
F00E8A14: 80a24008                 cmp     %o1, %o0
F00E8A18: 16800004                 bge     loc_F00E8A28
F00E8A1C: 01000000                 nop
F00E8A20: d0142030                 lduh    [%l0+0x30], %o0
F00E8A24: d037bfc8                 sth     %o0, [%fp+var_38]
F00E8A28: d0142032                 lduh    [%l0+0x32], %o0
F00E8A2C: 932b6010                 sll     %o5, 16, %o1
F00E8A30: 933a6010                 sra     %o1, 16, %o1
F00E8A34: 912a2010                 sll     %o0, 16, %o0
F00E8A38: 913a2010                 sra     %o0, 16, %o0
F00E8A3C: 80a24008                 cmp     %o1, %o0
F00E8A40: 04800005                 ble     loc_F00E8A54
F00E8A44: d017bfc8                 lduh    [%fp+var_38], %o0
F00E8A48: d0142032                 lduh    [%l0+0x32], %o0
F00E8A4C: d037bfca                 sth     %o0, [%fp+var_36]
F00E8A50: d017bfc8                 lduh    [%fp+var_38], %o0
F00E8A54: d034200c                 sth     %o0, [%l0+0xC]
F00E8A58: d017bfca                 lduh    [%fp+var_36], %o0
F00E8A5C: d034200e                 sth     %o0, [%l0+0xE]
F00E8A60: d017bfcc                 lduh    [%fp+var_34], %o0
F00E8A64: d0342010                 sth     %o0, [%l0+0x10]
F00E8A68: d017bfce                 lduh    [%fp+var_32], %o0
F00E8A6C: d0342012                 sth     %o0, [%l0+0x12]
F00E8A70: f2046008                 ld      [%l1+8], %i1
F00E8A74: d2142034                 lduh    [%l0+0x34], %o1
F00E8A78: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E8A7C: 90100019                 mov     %i1, %o0
F00E8A80: 932a6010                 sll     %o1, 16, %o1
F00E8A84: 933a6010                 sra     %o1, 16, %o1
F00E8A88: 7ffc769e                 call    _umul
F00E8A8C: 92228009                 sub     %o2, %o1, %o1
F00E8A90: 1300000492126048         set     0x1048, %o1
F00E8A98: d4046014                 ld      [%l1+0x14], %o2
F00E8A9C: ac040009                 add     %l0, %o1, %l6
F00E8AA0: d2142030                 lduh    [%l0+0x30], %o1
F00E8AA4: d657bfc8                 ldsh    [%fp+var_38], %o3
F00E8AA8: 912a2002                 sll     %o0, 2, %o0
F00E8AAC: d84c6020                 ldsb    [%l1+0x20], %o4
F00E8AB0: 94028008                 add     %o2, %o0, %o2
F00E8AB4: 932a6010                 sll     %o1, 16, %o1
F00E8AB8: 933a6010                 sra     %o1, 16, %o1
F00E8ABC: 9222c009                 sub     %o3, %o1, %o1
F00E8AC0: 932a6002                 sll     %o1, 2, %o1
F00E8AC4: d057bfca                 ldsh    [%fp+var_36], %o0
F00E8AC8: a4028009                 add     %o2, %o1, %l2
F00E8ACC: d2040000                 ld      [%l0], %o1
F00E8AD0: 80a32041                 cmp     %o4, 0x41 ! 'A'
F00E8AD4: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E8AD8: ba22000b                 sub     %o0, %o3, %i5
F00E8ADC: b226401d                 sub     %i1, %i5, %i1
F00E8AE0: 932a600a                 sll     %o1, 10, %o1
F00E8AE4: 92026048                 inc     0x48, %o1 ! 'H'
F00E8AE8: d0142024                 lduh    [%l0+0x24], %o0
F00E8AEC: a8040009                 add     %l0, %o1, %l4
F00E8AF0: 912a2010                 sll     %o0, 16, %o0
F00E8AF4: 913a2010                 sra     %o0, 16, %o0
F00E8AF8: 90228008                 sub     %o2, %o0, %o0
F00E8AFC: d2142020                 lduh    [%l0+0x20], %o1
F00E8B00: 912a2004                 sll     %o0, 4, %o0
F00E8B04: 932a6010                 sll     %o1, 16, %o1
F00E8B08: 933a6010                 sra     %o1, 16, %o1
F00E8B0C: 9622c009                 sub     %o3, %o1, %o3
F00E8B10: 9002000b                 add     %o0, %o3, %o0
F00E8B14: 912a2002                 sll     %o0, 2, %o0
F00E8B18: a8050008                 add     %l4, %o0, %l4
F00E8B1C: 90102010                 mov     0x10, %o0
F00E8B20: 02800005                 be      loc_F00E8B34
F00E8B24: b022001d                 sub     %o0, %i5, %i0
F00E8B28: 80a3202d                 cmp     %o4, 0x2D ! '-'
F00E8B2C: 1280003f                 bne     loc_F00E8C28
F00E8B30: d057bfce                 ldsh    [%fp+var_32], %o0
F00E8B34: d057bfce                 ldsh    [%fp+var_32], %o0
F00E8B38: aa22000a                 sub     %o0, %o2, %l5
F00E8B3C: aa057fff                 inc     -1, %l5
F00E8B40: 80a57fff                 cmp     %l5, -1
F00E8B44: 0280006d                 be      loc_F00E8CF8
F00E8B48: 113fc03f                 sethi   -0xFF0400, %o0
F00E8B4C: b8122300                 or      %o0, 0x300, %i4
F00E8B50: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E8B58: a6077fff                 add     %i5, -1, %l3
F00E8B5C: 80a4ffff                 cmp     %l3, -1
F00E8B60: 0280002a                 be      loc_F00E8C08
F00E8B64: 912e2002                 sll     %i0, 2, %o0
F00E8B68: d0048000                 ld      [%l2], %o0
F00E8B6C: d0258000                 st      %o0, [%l6]
F00E8B70: b4100008                 mov     %o0, %i2
F00E8B74: f6050000                 ld      [%l4], %i3
F00E8B78: ac05a004                 inc     4, %l6
F00E8B7C: a336e018                 srl     %i3, 24, %l1
F00E8B80: 80a46000                 cmp     %l1, 0
F00E8B84: 0280001c                 be      loc_F00E8BF4
F00E8B88: a8052004                 inc     4, %l4
F00E8B8C: 80a460ff                 cmp     %l1, 0xFF
F00E8B90: 32800004                 bne,a   loc_F00E8BA0
F00E8B94: b72ee008                 sll     %i3, 8, %i3
F00E8B98: 10800017                 ba      loc_F00E8BF4
F00E8B9C: f6248000                 st      %i3, [%l2]
F00E8BA0: b52ea008                 sll     %i2, 8, %i2
F00E8BA4: a21c60ff                 btog    0xFF, %l1
F00E8BA8: 900e801c                 and     %i2, %i4, %o0
F00E8BAC: 91322008                 srl     %o0, 8, %o0
F00E8BB0: 7ffc7654                 call    _umul
F00E8BB4: 92100011                 mov     %l1, %o1
F00E8BB8: a0100008                 mov     %o0, %l0
F00E8BBC: 900e8017                 and     %i2, %l7, %o0
F00E8BC0: 92100011                 mov     %l1, %o1
F00E8BC4: a0040017                 add     %l0, %l7, %l0
F00E8BC8: 7ffc764e                 call    _umul
F00E8BCC: a00c001c                 and     %l0, %i4, %l0
F00E8BD0: 90020017                 add     %o0, %l7, %o0
F00E8BD4: 91322008                 srl     %o0, 8, %o0
F00E8BD8: 900a0017                 and     %o0, %l7, %o0
F00E8BDC: a0140008                 bset    %o0, %l0
F00E8BE0: b406c010                 add     %i3, %l0, %i2
F00E8BE4: 9136a008                 srl     %i2, 8, %o0
F00E8BE8: 133fc000                 sethi   -0x1000000, %o1
F00E8BEC: 90120009                 bset    %o1, %o0
F00E8BF0: d0248000                 st      %o0, [%l2]
F00E8BF4: a604ffff                 inc     -1, %l3
F00E8BF8: 80a4ffff                 cmp     %l3, -1
F00E8BFC: 12bfffdb                 bne     loc_F00E8B68
F00E8C00: a404a004                 inc     4, %l2
F00E8C04: 912e2002                 sll     %i0, 2, %o0
F00E8C08: a8050008                 add     %l4, %o0, %l4
F00E8C0C: 912e6002                 sll     %i1, 2, %o0
F00E8C10: aa057fff                 inc     -1, %l5
F00E8C14: 80a57fff                 cmp     %l5, -1
F00E8C18: 12bfffd0                 bne     loc_F00E8B58
F00E8C1C: a4048008                 add     %l2, %o0, %l2
F00E8C20: 10800037                 ba      loc_F00E8CFC
F00E8C24: c607bfb4                 ld      [%fp+var_4C], %g3
F00E8C28: aa22000a                 sub     %o0, %o2, %l5
F00E8C2C: aa057fff                 inc     -1, %l5
F00E8C30: 80a57fff                 cmp     %l5, -1
F00E8C34: 02800031                 be      loc_F00E8CF8
F00E8C38: 113fc03f                 sethi   -0xFF0400, %o0
F00E8C3C: b8122300                 or      %o0, 0x300, %i4
F00E8C40: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E8C48: a6077fff                 add     %i5, -1, %l3
F00E8C4C: 80a4ffff                 cmp     %l3, -1
F00E8C50: 02800024                 be      loc_F00E8CE0
F00E8C54: 912e2002                 sll     %i0, 2, %o0
F00E8C58: d0048000                 ld      [%l2], %o0
F00E8C5C: d0258000                 st      %o0, [%l6]
F00E8C60: b4100008                 mov     %o0, %i2
F00E8C64: f6050000                 ld      [%l4], %i3
F00E8C68: ac05a004                 inc     4, %l6
F00E8C6C: a28ee0ff                 andcc   %i3, 0xFF, %l1
F00E8C70: 02800017                 be      loc_F00E8CCC
F00E8C74: a8052004                 inc     4, %l4
F00E8C78: 80a460ff                 cmp     %l1, 0xFF
F00E8C7C: 12800004                 bne     loc_F00E8C8C
F00E8C80: a21c60ff                 btog    0xFF, %l1
F00E8C84: 10800012                 ba      loc_F00E8CCC
F00E8C88: f6248000                 st      %i3, [%l2]
F00E8C8C: 900e801c                 and     %i2, %i4, %o0
F00E8C90: 91322008                 srl     %o0, 8, %o0
F00E8C94: 7ffc761b                 call    _umul
F00E8C98: 92100011                 mov     %l1, %o1
F00E8C9C: a0100008                 mov     %o0, %l0
F00E8CA0: 900e8017                 and     %i2, %l7, %o0
F00E8CA4: 92100011                 mov     %l1, %o1
F00E8CA8: a0040017                 add     %l0, %l7, %l0
F00E8CAC: 7ffc7615                 call    _umul
F00E8CB0: a00c001c                 and     %l0, %i4, %l0
F00E8CB4: 90020017                 add     %o0, %l7, %o0
F00E8CB8: 91322008                 srl     %o0, 8, %o0
F00E8CBC: 900a0017                 and     %o0, %l7, %o0
F00E8CC0: a0140008                 bset    %o0, %l0
F00E8CC4: b406c010                 add     %i3, %l0, %i2
F00E8CC8: f4248000                 st      %i2, [%l2]
F00E8CCC: a604ffff                 inc     -1, %l3
F00E8CD0: 80a4ffff                 cmp     %l3, -1
F00E8CD4: 12bfffe1                 bne     loc_F00E8C58
F00E8CD8: a404a004                 inc     4, %l2
F00E8CDC: 912e2002                 sll     %i0, 2, %o0
F00E8CE0: a8050008                 add     %l4, %o0, %l4
F00E8CE4: 912e6002                 sll     %i1, 2, %o0
F00E8CE8: aa057fff                 inc     -1, %l5
F00E8CEC: 80a57fff                 cmp     %l5, -1
F00E8CF0: 12bfffd6                 bne     loc_F00E8C48
F00E8CF4: a4048008                 add     %l2, %o0, %l2
F00E8CF8: c607bfb4                 ld      [%fp+var_4C], %g3
F00E8CFC: d010e020                 lduh    [%g3+0x20], %o0
F00E8D00: d030e028                 sth     %o0, [%g3+0x28]
F00E8D04: d010e022                 lduh    [%g3+0x22], %o0
F00E8D08: d030e02a                 sth     %o0, [%g3+0x2A]
F00E8D0C: d010e024                 lduh    [%g3+0x24], %o0
F00E8D10: d030e02c                 sth     %o0, [%g3+0x2C]
F00E8D14: d010e026                 lduh    [%g3+0x26], %o0
F00E8D18: d030e02e                 sth     %o0, [%g3+0x2E]
F00E8D1C: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8D20: d20061fc                 ld      [%g1+0x1FC], %o1
F00E8D24: d00a6008                 ldub    [%o1+8], %o0
F00E8D28: 80a22000                 cmp     %o0, 0
F00E8D2C: 2280020c                 be,a    loc_F00E955C
F00E8D30: c207bfbc                 ld      [%fp+var_44], %g1
F00E8D34: d00a6008                 ldub    [%o1+8], %o0
F00E8D38: 90023fff                 inc     -1, %o0
F00E8D3C: d02a6008                 stb     %o0, [%o1+8]
F00E8D40: d00a6008                 ldub    [%o1+8], %o0
F00E8D44: 80a22000                 cmp     %o0, 0
F00E8D48: 32800205                 bne,a   loc_F00E955C
F00E8D4C: c207bfbc                 ld      [%fp+var_44], %g1
F00E8D50: c60061fc                 ld      [%g1+0x1FC], %g3
F00E8D54: d000c000                 ld      [%g3], %o0
F00E8D58: 912a2002                 sll     %o0, 2, %o0
F00E8D5C: 90020003                 add     %o0, %g3, %o0
F00E8D60: d2122038                 lduh    [%o0+0x38], %o1
F00E8D64: d237bfd0                 sth     %o1, [%fp+var_30]
F00E8D68: d012203a                 lduh    [%o0+0x3A], %o0
F00E8D6C: d037bfd2                 sth     %o0, [%fp+var_2E]
F00E8D70: d010e01c                 lduh    [%g3+0x1C], %o0
F00E8D74: 90220009                 sub     %o0, %o1, %o0
F00E8D78: d030e020                 sth     %o0, [%g3+0x20]
F00E8D7C: d010e020                 lduh    [%g3+0x20], %o0
F00E8D80: 90022010                 inc     0x10, %o0
F00E8D84: d030e022                 sth     %o0, [%g3+0x22]
F00E8D88: d210e01e                 lduh    [%g3+0x1E], %o1
F00E8D8C: d417bfd2                 lduh    [%fp+var_2E], %o2
F00E8D90: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E8D94: d007bfc4                 ld      [%fp+var_3C], %o0! id
F00E8D98: 9222400a                 sub     %o1, %o2, %o1
F00E8D9C: d230e024                 sth     %o1, [%g3+0x24]
F00E8DA0: d410e024                 lduh    [%g3+0x24], %o2
F00E8DA4: c627bf9c                 st      %g3, [%fp+var_64]
F00E8DA8: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E8DAC: 9402a010                 inc     0x10, %o2
F00E8DB0: d430e026                 sth     %o2, [%g3+0x26]
F00E8DB4: 400022af                 call    _objc_msgSend
F00E8DB8: 01000000                 nop
F00E8DBC: d0022018                 ld      [%o0+0x18], %o0! id
F00E8DC0: 80a22003                 cmp     %o0, 3
F00E8DC4: 18800008                 bgu     loc_F00E8DE4
F00E8DC8: 80a22002                 cmp     %o0, 2
F00E8DCC: 1a8001da                 bcc     loc_F00E9534
F00E8DD0: 80a22001                 cmp     %o0, 1
F00E8DD4: 02800009                 be      loc_F00E8DF8
F00E8DD8: d20423ac                 ld      [%l0+0x3AC], %o1
F00E8DDC: 108001d7                 ba      loc_F00E9538
F00E8DE0: c607bf9c                 ld      [%fp+var_64], %g3
F00E8DE4: 80a22004                 cmp     %o0, 4
F00E8DE8: 028000f2                 be      loc_F00E91B0
F00E8DEC: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E8DF0: 108001d2                 ba      loc_F00E9538
F00E8DF4: c607bf9c                 ld      [%fp+var_64], %g3
F00E8DF8: 4000229e                 call    _objc_msgSend
F00E8DFC: d007bfc4                 ld      [%fp+var_3C], %o0
F00E8E00: c207bfc4                 ld      [%fp+var_3C], %g1
F00E8E04: e00061fc                 ld      [%g1+0x1FC], %l0
F00E8E08: d8142020                 lduh    [%l0+0x20], %o4
F00E8E0C: d837bfc8                 sth     %o4, [%fp+var_38]
F00E8E10: da142022                 lduh    [%l0+0x22], %o5
F00E8E14: da37bfca                 sth     %o5, [%fp+var_36]
F00E8E18: d4142024                 lduh    [%l0+0x24], %o2
F00E8E1C: a2100008                 mov     %o0, %l1
F00E8E20: d437bfcc                 sth     %o2, [%fp+var_34]
F00E8E24: d6142026                 lduh    [%l0+0x26], %o3
F00E8E28: 952aa010                 sll     %o2, 16, %o2
F00E8E2C: d637bfce                 sth     %o3, [%fp+var_32]
F00E8E30: d2142034                 lduh    [%l0+0x34], %o1
F00E8E34: 953aa010                 sra     %o2, 16, %o2
F00E8E38: 932a6010                 sll     %o1, 16, %o1
F00E8E3C: 933a6010                 sra     %o1, 16, %o1
F00E8E40: 80a28009                 cmp     %o2, %o1
F00E8E44: 16800004                 bge     loc_F00E8E54
F00E8E48: 01000000                 nop
F00E8E4C: d0142034                 lduh    [%l0+0x34], %o0
F00E8E50: d037bfcc                 sth     %o0, [%fp+var_34]
F00E8E54: d0142036                 lduh    [%l0+0x36], %o0
F00E8E58: 932ae010                 sll     %o3, 16, %o1
F00E8E5C: 933a6010                 sra     %o1, 16, %o1
F00E8E60: 912a2010                 sll     %o0, 16, %o0
F00E8E64: 913a2010                 sra     %o0, 16, %o0
F00E8E68: 80a24008                 cmp     %o1, %o0
F00E8E6C: 04800004                 ble     loc_F00E8E7C
F00E8E70: 01000000                 nop
F00E8E74: d0142036                 lduh    [%l0+0x36], %o0
F00E8E78: d037bfce                 sth     %o0, [%fp+var_32]
F00E8E7C: d0142030                 lduh    [%l0+0x30], %o0
F00E8E80: 932b2010                 sll     %o4, 16, %o1
F00E8E84: 933a6010                 sra     %o1, 16, %o1
F00E8E88: 912a2010                 sll     %o0, 16, %o0
F00E8E8C: 913a2010                 sra     %o0, 16, %o0
F00E8E90: 80a24008                 cmp     %o1, %o0
F00E8E94: 16800004                 bge     loc_F00E8EA4
F00E8E98: 01000000                 nop
F00E8E9C: d0142030                 lduh    [%l0+0x30], %o0
F00E8EA0: d037bfc8                 sth     %o0, [%fp+var_38]
F00E8EA4: d0142032                 lduh    [%l0+0x32], %o0
F00E8EA8: 932b6010                 sll     %o5, 16, %o1
F00E8EAC: 933a6010                 sra     %o1, 16, %o1
F00E8EB0: 912a2010                 sll     %o0, 16, %o0
F00E8EB4: 913a2010                 sra     %o0, 16, %o0
F00E8EB8: 80a24008                 cmp     %o1, %o0
F00E8EBC: 04800005                 ble     loc_F00E8ED0
F00E8EC0: d017bfc8                 lduh    [%fp+var_38], %o0
F00E8EC4: d0142032                 lduh    [%l0+0x32], %o0
F00E8EC8: d037bfca                 sth     %o0, [%fp+var_36]
F00E8ECC: d017bfc8                 lduh    [%fp+var_38], %o0
F00E8ED0: d034200c                 sth     %o0, [%l0+0xC]
F00E8ED4: d017bfca                 lduh    [%fp+var_36], %o0
F00E8ED8: d034200e                 sth     %o0, [%l0+0xE]
F00E8EDC: d017bfcc                 lduh    [%fp+var_34], %o0
F00E8EE0: d0342010                 sth     %o0, [%l0+0x10]
F00E8EE4: d017bfce                 lduh    [%fp+var_32], %o0
F00E8EE8: d0342012                 sth     %o0, [%l0+0x12]
F00E8EEC: c6046008                 ld      [%l1+8], %g3
F00E8EF0: d2142034                 lduh    [%l0+0x34], %o1
F00E8EF4: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E8EF8: c627bf94                 st      %g3, [%fp+var_6C]
F00E8EFC: 932a6010                 sll     %o1, 16, %o1
F00E8F00: 933a6010                 sra     %o1, 16, %o1
F00E8F04: d007bf94                 ld      [%fp+var_6C], %o0
F00E8F08: 7ffc757e                 call    _umul
F00E8F0C: 92228009                 sub     %o2, %o1, %o1
F00E8F10: d4046014                 ld      [%l1+0x14], %o2
F00E8F14: d2142030                 lduh    [%l0+0x30], %o1
F00E8F18: d657bfc8                 ldsh    [%fp+var_38], %o3
F00E8F1C: ae042848                 add     %l0, 0x848, %l7
F00E8F20: c207bf94                 ld      [%fp+var_6C], %g1
F00E8F24: 94028008                 add     %o2, %o0, %o2
F00E8F28: 932a6010                 sll     %o1, 16, %o1
F00E8F2C: 933a6010                 sra     %o1, 16, %o1
F00E8F30: 9222c009                 sub     %o3, %o1, %o1
F00E8F34: d057bfca                 ldsh    [%fp+var_36], %o0
F00E8F38: b4028009                 add     %o2, %o1, %i2
F00E8F3C: d204601c                 ld      [%l1+0x1C], %o1
F00E8F40: 9022000b                 sub     %o0, %o3, %o0
F00E8F44: d027bf8c                 st      %o0, [%fp+var_74]
F00E8F48: 82204008                 sub     %g1, %o0, %g1
F00E8F4C: c227bf94                 st      %g1, [%fp+var_6C]
F00E8F50: d0040000                 ld      [%l0], %o0
F00E8F54: 80a26001                 cmp     %o1, 1
F00E8F58: c607bf8c                 ld      [%fp+var_74], %g3
F00E8F5C: 912a2008                 sll     %o0, 8, %o0
F00E8F60: 90022048                 inc     0x48, %o0 ! 'H'
F00E8F64: d4040000                 ld      [%l0], %o2
F00E8F68: a8040008                 add     %l0, %o0, %l4
F00E8F6C: 952aa008                 sll     %o2, 8, %o2
F00E8F70: 9402a448                 inc     0x448, %o2
F00E8F74: d2142024                 lduh    [%l0+0x24], %o1
F00E8F78: b604000a                 add     %l0, %o2, %i3
F00E8F7C: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E8F80: 932a6010                 sll     %o1, 16, %o1
F00E8F84: 933a6010                 sra     %o1, 16, %o1
F00E8F88: 92228009                 sub     %o2, %o1, %o1
F00E8F8C: d0142020                 lduh    [%l0+0x20], %o0
F00E8F90: 932a6004                 sll     %o1, 4, %o1
F00E8F94: 912a2010                 sll     %o0, 16, %o0
F00E8F98: 913a2010                 sra     %o0, 16, %o0
F00E8F9C: 9622c008                 sub     %o3, %o0, %o3
F00E8FA0: aa02400b                 add     %o1, %o3, %l5
F00E8FA4: a8050015                 add     %l4, %l5, %l4
F00E8FA8: d057bfce                 ldsh    [%fp+var_32], %o0
F00E8FAC: b606c015                 add     %i3, %l5, %i3
F00E8FB0: 9222000a                 sub     %o0, %o2, %o1
F00E8FB4: 90102010                 mov     0x10, %o0
F00E8FB8: 12800023                 bne     loc_F00E9044
F00E8FBC: b2220003                 sub     %o0, %g3, %i1
F00E8FC0: aa827fff                 addcc   %o1, -1, %l5
F00E8FC4: 0c80015c                 bneg    loc_F00E9534
F00E8FC8: a21020ff                 mov     0xFF, %l1
F00E8FCC: c207bf8c                 ld      [%fp+var_74], %g1
F00E8FD0: a4807fff                 addcc   %g1, -1, %l2
F00E8FD4: 2c800015                 bneg,a  loc_F00E9028
F00E8FD8: a8050019                 add     %l4, %i1, %l4
F00E8FDC: d00e8000                 ldub    [%i2], %o0
F00E8FE0: d02dc000                 stb     %o0, [%l7]
F00E8FE4: ae05e001                 inc     %l7
F00E8FE8: e00d0000                 ldub    [%l4], %l0
F00E8FEC: d20ec000                 ldub    [%i3], %o1
F00E8FF0: a8052001                 inc     %l4
F00E8FF4: 7ffc7543                 call    _umul
F00E8FF8: 92244009                 sub     %l1, %o1, %o1
F00E8FFC: b606e001                 inc     %i3
F00E9000: 933a2008                 sra     %o0, 8, %o1
F00E9004: 90020009                 add     %o0, %o1, %o0
F00E9008: 90022001                 inc     %o0
F00E900C: 913a2008                 sra     %o0, 8, %o0
F00E9010: a0040008                 add     %l0, %o0, %l0
F00E9014: e02e8000                 stb     %l0, [%i2]
F00E9018: a484bfff                 inccc   -1, %l2
F00E901C: 1cbffff0                 bpos    loc_F00E8FDC
F00E9020: b406a001                 inc     %i2
F00E9024: a8050019                 add     %l4, %i1, %l4
F00E9028: b606c019                 add     %i3, %i1, %i3
F00E902C: c607bf94                 ld      [%fp+var_6C], %g3
F00E9030: aa857fff                 inccc   -1, %l5
F00E9034: 1cbfffe6                 bpos    loc_F00E8FCC
F00E9038: b4068003                 add     %i2, %g3, %i2
F00E903C: 1080013f                 ba      loc_F00E9538
F00E9040: c607bf9c                 ld      [%fp+var_64], %g3
F00E9044: c207bfc4                 ld      [%fp+var_3C], %g1
F00E9048: fa006208                 ld      [%g1+0x208], %i5
F00E904C: aa827fff                 addcc   %o1, -1, %l5
F00E9050: 0c800139                 bneg    loc_F00E9534
F00E9054: ec00620c                 ld      [%g1+0x20C], %l6
F00E9058: 113fc03fb0122300         set     -0xFF0100, %i0
F00E9060: c607bf8c                 ld      [%fp+var_74], %g3
F00E9064: a480ffff                 addcc   %g3, -1, %l2
F00E9068: 0c80004a                 bneg    loc_F00E9190
F00E906C: 11003fc0                 sethi   0xFF0000, %o0
F00E9070: b81220ff                 or      %o0, 0xFF, %i4
F00E9074: d00e8000                 ldub    [%i2], %o0
F00E9078: d02dc000                 stb     %o0, [%l7]
F00E907C: e00ec000                 ldub    [%i3], %l0
F00E9080: 80a42000                 cmp     %l0, 0
F00E9084: 2280003e                 be,a    loc_F00E917C
F00E9088: ae05e001                 inc     %l7
F00E908C: e60d0000                 ldub    [%l4], %l3
F00E9090: 90380010                 xnor    %g0, %l0, %o0
F00E9094: 808a20ff                 btst    0xFF, %o0
F00E9098: 02800037                 be      loc_F00E9174
F00E909C: a0100008                 mov     %o0, %l0
F00E90A0: d00e8000                 ldub    [%i2], %o0
F00E90A4: a00c20ff                 and     %l0, 0xFF, %l0
F00E90A8: 912a2002                 sll     %o0, 2, %o0
F00E90AC: e2074008                 ld      [%i5+%o0], %l1
F00E90B0: 92100010                 mov     %l0, %o1
F00E90B4: 900c4018                 and     %l1, %i0, %o0
F00E90B8: 7ffc7512                 call    _umul
F00E90BC: 91322008                 srl     %o0, 8, %o0
F00E90C0: 94100008                 mov     %o0, %o2
F00E90C4: 900c401c                 and     %l1, %i4, %o0
F00E90C8: 92100010                 mov     %l0, %o1
F00E90CC: 0300004082106001         set     0x10001, %g1
F00E90D4: a0028001                 add     %o2, %g1, %l0
F00E90D8: 940a8018                 and     %o2, %i0, %o2
F00E90DC: 9532a008                 srl     %o2, 8, %o2
F00E90E0: 7ffc7508                 call    _umul
F00E90E4: a004000a                 add     %l0, %o2, %l0
F00E90E8: 070000408610e001         set     0x10001, %g3
F00E90F0: 92020003                 add     %o0, %g3, %o1
F00E90F4: 900a0018                 and     %o0, %i0, %o0
F00E90F8: 91322008                 srl     %o0, 8, %o0
F00E90FC: 92024008                 add     %o1, %o0, %o1
F00E9100: a00c0018                 and     %l0, %i0, %l0
F00E9104: 93326008                 srl     %o1, 8, %o1
F00E9108: 920a401c                 and     %o1, %i4, %o1
F00E910C: 912ce002                 sll     %l3, 2, %o0
F00E9110: a0140009                 bset    %o1, %l0
F00E9114: 03003fff                 sethi   0xFFFC00, %g1
F00E9118: d0074008                 ld      [%i5+%o0], %o0
F00E911C: 82106300                 bset    0x300, %g1
F00E9120: 900a3f00                 and     %o0, -0x100, %o0
F00E9124: a2020010                 add     %o0, %l0, %l1
F00E9128: 97346008                 srl     %l1, 8, %o3
F00E912C: 901c400b                 xor     %l1, %o3, %o0
F00E9130: 808a0001                 btst    %g1, %o0
F00E9134: 0280000d                 be      loc_F00E9168
F00E9138: 93346018                 srl     %l1, 24, %o1
F00E913C: 91346010                 srl     %l1, 16, %o0
F00E9140: 900a20ff                 and     %o0, 0xFF, %o0
F00E9144: d40d8009                 ldub    [%l6+%o1], %o2
F00E9148: 90020016                 add     %o0, %l6, %o0
F00E914C: 920ae0ff                 and     %o3, 0xFF, %o1
F00E9150: d60a2100                 ldub    [%o0+0x100], %o3
F00E9154: 92024016                 add     %o1, %l6, %o1! SEL
F00E9158: d00a6200                 ldub    [%o1+0x200], %o0
F00E915C: 9402800b                 add     %o2, %o3, %o2
F00E9160: 10800005                 ba      loc_F00E9174
F00E9164: a602000a                 add     %o0, %o2, %l3
F00E9168: 91346018                 srl     %l1, 24, %o0
F00E916C: 90020016                 add     %o0, %l6, %o0! id
F00E9170: e60a2300                 ldub    [%o0+0x300], %l3
F00E9174: e62e8000                 stb     %l3, [%i2]
F00E9178: ae05e001                 inc     %l7
F00E917C: b606e001                 inc     %i3
F00E9180: a8052001                 inc     %l4
F00E9184: a484bfff                 inccc   -1, %l2
F00E9188: 1cbfffbb                 bpos    loc_F00E9074
F00E918C: b406a001                 inc     %i2
F00E9190: a8050019                 add     %l4, %i1, %l4
F00E9194: b606c019                 add     %i3, %i1, %i3
F00E9198: c607bf94                 ld      [%fp+var_6C], %g3
F00E919C: aa857fff                 inccc   -1, %l5
F00E91A0: 1cbfffb0                 bpos    loc_F00E9060
F00E91A4: b4068003                 add     %i2, %g3, %i2
F00E91A8: 108000e4                 ba      loc_F00E9538
F00E91AC: c607bf9c                 ld      [%fp+var_64], %g3
F00E91B0: 400021b0                 call    _objc_msgSend
F00E91B4: d007bfc4                 ld      [%fp+var_3C], %o0
F00E91B8: c207bfc4                 ld      [%fp+var_3C], %g1
F00E91BC: e00061fc                 ld      [%g1+0x1FC], %l0
F00E91C0: d8142020                 lduh    [%l0+0x20], %o4
F00E91C4: d837bfc8                 sth     %o4, [%fp+var_38]
F00E91C8: da142022                 lduh    [%l0+0x22], %o5
F00E91CC: da37bfca                 sth     %o5, [%fp+var_36]
F00E91D0: d4142024                 lduh    [%l0+0x24], %o2
F00E91D4: a2100008                 mov     %o0, %l1
F00E91D8: d437bfcc                 sth     %o2, [%fp+var_34]
F00E91DC: d6142026                 lduh    [%l0+0x26], %o3
F00E91E0: 952aa010                 sll     %o2, 16, %o2
F00E91E4: d637bfce                 sth     %o3, [%fp+var_32]
F00E91E8: d2142034                 lduh    [%l0+0x34], %o1
F00E91EC: 953aa010                 sra     %o2, 16, %o2
F00E91F0: 932a6010                 sll     %o1, 16, %o1
F00E91F4: 933a6010                 sra     %o1, 16, %o1
F00E91F8: 80a28009                 cmp     %o2, %o1
F00E91FC: 16800004                 bge     loc_F00E920C
F00E9200: 01000000                 nop
F00E9204: d0142034                 lduh    [%l0+0x34], %o0
F00E9208: d037bfcc                 sth     %o0, [%fp+var_34]
F00E920C: d0142036                 lduh    [%l0+0x36], %o0
F00E9210: 932ae010                 sll     %o3, 16, %o1
F00E9214: 933a6010                 sra     %o1, 16, %o1
F00E9218: 912a2010                 sll     %o0, 16, %o0
F00E921C: 913a2010                 sra     %o0, 16, %o0
F00E9220: 80a24008                 cmp     %o1, %o0
F00E9224: 04800004                 ble     loc_F00E9234
F00E9228: 01000000                 nop
F00E922C: d0142036                 lduh    [%l0+0x36], %o0
F00E9230: d037bfce                 sth     %o0, [%fp+var_32]
F00E9234: d0142030                 lduh    [%l0+0x30], %o0
F00E9238: 932b2010                 sll     %o4, 16, %o1
F00E923C: 933a6010                 sra     %o1, 16, %o1
F00E9240: 912a2010                 sll     %o0, 16, %o0
F00E9244: 913a2010                 sra     %o0, 16, %o0
F00E9248: 80a24008                 cmp     %o1, %o0
F00E924C: 16800004                 bge     loc_F00E925C
F00E9250: 01000000                 nop
F00E9254: d0142030                 lduh    [%l0+0x30], %o0
F00E9258: d037bfc8                 sth     %o0, [%fp+var_38]
F00E925C: d0142032                 lduh    [%l0+0x32], %o0
F00E9260: 932b6010                 sll     %o5, 16, %o1
F00E9264: 933a6010                 sra     %o1, 16, %o1
F00E9268: 912a2010                 sll     %o0, 16, %o0
F00E926C: 913a2010                 sra     %o0, 16, %o0
F00E9270: 80a24008                 cmp     %o1, %o0
F00E9274: 04800005                 ble     loc_F00E9288
F00E9278: d017bfc8                 lduh    [%fp+var_38], %o0
F00E927C: d0142032                 lduh    [%l0+0x32], %o0
F00E9280: d037bfca                 sth     %o0, [%fp+var_36]
F00E9284: d017bfc8                 lduh    [%fp+var_38], %o0
F00E9288: d034200c                 sth     %o0, [%l0+0xC]
F00E928C: d017bfca                 lduh    [%fp+var_36], %o0
F00E9290: d034200e                 sth     %o0, [%l0+0xE]
F00E9294: d017bfcc                 lduh    [%fp+var_34], %o0
F00E9298: d0342010                 sth     %o0, [%l0+0x10]
F00E929C: d017bfce                 lduh    [%fp+var_32], %o0
F00E92A0: d0342012                 sth     %o0, [%l0+0x12]
F00E92A4: f2046008                 ld      [%l1+8], %i1
F00E92A8: d2142034                 lduh    [%l0+0x34], %o1
F00E92AC: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E92B0: 90100019                 mov     %i1, %o0
F00E92B4: 932a6010                 sll     %o1, 16, %o1
F00E92B8: 933a6010                 sra     %o1, 16, %o1
F00E92BC: 7ffc7491                 call    _umul
F00E92C0: 92228009                 sub     %o2, %o1, %o1
F00E92C4: 1300000492126048         set     0x1048, %o1
F00E92CC: d4046014                 ld      [%l1+0x14], %o2
F00E92D0: ac040009                 add     %l0, %o1, %l6
F00E92D4: d2142030                 lduh    [%l0+0x30], %o1
F00E92D8: d657bfc8                 ldsh    [%fp+var_38], %o3
F00E92DC: 912a2002                 sll     %o0, 2, %o0
F00E92E0: d84c6020                 ldsb    [%l1+0x20], %o4
F00E92E4: 94028008                 add     %o2, %o0, %o2
F00E92E8: 932a6010                 sll     %o1, 16, %o1
F00E92EC: 933a6010                 sra     %o1, 16, %o1
F00E92F0: 9222c009                 sub     %o3, %o1, %o1
F00E92F4: 932a6002                 sll     %o1, 2, %o1
F00E92F8: d057bfca                 ldsh    [%fp+var_36], %o0
F00E92FC: a4028009                 add     %o2, %o1, %l2
F00E9300: d2040000                 ld      [%l0], %o1
F00E9304: 80a32041                 cmp     %o4, 0x41 ! 'A'
F00E9308: d457bfcc                 ldsh    [%fp+var_34], %o2
F00E930C: ba22000b                 sub     %o0, %o3, %i5
F00E9310: b226401d                 sub     %i1, %i5, %i1
F00E9314: 932a600a                 sll     %o1, 10, %o1
F00E9318: 92026048                 inc     0x48, %o1 ! 'H'
F00E931C: d0142024                 lduh    [%l0+0x24], %o0
F00E9320: a8040009                 add     %l0, %o1, %l4
F00E9324: 912a2010                 sll     %o0, 16, %o0
F00E9328: 913a2010                 sra     %o0, 16, %o0
F00E932C: 90228008                 sub     %o2, %o0, %o0
F00E9330: d2142020                 lduh    [%l0+0x20], %o1
F00E9334: 912a2004                 sll     %o0, 4, %o0
F00E9338: 932a6010                 sll     %o1, 16, %o1
F00E933C: 933a6010                 sra     %o1, 16, %o1
F00E9340: 9622c009                 sub     %o3, %o1, %o3
F00E9344: 9002000b                 add     %o0, %o3, %o0
F00E9348: 912a2002                 sll     %o0, 2, %o0
F00E934C: a8050008                 add     %l4, %o0, %l4
F00E9350: 90102010                 mov     0x10, %o0
F00E9354: 02800005                 be      loc_F00E9368
F00E9358: b022001d                 sub     %o0, %i5, %i0
F00E935C: 80a3202d                 cmp     %o4, 0x2D ! '-'
F00E9360: 12800040                 bne     loc_F00E9460
F00E9364: d057bfce                 ldsh    [%fp+var_32], %o0
F00E9368: d057bfce                 ldsh    [%fp+var_32], %o0
F00E936C: aa22000a                 sub     %o0, %o2, %l5
F00E9370: aa057fff                 inc     -1, %l5
F00E9374: 80a57fff                 cmp     %l5, -1
F00E9378: 02800070                 be      loc_F00E9538
F00E937C: c607bf9c                 ld      [%fp+var_64], %g3
F00E9380: 113fc03fb8122300         set     -0xFF0100, %i4
F00E9388: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E9390: a6077fff                 add     %i5, -1, %l3
F00E9394: 80a4ffff                 cmp     %l3, -1
F00E9398: 0280002a                 be      loc_F00E9440
F00E939C: 912e2002                 sll     %i0, 2, %o0
F00E93A0: d0048000                 ld      [%l2], %o0
F00E93A4: d0258000                 st      %o0, [%l6]
F00E93A8: b4100008                 mov     %o0, %i2
F00E93AC: f6050000                 ld      [%l4], %i3
F00E93B0: ac05a004                 inc     4, %l6
F00E93B4: a336e018                 srl     %i3, 24, %l1
F00E93B8: 80a46000                 cmp     %l1, 0
F00E93BC: 0280001c                 be      loc_F00E942C
F00E93C0: a8052004                 inc     4, %l4
F00E93C4: 80a460ff                 cmp     %l1, 0xFF
F00E93C8: 32800004                 bne,a   loc_F00E93D8
F00E93CC: b72ee008                 sll     %i3, 8, %i3
F00E93D0: 10800017                 ba      loc_F00E942C
F00E93D4: f6248000                 st      %i3, [%l2]
F00E93D8: b52ea008                 sll     %i2, 8, %i2
F00E93DC: a21c60ff                 btog    0xFF, %l1
F00E93E0: 900e801c                 and     %i2, %i4, %o0
F00E93E4: 91322008                 srl     %o0, 8, %o0
F00E93E8: 7ffc7446                 call    _umul
F00E93EC: 92100011                 mov     %l1, %o1
F00E93F0: a0100008                 mov     %o0, %l0
F00E93F4: 900e8017                 and     %i2, %l7, %o0
F00E93F8: 92100011                 mov     %l1, %o1
F00E93FC: a0040017                 add     %l0, %l7, %l0
F00E9400: 7ffc7440                 call    _umul
F00E9404: a00c001c                 and     %l0, %i4, %l0
F00E9408: 90020017                 add     %o0, %l7, %o0
F00E940C: 91322008                 srl     %o0, 8, %o0
F00E9410: 900a0017                 and     %o0, %l7, %o0
F00E9414: a0140008                 bset    %o0, %l0
F00E9418: b406c010                 add     %i3, %l0, %i2
F00E941C: 9136a008                 srl     %i2, 8, %o0
F00E9420: 133fc000                 sethi   -0x1000000, %o1
F00E9424: 90120009                 bset    %o1, %o0
F00E9428: d0248000                 st      %o0, [%l2]
F00E942C: a604ffff                 inc     -1, %l3
F00E9430: 80a4ffff                 cmp     %l3, -1
F00E9434: 12bfffdb                 bne     loc_F00E93A0
F00E9438: a404a004                 inc     4, %l2
F00E943C: 912e2002                 sll     %i0, 2, %o0
F00E9440: a8050008                 add     %l4, %o0, %l4
F00E9444: 912e6002                 sll     %i1, 2, %o0
F00E9448: aa057fff                 inc     -1, %l5
F00E944C: 80a57fff                 cmp     %l5, -1
F00E9450: 12bfffd0                 bne     loc_F00E9390
F00E9454: a4048008                 add     %l2, %o0, %l2
F00E9458: 10800038                 ba      loc_F00E9538
F00E945C: c607bf9c                 ld      [%fp+var_64], %g3
F00E9460: aa22000a                 sub     %o0, %o2, %l5
F00E9464: aa057fff                 inc     -1, %l5
F00E9468: 80a57fff                 cmp     %l5, -1
F00E946C: 02800033                 be      loc_F00E9538
F00E9470: c607bf9c                 ld      [%fp+var_64], %g3
F00E9474: 113fc03fb8122300         set     -0xFF0100, %i4
F00E947C: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E9484: a6077fff                 add     %i5, -1, %l3
F00E9488: 80a4ffff                 cmp     %l3, -1
F00E948C: 02800024                 be      loc_F00E951C
F00E9490: 912e2002                 sll     %i0, 2, %o0
F00E9494: d0048000                 ld      [%l2], %o0
F00E9498: d0258000                 st      %o0, [%l6]
F00E949C: b4100008                 mov     %o0, %i2
F00E94A0: f6050000                 ld      [%l4], %i3
F00E94A4: ac05a004                 inc     4, %l6
F00E94A8: a28ee0ff                 andcc   %i3, 0xFF, %l1
F00E94AC: 02800017                 be      loc_F00E9508
F00E94B0: a8052004                 inc     4, %l4
F00E94B4: 80a460ff                 cmp     %l1, 0xFF
F00E94B8: 12800004                 bne     loc_F00E94C8
F00E94BC: a21c60ff                 btog    0xFF, %l1
F00E94C0: 10800012                 ba      loc_F00E9508
F00E94C4: f6248000                 st      %i3, [%l2]
F00E94C8: 900e801c                 and     %i2, %i4, %o0
F00E94CC: 91322008                 srl     %o0, 8, %o0
F00E94D0: 7ffc740c                 call    _umul
F00E94D4: 92100011                 mov     %l1, %o1
F00E94D8: a0100008                 mov     %o0, %l0
F00E94DC: 900e8017                 and     %i2, %l7, %o0
F00E94E0: 92100011                 mov     %l1, %o1
F00E94E4: a0040017                 add     %l0, %l7, %l0
F00E94E8: 7ffc7406                 call    _umul
F00E94EC: a00c001c                 and     %l0, %i4, %l0
F00E94F0: 90020017                 add     %o0, %l7, %o0
F00E94F4: 91322008                 srl     %o0, 8, %o0
F00E94F8: 900a0017                 and     %o0, %l7, %o0
F00E94FC: a0140008                 bset    %o0, %l0
F00E9500: b406c010                 add     %i3, %l0, %i2
F00E9504: f4248000                 st      %i2, [%l2]
F00E9508: a604ffff                 inc     -1, %l3
F00E950C: 80a4ffff                 cmp     %l3, -1
F00E9510: 12bfffe1                 bne     loc_F00E9494
F00E9514: a404a004                 inc     4, %l2
F00E9518: 912e2002                 sll     %i0, 2, %o0
F00E951C: a8050008                 add     %l4, %o0, %l4
F00E9520: 912e6002                 sll     %i1, 2, %o0
F00E9524: aa057fff                 inc     -1, %l5
F00E9528: 80a57fff                 cmp     %l5, -1
F00E952C: 12bfffd6                 bne     loc_F00E9484
F00E9530: a4048008                 add     %l2, %o0, %l2
F00E9534: c607bf9c                 ld      [%fp+var_64], %g3
F00E9538: d010e020                 lduh    [%g3+0x20], %o0
F00E953C: d030e028                 sth     %o0, [%g3+0x28]
F00E9540: d010e022                 lduh    [%g3+0x22], %o0
F00E9544: d030e02a                 sth     %o0, [%g3+0x2A]
F00E9548: d010e024                 lduh    [%g3+0x24], %o0
F00E954C: d030e02c                 sth     %o0, [%g3+0x2C]
F00E9550: d010e026                 lduh    [%g3+0x26], %o0
F00E9554: d030e02e                 sth     %o0, [%g3+0x2E]
F00E9558: c207bfbc                 ld      [%fp+var_44], %g1
F00E955C: 7fff663b                 call    _ev_unlock
F00E9560: 90006004                 add     %g1, 4, %o0
F00E9564: f007bfc4                 ld      [%fp+var_3C], %i0
F00E9568: 81c7e008                 ret
F00E956C: 81e80000                 restore
