/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c024 */

void _mach_clock_bootstrap(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _kmem_alloc_wired(_kernel_map,&_mtime,_page_size);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_mappable_time_init_001dee54);
  }
  _bzero(_mtime,_page_size);
  uVar3 = _splhigh();
  _get_calendar_time_value(&_time);
  puVar1 = _mtime;
  if (_mtime != (undefined4 *)0x0) {
    _mtime[2] = _time;
    puVar1[1] = DAT_001dee3c;
    *puVar1 = _time;
  }
  _splx(uVar3);
  return;
}

