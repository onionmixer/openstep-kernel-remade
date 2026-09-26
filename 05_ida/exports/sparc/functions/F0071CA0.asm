F0071CA0: 9de3bf98                 save    %sp, -0x68, %sp
F0071CA4: d0062070                 ld      [%i0+0x70], %o0
F0071CA8: 133c04f0                 sethi   %hi(_sched_tick), %o1
F0071CAC: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F0071CB0: 80a20009                 cmp     %o0, %o1
F0071CB4: 22800005                 be,a    loc_F0071CC8
F0071CB8: 133c04d4                 sethi   -0xFECB000, %o1
F0071CBC: 7fffff63                 call    _update_priority
F0071CC0: 90100018                 mov     %i0, %o0
F0071CC4: 133c04d4                 sethi   -0xFECB000, %o1
F0071CC8: d00260d4                 ld      [%o1+0xD4], %o0
F0071CCC: 80a22000                 cmp     %o0, 0
F0071CD0: 0480001a                 ble     loc_F0071D38
F0071CD4: 921260d4                 bset    0xD4, %o1
F0071CD8: d8027ff8                 ld      [%o1-8], %o4
F0071CDC: 90027ff8                 add     %o1, -8, %o0
F0071CE0: d603210c                 ld      [%o4+0x10C], %o3
F0071CE4: 80a2c008                 cmp     %o3, %o0
F0071CE8: 12800004                 bne     loc_F0071CF8
F0071CEC: d4032110                 ld      [%o4+0x110], %o2
F0071CF0: 10800003                 ba      loc_F0071CFC
F0071CF4: d4227ffc                 st      %o2, [%o1-4]
F0071CF8: d422e110                 st      %o2, [%o3+0x110]
F0071CFC: 133c04d4901260cc         set     unk_F01350CC, %o0
F0071D04: 80a28008                 cmp     %o2, %o0
F0071D08: 22800003                 be,a    loc_F0071D14
F0071D0C: d62260cc                 st      %o3, [%o1+0xCC]
F0071D10: d622a10c                 st      %o3, [%o2+0x10C]
F0071D14: 113c04d3901223c0         set     _default_pset, %o0
F0071D1C: d2022114                 ld      [%o0+0x114], %o1
F0071D20: 92027fff                 inc     -1, %o1
F0071D24: d2222114                 st      %o1, [%o0+0x114]
F0071D28: f0232118                 st      %i0, [%o4+0x118]
F0071D2C: 90102003                 mov     3, %o0
F0071D30: 10800021                 ba      locret_F0071DB4
F0071D34: d0232114                 st      %o0, [%o4+0x114]
F0071D38: d0062194                 ld      [%i0+0x194], %o0
F0071D3C: 80a22000                 cmp     %o0, 0
F0071D40: 12800004                 bne     loc_F0071D50
F0071D44: 113c04d8                 sethi   -0xFECA000, %o0
F0071D48: 10800008                 ba      loc_F0071D68
F0071D4C: 94027eec                 add     %o1, -0x114, %o2
F0071D50: d40223d0                 ld      [%o0+0x3D0], %o2
F0071D54: 133c04cf                 sethi   %hi(_need_ast), %o1
F0071D58: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0071D5C: 90122004                 bset    4, %o0
F0071D60: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F0071D64: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0071D68: 9010000a                 mov     %o2, %o0
F0071D6C: 7fffffa4                 call    _run_queue_enqueue
F0071D70: 92100018                 mov     %i0, %o1
F0071D74: 80a66000                 cmp     %i1, 0
F0071D78: 0280000f                 be      locret_F0071DB4
F0071D7C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0071D80: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0071D84: d2022058                 ld      [%o0+0x58], %o1
F0071D88: d0062058                 ld      [%i0+0x58], %o0
F0071D8C: 80a24008                 cmp     %o1, %o0
F0071D90: 16800009                 bge     locret_F0071DB4
F0071D94: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F0071D98: d00221b0                 ld      [%o0+%lo(_processor_ptr)], %o0
F0071D9C: c0222124                 clr     [%o0+0x124]
F0071DA0: 133c04cf                 sethi   %hi(_need_ast), %o1
F0071DA4: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0071DA8: 90122004                 bset    4, %o0
F0071DAC: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F0071DB0: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0071DB4: 81c7e008                 ret
F0071DB8: 81e80000                 restore
