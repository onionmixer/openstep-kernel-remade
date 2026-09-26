F0030D54: 9de3bf98                 save    %sp, -0x68, %sp
F0030D58: 90102010                 mov     0x10, %o0! void *
F0030D5C: d0366008                 sth     %o0, [%i1+8]
F0030D60: e2066004                 ld      [%i1+4], %l1
F0030D64: 92102010                 mov     0x10, %o1! size_t
F0030D68: a0064011                 add     %i1, %l1, %l0
F0030D6C: 4001903b                 call    _bzero
F0030D70: 90100010                 mov     %l0, %o0
F0030D74: 90102002                 mov     2, %o0
F0030D78: d0364011                 sth     %o0, [%i1+%l1]
F0030D7C: d0162010                 lduh    [%i0+0x10], %o0
F0030D80: d0342002                 sth     %o0, [%l0+2]
F0030D84: d006200c                 ld      [%i0+0xC], %o0
F0030D88: d0242004                 st      %o0, [%l0+4]
F0030D8C: 81c7e008                 ret
F0030D90: 81e80000                 restore
