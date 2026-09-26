F00E3DBC: 9de3bf90                 save    %sp, -0x70, %sp
F00E3DC0: d2062004                 ld      [%i0+4], %o1
F00E3DC4: 80a2602c                 cmp     %o1, 0x2C ! ','
F00E3DC8: 12800005                 bne     loc_F00E3DDC
F00E3DCC: d00e2003                 ldub    [%i0+3], %o0
F00E3DD0: 80a22001                 cmp     %o0, 1
F00E3DD4: 22800005                 be,a    loc_F00E3DE8
F00E3DD8: d0062018                 ld      [%i0+0x18], %o0
F00E3DDC: 90103ed0                 mov     -0x130, %o0
F00E3DE0: 1080001f                 ba      locret_F00E3E5C
F00E3DE4: d026601c                 st      %o0, [%i1+0x1C]
F00E3DE8: 133c03e6                 sethi   %hi(dword_F00F9AD4), %o1
F00E3DEC: d20262d4                 ld      [%o1+%lo(dword_F00F9AD4)], %o1
F00E3DF0: 80a20009                 cmp     %o0, %o1
F00E3DF4: 12800012                 bne     loc_F00E3E3C
F00E3DF8: 90103ed0                 mov     -0x130, %o0
F00E3DFC: d0062020                 ld      [%i0+0x20], %o0
F00E3E00: 133c03e6                 sethi   %hi(dword_F00F9AD8), %o1
F00E3E04: d20262d8                 ld      [%o1+%lo(dword_F00F9AD8)], %o1
F00E3E08: 80a20009                 cmp     %o0, %o1
F00E3E0C: 22800004                 be,a    loc_F00E3E1C
F00E3E10: d0062024                 ld      [%i0+0x24], %o0
F00E3E14: 1080000a                 ba      loc_F00E3E3C
F00E3E18: 90103ed0                 mov     -0x130, %o0
F00E3E1C: d027bff0                 st      %o0, [%fp+var_10]
F00E3E20: d0062028                 ld      [%i0+0x28], %o0
F00E3E24: d027bff4                 st      %o0, [%fp+var_C]
F00E3E28: 7fffe876                 call    _audio_port_to_stream
F00E3E2C: d006200c                 ld      [%i0+0xC], %o0
F00E3E30: d206201c                 ld      [%i0+0x1C], %o1
F00E3E34: 7fffea86                 call    __NXAudioStreamControl
F00E3E38: 9407bff0                 add     %fp, var_10, %o2
F00E3E3C: d026601c                 st      %o0, [%i1+0x1C]
F00E3E40: d006601c                 ld      [%i1+0x1C], %o0
F00E3E44: 80a22000                 cmp     %o0, 0
F00E3E48: 12800005                 bne     locret_F00E3E5C
F00E3E4C: 92102020                 mov     0x20, %o1 ! ' '
F00E3E50: 90102001                 mov     1, %o0
F00E3E54: d02e6003                 stb     %o0, [%i1+3]
F00E3E58: d2266004                 st      %o1, [%i1+4]
F00E3E5C: 81c7e008                 ret
F00E3E60: 81e80000                 restore
