
void nrm_zero(void)

{
  int iVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  word *in_A0;
  
  wVar3 = *in_A0;
  uVar4 = (uint)wVar3;
  if (-1 < (sword)(wVar3 - 0x40)) {
    nrm_set();
    return;
  }
  iVar1 = *(int *)(in_A0 + 2);
  uVar2 = *(uint *)(in_A0 + 4);
  if (iVar1 == 0) {
    if (uVar2 == 0) {
      *in_A0 = 0;
      return;
    }
    if (-1 < (sword)(wVar3 - ((word)(uVar2 != 0) * (sword)LZCOUNT(uVar2) + 0x20))) {
      nrm_set();
      return;
    }
  }
  else if (-1 < (sword)(wVar3 - (word)(iVar1 != 0) * (sword)LZCOUNT(iVar1))) {
    nrm_set();
    return;
  }
  *in_A0 = 0;
  *(uint *)(in_A0 + 2) = uVar2 >> (0x20 - uVar4 & 0x3f) | iVar1 << (uVar4 & 0x3f);
  *(uint *)(in_A0 + 4) = uVar2 << (uVar4 & 0x3f);
  return;
}
