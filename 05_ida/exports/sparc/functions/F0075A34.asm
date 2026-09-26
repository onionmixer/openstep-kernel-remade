F0075A34: 9de3bf90                 save    %sp, -0x70, %sp
F0075A38: 90100018                 mov     %i0, %o0! parent_task
F0075A3C: 7ffff9b2                 call    _thread_create
F0075A40: 9207bff4                 add     %fp, target_act, %o1
F0075A44: 7ffffa5a                 call    _thread_deallocate
F0075A48: d007bff4                 ld      [%fp+target_act], %o0
F0075A4C: d007bff4                 ld      [%fp+target_act], %o0
F0075A50: 7ffffff5                 call    _thread_start
F0075A54: 92100019                 mov     %i1, %o1
F0075A58: d007bff4                 ld      [%fp+target_act], %o0
F0075A5C: 400002a6                 call    _thread_doswapin
F0075A60: f42220c4                 st      %i2, [%o0+0xC4]
F0075A64: d007bff4                 ld      [%fp+target_act], %o0! target_act
F0075A68: 9210201f                 mov     0x1F, %o1
F0075A6C: d2222054                 st      %o1, [%o0+0x54]
F0075A70: 92102018                 mov     0x18, %o1
F0075A74: d2222050                 st      %o1, [%o0+0x50]
F0075A78: 7ffffec8                 call    _thread_resume
F0075A7C: d2222058                 st      %o1, [%o0+0x58]
F0075A80: f007bff4                 ld      [%fp+target_act], %i0
F0075A84: 81c7e008                 ret
F0075A88: 81e80000                 restore
