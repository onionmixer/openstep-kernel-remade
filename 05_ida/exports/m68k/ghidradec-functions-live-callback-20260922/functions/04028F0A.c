
void _rnode_cache_clear(void)

{
  undefined4 *puVar1;
  
  puVar1 = _rpfreelist;
  while (puVar1 != (undefined4 *)0x0) {
    _rpfreelist = (undefined4 *)*puVar1;
    sub_402935A(puVar1);
    _rp_rmhash(puVar1);
    _rinactive(puVar1);
    _mfs_uncache(puVar1 + 3);
    _zfree(_vm_info_zone,puVar1[3]);
    _zfree(_rnode_zone,puVar1);
    puVar1 = _rpfreelist;
  }
  _rpfreelist = puVar1;
  return;
}

