
uint _fsfull(int param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aFsfull);
    }
    puVar2 = aOutOfInodes;
    puVar3 = aCreateSymlinkF;
  }
  else {
    puVar2 = aFileSystemFull;
    puVar3 = aWriteFailedFil;
  }
  uVar1 = param_2 & (int)*(char *)(param_1 + 0xd3);
  if (uVar1 == 0) {
    uVar1 = _fserr(param_1,puVar2);
  }
  *(byte *)(param_1 + 0xd3) = (byte)param_2 | *(byte *)(param_1 + 0xd3);
  if ((*(byte *)(_active_u + 0x254) & 8) == 0) {
    uVar1 = _uprintf(aSS_0,param_1 + 0xd4,puVar3);
  }
  if (*(int *)(dword_40B57D4 + 0x66) == 0) {
    *(int *)(dword_40B57D4 + 0x66) = param_1;
    *(byte *)(dword_40B57D4 + 0x6a) = (byte)param_2;
  }
  *(undefined *)(dword_40B57D4 + 100) = 0x1c;
  return uVar1;
}
