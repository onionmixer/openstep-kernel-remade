F008A48C: 9de3bf98                 save    %sp, -0x68, %sp
F008A490: 113c0447                 sethi   %hi(aDevicePageinCa), %o0! "device_pagein called"
F008A494: 7ffe2b37                 call    _panic
F008A498: 90122258                 bset    %lo(aDevicePageinCa), %o0! "device_pagein called"
F008A49C: 81c7e008                 ret
F008A4A0: 81e80000                 restore
