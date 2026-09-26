F00717FC: 9de3bf98                 save    %sp, -0x68, %sp
F0071800: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0071804: d0040000                 ld      [%l0], %o0
F0071808: 80a22000                 cmp     %o0, 0
F007180C: 12bffffe                 bne     loc_F0071804
F0071810: 01000000                 nop
F0071814: 400095a5                 call    _simple_lock_try
F0071818: 90100010                 mov     %l0, %o0
F007181C: 80a22000                 cmp     %o0, 0
F0071820: 02bffff9                 be      loc_F0071804
F0071824: 01000000                 nop
F0071828: d0062034                 ld      [%i0+0x34], %o0
F007182C: 80a22000                 cmp     %o0, 0
F0071830: 02800006                 be      loc_F0071848
F0071834: 90100018                 mov     %i0, %o0
F0071838: d206204c                 ld      [%i0+0x4C], %o1
F007183C: 92126100                 bset    0x100, %o1
F0071840: 7fffdced                 call    _stack_free
F0071844: d226204c                 st      %o1, [%i0+0x4C]
F0071848: d006204c                 ld      [%i0+0x4C], %o0
F007184C: 900a3cff                 and     %o0, -0x301, %o0
F0071850: 80a2200c                 cmp     %o0, 0xC
F0071854: 22800030                 be,a    loc_F0071914
F0071858: 90100018                 mov     %i0, %o0
F007185C: 14800010                 bg      loc_F007189C
F0071860: 80a2200f                 cmp     %o0, 0xF
F0071864: 80a22005                 cmp     %o0, 5
F0071868: 2280002f                 be,a    loc_F0071924
F007186C: d006204c                 ld      [%i0+0x4C], %o0
F0071870: 14800007                 bg      loc_F007188C
F0071874: 80a22007                 cmp     %o0, 7
F0071878: 80a22004                 cmp     %o0, 4
F007187C: 22800026                 be,a    loc_F0071914
F0071880: 90100018                 mov     %i0, %o0
F0071884: 1080002b                 ba      loc_F0071930
F0071888: 113c0441                 sethi   -0xFEEFC00, %o0
F007188C: 14800029                 bg      loc_F0071930
F0071890: 113c0441                 sethi   -0xFEEFC00, %o0
F0071894: 10800014                 ba      loc_F00718E4
F0071898: d006204c                 ld      [%i0+0x4C], %o0
F007189C: 02800021                 be      loc_F0071920
F00718A0: 80a2200f                 cmp     %o0, 0xF
F00718A4: 14800009                 bg      loc_F00718C8
F00718A8: 80a22016                 cmp     %o0, 0x16
F00718AC: 80a2200d                 cmp     %o0, 0xD
F00718B0: 0280001c                 be      loc_F0071920
F00718B4: 80a2200e                 cmp     %o0, 0xE
F00718B8: 22800017                 be,a    loc_F0071914
F00718BC: 90100018                 mov     %i0, %o0
F00718C0: 1080001c                 ba      loc_F0071930
F00718C4: 113c0441                 sethi   -0xFEEFC00, %o0
F00718C8: 02800006                 be      loc_F00718E0
F00718CC: 80a22084                 cmp     %o0, 0x84
F00718D0: 0280001a                 be      loc_F0071938
F00718D4: 01000000                 nop
F00718D8: 10800016                 ba      loc_F0071930
F00718DC: 113c0441                 sethi   -0xFEEFC00, %o0
F00718E0: d006204c                 ld      [%i0+0x4C], %o0
F00718E4: d2062048                 ld      [%i0+0x48], %o1
F00718E8: 900a3ffb                 and     %o0, -5, %o0
F00718EC: 80a26000                 cmp     %o1, 0
F00718F0: 02800012                 be      loc_F0071938
F00718F4: d026204c                 st      %o0, [%i0+0x4C]
F00718F8: c0262048                 clr     [%i0+0x48]
F00718FC: c0262020                 clr     [%i0+0x20]
F0071900: 90062048                 add     %i0, 0x48, %o0 ! 'H'
F0071904: 92102000                 mov     0, %o1
F0071908: 7ffffdbd                 call    _thread_wakeup_prim
F007190C: 94102000                 mov     0, %o2
F0071910: 3080000b                 ba,a    locret_F007193C
F0071914: 400000e3                 call    _thread_setrun
F0071918: 92102000                 mov     0, %o1
F007191C: 30800007                 ba,a    loc_F0071938
F0071920: d006204c                 ld      [%i0+0x4C], %o0
F0071924: 900a3ffb                 and     %o0, -5, %o0! char *
F0071928: 10800004                 ba      loc_F0071938
F007192C: d026204c                 st      %o0, [%i0+0x4C]
F0071930: 7ffe8e10                 call    _panic
F0071934: 90122028                 bset    0x28, %o0 ! '('
F0071938: c0262020                 clr     [%i0+0x20]
F007193C: 81c7e008                 ret
F0071940: 81e80000                 restore
