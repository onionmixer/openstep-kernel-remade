/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f48c */

void _rnode_cache_clear(void)

{
  undefined4 *puVar1;
  
  while (puVar1 = _rpfreelist, _rpfreelist != (undefined4 *)0x0) {
    _rpfreelist = (undefined4 *)*_rpfreelist;
    FUN_0012f7d0(puVar1);
    _rp_rmhash(puVar1);
    _rinactive(puVar1);
    _mfs_uncache(puVar1 + 3);
    _zfree(_vm_info_zone,puVar1[3]);
    _zfree(_rnode_zone,puVar1);
  }
  return;
}

