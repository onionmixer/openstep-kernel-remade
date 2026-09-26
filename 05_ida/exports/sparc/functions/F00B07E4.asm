F00B07E4: 9de3bf98                 save    %sp, -0x68, %sp
F00B07E8: e0062028                 ld      [%i0+0x28], %l0
F00B07EC: 133c047192126080         set     aName_1, %o1! "name"
F00B07F4: 40000249                 call    _getlongprop
F00B07F8: 90100010                 mov     %l0, %o0
F00B07FC: 92100008                 mov     %o0, %o1! __s2
F00B0800: d226200c                 st      %o1, [%i0+0xC]
F00B0804: 113c0471                 sethi   %hi(aZs_1), %o0! "zs"
F00B0808: 7ffd5e69                 call    _strcmp
F00B080C: 90122088                 bset    %lo(aZs_1), %o0! "zs"
F00B0810: 80a22000                 cmp     %o0, 0
F00B0814: 12800008                 bne     loc_F00B0834
F00B0818: 90100010                 mov     %l0, %o0
F00B081C: 113c0471                 sethi   %hi(dword_F011C478), %o0
F00B0820: d4022078                 ld      [%o0+%lo(dword_F011C478)], %o2
F00B0824: 9202a001                 add     %o2, 1, %o1
F00B0828: d2222078                 st      %o1, [%o0+%lo(dword_F011C478)]
F00B082C: d426202c                 st      %o2, [%i0+0x2C]
F00B0830: 90100010                 mov     %l0, %o0
F00B0834: 133c0471                 sethi   %hi(aIntr), %o1! "intr"
F00B0838: 40000232                 call    _getproplen
F00B083C: 92126090                 bset    %lo(aIntr), %o1! "intr"
F00B0840: 80a22000                 cmp     %o0, 0
F00B0844: 04800007                 ble     loc_F00B0860
F00B0848: 91322003                 srl     %o0, 3, %o0
F00B084C: d0262018                 st      %o0, [%i0+0x18]
F00B0850: 90100010                 mov     %l0, %o0
F00B0854: 133c0471                 sethi   %hi(aIntr_0), %o1! "intr"
F00B0858: 1080000d                 ba      loc_F00B088C
F00B085C: 92126098                 bset    %lo(aIntr_0), %o1! "intr"
F00B0860: 90100010                 mov     %l0, %o0
F00B0864: 133c0471                 sethi   %hi(aInterrupts_0), %o1! "interrupts"
F00B0868: 40000226                 call    _getproplen
F00B086C: 921260a0                 bset    %lo(aInterrupts_0), %o1! "interrupts"
F00B0870: 80a22000                 cmp     %o0, 0
F00B0874: 04800009                 ble     loc_F00B0898
F00B0878: 91322003                 srl     %o0, 3, %o0
F00B087C: d0262018                 st      %o0, [%i0+0x18]
F00B0880: 90100010                 mov     %l0, %o0
F00B0884: 133c0471921260b0         set     aInterrupts_1, %o1! "interrupts"
F00B088C: 40000223                 call    _getlongprop
F00B0890: 01000000                 nop
F00B0894: d026201c                 st      %o0, [%i0+0x1C]
F00B0898: 90100010                 mov     %l0, %o0
F00B089C: 133c0471                 sethi   %hi(aReg_0), %o1! "reg"
F00B08A0: 40000218                 call    _getproplen
F00B08A4: 921260c0                 bset    %lo(aReg_0), %o1! "reg"
F00B08A8: 80a22000                 cmp     %o0, 0
F00B08AC: 2480001c                 ble,a   loc_F00B091C
F00B08B0: 90100010                 mov     %l0, %o0
F00B08B4: 7ffd5753                 call    _udiv
F00B08B8: 9210200c                 mov     0xC, %o1
F00B08BC: 80a22000                 cmp     %o0, 0
F00B08C0: 04800016                 ble     loc_F00B0918
F00B08C4: d0262010                 st      %o0, [%i0+0x10]
F00B08C8: 90100010                 mov     %l0, %o0
F00B08CC: 133c0471                 sethi   %hi(aReg_1), %o1! "reg"
F00B08D0: 40000212                 call    _getlongprop
F00B08D4: 921260c8                 bset    %lo(aReg_1), %o1! "reg"
F00B08D8: 98100008                 mov     %o0, %o4
F00B08DC: d4060000                 ld      [%i0], %o2
F00B08E0: 80a2a000                 cmp     %o2, 0
F00B08E4: 0280000d                 be      loc_F00B0918
F00B08E8: d8262014                 st      %o4, [%i0+0x14]
F00B08EC: d202a030                 ld      [%o2+0x30], %o1
F00B08F0: 80a26000                 cmp     %o1, 0
F00B08F4: 0480000a                 ble     loc_F00B091C
F00B08F8: 90100010                 mov     %l0, %o0
F00B08FC: d402a034                 ld      [%o2+0x34], %o2
F00B0900: 80a2a000                 cmp     %o2, 0
F00B0904: 22800007                 be,a    loc_F00B0920
F00B0908: 133c0471                 sethi   -0xFEE3C00, %o1
F00B090C: d006200c                 ld      [%i0+0xC], %o0
F00B0910: 7fffff5c                 call    _apply_range_to_reg
F00B0914: d6062010                 ld      [%i0+0x10], %o3
F00B0918: 90100010                 mov     %l0, %o0
F00B091C: 133c0471                 sethi   -0xFEE3C00, %o1
F00B0920: 400001f8                 call    _getproplen
F00B0924: 921260d0                 bset    0xD0, %o1
F00B0928: 80a22000                 cmp     %o0, 0
F00B092C: 24800022                 ble,a   loc_F00B09B4
F00B0930: d0060000                 ld      [%i0], %o0
F00B0934: 7ffd5733                 call    _udiv
F00B0938: 92102014                 mov     0x14, %o1
F00B093C: 80a22000                 cmp     %o0, 0
F00B0940: 04800017                 ble     loc_F00B099C
F00B0944: d0262030                 st      %o0, [%i0+0x30]
F00B0948: 90100010                 mov     %l0, %o0
F00B094C: 133c0471                 sethi   %hi(aRanges_1), %o1! "ranges"
F00B0950: 400001f2                 call    _getlongprop
F00B0954: 921260d8                 bset    %lo(aRanges_1), %o1! "ranges"
F00B0958: 98100008                 mov     %o0, %o4
F00B095C: d4060000                 ld      [%i0], %o2
F00B0960: 80a2a000                 cmp     %o2, 0
F00B0964: 0280001e                 be      locret_F00B09DC
F00B0968: d8262034                 st      %o4, [%i0+0x34]
F00B096C: d202a030                 ld      [%o2+0x30], %o1
F00B0970: 80a26000                 cmp     %o1, 0
F00B0974: 0480001a                 ble     locret_F00B09DC
F00B0978: 01000000                 nop
F00B097C: d402a034                 ld      [%o2+0x34], %o2
F00B0980: 80a2a000                 cmp     %o2, 0
F00B0984: 02800016                 be      locret_F00B09DC
F00B0988: 01000000                 nop
F00B098C: d006200c                 ld      [%i0+0xC], %o0
F00B0990: 7fffff69                 call    _apply_range_to_range
F00B0994: d6062030                 ld      [%i0+0x30], %o3
F00B0998: 30800011                 ba,a    locret_F00B09DC
F00B099C: d0060000                 ld      [%i0], %o0
F00B09A0: 80a22000                 cmp     %o0, 0
F00B09A4: 32800008                 bne,a   loc_F00B09C4
F00B09A8: d0022030                 ld      [%o0+0x30], %o0
F00B09AC: 1080000b                 ba      loc_F00B09D8
F00B09B0: c0262030                 clr     [%i0+0x30]
F00B09B4: 80a22000                 cmp     %o0, 0
F00B09B8: 22800008                 be,a    loc_F00B09D8
F00B09BC: c0262030                 clr     [%i0+0x30]
F00B09C0: d0022030                 ld      [%o0+0x30], %o0
F00B09C4: d2060000                 ld      [%i0], %o1
F00B09C8: d0262030                 st      %o0, [%i0+0x30]
F00B09CC: d0026034                 ld      [%o1+0x34], %o0
F00B09D0: 10800003                 ba      locret_F00B09DC
F00B09D4: d0262034                 st      %o0, [%i0+0x34]
F00B09D8: c0262034                 clr     [%i0+0x34]
F00B09DC: 81c7e008                 ret
F00B09E0: 81e80000                 restore
