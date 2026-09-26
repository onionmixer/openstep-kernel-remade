F008E628: 9de3bf90                 save    %sp, -0x70, %sp
F008E62C: d0062004                 ld      [%i0+4], %o0
F008E630: 80a22000                 cmp     %o0, 0
F008E634: 02800008                 be      locret_F008E654
F008E638: 113c0504                 sethi   %hi(paDetachinterrup), %o0! id
F008E63C: d20220c4                 ld      [%o0+%lo(paDetachinterrup)], %o1! SEL
F008E640: 40018c8c                 call    _objc_msgSend
F008E644: 90100018                 mov     %i0, %o0
F008E648: 7fff32b5                 call    _ipc_port_release_send
F008E64C: d0062004                 ld      [%i0+4], %o0
F008E650: c0262004                 clr     [%i0+4]
F008E654: 81c7e008                 ret
F008E658: 81e80000                 restore
