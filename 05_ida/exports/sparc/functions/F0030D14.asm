F0030D14: 9de3bf98                 save    %sp, -0x68, %sp
F0030D18: 90102010                 mov     0x10, %o0! void *
F0030D1C: d0366008                 sth     %o0, [%i1+8]
F0030D20: e2066004                 ld      [%i1+4], %l1
F0030D24: 92102010                 mov     0x10, %o1! size_t
F0030D28: a0064011                 add     %i1, %l1, %l0
F0030D2C: 4001904b                 call    _bzero
F0030D30: 90100010                 mov     %l0, %o0
F0030D34: 90102002                 mov     2, %o0
F0030D38: d0364011                 sth     %o0, [%i1+%l1]
F0030D3C: d0162018                 lduh    [%i0+0x18], %o0
F0030D40: d0342002                 sth     %o0, [%l0+2]
F0030D44: d0062014                 ld      [%i0+0x14], %o0
F0030D48: d0242004                 st      %o0, [%l0+4]
F0030D4C: 81c7e008                 ret
F0030D50: 81e80000                 restore
