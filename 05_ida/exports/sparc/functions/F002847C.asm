F002847C: 9de3bf58                 save    %sp, -0xA8, %sp
F0028480: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0028484: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0028488: e0022024                 ld      [%o0+0x24], %l0
F002848C: a207bfb8                 add     %fp, var_48, %l1
F0028490: 40000401                 call    _vattr_null
F0028494: 90100011                 mov     %l1, %o0
F0028498: d0042004                 ld      [%l0+4], %o0
F002849C: d037bfbe                 sth     %o0, [%fp+var_42]
F00284A0: d0042008                 ld      [%l0+8], %o0
F00284A4: d037bfc0                 sth     %o0, [%fp+var_40]
F00284A8: d0040000                 ld      [%l0], %o0
F00284AC: 400000db                 call    _fdsetattr
F00284B0: 92100011                 mov     %l1, %o1
F00284B4: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F00284B8: d02a6038                 stb     %o0, [%o1+0x38]
F00284BC: 81c7e008                 ret
F00284C0: 81e80000                 restore
