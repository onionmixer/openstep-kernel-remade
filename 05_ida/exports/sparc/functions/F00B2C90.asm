F00B2C90: 9de3bf98                 save    %sp, -0x68, %sp
F00B2C94: 113c0477                 sethi   %hi(dword_F011DDA0), %o0
F00B2C98: d00221a0                 ld      [%o0+%lo(dword_F011DDA0)], %o0
F00B2C9C: 80a22000                 cmp     %o0, 0
F00B2CA0: 02800005                 be      loc_F00B2CB4
F00B2CA4: 113c0477                 sethi   %hi(aPathGetencodef), %o0! "path_getencodefunc: for device <%s>\n"
F00B2CA8: d206200c                 ld      [%i0+0xC], %o1
F00B2CAC: 7ffd866b                 call    _printf
F00B2CB0: 901221a8                 bset    %lo(aPathGetencodef), %o0! "path_getencodefunc: for device <%s>\n"
F00B2CB4: 113c0477                 sethi   %hi(_dev_path_opstab), %o0! __s1
F00B2CB8: 80a62000                 cmp     %i0, 0
F00B2CBC: 0280000f                 be      loc_F00B2CF8
F00B2CC0: a01223bc                 or      %o0, %lo(_dev_path_opstab), %l0
F00B2CC4: d2040000                 ld      [%l0], %o1! __s2
F00B2CC8: 80a26000                 cmp     %o1, 0
F00B2CCC: 2280000c                 be,a    locret_F00B2CFC
F00B2CD0: b0102000                 mov     0, %i0
F00B2CD4: 7ffd5536                 call    _strcmp
F00B2CD8: d006200c                 ld      [%i0+0xC], %o0
F00B2CDC: 80a22000                 cmp     %o0, 0
F00B2CE0: 12800004                 bne     loc_F00B2CF0
F00B2CE4: 80a62000                 cmp     %i0, 0
F00B2CE8: 10800005                 ba      locret_F00B2CFC
F00B2CEC: f0042008                 ld      [%l0+8], %i0
F00B2CF0: 12bffff5                 bne     loc_F00B2CC4
F00B2CF4: a0042010                 inc     0x10, %l0
F00B2CF8: b0102000                 mov     0, %i0
F00B2CFC: 81c7e008                 ret
F00B2D00: 81e80000                 restore
