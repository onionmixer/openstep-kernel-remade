
int _km_convert_addr(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  while (((*(int *)((int)&unk_40B6978 + iVar2) == 0 ||
          (uVar1 = *(uint *)((int)&unk_40B6970 + iVar2), param_1 < uVar1)) ||
         (uVar1 + *(int *)((int)&unk_40B6978 + iVar2) <= param_1))) {
    iVar2 = iVar2 + 0xc;
    iVar3 = iVar3 + 1;
    if (5 < iVar3) {
      _log(3,aKmConvertAddr0,param_1,(int)byte_40B6964);
                    /* WARNING: Subroutine does not return */
      _panic(aKmConvertAddrH);
    }
  }
  return *(int *)((int)&dword_40B6974 + iVar2) + (param_1 - uVar1);
}

