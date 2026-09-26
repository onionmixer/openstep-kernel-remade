F00CF178: 9de3bf08                 save    %sp, -0xF8, %sp
F00CF17C: 113c0504                 sethi   %hi(paName), %o0! id
F00CF180: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00CF184: a2102064                 mov     0x64, %l1 ! 'd'
F00CF188: 400089ba                 call    _objc_msgSend
F00CF18C: 90100018                 mov     %i0, %o0
F00CF190: 9410200a                 mov     0xA, %o2
F00CF194: d426a034                 st      %o2, [%i2+0x34]
F00CF198: 92102005                 mov     5, %o1
F00CF19C: d226a038                 st      %o1, [%i2+0x38]
F00CF1A0: d426a03c                 st      %o2, [%i2+0x3C]
F00CF1A4: d206a034                 ld      [%i2+0x34], %o1
F00CF1A8: 80a26000                 cmp     %o1, 0
F00CF1AC: 02800154                 be      loc_F00CF6FC
F00CF1B0: a4100008                 mov     %o0, %l2
F00CF1B4: d006a038                 ld      [%i2+0x38], %o0
F00CF1B8: 80a22000                 cmp     %o0, 0
F00CF1BC: 22800151                 be,a    loc_F00CF700
F00CF1C0: d006a034                 ld      [%i2+0x34], %o0
F00CF1C4: a807bf90                 add     %fp, var_70, %l4
F00CF1C8: 273c0505                 sethi   -0xFEBEC00, %l3
F00CF1CC: d006a03c                 ld      [%i2+0x3C], %o0
F00CF1D0: 80a22000                 cmp     %o0, 0
F00CF1D4: 0280014a                 be      loc_F00CF6FC
F00CF1D8: 90100018                 mov     %i0, %o0! id
F00CF1DC: 133c0505                 sethi   %hi(paSetupscsireqSc), %o1
F00CF1E0: d20263b4                 ld      [%o1+%lo(paSetupscsireqSc)], %o1! SEL
F00CF1E4: 9410001a                 mov     %i2, %o2
F00CF1E8: 400089a2                 call    _objc_msgSend
F00CF1EC: 96100014                 mov     %l4, %o3
F00CF1F0: 80a22000                 cmp     %o0, 0
F00CF1F4: 128001c5                 bne     locret_F00CF908
F00CF1F8: 113c0505                 sethi   %hi(paExecuterequest_0), %o0
F00CF1FC: d20223b0                 ld      [%o0+%lo(paExecuterequest_0)], %o1! SEL
F00CF200: d407bf70                 ld      [%fp+var_90], %o2
F00CF204: 11200000                 sethi   0x80000000, %o0
F00CF208: 902a8008                 andn    %o2, %o0, %o0
F00CF20C: d027bf70                 st      %o0, [%fp+var_90]
F00CF210: d0062184                 ld      [%i0+0x184], %o0! id
F00CF214: d606a00c                 ld      [%i2+0xC], %o3
F00CF218: d806a010                 ld      [%i2+0x10], %o4
F00CF21C: 40008995                 call    _objc_msgSend
F00CF220: 94100014                 mov     %l4, %o2
F00CF224: a2920000                 orcc    %o0, %g0, %l1
F00CF228: 32800045                 bne,a   loc_F00CF33C
F00CF22C: d206a020                 ld      [%i2+0x20], %o1
F00CF230: d0068000                 ld      [%i2], %o0
F00CF234: 80a22001                 cmp     %o0, 1
F00CF238: 18800020                 bgu     loc_F00CF2B8
F00CF23C: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F00CF240: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F00CF244: 4000898b                 call    _objc_msgSend
F00CF248: 90100018                 mov     %i0, %o0
F00CF24C: a0100008                 mov     %o0, %l0
F00CF250: d006a008                 ld      [%i2+8], %o0
F00CF254: 7ffcdcab                 call    _umul
F00CF258: 92100010                 mov     %l0, %o1
F00CF25C: d207bfb8                 ld      [%fp+var_48], %o1
F00CF260: 80a20009                 cmp     %o0, %o1
F00CF264: 22800016                 be,a    loc_F00CF2BC
F00CF268: d2062188                 ld      [%i0+0x188], %o1
F00CF26C: d006a038                 ld      [%i2+0x38], %o0
F00CF270: 90023fff                 inc     -1, %o0
F00CF274: 80a22000                 cmp     %o0, 0
F00CF278: 0480015e                 ble     loc_F00CF7F0
F00CF27C: d026a038                 st      %o0, [%i2+0x38]
F00CF280: d006a008                 ld      [%i2+8], %o0
F00CF284: 7ffcdc9f                 call    _umul
F00CF288: 92100010                 mov     %l0, %o1
F00CF28C: 133c03ed                 sethi   %hi(aSTransferCount_0), %o1! "%s: TRANSFER COUNT ERROR.  Expected = %"...
F00CF290: 94100008                 mov     %o0, %o2
F00CF294: 90126030                 or      %o1, %lo(aSTransferCount_0), %o0! "%s: TRANSFER COUNT ERROR.  Expected = %"...
F00CF298: d606a024                 ld      [%i2+0x24], %o3
F00CF29C: 7fffdb96                 call    _IOLog
F00CF2A0: 92100012                 mov     %l2, %o1
F00CF2A4: 90100018                 mov     %i0, %o0
F00CF2A8: 9410001a                 mov     %i2, %o2
F00CF2AC: d204e3ac                 ld      [%l3+0x3AC], %o1
F00CF2B0: 108000f4                 ba      loc_F00CF680
F00CF2B4: 96102000                 mov     0, %o3
F00CF2B8: d2062188                 ld      [%i0+0x188], %o1
F00CF2BC: 11000010                 sethi   0x4000, %o0
F00CF2C0: 808a4008                 btst    %o0, %o1
F00CF2C4: 2280010f                 be,a    loc_F00CF700
F00CF2C8: d006a034                 ld      [%i2+0x34], %o0
F00CF2CC: d0068000                 ld      [%i2], %o0
F00CF2D0: 80a22000                 cmp     %o0, 0
F00CF2D4: 02800006                 be      loc_F00CF2EC
F00CF2D8: 80a22001                 cmp     %o0, 1
F00CF2DC: 0280000b                 be      loc_F00CF308
F00CF2E0: d407bfb8                 ld      [%fp+var_48], %o2
F00CF2E4: 10800107                 ba      loc_F00CF700
F00CF2E8: d006a034                 ld      [%i2+0x34], %o0
F00CF2EC: d407bfb8                 ld      [%fp+var_48], %o2
F00CF2F0: c41fbfc0                 ldd     [%fp+var_40], %g2
F00CF2F4: 90100018                 mov     %i0, %o0
F00CF2F8: d81fbfc8                 ldd     [%fp+var_38], %o4
F00CF2FC: 133c0505                 sethi   %hi(paAddtobytesread), %o1
F00CF300: 10800007                 ba      loc_F00CF31C
F00CF304: d20263a8                 ld      [%o1+%lo(paAddtobytesread)], %o1
F00CF308: c41fbfc0                 ldd     [%fp+var_40], %g2
F00CF30C: 90100018                 mov     %i0, %o0! id
F00CF310: d81fbfc8                 ldd     [%fp+var_38], %o4
F00CF314: 133c0505                 sethi   %hi(paAddtobyteswrit), %o1
F00CF318: d20263a4                 ld      [%o1+%lo(paAddtobyteswrit)], %o1! SEL
F00CF31C: da23a05c                 st      %o5, [%sp+0xF8+var_9C]
F00CF320: 9a10000c                 mov     %o4, %o5
F00CF324: 96100002                 mov     %g2, %o3
F00CF328: 98100003                 mov     %g3, %o4
F00CF32C: 40008951                 call    _objc_msgSend
F00CF330: 01000000                 nop
F00CF334: 108000f3                 ba      loc_F00CF700
F00CF338: d006a034                 ld      [%i2+0x34], %o0
F00CF33C: 11100000                 sethi   0x40000000, %o0
F00CF340: 808a4008                 btst    %o0, %o1
F00CF344: 128000ee                 bne     loc_F00CF6FC
F00CF348: 80a46009                 cmp     %l1, 9
F00CF34C: 1880000c                 bgu     loc_F00CF37C
F00CF350: 80a46007                 cmp     %l1, 7
F00CF354: 1a800016                 bcc     loc_F00CF3AC
F00CF358: 80a46001                 cmp     %l1, 1
F00CF35C: 22800015                 be,a    loc_F00CF3B0
F00CF360: 90100011                 mov     %l1, %o0
F00CF364: 0a8000b5                 bcs     loc_F00CF638
F00CF368: 80a46003                 cmp     %l1, 3
F00CF36C: 388000b4                 bgu,a   loc_F00CF63C
F00CF370: d006a038                 ld      [%i2+0x38], %o0
F00CF374: 1080001a                 ba      loc_F00CF3DC
F00CF378: d40fbfb4                 ldub    [%fp+var_4C], %o2
F00CF37C: 80a46013                 cmp     %l1, 0x13
F00CF380: 18800008                 bgu     loc_F00CF3A0
F00CF384: 80a4600e                 cmp     %l1, 0xE
F00CF388: 1a800009                 bcc     loc_F00CF3AC
F00CF38C: 80a4600d                 cmp     %l1, 0xD
F00CF390: 02800013                 be      loc_F00CF3DC
F00CF394: d40fbfb4                 ldub    [%fp+var_4C], %o2
F00CF398: 108000a9                 ba      loc_F00CF63C
F00CF39C: d006a038                 ld      [%i2+0x38], %o0
F00CF3A0: 80a46064                 cmp     %l1, 0x64 ! 'd'
F00CF3A4: 328000a6                 bne,a   loc_F00CF63C
F00CF3A8: d006a038                 ld      [%i2+0x38], %o0
F00CF3AC: 90100011                 mov     %l1, %o0
F00CF3B0: 133c04bb                 sethi   %hi(_IOScStatusStrings), %o1
F00CF3B4: 7fffdb61                 call    _IOFindNameForValue
F00CF3B8: 92126100                 bset    %lo(_IOScStatusStrings), %o1
F00CF3BC: 133c03ed                 sethi   %hi(aSSFatalError), %o1! "%s: %s : FATAL ERROR\n"
F00CF3C0: 94100008                 mov     %o0, %o2
F00CF3C4: 90126078                 or      %o1, %lo(aSSFatalError), %o0! "%s: %s : FATAL ERROR\n"
F00CF3C8: 7fffdb4b                 call    _IOLog
F00CF3CC: 92100012                 mov     %l2, %o1
F00CF3D0: 90100018                 mov     %i0, %o0
F00CF3D4: 10800102                 ba      loc_F00CF7DC
F00CF3D8: d204e3ac                 ld      [%l3+0x3AC], %o1
F00CF3DC: 80a2a002                 cmp     %o2, 2
F00CF3E0: 0280000e                 be      loc_F00CF418
F00CF3E4: 80a2a008                 cmp     %o2, 8
F00CF3E8: 12800089                 bne     loc_F00CF60C
F00CF3EC: 113c03ed                 sethi   -0xFF04C00, %o0
F00CF3F0: d006a034                 ld      [%i2+0x34], %o0
F00CF3F4: 90023fff                 inc     -1, %o0
F00CF3F8: 80a22000                 cmp     %o0, 0
F00CF3FC: 048000f1                 ble     loc_F00CF7C0
F00CF400: d026a034                 st      %o0, [%i2+0x34]
F00CF404: 113c03ed901220b0         set     aSBusyStatusRet, %o0! "%s: BUSY STATUS; Retrying.\n"
F00CF40C: 7fffdb3a                 call    _IOLog
F00CF410: 92100012                 mov     %l2, %o1
F00CF414: 3080003f                 ba,a    loc_F00CF510
F00CF418: 80a46002                 cmp     %l1, 2
F00CF41C: 0280000e                 be      loc_F00CF454
F00CF420: 90100018                 mov     %i0, %o0! id
F00CF424: 133c0505                 sethi   %hi(paReqsense), %o1
F00CF428: d20263a0                 ld      [%o1+%lo(paReqsense)], %o1! SEL
F00CF42C: 40008911                 call    _objc_msgSend
F00CF430: 9407bf70                 add     %fp, var_90, %o2
F00CF434: a2920000                 orcc    %o0, %g0, %l1
F00CF438: 02800014                 be      loc_F00CF488
F00CF43C: 113c03ed                 sethi   %hi(aSRequestSenseE), %o0! "%s: REQUEST SENSE ERROR;  FATAL.\n"
F00CF440: 901220d0                 bset    %lo(aSRequestSenseE), %o0! "%s: REQUEST SENSE ERROR;  FATAL.\n"
F00CF444: 7fffdb2c                 call    _IOLog
F00CF448: 92100012                 mov     %l2, %o1
F00CF44C: 108000ad                 ba      loc_F00CF700
F00CF450: d006a034                 ld      [%i2+0x34], %o0
F00CF454: d01fbfd0                 ldd     [%fp+var_30], %o0
F00CF458: d027bf70                 st      %o0, [%fp+var_90]
F00CF45C: d007bfd8                 ld      [%fp+var_28], %o0
F00CF460: d227bf74                 st      %o1, [%fp+var_8C]
F00CF464: d207bfdc                 ld      [%fp+var_24], %o1
F00CF468: d027bf78                 st      %o0, [%fp+var_88]
F00CF46C: d007bfe0                 ld      [%fp+var_20], %o0
F00CF470: d227bf7c                 st      %o1, [%fp+var_84]
F00CF474: d207bfe4                 ld      [%fp+var_1C], %o1
F00CF478: d027bf80                 st      %o0, [%fp+var_80]
F00CF47C: d007bfe8                 ld      [%fp+var_18], %o0
F00CF480: d227bf84                 st      %o1, [%fp+var_7C]
F00CF484: d027bf88                 st      %o0, [%fp+var_78]
F00CF488: d007bf70                 ld      [%fp+var_90], %o0
F00CF48C: 91322008                 srl     %o0, 8, %o0
F00CF490: 920a200f                 and     %o0, 0xF, %o1
F00CF494: 80a26007                 cmp     %o1, 7! switch 8 cases
F00CF498: 3880004e                 bgu,a   def_F00CF4B0! jumptable F00CF4B0 default case
F00CF49C: 133c04bb                 sethi   -0xFED1400, %o1
F00CF4A0: 113c033d901220b8         set     jpt_F00CF4B0, %o0
F00CF4A8: 932a6002                 sll     %o1, 2, %o1
F00CF4AC: d0024008                 ld      [%o1+%o0], %o0
F00CF4B0: 81c20000                 jmp     %o0! switch jump
F00CF4B4: 01000000                 nop
F00CF4D8: d006a03c                 ld      [%i2+0x3C], %o0! jumptable F00CF4B0 case 2
F00CF4DC: 90023fff                 inc     -1, %o0
F00CF4E0: 80a22000                 cmp     %o0, 0
F00CF4E4: 048000b4                 ble     loc_F00CF7B4
F00CF4E8: d026a03c                 st      %o0, [%i2+0x3C]
F00CF4EC: 113c03ed90122110         set     aSNotReadyRetry, %o0! "%s: NOT READY; Retrying.\n"
F00CF4F4: 7fffdb00                 call    _IOLog
F00CF4F8: 92100012                 mov     %l2, %o1
F00CF4FC: 90100018                 mov     %i0, %o0! id
F00CF500: d204e3ac                 ld      [%l3+0x3AC], %o1! SEL
F00CF504: 9410001a                 mov     %i2, %o2
F00CF508: 400088da                 call    _objc_msgSend
F00CF50C: 9607bf70                 add     %fp, var_90, %o3
F00CF510: 7fffda9b                 call    _IOSleep
F00CF514: 901023e8                 mov     0x3E8, %o0
F00CF518: 1080005d                 ba      loc_F00CF68C
F00CF51C: d2062188                 ld      [%i0+0x188], %o1
F00CF520: d006a038                 ld      [%i2+0x38], %o0! jumptable F00CF4B0 cases 0,1,3,4
F00CF524: 90023fff                 inc     -1, %o0
F00CF528: 80a22000                 cmp     %o0, 0
F00CF52C: 04800091                 ble     loc_F00CF770
F00CF530: d026a038                 st      %o0, [%i2+0x38]
F00CF534: 133c04bb                 sethi   %hi(_IOSCSISenseStrings), %o1
F00CF538: d007bf70                 ld      [%fp+var_90], %o0
F00CF53C: 921261d0                 bset    %lo(_IOSCSISenseStrings), %o1
F00CF540: 91322008                 srl     %o0, 8, %o0
F00CF544: 7fffdafd                 call    _IOFindNameForValue
F00CF548: 900a200f                 and     %o0, 0xF, %o0
F00CF54C: 133c03ed                 sethi   %hi(aSSRetrying), %o1! "%s: %s; Retrying.\n"
F00CF550: 94100008                 mov     %o0, %o2
F00CF554: 90126140                 or      %o1, %lo(aSSRetrying), %o0! "%s: %s; Retrying.\n"
F00CF558: 7fffdae7                 call    _IOLog
F00CF55C: 92100012                 mov     %l2, %o1
F00CF560: 90100018                 mov     %i0, %o0
F00CF564: 9410001a                 mov     %i2, %o2
F00CF568: 10800045                 ba      loc_F00CF67C
F00CF56C: d204e3ac                 ld      [%l3+0x3AC], %o1
F00CF570: d006a038                 ld      [%i2+0x38], %o0! jumptable F00CF4B0 case 6
F00CF574: 90023fff                 inc     -1, %o0
F00CF578: 80a22000                 cmp     %o0, 0
F00CF57C: 0480007a                 ble     loc_F00CF764
F00CF580: d026a038                 st      %o0, [%i2+0x38]
F00CF584: 113c03ed90122178         set     aSUnitAttention_0, %o0! "%s: UNIT ATTENTION; Retrying.\n"
F00CF58C: 7fffdada                 call    _IOLog
F00CF590: 92100012                 mov     %l2, %o1
F00CF594: 10800038                 ba      loc_F00CF674
F00CF598: 90100018                 mov     %i0, %o0
F00CF59C: 113c03ed90122198         set     aSWriteProtecte, %o0! jumptable F00CF4B0 case 7
F00CF5A4: 7fffdad4                 call    _IOLog
F00CF5A8: 92100012                 mov     %l2, %o1
F00CF5AC: 90100018                 mov     %i0, %o0! id
F00CF5B0: d204e3ac                 ld      [%l3+0x3AC], %o1! SEL
F00CF5B4: 9410001a                 mov     %i2, %o2
F00CF5B8: 9607bf70                 add     %fp, var_90, %o3
F00CF5BC: 400088ad                 call    _objc_msgSend
F00CF5C0: a2102011                 mov     0x11, %l1
F00CF5C4: 1080004f                 ba      loc_F00CF700
F00CF5C8: d006a034                 ld      [%i2+0x34], %o0
F00CF5CC: 133c04bb                 sethi   -0xFED1400, %o1! jumptable F00CF4B0 case 5
F00CF5D0: 921261d0                 bset    0x1D0, %o1! jumptable F00CF4B0 default case
F00CF5D4: d007bf70                 ld      [%fp+var_90], %o0
F00CF5D8: a2102002                 mov     2, %l1
F00CF5DC: 91322008                 srl     %o0, 8, %o0
F00CF5E0: 7fffdad6                 call    _IOFindNameForValue
F00CF5E4: 900a200f                 and     %o0, 0xF, %o0
F00CF5E8: 133c03ed                 sethi   %hi(aSSFatal), %o1! "%s: %s; FATAL.\n"
F00CF5EC: 94100008                 mov     %o0, %o2
F00CF5F0: 90126130                 or      %o1, %lo(aSSFatal), %o0! "%s: %s; FATAL.\n"
F00CF5F4: 7fffdac0                 call    _IOLog
F00CF5F8: 92100012                 mov     %l2, %o1
F00CF5FC: 90100018                 mov     %i0, %o0
F00CF600: 9410001a                 mov     %i2, %o2
F00CF604: 10800077                 ba      loc_F00CF7E0
F00CF608: d204e3ac                 ld      [%l3+0x3AC], %o1
F00CF60C: 901221b8                 bset    0x1B8, %o0
F00CF610: 7fffdab9                 call    _IOLog
F00CF614: 92100012                 mov     %l2, %o1
F00CF618: 90100018                 mov     %i0, %o0! id
F00CF61C: d204e3ac                 ld      [%l3+0x3AC], %o1! SEL
F00CF620: 9410001a                 mov     %i2, %o2
F00CF624: 9607bf70                 add     %fp, var_90, %o3
F00CF628: 40008892                 call    _objc_msgSend
F00CF62C: a210200d                 mov     0xD, %l1
F00CF630: 10800034                 ba      loc_F00CF700
F00CF634: d006a034                 ld      [%i2+0x34], %o0
F00CF638: d006a038                 ld      [%i2+0x38], %o0
F00CF63C: 90023fff                 inc     -1, %o0
F00CF640: 80a22000                 cmp     %o0, 0
F00CF644: 0480003c                 ble     loc_F00CF734
F00CF648: d026a038                 st      %o0, [%i2+0x38]
F00CF64C: 90100011                 mov     %l1, %o0
F00CF650: 133c04bb                 sethi   %hi(_IOScStatusStrings), %o1
F00CF654: 7fffdab9                 call    _IOFindNameForValue
F00CF658: 92126100                 bset    %lo(_IOScStatusStrings), %o1
F00CF65C: 133c03ed                 sethi   %hi(aSSRetrying), %o1! "%s: %s; Retrying.\n"
F00CF660: 94100008                 mov     %o0, %o2
F00CF664: 90126140                 or      %o1, %lo(aSSRetrying), %o0! "%s: %s; Retrying.\n"
F00CF668: 7fffdaa3                 call    _IOLog
F00CF66C: 92100012                 mov     %l2, %o1
F00CF670: 90100018                 mov     %i0, %o0! id
F00CF674: d204e3ac                 ld      [%l3+0x3AC], %o1! SEL
F00CF678: 9410001a                 mov     %i2, %o2
F00CF67C: 9607bf70                 add     %fp, var_90, %o3
F00CF680: 4000887c                 call    _objc_msgSend
F00CF684: 01000000                 nop
F00CF688: d2062188                 ld      [%i0+0x188], %o1
F00CF68C: 11000010                 sethi   0x4000, %o0
F00CF690: 808a4008                 btst    %o0, %o1
F00CF694: 22800013                 be,a    loc_F00CF6E0
F00CF698: d006a034                 ld      [%i2+0x34], %o0
F00CF69C: d0068000                 ld      [%i2], %o0
F00CF6A0: 80a22000                 cmp     %o0, 0
F00CF6A4: 02800006                 be      loc_F00CF6BC
F00CF6A8: 80a22001                 cmp     %o0, 1
F00CF6AC: 22800007                 be,a    loc_F00CF6C8
F00CF6B0: 113c0505                 sethi   -0xFEBEC00, %o0
F00CF6B4: 10800007                 ba      loc_F00CF6D0
F00CF6B8: 113c0505                 sethi   -0xFEBEC00, %o0
F00CF6BC: 113c0505                 sethi   %hi(paIncrementreadr), %o0! id
F00CF6C0: 10800005                 ba      loc_F00CF6D4
F00CF6C4: d202239c                 ld      [%o0+%lo(paIncrementreadr)], %o1
F00CF6C8: 10800003                 ba      loc_F00CF6D4
F00CF6CC: d2022398                 ld      [%o0+0x398], %o1
F00CF6D0: d2022394                 ld      [%o0+0x394], %o1! SEL
F00CF6D4: 40008867                 call    _objc_msgSend
F00CF6D8: 90100018                 mov     %i0, %o0
F00CF6DC: d006a034                 ld      [%i2+0x34], %o0
F00CF6E0: 80a22000                 cmp     %o0, 0
F00CF6E4: 22800007                 be,a    loc_F00CF700
F00CF6E8: d006a034                 ld      [%i2+0x34], %o0
F00CF6EC: d006a038                 ld      [%i2+0x38], %o0
F00CF6F0: 80a22000                 cmp     %o0, 0
F00CF6F4: 32bffeb7                 bne,a   loc_F00CF1D0
F00CF6F8: d006a03c                 ld      [%i2+0x3C], %o0
F00CF6FC: d006a034                 ld      [%i2+0x34], %o0
F00CF700: 80a22000                 cmp     %o0, 0
F00CF704: 02800051                 be      loc_F00CF848
F00CF708: a0103d36                 mov     -0x2CA, %l0
F00CF70C: d006a038                 ld      [%i2+0x38], %o0
F00CF710: 80a22000                 cmp     %o0, 0
F00CF714: 0280004e                 be      loc_F00CF84C
F00CF718: 80a42000                 cmp     %l0, 0
F00CF71C: d006a03c                 ld      [%i2+0x3C], %o0
F00CF720: 80a22000                 cmp     %o0, 0
F00CF724: 12800040                 bne     loc_F00CF824
F00CF728: 80a46000                 cmp     %l1, 0
F00CF72C: 10800048                 ba      loc_F00CF84C
F00CF730: 80a42000                 cmp     %l0, 0
F00CF734: 90100011                 mov     %l1, %o0
F00CF738: 133c04bb92126100         set     _IOScStatusStrings, %o1
F00CF740: 213c03ed                 sethi   %hi(aSSFatal), %l0! "%s: %s; FATAL.\n"
F00CF744: 7fffda7d                 call    _IOFindNameForValue
F00CF748: a0142130                 bset    %lo(aSSFatal), %l0! "%s: %s; FATAL.\n"
F00CF74C: 94100008                 mov     %o0, %o2
F00CF750: 90100010                 mov     %l0, %o0
F00CF754: 7fffda68                 call    _IOLog
F00CF758: 92100012                 mov     %l2, %o1
F00CF75C: 1080001e                 ba      loc_F00CF7D4
F00CF760: 90100018                 mov     %i0, %o0
F00CF764: 113c03ed                 sethi   %hi(aSUnitAttention), %o0! "%s: UNIT ATTENTION; FATAL.\n"
F00CF768: 10800018                 ba      loc_F00CF7C8
F00CF76C: 90122158                 bset    %lo(aSUnitAttention), %o0! "%s: UNIT ATTENTION; FATAL.\n"
F00CF770: 133c04bb921261d0         set     _IOSCSISenseStrings, %o1
F00CF778: 213c03ed                 sethi   %hi(aSSFatal), %l0! "%s: %s; FATAL.\n"
F00CF77C: d007bf70                 ld      [%fp+var_90], %o0
F00CF780: a0142130                 bset    %lo(aSSFatal), %l0! "%s: %s; FATAL.\n"
F00CF784: 91322008                 srl     %o0, 8, %o0
F00CF788: 7fffda6c                 call    _IOFindNameForValue
F00CF78C: 900a200f                 and     %o0, 0xF, %o0
F00CF790: 94100008                 mov     %o0, %o2
F00CF794: 90100010                 mov     %l0, %o0
F00CF798: 7fffda57                 call    _IOLog
F00CF79C: 92100012                 mov     %l2, %o1
F00CF7A0: 90100018                 mov     %i0, %o0
F00CF7A4: 9410001a                 mov     %i2, %o2
F00CF7A8: 133c0505                 sethi   %hi(paLogopinfoSense), %o1
F00CF7AC: 1080000d                 ba      loc_F00CF7E0
F00CF7B0: d20263ac                 ld      [%o1+%lo(paLogopinfoSense)], %o1
F00CF7B4: 113c03ed                 sethi   %hi(aSNotReadyFatal), %o0! "%s: NOT READY; FATAL.\n"
F00CF7B8: 10800004                 ba      loc_F00CF7C8
F00CF7BC: 901220f8                 bset    %lo(aSNotReadyFatal), %o0! "%s: NOT READY; FATAL.\n"
F00CF7C0: 113c03ed90122090         set     aSBusyStatusFat, %o0! "%s: BUSY STATUS; FATAL.\n"
F00CF7C8: 7fffda4b                 call    _IOLog
F00CF7CC: 92100012                 mov     %l2, %o1
F00CF7D0: 90100018                 mov     %i0, %o0! id
F00CF7D4: 133c0505                 sethi   %hi(paLogopinfoSense), %o1
F00CF7D8: d20263ac                 ld      [%o1+%lo(paLogopinfoSense)], %o1! SEL
F00CF7DC: 9410001a                 mov     %i2, %o2
F00CF7E0: 40008824                 call    _objc_msgSend
F00CF7E4: 9607bf70                 add     %fp, var_90, %o3
F00CF7E8: 10bfffc6                 ba      loc_F00CF700
F00CF7EC: d006a034                 ld      [%i2+0x34], %o0
F00CF7F0: 113c03ed90122008         set     aSTransferCount, %o0! "%s: TRANSFER COUNT ERROR;  FATAL.\n"
F00CF7F8: 7fffda3f                 call    _IOLog
F00CF7FC: 92100012                 mov     %l2, %o1
F00CF800: 90100018                 mov     %i0, %o0! id
F00CF804: 133c0505                 sethi   %hi(paLogopinfoSense), %o1
F00CF808: d20263ac                 ld      [%o1+%lo(paLogopinfoSense)], %o1! SEL
F00CF80C: 9410001a                 mov     %i2, %o2
F00CF810: 9607bf70                 add     %fp, var_90, %o3
F00CF814: 40008817                 call    _objc_msgSend
F00CF818: a210200f                 mov     0xF, %l1
F00CF81C: 10bfffb9                 ba      loc_F00CF700
F00CF820: d006a034                 ld      [%i2+0x34], %o0
F00CF824: 02800008                 be      loc_F00CF844
F00CF828: 133c0505                 sethi   %hi(paReturnfromscst), %o1
F00CF82C: d0062184                 ld      [%i0+0x184], %o0! id
F00CF830: d2026390                 ld      [%o1+%lo(paReturnfromscst)], %o1! SEL
F00CF834: 4000880f                 call    _objc_msgSend
F00CF838: 94100011                 mov     %l1, %o2
F00CF83C: 10800003                 ba      loc_F00CF848
F00CF840: a0100008                 mov     %o0, %l0
F00CF844: a0102000                 mov     0, %l0
F00CF848: 80a42000                 cmp     %l0, 0
F00CF84C: 2280001d                 be,a    loc_F00CF8C0
F00CF850: d206a014                 ld      [%i2+0x14], %o1
F00CF854: d2062188                 ld      [%i0+0x188], %o1
F00CF858: 11000010                 sethi   0x4000, %o0
F00CF85C: 808a4008                 btst    %o0, %o1
F00CF860: 22800018                 be,a    loc_F00CF8C0
F00CF864: d206a014                 ld      [%i2+0x14], %o1
F00CF868: d0068000                 ld      [%i2], %o0
F00CF86C: 80a22000                 cmp     %o0, 0
F00CF870: 02800006                 be      loc_F00CF888
F00CF874: 80a22001                 cmp     %o0, 1
F00CF878: 02800007                 be      loc_F00CF894
F00CF87C: 113c0505                 sethi   -0xFEBEC00, %o0
F00CF880: 10800007                 ba      loc_F00CF89C
F00CF884: d206a020                 ld      [%i2+0x20], %o1
F00CF888: 113c0505                 sethi   %hi(paIncrementreade), %o0
F00CF88C: 1080000a                 ba      loc_F00CF8B4
F00CF890: d202238c                 ld      [%o0+%lo(paIncrementreade)], %o1
F00CF894: 10800008                 ba      loc_F00CF8B4
F00CF898: d2022388                 ld      [%o0+0x388], %o1
F00CF89C: 11100000                 sethi   0x40000000, %o0
F00CF8A0: 808a4008                 btst    %o0, %o1
F00CF8A4: 32800007                 bne,a   loc_F00CF8C0
F00CF8A8: d206a014                 ld      [%i2+0x14], %o1
F00CF8AC: 113c0505                 sethi   %hi(paIncrementother), %o0! id
F00CF8B0: d2022384                 ld      [%o0+%lo(paIncrementother)], %o1! SEL
F00CF8B4: 400087ef                 call    _objc_msgSend
F00CF8B8: 90100018                 mov     %i0, %o0
F00CF8BC: d206a014                 ld      [%i2+0x14], %o1
F00CF8C0: 80a26000                 cmp     %o1, 0
F00CF8C4: 02800009                 be      loc_F00CF8E8
F00CF8C8: d007bfb0                 ld      [%fp+var_50], %o0
F00CF8CC: d0226020                 st      %o0, [%o1+0x20]
F00CF8D0: d206a014                 ld      [%i2+0x14], %o1
F00CF8D4: d00fbfb4                 ldub    [%fp+var_4C], %o0
F00CF8D8: d02a6024                 stb     %o0, [%o1+0x24]
F00CF8DC: d206a014                 ld      [%i2+0x14], %o1
F00CF8E0: d007bfb8                 ld      [%fp+var_48], %o0
F00CF8E4: d0226028                 st      %o0, [%o1+0x28]
F00CF8E8: 90100018                 mov     %i0, %o0! id
F00CF8EC: 9410001a                 mov     %i2, %o2
F00CF8F0: d607bfb8                 ld      [%fp+var_48], %o3
F00CF8F4: 133c0505                 sethi   %hi(paSdiocomplete), %o1
F00CF8F8: d2026380                 ld      [%o1+%lo(paSdiocomplete)], %o1! SEL
F00CF8FC: d622a024                 st      %o3, [%o2+0x24]
F00CF900: 400087dc                 call    _objc_msgSend
F00CF904: e022a028                 st      %l0, [%o2+0x28]
F00CF908: 81c7e008                 ret
F00CF90C: 81e80000                 restore
