F002D574: 9de3bf80                 save    %sp, -0x80, %sp
F002D578: 90102000                 mov     0, %o0
F002D57C: d4068000                 ld      [%i2], %o2
F002D580: 92102001                 mov     1, %o1
F002D584: 7fffc0f6                 call    _m_get
F002D588: d427bfe4                 st      %o2, [%fp+var_1C]
F002D58C: b4920000                 orcc    %o0, %g0, %i2
F002D590: 0280003d                 be      locret_F002D684
F002D594: 9210201c                 mov     0x1C, %o1
F002D598: d236a008                 sth     %o1, [%i2+8]
F002D59C: 90102806                 mov     0x806, %o0
F002D5A0: d037bfe8                 sth     %o0, [%fp+var_18]
F002D5A4: d236a008                 sth     %o1, [%i2+8]
F002D5A8: a607bfe8                 add     %fp, var_18, %l3
F002D5AC: 90100013                 mov     %l3, %o0! void *
F002D5B0: 213c0430a0142354         set     _arpethertempl, %l0
F002D5B8: d20c2004                 ldub    [%l0+4], %o1
F002D5BC: 94102002                 mov     2, %o2! size_t
F002D5C0: 932a6001                 sll     %o1, 1, %o1
F002D5C4: 92026002                 inc     2, %o1! void *
F002D5C8: 40019d52                 call    _bcopy
F002D5CC: 9204c009                 add     %l3, %o1, %o1
F002D5D0: d40c2004                 ldub    [%l0+4], %o2! size_t
F002D5D4: d00c2005                 ldub    [%l0+5], %o0
F002D5D8: 9207bfea                 add     %fp, var_16, %o1! void *
F002D5DC: 90028008                 add     %o2, %o0, %o0
F002D5E0: 90022008                 inc     8, %o0! void *
F002D5E4: 40019d4b                 call    _bcopy
F002D5E8: 90020010                 add     %o0, %l0, %o0
F002D5EC: 90100010                 mov     %l0, %o0! void *
F002D5F0: d256a008                 ldsh    [%i2+8], %o1! void *
F002D5F4: a410207c                 mov     0x7C, %l2 ! '|'
F002D5F8: d456a008                 ldsh    [%i2+8], %o2! size_t
F002D5FC: a4248009                 sub     %l2, %o1, %l2
F002D600: e426a004                 st      %l2, [%i2+4]
F002D604: a2068012                 add     %i2, %l2, %l1
F002D608: 40019d42                 call    _bcopy
F002D60C: 92100011                 mov     %l1, %o1! void *
F002D610: 90100019                 mov     %i1, %o0! void *
F002D614: d40c2004                 ldub    [%l0+4], %o2! size_t
F002D618: 40019d3e                 call    _bcopy
F002D61C: 92046008                 add     %l1, 8, %o1
F002D620: d20c2004                 ldub    [%l0+4], %o1
F002D624: 9007bfe4                 add     %fp, var_1C, %o0! void *
F002D628: d40c2005                 ldub    [%l0+5], %o2! size_t
F002D62C: 92026008                 inc     8, %o1! void *
F002D630: 40019d38                 call    _bcopy
F002D634: 92044009                 add     %l1, %o1, %o1
F002D638: d20c2004                 ldub    [%l0+4], %o1
F002D63C: 9010001b                 mov     %i3, %o0! void *
F002D640: d40c2005                 ldub    [%l0+5], %o2! size_t
F002D644: 932a6001                 sll     %o1, 1, %o1
F002D648: 9202400a                 add     %o1, %o2, %o1
F002D64C: 92026008                 inc     8, %o1! void *
F002D650: 40019d30                 call    _bcopy
F002D654: 92044009                 add     %l1, %o1, %o1
F002D658: 90100018                 mov     %i0, %o0
F002D65C: d4168012                 lduh    [%i2+%l2], %o2
F002D660: 9210001a                 mov     %i2, %o1
F002D664: d4324012                 sth     %o2, [%o1+%l2]
F002D668: d8146002                 lduh    [%l1+2], %o4
F002D66C: 94100013                 mov     %l3, %o2
F002D670: d6146006                 lduh    [%l1+6], %o3
F002D674: d8346002                 sth     %o4, [%l1+2]
F002D678: d6346006                 sth     %o3, [%l1+6]
F002D67C: 7ffffb13                 call    _if_output_mbuf
F002D680: c037bfe8                 clrh    [%fp+var_18]
F002D684: 81c7e008                 ret
F002D688: 81e80000                 restore
