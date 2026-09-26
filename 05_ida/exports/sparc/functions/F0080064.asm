F0080064: 9de3bf98                 save    %sp, -0x68, %sp
F0080068: d0062004                 ld      [%i0+4], %o0
F008006C: 80a22028                 cmp     %o0, 0x28 ! '('
F0080070: 12800012                 bne     loc_F00800B8
F0080074: 90103ed0                 mov     -0x130, %o0
F0080078: d0060000                 ld      [%i0], %o0
F008007C: 80a22000                 cmp     %o0, 0
F0080080: 0680000d                 bl      loc_F00800B4
F0080084: 133c0445                 sethi   %hi(dword_F01114AC), %o1
F0080088: d0062018                 ld      [%i0+0x18], %o0
F008008C: d20260ac                 ld      [%o1+%lo(dword_F01114AC)], %o1
F0080090: 80a20009                 cmp     %o0, %o1
F0080094: 12800009                 bne     loc_F00800B8
F0080098: 90103ed0                 mov     -0x130, %o0
F008009C: d0062020                 ld      [%i0+0x20], %o0
F00800A0: 133c0445                 sethi   %hi(dword_F01114B0), %o1
F00800A4: d20260b0                 ld      [%o1+%lo(dword_F01114B0)], %o1
F00800A8: 80a20009                 cmp     %o0, %o1
F00800AC: 02800005                 be      loc_F00800C0
F00800B0: 01000000                 nop
F00800B4: 90103ed0                 mov     -0x130, %o0
F00800B8: 1080000b                 ba      locret_F00800E4
F00800BC: d026601c                 st      %o0, [%i1+0x1C]
F00800C0: 7fff9e4e                 call    _convert_port_to_map
F00800C4: d0062008                 ld      [%i0+8], %o0
F00800C8: d206201c                 ld      [%i0+0x1C], %o1
F00800CC: a0100008                 mov     %o0, %l0
F00800D0: 40002622                 call    _vm_synchronize
F00800D4: d4062024                 ld      [%i0+0x24], %o2
F00800D8: d026601c                 st      %o0, [%i1+0x1C]
F00800DC: 4000104c                 call    _vm_map_deallocate
F00800E0: 90100010                 mov     %l0, %o0
F00800E4: 81c7e008                 ret
F00800E8: 81e80000                 restore
