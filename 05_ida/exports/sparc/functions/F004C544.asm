F004C544: 9de3bf98                 save    %sp, -0x68, %sp
F004C548: 80a6a000                 cmp     %i2, 0
F004C54C: 12800005                 bne     loc_F004C560
F004C550: a6102000                 mov     0, %l3
F004C554: 113c043a                 sethi   %hi(aDirmakeinodeNo), %o0! "dirmakeinode: no attributes"
F004C558: 7fff2306                 call    _panic
F004C55C: 901222d0                 bset    %lo(aDirmakeinodeNo), %o0! "dirmakeinode: no attributes"
F004C560: e4068000                 ld      [%i2], %l2
F004C564: 80a4a002                 cmp     %l2, 2
F004C568: 32800005                 bne,a   loc_F004C57C
F004C56C: d8062048                 ld      [%i0+0x48], %o4
F004C570: 7ffff2c8                 call    _dirpref
F004C574: d0062050                 ld      [%i0+0x50], %o0
F004C578: 98100008                 mov     %o0, %o4
F004C57C: 133c043a921263dc         set     _vttoif_tab, %o1
F004C584: 952ca002                 sll     %l2, 2, %o2
F004C588: d4028009                 ld      [%o2+%o1], %o2
F004C58C: 90100018                 mov     %i0, %o0
F004C590: d616a004                 lduh    [%i2+4], %o3
F004C594: 9210000c                 mov     %o4, %o1
F004C598: a212800b                 or      %o2, %o3, %l1
F004C59C: 7ffff26f                 call    _ialloc
F004C5A0: 94100011                 mov     %l1, %o2
F004C5A4: a0920000                 orcc    %o0, %g0, %l0
F004C5A8: 32800006                 bne,a   loc_F004C5C0
F004C5AC: e2342064                 sth     %l1, [%l0+0x64]
F004C5B0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004C5B4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004C5B8: 10800058                 ba      locret_F004C718
F004C5BC: f04a2038                 ldsb    [%o0+0x38], %i0
F004C5C0: d0142044                 lduh    [%l0+0x44], %o0
F004C5C4: 9204bffd                 add     %l2, -3, %o1
F004C5C8: 80a26001                 cmp     %o1, 1
F004C5CC: 90122046                 bset    0x46, %o0 ! 'F'
F004C5D0: 08800005                 bleu    loc_F004C5E4
F004C5D4: d0342044                 sth     %o0, [%l0+0x44]
F004C5D8: 80a4a009                 cmp     %l2, 9
F004C5DC: 12800006                 bne     loc_F004C5F4
F004C5E0: 80a4a002                 cmp     %l2, 2
F004C5E4: d056a038                 ldsh    [%i2+0x38], %o0
F004C5E8: d024208c                 st      %o0, [%l0+0x8C]
F004C5EC: d0342038                 sth     %o0, [%l0+0x38]
F004C5F0: 80a4a002                 cmp     %l2, 2
F004C5F4: 12800004                 bne     loc_F004C604
F004C5F8: e4242034                 st      %l2, [%l0+0x34]
F004C5FC: 10800003                 ba      loc_F004C608
F004C600: 90102002                 mov     2, %o0
F004C604: 90102001                 mov     1, %o0
F004C608: d0342066                 sth     %o0, [%l0+0x66]
F004C60C: d0042030                 ld      [%l0+0x30], %o0
F004C610: d0522124                 ldsh    [%o0+0x124], %o0
F004C614: 80a22000                 cmp     %o0, 0
F004C618: 0280000c                 be      loc_F004C648
F004C61C: 113c04cf                 sethi   -0xFECC400, %o0
F004C620: d01620e4                 lduh    [%i0+0xE4], %o0
F004C624: d03420e4                 sth     %o0, [%l0+0xE4]
F004C628: d01620e6                 lduh    [%i0+0xE6], %o0
F004C62C: d2042030                 ld      [%l0+0x30], %o1
F004C630: d03420e6                 sth     %o0, [%l0+0xE6]
F004C634: d2126124                 lduh    [%o1+0x124], %o1
F004C638: 113c043a                 sethi   %hi(_nogroup), %o0
F004C63C: d01223b8                 lduh    [%o0+%lo(_nogroup)], %o0
F004C640: 10800007                 ba      loc_F004C65C
F004C644: d2342068                 sth     %o1, [%l0+0x68]
F004C648: d00221d8                 ld      [%o0+0x1D8], %o0
F004C64C: d002201c                 ld      [%o0+0x1C], %o0
F004C650: d0122002                 lduh    [%o0+2], %o0
F004C654: d0342068                 sth     %o0, [%l0+0x68]
F004C658: d016206a                 lduh    [%i0+0x6A], %o0
F004C65C: d034206a                 sth     %o0, [%l0+0x6A]
F004C660: d0142064                 lduh    [%l0+0x64], %o0
F004C664: 808a2400                 btst    0x400, %o0
F004C668: 0280000b                 be      loc_F004C694
F004C66C: 90100010                 mov     %l0, %o0
F004C670: 7fff0ca2                 call    _groupmember
F004C674: d054206a                 ldsh    [%l0+0x6A], %o0
F004C678: 80a22000                 cmp     %o0, 0
F004C67C: 12800006                 bne     loc_F004C694
F004C680: 90100010                 mov     %l0, %o0
F004C684: d0142064                 lduh    [%l0+0x64], %o0
F004C688: 900a3bff                 and     %o0, -0x401, %o0
F004C68C: d0342064                 sth     %o0, [%l0+0x64]
F004C690: 90100010                 mov     %l0, %o0
F004C694: 400007ac                 call    _iupdat
F004C698: 92102001                 mov     1, %o1
F004C69C: 80a4a002                 cmp     %l2, 2
F004C6A0: 12800006                 bne     loc_F004C6B8
F004C6A4: 80a4e000                 cmp     %l3, 0
F004C6A8: 90100010                 mov     %l0, %o0
F004C6AC: 4000001d                 call    sub_F004C720
F004C6B0: 92100018                 mov     %i0, %o1
F004C6B4: a6920000                 orcc    %o0, %g0, %l3
F004C6B8: 02800009                 be      loc_F004C6DC
F004C6BC: 90100010                 mov     %l0, %o0
F004C6C0: c0342066                 clrh    [%l0+0x66]
F004C6C4: d2142044                 lduh    [%l0+0x44], %o1
F004C6C8: 92126040                 bset    0x40, %o1 ! '@'
F004C6CC: 400006b3                 call    _iput
F004C6D0: d2322044                 sth     %o1, [%o0+0x44]
F004C6D4: 10800011                 ba      locret_F004C718
F004C6D8: b0100013                 mov     %l3, %i0
F004C6DC: d2142044                 lduh    [%l0+0x44], %o1
F004C6E0: 1100003f901223fe         set     0xFFFE, %o0
F004C6E8: 920a4008                 and     %o1, %o0, %o1
F004C6EC: 808a6010                 btst    0x10, %o1
F004C6F0: 02800008                 be      loc_F004C710
F004C6F4: d2342044                 sth     %o1, [%l0+0x44]
F004C6F8: 1100003f901223ef         set     0xFFEF, %o0
F004C700: 900a4008                 and     %o1, %o0, %o0
F004C704: d0342044                 sth     %o0, [%l0+0x44]
F004C708: 7fff19b8                 call    _wakeup
F004C70C: 90100010                 mov     %l0, %o0
F004C710: e0264000                 st      %l0, [%i1]
F004C714: b0100013                 mov     %l3, %i0
F004C718: 81c7e008                 ret
F004C71C: 81e80000                 restore
