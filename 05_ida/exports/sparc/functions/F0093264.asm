F0093264: 9de3beb0                 save    %sp, -0x150, %sp! int
F0093268: a6102000                 mov     0, %l3
F009326C: ae102000                 mov     0, %l7
F0093270: a8102000                 mov     0, %l4
F0093274: 80a66000                 cmp     %i1, 0
F0093278: 02800006                 be      loc_F0093290
F009327C: a4102000                 mov     0, %l2
F0093280: e0066014                 ld      [%i1+0x14], %l0
F0093284: ea06600c                 ld      [%i1+0xC], %l5
F0093288: 1080000b                 ba      loc_F00932B4
F009328C: ec066010                 ld      [%i1+0x10], %l6
F0093290: 80a6a000                 cmp     %i2, 0
F0093294: 02800006                 be      loc_F00932AC
F0093298: 113c0449                 sethi   -0xFEEDC00, %o0
F009329C: e006a018                 ld      [%i2+0x18], %l0
F00932A0: ea06a010                 ld      [%i2+0x10], %l5
F00932A4: 10800004                 ba      loc_F00932B4
F00932A8: ec06a014                 ld      [%i2+0x14], %l6
F00932AC: 4000cb9e                 call    _IOPanic
F00932B0: 901220f0                 bset    0xF0, %o0
F00932B4: 113c0504                 sethi   %hi(paController), %o0
F00932B8: e202217c                 ld      [%o0+%lo(paController)], %l1
F00932BC: 90100018                 mov     %i0, %o0! id
F00932C0: 4001796c                 call    _objc_msgSend
F00932C4: 92100011                 mov     %l1, %o1
F00932C8: 133c0504                 sethi   %hi(paMaxtransfer), %o1! SEL
F00932CC: 40017969                 call    _objc_msgSend
F00932D0: d2026168                 ld      [%o1+%lo(paMaxtransfer)], %o1! SEL
F00932D4: 80a40008                 cmp     %l0, %o0
F00932D8: 08800004                 bleu    loc_F00932E8
F00932DC: 80a42000                 cmp     %l0, 0
F00932E0: 108000f1                 ba      locret_F00936A4
F00932E4: b0102016                 mov     0x16, %i0
F00932E8: 0280002b                 be      loc_F0093394
F00932EC: 90100018                 mov     %i0, %o0! id
F00932F0: 40017960                 call    _objc_msgSend
F00932F4: 92100011                 mov     %l1, %o1
F00932F8: a2100008                 mov     %o0, %l1
F00932FC: 133c0504                 sethi   %hi(paGetdmaalignmen), %o1
F0093300: d2026180                 ld      [%o1+%lo(paGetdmaalignmen)], %o1! SEL
F0093304: 4001795b                 call    _objc_msgSend
F0093308: 9407bfe8                 add     %fp, var_18, %o2
F009330C: 80a56001                 cmp     %l5, 1
F0093310: 12800003                 bne     loc_F009331C
F0093314: d207bff0                 ld      [%fp+var_10], %o1
F0093318: d207bff4                 ld      [%fp+var_C], %o1
F009331C: ae102001                 mov     1, %l7
F0093320: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0093324: 80a26001                 cmp     %o1, 1
F0093328: 08800007                 bleu    loc_F0093344
F009332C: e8022340                 ld      [%o0+%lo(_kernel_map)], %l4
F0093330: 90040009                 add     %l0, %o1, %o0
F0093334: 90023fff                 inc     -1, %o0
F0093338: 92200009                 neg     %o1
F009333C: 10800003                 ba      loc_F0093348
F0093340: a60a0009                 and     %o0, %o1, %l3
F0093344: a6100010                 mov     %l0, %l3
F0093348: 90100011                 mov     %l1, %o0! id
F009334C: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F0093350: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F0093354: 94100010                 mov     %l0, %o2! int
F0093358: 9607bfe4                 add     %fp, var_1C, %o3! int
F009335C: 40017945                 call    _objc_msgSend
F0093360: 9807bfe0                 add     %fp, var_20, %o4! int
F0093364: 80a56001                 cmp     %l5, 1
F0093368: 1280000c                 bne     loc_F0093398
F009336C: a2100008                 mov     %o0, %l1
F0093370: 90100016                 mov     %l6, %o0! int
F0093374: 92100011                 mov     %l1, %o1! int
F0093378: 40001338                 call    _copyin
F009337C: 94100010                 mov     %l0, %o2
F0093380: a4920000                 orcc    %o0, %g0, %l2
F0093384: 02800006                 be      loc_F009339C
F0093388: 80a66000                 cmp     %i1, 0
F009338C: 108000c0                 ba      loc_F009368C
F0093390: a410200e                 mov     0xE, %l2
F0093394: a2100016                 mov     %l6, %l1
F0093398: 80a66000                 cmp     %i1, 0
F009339C: 02800060                 be      loc_F009351C
F00933A0: a007bf10                 add     %fp, var_F0, %l0
F00933A4: 9007bf80                 add     %fp, var_80, %o0! void *
F00933A8: 400006ac                 call    _bzero
F00933AC: 92102060                 mov     0x60, %o1 ! '`'
F00933B0: 113c0504                 sethi   %hi(paScsi3Target), %o0! id
F00933B4: d20221dc                 ld      [%o0+%lo(paScsi3Target)], %o1! SEL
F00933B8: 4001792e                 call    _objc_msgSend
F00933BC: 90100018                 mov     %i0, %o0
F00933C0: 80a22000                 cmp     %o0, 0
F00933C4: 388000b2                 bgu,a   loc_F009368C
F00933C8: a4102016                 mov     0x16, %l2
F00933CC: 32800006                 bne,a   loc_F00933E4
F00933D0: d22fbf80                 stb     %o1, [%fp+var_80]
F00933D4: 80a2601f                 cmp     %o1, 0x1F
F00933D8: 388000ad                 bgu,a   loc_F009368C
F00933DC: a4102016                 mov     0x16, %l2
F00933E0: d22fbf80                 stb     %o1, [%fp+var_80]
F00933E4: 113c0504                 sethi   %hi(paScsi3Lun), %o0! id
F00933E8: d20221e0                 ld      [%o0+%lo(paScsi3Lun)], %o1! SEL
F00933EC: 40017921                 call    _objc_msgSend
F00933F0: 90100018                 mov     %i0, %o0
F00933F4: 80a22000                 cmp     %o0, 0
F00933F8: 388000a5                 bgu,a   loc_F009368C
F00933FC: a4102016                 mov     0x16, %l2
F0093400: 32800007                 bne,a   loc_F009341C
F0093404: d22fbf81                 stb     %o1, [%fp+var_7F]
F0093408: 80a26007                 cmp     %o1, 7
F009340C: 28800004                 bleu,a  loc_F009341C
F0093410: d22fbf81                 stb     %o1, [%fp+var_7F]
F0093414: 1080009e                 ba      loc_F009368C
F0093418: a4102016                 mov     0x16, %l2
F009341C: 90100018                 mov     %i0, %o0! id
F0093420: 9407bf80                 add     %fp, var_80, %o2
F0093424: 96100011                 mov     %l1, %o3
F0093428: d2064000                 ld      [%i1], %o1
F009342C: 98100014                 mov     %l4, %o4
F0093430: d227bf84                 st      %o1, [%fp+var_7C]
F0093434: d2066004                 ld      [%i1+4], %o1
F0093438: 9a066024                 add     %i1, 0x24, %o5 ! '$'
F009343C: d227bf88                 st      %o1, [%fp+var_78]
F0093440: d2066008                 ld      [%i1+8], %o1
F0093444: 07200000                 sethi   0x80000000, %g3
F0093448: de07bf9c                 ld      [%fp+var_64], %o7
F009344C: d227bf8c                 st      %o1, [%fp+var_74]
F0093450: d206600c                 ld      [%i1+0xC], %o1
F0093454: 862bc003                 andn    %o7, %g3, %g3
F0093458: 80a00009                 cmp     %g0, %o1
F009345C: 92603fff                 subc    %g0, -1, %o1
F0093460: d22fbf90                 stb     %o1, [%fp+var_70]
F0093464: e627bf94                 st      %l3, [%fp+var_6C]
F0093468: c4066018                 ld      [%i1+0x18], %g2
F009346C: 1f100000                 sethi   0x40000000, %o7
F0093470: c427bf98                 st      %g2, [%fp+var_68]
F0093474: c406604c                 ld      [%i1+0x4C], %g2
F0093478: 133c0504                 sethi   %hi(paExecuterequest), %o1
F009347C: d20261f8                 ld      [%o1+%lo(paExecuterequest)], %o1! SEL
F0093480: 8530a017                 srl     %g2, 23, %g2
F0093484: 8418a001                 btog    1, %g2
F0093488: 8528a01f                 sll     %g2, 31, %g2
F009348C: 8610c002                 bset    %g2, %g3
F0093490: c627bf9c                 st      %g3, [%fp+var_64]
F0093494: 9e28c00f                 andn    %g3, %o7, %o7
F0093498: c406604c                 ld      [%i1+0x4C], %g2
F009349C: 07080000                 sethi   0x20000000, %g3
F00934A0: 8530a016                 srl     %g2, 22, %g2
F00934A4: 8408a001                 and     %g2, 1, %g2
F00934A8: 8528a01e                 sll     %g2, 30, %g2
F00934AC: 9e13c002                 bset    %g2, %o7
F00934B0: de27bf9c                 st      %o7, [%fp+var_64]
F00934B4: c406604c                 ld      [%i1+0x4C], %g2
F00934B8: 862bc003                 andn    %o7, %g3, %g3
F00934BC: 8530a015                 srl     %g2, 21, %g2
F00934C0: 8408a001                 and     %g2, 1, %g2
F00934C4: 8528a01d                 sll     %g2, 29, %g2
F00934C8: 8610c002                 bset    %g2, %g3
F00934CC: c627bf9c                 st      %g3, [%fp+var_64]
F00934D0: c40e604c                 ldub    [%i1+0x4C], %g2
F00934D4: 8608fff0                 and     %g3, -0x10, %g3
F00934D8: 8408a00f                 and     %g2, 0xF, %g2
F00934DC: 8610c002                 bset    %g2, %g3
F00934E0: 400178e4                 call    _objc_msgSend
F00934E4: c627bf9c                 st      %g3, [%fp+var_64]
F00934E8: d026601c                 st      %o0, [%i1+0x1C]
F00934EC: d00fbfa4                 ldub    [%fp+var_5C], %o0
F00934F0: d02e6020                 stb     %o0, [%i1+0x20]
F00934F4: d007bfa8                 ld      [%fp+var_58], %o0
F00934F8: d2066014                 ld      [%i1+0x14], %o1! size_t
F00934FC: a0100008                 mov     %o0, %l0
F0093500: 80a40009                 cmp     %l0, %o1
F0093504: 04800003                 ble     loc_F0093510
F0093508: d0266040                 st      %o0, [%i1+0x40]
F009350C: d2266040                 st      %o1, [%i1+0x40]
F0093510: d01fbfb0                 ldd     [%fp+var_50], %o0
F0093514: 10800050                 ba      loc_F0093654
F0093518: 94066044                 add     %i1, 0x44, %o2 ! 'D'
F009351C: 90100010                 mov     %l0, %o0! void *
F0093520: 4000064e                 call    _bzero
F0093524: 92102070                 mov     0x70, %o1 ! 'p'
F0093528: 113c0504                 sethi   %hi(paScsi3Target), %o0! id
F009352C: d20221dc                 ld      [%o0+%lo(paScsi3Target)], %o1! SEL
F0093530: 400178d0                 call    _objc_msgSend
F0093534: 90100018                 mov     %i0, %o0
F0093538: d03fbf10                 std     %o0, [%fp+var_F0]
F009353C: 113c0504                 sethi   %hi(paScsi3Lun), %o0! id
F0093540: d20221e0                 ld      [%o0+%lo(paScsi3Lun)], %o1! SEL
F0093544: 400178cb                 call    _objc_msgSend
F0093548: 90100018                 mov     %i0, %o0
F009354C: d03fbf18                 std     %o0, [%fp+var_E8]
F0093550: 90100018                 mov     %i0, %o0! id
F0093554: 94100010                 mov     %l0, %o2
F0093558: d2068000                 ld      [%i2], %o1
F009355C: 96100011                 mov     %l1, %o3! int
F0093560: d227bf20                 st      %o1, [%fp+var_E0]
F0093564: d206a004                 ld      [%i2+4], %o1
F0093568: 98100014                 mov     %l4, %o4! int
F009356C: d227bf24                 st      %o1, [%fp+var_DC]
F0093570: d206a008                 ld      [%i2+8], %o1
F0093574: 9a102024                 mov     0x24, %o5 ! '$'! int
F0093578: d227bf28                 st      %o1, [%fp+var_D8]
F009357C: d206a00c                 ld      [%i2+0xC], %o1
F0093580: 07200000                 sethi   0x80000000, %g3
F0093584: de07bf3c                 ld      [%fp+var_C4], %o7
F0093588: d227bf2c                 st      %o1, [%fp+var_D4]
F009358C: d206a010                 ld      [%i2+0x10], %o1
F0093590: 862bc003                 andn    %o7, %g3, %g3
F0093594: 80a00009                 cmp     %g0, %o1
F0093598: 92603fff                 subc    %g0, -1, %o1
F009359C: d22fbf30                 stb     %o1, [%fp+var_D0]
F00935A0: e627bf34                 st      %l3, [%fp+var_CC]
F00935A4: c406a01c                 ld      [%i2+0x1C], %g2
F00935A8: 1f100000                 sethi   0x40000000, %o7
F00935AC: c427bf38                 st      %g2, [%fp+var_C8]
F00935B0: c406a050                 ld      [%i2+0x50], %g2
F00935B4: 133c0504                 sethi   %hi(paExecutescsi3re), %o1
F00935B8: d20261fc                 ld      [%o1+%lo(paExecutescsi3re)], %o1! SEL
F00935BC: 8530a017                 srl     %g2, 23, %g2
F00935C0: 8418a001                 btog    1, %g2
F00935C4: 8528a01f                 sll     %g2, 31, %g2
F00935C8: 8610c002                 bset    %g2, %g3
F00935CC: c627bf3c                 st      %g3, [%fp+var_C4]
F00935D0: 9e28c00f                 andn    %g3, %o7, %o7
F00935D4: c406a050                 ld      [%i2+0x50], %g2
F00935D8: 07080000                 sethi   0x20000000, %g3
F00935DC: 8530a016                 srl     %g2, 22, %g2
F00935E0: 8408a001                 and     %g2, 1, %g2
F00935E4: 8528a01e                 sll     %g2, 30, %g2
F00935E8: 9e13c002                 bset    %g2, %o7
F00935EC: de27bf3c                 st      %o7, [%fp+var_C4]
F00935F0: c406a050                 ld      [%i2+0x50], %g2
F00935F4: 862bc003                 andn    %o7, %g3, %g3
F00935F8: 8530a015                 srl     %g2, 21, %g2
F00935FC: 8408a001                 and     %g2, 1, %g2
F0093600: 8528a01d                 sll     %g2, 29, %g2
F0093604: 8610c002                 bset    %g2, %g3
F0093608: c627bf3c                 st      %g3, [%fp+var_C4]
F009360C: c40ea050                 ldub    [%i2+0x50], %g2
F0093610: 8608fff0                 and     %g3, -0x10, %g3
F0093614: 8408a00f                 and     %g2, 0xF, %g2
F0093618: 8610c002                 bset    %g2, %g3
F009361C: 40017895                 call    _objc_msgSend
F0093620: c627bf3c                 st      %g3, [%fp+var_C4]
F0093624: d026a020                 st      %o0, [%i2+0x20]
F0093628: d00fbf44                 ldub    [%fp+var_BC], %o0
F009362C: d02ea024                 stb     %o0, [%i2+0x24]
F0093630: d007bf48                 ld      [%fp+var_B8], %o0
F0093634: d206a018                 ld      [%i2+0x18], %o1
F0093638: a0100008                 mov     %o0, %l0
F009363C: 80a40009                 cmp     %l0, %o1
F0093640: 04800003                 ble     loc_F009364C
F0093644: d026a044                 st      %o0, [%i2+0x44]
F0093648: d226a044                 st      %o1, [%i2+0x44]
F009364C: d01fbf50                 ldd     [%fp+var_B0], %o0
F0093650: 9406a048                 add     %i2, 0x48, %o2 ! 'H'! int
F0093654: 7fff6ae0                 call    _ns_time_to_timeval
F0093658: 01000000                 nop
F009365C: 80a56000                 cmp     %l5, 0
F0093660: 1280000c                 bne     loc_F0093690
F0093664: 80a5e000                 cmp     %l7, 0
F0093668: 80a42000                 cmp     %l0, 0
F009366C: 02800008                 be      loc_F009368C
F0093670: 80a5e000                 cmp     %l7, 0
F0093674: 02800007                 be      loc_F0093690
F0093678: 90100011                 mov     %l1, %o0! int
F009367C: 92100016                 mov     %l6, %o1! int
F0093680: 40001293                 call    _copyout
F0093684: 94100010                 mov     %l0, %o2
F0093688: a4100008                 mov     %o0, %l2
F009368C: 80a5e000                 cmp     %l7, 0
F0093690: 02800004                 be      loc_F00936A0
F0093694: d007bfe4                 ld      [%fp+var_1C], %o0
F0093698: 4000ca2b                 call    _IOFree
F009369C: d207bfe0                 ld      [%fp+var_20], %o1
F00936A0: b0100012                 mov     %l2, %i0
F00936A4: 81c7e008                 ret
F00936A8: 81e80000                 restore
