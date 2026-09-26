F0052FFC: 9de3bf78                 save    %sp, -0x88, %sp
F0053000: f43fbfd8                 std     %i2, [%fp+var_28]
F0053004: 9007bfd8                 add     %fp, var_28, %o0
F0053008: d027bfe0                 st      %o0, [%fp+var_20]
F005300C: 90102001                 mov     1, %o0
F0053010: d027bfe4                 st      %o0, [%fp+var_1C]
F0053014: f83fbfe8                 std     %i4, [%fp+var_18]
F0053018: f627bff4                 st      %i3, [%fp+var_C]
F005301C: 9006600c                 add     %i1, 0xC, %o0
F0053020: f207a05c                 ld      [%fp+arg_5C], %i1
F0053024: 153c04cf                 sethi   %hi(_active_u), %o2
F0053028: d602a1d8                 ld      [%o2+%lo(_active_u)], %o3
F005302C: 9207bfe0                 add     %fp, var_20, %o1
F0053030: d802e01c                 ld      [%o3+0x1C], %o4
F0053034: 94100018                 mov     %i0, %o2
F0053038: 7ffff903                 call    sub_F0051444
F005303C: 96102000                 mov     0, %o3
F0053040: 80a66000                 cmp     %i1, 0
F0053044: 02800005                 be      loc_F0053058
F0053048: b0100008                 mov     %o0, %i0
F005304C: d007bff4                 ld      [%fp+var_C], %o0
F0053050: 10800006                 ba      locret_F0053068
F0053054: d0264000                 st      %o0, [%i1]
F0053058: d007bff4                 ld      [%fp+var_C], %o0
F005305C: 80a22000                 cmp     %o0, 0
F0053060: 32800002                 bne,a   locret_F0053068
F0053064: b0102005                 mov     5, %i0
F0053068: 81c7e008                 ret
F005306C: 81e80000                 restore
