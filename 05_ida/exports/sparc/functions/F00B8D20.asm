F00B8D20: 9de3bf98                 save    %sp, -0x68, %sp
F00B8D24: 113c04fc                 sethi   %hi(_scsi_spl), %o0
F00B8D28: 7fff77f7                 call    _splr
F00B8D2C: d00220c0                 ld      [%o0+%lo(_scsi_spl)], %o0
F00B8D30: 173c04c59812e3d4         set     dword_F01317D4, %o4
F00B8D38: 92102001                 mov     1, %o1
F00B8D3C: d402e3d4                 ld      [%o3+0x3D4], %o2
F00B8D40: a0100008                 mov     %o0, %l0
F00B8D44: 80a2a000                 cmp     %o2, 0
F00B8D48: 02800019                 be      loc_F00B8DAC
F00B8D4C: d2232010                 st      %o1, [%o4+0x10]
F00B8D50: a410000b                 mov     %o3, %l2
F00B8D54: a210000c                 mov     %o4, %l1
F00B8D58: f004a3d4                 ld      [%l2+0x3D4], %i0
F00B8D5C: 4000004a                 call    sub_F00B8E84
F00B8D60: 90100011                 mov     %l1, %o0
F00B8D64: 9fc20000                 call    %o0
F00B8D68: 01000000                 nop
F00B8D6C: 80a22000                 cmp     %o0, 0
F00B8D70: 1280000b                 bne     loc_F00B8D9C
F00B8D74: 173c04c5                 sethi   %hi(dword_F01317D4), %o3
F00B8D78: d004a3d4                 ld      [%l2+0x3D4], %o0
F00B8D7C: 80a60008                 cmp     %i0, %o0
F00B8D80: 18800008                 bgu     loc_F00B8DA0
F00B8D84: d002e3d4                 ld      [%o3+%lo(dword_F01317D4)], %o0
F00B8D88: c0246010                 clr     [%l1+0x10]
F00B8D8C: 7fff77e6                 call    _splx
F00B8D90: 90100010                 mov     %l0, %o0
F00B8D94: 1080000b                 ba      locret_F00B8DC0
F00B8D98: b0103fff                 mov     -1, %i0
F00B8D9C: d002e3d4                 ld      [%o3+0x3D4], %o0
F00B8DA0: 80a22000                 cmp     %o0, 0
F00B8DA4: 12bfffee                 bne     loc_F00B8D5C
F00B8DA8: f004a3d4                 ld      [%l2+0x3D4], %i0
F00B8DAC: 113c04c5                 sethi   %hi(dword_F01317E4), %o0
F00B8DB0: c02223e4                 clr     [%o0+%lo(dword_F01317E4)]
F00B8DB4: 7fff77dc                 call    _splx
F00B8DB8: 90100010                 mov     %l0, %o0
F00B8DBC: b0102000                 mov     0, %i0
F00B8DC0: 81c7e008                 ret
F00B8DC4: 81e80000                 restore
