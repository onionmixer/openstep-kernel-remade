F0099B88: 9de3bf98                 save    %sp, -0x68, %sp
F0099B8C: 213c04f7                 sethi   %hi(_softhead), %l0
F0099B90: d0042190                 ld      [%l0+%lo(_softhead)], %o0
F0099B94: 80a22000                 cmp     %o0, 0
F0099B98: 0280001b                 be      locret_F0099C04
F0099B9C: b0102000                 mov     0, %i0
F0099BA0: 7ffff3fa                 call    _splusclock
F0099BA4: 01000000                 nop
F0099BA8: d6042190                 ld      [%l0+%lo(_softhead)], %o3
F0099BAC: 80a2e000                 cmp     %o3, 0
F0099BB0: 02800013                 be      loc_F0099BFC
F0099BB4: 313c04f7                 sethi   -0xFEC2400, %i0
F0099BB8: a4100010                 mov     %l0, %l2
F0099BBC: d202e008                 ld      [%o3+8], %o1
F0099BC0: d4062188                 ld      [%i0+0x188], %o2
F0099BC4: e202c000                 ld      [%o3], %l1
F0099BC8: e002e004                 ld      [%o3+4], %l0
F0099BCC: d224a190                 st      %o1, [%l2+0x190]
F0099BD0: d422e008                 st      %o2, [%o3+8]
F0099BD4: 7ffff454                 call    _splx
F0099BD8: d6262188                 st      %o3, [%i0+0x188]
F0099BDC: 9fc44000                 call    %l1
F0099BE0: 90100010                 mov     %l0, %o0
F0099BE4: 7ffff3e9                 call    _splusclock
F0099BE8: 01000000                 nop
F0099BEC: d604a190                 ld      [%l2+0x190], %o3
F0099BF0: 80a2e000                 cmp     %o3, 0
F0099BF4: 32bffff3                 bne,a   loc_F0099BC0
F0099BF8: d202e008                 ld      [%o3+8], %o1
F0099BFC: 7ffff44a                 call    _splx
F0099C00: b0102001                 mov     1, %i0
F0099C04: 81c7e008                 ret
F0099C08: 81e80000                 restore
