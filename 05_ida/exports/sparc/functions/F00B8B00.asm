F00B8B00: 9de3bf98                 save    %sp, -0x68, %sp
F00B8B04: 113c04fc                 sethi   %hi(_scsi_spl), %o0
F00B8B08: 7fff787f                 call    _splr
F00B8B0C: d00220c0                 ld      [%o0+%lo(_scsi_spl)], %o0
F00B8B10: 153c04c5                 sethi   %hi(dword_F013179C), %o2
F00B8B14: 173c047d                 sethi   %hi(dword_F011F4A4), %o3
F00B8B18: a0100008                 mov     %o0, %l0
F00B8B1C: d202a39c                 ld      [%o2+%lo(dword_F013179C)], %o1
F00B8B20: 9012a39c                 or      %o2, %lo(dword_F013179C), %o0
F00B8B24: d2260000                 st      %o1, [%i0]
F00B8B28: d202e0a4                 ld      [%o3+%lo(dword_F011F4A4)], %o1
F00B8B2C: 80a26000                 cmp     %o1, 0
F00B8B30: 02800004                 be      loc_F00B8B40
F00B8B34: f022a39c                 st      %i0, [%o2+%lo(dword_F013179C)]
F00B8B38: 7ffd68ac                 call    _wakeup
F00B8B3C: c022e0a4                 clr     [%o3+%lo(dword_F011F4A4)]
F00B8B40: 133c04c5                 sethi   %hi(dword_F01317A0), %o1
F00B8B44: d00263a0                 ld      [%o1+%lo(dword_F01317A0)], %o0
F00B8B48: 80a22000                 cmp     %o0, 0
F00B8B4C: 0280000d                 be      loc_F00B8B80
F00B8B50: 01000000                 nop
F00B8B54: b0100009                 mov     %o1, %i0
F00B8B58: 400000cb                 call    sub_F00B8E84
F00B8B5C: 901623a0                 or      %i0, 0x3A0, %o0
F00B8B60: 9fc20000                 call    %o0
F00B8B64: 01000000                 nop
F00B8B68: 80a22000                 cmp     %o0, 0
F00B8B6C: 02800005                 be      loc_F00B8B80
F00B8B70: d00623a0                 ld      [%i0+0x3A0], %o0
F00B8B74: 80a22000                 cmp     %o0, 0
F00B8B78: 12bffff8                 bne     loc_F00B8B58
F00B8B7C: 01000000                 nop
F00B8B80: 7fff7869                 call    _splx
F00B8B84: 90100010                 mov     %l0, %o0
F00B8B88: 81c7e008                 ret
F00B8B8C: 81e80000                 restore
