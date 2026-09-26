F006E714: 9de3bf90                 save    %sp, -0x70, %sp
F006E718: a6100018                 mov     %i0, %l3
F006E71C: 40009874                 call    _PMGetPowerEvent
F006E720: 9007bff4                 add     %fp, var_C, %o0
F006E724: b0920000                 orcc    %o0, %g0, %i0
F006E728: 1280003f                 bne     locret_F006E824
F006E72C: d007bff4                 ld      [%fp+var_C], %o0
F006E730: 92023fff                 add     %o0, -1, %o1
F006E734: 80a2600a                 cmp     %o1, 0xA! switch 11 cases
F006E738: 18800037                 bgu     def_F006E74C! jumptable F006E74C default case, cases 4,5
F006E73C: 113c01b9                 sethi   %hi(jpt_F006E74C), %o0
F006E740: 90122354                 bset    %lo(jpt_F006E74C), %o0
F006E744: 932a6002                 sll     %o1, 2, %o1
F006E748: d0024008                 ld      [%o1+%o0], %o0
F006E74C: 81c20000                 jmp     %o0! switch jump
F006E750: 01000000                 nop
F006E780: 113c04be                 sethi   %hi(dword_F012F928), %o0! jumptable F006E74C cases 0,8
F006E784: 92102001                 mov     1, %o1
F006E788: d2222128                 st      %o1, [%o0+%lo(dword_F012F928)]
F006E78C: 11000040                 sethi   0x10000, %o0
F006E790: d027bff0                 st      %o0, [%fp+var_10]
F006E794: 40009851                 call    _PMSetPowerState
F006E798: 9007bff0                 add     %fp, var_10, %o0
F006E79C: 1080001f                 ba      loc_F006E818
F006E7A0: 80a4e000                 cmp     %l3, 0
F006E7A4: 253c04be                 sethi   %hi(dword_F012F928), %l2! jumptable F006E74C cases 1,7,9
F006E7A8: 90102002                 mov     2, %o0
F006E7AC: d024a128                 st      %o0, [%l2+%lo(dword_F012F928)]
F006E7B0: 23000040                 sethi   0x10000, %l1
F006E7B4: e227bff0                 st      %l1, [%fp+var_10]
F006E7B8: a007bff0                 add     %fp, var_10, %l0
F006E7BC: 90100010                 mov     %l0, %o0
F006E7C0: 40009846                 call    _PMSetPowerState
F006E7C4: 92102002                 mov     2, %o1
F006E7C8: c024a128                 clr     [%l2+%lo(dword_F012F928)]
F006E7CC: e227bff0                 st      %l1, [%fp+var_10]
F006E7D0: 90100010                 mov     %l0, %o0
F006E7D4: 40009841                 call    _PMSetPowerState
F006E7D8: 92102000                 mov     0, %o1
F006E7DC: 1080000f                 ba      loc_F006E818
F006E7E0: 80a4e000                 cmp     %l3, 0
F006E7E4: 133c04be                 sethi   %hi(dword_F012F928), %o1! jumptable F006E74C cases 2,3,10
F006E7E8: d0026128                 ld      [%o1+%lo(dword_F012F928)], %o0
F006E7EC: 80a22000                 cmp     %o0, 0
F006E7F0: 02800007                 be      loc_F006E80C! jumptable F006E74C case 6
F006E7F4: 11000040                 sethi   0x10000, %o0
F006E7F8: c0226128                 clr     [%o1+%lo(dword_F012F928)]
F006E7FC: d027bff0                 st      %o0, [%fp+var_10]
F006E800: 9007bff0                 add     %fp, var_10, %o0
F006E804: 40009835                 call    _PMSetPowerState
F006E808: 92102000                 mov     0, %o1
F006E80C: 4000984a                 call    _PMUpdateClock! jumptable F006E74C case 6
F006E810: 01000000                 nop
F006E814: 80a4e000                 cmp     %l3, 0! jumptable F006E74C default case, cases 4,5
F006E818: 02800003                 be      locret_F006E824
F006E81C: d007bff4                 ld      [%fp+var_C], %o0
F006E820: d024c000                 st      %o0, [%l3]
F006E824: 81c7e008                 ret
F006E828: 81e80000                 restore
