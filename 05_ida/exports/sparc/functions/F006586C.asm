F006586C: 9de3bf98                 save    %sp, -0x68, %sp
F0065870: d2062008                 ld      [%i0+8], %o1
F0065874: 1100003f901223ff         set     0xFFFF, %o0
F006587C: 920a4008                 and     %o1, %o0, %o1
F0065880: 80a26009                 cmp     %o1, 9
F0065884: 0280000e                 be      loc_F00658BC
F0065888: 01000000                 nop
F006588C: 18800005                 bgu     loc_F00658A0
F0065890: 80a26008                 cmp     %o1, 8
F0065894: 02800007                 be      loc_F00658B0
F0065898: 01000000                 nop
F006589C: 3080000d                 ba,a    locret_F00658D0
F00658A0: 80a26011                 cmp     %o1, 0x11
F00658A4: 02800009                 be      loc_F00658C8
F00658A8: 90102000                 mov     0, %o0
F00658AC: 30800009                 ba,a    locret_F00658D0
F00658B0: 4000850e                 call    _vm_object_destroy
F00658B4: 90100018                 mov     %i0, %o0
F00658B8: 30800006                 ba,a    locret_F00658D0
F00658BC: 40000989                 call    _vm_object_pager_wakeup
F00658C0: 90100018                 mov     %i0, %o0
F00658C4: 30800003                 ba,a    locret_F00658D0
F00658C8: 40001839                 call    _netipc_ignore
F00658CC: 92100018                 mov     %i0, %o1
F00658D0: 81c7e008                 ret
F00658D4: 81e80000                 restore
