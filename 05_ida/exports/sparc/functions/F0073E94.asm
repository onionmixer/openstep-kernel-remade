F0073E94: 9de3bf98                 save    %sp, -0x68, %sp
F0073E98: 90100018                 mov     %i0, %o0! task
F0073E9C: 133c04d3921263c0         set     _default_pset, %o1! new_set
F0073EA4: 7ffffff9                 call    _task_assign
F0073EA8: 94100019                 mov     %i1, %o2
F0073EAC: 81c7e008                 ret
F0073EB0: 91e80008                 restore %g0, %o0, %o0
