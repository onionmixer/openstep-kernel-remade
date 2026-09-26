F00EE350: 9de3bf98                 save    %sp, -0x68, %sp
F00EE354: a0100018                 mov     %i0, %l0
F00EE358: 90100010                 mov     %l0, %o0! info
F00EE35C: 7ffffed0                 call    _NXPtrHash
F00EE360: d2064000                 ld      [%i1], %o1! data
F00EE364: b0100008                 mov     %o0, %i0
F00EE368: 90100010                 mov     %l0, %o0! info
F00EE36C: 7ffffecc                 call    _NXPtrHash
F00EE370: d2066004                 ld      [%i1+4], %o1! data
F00EE374: a2100008                 mov     %o0, %l1
F00EE378: 90100010                 mov     %l0, %o0! info
F00EE37C: 7ffffec8                 call    _NXPtrHash
F00EE380: d2066008                 ld      [%i1+8], %o1
F00EE384: b01e0011                 btog    %l1, %i0
F00EE388: b01e0008                 btog    %o0, %i0
F00EE38C: d006600c                 ld      [%i1+0xC], %o0
F00EE390: b01e0008                 btog    %o0, %i0
F00EE394: 81c7e008                 ret
F00EE398: 81e80000                 restore
