F005724C: 9de3bf60                 save    %sp, -0xA0, %sp
F0057250: d0062014                 ld      [%i0+0x14], %o0
F0057254: d027bfe0                 st      %o0, [%fp+var_20]
F0057258: d0062018                 ld      [%i0+0x18], %o0
F005725C: d027bfe4                 st      %o0, [%fp+var_1C]
F0057260: d206201c                 ld      [%i0+0x1C], %o1
F0057264: f227bfc4                 st      %i1, [%fp+var_3C]
F0057268: d227bfe8                 st      %o1, [%fp+var_18]
F005726C: e0062020                 ld      [%i0+0x20], %l0
F0057270: ba10001a                 mov     %i2, %i5
F0057274: e027bfec                 st      %l0, [%fp+var_14]
F0057278: d2062024                 ld      [%i0+0x24], %o1
F005727C: 9407bfdc                 add     %fp, var_24, %o2
F0057280: d227bff0                 st      %o1, [%fp+var_10]
F0057284: d8062028                 ld      [%i0+0x28], %o4
F0057288: 9607bfd8                 add     %fp, var_28, %o3
F005728C: d007bfc4                 ld      [%fp+var_3C], %o0
F0057290: 40000baf                 call    _ipc_object_copyin_header
F0057294: d827bff4                 st      %o4, [%fp+var_C]
F0057298: 80a22000                 cmp     %o0, 0
F005729C: 02800005                 be      loc_F00572B0
F00572A0: 80a42000                 cmp     %l0, 0
F00572A4: 31040000                 sethi   0x10000000, %i0
F00572A8: 108000fc                 ba      locret_F0057698
F00572AC: b0162003                 bset    3, %i0
F00572B0: 0280000e                 be      loc_F00572E8
F00572B4: d007bfc4                 ld      [%fp+var_3C], %o0
F00572B8: 92100010                 mov     %l0, %o1
F00572BC: 9407bfd4                 add     %fp, var_2C, %o2
F00572C0: 40000ba3                 call    _ipc_object_copyin_header
F00572C4: 9607bfd0                 add     %fp, var_30, %o3
F00572C8: 80a22000                 cmp     %o0, 0
F00572CC: 02800009                 be      loc_F00572F0
F00572D0: d007bfdc                 ld      [%fp+var_24], %o0
F00572D4: 40000a72                 call    _ipc_object_destroy
F00572D8: d207bfd8                 ld      [%fp+var_28], %o1
F00572DC: 31040000                 sethi   0x10000000, %i0
F00572E0: 108000ee                 ba      locret_F0057698
F00572E4: b0162009                 bset    9, %i0
F00572E8: c027bfd4                 clr     [%fp+var_2C]
F00572EC: c027bfd0                 clr     [%fp+var_30]
F00572F0: d007bfd0                 ld      [%fp+var_30], %o0
F00572F4: d207bfd8                 ld      [%fp+var_28], %o1
F00572F8: 912a2008                 sll     %o0, 8, %o0
F00572FC: 92124008                 bset    %o0, %o1
F0057300: d2262014                 st      %o1, [%i0+0x14]
F0057304: d007bfe4                 ld      [%fp+var_1C], %o0
F0057308: d207bfdc                 ld      [%fp+var_24], %o1
F005730C: d0262018                 st      %o0, [%i0+0x18]
F0057310: d007bfd4                 ld      [%fp+var_2C], %o0
F0057314: d226201c                 st      %o1, [%i0+0x1C]
F0057318: d0262020                 st      %o0, [%i0+0x20]
F005731C: d007bfe8                 ld      [%fp+var_18], %o0
F0057320: d0262024                 st      %o0, [%i0+0x24]
F0057324: d007bff4                 ld      [%fp+var_C], %o0
F0057328: d0262028                 st      %o0, [%i0+0x28]
F005732C: d00fbfe3                 ldub    [%fp+var_20+3], %o0
F0057330: 80a22000                 cmp     %o0, 0
F0057334: 02800019                 be      loc_F0057398
F0057338: a6102000                 mov     0, %l3
F005733C: 108000d7                 ba      locret_F0057698
F0057340: b0102000                 mov     0, %i0
F0057344: 9210001c                 mov     %i4, %o1
F0057348: 94102000                 mov     0, %o2
F005734C: 7ffff757                 call    _ipc_kmsg_clean_partial
F0057350: 96102000                 mov     0, %o3
F0057354: 31040000                 sethi   0x10000000, %i0
F0057358: 108000d0                 ba      locret_F0057698
F005735C: b016200f                 bset    0xF, %i0
F0057360: 90100018                 mov     %i0, %o0
F0057364: 10800021                 ba      loc_F00573E8
F0057368: 9210001c                 mov     %i4, %o1
F005736C: 90100018                 mov     %i0, %o0
F0057370: 1080001e                 ba      loc_F00573E8
F0057374: 9210001c                 mov     %i4, %o1
F0057378: 90100018                 mov     %i0, %o0
F005737C: 9210001c                 mov     %i4, %o1
F0057380: 94102001                 mov     1, %o2
F0057384: 7ffff749                 call    _ipc_kmsg_clean_partial
F0057388: 96100011                 mov     %l1, %o3
F005738C: 31040000                 sethi   0x10000000, %i0
F0057390: 108000c2                 ba      locret_F0057698
F0057394: b016200a                 bset    0xA, %i0
F0057398: d0062018                 ld      [%i0+0x18], %o0
F005739C: a406202c                 add     %i0, 0x2C, %l2 ! ','
F00573A0: 90022014                 inc     0x14, %o0
F00573A4: b6060008                 add     %i0, %o0, %i3
F00573A8: 80a4801b                 cmp     %l2, %i3
F00573AC: 1a8000b4                 bcc     loc_F005767C
F00573B0: 9226c012                 sub     %i3, %l2, %o1
F00573B4: 80a26003                 cmp     %o1, 3
F00573B8: b8100012                 mov     %l2, %i4
F00573BC: 08800009                 bleu    loc_F00573E0
F00573C0: a8100012                 mov     %l2, %l4
F00573C4: d0048000                 ld      [%l2], %o0
F00573C8: ad322002                 srl     %o0, 2, %l6
F00573CC: ac8da001                 andcc   %l6, 1, %l6
F00573D0: 0280000c                 be      loc_F0057400
F00573D4: 80a2600b                 cmp     %o1, 0xB
F00573D8: 3880000b                 bgu,a   loc_F0057404
F00573DC: d0050000                 ld      [%l4], %o0
F00573E0: 90100018                 mov     %i0, %o0
F00573E4: 92100012                 mov     %l2, %o1
F00573E8: 94102000                 mov     0, %o2
F00573EC: 7ffff72f                 call    _ipc_kmsg_clean_partial
F00573F0: 96102000                 mov     0, %o3
F00573F4: 31040000                 sethi   0x10000000, %i0
F00573F8: 108000a8                 ba      locret_F0057698
F00573FC: b0162008                 bset    8, %i0
F0057400: d0050000                 ld      [%l4], %o0
F0057404: 80a5a000                 cmp     %l6, 0
F0057408: a1322003                 srl     %o0, 3, %l0
F005740C: a00c2001                 and     %l0, 1, %l0
F0057410: b3322001                 srl     %o0, 1, %i1
F0057414: 02800007                 be      loc_F0057430
F0057418: b20e6001                 and     %i1, 1, %i1
F005741C: f4152004                 lduh    [%l4+4], %i2
F0057420: d2152006                 lduh    [%l4+6], %o1
F0057424: ee052008                 ld      [%l4+8], %l7
F0057428: 10800008                 ba      loc_F0057448
F005742C: a404a00c                 inc     0xC, %l2
F0057430: f40d0000                 ldub    [%l4], %i2
F0057434: 93322010                 srl     %o0, 16, %o1
F0057438: 920a60ff                 and     %o1, 0xFF, %o1
F005743C: af322004                 srl     %o0, 4, %l7
F0057440: ae0defff                 and     %l7, 0xFFF, %l7
F0057444: a404a004                 inc     4, %l2
F0057448: aa06bffb                 add     %i2, -5, %l5
F005744C: 80a56001                 cmp     %l5, 1
F0057450: 28800003                 bleu,a  loc_F005745C
F0057454: aa102001                 mov     1, %l5
F0057458: aa102000                 mov     0, %l5
F005745C: 80a56000                 cmp     %l5, 0
F0057460: 02800004                 be      loc_F0057470
F0057464: 80a26020                 cmp     %o1, 0x20 ! ' '
F0057468: 12bfffb7                 bne     loc_F0057344
F005746C: 90100018                 mov     %i0, %o0
F0057470: d0050000                 ld      [%l4], %o0
F0057474: 80a5a000                 cmp     %l6, 0
F0057478: 900a3ffe                 and     %o0, -2, %o0
F005747C: 02800009                 be      loc_F00574A0
F0057480: d0250000                 st      %o0, [%l4]
F0057484: c02d0000                 clrb    [%l4]
F0057488: c02d2001                 clrb    [%l4+1]
F005748C: d0050000                 ld      [%l4], %o0
F0057490: 053fffc08410a00f         set     -0xFFF1, %g2
F0057498: 900a0002                 and     %o0, %g2, %o0
F005749C: d0250000                 st      %o0, [%l4]
F00574A0: 7ffebc18                 call    _umul
F00574A4: 90100017                 mov     %l7, %o0
F00574A8: 80a42000                 cmp     %l0, 0
F00574AC: 90022007                 inc     7, %o0
F00574B0: 0280000a                 be      loc_F00574D8
F00574B4: a3322003                 srl     %o0, 3, %l1
F00574B8: 90046003                 add     %l1, 3, %o0
F00574BC: 920a3ffc                 and     %o0, -4, %o1
F00574C0: 9026c012                 sub     %i3, %l2, %o0
F00574C4: 80a20009                 cmp     %o0, %o1
F00574C8: 0abfffa6                 bcs     loc_F0057360
F00574CC: a0100012                 mov     %l2, %l0
F00574D0: 1080003b                 ba      loc_F00575BC
F00574D4: a4048009                 add     %l2, %o1, %l2
F00574D8: 9026c012                 sub     %i3, %l2, %o0
F00574DC: 80a22003                 cmp     %o0, 3
F00574E0: 08bfffa3                 bleu    loc_F005736C
F00574E4: 80a46000                 cmp     %l1, 0
F00574E8: 12800004                 bne     loc_F00574F8
F00574EC: e6048000                 ld      [%l2], %l3
F00574F0: 10800030                 ba      loc_F00575B0
F00574F4: a0102000                 mov     0, %l0
F00574F8: 80a56000                 cmp     %l5, 0
F00574FC: 0280001b                 be      loc_F0057568
F0057500: 9010001d                 mov     %i5, %o0
F0057504: 400042db                 call    _kalloc
F0057508: 90100011                 mov     %l1, %o0
F005750C: a0920000                 orcc    %o0, %g0, %l0
F0057510: 02800020                 be      loc_F0057590
F0057514: 9010001d                 mov     %i5, %o0
F0057518: 92100013                 mov     %l3, %o1
F005751C: 94100010                 mov     %l0, %o2! size
F0057520: 4000b175                 call    _copyinmap
F0057524: 96100011                 mov     %l1, %o3
F0057528: 80a22000                 cmp     %o0, 0
F005752C: 3280000b                 bne,a   loc_F0057558
F0057530: 90100010                 mov     %l0, %o0
F0057534: 80a66000                 cmp     %i1, 0
F0057538: 0280001e                 be      loc_F00575B0
F005753C: 9010001d                 mov     %i5, %o0! target_task
F0057540: 92100013                 mov     %l3, %o1! address
F0057544: 4000ccd7                 call    _vm_deallocate
F0057548: 94100011                 mov     %l1, %o2
F005754C: 80a22000                 cmp     %o0, 0
F0057550: 02800018                 be      loc_F00575B0
F0057554: 90100010                 mov     %l0, %o0
F0057558: 40004312                 call    _kfree
F005755C: 92100011                 mov     %l1, %o1
F0057560: 1080000d                 ba      loc_F0057594
F0057564: 90100018                 mov     %i0, %o0
F0057568: 92100013                 mov     %l3, %o1
F005756C: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F0057570: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F0057574: 96100011                 mov     %l1, %o3
F0057578: 98100019                 mov     %i1, %o4
F005757C: 4000bb3f                 call    _vm_move
F0057580: 9a07bfcc                 add     %fp, var_34, %o5
F0057584: 80a22000                 cmp     %o0, 0
F0057588: 0280000a                 be      loc_F00575B0
F005758C: e007bfcc                 ld      [%fp+var_34], %l0
F0057590: 90100018                 mov     %i0, %o0
F0057594: 9210001c                 mov     %i4, %o1
F0057598: 94102000                 mov     0, %o2
F005759C: 7ffff6c3                 call    _ipc_kmsg_clean_partial
F00575A0: 96102000                 mov     0, %o3
F00575A4: 31040000                 sethi   0x10000000, %i0
F00575A8: 1080003c                 ba      locret_F0057698
F00575AC: b016200c                 bset    0xC, %i0
F00575B0: e0248000                 st      %l0, [%l2]
F00575B4: a404a004                 inc     4, %l2
F00575B8: a6102001                 mov     1, %l3
F00575BC: 80a56000                 cmp     %l5, 0
F00575C0: 02bfff7b                 be      loc_F00573AC
F00575C4: 80a4801b                 cmp     %l2, %i3
F00575C8: 400008fd                 call    _ipc_object_copyin_type
F00575CC: 9010001a                 mov     %i2, %o0
F00575D0: 80a5a000                 cmp     %l6, 0
F00575D4: a6100008                 mov     %o0, %l3
F00575D8: 02800004                 be      loc_F00575E8
F00575DC: 90100010                 mov     %l0, %o0
F00575E0: 10800003                 ba      loc_F00575EC
F00575E4: e6352004                 sth     %l3, [%l4+4]
F00575E8: e62d0000                 stb     %l3, [%l4]
F00575EC: a2102000                 mov     0, %l1
F00575F0: 80a44017                 cmp     %l1, %l7
F00575F4: 1a800020                 bcc     loc_F0057674
F00575F8: a0100008                 mov     %o0, %l0
F00575FC: d2040000                 ld      [%l0], %o1
F0057600: 80a26000                 cmp     %o1, 0
F0057604: 02800018                 be      loc_F0057664
F0057608: 80a27fff                 cmp     %o1, -1
F005760C: 02800016                 be      loc_F0057664
F0057610: d007bfc4                 ld      [%fp+var_3C], %o0
F0057614: 9410001a                 mov     %i2, %o2
F0057618: 96100019                 mov     %i1, %o3
F005761C: 40000abc                 call    _ipc_object_copyin_compat
F0057620: 9807bfc8                 add     %fp, var_38, %o4
F0057624: 80a22000                 cmp     %o0, 0
F0057628: 12bfff54                 bne     loc_F0057378
F005762C: 80a4e010                 cmp     %l3, 0x10
F0057630: 1280000c                 bne     loc_F0057660
F0057634: d007bfc8                 ld      [%fp+var_38], %o0
F0057638: 40000de3                 call    _ipc_port_check_circularity
F005763C: d207bfdc                 ld      [%fp+var_24], %o1
F0057640: 80a22000                 cmp     %o0, 0
F0057644: 02800007                 be      loc_F0057660
F0057648: d007bfc8                 ld      [%fp+var_38], %o0
F005764C: d0062014                 ld      [%i0+0x14], %o0
F0057650: 05100000                 sethi   0x40000000, %g2
F0057654: 90120002                 bset    %g2, %o0
F0057658: d0262014                 st      %o0, [%i0+0x14]
F005765C: d007bfc8                 ld      [%fp+var_38], %o0
F0057660: d0240000                 st      %o0, [%l0]
F0057664: a2046001                 inc     %l1
F0057668: 80a44017                 cmp     %l1, %l7
F005766C: 0abfffe4                 bcs     loc_F00575FC
F0057670: a0042004                 inc     4, %l0
F0057674: 10bfff4d                 ba      loc_F00573A8
F0057678: a6102001                 mov     1, %l3
F005767C: 80a4e000                 cmp     %l3, 0
F0057680: 02800005                 be      loc_F0057694
F0057684: 13200000                 sethi   0x80000000, %o1
F0057688: d0062014                 ld      [%i0+0x14], %o0
F005768C: 90120009                 bset    %o1, %o0
F0057690: d0262014                 st      %o0, [%i0+0x14]
F0057694: b0102000                 mov     0, %i0
F0057698: 81c7e008                 ret
F005769C: 81e80000                 restore
