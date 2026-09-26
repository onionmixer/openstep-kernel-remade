
byte _mach_clock_bootstrap(void)

{
  code cVar1;
  code *pcVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  
  iVar3 = _kmem_alloc_wired(_kernel_map,&_mtime,_page_size);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aMappableTimeIn);
  }
  _bzero(_mtime,_page_size);
  cVar4 = '\0';
  _get_calendar_time_value(_time);
  pcVar2 = _mtime;
  bVar5 = _mtime == (code *)0x0;
  cVar1 = (code)0x0;
  if (!bVar5) {
    *(code *)((int)_mtime + 8) = _time;
    *(undefined4 *)((int)pcVar2 + 4) = dword_40AF7F0;
    cVar1 = _time;
    *pcVar2 = _time;
    bVar5 = cVar1 == (code)0x0;
  }
  return cVar4 << 4 | ((int)cVar1 < 0) << 3 | bVar5 << 2;
}

