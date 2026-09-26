F00E41F4: 9de3bf90                 save    %sp, -0x70, %sp
F00E41F8: d2062004                 ld      [%i0+4], %o1
F00E41FC: 80a26048                 cmp     %o1, 0x48 ! 'H'
F00E4200: 12800005                 bne     loc_F00E4214
F00E4204: d00e2003                 ldub    [%i0+3], %o0
F00E4208: 80a22000                 cmp     %o0, 0
F00E420C: 22800005                 be,a    loc_F00E4220
F00E4210: d0062018                 ld      [%i0+0x18], %o0
F00E4214: 90103ed0                 mov     -0x130, %o0
F00E4218: 10800037                 ba      locret_F00E42F4
F00E421C: d026601c                 st      %o0, [%i1+0x1C]
F00E4220: 133c03e6                 sethi   %hi(dword_F00F9B18), %o1
F00E4224: d2026318                 ld      [%o1+%lo(dword_F00F9B18)], %o1
F00E4228: 80a20009                 cmp     %o0, %o1
F00E422C: 1280002a                 bne     loc_F00E42D4
F00E4230: 90103ed0                 mov     -0x130, %o0
F00E4234: d0062020                 ld      [%i0+0x20], %o0
F00E4238: 133c03e6                 sethi   %hi(dword_F00F9B1C), %o1
F00E423C: d202631c                 ld      [%o1+%lo(dword_F00F9B1C)], %o1
F00E4240: 80a20009                 cmp     %o0, %o1
F00E4244: 12800024                 bne     loc_F00E42D4
F00E4248: 90103ed0                 mov     -0x130, %o0
F00E424C: d0062028                 ld      [%i0+0x28], %o0
F00E4250: 133c03e6                 sethi   %hi(dword_F00F9B20), %o1
F00E4254: d2026320                 ld      [%o1+%lo(dword_F00F9B20)], %o1
F00E4258: 80a20009                 cmp     %o0, %o1
F00E425C: 1280001e                 bne     loc_F00E42D4
F00E4260: 90103ed0                 mov     -0x130, %o0
F00E4264: d0062030                 ld      [%i0+0x30], %o0
F00E4268: 133c03e6                 sethi   %hi(dword_F00F9B24), %o1
F00E426C: d2026324                 ld      [%o1+%lo(dword_F00F9B24)], %o1
F00E4270: 80a20009                 cmp     %o0, %o1
F00E4274: 12800018                 bne     loc_F00E42D4
F00E4278: 90103ed0                 mov     -0x130, %o0
F00E427C: d0062038                 ld      [%i0+0x38], %o0
F00E4280: 133c03e6                 sethi   %hi(dword_F00F9B28), %o1
F00E4284: d2026328                 ld      [%o1+%lo(dword_F00F9B28)], %o1
F00E4288: 80a20009                 cmp     %o0, %o1
F00E428C: 12800012                 bne     loc_F00E42D4
F00E4290: 90103ed0                 mov     -0x130, %o0
F00E4294: d0062040                 ld      [%i0+0x40], %o0
F00E4298: 133c03e6                 sethi   %hi(dword_F00F9B2C), %o1
F00E429C: d202632c                 ld      [%o1+%lo(dword_F00F9B2C)], %o1
F00E42A0: 80a20009                 cmp     %o0, %o1
F00E42A4: 1280000c                 bne     loc_F00E42D4
F00E42A8: 90103ed0                 mov     -0x130, %o0
F00E42AC: 7fffe755                 call    _audio_port_to_stream
F00E42B0: d006200c                 ld      [%i0+0xC], %o0
F00E42B4: d206201c                 ld      [%i0+0x1C], %o1
F00E42B8: d4062024                 ld      [%i0+0x24], %o2
F00E42BC: d606202c                 ld      [%i0+0x2C], %o3
F00E42C0: d8062034                 ld      [%i0+0x34], %o4
F00E42C4: c4062044                 ld      [%i0+0x44], %g2
F00E42C8: da06203c                 ld      [%i0+0x3C], %o5
F00E42CC: 7fffea4d                 call    __NXAudioRecordStream
F00E42D0: c423a05c                 st      %g2, [%sp+0x70+var_14]
F00E42D4: d026601c                 st      %o0, [%i1+0x1C]
F00E42D8: d006601c                 ld      [%i1+0x1C], %o0
F00E42DC: 80a22000                 cmp     %o0, 0
F00E42E0: 12800005                 bne     locret_F00E42F4
F00E42E4: 92102020                 mov     0x20, %o1 ! ' '
F00E42E8: 90102001                 mov     1, %o0
F00E42EC: d02e6003                 stb     %o0, [%i1+3]
F00E42F0: d2266004                 st      %o1, [%i1+4]
F00E42F4: 81c7e008                 ret
F00E42F8: 81e80000                 restore
