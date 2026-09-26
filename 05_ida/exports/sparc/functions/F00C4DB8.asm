F00C4DB8: 9de3bf88                 save    %sp, -0x78, %sp
F00C4DBC: 90100018                 mov     %i0, %o0
F00C4DC0: 7ffffe78                 call    sub_F00C47A0
F00C4DC4: 9207bfec                 add     %fp, var_14, %o1
F00C4DC8: 80a22000                 cmp     %o0, 0
F00C4DCC: 12800004                 bne     locret_F00C4DDC
F00C4DD0: b0103fff                 mov     -1, %i0
F00C4DD4: d007bfec                 ld      [%fp+var_14], %o0
F00C4DD8: f0022008                 ld      [%o0+8], %i0
F00C4DDC: 81c7e008                 ret
F00C4DE0: 81e80000                 restore
