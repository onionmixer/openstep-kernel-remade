F0072110: 9de3bf98                 save    %sp, -0x68, %sp
F0072114: b4102000                 mov     0, %i2
F0072118: 333c04d4b01660c8         set     unk_F01350C8, %i0
F0072120: 113c04cfaa122160         set     _need_ast, %l5
F0072128: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F007212C: e40221b0                 ld      [%o0+%lo(_processor_ptr)], %l2
F0072130: a8102000                 mov     0, %l4
F0072134: a604a118                 add     %l2, 0x118, %l3
F0072138: ac04a108                 add     %l2, 0x108, %l6
F007213C: 400089e4                 call    _PMSetCpuState
F0072140: 90102000                 mov     0, %o0
F0072144: d004c000                 ld      [%l3], %o0
F0072148: 80a22000                 cmp     %o0, 0
F007214C: 1280001c                 bne     loc_F00721BC
F0072150: 01000000                 nop
F0072154: d00660c8                 ld      [%i1+0xC8], %o0
F0072158: 10800013                 ba      loc_F00721A4
F007215C: 80a22000                 cmp     %o0, 0
F0072160: d0050015                 ld      [%l4+%l5], %o0
F0072164: 808a3ff8                 btst    -8, %o0
F0072168: 02800009                 be      loc_F007218C
F007216C: 01000000                 nop
F0072170: 40009286                 call    _splusclock
F0072174: 01000000                 nop
F0072178: d0050015                 ld      [%l4+%l5], %o0
F007217C: 900a3ff8                 and     %o0, -8, %o0
F0072180: d0250015                 st      %o0, [%l4+%l5]
F0072184: 400092d7                 call    _spl0
F0072188: 01000000                 nop
F007218C: d004c000                 ld      [%l3], %o0
F0072190: 80a22000                 cmp     %o0, 0
F0072194: 1280000a                 bne     loc_F00721BC
F0072198: 01000000                 nop
F007219C: d0060000                 ld      [%i0], %o0
F00721A0: 80a22000                 cmp     %o0, 0
F00721A4: 12800006                 bne     loc_F00721BC
F00721A8: 01000000                 nop
F00721AC: d0058000                 ld      [%l6], %o0
F00721B0: 80a22000                 cmp     %o0, 0
F00721B4: 02bfffeb                 be      loc_F0072160
F00721B8: 01000000                 nop
F00721BC: 400089c4                 call    _PMSetCpuState
F00721C0: 90102001                 mov     1, %o0
F00721C4: 40009271                 call    _splusclock
F00721C8: 01000000                 nop
F00721CC: ae100008                 mov     %o0, %l7
F00721D0: d004a114                 ld      [%l2+0x114], %o0
F00721D4: 80a22003                 cmp     %o0, 3
F00721D8: 12800014                 bne     loc_F0072228
F00721DC: 80a22002                 cmp     %o0, 2
F00721E0: d204c000                 ld      [%l3], %o1
F00721E4: 90102001                 mov     1, %o0
F00721E8: c024c000                 clr     [%l3]
F00721EC: d024a114                 st      %o0, [%l2+0x114]
F00721F0: d0026060                 ld      [%o1+0x60], %o0
F00721F4: 80a22002                 cmp     %o0, 2
F00721F8: 02800004                 be      loc_F0072208
F00721FC: 113c04d4                 sethi   %hi(dword_F013512C), %o0
F0072200: 10800003                 ba      loc_F007220C
F0072204: d002212c                 ld      [%o0+%lo(dword_F013512C)], %o0
F0072208: d002605c                 ld      [%o1+0x5C], %o0
F007220C: d024a120                 st      %o0, [%l2+0x120]
F0072210: 90102001                 mov     1, %o0
F0072214: d024a124                 st      %o0, [%l2+0x124]
F0072218: 113c01c8                 sethi   %hi(_idle_thread_continue), %o0
F007221C: 7ffffd62                 call    _thread_run
F0072220: 90122110                 bset    %lo(_idle_thread_continue), %o0
F0072224: 30800046                 ba,a    loc_F007233C
F0072228: 1280002c                 bne     loc_F00722D8
F007222C: 90023ffc                 inc     -4, %o0
F0072230: e204a12c                 ld      [%l2+0x12C], %l1
F0072234: a0046118                 add     %l1, 0x118, %l0
F0072238: d0040000                 ld      [%l0], %o0
F007223C: 80a22000                 cmp     %o0, 0
F0072240: 12bffffe                 bne     loc_F0072238
F0072244: 01000000                 nop
F0072248: 40009318                 call    _simple_lock_try
F007224C: 90100010                 mov     %l0, %o0
F0072250: 80a22000                 cmp     %o0, 0
F0072254: 02bffff9                 be      loc_F0072238
F0072258: 01000000                 nop
F007225C: d004a114                 ld      [%l2+0x114], %o0
F0072260: 80a22002                 cmp     %o0, 2
F0072264: 02800005                 be      loc_F0072278
F0072268: 153c0441                 sethi   -0xFEEFC00, %o2
F007226C: c0246118                 clr     [%l1+0x118]
F0072270: 10bfffd9                 ba      loc_F00721D4
F0072274: d004a114                 ld      [%l2+0x114], %o0
F0072278: d002a184                 ld      [%o2+0x184], %o0
F007227C: d2046114                 ld      [%l1+0x114], %o1
F0072280: 90022001                 inc     %o0
F0072284: d022a184                 st      %o0, [%o2+0x184]
F0072288: 92027fff                 inc     -1, %o1
F007228C: d2246114                 st      %o1, [%l1+0x114]
F0072290: d404a10c                 ld      [%l2+0x10C], %o2
F0072294: 9004610c                 add     %l1, 0x10C, %o0
F0072298: 80a2000a                 cmp     %o0, %o2
F007229C: 12800004                 bne     loc_F00722AC
F00722A0: d204a110                 ld      [%l2+0x110], %o1
F00722A4: 10800004                 ba      loc_F00722B4
F00722A8: d2246110                 st      %o1, [%l1+0x110]
F00722AC: d222a110                 st      %o1, [%o2+0x110]
F00722B0: 9004610c                 add     %l1, 0x10C, %o0
F00722B4: 80a20009                 cmp     %o0, %o1
F00722B8: 22800003                 be,a    loc_F00722C4
F00722BC: d424610c                 st      %o2, [%l1+0x10C]
F00722C0: d422610c                 st      %o2, [%o1+0x10C]
F00722C4: 90102001                 mov     1, %o0
F00722C8: d024a114                 st      %o0, [%l2+0x114]
F00722CC: c0246118                 clr     [%l1+0x118]
F00722D0: 1080000e                 ba      loc_F0072308
F00722D4: 113c01c8                 sethi   -0xFF8E000, %o0
F00722D8: 80a22001                 cmp     %o0, 1
F00722DC: 3880000e                 bgu,a   loc_F0072314
F00722E0: 113c0441                 sethi   -0xFEEFC00, %o0
F00722E4: d204c000                 ld      [%l3], %o1
F00722E8: 80a26000                 cmp     %o1, 0
F00722EC: 02800007                 be      loc_F0072308
F00722F0: 113c01c8                 sethi   -0xFF8E000, %o0
F00722F4: c024c000                 clr     [%l3]
F00722F8: 90100009                 mov     %o1, %o0
F00722FC: 7ffffe69                 call    _thread_setrun
F0072300: 92102000                 mov     0, %o1
F0072304: 113c01c8                 sethi   -0xFF8E000, %o0
F0072308: 7ffffd0e                 call    _thread_block_with_continuation
F007230C: 90122110                 bset    0x110, %o0
F0072310: 3080000b                 ba,a    loc_F007233C
F0072314: 133c04d2921261b0         set     _processor_ptr, %o1
F007231C: d2050009                 ld      [%l4+%o1], %o1
F0072320: 90122188                 bset    0x188, %o0! char *
F0072324: d2026114                 ld      [%o1+0x114], %o1
F0072328: 7ffe88cc                 call    _printf
F007232C: 9410001a                 mov     %i2, %o2
F0072330: 113c0441                 sethi   %hi(aIdleThread), %o0! "idle_thread"
F0072334: 7ffe8b8f                 call    _panic
F0072338: 901221b0                 bset    %lo(aIdleThread), %o0! "idle_thread"
F007233C: 4000927a                 call    _splx
F0072340: 90100017                 mov     %l7, %o0
F0072344: 30bfff7e                 ba,a    loc_F007213C
