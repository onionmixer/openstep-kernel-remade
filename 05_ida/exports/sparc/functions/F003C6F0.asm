F003C6F0: 9de3bf98                 save    %sp, -0x68, %sp
F003C6F4: 7fffff0b                 call    sub_F003C320
F003C6F8: d0060000                 ld      [%i0], %o0
F003C6FC: 4000193b                 call    _clntkudp_freecred
F003C700: 90100018                 mov     %i0, %o0
F003C704: c0260000                 clr     [%i0]
F003C708: 153c04ea                 sethi   %hi(_chtable), %o2
F003C70C: 113c0433                 sethi   %hi(_MAXCLIENTS), %o0
F003C710: d2022180                 ld      [%o0+%lo(_MAXCLIENTS)], %o1
F003C714: 9412a160                 bset    %lo(_chtable), %o2
F003C718: 912a6001                 sll     %o1, 1, %o0
F003C71C: 90020009                 add     %o0, %o1, %o0
F003C720: 912a2002                 sll     %o0, 2, %o0
F003C724: 9002000a                 add     %o0, %o2, %o0
F003C728: 80a28008                 cmp     %o2, %o0
F003C72C: 1a80000c                 bcc     loc_F003C75C
F003C730: 96100008                 mov     %o0, %o3
F003C734: 9202a004                 add     %o2, 4, %o1
F003C738: d0026004                 ld      [%o1+4], %o0
F003C73C: 80a20018                 cmp     %o0, %i0
F003C740: 12800004                 bne     loc_F003C750
F003C744: 9402a00c                 inc     0xC, %o2
F003C748: 10800009                 ba      locret_F003C76C
F003C74C: c0224000                 clr     [%o1]
F003C750: 80a2800b                 cmp     %o2, %o3
F003C754: 0abffff9                 bcs     loc_F003C738
F003C758: 9202600c                 inc     0xC, %o1
F003C75C: d0062004                 ld      [%i0+4], %o0
F003C760: d2022010                 ld      [%o0+0x10], %o1
F003C764: 9fc24000                 call    %o1
F003C768: 90100018                 mov     %i0, %o0
F003C76C: 81c7e008                 ret
F003C770: 81e80000                 restore
