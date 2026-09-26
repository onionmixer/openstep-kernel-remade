F0066C5C: 9de3bf98                 save    %sp, -0x68, %sp
F0066C60: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F0066C64: d0040000                 ld      [%l0], %o0
F0066C68: 80a22000                 cmp     %o0, 0
F0066C6C: 12bffffe                 bne     loc_F0066C64
F0066C70: 01000000                 nop
F0066C74: 4000c08d                 call    _simple_lock_try
F0066C78: 90100010                 mov     %l0, %o0
F0066C7C: 80a22000                 cmp     %o0, 0
F0066C80: 02bffff9                 be      loc_F0066C64
F0066C84: 01000000                 nop
F0066C88: e4062068                 ld      [%i0+0x68], %l2
F0066C8C: 80a4a000                 cmp     %l2, 0
F0066C90: 32800004                 bne,a   loc_F0066CA0
F0066C94: c0262068                 clr     [%i0+0x68]
F0066C98: c0262064                 clr     [%i0+0x64]
F0066C9C: 3080002e                 ba,a    locret_F0066D54
F0066CA0: d006206c                 ld      [%i0+0x6C], %o0
F0066CA4: c0262064                 clr     [%i0+0x64]
F0066CA8: 80a22000                 cmp     %o0, 0
F0066CAC: 02800006                 be      loc_F0066CC4
F0066CB0: 80a23fff                 cmp     %o0, -1
F0066CB4: 22800005                 be,a    loc_F0066CC8
F0066CB8: d0062070                 ld      [%i0+0x70], %o0
F0066CBC: 7fffd118                 call    _ipc_port_release_send
F0066CC0: 01000000                 nop
F0066CC4: d0062070                 ld      [%i0+0x70], %o0
F0066CC8: 80a22000                 cmp     %o0, 0
F0066CCC: 02800006                 be      loc_F0066CE4
F0066CD0: 80a23fff                 cmp     %o0, -1
F0066CD4: 22800005                 be,a    loc_F0066CE8
F0066CD8: d0062074                 ld      [%i0+0x74], %o0
F0066CDC: 7fffd110                 call    _ipc_port_release_send
F0066CE0: 01000000                 nop
F0066CE4: d0062074                 ld      [%i0+0x74], %o0
F0066CE8: 80a22000                 cmp     %o0, 0
F0066CEC: 02800006                 be      loc_F0066D04
F0066CF0: 80a23fff                 cmp     %o0, -1
F0066CF4: 02800005                 be      loc_F0066D08
F0066CF8: a2102000                 mov     0, %l1
F0066CFC: 7fffd108                 call    _ipc_port_release_send
F0066D00: 01000000                 nop
F0066D04: a2102000                 mov     0, %l1
F0066D08: a0100018                 mov     %i0, %l0
F0066D0C: d0042078                 ld      [%l0+0x78], %o0
F0066D10: 80a22000                 cmp     %o0, 0
F0066D14: 02800007                 be      loc_F0066D30
F0066D18: a2046001                 inc     %l1
F0066D1C: 80a23fff                 cmp     %o0, -1
F0066D20: 02800004                 be      loc_F0066D30
F0066D24: 01000000                 nop
F0066D28: 7fffd0fd                 call    _ipc_port_release_send
F0066D2C: 01000000                 nop
F0066D30: 80a46003                 cmp     %l1, 3
F0066D34: 04bffff6                 ble     loc_F0066D0C
F0066D38: a0042004                 inc     4, %l0
F0066D3C: 7fffdca2                 call    _ipc_space_destroy
F0066D40: d0062088                 ld      [%i0+0x88], %o0
F0066D44: 113c04ef                 sethi   %hi(_ipc_space_kernel), %o0
F0066D48: d2022330                 ld      [%o0+%lo(_ipc_space_kernel)], %o1
F0066D4C: 7fffd184                 call    _ipc_port_dealloc_special
F0066D50: 90100012                 mov     %l2, %o0
F0066D54: 81c7e008                 ret
F0066D58: 81e80000                 restore
