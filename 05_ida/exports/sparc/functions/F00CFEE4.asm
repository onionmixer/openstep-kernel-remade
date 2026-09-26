F00CFEE4: 9de3bf90                 save    %sp, -0x70, %sp
F00CFEE8: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F00CFEEC: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F00CFEF0: 40008660                 call    _objc_msgSend
F00CFEF4: 90100018                 mov     %i0, %o0
F00CFEF8: a0100008                 mov     %o0, %l0
F00CFEFC: 9010001b                 mov     %i3, %o0! void *
F00CFF00: 7fff13d6                 call    _bzero
F00CFF04: 92102060                 mov     0x60, %o1 ! '`'
F00CFF08: d00e2188                 ldub    [%i0+0x188], %o0
F00CFF0C: d02ec000                 stb     %o0, [%i3]
F00CFF10: d00e2189                 ldub    [%i0+0x189], %o0
F00CFF14: d02ee001                 stb     %o0, [%i3+1]
F00CFF18: d0068000                 ld      [%i2], %o0
F00CFF1C: 80a22001                 cmp     %o0, 1
F00CFF20: 22800010                 be,a    loc_F00CFF60
F00CFF24: c02ee010                 clrb    [%i3+0x10]
F00CFF28: 0a800006                 bcs     loc_F00CFF40
F00CFF2C: 80a22004                 cmp     %o0, 4
F00CFF30: 3880004b                 bgu,a   locret_F00D005C
F00CFF34: b0102000                 mov     0, %i0
F00CFF38: 1080001e                 ba      loc_F00CFFB0
F00CFF3C: d606a014                 ld      [%i2+0x14], %o3
F00CFF40: 90102001                 mov     1, %o0
F00CFF44: d02ee010                 stb     %o0, [%i3+0x10]
F00CFF48: 113c0505                 sethi   %hi(paGenrwcdbReadfl), %o0
F00CFF4C: d202237c                 ld      [%o0+%lo(paGenrwcdbReadfl)], %o1
F00CFF50: 9406e004                 add     %i3, 4, %o2
F00CFF54: d806a004                 ld      [%i2+4], %o4
F00CFF58: 10800007                 ba      loc_F00CFF74
F00CFF5C: 96102001                 mov     1, %o3
F00CFF60: 113c0505                 sethi   %hi(paGenrwcdbReadfl), %o0! id
F00CFF64: d202237c                 ld      [%o0+%lo(paGenrwcdbReadfl)], %o1! SEL
F00CFF68: 9406e004                 add     %i3, 4, %o2
F00CFF6C: d806a004                 ld      [%i2+4], %o4
F00CFF70: 96102000                 mov     0, %o3
F00CFF74: da06a008                 ld      [%i2+8], %o5
F00CFF78: 4000863e                 call    _objc_msgSend
F00CFF7C: 90100018                 mov     %i0, %o0
F00CFF80: c026a014                 clr     [%i2+0x14]
F00CFF84: d006a008                 ld      [%i2+8], %o0
F00CFF88: 7ffcd95e                 call    _umul
F00CFF8C: 92100010                 mov     %l0, %o1
F00CFF90: d026e014                 st      %o0, [%i3+0x14]
F00CFF94: 9010201e                 mov     0x1E, %o0
F00CFF98: d026e018                 st      %o0, [%i3+0x18]
F00CFF9C: d006e01c                 ld      [%i3+0x1C], %o0
F00CFFA0: 13200000                 sethi   0x80000000, %o1
F00CFFA4: 90120009                 bset    %o1, %o0
F00CFFA8: 1080002c                 ba      loc_F00D0058
F00CFFAC: d026e01c                 st      %o0, [%i3+0x1C]
F00CFFB0: d2062188                 ld      [%i0+0x188], %o1
F00CFFB4: 153fffc0                 sethi   -0x10000, %o2
F00CFFB8: d002c000                 ld      [%o3], %o0
F00CFFBC: 920a400a                 and     %o1, %o2, %o1
F00CFFC0: 900a000a                 and     %o0, %o2, %o0
F00CFFC4: 80a20009                 cmp     %o0, %o1
F00CFFC8: 0280000c                 be      loc_F00CFFF8
F00CFFCC: 90102007                 mov     7, %o0
F00CFFD0: d022e020                 st      %o0, [%o3+0x20]
F00CFFD4: 90103d3e                 mov     -0x2C2, %o0
F00CFFD8: d026a028                 st      %o0, [%i2+0x28]
F00CFFDC: 90100018                 mov     %i0, %o0! id
F00CFFE0: 133c0505                 sethi   %hi(paSdiocomplete), %o1
F00CFFE4: d2026380                 ld      [%o1+%lo(paSdiocomplete)], %o1! SEL
F00CFFE8: 40008622                 call    _objc_msgSend
F00CFFEC: 9410001a                 mov     %i2, %o2
F00CFFF0: 1080001b                 ba      locret_F00D005C
F00CFFF4: b0102007                 mov     7, %i0
F00CFFF8: d01ac000                 ldd     [%o3], %o0
F00CFFFC: d03ec000                 std     %o0, [%i3]
F00D0000: d01ae008                 ldd     [%o3+8], %o0
F00D0004: d03ee008                 std     %o0, [%i3+8]
F00D0008: d01ae010                 ldd     [%o3+0x10], %o0
F00D000C: d03ee010                 std     %o0, [%i3+0x10]
F00D0010: d01ae018                 ldd     [%o3+0x18], %o0
F00D0014: d03ee018                 std     %o0, [%i3+0x18]
F00D0018: d01ae020                 ldd     [%o3+0x20], %o0
F00D001C: d03ee020                 std     %o0, [%i3+0x20]
F00D0020: d01ae028                 ldd     [%o3+0x28], %o0
F00D0024: d03ee028                 std     %o0, [%i3+0x28]
F00D0028: d01ae030                 ldd     [%o3+0x30], %o0
F00D002C: d03ee030                 std     %o0, [%i3+0x30]
F00D0030: d01ae038                 ldd     [%o3+0x38], %o0
F00D0034: d03ee038                 std     %o0, [%i3+0x38]
F00D0038: d01ae040                 ldd     [%o3+0x40], %o0
F00D003C: d03ee040                 std     %o0, [%i3+0x40]
F00D0040: d01ae048                 ldd     [%o3+0x48], %o0
F00D0044: d03ee048                 std     %o0, [%i3+0x48]
F00D0048: d01ae050                 ldd     [%o3+0x50], %o0
F00D004C: d03ee050                 std     %o0, [%i3+0x50]
F00D0050: d01ae058                 ldd     [%o3+0x58], %o0
F00D0054: d03ee058                 std     %o0, [%i3+0x58]
F00D0058: b0102000                 mov     0, %i0
F00D005C: 81c7e008                 ret
F00D0060: 81e80000                 restore
