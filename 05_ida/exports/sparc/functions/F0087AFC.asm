F0087AFC: 9de3bf98                 save    %sp, -0x68, %sp
F0087B00: 113c0447                 sethi   %hi(aVmObjectReques), %o0! "vm_object_request_object: called\n"
F0087B04: 7ffe32d5                 call    _printf
F0087B08: 901220b0                 bset    %lo(aVmObjectReques), %o0! "vm_object_request_object: called\n"
F0087B0C: 81c7e008                 ret
F0087B10: 91e82000                 restore %g0, 0, %o0
