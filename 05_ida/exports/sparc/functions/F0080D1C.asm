F0080D1C: 9de3bf98                 save    %sp, -0x68, %sp
F0080D20: d0062004                 ld      [%i0+4], %o0
F0080D24: 80a22018                 cmp     %o0, 0x18
F0080D28: 12800007                 bne     loc_F0080D44
F0080D2C: 90103ed0                 mov     -0x130, %o0
F0080D30: d0060000                 ld      [%i0], %o0
F0080D34: 80a22000                 cmp     %o0, 0
F0080D38: 16800005                 bge     loc_F0080D4C
F0080D3C: 01000000                 nop
F0080D40: 90103ed0                 mov     -0x130, %o0
F0080D44: 10800022                 ba      locret_F0080DCC
F0080D48: d026601c                 st      %o0, [%i1+0x1C]
F0080D4C: 7fff91c5                 call    _convert_port_to_pset_name
F0080D50: d0062008                 ld      [%i0+8], %o0! pset
F0080D54: a0100008                 mov     %o0, %l0
F0080D58: 92066024                 add     %i1, 0x24, %o1 ! '$'! ltotal
F0080D5C: 9406602c                 add     %i1, 0x2C, %o2 ! ','! space
F0080D60: 96066034                 add     %i1, 0x34, %o3 ! '4'! resident
F0080D64: 9806603c                 add     %i1, 0x3C, %o4 ! '<'! maxusage
F0080D68: 7fffd50e                 call    _processor_set_stack_usage
F0080D6C: 9a066044                 add     %i1, 0x44, %o5 ! 'D'
F0080D70: d026601c                 st      %o0, [%i1+0x1C]
F0080D74: 7fffb8f1                 call    _pset_deallocate
F0080D78: 90100010                 mov     %l0, %o0
F0080D7C: d006601c                 ld      [%i1+0x1C], %o0
F0080D80: 80a22000                 cmp     %o0, 0
F0080D84: 12800012                 bne     locret_F0080DCC
F0080D88: 90102048                 mov     0x48, %o0 ! 'H'
F0080D8C: d0266004                 st      %o0, [%i1+4]
F0080D90: 113c0445                 sethi   %hi(dword_F0111724), %o0
F0080D94: d0022324                 ld      [%o0+%lo(dword_F0111724)], %o0
F0080D98: d0266020                 st      %o0, [%i1+0x20]
F0080D9C: 113c0445                 sethi   %hi(dword_F0111728), %o0
F0080DA0: d0022328                 ld      [%o0+%lo(dword_F0111728)], %o0
F0080DA4: d0266028                 st      %o0, [%i1+0x28]
F0080DA8: 113c0445                 sethi   %hi(dword_F011172C), %o0
F0080DAC: d002232c                 ld      [%o0+%lo(dword_F011172C)], %o0
F0080DB0: d0266030                 st      %o0, [%i1+0x30]
F0080DB4: 113c0445                 sethi   %hi(dword_F0111730), %o0
F0080DB8: d0022330                 ld      [%o0+%lo(dword_F0111730)], %o0
F0080DBC: d0266038                 st      %o0, [%i1+0x38]
F0080DC0: 113c0445                 sethi   %hi(dword_F0111734), %o0
F0080DC4: d0022334                 ld      [%o0+%lo(dword_F0111734)], %o0
F0080DC8: d0266040                 st      %o0, [%i1+0x40]
F0080DCC: 81c7e008                 ret
F0080DD0: 81e80000                 restore
