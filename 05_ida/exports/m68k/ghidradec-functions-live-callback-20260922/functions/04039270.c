
void _clrblock(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 2) {
    iVar4 = (int)param_3 >> 2;
    iVar3 = (param_3 & 3) * 2;
    iVar2 = 3;
loc_40392C4:
    *(byte *)(param_2 + iVar4) = ~(byte)(iVar2 << iVar3) & *(byte *)(param_2 + iVar4);
    return;
  }
  if (iVar3 < 3) {
    if (iVar3 == 1) {
      pbVar1 = (byte *)(param_2 + ((int)param_3 >> 3));
      *pbVar1 = ~(byte)(1 << (param_3 & 7)) & *pbVar1;
      return;
    }
  }
  else {
    if (iVar3 == 4) {
      iVar4 = (int)param_3 >> 1;
      iVar3 = (param_3 & 1) << 2;
      iVar2 = 0xf;
      goto loc_40392C4;
    }
    if (iVar3 == 8) {
      *(undefined *)(param_2 + param_3) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aClrblock);
}

