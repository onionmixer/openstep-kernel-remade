F007C3FC: 9de3bf90                 save    %sp, -0x70, %sp
F007C400: d0062004                 ld      [%i0+4], %o0
F007C404: 80a22018                 cmp     %o0, 0x18
F007C408: 12800007                 bne     loc_F007C424
F007C40C: 90103ed0                 mov     -0x130, %o0
F007C410: d0060000                 ld      [%i0], %o0
F007C414: 21200000                 sethi   0x80000000, %l0
F007C418: 808a0010                 btst    %l0, %o0
F007C41C: 02800004                 be      loc_F007C42C
F007C420: 90103ed0                 mov     -0x130, %o0
F007C424: 1080001b                 ba      locret_F007C490
F007C428: d026601c                 st      %o0, [%i1+0x1C]
F007C42C: 7fffa398                 call    _convert_port_to_host
F007C430: d0062008                 ld      [%i0+8], %o0! host
F007C434: 9207bff4                 add     %fp, var_C, %o1! new_set
F007C438: 7fffcbb4                 call    _processor_set_create
F007C43C: 9407bff0                 add     %fp, var_10, %o2
F007C440: 80a22000                 cmp     %o0, 0
F007C444: 12800013                 bne     locret_F007C490
F007C448: d026601c                 st      %o0, [%i1+0x1C]
F007C44C: 92102030                 mov     0x30, %o1 ! '0'
F007C450: d0064000                 ld      [%i1], %o0
F007C454: d2266004                 st      %o1, [%i1+4]
F007C458: 90120010                 bset    %l0, %o0
F007C45C: d0264000                 st      %o0, [%i1]
F007C460: 113c0444                 sethi   %hi(dword_F0111090), %o0
F007C464: d2022090                 ld      [%o0+%lo(dword_F0111090)], %o1
F007C468: d007bff4                 ld      [%fp+var_C], %o0
F007C46C: 7fffa428                 call    _convert_pset_to_port
F007C470: d2266020                 st      %o1, [%i1+0x20]
F007C474: d0266024                 st      %o0, [%i1+0x24]
F007C478: 113c0444                 sethi   %hi(dword_F0111094), %o0
F007C47C: d2022094                 ld      [%o0+%lo(dword_F0111094)], %o1
F007C480: d007bff0                 ld      [%fp+var_10], %o0
F007C484: 7fffa439                 call    _convert_pset_name_to_port
F007C488: d2266028                 st      %o1, [%i1+0x28]
F007C48C: d026602c                 st      %o0, [%i1+0x2C]
F007C490: 81c7e008                 ret
F007C494: 81e80000                 restore
