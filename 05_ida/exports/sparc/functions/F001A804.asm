F001A804: 9de3bf98                 save    %sp, -0x68, %sp
F001A808: 90100018                 mov     %i0, %o0
F001A80C: d4122038                 lduh    [%o0+0x38], %o2
F001A810: 9532a008                 srl     %o2, 8, %o2
F001A814: 932aa001                 sll     %o2, 1, %o1
F001A818: 9202400a                 add     %o1, %o2, %o1
F001A81C: 932a6002                 sll     %o1, 2, %o1
F001A820: 9222400a                 sub     %o1, %o2, %o1
F001A824: 932a6002                 sll     %o1, 2, %o1
F001A828: 153c04729412a1f0         set     _cdevsw, %o2
F001A830: 9202400a                 add     %o1, %o2, %o1
F001A834: d4026014                 ld      [%o1+0x14], %o2
F001A838: 9fc28000                 call    %o2
F001A83C: 92102000                 mov     0, %o1
F001A840: 81c7e008                 ret
F001A844: 81e80000                 restore
