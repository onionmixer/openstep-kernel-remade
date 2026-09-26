F007FF7C: 9de3bf98                 save    %sp, -0x68, %sp
F007FF80: d0062004                 ld      [%i0+4], %o0
F007FF84: 80a22038                 cmp     %o0, 0x38 ! '8'
F007FF88: 1280001e                 bne     loc_F0080000
F007FF8C: 90103ed0                 mov     -0x130, %o0
F007FF90: d0060000                 ld      [%i0], %o0
F007FF94: 80a22000                 cmp     %o0, 0
F007FF98: 06800019                 bl      loc_F007FFFC
F007FF9C: 133c0445                 sethi   %hi(dword_F0111498), %o1
F007FFA0: d0062018                 ld      [%i0+0x18], %o0
F007FFA4: d2026098                 ld      [%o1+%lo(dword_F0111498)], %o1
F007FFA8: 80a20009                 cmp     %o0, %o1
F007FFAC: 12800015                 bne     loc_F0080000
F007FFB0: 90103ed0                 mov     -0x130, %o0
F007FFB4: d0062020                 ld      [%i0+0x20], %o0
F007FFB8: 133c0445                 sethi   %hi(dword_F011149C), %o1
F007FFBC: d202609c                 ld      [%o1+%lo(dword_F011149C)], %o1
F007FFC0: 80a20009                 cmp     %o0, %o1
F007FFC4: 1280000f                 bne     loc_F0080000
F007FFC8: 90103ed0                 mov     -0x130, %o0
F007FFCC: d0062028                 ld      [%i0+0x28], %o0
F007FFD0: 133c0445                 sethi   %hi(dword_F01114A0), %o1
F007FFD4: d20260a0                 ld      [%o1+%lo(dword_F01114A0)], %o1
F007FFD8: 80a20009                 cmp     %o0, %o1
F007FFDC: 12800009                 bne     loc_F0080000
F007FFE0: 90103ed0                 mov     -0x130, %o0
F007FFE4: d0062030                 ld      [%i0+0x30], %o0
F007FFE8: 133c0445                 sethi   %hi(dword_F01114A4), %o1
F007FFEC: d20260a4                 ld      [%o1+%lo(dword_F01114A4)], %o1
F007FFF0: 80a20009                 cmp     %o0, %o1
F007FFF4: 02800005                 be      loc_F0080008
F007FFF8: 01000000                 nop
F007FFFC: 90103ed0                 mov     -0x130, %o0
F0080000: 10800017                 ba      locret_F008005C
F0080004: d026601c                 st      %o0, [%i1+0x1C]
F0080008: 7fff9e7c                 call    _convert_port_to_map
F008000C: d0062008                 ld      [%i0+8], %o0! target_task
F0080010: d206201c                 ld      [%i0+0x1C], %o1! address
F0080014: a0100008                 mov     %o0, %l0
F0080018: d4062024                 ld      [%i0+0x24], %o2! size
F008001C: d606202c                 ld      [%i0+0x2C], %o3! attribute
F0080020: 40002a8d                 call    _vm_machine_attribute
F0080024: 98062034                 add     %i0, 0x34, %o4 ! '4'
F0080028: d026601c                 st      %o0, [%i1+0x1C]
F008002C: 40001078                 call    _vm_map_deallocate
F0080030: 90100010                 mov     %l0, %o0
F0080034: d006601c                 ld      [%i1+0x1C], %o0
F0080038: 80a22000                 cmp     %o0, 0
F008003C: 12800008                 bne     locret_F008005C
F0080040: 90102028                 mov     0x28, %o0 ! '('
F0080044: d0266004                 st      %o0, [%i1+4]
F0080048: 113c0445                 sethi   %hi(dword_F01114A8), %o0
F008004C: d00220a8                 ld      [%o0+%lo(dword_F01114A8)], %o0
F0080050: d0266020                 st      %o0, [%i1+0x20]
F0080054: d0062034                 ld      [%i0+0x34], %o0
F0080058: d0266024                 st      %o0, [%i1+0x24]
F008005C: 81c7e008                 ret
F0080060: 81e80000                 restore
