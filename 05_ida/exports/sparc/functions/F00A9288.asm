F00A9288: 9de3bf88                 save    %sp, -0x78, %sp
F00A928C: 113c04d4                 sethi   %hi(_panicstr), %o0
F00A9290: d0022228                 ld      [%o0+%lo(_panicstr)], %o0
F00A9294: 80a22000                 cmp     %o0, 0
F00A9298: 02800009                 be      loc_F00A92BC
F00A929C: 808e2007                 btst    7, %i0
F00A92A0: 113c046f                 sethi   %hi(dword_F011BC7C), %o0
F00A92A4: d402207c                 ld      [%o0+%lo(dword_F011BC7C)], %o2
F00A92A8: 9202a001                 add     %o2, 1, %o1
F00A92AC: 80a2a000                 cmp     %o2, 0
F00A92B0: 14800049                 bg      locret_F00A93D4
F00A92B4: d222207c                 st      %o1, [%o0+%lo(dword_F011BC7C)]
F00A92B8: 808e2007                 btst    7, %i0
F00A92BC: 0280000b                 be      loc_F00A92E8
F00A92C0: 113c046f                 sethi   %hi(aTracebackMisal), %o0! "traceback: misaligned sp = %x\n"
F00A92C4: 90122080                 bset    %lo(aTracebackMisal), %o0! "traceback: misaligned sp = %x\n"
F00A92C8: 7ffdace4                 call    _printf
F00A92CC: 92100018                 mov     %i0, %o1
F00A92D0: 30800041                 ba,a    locret_F00A93D4
F00A92D4: 901220c0                 bset    0xC0, %o0! char *
F00A92D8: 7ffdace0                 call    _printf
F00A92DC: 92100018                 mov     %i0, %o1
F00A92E0: 10800034                 ba      loc_F00A93B0
F00A92E4: 113c046f                 sethi   -0xFEE4400, %o0
F00A92E8: 7ffd6eec                 call    _flush_windows
F00A92EC: a0063fff                 add     %i0, -1, %l0
F00A92F0: 113c046f901220a0         set     aBeginTraceback, %o0! "Begin traceback... sp = %x\n"
F00A92F8: 92100018                 mov     %i0, %o1
F00A92FC: 253c0447                 sethi   %hi(_page_size), %l2
F00A9300: d404a13c                 ld      [%l2+%lo(_page_size)], %o2
F00A9304: 233c04f4                 sethi   %hi(_page_shift), %l1
F00A9308: d6046348                 ld      [%l1+%lo(_page_shift)], %o3
F00A930C: 9404000a                 add     %l0, %o2, %o2
F00A9310: 7ffdacd2                 call    _printf
F00A9314: a732800b                 srl     %o2, %o3, %l3
F00A9318: d004a13c                 ld      [%l2+%lo(_page_size)], %o0
F00A931C: d2046348                 ld      [%l1+%lo(_page_shift)], %o1
F00A9320: a0040008                 add     %l0, %o0, %l0
F00A9324: a1340009                 srl     %l0, %o1, %l0
F00A9328: 80a40013                 cmp     %l0, %l3
F00A932C: 12800021                 bne     loc_F00A93B0
F00A9330: 113c046f                 sethi   -0xFEE4400, %o0
F00A9334: 293c046f                 sethi   -0xFEE4400, %l4
F00A9338: a0100011                 mov     %l1, %l0
F00A933C: c4062038                 ld      [%i0+0x38], %g2
F00A9340: 80a60002                 cmp     %i0, %g2
F00A9344: 02bfffe4                 be      loc_F00A92D4
F00A9348: 113c046f                 sethi   -0xFEE4400, %o0
F00A934C: d206203c                 ld      [%i0+0x3C], %o1
F00A9350: d6062020                 ld      [%i0+0x20], %o3
F00A9354: d8062024                 ld      [%i0+0x24], %o4
F00A9358: d006202c                 ld      [%i0+0x2C], %o0
F00A935C: da062028                 ld      [%i0+0x28], %o5
F00A9360: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F00A9364: d4062030                 ld      [%i0+0x30], %o2
F00A9368: d423a060                 st      %o2, [%sp+0x78+var_18]
F00A936C: d4062034                 ld      [%i0+0x34], %o2
F00A9370: 901520d0                 or      %l4, 0xD0, %o0! char *
F00A9374: d423a064                 st      %o2, [%sp+0x78+var_14]
F00A9378: 7ffdacb8                 call    _printf
F00A937C: 94100002                 mov     %g2, %o2
F00A9380: f0062038                 ld      [%i0+0x38], %i0
F00A9384: 80a62000                 cmp     %i0, 0
F00A9388: 02800009                 be      loc_F00A93AC
F00A938C: 92063fff                 add     %i0, -1, %o1
F00A9390: d004a13c                 ld      [%l2+0x13C], %o0
F00A9394: d4042348                 ld      [%l0+0x348], %o2
F00A9398: 92024008                 add     %o1, %o0, %o1
F00A939C: 9332400a                 srl     %o1, %o2, %o1
F00A93A0: 80a24013                 cmp     %o1, %l3
F00A93A4: 22bfffe7                 be,a    loc_F00A9340
F00A93A8: c4062038                 ld      [%i0+0x38], %g2
F00A93AC: 113c046f                 sethi   -0xFEE4400, %o0! char *
F00A93B0: 7ffdacaa                 call    _printf
F00A93B4: 90122100                 bset    0x100, %o0
F00A93B8: 113c042d                 sethi   %hi(_pmsgbuf), %o0
F00A93BC: d002208c                 ld      [%o0+%lo(_pmsgbuf)], %o0
F00A93C0: 7fffb17a                 call    _vac_flush
F00A93C4: 13000004                 sethi   0x1000, %o1
F00A93C8: 110007a1                 sethi   0x1E8400, %o0
F00A93CC: 7fffb925                 call    _us_spin
F00A93D0: 90122080                 bset    0x80, %o0
F00A93D4: 81c7e008                 ret
F00A93D8: 81e80000                 restore
