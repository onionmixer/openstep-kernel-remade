F00E9570: 9de3bf80                 save    %sp, -0x80, %sp
F00E9574: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00E9578: e80222e0                 ld      [%o0+%lo(paEventdriver_0)], %l4
F00E957C: 113c0505                 sethi   %hi(paInstance), %o0
F00E9580: e6022278                 ld      [%o0+%lo(paInstance)], %l3
F00E9584: 90100014                 mov     %l4, %o0! id
F00E9588: 400020ba                 call    _objc_msgSend
F00E958C: 92100013                 mov     %l3, %o1
F00E9590: 94100018                 mov     %i0, %o2
F00E9594: 9607bfe8                 add     %fp, var_18, %o3
F00E9598: 133c0504                 sethi   %hi(paRegisterscreen), %o1
F00E959C: 980621fc                 add     %i0, 0x1FC, %o4
F00E95A0: d20263b8                 ld      [%o1+%lo(paRegisterscreen)], %o1! SEL
F00E95A4: 400020b3                 call    _objc_msgSend
F00E95A8: 9a07bfe4                 add     %fp, __len, %o5
F00E95AC: a2100008                 mov     %o0, %l1
F00E95B0: 80a47fff                 cmp     %l1, -1
F00E95B4: 0280002d                 be      loc_F00E9668
F00E95B8: 11000005                 sethi   0x1400, %o0
F00E95BC: d407bfe4                 ld      [%fp+__len], %o2! __len
F00E95C0: a4122048                 or      %o0, 0x48, %l2
F00E95C4: 80a28012                 cmp     %o2, %l2
F00E95C8: 18800017                 bgu     loc_F00E9624
F00E95CC: 90100018                 mov     %i0, %o0! __b
F00E95D0: e00621fc                 ld      [%i0+0x1FC], %l0
F00E95D4: 92102000                 mov     0, %o1! __c
F00E95D8: 7ffc7369                 call    _memset
F00E95DC: 90100010                 mov     %l0, %o0
F00E95E0: 90102001                 mov     1, %o0
F00E95E4: d02c2008                 stb     %o0, [%l0+8]
F00E95E8: d017bfe8                 lduh    [%fp+var_18], %o0
F00E95EC: d0342030                 sth     %o0, [%l0+0x30]
F00E95F0: d217bfea                 lduh    [%fp+var_16], %o1
F00E95F4: 94100011                 mov     %l1, %o2
F00E95F8: d2342032                 sth     %o1, [%l0+0x32]
F00E95FC: d217bfec                 lduh    [%fp+var_14], %o1
F00E9600: 90100018                 mov     %i0, %o0! id
F00E9604: d2342034                 sth     %o1, [%l0+0x34]
F00E9608: d617bfee                 lduh    [%fp+var_12], %o3
F00E960C: 133c0504                 sethi   %hi(paSettoken), %o1
F00E9610: d20263b0                 ld      [%o1+%lo(paSettoken)], %o1! SEL
F00E9614: d6342036                 sth     %o3, [%l0+0x36]
F00E9618: 40002096                 call    _objc_msgSend
F00E961C: b0102000                 mov     0, %i0
F00E9620: 30800013                 ba,a    locret_F00E966C
F00E9624: 133c0504                 sethi   %hi(paName), %o1
F00E9628: 213c03f2                 sethi   %hi(aSShmemSizeSize), %l0! "%s: shmem_size > sizeof (StdFBShmem_t)("...
F00E962C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00E9630: 40002090                 call    _objc_msgSend
F00E9634: a0142310                 bset    %lo(aSShmemSizeSize), %l0! "%s: shmem_size > sizeof (StdFBShmem_t)("...
F00E9638: 92100008                 mov     %o0, %o1! SEL
F00E963C: 90100010                 mov     %l0, %o0
F00E9640: d407bfe4                 ld      [%fp+__len], %o2
F00E9644: 7fff72ac                 call    _IOLog
F00E9648: 96100012                 mov     %l2, %o3
F00E964C: 90100014                 mov     %l4, %o0! id
F00E9650: 40002088                 call    _objc_msgSend
F00E9654: 92100013                 mov     %l3, %o1
F00E9658: 133c0504                 sethi   %hi(paUnregisterscre), %o1
F00E965C: d20263b4                 ld      [%o1+%lo(paUnregisterscre)], %o1! SEL
F00E9660: 40002084                 call    _objc_msgSend
F00E9664: 94100011                 mov     %l1, %o2
F00E9668: b0103d3e                 mov     -0x2C2, %i0
F00E966C: 81c7e008                 ret
F00E9670: 81e80000                 restore
