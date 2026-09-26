
undefined4 * _alloc_posix_proc(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x1e);
  _bzero(puVar1,0x1e);
  *puVar1 = 0;
  return puVar1;
}

