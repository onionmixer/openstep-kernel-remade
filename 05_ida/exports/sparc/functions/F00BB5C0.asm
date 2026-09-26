F00BB5C0: 9de3bf98                 save    %sp, -0x68, %sp
F00BB5C4: 113c047f901220a8         set     aCgfourteen_0, %o0! "cgfourteen"
F00BB5CC: 92100018                 mov     %i0, %o1! __s2
F00BB5D0: 153c047f                 sethi   %hi(aSunwCgfourteen), %o2! "SUNW,cgfourteen"
F00BB5D4: 7ffd32f6                 call    _strcmp
F00BB5D8: a012a098                 or      %o2, %lo(aSunwCgfourteen), %l0! "SUNW,cgfourteen"
F00BB5DC: 80a22000                 cmp     %o0, 0
F00BB5E0: 02800007                 be      loc_F00BB5FC
F00BB5E4: 90100010                 mov     %l0, %o0! __s1
F00BB5E8: 7ffd32f1                 call    _strcmp
F00BB5EC: 92100018                 mov     %i0, %o1
F00BB5F0: 80a22000                 cmp     %o0, 0
F00BB5F4: 3280000a                 bne,a   locret_F00BB61C
F00BB5F8: b0102000                 mov     0, %i0
F00BB5FC: 113c047f901220b8         set     aSIdentified, %o0! "%s identified.\n"
F00BB604: 7ffd6415                 call    _printf
F00BB608: 92100018                 mov     %i0, %o1
F00BB60C: 113c04fd                 sethi   %hi(_ncg14), %o0
F00BB610: f0022210                 ld      [%o0+%lo(_ncg14)], %i0
F00BB614: b0062001                 inc     %i0
F00BB618: f0222210                 st      %i0, [%o0+%lo(_ncg14)]
F00BB61C: 81c7e008                 ret
F00BB620: 81e80000                 restore
