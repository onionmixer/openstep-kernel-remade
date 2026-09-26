F0080C64: 9de3bf90                 save    %sp, -0x70, %sp
F0080C68: d0062004                 ld      [%i0+4], %o0
F0080C6C: 80a22018                 cmp     %o0, 0x18
F0080C70: 12800006                 bne     loc_F0080C88
F0080C74: 90103ed0                 mov     -0x130, %o0
F0080C78: d0060000                 ld      [%i0], %o0
F0080C7C: 80a22000                 cmp     %o0, 0
F0080C80: 16800004                 bge     loc_F0080C90
F0080C84: 90103ed0                 mov     -0x130, %o0
F0080C88: 10800023                 ba      locret_F0080D14
F0080C8C: d026601c                 st      %o0, [%i1+0x1C]
F0080C90: 7fff917f                 call    _convert_port_to_host
F0080C94: d0062008                 ld      [%i0+8], %o0
F0080C98: 9206604c                 add     %i1, 0x4C, %o1 ! 'L'
F0080C9C: d223a05c                 st      %o1, [%sp+0x70+var_14]
F0080CA0: 92066024                 add     %i1, 0x24, %o1 ! '$'
F0080CA4: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F0080CA8: 96066034                 add     %i1, 0x34, %o3 ! '4'
F0080CAC: 9806603c                 add     %i1, 0x3C, %o4 ! '<'
F0080CB0: 7fffd50f                 call    _host_stack_usage
F0080CB4: 9a066044                 add     %i1, 0x44, %o5 ! 'D'
F0080CB8: 80a22000                 cmp     %o0, 0
F0080CBC: 12800016                 bne     locret_F0080D14
F0080CC0: d026601c                 st      %o0, [%i1+0x1C]
F0080CC4: 90102050                 mov     0x50, %o0 ! 'P'
F0080CC8: d0266004                 st      %o0, [%i1+4]
F0080CCC: 113c0445                 sethi   %hi(dword_F011170C), %o0
F0080CD0: d002230c                 ld      [%o0+%lo(dword_F011170C)], %o0
F0080CD4: d0266020                 st      %o0, [%i1+0x20]
F0080CD8: 113c0445                 sethi   %hi(dword_F0111710), %o0
F0080CDC: d0022310                 ld      [%o0+%lo(dword_F0111710)], %o0
F0080CE0: d0266028                 st      %o0, [%i1+0x28]
F0080CE4: 113c0445                 sethi   %hi(dword_F0111714), %o0
F0080CE8: d0022314                 ld      [%o0+%lo(dword_F0111714)], %o0
F0080CEC: d0266030                 st      %o0, [%i1+0x30]
F0080CF0: 113c0445                 sethi   %hi(dword_F0111718), %o0
F0080CF4: d0022318                 ld      [%o0+%lo(dword_F0111718)], %o0
F0080CF8: d0266038                 st      %o0, [%i1+0x38]
F0080CFC: 113c0445                 sethi   %hi(dword_F011171C), %o0
F0080D00: d002231c                 ld      [%o0+%lo(dword_F011171C)], %o0
F0080D04: d0266040                 st      %o0, [%i1+0x40]
F0080D08: 113c0445                 sethi   %hi(dword_F0111720), %o0
F0080D0C: d0022320                 ld      [%o0+%lo(dword_F0111720)], %o0
F0080D10: d0266048                 st      %o0, [%i1+0x48]
F0080D14: 81c7e008                 ret
F0080D18: 81e80000                 restore
