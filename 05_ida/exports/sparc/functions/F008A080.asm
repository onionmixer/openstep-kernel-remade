F008A080: 9de3bf90                 save    %sp, -0x70, %sp
F008A084: 40006eed                 call    _flush_user_windows_to_stack
F008A088: 01000000                 nop
F008A08C: d0066068                 ld      [%i1+0x68], %o0! target_task
F008A090: 133c0442                 sethi   %hi(_kernel_task), %o1
F008A094: d2026250                 ld      [%o1+%lo(_kernel_task)], %o1
F008A098: 9407bff4                 add     %fp, parent_task, %o2! size_t
F008A09C: 921a0009                 btog    %o0, %o1! ledgers
F008A0A0: 80a00009                 cmp     %g0, %o1
F008A0A4: 7fffa38d                 call    _task_create
F008A0A8: 92402000                 addc    %g0, 0, %o1
F008A0AC: 92920000                 orcc    %o0, %g0, %o1
F008A0B0: 02800004                 be      loc_F008A0C0
F008A0B4: 113c0447                 sethi   %hi(aForkProcdupTas), %o0! "fork/procdup: task_create failed. Code:"...
F008A0B8: 7ffe2968                 call    _printf
F008A0BC: 901221f8                 bset    %lo(aForkProcdupTas), %o0! "fork/procdup: task_create failed. Code:"...
F008A0C0: d007bff4                 ld      [%fp+parent_task], %o0
F008A0C4: 7fffa3f9                 call    _task_deallocate
F008A0C8: d0262068                 st      %o0, [%i0+0x68]
F008A0CC: d007bff4                 ld      [%fp+parent_task], %o0! parent_task
F008A0D0: 9207bff0                 add     %fp, var_10, %o1! child_act
F008A0D4: 7fffa80c                 call    _thread_create
F008A0D8: f022203c                 st      %i0, [%o0+0x3C]
F008A0DC: 92920000                 orcc    %o0, %g0, %o1
F008A0E0: 02800005                 be      loc_F008A0F4
F008A0E4: 01000000                 nop
F008A0E8: 113c0447                 sethi   %hi(aForkProcdupThr), %o0! "fork/procdup: thread_create failed. Cod"...
F008A0EC: 7ffe295b                 call    _printf
F008A0F0: 90122228                 bset    %lo(aForkProcdupThr), %o0! "fork/procdup: thread_create failed. Cod"...
F008A0F4: 7fffa8ae                 call    _thread_deallocate
F008A0F8: d007bff0                 ld      [%fp+var_10], %o0
F008A0FC: d007bff0                 ld      [%fp+var_10], %o0
F008A100: 7fff9e11                 call    _compute_priority
F008A104: 92102000                 mov     0, %o1
F008A108: d0066068                 ld      [%i1+0x68], %o0
F008A10C: d207bff4                 ld      [%fp+parent_task], %o1
F008A110: d0022038                 ld      [%o0+0x38], %o0! void *
F008A114: d2026038                 ld      [%o1+0x38], %o1! void *
F008A118: 40002a7e                 call    _bcopy
F008A11C: 94102294                 mov     0x294, %o2
F008A120: d007bff4                 ld      [%fp+parent_task], %o0
F008A124: d0022038                 ld      [%o0+0x38], %o0! void *
F008A128: 92102018                 mov     0x18, %o1! size_t
F008A12C: 40002b4b                 call    _bzero
F008A130: 90022244                 inc     0x244, %o0
F008A134: d207bff4                 ld      [%fp+parent_task], %o1
F008A138: d0026038                 ld      [%o1+0x38], %o0
F008A13C: c0222158                 clr     [%o0+0x158]
F008A140: d0026038                 ld      [%o1+0x38], %o0
F008A144: 7ffe058d                 call    _expand_fdlist
F008A148: d2022154                 ld      [%o0+0x154], %o1
F008A14C: d207bff4                 ld      [%fp+parent_task], %o1
F008A150: d0066068                 ld      [%i1+0x68], %o0
F008A154: d2026038                 ld      [%o1+0x38], %o1
F008A158: d0022038                 ld      [%o0+0x38], %o0
F008A15C: d4026154                 ld      [%o1+0x154], %o2! size_t
F008A160: d002214c                 ld      [%o0+0x14C], %o0! void *
F008A164: 9402a001                 inc     %o2
F008A168: d202614c                 ld      [%o1+0x14C], %o1! void *
F008A16C: 40002a69                 call    _bcopy
F008A170: 952aa002                 sll     %o2, 2, %o2
F008A174: d207bff4                 ld      [%fp+parent_task], %o1
F008A178: d0066068                 ld      [%i1+0x68], %o0
F008A17C: d2026038                 ld      [%o1+0x38], %o1
F008A180: d0022038                 ld      [%o0+0x38], %o0
F008A184: d4026154                 ld      [%o1+0x154], %o2! size_t
F008A188: d0022150                 ld      [%o0+0x150], %o0! void *
F008A18C: d2026150                 ld      [%o1+0x150], %o1! void *
F008A190: 40002a60                 call    _bcopy
F008A194: 9402a001                 inc     %o2
F008A198: d207bff0                 ld      [%fp+var_10], %o1
F008A19C: d002600c                 ld      [%o1+0xC], %o0
F008A1A0: d0022038                 ld      [%o0+0x38], %o0
F008A1A4: f0220000                 st      %i0, [%o0]
F008A1A8: d002600c                 ld      [%o1+0xC], %o0
F008A1AC: d0022038                 ld      [%o0+0x38], %o0! void *
F008A1B0: 92102048                 mov     0x48, %o1 ! 'H'! size_t
F008A1B4: 40002b29                 call    _bzero
F008A1B8: 9002216c                 inc     0x16C, %o0
F008A1BC: d007bff0                 ld      [%fp+var_10], %o0
F008A1C0: d002200c                 ld      [%o0+0xC], %o0
F008A1C4: d0022038                 ld      [%o0+0x38], %o0! void *
F008A1C8: 92102048                 mov     0x48, %o1 ! 'H'! size_t
F008A1CC: 40002b23                 call    _bzero
F008A1D0: 900221b4                 inc     0x1B4, %o0
F008A1D4: f007bff0                 ld      [%fp+var_10], %i0
F008A1D8: d006200c                 ld      [%i0+0xC], %o0
F008A1DC: d0022038                 ld      [%o0+0x38], %o0
F008A1E0: c022202c                 clr     [%o0+0x2C]
F008A1E4: 81c7e008                 ret
F008A1E8: 81e80000                 restore
