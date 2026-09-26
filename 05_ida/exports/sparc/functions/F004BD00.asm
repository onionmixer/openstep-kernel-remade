F004BD00: 9de3bf98                 save    %sp, -0x68, %sp
F004BD04: d2076030                 ld      [%i5+0x30], %o1
F004BD08: d006a030                 ld      [%i2+0x30], %o0
F004BD0C: a6100018                 mov     %i0, %l3
F004BD10: 80a24008                 cmp     %o1, %o0
F004BD14: 12800006                 bne     loc_F004BD2C
F004BD18: e407a05c                 ld      [%fp+arg_5C], %l2
F004BD1C: d0066030                 ld      [%i1+0x30], %o0
F004BD20: 80a24008                 cmp     %o1, %o0
F004BD24: 22800004                 be,a    loc_F004BD34
F004BD28: d2066048                 ld      [%i1+0x48], %o1
F004BD2C: 10800077                 ba      locret_F004BF08
F004BD30: b0102012                 mov     0x12, %i0
F004BD34: d0076048                 ld      [%i5+0x48], %o0
F004BD38: 80a24008                 cmp     %o1, %o0
F004BD3C: 12800004                 bne     loc_F004BD4C
F004BD40: 9010001a                 mov     %i2, %o0
F004BD44: 10800071                 ba      locret_F004BF08
F004BD48: b0103fff                 mov     -1, %i0
F004BD4C: 40000cef                 call    _iaccess
F004BD50: 92102080                 mov     0x80, %o1
F004BD54: 80a22000                 cmp     %o0, 0
F004BD58: 1280006c                 bne     locret_F004BF08
F004BD5C: b0100008                 mov     %o0, %i0
F004BD60: d016a064                 lduh    [%i2+0x64], %o0
F004BD64: 808a2200                 btst    0x200, %o0
F004BD68: 02800011                 be      loc_F004BDAC
F004BD6C: 113c04cf                 sethi   %hi(_active_u), %o0
F004BD70: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F004BD74: d002201c                 ld      [%o0+0x1C], %o0
F004BD78: d2522002                 ldsh    [%o0+2], %o1
F004BD7C: 80a26000                 cmp     %o1, 0
F004BD80: 0280000c                 be      loc_F004BDB0
F004BD84: 1500003c                 sethi   0xF000, %o2
F004BD88: d056a068                 ldsh    [%i2+0x68], %o0
F004BD8C: 80a24008                 cmp     %o1, %o0
F004BD90: 22800009                 be,a    loc_F004BDB4
F004BD94: d0166064                 lduh    [%i1+0x64], %o0
F004BD98: d0576068                 ldsh    [%i5+0x68], %o0
F004BD9C: 80a20009                 cmp     %o0, %o1
F004BDA0: 02800004                 be      loc_F004BDB0
F004BDA4: b0102001                 mov     1, %i0
F004BDA8: 30800058                 ba,a    locret_F004BF08
F004BDAC: 1500003c                 sethi   0xF000, %o2
F004BDB0: d0166064                 lduh    [%i1+0x64], %o0
F004BDB4: 13000010                 sethi   0x4000, %o1
F004BDB8: 900a000a                 and     %o0, %o2, %o0
F004BDBC: 901a0009                 btog    %o1, %o0
F004BDC0: 80a00008                 cmp     %g0, %o0
F004BDC4: d0176064                 lduh    [%i5+0x64], %o0
F004BDC8: a2603fff                 subc    %g0, -1, %l1
F004BDCC: 900a000a                 and     %o0, %o2, %o0
F004BDD0: 80a20009                 cmp     %o0, %o1
F004BDD4: 12800010                 bne     loc_F004BE14
F004BDD8: 80a46000                 cmp     %l1, 0
F004BDDC: 32800004                 bne,a   loc_F004BDEC
F004BDE0: d206a048                 ld      [%i2+0x48], %o1
F004BDE4: 10800049                 ba      locret_F004BF08
F004BDE8: b0102015                 mov     0x15, %i0
F004BDEC: 400003f6                 call    sub_F004CDC4
F004BDF0: 9010001d                 mov     %i5, %o0
F004BDF4: 80a22000                 cmp     %o0, 0
F004BDF8: 02800044                 be      locret_F004BF08
F004BDFC: b0102042                 mov     0x42, %i0 ! 'B'
F004BE00: d0576066                 ldsh    [%i5+0x66], %o0
F004BE04: 80a22002                 cmp     %o0, 2
F004BE08: 04800006                 ble     loc_F004BE20
F004BE0C: a006a00c                 add     %i2, 0xC, %l0
F004BE10: 3080003e                 ba,a    locret_F004BF08
F004BE14: 1280003d                 bne     locret_F004BF08
F004BE18: b0102014                 mov     0x14, %i0
F004BE1C: a006a00c                 add     %i2, 0xC, %l0
F004BE20: 90100010                 mov     %l0, %o0
F004BE24: 7fff6781                 call    _dnlc_remove
F004BE28: 9210001b                 mov     %i3, %o1
F004BE2C: 90100010                 mov     %l0, %o0
F004BE30: d804a010                 ld      [%l2+0x10], %o4
F004BE34: 9210001b                 mov     %i3, %o1
F004BE38: d6066048                 ld      [%i1+0x48], %o3
F004BE3C: 9406600c                 add     %i1, 0xC, %o2
F004BE40: d6230000                 st      %o3, [%o4]
F004BE44: 7fff6646                 call    _dnlc_enter
F004BE48: 96102000                 mov     0, %o3
F004BE4C: 7fff6247                 call    _bwrite
F004BE50: d004a00c                 ld      [%l2+0xC], %o0
F004BE54: c024a00c                 clr     [%l2+0xC]
F004BE58: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004BE5C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004BE60: f04a2038                 ldsb    [%o0+0x38], %i0
F004BE64: 80a62000                 cmp     %i0, 0
F004BE68: 12800028                 bne     locret_F004BF08
F004BE6C: 80a46000                 cmp     %l1, 0
F004BE70: d016a044                 lduh    [%i2+0x44], %o0
F004BE74: 90122042                 bset    0x42, %o0 ! 'B'
F004BE78: d036a044                 sth     %o0, [%i2+0x44]
F004BE7C: d2176066                 lduh    [%i5+0x66], %o1
F004BE80: d0176044                 lduh    [%i5+0x44], %o0
F004BE84: 92027fff                 inc     -1, %o1
F004BE88: d2376066                 sth     %o1, [%i5+0x66]
F004BE8C: 90122040                 bset    0x40, %o0 ! '@'
F004BE90: 0280001d                 be      loc_F004BF04
F004BE94: d0376044                 sth     %o0, [%i5+0x44]
F004BE98: d0176066                 lduh    [%i5+0x66], %o0
F004BE9C: 90023fff                 inc     -1, %o0
F004BEA0: d0376066                 sth     %o0, [%i5+0x66]
F004BEA4: 912a2010                 sll     %o0, 16, %o0
F004BEA8: 80a22000                 cmp     %o0, 0
F004BEAC: 02800004                 be      loc_F004BEBC
F004BEB0: 113c043a                 sethi   %hi(aDirenterTarget), %o0! "direnter: target directory link count"
F004BEB4: 7fff24af                 call    _panic
F004BEB8: 90122220                 bset    %lo(aDirenterTarget), %o0! "direnter: target directory link count"
F004BEBC: 9010001d                 mov     %i5, %o0
F004BEC0: 40000a0f                 call    _itrunc
F004BEC4: 92102000                 mov     0, %o1
F004BEC8: d216a066                 lduh    [%i2+0x66], %o1
F004BECC: 80a4c01a                 cmp     %l3, %i2
F004BED0: d016a044                 lduh    [%i2+0x44], %o0
F004BED4: 92027fff                 inc     -1, %o1
F004BED8: d236a066                 sth     %o1, [%i2+0x66]
F004BEDC: 90122040                 bset    0x40, %o0 ! '@'
F004BEE0: 02800009                 be      loc_F004BF04
F004BEE4: d036a044                 sth     %o0, [%i2+0x44]
F004BEE8: 90100019                 mov     %i1, %o0
F004BEEC: 92100013                 mov     %l3, %o1
F004BEF0: 40000008                 call    sub_F004BF10
F004BEF4: 9410001a                 mov     %i2, %o2
F004BEF8: 80a22000                 cmp     %o0, 0
F004BEFC: 12800003                 bne     locret_F004BF08
F004BF00: b0100008                 mov     %o0, %i0
F004BF04: b0102000                 mov     0, %i0
F004BF08: 81c7e008                 ret
F004BF0C: 81e80000                 restore
