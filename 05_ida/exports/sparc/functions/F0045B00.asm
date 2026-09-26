F0045B00: 9de3bf98                 save    %sp, -0x68, %sp
F0045B04: e0064000                 ld      [%i1], %l0
F0045B08: a2102001                 mov     1, %l1
F0045B0C: 90100018                 mov     %i0, %o0! XDR *
F0045B10: 7ffffe57                 call    _xdr_u_int
F0045B14: 9210001a                 mov     %i2, %o1
F0045B18: 80a22000                 cmp     %o0, 0
F0045B1C: 32800005                 bne,a   loc_F0045B30
F0045B20: f4068000                 ld      [%i2], %i2
F0045B24: 113c0438                 sethi   %hi(aXdrArraySizeFa), %o0! "xdr_array: size FAILED\n"
F0045B28: 1080000a                 ba      loc_F0045B50
F0045B2C: 90122078                 bset    %lo(aXdrArraySizeFa), %o0! "xdr_array: size FAILED\n"
F0045B30: 80a6801b                 cmp     %i2, %i3
F0045B34: 0880000b                 bleu    loc_F0045B60
F0045B38: 9010001a                 mov     %i2, %o0
F0045B3C: d0060000                 ld      [%i0], %o0
F0045B40: 80a22002                 cmp     %o0, 2
F0045B44: 02800006                 be      loc_F0045B5C
F0045B48: 113c0438                 sethi   %hi(aXdrArrayBadSiz), %o0! "xdr_array: bad size FAILED\n"
F0045B4C: 90122090                 bset    %lo(aXdrArrayBadSiz), %o0! "xdr_array: bad size FAILED\n"
F0045B50: 7fff3ac2                 call    _printf
F0045B54: b0102000                 mov     0, %i0
F0045B58: 30800032                 ba,a    locret_F0045C20
F0045B5C: 9010001a                 mov     %i2, %o0
F0045B60: 7fff0268                 call    _umul
F0045B64: 9210001c                 mov     %i4, %o1! size_t
F0045B68: 80a42000                 cmp     %l0, 0
F0045B6C: 12800015                 bne     loc_F0045BC0
F0045B70: a4100008                 mov     %o0, %l2
F0045B74: d0060000                 ld      [%i0], %o0
F0045B78: 80a22001                 cmp     %o0, 1
F0045B7C: 02800006                 be      loc_F0045B94
F0045B80: 80a22002                 cmp     %o0, 2
F0045B84: 22800027                 be,a    locret_F0045C20
F0045B88: b0102001                 mov     1, %i0
F0045B8C: 1080000e                 ba      loc_F0045BC4
F0045B90: b6102000                 mov     0, %i3
F0045B94: 80a6a000                 cmp     %i2, 0
F0045B98: 12800004                 bne     loc_F0045BA8
F0045B9C: 01000000                 nop
F0045BA0: 10800020                 ba      locret_F0045C20
F0045BA4: b0102001                 mov     1, %i0
F0045BA8: 40008932                 call    _kalloc
F0045BAC: 90100012                 mov     %l2, %o0! void *
F0045BB0: a0100008                 mov     %o0, %l0
F0045BB4: e0264000                 st      %l0, [%i1]
F0045BB8: 40013ca8                 call    _bzero
F0045BBC: 92100012                 mov     %l2, %o1
F0045BC0: b6102000                 mov     0, %i3
F0045BC4: 80a6c01a                 cmp     %i3, %i2
F0045BC8: 3a80000e                 bcc,a   loc_F0045C00
F0045BCC: d0060000                 ld      [%i0], %o0
F0045BD0: 80a46000                 cmp     %l1, 0
F0045BD4: 0280000a                 be      loc_F0045BFC
F0045BD8: 90100018                 mov     %i0, %o0
F0045BDC: 92100010                 mov     %l0, %o1
F0045BE0: 9fc74000                 call    %i5
F0045BE4: 94103fff                 mov     -1, %o2
F0045BE8: a2100008                 mov     %o0, %l1
F0045BEC: b606e001                 inc     %i3
F0045BF0: 80a6c01a                 cmp     %i3, %i2
F0045BF4: 0abffff7                 bcs     loc_F0045BD0
F0045BF8: a004001c                 add     %l0, %i4, %l0
F0045BFC: d0060000                 ld      [%i0], %o0
F0045C00: 80a22002                 cmp     %o0, 2
F0045C04: 12800007                 bne     locret_F0045C20
F0045C08: b0100011                 mov     %l1, %i0
F0045C0C: d0064000                 ld      [%i1], %o0
F0045C10: 40008964                 call    _kfree
F0045C14: 92100012                 mov     %l2, %o1
F0045C18: c0264000                 clr     [%i1]
F0045C1C: b0100011                 mov     %l1, %i0
F0045C20: 81c7e008                 ret
F0045C24: 81e80000                 restore
