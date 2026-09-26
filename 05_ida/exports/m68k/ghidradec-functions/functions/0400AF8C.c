
uint _thread_psignal(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 < 0x21) {
    uVar3 = 1 << (param_2 - 1 & 0x3f);
    if ((uVar3 & 0x1ef8) == 0) {
      _printf(aSignalD);
                    /* WARNING: Subroutine does not return */
      _panic(aThreadPsignalS);
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x34);
    param_2 = uVar3 & *(uint *)(iVar2 + 0x20);
    if ((param_2 == 0) || ((*(byte *)(iVar2 + 0x2b) & 0x10) != 0)) {
      puVar1 = (uint *)(*(int *)(param_1 + 0x80) + 0x72);
      *puVar1 = uVar3 | *puVar1;
    }
  }
  return param_2;
}

