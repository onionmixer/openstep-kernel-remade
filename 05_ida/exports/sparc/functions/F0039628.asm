F0039628: 9de3bf98                 save    %sp, -0x68, %sp
F003962C: 40014ae5                 call    _vnode_uncache
F0039630: 90100018                 mov     %i0, %o0
F0039634: 4000cf19                 call    _mfs_invalidate
F0039638: 90100018                 mov     %i0, %o0
F003963C: d2062030                 ld      [%i0+0x30], %o1
F0039640: 90100018                 mov     %i0, %o0
F0039644: 7fffb1b8                 call    _dnlc_purge_vp
F0039648: c02260c0                 clr     [%o1+0xC0]
F003964C: 7fffaf6a                 call    _binvalfree
F0039650: 90100018                 mov     %i0, %o0
F0039654: 81c7e008                 ret
F0039658: 81e80000                 restore
