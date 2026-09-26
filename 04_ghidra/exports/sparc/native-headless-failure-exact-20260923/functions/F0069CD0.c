
/* WARNING: Removing unreachable block (ram,0xf0069d14) */
/* WARNING: Removing unreachable block (ram,0xf0069d50) */
/* WARNING: Removing unreachable block (ram,0xf0069cd0) */
/* WARNING: Removing unreachable block (ram,0xf0069d24) */
/* WARNING: Removing unreachable block (ram,0xf0069d0c) */
/* WARNING: Removing unreachable block (ram,0xf0069ce8) */

undefined8 _mach_clock_bootstrap(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = _kernel_map;
  _kmem_alloc_wired(_kernel_map,&_mtime,_page_size);
  if (iVar2 == 0) {
    puVar3 = _mtime;
    _blkclr(_mtime,_page_size);
    _spl6();
    _get_calendar_time_value(&_time);
    puVar1 = _mtime;
    if (_mtime != (undefined4 *)0x0) {
      _mtime[2] = _time;
      puVar1[1] = DAT_f010fbec;
      *puVar1 = _time;
    }
    _spln(puVar3);
    return CONCAT44(param_2,param_1);
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_mappable_time_init_f010fc08);
}

