F0047104: 9de3bf90                 save    %sp, -0x70, %sp
F0047108: a0100018                 mov     %i0, %l0
F004710C: 193c04eb                 sethi   %hi(_fifo_alloc), %o4
F0047110: d6032128                 ld      [%o4+%lo(_fifo_alloc)], %o3
F0047114: 133c043c                 sethi   %hi(dword_F010F3A0), %o1
F0047118: d00263a0                 ld      [%o1+%lo(dword_F010F3A0)], %o0
F004711C: b0132128                 or      %o4, %lo(_fifo_alloc), %i0
F0047120: 80a2c008                 cmp     %o3, %o0
F0047124: 06800020                 bl      loc_F00471A4
F0047128: 901263a0                 or      %o1, %lo(dword_F010F3A0), %o0
F004712C: d2142040                 lduh    [%l0+0x40], %o1
F0047130: 1100003f901223fe         set     0xFFFE, %o0
F0047138: 920a4008                 and     %o1, %o0, %o1
F004713C: 808a6010                 btst    0x10, %o1
F0047140: 02800008                 be      loc_F0047160
F0047144: d2342040                 sth     %o1, [%l0+0x40]
F0047148: 1100003f901223ef         set     0xFFEF, %o0
F0047150: 900a4008                 and     %o1, %o0, %o0
F0047154: d0342040                 sth     %o0, [%l0+0x40]
F0047158: 7fff2f24                 call    _wakeup
F004715C: 90100010                 mov     %l0, %o0
F0047160: 90100018                 mov     %i0, %o0
F0047164: 10800005                 ba      loc_F0047178
F0047168: 9210201a                 mov     0x1A, %o1
F004716C: d0342040                 sth     %o0, [%l0+0x40]
F0047170: 90100010                 mov     %l0, %o0! unsigned int
F0047174: 9210200a                 mov     0xA, %o1
F0047178: 7fff2d40                 call    _sleep
F004717C: 01000000                 nop
F0047180: d0142040                 lduh    [%l0+0x40], %o0
F0047184: 808a2001                 btst    1, %o0
F0047188: 12bffff9                 bne     loc_F004716C
F004718C: 90122010                 bset    0x10, %o0
F0047190: d0142040                 lduh    [%l0+0x40], %o0
F0047194: b0102000                 mov     0, %i0
F0047198: 90122001                 bset    1, %o0
F004719C: 1080000d                 ba      locret_F00471D0
F00471A0: d0342040                 sth     %o0, [%l0+0x40]
F00471A4: d4023ffc                 ld      [%o0-4], %o2
F00471A8: 9207bff4                 add     %fp, var_C, %o1
F00471AC: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00471B0: 9602c00a                 add     %o3, %o2, %o3
F00471B4: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00471B8: 4000f193                 call    _kmem_alloc_wired
F00471BC: d6232128                 st      %o3, [%o4+0x128]
F00471C0: d014208a                 lduh    [%l0+0x8A], %o0
F00471C4: f007bff4                 ld      [%fp+var_C], %i0
F00471C8: 90022001                 inc     %o0
F00471CC: d034208a                 sth     %o0, [%l0+0x8A]
F00471D0: 81c7e008                 ret
F00471D4: 81e80000                 restore
