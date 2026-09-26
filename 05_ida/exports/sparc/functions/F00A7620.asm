F00A7620: 9de3bf90                 save    %sp, -0x70, %sp
F00A7624: 7fffbd46                 call    _splaudio
F00A7628: 01000000                 nop
F00A762C: f823a05c                 st      %i4, [%sp+0x70+var_14]
F00A7630: 113c046e90122028         set     aBadTrapCpuDTyp, %o0! "BAD TRAP: cpu=%d type=%x rp=%x addr=%x "...
F00A7638: 94100018                 mov     %i0, %o2
F00A763C: 96100019                 mov     %i1, %o3
F00A7640: 133c0464                 sethi   %hi(_cpuid), %o1
F00A7644: 9810001a                 mov     %i2, %o4
F00A7648: d2026340                 ld      [%o1+%lo(_cpuid)], %o1
F00A764C: 7ffdb403                 call    _printf
F00A7650: 9a10001b                 mov     %i3, %o5
F00A7654: 7fffb839                 call    _mmu_print_sfsr
F00A7658: 9010001b                 mov     %i3, %o0
F00A765C: 113c046e90122068         set     aRegsAtX, %o0! "regs at %x:\n"
F00A7664: 7ffdb3fd                 call    _printf
F00A7668: 92100019                 mov     %i1, %o1
F00A766C: d2064000                 ld      [%i1], %o1
F00A7670: d4066004                 ld      [%i1+4], %o2
F00A7674: 113c046e                 sethi   %hi(aPsrXPcXNpcX), %o0! "\tpsr=%x pc=%x npc=%x\n"
F00A7678: d6066008                 ld      [%i1+8], %o3
F00A767C: 7ffdb3f7                 call    _printf
F00A7680: 90122078                 bset    %lo(aPsrXPcXNpcX), %o0! "\tpsr=%x pc=%x npc=%x\n"
F00A7684: d206600c                 ld      [%i1+0xC], %o1
F00A7688: d4066010                 ld      [%i1+0x10], %o2
F00A768C: d6066014                 ld      [%i1+0x14], %o3
F00A7690: 113c046e                 sethi   %hi(aYXG1XG2XG3X), %o0! "\ty: %x g1: %x g2: %x g3: %x\n"
F00A7694: d8066018                 ld      [%i1+0x18], %o4
F00A7698: 7ffdb3f0                 call    _printf
F00A769C: 90122090                 bset    %lo(aYXG1XG2XG3X), %o0! "\ty: %x g1: %x g2: %x g3: %x\n"
F00A76A0: d206601c                 ld      [%i1+0x1C], %o1
F00A76A4: d4066020                 ld      [%i1+0x20], %o2
F00A76A8: d6066024                 ld      [%i1+0x24], %o3
F00A76AC: 113c046e                 sethi   %hi(aG4XG5XG6XG7X), %o0! "\tg4: %x g5: %x g6: %x g7: %x\n"
F00A76B0: d8066028                 ld      [%i1+0x28], %o4
F00A76B4: 7ffdb3e9                 call    _printf
F00A76B8: 901220b0                 bset    %lo(aG4XG5XG6XG7X), %o0! "\tg4: %x g5: %x g6: %x g7: %x\n"
F00A76BC: d206602c                 ld      [%i1+0x2C], %o1
F00A76C0: d4066030                 ld      [%i1+0x30], %o2
F00A76C4: d6066034                 ld      [%i1+0x34], %o3
F00A76C8: 113c046e                 sethi   %hi(aO0XO1XO2XO3X), %o0! "\to0: %x o1: %x o2: %x o3: %x\n"
F00A76CC: d8066038                 ld      [%i1+0x38], %o4
F00A76D0: 7ffdb3e2                 call    _printf
F00A76D4: 901220d0                 bset    %lo(aO0XO1XO2XO3X), %o0! "\to0: %x o1: %x o2: %x o3: %x\n"
F00A76D8: d206603c                 ld      [%i1+0x3C], %o1
F00A76DC: d4066040                 ld      [%i1+0x40], %o2
F00A76E0: d6066044                 ld      [%i1+0x44], %o3
F00A76E4: 113c046e                 sethi   %hi(aO4XO5XSpXRaX), %o0! "\to4: %x o5: %x sp: %x ra: %x\n"
F00A76E8: d8066048                 ld      [%i1+0x48], %o4
F00A76EC: 7ffdb3db                 call    _printf
F00A76F0: 901220f0                 bset    %lo(aO4XO5XSpXRaX), %o0! "\to4: %x o5: %x sp: %x ra: %x\n"
F00A76F4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A76F8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00A76FC: 80a22000                 cmp     %o0, 0
F00A7700: 02800007                 be      loc_F00A771C
F00A7704: 90100018                 mov     %i0, %o0
F00A7708: 92100019                 mov     %i1, %o1
F00A770C: 9410001a                 mov     %i2, %o2
F00A7710: 9610001b                 mov     %i3, %o3
F00A7714: 40000739                 call    _showregs
F00A7718: 9810001c                 mov     %i4, %o4
F00A771C: 400006db                 call    _traceback
F00A7720: d0066044                 ld      [%i1+0x44], %o0
F00A7724: 80a6202b                 cmp     %i0, 0x2B ! '+'
F00A7728: 18800006                 bgu     loc_F00A7740
F00A772C: 932e2002                 sll     %i0, 2, %o1
F00A7730: 113c046c9012237c         set     _trap_type, %o0! char *
F00A7738: 7ffdb68e                 call    _panic
F00A773C: d0024008                 ld      [%o1+%o0], %o0
F00A7740: 113c046e                 sethi   %hi(aTrap), %o0! "trap"
F00A7744: 7ffdb68b                 call    _panic
F00A7748: 90122110                 bset    %lo(aTrap), %o0! "trap"
F00A774C: 81c7e008                 ret
F00A7750: 81e80000                 restore
