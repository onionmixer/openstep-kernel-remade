F00E2FA8: 9de3bf98                 save    %sp, -0x68, %sp
F00E2FAC: d2062004                 ld      [%i0+4], %o1
F00E2FB0: 80a260a8                 cmp     %o1, 0xA8
F00E2FB4: 12800005                 bne     loc_F00E2FC8
F00E2FB8: d00e2003                 ldub    [%i0+3], %o0
F00E2FBC: 80a22000                 cmp     %o0, 0
F00E2FC0: 22800005                 be,a    loc_F00E2FD4
F00E2FC4: d0062018                 ld      [%i0+0x18], %o0
F00E2FC8: 90103ed0                 mov     -0x130, %o0
F00E2FCC: 10800023                 ba      locret_F00E3058
F00E2FD0: d026601c                 st      %o0, [%i1+0x1C]
F00E2FD4: 133c03e6                 sethi   %hi(dword_F00F99DC), %o1
F00E2FD8: d20261dc                 ld      [%o1+%lo(dword_F00F99DC)], %o1
F00E2FDC: 80a20009                 cmp     %o0, %o1
F00E2FE0: 12800014                 bne     loc_F00E3030
F00E2FE4: 90103ed0                 mov     -0x130, %o0
F00E2FE8: d0062020                 ld      [%i0+0x20], %o0
F00E2FEC: 133c03e6                 sethi   %hi(dword_F00F99E0), %o1
F00E2FF0: d20261e0                 ld      [%o1+%lo(dword_F00F99E0)], %o1
F00E2FF4: 80a20009                 cmp     %o0, %o1
F00E2FF8: 1280000e                 bne     loc_F00E3030
F00E2FFC: 90103ed0                 mov     -0x130, %o0
F00E3000: d0062064                 ld      [%i0+0x64], %o0
F00E3004: 133c03e6                 sethi   %hi(dword_F00F99E4), %o1
F00E3008: d20261e4                 ld      [%o1+%lo(dword_F00F99E4)], %o1
F00E300C: 80a20009                 cmp     %o0, %o1
F00E3010: 12800008                 bne     loc_F00E3030
F00E3014: 90103ed0                 mov     -0x130, %o0
F00E3018: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00E301C: d006200c                 ld      [%i0+0xC], %o0
F00E3020: 96062068                 add     %i0, 0x68, %o3 ! 'h'
F00E3024: d206201c                 ld      [%i0+0x1C], %o1
F00E3028: 7fffc969                 call    _EvFrameBufferDevicePort
F00E302C: 98066024                 add     %i1, 0x24, %o4 ! '$'
F00E3030: d026601c                 st      %o0, [%i1+0x1C]
F00E3034: d006601c                 ld      [%i1+0x1C], %o0
F00E3038: 80a22000                 cmp     %o0, 0
F00E303C: 12800007                 bne     locret_F00E3058
F00E3040: 92102028                 mov     0x28, %o1 ! '('
F00E3044: c02e6003                 clrb    [%i1+3]
F00E3048: 113c03e6                 sethi   %hi(dword_F00F99E8), %o0
F00E304C: d00221e8                 ld      [%o0+%lo(dword_F00F99E8)], %o0
F00E3050: d2266004                 st      %o1, [%i1+4]
F00E3054: d0266020                 st      %o0, [%i1+0x20]
F00E3058: 81c7e008                 ret
F00E305C: 81e80000                 restore
