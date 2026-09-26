
void __setuid(void)

{
  sword sVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  sword sVar7;
  sword sVar8;
  
  sVar1 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 6);
  sVar2 = *(sword *)(*(int *)(dword_40B57D4 + 0x24) + 2);
  iVar4 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  if (sVar2 < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    sVar3 = *(sword *)(iVar4 + 6);
    iVar5 = _suser();
    sVar8 = sVar2;
    sVar7 = sVar2;
    if (((iVar5 == 0) && (sVar8 = sVar1, sVar7 = sVar3, sVar1 != sVar2)) && (sVar3 != sVar2)) {
      *(undefined *)(dword_40B57D4 + 100) = 1;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0;
      _lock_write((int)_active_u + 0x1e);
      uVar6 = _crcopy(*(undefined4 *)((int)_active_u + 0x1a));
      *(undefined4 *)((int)_active_u + 0x1a) = uVar6;
      iVar5 = *(int *)((int)_active_u + 0x1a);
      *(sword *)(iVar4 + 4) = sVar8;
      *(sword *)(iVar5 + 6) = sVar8;
      iVar5 = *_active_u;
      *(sword *)(*(int *)((int)_active_u + 0x1a) + 2) = sVar2;
      *(sword *)(iVar5 + 0x2c) = sVar2;
      _lock_done((int)_active_u + 0x1e);
      *(sword *)(iVar4 + 6) = sVar7;
    }
  }
  return;
}
