F007CAA0: 9de3bf98                 save    %sp, -0x68, %sp
F007CAA4: d0062004                 ld      [%i0+4], %o0
F007CAA8: 80a22018                 cmp     %o0, 0x18
F007CAAC: 12800006                 bne     loc_F007CAC4
F007CAB0: 90103ed0                 mov     -0x130, %o0
F007CAB4: d0060000                 ld      [%i0], %o0
F007CAB8: 80a22000                 cmp     %o0, 0
F007CABC: 16800004                 bge     loc_F007CACC
F007CAC0: 90103ed0                 mov     -0x130, %o0
F007CAC4: 10800013                 ba      locret_F007CB10
F007CAC8: d026601c                 st      %o0, [%i1+0x1C]
F007CACC: 7fffa1f0                 call    _convert_port_to_host
F007CAD0: d0062008                 ld      [%i0+8], %o0! host
F007CAD4: 7fffa0f3                 call    _host_kernel_version
F007CAD8: 9206602c                 add     %i1, 0x2C, %o1 ! ','
F007CADC: 80a22000                 cmp     %o0, 0
F007CAE0: 1280000c                 bne     locret_F007CB10
F007CAE4: d026601c                 st      %o0, [%i1+0x1C]
F007CAE8: 9010222c                 mov     0x22C, %o0
F007CAEC: d0266004                 st      %o0, [%i1+4]
F007CAF0: 113c0444                 sethi   %hi(dword_F01110C4), %o0
F007CAF4: d20220c4                 ld      [%o0+%lo(dword_F01110C4)], %o1
F007CAF8: d2266020                 st      %o1, [%i1+0x20]
F007CAFC: 901220c4                 bset    %lo(dword_F01110C4), %o0
F007CB00: d2022004                 ld      [%o0+4], %o1
F007CB04: d2266024                 st      %o1, [%i1+0x24]
F007CB08: d0022008                 ld      [%o0+8], %o0
F007CB0C: d0266028                 st      %o0, [%i1+0x28]
F007CB10: 81c7e008                 ret
F007CB14: 81e80000                 restore
