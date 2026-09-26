F007E254: 9de3bf90                 save    %sp, -0x70, %sp
F007E258: d0062004                 ld      [%i0+4], %o0
F007E25C: 80a22018                 cmp     %o0, 0x18
F007E260: 12800008                 bne     loc_F007E280
F007E264: 90103ed0                 mov     -0x130, %o0
F007E268: d0060000                 ld      [%i0], %o0
F007E26C: 23200000                 sethi   0x80000000, %l1
F007E270: 808a0011                 btst    %l1, %o0
F007E274: 02800005                 be      loc_F007E288
F007E278: 01000000                 nop
F007E27C: 90103ed0                 mov     -0x130, %o0
F007E280: 1080001d                 ba      locret_F007E2F4
F007E284: d026601c                 st      %o0, [%i1+0x1C]
F007E288: 7fffa59b                 call    _convert_port_to_task
F007E28C: d0062008                 ld      [%i0+8], %o0! target_task
F007E290: a0100008                 mov     %o0, %l0
F007E294: 9206602c                 add     %i1, 0x2C, %o1 ! ','! act_list
F007E298: 7fffd577                 call    _task_threads
F007E29C: 9407bff4                 add     %fp, var_C, %o2
F007E2A0: d026601c                 st      %o0, [%i1+0x1C]
F007E2A4: 7fffd381                 call    _task_deallocate
F007E2A8: 90100010                 mov     %l0, %o0
F007E2AC: d006601c                 ld      [%i1+0x1C], %o0
F007E2B0: 80a22000                 cmp     %o0, 0
F007E2B4: 12800010                 bne     locret_F007E2F4
F007E2B8: 92102030                 mov     0x30, %o1 ! '0'
F007E2BC: d0064000                 ld      [%i1], %o0
F007E2C0: d2266004                 st      %o1, [%i1+4]
F007E2C4: 90120011                 bset    %l1, %o0
F007E2C8: d0264000                 st      %o0, [%i1]
F007E2CC: 113c0444                 sethi   %hi(dword_F01112F4), %o0
F007E2D0: d20222f4                 ld      [%o0+%lo(dword_F01112F4)], %o1
F007E2D4: d2266020                 st      %o1, [%i1+0x20]
F007E2D8: 901222f4                 bset    %lo(dword_F01112F4), %o0
F007E2DC: d2022004                 ld      [%o0+4], %o1
F007E2E0: d2266024                 st      %o1, [%i1+0x24]
F007E2E4: d0022008                 ld      [%o0+8], %o0
F007E2E8: d207bff4                 ld      [%fp+var_C], %o1
F007E2EC: d0266028                 st      %o0, [%i1+0x28]
F007E2F0: d2266028                 st      %o1, [%i1+0x28]
F007E2F4: 81c7e008                 ret
F007E2F8: 81e80000                 restore
