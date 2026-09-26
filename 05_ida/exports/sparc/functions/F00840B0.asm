F00840B0: 9de3bf98                 save    %sp, -0x68, %sp
F00840B4: 113c04f4                 sethi   %hi(_vm_map_zone), %o0
F00840B8: d0022388                 ld      [%o0+%lo(_vm_map_zone)], %o0
F00840BC: 7fffd404                 call    _zalloc
F00840C0: a0100018                 mov     %i0, %l0
F00840C4: b0920000                 orcc    %o0, %g0, %i0
F00840C8: 32800006                 bne,a   loc_F00840E0
F00840CC: 9206200c                 add     %i0, 0xC, %o1
F00840D0: 113c0446                 sethi   %hi(aVmMapCreate), %o0! "vm_map_create"
F00840D4: 7ffe4427                 call    _panic
F00840D8: 90122260                 bset    %lo(aVmMapCreate), %o0! "vm_map_create"
F00840DC: 9206200c                 add     %i0, 0xC, %o1
F00840E0: d2262010                 st      %o1, [%i0+0x10]
F00840E4: d226200c                 st      %o1, [%i0+0xC]
F00840E8: c026201c                 clr     [%i0+0x1C]
F00840EC: f6262020                 st      %i3, [%i0+0x20]
F00840F0: c0262028                 clr     [%i0+0x28]
F00840F4: 90102001                 mov     1, %o0
F00840F8: d0262030                 st      %o0, [%i0+0x30]
F00840FC: e0262024                 st      %l0, [%i0+0x24]
F0084100: d026202c                 st      %o0, [%i0+0x2C]
F0084104: f2262014                 st      %i1, [%i0+0x14]
F0084108: f4262018                 st      %i2, [%i0+0x18]
F008410C: c0262048                 clr     [%i0+0x48]
F0084110: c0262044                 clr     [%i0+0x44]
F0084114: d2262040                 st      %o1, [%i0+0x40]
F0084118: d2262038                 st      %o1, [%i0+0x38]
F008411C: c026204c                 clr     [%i0+0x4C]
F0084120: 90100018                 mov     %i0, %o0
F0084124: 7fff92f9                 call    _lock_init
F0084128: 92102001                 mov     1, %o1
F008412C: c026204c                 clr     [%i0+0x4C]
F0084130: c0262034                 clr     [%i0+0x34]
F0084134: c026203c                 clr     [%i0+0x3C]
F0084138: 81c7e008                 ret
F008413C: 81e80000                 restore
