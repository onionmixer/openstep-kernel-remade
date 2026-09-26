F007F044: 9de3bf90                 save    %sp, -0x70, %sp
F007F048: d0062004                 ld      [%i0+4], %o0
F007F04C: 80a22018                 cmp     %o0, 0x18
F007F050: 12800008                 bne     loc_F007F070
F007F054: 90103ed0                 mov     -0x130, %o0
F007F058: d0060000                 ld      [%i0], %o0
F007F05C: 23200000                 sethi   0x80000000, %l1
F007F060: 808a0011                 btst    %l1, %o0
F007F064: 02800005                 be      loc_F007F078
F007F068: 01000000                 nop
F007F06C: 90103ed0                 mov     -0x130, %o0
F007F070: 10800018                 ba      locret_F007F0D0
F007F074: d026601c                 st      %o0, [%i1+0x1C]
F007F078: 7fffa21f                 call    _convert_port_to_task
F007F07C: d0062008                 ld      [%i0+8], %o0! parent_task
F007F080: a0100008                 mov     %o0, %l0
F007F084: 7fffd420                 call    _thread_create
F007F088: 9207bff4                 add     %fp, var_C, %o1
F007F08C: d026601c                 st      %o0, [%i1+0x1C]
F007F090: 7fffd006                 call    _task_deallocate
F007F094: 90100010                 mov     %l0, %o0
F007F098: d006601c                 ld      [%i1+0x1C], %o0
F007F09C: 80a22000                 cmp     %o0, 0
F007F0A0: 1280000c                 bne     locret_F007F0D0
F007F0A4: 92102028                 mov     0x28, %o1 ! '('
F007F0A8: d0064000                 ld      [%i1], %o0
F007F0AC: d2266004                 st      %o1, [%i1+4]
F007F0B0: 90120011                 bset    %l1, %o0
F007F0B4: d0264000                 st      %o0, [%i1]
F007F0B8: 113c0444                 sethi   %hi(dword_F01113D0), %o0
F007F0BC: d20223d0                 ld      [%o0+%lo(dword_F01113D0)], %o1
F007F0C0: d007bff4                 ld      [%fp+var_C], %o0
F007F0C4: 7fffa2a5                 call    _convert_thread_to_port
F007F0C8: d2266020                 st      %o1, [%i1+0x20]
F007F0CC: d0266024                 st      %o0, [%i1+0x24]
F007F0D0: 81c7e008                 ret
F007F0D4: 81e80000                 restore
