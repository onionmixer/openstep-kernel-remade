F00B50E4: 9de3bf98                 save    %sp, -0x68, %sp
F00B50E8: a0100018                 mov     %i0, %l0
F00B50EC: d00c2044                 ldub    [%l0+0x44], %o0
F00B50F0: 808a2020                 btst    0x20, %o0 ! ' '
F00B50F4: 2280000c                 be,a    loc_F00B5124
F00B50F8: d00c2043                 ldub    [%l0+0x43], %o0
F00B50FC: 400008d7                 call    _esp_chip_disconnect
F00B5100: 90100010                 mov     %l0, %o0
F00B5104: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B5108: 912a2002                 sll     %o0, 2, %o0
F00B510C: 90020010                 add     %o0, %l0, %o0
F00B5110: d20220b8                 ld      [%o0+0xB8], %o1
F00B5114: b0102003                 mov     3, %i0
F00B5118: 90102014                 mov     0x14, %o0
F00B511C: 1080002d                 ba      locret_F00B51D0
F00B5120: d02a6028                 stb     %o0, [%o1+0x28]
F00B5124: 920a2007                 and     %o0, 7, %o1
F00B5128: 80a26007                 cmp     %o1, 7! switch 8 cases
F00B512C: 18800021                 bgu     def_F00B5140! jumptable F00B5140 default case, cases 4,5
F00B5130: 113c02d4                 sethi   %hi(jpt_F00B5140), %o0
F00B5134: 90122148                 bset    %lo(jpt_F00B5140), %o0
F00B5138: 932a6002                 sll     %o1, 2, %o1
F00B513C: d0024008                 ld      [%o1+%o0], %o0
F00B5140: 81c20000                 jmp     %o0! switch jump
F00B5144: 01000000                 nop
F00B5168: 10800018                 ba      loc_F00B51C8! jumptable F00B5140 cases 0,1
F00B516C: 90102009                 mov     9, %o0
F00B5170: 10800016                 ba      loc_F00B51C8! jumptable F00B5140 case 6
F00B5174: 90102003                 mov     3, %o0
F00B5178: 10800014                 ba      loc_F00B51C8! jumptable F00B5140 case 7
F00B517C: 90102005                 mov     5, %o0
F00B5180: b0103fff                 mov     -1, %i0! jumptable F00B5140 case 3
F00B5184: d204209c                 ld      [%l0+0x9C], %o1
F00B5188: 90102001                 mov     1, %o0
F00B518C: d02a600c                 stb     %o0, [%o1+0xC]
F00B5190: d204209c                 ld      [%l0+0x9C], %o1
F00B5194: 90102011                 mov     0x11, %o0
F00B5198: d02a600c                 stb     %o0, [%o1+0xC]
F00B519C: 9010200b                 mov     0xB, %o0
F00B51A0: 1080000c                 ba      locret_F00B51D0
F00B51A4: d02c2041                 stb     %o0, [%l0+0x41]
F00B51A8: 10800008                 ba      loc_F00B51C8! jumptable F00B5140 case 2
F00B51AC: 90102001                 mov     1, %o0
F00B51B0: 90100010                 mov     %l0, %o0! jumptable F00B5140 default case, cases 4,5
F00B51B4: 133c0479                 sethi   %hi(aUnknownBusPhas), %o1! "Unknown bus phase"
F00B51B8: 40000ad7                 call    _esp_printstate
F00B51BC: 92126148                 bset    %lo(aUnknownBusPhas), %o1! "Unknown bus phase"
F00B51C0: 10800004                 ba      locret_F00B51D0
F00B51C4: b0102008                 mov     8, %i0
F00B51C8: d02c2041                 stb     %o0, [%l0+0x41]
F00B51CC: b0102002                 mov     2, %i0
F00B51D0: 81c7e008                 ret
F00B51D4: 81e80000                 restore
