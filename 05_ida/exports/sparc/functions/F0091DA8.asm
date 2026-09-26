F0091DA8: 9de3bf90                 save    %sp, -0x70, %sp
F0091DAC: d0062004                 ld      [%i0+4], %o0
F0091DB0: 80a22028                 cmp     %o0, 0x28 ! '('
F0091DB4: 1280001b                 bne     loc_F0091E20
F0091DB8: 90103ed0                 mov     -0x130, %o0
F0091DBC: d0060000                 ld      [%i0], %o0
F0091DC0: 80a22000                 cmp     %o0, 0
F0091DC4: 36800004                 bge,a   loc_F0091DD4
F0091DC8: d0062018                 ld      [%i0+0x18], %o0
F0091DCC: 10800015                 ba      loc_F0091E20
F0091DD0: 90103ed0                 mov     -0x130, %o0
F0091DD4: 133c0448                 sethi   %hi(dword_F01122FC), %o1
F0091DD8: d20262fc                 ld      [%o1+%lo(dword_F01122FC)], %o1
F0091DDC: 80a20009                 cmp     %o0, %o1
F0091DE0: 12800010                 bne     loc_F0091E20
F0091DE4: 90103ed0                 mov     -0x130, %o0
F0091DE8: d0062020                 ld      [%i0+0x20], %o0
F0091DEC: 133c0448                 sethi   %hi(dword_F0112300), %o1
F0091DF0: d2026300                 ld      [%o1+%lo(dword_F0112300)], %o1
F0091DF4: 80a20009                 cmp     %o0, %o1
F0091DF8: 22800004                 be,a    loc_F0091E08
F0091DFC: d006201c                 ld      [%i0+0x1C], %o0
F0091E00: 10800008                 ba      loc_F0091E20
F0091E04: 90103ed0                 mov     -0x130, %o0
F0091E08: d027bff4                 st      %o0, [%fp+var_C]
F0091E0C: 7fff4d20                 call    _convert_port_to_host
F0091E10: d0062008                 ld      [%i0+8], %o0
F0091E14: d4062024                 ld      [%i0+0x24], %o2
F0091E18: 7fff72d6                 call    _kern_PMSetPowerManagement
F0091E1C: 9207bff4                 add     %fp, var_C, %o1
F0091E20: d026601c                 st      %o0, [%i1+0x1C]
F0091E24: 81c7e008                 ret
F0091E28: 81e80000                 restore
