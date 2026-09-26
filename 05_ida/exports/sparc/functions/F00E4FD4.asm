F00E4FD4: 9de3bf70                 save    %sp, -0x90, %sp
F00E4FD8: 90100019                 mov     %i1, %o0
F00E4FDC: 133c03f2a01262b8         set     aAddress, %l0! "address"
F00E4FE4: 92100010                 mov     %l0, %o1
F00E4FE8: 173c04bb                 sethi   %hi(_sparcfbs), %o3
F00E4FEC: 952e2004                 sll     %i0, 4, %o2
F00E4FF0: 94028018                 add     %o2, %i0, %o2
F00E4FF4: 952aa002                 sll     %o2, 2, %o2
F00E4FF8: d602e364                 ld      [%o3+%lo(_sparcfbs)], %o3
F00E4FFC: 9402a008                 inc     8, %o2
F00E5000: 7fff27f7                 call    _prom_getproplen
F00E5004: b002c00a                 add     %o3, %o2, %i0
F00E5008: 80a22000                 cmp     %o0, 0
F00E500C: 34800003                 bg,a    loc_F00E5018
F00E5010: 90102001                 mov     1, %o0
F00E5014: 90102000                 mov     0, %o0
F00E5018: 80a22000                 cmp     %o0, 0
F00E501C: 0280000a                 be      loc_F00E5044
F00E5020: 80a22008                 cmp     %o0, 8
F00E5024: 04800004                 ble     loc_F00E5034
F00E5028: 113c03f2                 sethi   %hi(aBufferTooSmall), %o0! "buffer too small\n"
F00E502C: 7ffcbd8b                 call    _printf
F00E5030: 901222c0                 bset    %lo(aBufferTooSmall), %o0! "buffer too small\n"
F00E5034: 90100019                 mov     %i1, %o0
F00E5038: 92100010                 mov     %l0, %o1
F00E503C: 7fff27f2                 call    _prom_getprop
F00E5040: 9407bff0                 add     %fp, var_10, %o2
F00E5044: 90100019                 mov     %i1, %o0
F00E5048: 133c03f2921262d8         set     aReg, %o1! "reg"
F00E5050: 7fff27ed                 call    _prom_getprop
F00E5054: 9407bfd8                 add     %fp, var_28, %o2
F00E5058: 90102002                 mov     2, %o0
F00E505C: d0260000                 st      %o0, [%i0]
F00E5060: c0262004                 clr     [%i0+4]
F00E5064: 90100019                 mov     %i1, %o0
F00E5068: 133c03f2a01262e0         set     aWidth, %l0! "width"
F00E5070: 7fff27db                 call    _prom_getproplen
F00E5074: 92100010                 mov     %l0, %o1
F00E5078: 80a22000                 cmp     %o0, 0
F00E507C: 2280000e                 be,a    loc_F00E50B4
F00E5080: 90102001                 mov     1, %o0
F00E5084: 0480000b                 ble     loc_F00E50B0
F00E5088: 80a22004                 cmp     %o0, 4
F00E508C: 02800004                 be      loc_F00E509C
F00E5090: 90100019                 mov     %i1, %o0
F00E5094: 10800008                 ba      loc_F00E50B4
F00E5098: 90102480                 mov     0x480, %o0
F00E509C: 92100010                 mov     %l0, %o1
F00E50A0: 7fff27d9                 call    _prom_getprop
F00E50A4: 9407bfd4                 add     %fp, var_2C, %o2
F00E50A8: 10800003                 ba      loc_F00E50B4
F00E50AC: d007bfd4                 ld      [%fp+var_2C], %o0
F00E50B0: 90102480                 mov     0x480, %o0
F00E50B4: d0262020                 st      %o0, [%i0+0x20]
F00E50B8: 90100019                 mov     %i1, %o0
F00E50BC: 133c03f2a01262e8         set     aHeight, %l0! "height"
F00E50C4: 7fff27c6                 call    _prom_getproplen
F00E50C8: 92100010                 mov     %l0, %o1
F00E50CC: 80a22000                 cmp     %o0, 0
F00E50D0: 2280000e                 be,a    loc_F00E5108
F00E50D4: 90102001                 mov     1, %o0
F00E50D8: 0480000b                 ble     loc_F00E5104
F00E50DC: 80a22004                 cmp     %o0, 4
F00E50E0: 02800004                 be      loc_F00E50F0
F00E50E4: 90100019                 mov     %i1, %o0
F00E50E8: 10800008                 ba      loc_F00E5108
F00E50EC: 90102384                 mov     0x384, %o0
F00E50F0: 92100010                 mov     %l0, %o1
F00E50F4: 7fff27c4                 call    _prom_getprop
F00E50F8: 9407bfd4                 add     %fp, var_2C, %o2
F00E50FC: 10800003                 ba      loc_F00E5108
F00E5100: d007bfd4                 ld      [%fp+var_2C], %o0
F00E5104: 90102384                 mov     0x384, %o0
F00E5108: d0262024                 st      %o0, [%i0+0x24]
F00E510C: d007bff4                 ld      [%fp+var_C], %o0
F00E5110: d0262014                 st      %o0, [%i0+0x14]
F00E5114: d007bff4                 ld      [%fp+var_C], %o0
F00E5118: d0262018                 st      %o0, [%i0+0x18]
F00E511C: d007bff0                 ld      [%fp+var_10], %o0
F00E5120: d026200c                 st      %o0, [%i0+0xC]
F00E5124: d0062020                 ld      [%i0+0x20], %o0
F00E5128: d2062024                 ld      [%i0+0x24], %o1
F00E512C: 7ffc84f5                 call    _umul
F00E5130: 01000000                 nop
F00E5134: d026201c                 st      %o0, [%i0+0x1C]
F00E5138: 90102008                 mov     8, %o0
F00E513C: d0262030                 st      %o0, [%i0+0x30]
F00E5140: 90102001                 mov     1, %o0
F00E5144: d0262034                 st      %o0, [%i0+0x34]
F00E5148: d0062020                 ld      [%i0+0x20], %o0
F00E514C: d2062034                 ld      [%i0+0x34], %o1
F00E5150: 7ffc84ec                 call    _umul
F00E5154: 01000000                 nop
F00E5158: d0262038                 st      %o0, [%i0+0x38]
F00E515C: 81c7e008                 ret
F00E5160: 91e82000                 restore %g0, 0, %o0
