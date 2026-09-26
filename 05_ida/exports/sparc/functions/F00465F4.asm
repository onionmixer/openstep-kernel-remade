F00465F4: 9de3bf98                 save    %sp, -0x68, %sp
F00465F8: f027a044                 st      %i0, [%fp+arg_44]
F00465FC: f227a048                 st      %i1, [%fp+arg_48]
F0046600: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0046604: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F0046608: f427a04c                 st      %i2, [%fp+arg_4C]
F004660C: 400141d2                 call    _setjmp
F0046610: 90022028                 inc     0x28, %o0 ! '('
F0046614: 80a22000                 cmp     %o0, 0
F0046618: 0280000a                 be      loc_F0046640
F004661C: d007a044                 ld      [%fp+arg_44], %o0
F0046620: d207a048                 ld      [%fp+arg_48], %o1
F0046624: d607a04c                 ld      [%fp+arg_4C], %o3
F0046628: 94102001                 mov     1, %o2
F004662C: d0020000                 ld      [%o0], %o0
F0046630: 4000004a                 call    sub_F0046758
F0046634: 920a604b                 and     %o1, 0x4B, %o1
F0046638: 10800046                 ba      locret_F0046750
F004663C: b0102004                 mov     4, %i0
F0046640: d207a048                 ld      [%fp+arg_48], %o1
F0046644: d0020000                 ld      [%o0], %o0
F0046648: 808a6001                 btst    1, %o1
F004664C: 0280000c                 be      loc_F004667C
F0046650: f0022030                 ld      [%o0+0x30], %i0
F0046654: d0162082                 lduh    [%i0+0x82], %o0
F0046658: 90022001                 inc     %o0
F004665C: d0362082                 sth     %o0, [%i0+0x82]
F0046660: 912a2010                 sll     %o0, 16, %o0
F0046664: 913a2010                 sra     %o0, 16, %o0
F0046668: 80a22001                 cmp     %o0, 1
F004666C: 12800005                 bne     loc_F0046680
F0046670: d007a048                 ld      [%fp+arg_48], %o0
F0046674: 7fff31dd                 call    _wakeup
F0046678: 90062082                 add     %i0, 0x82, %o0
F004667C: d007a048                 ld      [%fp+arg_48], %o0
F0046680: 808a2002                 btst    2, %o0
F0046684: 02800013                 be      loc_F00466D0
F0046688: 808a2004                 btst    4, %o0
F004668C: 22800008                 be,a    loc_F00466AC
F0046690: d0162080                 lduh    [%i0+0x80], %o0
F0046694: d0562082                 ldsh    [%i0+0x82], %o0
F0046698: 80a22000                 cmp     %o0, 0
F004669C: 32800004                 bne,a   loc_F00466AC
F00466A0: d0162080                 lduh    [%i0+0x80], %o0
F00466A4: 1080002b                 ba      locret_F0046750
F00466A8: b0102006                 mov     6, %i0
F00466AC: 90022001                 inc     %o0
F00466B0: d0362080                 sth     %o0, [%i0+0x80]
F00466B4: 912a2010                 sll     %o0, 16, %o0
F00466B8: 913a2010                 sra     %o0, 16, %o0
F00466BC: 80a22001                 cmp     %o0, 1
F00466C0: 12800005                 bne     loc_F00466D4
F00466C4: d007a048                 ld      [%fp+arg_48], %o0
F00466C8: 7fff31c8                 call    _wakeup
F00466CC: 90062080                 add     %i0, 0x80, %o0
F00466D0: d007a048                 ld      [%fp+arg_48], %o0
F00466D4: 808a2001                 btst    1, %o0
F00466D8: 02800012                 be      loc_F0046720
F00466DC: d007a048                 ld      [%fp+arg_48], %o0
F00466E0: 1080000d                 ba      loc_F0046714
F00466E4: d0562080                 ldsh    [%i0+0x80], %o0
F00466E8: 808a2004                 btst    4, %o0
F00466EC: 32800019                 bne,a   locret_F0046750
F00466F0: b0102000                 mov     0, %i0
F00466F4: d006207c                 ld      [%i0+0x7C], %o0
F00466F8: 80a22000                 cmp     %o0, 0
F00466FC: 32800015                 bne,a   locret_F0046750
F0046700: b0102000                 mov     0, %i0
F0046704: 90062080                 add     %i0, 0x80, %o0! unsigned int
F0046708: 7fff2fdc                 call    _sleep
F004670C: 9210201a                 mov     0x1A, %o1
F0046710: d0562080                 ldsh    [%i0+0x80], %o0
F0046714: 80a22000                 cmp     %o0, 0
F0046718: 02bffff4                 be      loc_F00466E8
F004671C: d007a048                 ld      [%fp+arg_48], %o0
F0046720: 808a2002                 btst    2, %o0
F0046724: 2280000b                 be,a    locret_F0046750
F0046728: b0102000                 mov     0, %i0
F004672C: 10800005                 ba      loc_F0046740
F0046730: d0562082                 ldsh    [%i0+0x82], %o0! unsigned int
F0046734: 7fff2fd1                 call    _sleep
F0046738: 9210201a                 mov     0x1A, %o1
F004673C: d0562082                 ldsh    [%i0+0x82], %o0
F0046740: 80a22000                 cmp     %o0, 0
F0046744: 02bffffc                 be      loc_F0046734
F0046748: 90062082                 add     %i0, 0x82, %o0
F004674C: b0102000                 mov     0, %i0
F0046750: 81c7e008                 ret
F0046754: 81e80000                 restore
