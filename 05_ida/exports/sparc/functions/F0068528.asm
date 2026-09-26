F0068528: 9de3bf98                 save    %sp, -0x68, %sp
F006852C: 153c04f09412a0c0         set     _stackStats, %o2
F0068534: 213c04f0a01420e0         set     _stack_queue_lock, %l0
F006853C: d202a004                 ld      [%o2+4], %o1
F0068540: 90100010                 mov     %l0, %o0
F0068544: 92027fff                 inc     -1, %o1
F0068548: 4000021f                 call    _lock_write
F006854C: d222a004                 st      %o1, [%o2+4]
F0068550: b0063ff4                 inc     -0xC, %i0
F0068554: 7fffff8c                 call    sub_F0068384
F0068558: 90100018                 mov     %i0, %o0
F006855C: 400002b6                 call    _lock_done
F0068560: 90100010                 mov     %l0, %o0
F0068564: 133c043e                 sethi   %hi(dword_F010FB08), %o1
F0068568: d0026308                 ld      [%o1+%lo(dword_F010FB08)], %o0
F006856C: 80a22000                 cmp     %o0, 0
F0068570: 02800007                 be      loc_F006858C
F0068574: 113c04bd                 sethi   %hi(dword_F012F670), %o0
F0068578: c0226308                 clr     [%o1+%lo(dword_F010FB08)]
F006857C: 90122270                 bset    %lo(dword_F012F670), %o0
F0068580: 92102000                 mov     0, %o1
F0068584: 4000229e                 call    _thread_wakeup_prim
F0068588: 94102000                 mov     0, %o2
F006858C: 113c043e                 sethi   %hi(dword_F010FB00), %o0
F0068590: d2022300                 ld      [%o0+%lo(dword_F010FB00)], %o1
F0068594: 113c043e                 sethi   %hi(dword_F010FB04), %o0
F0068598: d0022304                 ld      [%o0+%lo(dword_F010FB04)], %o0
F006859C: 80a24008                 cmp     %o1, %o0
F00685A0: 04800004                 ble     locret_F00685B0
F00685A4: 01000000                 nop
F00685A8: 7fffff91                 call    sub_F00683EC
F00685AC: 90100018                 mov     %i0, %o0
F00685B0: 81c7e008                 ret
F00685B4: 81e80000                 restore
