# Decompiler issue boundary

The retry result is based on branch targets and raw register/memory instructions. It does not
depend on a recovered C prototype for `_pmap_enter`, `_splvm`, `_splx`, `_zalloc`, or `_zfree`.

Reading an SPL-level global in `_splvm` is not treated as proof of a lock acquisition or a
runtime scheduling guarantee.
