F0021280: 9de3bf88                 save    %sp, -0x78, %sp
F0021284: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0021288: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F002128C: e0022024                 ld      [%o0+0x24], %l0
F0021290: 40000450                 call    _getsock
F0021294: d0040000                 ld      [%l0], %o0
F0021298: 80a22000                 cmp     %o0, 0
F002129C: 02800054                 be      locret_F00213EC
F00212A0: 01000000                 nop
F00212A4: d0022018                 ld      [%o0+0x18], %o0
F00212A8: d027bfec                 st      %o0, [%fp+var_14]
F00212AC: d0022004                 ld      [%o0+4], %o0
F00212B0: 900a2104                 and     %o0, 0x104, %o0
F00212B4: 80a22104                 cmp     %o0, 0x104
F00212B8: 32800006                 bne,a   loc_F00212D0
F00212BC: d2042004                 ld      [%l0+4], %o1
F00212C0: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F00212C4: 90102025                 mov     0x25, %o0 ! '%'
F00212C8: 10800049                 ba      locret_F00213EC
F00212CC: d02a6038                 stb     %o0, [%o1+0x38]
F00212D0: 9007bff4                 add     %fp, var_C, %o0
F00212D4: d4042008                 ld      [%l0+8], %o2
F00212D8: 40000424                 call    _sockargs
F00212DC: 96102008                 mov     8, %o3
F00212E0: d20461dc                 ld      [%l1+0x1DC], %o1
F00212E4: d02a6038                 stb     %o0, [%o1+0x38]
F00212E8: d00461dc                 ld      [%l1+0x1DC], %o0
F00212EC: d04a2038                 ldsb    [%o0+0x38], %o0
F00212F0: 80a22000                 cmp     %o0, 0
F00212F4: 1280003e                 bne     locret_F00213EC
F00212F8: d207bff4                 ld      [%fp+var_C], %o1
F00212FC: 7ffff5cb                 call    _soconnect
F0021300: d007bfec                 ld      [%fp+var_14], %o0
F0021304: d20461dc                 ld      [%l1+0x1DC], %o1
F0021308: d02a6038                 stb     %o0, [%o1+0x38]
F002130C: d20461dc                 ld      [%l1+0x1DC], %o1
F0021310: d04a6038                 ldsb    [%o1+0x38], %o0
F0021314: 80a22000                 cmp     %o0, 0
F0021318: 1280002f                 bne     loc_F00213D4
F002131C: d807bfec                 ld      [%fp+var_14], %o4
F0021320: d0032004                 ld      [%o4+4], %o0
F0021324: 900a2104                 and     %o0, 0x104, %o0
F0021328: 80a22104                 cmp     %o0, 0x104
F002132C: 12800006                 bne     loc_F0021344
F0021330: 01000000                 nop
F0021334: 90102024                 mov     0x24, %o0 ! '$'
F0021338: d02a6038                 stb     %o0, [%o1+0x38]
F002133C: 1080002a                 ba      loc_F00213E4
F0021340: d007bff4                 ld      [%fp+var_C], %o0! jmp_buf
F0021344: 4001d654                 call    _splnet
F0021348: 01000000                 nop
F002134C: d20461dc                 ld      [%l1+0x1DC], %o1
F0021350: d027bff0                 st      %o0, [%fp+var_10]
F0021354: 4001d680                 call    _setjmp
F0021358: 90026028                 add     %o1, 0x28, %o0 ! '('
F002135C: 80a22000                 cmp     %o0, 0
F0021360: 0280000b                 be      loc_F002138C
F0021364: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0021368: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F002136C: d04a6038                 ldsb    [%o1+0x38], %o0
F0021370: 80a22000                 cmp     %o0, 0
F0021374: 12800015                 bne     loc_F00213C8
F0021378: 90102004                 mov     4, %o0! unsigned int
F002137C: 10800013                 ba      loc_F00213C8
F0021380: d02a6038                 stb     %o0, [%o1+0x38]
F0021384: 7fffc4bd                 call    _sleep
F0021388: 90032054                 add     %o4, 0x54, %o0 ! 'T'
F002138C: d807bfec                 ld      [%fp+var_14], %o4
F0021390: d0132006                 lduh    [%o4+6], %o0
F0021394: 808a2004                 btst    4, %o0
F0021398: 02800008                 be      loc_F00213B8
F002139C: 113c04cf                 sethi   -0xFECC400, %o0
F00213A0: d0132056                 lduh    [%o4+0x56], %o0
F00213A4: 80a22000                 cmp     %o0, 0
F00213A8: 02bffff7                 be      loc_F0021384
F00213AC: 9210201a                 mov     0x1A, %o1
F00213B0: d807bfec                 ld      [%fp+var_14], %o4
F00213B4: 113c04cf                 sethi   -0xFECC400, %o0
F00213B8: d20221dc                 ld      [%o0+0x1DC], %o1
F00213BC: d0132056                 lduh    [%o4+0x56], %o0
F00213C0: d02a6038                 stb     %o0, [%o1+0x38]
F00213C4: c0332056                 clrh    [%o4+0x56]
F00213C8: 4001d657                 call    _splx
F00213CC: d007bff0                 ld      [%fp+var_10], %o0
F00213D0: d807bfec                 ld      [%fp+var_14], %o4
F00213D4: d2132006                 lduh    [%o4+6], %o1
F00213D8: d007bff4                 ld      [%fp+var_C], %o0
F00213DC: 920a7ffb                 and     %o1, -5, %o1
F00213E0: d2332006                 sth     %o1, [%o4+6]
F00213E4: 7ffff220                 call    _m_freem
F00213E8: 01000000                 nop
F00213EC: 81c7e008                 ret
F00213F0: 81e80000                 restore
