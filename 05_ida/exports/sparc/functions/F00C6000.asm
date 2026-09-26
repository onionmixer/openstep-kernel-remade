F00C6000: 9de3bf98                 save    %sp, -0x68, %sp
F00C6004: b610001a                 mov     %i2, %i3
F00C6008: b53ea01f                 sra     %i2, 31, %i2
F00C600C: 9736e01b                 srl     %i3, 27, %o3
F00C6010: 952ea005                 sll     %i2, 5, %o2
F00C6014: 9012c00a                 or      %o3, %o2, %o0
F00C6018: 932ee005                 sll     %i3, 5, %o1
F00C601C: 92a2401b                 subcc   %o1, %i3, %o1
F00C6020: 9062001a                 subc    %o0, %i2, %o0
F00C6024: 9b32601e                 srl     %o1, 30, %o5
F00C6028: 992a2002                 sll     %o0, 2, %o4
F00C602C: 9413400c                 or      %o5, %o4, %o2
F00C6030: 972a6002                 sll     %o1, 2, %o3
F00C6034: 96a2c01b                 subcc   %o3, %i3, %o3
F00C6038: 9462801a                 subc    %o2, %i2, %o2
F00C603C: 9b32e01c                 srl     %o3, 28, %o5
F00C6040: 992aa004                 sll     %o2, 4, %o4
F00C6044: 9013400c                 or      %o5, %o4, %o0
F00C6048: 932ae004                 sll     %o3, 4, %o1
F00C604C: 9282401b                 addcc   %o1, %i3, %o1
F00C6050: 9042001a                 addc    %o0, %i2, %o0
F00C6054: 9b32601d                 srl     %o1, 29, %o5
F00C6058: 992a2003                 sll     %o0, 3, %o4
F00C605C: 9413400c                 or      %o5, %o4, %o2
F00C6060: 972a6003                 sll     %o1, 3, %o3
F00C6064: 96a2c01b                 subcc   %o3, %i3, %o3
F00C6068: 9462801a                 subc    %o2, %i2, %o2
F00C606C: 9b32e01b                 srl     %o3, 27, %o5
F00C6070: 992aa005                 sll     %o2, 5, %o4
F00C6074: 9013400c                 or      %o5, %o4, %o0
F00C6078: 932ae005                 sll     %o3, 5, %o1
F00C607C: 92a2400b                 subcc   %o1, %o3, %o1
F00C6080: 9062000a                 subc    %o0, %o2, %o0
F00C6084: 9732601e                 srl     %o1, 30, %o3
F00C6088: 952a2002                 sll     %o0, 2, %o2
F00C608C: 9812c00a                 or      %o3, %o2, %o4
F00C6090: 9b2a6002                 sll     %o1, 2, %o5
F00C6094: 9a83401b                 addcc   %o5, %i3, %o5
F00C6098: 9843001a                 addc    %o4, %i2, %o4
F00C609C: 93336017                 srl     %o5, 23, %o1
F00C60A0: 912b2009                 sll     %o4, 9, %o0
F00C60A4: 94124008                 or      %o1, %o0, %o2
F00C60A8: 972b6009                 sll     %o5, 9, %o3
F00C60AC: 90100018                 mov     %i0, %o0
F00C60B0: 92100019                 mov     %i1, %o1
F00C60B4: 7ffea01c                 call    _ns_timeout
F00C60B8: 98102004                 mov     4, %o4
F00C60BC: 81c7e008                 ret
F00C60C0: 81e80000                 restore
