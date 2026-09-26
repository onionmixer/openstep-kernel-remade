F007C198: 9de3bf90                 save    %sp, -0x70, %sp
F007C19C: d0062004                 ld      [%i0+4], %o0
F007C1A0: 80a22020                 cmp     %o0, 0x20 ! ' '
F007C1A4: 1280000d                 bne     loc_F007C1D8
F007C1A8: 90103ed0                 mov     -0x130, %o0
F007C1AC: d0060000                 ld      [%i0], %o0
F007C1B0: 21200000                 sethi   0x80000000, %l0
F007C1B4: 808a0010                 btst    %l0, %o0
F007C1B8: 12800008                 bne     loc_F007C1D8
F007C1BC: 90103ed0                 mov     -0x130, %o0
F007C1C0: d0062018                 ld      [%i0+0x18], %o0
F007C1C4: 133c0444                 sethi   %hi(dword_F0111078), %o1
F007C1C8: d2026078                 ld      [%o1+%lo(dword_F0111078)], %o1
F007C1CC: 80a20009                 cmp     %o0, %o1
F007C1D0: 02800004                 be      loc_F007C1E0
F007C1D4: 90103ed0                 mov     -0x130, %o0
F007C1D8: 10800024                 ba      locret_F007C268
F007C1DC: d026601c                 st      %o0, [%i1+0x1C]
F007C1E0: 92102400                 mov     0x400, %o1
F007C1E4: d0062008                 ld      [%i0+8], %o0! processor
F007C1E8: 7fffa462                 call    _convert_port_to_processor
F007C1EC: d227bff0                 st      %o1, [%fp+var_10]
F007C1F0: 9407bff4                 add     %fp, var_C, %o2! host
F007C1F4: 96066034                 add     %i1, 0x34, %o3 ! '4'! processor_info_out
F007C1F8: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007C1FC: 7fffcbf9                 call    _processor_info
F007C200: 9807bff0                 add     %fp, var_10, %o4
F007C204: 80a22000                 cmp     %o0, 0
F007C208: 12800018                 bne     locret_F007C268
F007C20C: d026601c                 st      %o0, [%i1+0x1C]
F007C210: d0064000                 ld      [%i1], %o0
F007C214: 90120010                 bset    %l0, %o0
F007C218: d0264000                 st      %o0, [%i1]
F007C21C: 113c0444                 sethi   %hi(dword_F011107C), %o0
F007C220: d202207c                 ld      [%o0+%lo(dword_F011107C)], %o1
F007C224: d007bff4                 ld      [%fp+var_C], %o0
F007C228: 7fffa4af                 call    _convert_host_to_port
F007C22C: d2266020                 st      %o1, [%i1+0x20]
F007C230: d0266024                 st      %o0, [%i1+0x24]
F007C234: 113c0444                 sethi   %hi(dword_F0111080), %o0
F007C238: d2022080                 ld      [%o0+%lo(dword_F0111080)], %o1
F007C23C: d2266028                 st      %o1, [%i1+0x28]
F007C240: 90122080                 bset    %lo(dword_F0111080), %o0
F007C244: d2022004                 ld      [%o0+4], %o1
F007C248: d226602c                 st      %o1, [%i1+0x2C]
F007C24C: d2022008                 ld      [%o0+8], %o1
F007C250: d007bff0                 ld      [%fp+var_10], %o0
F007C254: d2266030                 st      %o1, [%i1+0x30]
F007C258: d0266030                 st      %o0, [%i1+0x30]
F007C25C: 912a2002                 sll     %o0, 2, %o0
F007C260: 90022034                 inc     0x34, %o0 ! '4'
F007C264: d0266004                 st      %o0, [%i1+4]
F007C268: 81c7e008                 ret
F007C26C: 81e80000                 restore
