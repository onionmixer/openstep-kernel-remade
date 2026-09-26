
int _isblock(int param_1,int param_2,uint param_3)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 2) {
    bVar2 = (byte)(3 << (param_3 & 3) * 2);
    iVar1 = (int)param_3 >> 2;
  }
  else if (iVar1 < 3) {
    if (iVar1 != 1) {
loc_4039256:
                    /* WARNING: Subroutine does not return */
      _panic(&aIsblock);
    }
    bVar2 = (byte)(1 << (param_3 & 7));
    iVar1 = (int)param_3 >> 3;
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 != 8) goto loc_4039256;
      bVar3 = *(char *)(param_2 + param_3) == -1;
      goto loc_4039250;
    }
    bVar2 = (byte)(0xf << ((param_3 & 1) << 2));
    iVar1 = (int)param_3 >> 1;
  }
  bVar3 = bVar2 == (*(byte *)(param_2 + iVar1) & bVar2);
loc_4039250:
  return -(int)(char)-bVar3;
}
