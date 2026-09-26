
void nrm_set(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  sword *in_A0;
  
  iVar2 = *(int *)(in_A0 + 2);
  iVar3 = (uint)(iVar2 != 0) * LZCOUNT(iVar2);
  if (iVar2 != 0) {
    *in_A0 = *in_A0 - (sword)iVar3;
    uVar1 = *(uint *)(in_A0 + 4);
    *(uint *)(in_A0 + 4) = uVar1 << iVar3;
    *(uint *)(in_A0 + 2) = uVar1 >> (0x20U - iVar3 & 0x3f) | *(int *)(in_A0 + 2) << iVar3;
    return;
  }
  iVar2 = *(int *)(in_A0 + 4);
  iVar3 = (uint)(iVar2 != 0) * LZCOUNT(iVar2);
  *in_A0 = (*in_A0 + -0x20) - (sword)iVar3;
  *(int *)(in_A0 + 2) = iVar2 << iVar3;
  in_A0[4] = 0;
  in_A0[5] = 0;
  return;
}
