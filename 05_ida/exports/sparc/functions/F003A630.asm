F003A630: 9de3bf58                 save    %sp, -0xA8, %sp
F003A634: 90100018                 mov     %i0, %o0
F003A638: 4000067a                 call    sub_F003C020
F003A63C: 9210001a                 mov     %i2, %o1
F003A640: b0920000                 orcc    %o0, %g0, %i0
F003A644: 32800005                 bne,a   loc_F003A658
F003A648: d206201c                 ld      [%i0+0x1C], %o1
F003A64C: 90102046                 mov     0x46, %o0 ! 'F'
F003A650: 10800013                 ba      locret_F003A69C
F003A654: d0264000                 st      %o0, [%i1]
F003A658: 113c04cf                 sethi   %hi(_active_u), %o0
F003A65C: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F003A660: a007bfb8                 add     %fp, var_48, %l0
F003A664: d6026014                 ld      [%o1+0x14], %o3
F003A668: 90100018                 mov     %i0, %o0
F003A66C: d402a01c                 ld      [%o2+0x1C], %o2
F003A670: 9fc2c000                 call    %o3
F003A674: 92100010                 mov     %l0, %o1
F003A678: b4920000                 orcc    %o0, %g0, %i2
F003A67C: 32800006                 bne,a   loc_F003A694
F003A680: f4264000                 st      %i2, [%i1]
F003A684: 90100010                 mov     %l0, %o0
F003A688: 7ffffd50                 call    _vattr_to_nattr
F003A68C: 92066004                 add     %i1, 4, %o1
F003A690: f4264000                 st      %i2, [%i1]
F003A694: 7fffb934                 call    _vn_rele
F003A698: 90100018                 mov     %i0, %o0
F003A69C: 81c7e008                 ret
F003A6A0: 81e80000                 restore
