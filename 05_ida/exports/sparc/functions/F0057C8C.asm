F0057C8C: 9de3bf98                 save    %sp, -0x68, %sp
F0057C90: 133c04ef                 sethi   %hi(_ipc_marequest_size), %o1
F0057C94: d0026358                 ld      [%o1+%lo(_ipc_marequest_size)], %o0
F0057C98: 80a22000                 cmp     %o0, 0
F0057C9C: 1280000b                 bne     loc_F0057CC8
F0057CA0: 193c04ef                 sethi   -0xFEC4400, %o4
F0057CA4: 113c043d                 sethi   %hi(_ipc_marequest_max), %o0
F0057CA8: d0022018                 ld      [%o0+%lo(_ipc_marequest_max)], %o0
F0057CAC: 913a2008                 sra     %o0, 8, %o0
F0057CB0: 80a2200f                 cmp     %o0, 0xF
F0057CB4: 18800005                 bgu     loc_F0057CC8
F0057CB8: d0226358                 st      %o0, [%o1+%lo(_ipc_marequest_size)]
F0057CBC: 90102010                 mov     0x10, %o0
F0057CC0: d0226358                 st      %o0, [%o1+%lo(_ipc_marequest_size)]
F0057CC4: 193c04ef                 sethi   -0xFEC4400, %o4
F0057CC8: d0032358                 ld      [%o4+0x358], %o0
F0057CCC: 173c04ef                 sethi   %hi(_ipc_marequest_mask), %o3
F0057CD0: 92023fff                 add     %o0, -1, %o1
F0057CD4: 808a0009                 btst    %o1, %o0
F0057CD8: 0280000d                 be      loc_F0057D0C
F0057CDC: d222e350                 st      %o1, [%o3+%lo(_ipc_marequest_mask)]
F0057CE0: 94102001                 mov     1, %o2
F0057CE4: 10800005                 ba      loc_F0057CF8
F0057CE8: 90126001                 or      %o1, 1, %o0
F0057CEC: d002e350                 ld      [%o3+0x350], %o0
F0057CF0: 952aa001                 sll     %o2, 1, %o2
F0057CF4: 9012000a                 bset    %o2, %o0
F0057CF8: d022e350                 st      %o0, [%o3+0x350]
F0057CFC: 92022001                 add     %o0, 1, %o1
F0057D00: 808a4008                 btst    %o0, %o1
F0057D04: 12bffffa                 bne     loc_F0057CEC
F0057D08: d2232358                 st      %o1, [%o4+0x358]
F0057D0C: 213c04ef                 sethi   %hi(_ipc_marequest_size), %l0
F0057D10: d0042358                 ld      [%l0+%lo(_ipc_marequest_size)], %o0
F0057D14: 400040d7                 call    _kalloc
F0057D18: 912a2003                 sll     %o0, 3, %o0
F0057D1C: 94100008                 mov     %o0, %o2
F0057D20: 113c04ef                 sethi   %hi(_ipc_marequest_table), %o0
F0057D24: d4222360                 st      %o2, [%o0+%lo(_ipc_marequest_table)]
F0057D28: d0042358                 ld      [%l0+%lo(_ipc_marequest_size)], %o0
F0057D2C: 92102000                 mov     0, %o1
F0057D30: 80a24008                 cmp     %o1, %o0
F0057D34: 1a80000a                 bcc     loc_F0057D5C
F0057D38: 9610000a                 mov     %o2, %o3
F0057D3C: 98100008                 mov     %o0, %o4
F0057D40: 912a6003                 sll     %o1, 3, %o0
F0057D44: c022c008                 clr     [%o3+%o0]
F0057D48: c022a004                 clr     [%o2+4]
F0057D4C: 92026001                 inc     %o1
F0057D50: 80a2400c                 cmp     %o1, %o4
F0057D54: 0abffffb                 bcs     loc_F0057D40
F0057D58: 9402a008                 inc     8, %o2
F0057D5C: 90102010                 mov     0x10, %o0
F0057D60: 94102010                 mov     0x10, %o2
F0057D64: 96102000                 mov     0, %o3
F0057D68: 133c043d                 sethi   %hi(_ipc_marequest_max), %o1
F0057D6C: d2026018                 ld      [%o1+%lo(_ipc_marequest_max)], %o1
F0057D70: 193c043d98132020         set     aIpcMsgAccepted, %o4! "ipc msg-accepted requests"
F0057D78: 40008070                 call    _zinit
F0057D7C: 932a6004                 sll     %o1, 4, %o1
F0057D80: 133c04ef                 sethi   %hi(_ipc_marequest_zone), %o1
F0057D84: d0226368                 st      %o0, [%o1+%lo(_ipc_marequest_zone)]
F0057D88: 92102000                 mov     0, %o1
F0057D8C: 94102000                 mov     0, %o2
F0057D90: 96102001                 mov     1, %o3
F0057D94: 4000855b                 call    _zchange
F0057D98: 98102000                 mov     0, %o4
F0057D9C: 81c7e008                 ret
F0057DA0: 81e80000                 restore
