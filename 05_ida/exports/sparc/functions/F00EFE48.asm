F00EFE48: 9de3bf98                 save    %sp, -0x68, %sp
F00EFE4C: a8100018                 mov     %i0, %l4
F00EFE50: e6052020                 ld      [%l4+0x20], %l3
F00EFE54: 113c03e890122354         set     _emptyCache, %o0
F00EFE5C: 80a4c008                 cmp     %l3, %o0
F00EFE60: 12800006                 bne     loc_F00EFE78
F00EFE64: 113c04bc                 sethi   -0xFED1000, %o0
F00EFE68: 7fffffd8                 call    __cache_create
F00EFE6C: 90100014                 mov     %l4, %o0
F00EFE70: 1080009b                 ba      locret_F00F00DC
F00EFE74: b0100008                 mov     %o0, %i0
F00EFE78: d00220d4                 ld      [%o0+0xD4], %o0
F00EFE7C: 80a22000                 cmp     %o0, 0
F00EFE80: 2280002e                 be,a    loc_F00EFF38
F00EFE84: d004c000                 ld      [%l3], %o0
F00EFE88: d0052010                 ld      [%l4+0x10], %o0
F00EFE8C: 808a2040                 btst    0x40, %o0 ! '@'
F00EFE90: 12800028                 bne     loc_F00EFF30
F00EFE94: 900a3fbf                 and     %o0, -0x41, %o0
F00EFE98: c024e004                 clr     [%l3+4]
F00EFE9C: d004c000                 ld      [%l3], %o0
F00EFEA0: 80a23fff                 cmp     %o0, -1
F00EFEA4: 0280001e                 be      loc_F00EFF1C
F00EFEA8: a2102000                 mov     0, %l1
F00EFEAC: 113c03c6aa1222b0         set     __objc_msgForward, %l5
F00EFEB4: 912c6002                 sll     %l1, 2, %o0
F00EFEB8: a4020013                 add     %o0, %l3, %l2
F00EFEBC: d004a008                 ld      [%l2+8], %o0
F00EFEC0: 80a22000                 cmp     %o0, 0
F00EFEC4: 22800011                 be,a    loc_F00EFF08
F00EFEC8: a2046001                 inc     %l1
F00EFECC: d0022008                 ld      [%o0+8], %o0
F00EFED0: 80a20015                 cmp     %o0, %l5
F00EFED4: 1280000a                 bne     loc_F00EFEFC
F00EFED8: 912c6002                 sll     %l1, 2, %o0
F00EFEDC: 4000031c                 call    _NXDefaultMallocZone
F00EFEE0: 01000000                 nop
F00EFEE4: 4000031a                 call    _NXDefaultMallocZone
F00EFEE8: a0100008                 mov     %o0, %l0
F00EFEEC: d4042008                 ld      [%l0+8], %o2
F00EFEF0: 9fc28000                 call    %o2
F00EFEF4: d204a008                 ld      [%l2+8], %o1
F00EFEF8: 912c6002                 sll     %l1, 2, %o0
F00EFEFC: 90020013                 add     %o0, %l3, %o0
F00EFF00: c0222008                 clr     [%o0+8]
F00EFF04: a2046001                 inc     %l1
F00EFF08: d004c000                 ld      [%l3], %o0
F00EFF0C: 90022001                 inc     %o0
F00EFF10: 80a44008                 cmp     %l1, %o0
F00EFF14: 0abfffe9                 bcs     loc_F00EFEB8
F00EFF18: 912c6002                 sll     %l1, 2, %o0
F00EFF1C: d0052010                 ld      [%l4+0x10], %o0
F00EFF20: 90122040                 bset    0x40, %o0 ! '@'
F00EFF24: d0252010                 st      %o0, [%l4+0x10]
F00EFF28: 1080006d                 ba      locret_F00F00DC
F00EFF2C: b0100013                 mov     %l3, %i0
F00EFF30: d0252010                 st      %o0, [%l4+0x10]
F00EFF34: d004c000                 ld      [%l3], %o0
F00EFF38: a4022001                 add     %o0, 1, %l2
F00EFF3C: 40000304                 call    _NXDefaultMallocZone
F00EFF40: a52ca001                 sll     %l2, 1, %l2
F00EFF44: 40000302                 call    _NXDefaultMallocZone
F00EFF48: a0100008                 mov     %o0, %l0
F00EFF4C: a204bfff                 add     %l2, -1, %l1
F00EFF50: 932c6002                 sll     %l1, 2, %o1
F00EFF54: d4042004                 ld      [%l0+4], %o2
F00EFF58: 9fc28000                 call    %o2
F00EFF5C: 9202600c                 inc     0xC, %o1
F00EFF60: b0100008                 mov     %o0, %i0
F00EFF64: e2260000                 st      %l1, [%i0]
F00EFF68: a2102000                 mov     0, %l1
F00EFF6C: 80a44012                 cmp     %l1, %l2
F00EFF70: 1a800008                 bcc     loc_F00EFF90
F00EFF74: c0262004                 clr     [%i0+4]
F00EFF78: 912c6002                 sll     %l1, 2, %o0
F00EFF7C: 90020018                 add     %o0, %i0, %o0
F00EFF80: a2046001                 inc     %l1
F00EFF84: 80a44012                 cmp     %l1, %l2
F00EFF88: 0abffffc                 bcs     loc_F00EFF78
F00EFF8C: c0222008                 clr     [%o0+8]
F00EFF90: 113c04bc                 sethi   %hi(dword_F012F0D0), %o0
F00EFF94: d00220d0                 ld      [%o0+%lo(dword_F012F0D0)], %o0
F00EFF98: 80a22000                 cmp     %o0, 0
F00EFF9C: 1280002e                 bne     loc_F00F0054
F00EFFA0: d004c000                 ld      [%l3], %o0
F00EFFA4: 80a23fff                 cmp     %o0, -1
F00EFFA8: 02800027                 be      loc_F00F0044
F00EFFAC: a2102000                 mov     0, %l1
F00EFFB0: 912c6002                 sll     %l1, 2, %o0
F00EFFB4: 90020013                 add     %o0, %l3, %o0
F00EFFB8: d6022008                 ld      [%o0+8], %o3
F00EFFBC: 80a2e000                 cmp     %o3, 0
F00EFFC0: 2280001c                 be,a    loc_F00F0030
F00EFFC4: a2046001                 inc     %l1
F00EFFC8: d8060000                 ld      [%i0], %o4
F00EFFCC: d002c000                 ld      [%o3], %o0
F00EFFD0: 920b0008                 and     %o4, %o0, %o1
F00EFFD4: 912a6002                 sll     %o1, 2, %o0
F00EFFD8: 94020018                 add     %o0, %i0, %o2
F00EFFDC: d002a008                 ld      [%o2+8], %o0
F00EFFE0: 80a22000                 cmp     %o0, 0
F00EFFE4: 32800004                 bne,a   loc_F00EFFF4
F00EFFE8: 92026001                 inc     %o1
F00EFFEC: 1080000d                 ba      loc_F00F0020
F00EFFF0: d622a008                 st      %o3, [%o2+8]
F00EFFF4: 920a400c                 and     %o1, %o4, %o1
F00EFFF8: 912a6002                 sll     %o1, 2, %o0
F00EFFFC: 94020018                 add     %o0, %i0, %o2
F00F0000: d002a008                 ld      [%o2+8], %o0
F00F0004: 80a22000                 cmp     %o0, 0
F00F0008: 32bffffb                 bne,a   loc_F00EFFF4
F00F000C: 92026001                 inc     %o1
F00F0010: 912c6002                 sll     %l1, 2, %o0
F00F0014: 90020013                 add     %o0, %l3, %o0
F00F0018: d0022008                 ld      [%o0+8], %o0
F00F001C: d022a008                 st      %o0, [%o2+8]
F00F0020: d0062004                 ld      [%i0+4], %o0
F00F0024: 90022001                 inc     %o0
F00F0028: d0262004                 st      %o0, [%i0+4]
F00F002C: a2046001                 inc     %l1
F00F0030: d004c000                 ld      [%l3], %o0
F00F0034: 90022001                 inc     %o0
F00F0038: 80a44008                 cmp     %l1, %o0
F00F003C: 0abfffde                 bcs     loc_F00EFFB4
F00F0040: 912c6002                 sll     %l1, 2, %o0
F00F0044: d0052010                 ld      [%l4+0x10], %o0
F00F0048: 90122020                 bset    0x20, %o0 ! ' '
F00F004C: 1080001d                 ba      loc_F00F00C0
F00F0050: d0252010                 st      %o0, [%l4+0x10]
F00F0054: 80a23fff                 cmp     %o0, -1
F00F0058: 0280001a                 be      loc_F00F00C0
F00F005C: a2102000                 mov     0, %l1
F00F0060: 113c03c6aa1222b0         set     __objc_msgForward, %l5
F00F0068: 912c6002                 sll     %l1, 2, %o0
F00F006C: a4020013                 add     %o0, %l3, %l2
F00F0070: d004a008                 ld      [%l2+8], %o0
F00F0074: 80a22000                 cmp     %o0, 0
F00F0078: 2280000d                 be,a    loc_F00F00AC
F00F007C: a2046001                 inc     %l1
F00F0080: d0022008                 ld      [%o0+8], %o0
F00F0084: 80a20015                 cmp     %o0, %l5
F00F0088: 12800009                 bne     loc_F00F00AC
F00F008C: a2046001                 inc     %l1
F00F0090: 400002af                 call    _NXDefaultMallocZone
F00F0094: 01000000                 nop
F00F0098: 400002ad                 call    _NXDefaultMallocZone
F00F009C: a0100008                 mov     %o0, %l0
F00F00A0: d4042008                 ld      [%l0+8], %o2
F00F00A4: 9fc28000                 call    %o2
F00F00A8: d204a008                 ld      [%l2+8], %o1
F00F00AC: d004c000                 ld      [%l3], %o0
F00F00B0: 90022001                 inc     %o0
F00F00B4: 80a44008                 cmp     %l1, %o0
F00F00B8: 0abfffed                 bcs     loc_F00F006C
F00F00BC: 912c6002                 sll     %l1, 2, %o0
F00F00C0: 400002a3                 call    _NXDefaultMallocZone
F00F00C4: f0252020                 st      %i0, [%l4+0x20]
F00F00C8: 400002a1                 call    _NXDefaultMallocZone
F00F00CC: a0100008                 mov     %o0, %l0
F00F00D0: d4042008                 ld      [%l0+8], %o2
F00F00D4: 9fc28000                 call    %o2
F00F00D8: 92100013                 mov     %l3, %o1
F00F00DC: 81c7e008                 ret
F00F00E0: 81e80000                 restore
