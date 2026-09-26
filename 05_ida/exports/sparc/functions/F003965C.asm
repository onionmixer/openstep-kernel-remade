F003965C: 9de3bf98                 save    %sp, -0x68, %sp
F0039660: 90100018                 mov     %i0, %o0
F0039664: 40001dcf                 call    _sync_vp_invalidate
F0039668: 92100019                 mov     %i1, %o1
F003966C: 40014ad5                 call    _vnode_uncache
F0039670: 90100018                 mov     %i0, %o0
F0039674: d2062030                 ld      [%i0+0x30], %o1
F0039678: 90100018                 mov     %i0, %o0
F003967C: 7fffb1aa                 call    _dnlc_purge_vp
F0039680: c02260c0                 clr     [%o1+0xC0]
F0039684: 7fffaf5c                 call    _binvalfree
F0039688: 90100018                 mov     %i0, %o0
F003968C: 81c7e008                 ret
F0039690: 81e80000                 restore
