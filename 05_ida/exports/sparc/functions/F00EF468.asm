F00EF468: 9de3bf88                 save    %sp, -0x78, %sp
F00EF46C: d0062020                 ld      [%i0+0x20], %o0
F00EF470: 80a22000                 cmp     %o0, 0
F00EF474: 02800035                 be      locret_F00EF548
F00EF478: 01000000                 nop
F00EF47C: 40000a15                 call    _objc_getClasses
F00EF480: 01000000                 nop
F00EF484: a0100008                 mov     %o0, %l0
F00EF488: 9007bff0                 add     %fp, var_10, %o0
F00EF48C: d023a040                 st      %o0, [%sp+0x78+var_38]
F00EF490: 90100010                 mov     %l0, %o0! table
F00EF494: 7ffffa54                 call    _NXInitHashState
F00EF498: 01000000                 nop
F00EF49C: 00000008                 illtrap
F00EF4A0: 912e6018                 sll     %i1, 24, %o0
F00EF4A4: b33a2018                 sra     %o0, 24, %i1
F00EF4A8: 90100010                 mov     %l0, %o0! table
F00EF4AC: 9207bff0                 add     %fp, var_10, %o1! state
F00EF4B0: 7ffffa58                 call    _NXNextHashState
F00EF4B4: 9407bfec                 add     %fp, var_14, %o2
F00EF4B8: 80a22000                 cmp     %o0, 0
F00EF4BC: 02800023                 be      locret_F00EF548
F00EF4C0: d207bfec                 ld      [%fp+var_14], %o1
F00EF4C4: 80a26000                 cmp     %o1, 0
F00EF4C8: 02bffff9                 be      loc_F00EF4AC
F00EF4CC: 90100010                 mov     %l0, %o0
F00EF4D0: 80a24018                 cmp     %o1, %i0
F00EF4D4: 3280000b                 bne,a   loc_F00EF500
F00EF4D8: d0024000                 ld      [%o1], %o0
F00EF4DC: 4000032c                 call    sub_F00F018C
F00EF4E0: d007bfec                 ld      [%fp+var_14], %o0
F00EF4E4: 80a66000                 cmp     %i1, 0
F00EF4E8: 02800012                 be      loc_F00EF530
F00EF4EC: d007bfec                 ld      [%fp+var_14], %o0
F00EF4F0: 40000327                 call    sub_F00F018C
F00EF4F4: d0020000                 ld      [%o0], %o0
F00EF4F8: 1080000f                 ba      loc_F00EF534
F00EF4FC: 92102000                 mov     0, %o1
F00EF500: 80a20018                 cmp     %o0, %i0
F00EF504: 32800006                 bne,a   loc_F00EF51C
F00EF508: d0026010                 ld      [%o1+0x10], %o0
F00EF50C: 40000320                 call    sub_F00F018C
F00EF510: d007bfec                 ld      [%fp+var_14], %o0
F00EF514: 10800008                 ba      loc_F00EF534
F00EF518: 92102000                 mov     0, %o1
F00EF51C: 808a2004                 btst    4, %o0
F00EF520: 22800005                 be,a    loc_F00EF534
F00EF524: 92102000                 mov     0, %o1
F00EF528: 10800003                 ba      loc_F00EF534
F00EF52C: d2026004                 ld      [%o1+4], %o1
F00EF530: 92102000                 mov     0, %o1
F00EF534: 80a26000                 cmp     %o1, 0
F00EF538: 12bfffe7                 bne     loc_F00EF4D4
F00EF53C: 80a24018                 cmp     %o1, %i0
F00EF540: 10bfffdb                 ba      loc_F00EF4AC
F00EF544: 90100010                 mov     %l0, %o0
F00EF548: 81c7e008                 ret
F00EF54C: 81e80000                 restore
