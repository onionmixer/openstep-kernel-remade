F007D0E8: 9de3bf90                 save    %sp, -0x70, %sp
F007D0EC: d0062004                 ld      [%i0+4], %o0
F007D0F0: 80a22020                 cmp     %o0, 0x20 ! ' '
F007D0F4: 1280000e                 bne     loc_F007D12C
F007D0F8: 90103ed0                 mov     -0x130, %o0
F007D0FC: d0060000                 ld      [%i0], %o0
F007D100: 80a22000                 cmp     %o0, 0
F007D104: 1680000a                 bge     loc_F007D12C
F007D108: 90103ed0                 mov     -0x130, %o0
F007D10C: d2062018                 ld      [%i0+0x18], %o1
F007D110: 1104480090122018         set     0x11200018, %o0
F007D118: 920a7ffc                 and     %o1, -4, %o1
F007D11C: 80a24008                 cmp     %o1, %o0
F007D120: 02800005                 be      loc_F007D134
F007D124: 01000000                 nop
F007D128: 90103ed0                 mov     -0x130, %o0
F007D12C: 10800025                 ba      locret_F007D1C0
F007D130: d026601c                 st      %o0, [%i1+0x1C]
F007D134: 7fffa0cb                 call    _convert_port_to_pset_name
F007D138: d006201c                 ld      [%i0+0x1C], %o0
F007D13C: a0100008                 mov     %o0, %l0
F007D140: 7fffa070                 call    _convert_port_to_host_priv
F007D144: d0062008                 ld      [%i0+8], %o0! host_priv
F007D148: 92100010                 mov     %l0, %o1! set_name
F007D14C: 7fff9f79                 call    _host_processor_set_priv
F007D150: 9407bff4                 add     %fp, var_C, %o2
F007D154: d026601c                 st      %o0, [%i1+0x1C]
F007D158: 7fffc7f8                 call    _pset_deallocate
F007D15C: 90100010                 mov     %l0, %o0
F007D160: d006601c                 ld      [%i1+0x1C], %o0
F007D164: 80a22000                 cmp     %o0, 0
F007D168: 12800016                 bne     locret_F007D1C0
F007D16C: 01000000                 nop
F007D170: d006201c                 ld      [%i0+0x1C], %o0
F007D174: 80a22000                 cmp     %o0, 0
F007D178: 02800006                 be      loc_F007D190
F007D17C: 80a23fff                 cmp     %o0, -1
F007D180: 22800005                 be,a    loc_F007D194
F007D184: 90102028                 mov     0x28, %o0 ! '('
F007D188: 7fff77e5                 call    _ipc_port_release_send
F007D18C: 01000000                 nop
F007D190: 90102028                 mov     0x28, %o0 ! '('
F007D194: d0266004                 st      %o0, [%i1+4]
F007D198: d0064000                 ld      [%i1], %o0
F007D19C: 13200000                 sethi   0x80000000, %o1
F007D1A0: 90120009                 bset    %o1, %o0
F007D1A4: d0264000                 st      %o0, [%i1]
F007D1A8: 113c0444                 sethi   %hi(dword_F0111124), %o0
F007D1AC: d2022124                 ld      [%o0+%lo(dword_F0111124)], %o1
F007D1B0: d007bff4                 ld      [%fp+var_C], %o0
F007D1B4: 7fffa0d6                 call    _convert_pset_to_port
F007D1B8: d2266020                 st      %o1, [%i1+0x20]
F007D1BC: d0266024                 st      %o0, [%i1+0x24]
F007D1C0: 81c7e008                 ret
F007D1C4: 81e80000                 restore
