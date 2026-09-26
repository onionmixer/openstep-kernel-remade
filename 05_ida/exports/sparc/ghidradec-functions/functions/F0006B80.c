
int .stret2(int param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int unaff_i0;
  int iVar3;
  int unaff_fp;
  int unaff_i7;
  
  if ((param_2 & 0xfff) == *(uint *)(unaff_i7 + 8)) {
    iVar3 = *(int *)(unaff_fp + 0x40);
    do {
      uVar1 = param_2 - 2;
      bVar2 = 1 < (int)param_2;
      *(undefined2 *)(iVar3 + uVar1) = *(undefined2 *)(param_1 + uVar1);
      param_2 = uVar1;
    } while (uVar1 != 0 && bVar2);
    return iVar3;
  }
  return unaff_i0;
}
