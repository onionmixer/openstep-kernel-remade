F006E5D0: 9de3bf98                 save    %sp, -0x68, %sp
F006E5D4: 4000a16d                 call    _splusclock
F006E5D8: 01000000                 nop
F006E5DC: a4100008                 mov     %o0, %l2
F006E5E0: 4000a4ca                 call    _clock_value
F006E5E4: 90102000                 mov     0, %o0
F006E5E8: 153c0440                 sethi   %hi(qword_F0110058), %o2
F006E5EC: d602a058                 ld      [%o2+%lo(qword_F0110058)], %o3
F006E5F0: a0100008                 mov     %o0, %l0
F006E5F4: a2100009                 mov     %o1, %l1
F006E5F8: 80a2c010                 cmp     %o3, %l0
F006E5FC: 18800009                 bgu     loc_F006E620
F006E600: 9412a058                 bset    %lo(qword_F0110058), %o2
F006E604: 80a2c010                 cmp     %o3, %l0
F006E608: 12800017                 bne     loc_F006E664
F006E60C: 113c0440                 sethi   -0xFEF0000, %o0
F006E610: d002a004                 ld      [%o2+4], %o0
F006E614: 80a20011                 cmp     %o0, %l1
F006E618: 08800013                 bleu    loc_F006E664
F006E61C: 113c0440                 sethi   -0xFEF0000, %o0
F006E620: 113c0440                 sethi   %hi(qword_F0110058), %o0
F006E624: d81a2058                 ldd     [%o0+%lo(qword_F0110058)], %o4
F006E628: 96a34011                 subcc   %o5, %l1, %o3
F006E62C: 94630010                 subc    %o4, %l0, %o2
F006E630: 80a2a000                 cmp     %o2, 0
F006E634: 3880000d                 bgu,a   loc_F006E668
F006E638: e03a2058                 std     %l0, [%o0+%lo(qword_F0110058)]
F006E63C: 12800007                 bne     loc_F006E658
F006E640: 01000000                 nop
F006E644: 110ee6b2901221ff         set     0x3B9AC9FF, %o0
F006E64C: 80a2c008                 cmp     %o3, %o0
F006E650: 38800005                 bgu,a   loc_F006E664
F006E654: 113c0440                 sethi   -0xFEF0000, %o0
F006E658: a010000c                 mov     %o4, %l0
F006E65C: a210000d                 mov     %o5, %l1
F006E660: 113c0440                 sethi   -0xFEF0000, %o0
F006E664: e03a2058                 std     %l0, [%o0+0x58]
F006E668: 4000a1af                 call    _splx
F006E66C: 90100012                 mov     %l2, %o0
F006E670: 90100010                 mov     %l0, %o0
F006E674: 92100011                 mov     %l1, %o1
F006E678: 7ffffed7                 call    _ns_time_to_timeval
F006E67C: 94100018                 mov     %i0, %o2
F006E680: 81c7e008                 ret
F006E684: 81e80000                 restore
