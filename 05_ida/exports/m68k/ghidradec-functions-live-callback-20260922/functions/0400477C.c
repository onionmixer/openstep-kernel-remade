
void _flock(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined uVar4;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  if (((*puVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (*(sword *)(iVar3 + 0xc) == 1) {
      uVar2 = puVar1[1];
      if ((uVar2 & 8) == 0) {
        if ((uVar2 & 2) == 0) {
          if ((uVar2 & 1) == 0) {
            *(undefined *)(dword_40B57D4 + 100) = 0x16;
            return;
          }
        }
        else {
          puVar1[1] = uVar2 & 0xfffffffe;
        }
        uVar4 = _vno_bsd_lock(iVar3,puVar1[1]);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
      }
      else {
        _vno_bsd_unlock(iVar3,0x180);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x2d;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  return;
}

