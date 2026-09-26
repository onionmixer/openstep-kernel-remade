F008A340: 9de3bf90                 save    %sp, -0x70, %sp
F008A344: c027bff0                 clr     [%fp+var_10]
F008A348: 113c04d0                 sethi   %hi(_active_threads), %o0
F008A34C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008A350: 92100018                 mov     %i0, %o1
F008A354: f002200c                 ld      [%o0+0xC], %i0
F008A358: 9407bff4                 add     %fp, var_C, %o2
F008A35C: 7fffffc7                 call    _task_by_unix_pid
F008A360: 90100018                 mov     %i0, %o0
F008A364: 80a22000                 cmp     %o0, 0
F008A368: 3280000c                 bne,a   locret_F008A398
F008A36C: f007bff0                 ld      [%fp+var_10], %i0
F008A370: 7fff75e3                 call    _convert_task_to_port
F008A374: d007bff4                 ld      [%fp+var_C], %o0
F008A378: 92920000                 orcc    %o0, %g0, %o1
F008A37C: 02800006                 be      loc_F008A394
F008A380: d227bff0                 st      %o1, [%fp+var_10]
F008A384: 90100018                 mov     %i0, %o0
F008A388: 94102006                 mov     6, %o2
F008A38C: 7fff76aa                 call    _object_copyout
F008A390: 9607bff0                 add     %fp, var_10, %o3
F008A394: f007bff0                 ld      [%fp+var_10], %i0
F008A398: 81c7e008                 ret
F008A39C: 81e80000                 restore
