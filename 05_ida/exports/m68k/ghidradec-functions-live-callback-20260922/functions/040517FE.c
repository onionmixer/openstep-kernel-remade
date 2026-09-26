
uint _do_thread_scan(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  
  do {
    uVar3 = _do_runq_scan(_default_pset);
    uVar4 = uVar3;
    if (uVar3 == 0) {
      uVar3 = _do_runq_scan(_master_processor);
      uVar4 = uVar3;
    }
    while (0 < _stuck_count) {
      iVar2 = _stuck_count + -1;
      iVar1 = *(int *)(_stuck_threads + iVar2 * 4);
      _stuck_count = _stuck_count + -1;
      *(undefined4 *)(_stuck_threads + iVar2 * 4) = 0;
      uVar3 = *(uint *)(iVar1 + 0x48) & 0xf;
      cVar8 = 4 < uVar3;
      cVar7 = SBORROW4(4,uVar3);
      cVar5 = (int)(4 - uVar3) < 0;
      cVar6 = '\0';
      bVar9 = cVar8;
      if (uVar3 == 4) {
        _update_priority(iVar1);
        cVar5 = iVar1 < 0;
        cVar6 = iVar1 == 0;
        cVar7 = '\0';
        bVar9 = 0;
        _thread_setrun(iVar1,1);
      }
      uVar3 = (uint)(byte)(cVar8 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar9);
    }
  } while (uVar4 != 0);
  return uVar3;
}

