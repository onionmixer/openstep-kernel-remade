F00DB224: 9de3bf88                 save    %sp, -0x78, %sp
F00DB228: c027bfec                 clr     [%fp+var_14]
F00DB22C: d0062028                 ld      [%i0+0x28], %o0! id
F00DB230: 133c0504                 sethi   %hi(paLock), %o1
F00DB234: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00DB238: 4000598e                 call    _objc_msgSend
F00DB23C: a6102000                 mov     0, %l3
F00DB240: d406202c                 ld      [%i0+0x2C], %o2
F00DB244: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00DB248: 80a2000a                 cmp     %o0, %o2
F00DB24C: 22800067                 be,a    loc_F00DB3E8
F00DB250: d0062028                 ld      [%i0+0x28], %o0
F00DB254: a010000a                 mov     %o2, %l0
F00DB258: 293c0505                 sethi   -0xFEBEC00, %l4
F00DB25C: a2100008                 mov     %o0, %l1
F00DB260: d0042020                 ld      [%l0+0x20], %o0
F00DB264: 80a2001a                 cmp     %o0, %i2
F00DB268: 1280000c                 bne     loc_F00DB298
F00DB26C: 90100018                 mov     %i0, %o0
F00DB270: d0042018                 ld      [%l0+0x18], %o0
F00DB274: 808a2001                 btst    1, %o0
F00DB278: 02800006                 be      loc_F00DB290
F00DB27C: 90100018                 mov     %i0, %o0! id
F00DB280: d2052074                 ld      [%l4+0x74], %o1! SEL
F00DB284: 94102000                 mov     0, %o2
F00DB288: 4000597a                 call    _objc_msgSend
F00DB28C: 96100010                 mov     %l0, %o3
F00DB290: c0242020                 clr     [%l0+0x20]
F00DB294: 90100018                 mov     %i0, %o0! id
F00DB298: 94100010                 mov     %l0, %o2
F00DB29C: 9610001a                 mov     %i2, %o3
F00DB2A0: 133c0505                 sethi   %hi(paCompleteregion), %o1
F00DB2A4: 9810001b                 mov     %i3, %o4
F00DB2A8: d2026070                 ld      [%o1+%lo(paCompleteregion)], %o1! SEL
F00DB2AC: 40005971                 call    _objc_msgSend
F00DB2B0: 9a07bfec                 add     %fp, var_14, %o5
F00DB2B4: d0042024                 ld      [%l0+0x24], %o0
F00DB2B8: 80a2001a                 cmp     %o0, %i2
F00DB2BC: 0280000a                 be      loc_F00DB2E4
F00DB2C0: d0042034                 ld      [%l0+0x34], %o0
F00DB2C4: 80a22000                 cmp     %o0, 0
F00DB2C8: 12800008                 bne     loc_F00DB2E8
F00DB2CC: 01000000                 nop
F00DB2D0: d0042030                 ld      [%l0+0x30], %o0
F00DB2D4: 80a22000                 cmp     %o0, 0
F00DB2D8: 0280003c                 be      loc_F00DB3C8
F00DB2DC: d007bfec                 ld      [%fp+var_14], %o0
F00DB2E0: d0042034                 ld      [%l0+0x34], %o0
F00DB2E4: 80a22000                 cmp     %o0, 0
F00DB2E8: 22800013                 be,a    loc_F00DB334
F00DB2EC: d0042034                 ld      [%l0+0x34], %o0
F00DB2F0: d0042018                 ld      [%l0+0x18], %o0
F00DB2F4: 808a2010                 btst    0x10, %o0
F00DB2F8: 0280000e                 be      loc_F00DB330
F00DB2FC: 80a4e000                 cmp     %l3, 0
F00DB300: 02800007                 be      loc_F00DB31C
F00DB304: 90100018                 mov     %i0, %o0
F00DB308: d006201c                 ld      [%i0+0x1C], %o0
F00DB30C: 80a22001                 cmp     %o0, 1
F00DB310: 32800009                 bne,a   loc_F00DB334
F00DB314: d0042034                 ld      [%l0+0x34], %o0
F00DB318: 90100018                 mov     %i0, %o0! id
F00DB31C: d2052074                 ld      [%l4+0x74], %o1! SEL
F00DB320: 94102004                 mov     4, %o2
F00DB324: 96100010                 mov     %l0, %o3
F00DB328: 40005952                 call    _objc_msgSend
F00DB32C: a6102001                 mov     1, %l3
F00DB330: d0042034                 ld      [%l0+0x34], %o0
F00DB334: 80a22000                 cmp     %o0, 0
F00DB338: 1280000f                 bne     loc_F00DB374
F00DB33C: a404203c                 add     %l0, 0x3C, %l2 ! '<'
F00DB340: d0042030                 ld      [%l0+0x30], %o0
F00DB344: 80a22000                 cmp     %o0, 0
F00DB348: 3280000c                 bne,a   loc_F00DB378
F00DB34C: d404203c                 ld      [%l0+0x3C], %o2
F00DB350: d0042018                 ld      [%l0+0x18], %o0
F00DB354: 808a2002                 btst    2, %o0
F00DB358: 02800007                 be      loc_F00DB374
F00DB35C: 90100018                 mov     %i0, %o0! id
F00DB360: d2052074                 ld      [%l4+0x74], %o1! SEL
F00DB364: 94102001                 mov     1, %o2
F00DB368: 40005942                 call    _objc_msgSend
F00DB36C: 96100010                 mov     %l0, %o3
F00DB370: a404203c                 add     %l0, 0x3C, %l2 ! '<'
F00DB374: d404203c                 ld      [%l0+0x3C], %o2
F00DB378: 80a4400a                 cmp     %l1, %o2
F00DB37C: 12800004                 bne     loc_F00DB38C
F00DB380: d2042040                 ld      [%l0+0x40], %o1
F00DB384: 10800003                 ba      loc_F00DB390
F00DB388: 90100011                 mov     %l1, %o0
F00DB38C: 9002a03c                 add     %o2, 0x3C, %o0 ! '<'
F00DB390: 80a44009                 cmp     %l1, %o1
F00DB394: 12800004                 bne     loc_F00DB3A4
F00DB398: d2222004                 st      %o1, [%o0+4]
F00DB39C: 10800003                 ba      loc_F00DB3A8
F00DB3A0: 90100011                 mov     %l1, %o0
F00DB3A4: 9002603c                 add     %o1, 0x3C, %o0 ! '<'
F00DB3A8: d4220000                 st      %o2, [%o0]
F00DB3AC: 133c0505                 sethi   %hi(paFreeregion), %o1
F00DB3B0: 90100018                 mov     %i0, %o0! id
F00DB3B4: d202606c                 ld      [%o1+%lo(paFreeregion)], %o1! SEL
F00DB3B8: 4000592e                 call    _objc_msgSend
F00DB3BC: 94100010                 mov     %l0, %o2
F00DB3C0: 10800006                 ba      loc_F00DB3D8
F00DB3C4: e0048000                 ld      [%l2], %l0
F00DB3C8: 80a2001b                 cmp     %o0, %i3
F00DB3CC: 3a800007                 bcc,a   loc_F00DB3E8
F00DB3D0: d0062028                 ld      [%i0+0x28], %o0
F00DB3D4: e004203c                 ld      [%l0+0x3C], %l0
F00DB3D8: 80a44010                 cmp     %l1, %l0
F00DB3DC: 32bfffa2                 bne,a   loc_F00DB264
F00DB3E0: d0042020                 ld      [%l0+0x20], %o0
F00DB3E4: d0062028                 ld      [%i0+0x28], %o0! id
F00DB3E8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DB3EC: 40005921                 call    _objc_msgSend
F00DB3F0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DB3F4: 81c7e008                 ret
F00DB3F8: 81e80000                 restore
