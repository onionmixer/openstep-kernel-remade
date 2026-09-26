F00C9818: 9de3bf90                 save    %sp, -0x70, %sp
F00C981C: d0062108                 ld      [%i0+0x108], %o0! id
F00C9820: 133c0506                 sethi   %hi(paNuminterrupts), %o1
F00C9824: d20260dc                 ld      [%o1+%lo(paNuminterrupts)], %o1! SEL
F00C9828: 4000a012                 call    _objc_msgSend
F00C982C: a0102000                 mov     0, %l0
F00C9830: a2100008                 mov     %o0, %l1
F00C9834: 80a40011                 cmp     %l0, %l1
F00C9838: 3a800014                 bcc,a   locret_F00C9888
F00C983C: b0102000                 mov     0, %i0
F00C9840: 253c0506                 sethi   -0xFEBE800, %l2
F00C9844: 273c0506                 sethi   -0xFEBE800, %l3
F00C9848: 90100018                 mov     %i0, %o0! id
F00C984C: d204a0d8                 ld      [%l2+0xD8], %o1! SEL
F00C9850: 4000a008                 call    _objc_msgSend
F00C9854: 94100010                 mov     %l0, %o2
F00C9858: 80a22000                 cmp     %o0, 0
F00C985C: 02800007                 be      loc_F00C9878
F00C9860: a0042001                 inc     %l0
F00C9864: d204e0d4                 ld      [%l3+0xD4], %o1! SEL
F00C9868: 4000a002                 call    _objc_msgSend
F00C986C: 90100018                 mov     %i0, %o0
F00C9870: 10800006                 ba      locret_F00C9888
F00C9874: b0103d27                 mov     -0x2D9, %i0
F00C9878: 80a40011                 cmp     %l0, %l1
F00C987C: 0abffff4                 bcs     loc_F00C984C
F00C9880: 90100018                 mov     %i0, %o0
F00C9884: b0102000                 mov     0, %i0
F00C9888: 81c7e008                 ret
F00C988C: 81e80000                 restore
