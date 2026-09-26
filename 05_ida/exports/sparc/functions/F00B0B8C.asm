F00B0B8C: 9de3bf98                 save    %sp, -0x68, %sp
F00B0B90: 90100018                 mov     %i0, %o0! __s1
F00B0B94: 133c0471                 sethi   %hi(aIommu), %o1! "iommu"
F00B0B98: 7ffd5d85                 call    _strcmp
F00B0B9C: 92126120                 bset    %lo(aIommu), %o1! "iommu"
F00B0BA0: 80a00008                 cmp     %g0, %o0
F00B0BA4: b0603fff                 subc    %g0, -1, %i0
F00B0BA8: 81c7e008                 ret
F00B0BAC: 81e80000                 restore
