F00DB460: 9de3bf80                 save    %sp, -0x80, %sp
F00DB464: e607a05c                 ld      [%fp+arg_5C], %l3
F00DB468: d04e2024                 ldsb    [%i0+0x24], %o0
F00DB46C: e407a064                 ld      [%fp+arg_64], %l2
F00DB470: a2102000                 mov     0, %l1
F00DB474: e807a060                 ld      [%fp+arg_60], %l4
F00DB478: 80a22000                 cmp     %o0, 0
F00DB47C: 02800004                 be      loc_F00DB48C
F00DB480: ac100012                 mov     %l2, %l6
F00DB484: 1080007a                 ba      locret_F00DB66C
F00DB488: b0102000                 mov     0, %i0
F00DB48C: d0062028                 ld      [%i0+0x28], %o0! id
F00DB490: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DB494: 400058f7                 call    _objc_msgSend
F00DB498: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DB49C: d406202c                 ld      [%i0+0x2C], %o2
F00DB4A0: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00DB4A4: 80a2000a                 cmp     %o0, %o2
F00DB4A8: 12800008                 bne     loc_F00DB4C8
F00DB4AC: a010000a                 mov     %o2, %l0
F00DB4B0: d0062028                 ld      [%i0+0x28], %o0! id
F00DB4B4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DB4B8: 400058ee                 call    _objc_msgSend
F00DB4BC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DB4C0: 1080006b                 ba      locret_F00DB66C
F00DB4C4: b0102000                 mov     0, %i0
F00DB4C8: 912ca018                 sll     %l2, 24, %o0
F00DB4CC: ab3a2018                 sra     %o0, 24, %l5
F00DB4D0: a4102001                 mov     1, %l2
F00DB4D4: d2042008                 ld      [%l0+8], %o1
F00DB4D8: d0042004                 ld      [%l0+4], %o0
F00DB4DC: 80a24008                 cmp     %o1, %o0
F00DB4E0: 3a80004e                 bcc,a   loc_F00DB618
F00DB4E4: e004203c                 ld      [%l0+0x3C], %l0
F00DB4E8: d0042034                 ld      [%l0+0x34], %o0
F00DB4EC: 80a22000                 cmp     %o0, 0
F00DB4F0: 3280004a                 bne,a   loc_F00DB618
F00DB4F4: e004203c                 ld      [%l0+0x3C], %l0
F00DB4F8: d0070000                 ld      [%i4], %o0
F00DB4FC: 80a22000                 cmp     %o0, 0
F00DB500: 32800005                 bne,a   loc_F00DB514
F00DB504: d0074000                 ld      [%i5], %o0
F00DB508: d0062064                 ld      [%i0+0x64], %o0
F00DB50C: d0270000                 st      %o0, [%i4]
F00DB510: d0074000                 ld      [%i5], %o0
F00DB514: 80a23fff                 cmp     %o0, -1
F00DB518: 32800005                 bne,a   loc_F00DB52C
F00DB51C: d004c000                 ld      [%l3], %o0
F00DB520: d0062068                 ld      [%i0+0x68], %o0
F00DB524: d0274000                 st      %o0, [%i5]
F00DB528: d004c000                 ld      [%l3], %o0
F00DB52C: 80a22000                 cmp     %o0, 0
F00DB530: 32800005                 bne,a   loc_F00DB544
F00DB534: 113c0505                 sethi   -0xFEBEC00, %o0
F00DB538: d006206c                 ld      [%i0+0x6C], %o0
F00DB53C: d024c000                 st      %o0, [%l3]
F00DB540: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DB544: d2022068                 ld      [%o0+0x68], %o1! SEL
F00DB548: d6070000                 ld      [%i4], %o3
F00DB54C: d8074000                 ld      [%i5], %o4
F00DB550: 94100010                 mov     %l0, %o2
F00DB554: da04c000                 ld      [%l3], %o5
F00DB558: 400058c6                 call    _objc_msgSend
F00DB55C: 90100018                 mov     %i0, %o0
F00DB560: 912a2018                 sll     %o0, 24, %o0
F00DB564: 80a22000                 cmp     %o0, 0
F00DB568: 2280002c                 be,a    loc_F00DB618
F00DB56C: e004203c                 ld      [%l0+0x3C], %l0
F00DB570: d0062068                 ld      [%i0+0x68], %o0
F00DB574: 80a22000                 cmp     %o0, 0
F00DB578: 12800005                 bne     loc_F00DB58C
F00DB57C: 98068011                 add     %i2, %l1, %o4
F00DB580: 808b2001                 btst    1, %o4
F00DB584: 32800002                 bne,a   loc_F00DB58C
F00DB588: 980b3ffe                 and     %o4, -2, %o4
F00DB58C: ea23a05c                 st      %l5, [%sp+0x80+var_24]
F00DB590: 90100018                 mov     %i0, %o0! id
F00DB594: 94100010                 mov     %l0, %o2
F00DB598: d2070000                 ld      [%i4], %o1
F00DB59C: 96100014                 mov     %l4, %o3
F00DB5A0: d223a060                 st      %o1, [%sp+0x80+var_20]
F00DB5A4: d2074000                 ld      [%i5], %o1
F00DB5A8: 9a26c011                 sub     %i3, %l1, %o5
F00DB5AC: d223a064                 st      %o1, [%sp+0x80+var_1C]
F00DB5B0: c404c000                 ld      [%l3], %g2
F00DB5B4: 133c0505                 sethi   %hi(paMixregionDescr), %o1
F00DB5B8: d2026064                 ld      [%o1+%lo(paMixregionDescr)], %o1! SEL
F00DB5BC: 400058ad                 call    _objc_msgSend
F00DB5C0: c423a068                 st      %g2, [%sp+0x80+var_18]
F00DB5C4: d2042028                 ld      [%l0+0x28], %o1
F00DB5C8: 80a26000                 cmp     %o1, 0
F00DB5CC: 12800004                 bne     loc_F00DB5DC
F00DB5D0: 94100008                 mov     %o0, %o2
F00DB5D4: e8242020                 st      %l4, [%l0+0x20]
F00DB5D8: e4242028                 st      %l2, [%l0+0x28]
F00DB5DC: d2042008                 ld      [%l0+8], %o1
F00DB5E0: d0042004                 ld      [%l0+4], %o0
F00DB5E4: 80a24008                 cmp     %o1, %o0
F00DB5E8: 0a800008                 bcs     loc_F00DB608
F00DB5EC: a204400a                 add     %l1, %o2, %l1
F00DB5F0: d004202c                 ld      [%l0+0x2C], %o0
F00DB5F4: 80a22000                 cmp     %o0, 0
F00DB5F8: 12800004                 bne     loc_F00DB608
F00DB5FC: 01000000                 nop
F00DB600: e8242024                 st      %l4, [%l0+0x24]
F00DB604: e424202c                 st      %l2, [%l0+0x2C]
F00DB608: 80a4401b                 cmp     %l1, %i3
F00DB60C: 3a800008                 bcc,a   loc_F00DB62C
F00DB610: d0062028                 ld      [%i0+0x28], %o0
F00DB614: e004203c                 ld      [%l0+0x3C], %l0
F00DB618: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00DB61C: 80a20010                 cmp     %o0, %l0
F00DB620: 32bfffae                 bne,a   loc_F00DB4D8
F00DB624: d2042008                 ld      [%l0+8], %o1
F00DB628: d0062028                 ld      [%i0+0x28], %o0! id
F00DB62C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DB630: 40005890                 call    _objc_msgSend
F00DB634: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DB638: 912da018                 sll     %l6, 24, %o0
F00DB63C: 80a22000                 cmp     %o0, 0
F00DB640: 0280000a                 be      loc_F00DB668
F00DB644: 80a4401b                 cmp     %l1, %i3
F00DB648: 1a800008                 bcc     loc_F00DB668
F00DB64C: 90100018                 mov     %i0, %o0! id
F00DB650: 133c0505                 sethi   %hi(paClearformixSiz), %o1
F00DB654: d2026060                 ld      [%o1+%lo(paClearformixSiz)], %o1! SEL
F00DB658: 94068011                 add     %i2, %l1, %o2
F00DB65C: d8074000                 ld      [%i5], %o4
F00DB660: 40005884                 call    _objc_msgSend
F00DB664: 9626c011                 sub     %i3, %l1, %o3
F00DB668: b0100011                 mov     %l1, %i0
F00DB66C: 81c7e008                 ret
F00DB670: 81e80000                 restore
