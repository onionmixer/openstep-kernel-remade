# VM-map bulk copies include `WORD +0x28`

The exact VM-map prefix contains 22 `REP MOVSD` sites with `ECX=0xb`. Python calculates that eleven dwords copy 44 bytes, covering offsets `0x00..0x2b`; therefore each bulk copy includes the two bytes at `WORD +0x28`.

One `_vm_map_fork` site immediately stores zero to its copy destination's `+0x28`. For the other 21 sites, no explicit `+0x28` store appears within the following fifteen exported instructions. This fills the bulk-copy exclusion in the prior explicit-writer inventory: destination values may be inherited from the source on those paths.

The result does not prove that all copied objects are the same entry type, that paths execute, or that later alias/bulk writes do not change the field. Open Item 1 remains **in progress**.
