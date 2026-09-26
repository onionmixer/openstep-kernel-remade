F007C0F0: 9de3bf90                 save    %sp, -0x70, %sp
F007C0F4: d0062004                 ld      [%i0+4], %o0
F007C0F8: 80a22020                 cmp     %o0, 0x20 ! ' '
F007C0FC: 1280000c                 bne     loc_F007C12C
F007C100: 90103ed0                 mov     -0x130, %o0
F007C104: d0060000                 ld      [%i0], %o0
F007C108: 80a22000                 cmp     %o0, 0
F007C10C: 06800007                 bl      loc_F007C128
F007C110: 133c0444                 sethi   %hi(dword_F0111068), %o1
F007C114: d0062018                 ld      [%i0+0x18], %o0
F007C118: d2026068                 ld      [%o1+%lo(dword_F0111068)], %o1
F007C11C: 80a20009                 cmp     %o0, %o1
F007C120: 02800005                 be      loc_F007C134
F007C124: 92102400                 mov     0x400, %o1
F007C128: 90103ed0                 mov     -0x130, %o0
F007C12C: 10800019                 ba      locret_F007C190
F007C130: d026601c                 st      %o0, [%i1+0x1C]
F007C134: d0062008                 ld      [%i0+8], %o0! host
F007C138: 7fffa455                 call    _convert_port_to_host
F007C13C: d227bff4                 st      %o1, [%fp+var_C]
F007C140: 9406602c                 add     %i1, 0x2C, %o2 ! ','! host_info_out
F007C144: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007C148: 7fffa2ed                 call    _host_info
F007C14C: 9607bff4                 add     %fp, var_C, %o3
F007C150: 80a22000                 cmp     %o0, 0
F007C154: 1280000f                 bne     locret_F007C190
F007C158: d026601c                 st      %o0, [%i1+0x1C]
F007C15C: 113c0444                 sethi   %hi(dword_F011106C), %o0
F007C160: d202206c                 ld      [%o0+%lo(dword_F011106C)], %o1
F007C164: d2266020                 st      %o1, [%i1+0x20]
F007C168: 9012206c                 bset    %lo(dword_F011106C), %o0
F007C16C: d2022004                 ld      [%o0+4], %o1
F007C170: d2266024                 st      %o1, [%i1+0x24]
F007C174: d2022008                 ld      [%o0+8], %o1
F007C178: d007bff4                 ld      [%fp+var_C], %o0
F007C17C: d2266028                 st      %o1, [%i1+0x28]
F007C180: d0266028                 st      %o0, [%i1+0x28]
F007C184: 912a2002                 sll     %o0, 2, %o0
F007C188: 9002202c                 inc     0x2C, %o0 ! ','
F007C18C: d0266004                 st      %o0, [%i1+4]
F007C190: 81c7e008                 ret
F007C194: 81e80000                 restore
