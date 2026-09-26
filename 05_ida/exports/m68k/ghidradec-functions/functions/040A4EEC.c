
void sub_40A4EEC(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_A6;
  
  iVar1 = *(int *)(unaff_A6 + 0xc);
  uVar3 = (*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a;
  if (uVar3 == 0) {
    iVar2 = 4;
    uVar3 = *(uint *)(unaff_A6 + -200) | 0x40000000;
    if (iVar1 != 0) {
      mem_write(uVar3);
      return;
    }
  }
  else if (uVar3 == 4) {
    iVar2 = 2;
    uVar3 = *(uint *)(unaff_A6 + -200) | 0x40000000;
    if (iVar1 != 0) {
      mem_write(uVar3);
      return;
    }
  }
  else {
    if (uVar3 != 6) {
      return;
    }
    iVar2 = 1;
    uVar3 = *(uint *)(unaff_A6 + -200) | 0x40000000;
    if (iVar1 != 0) {
      mem_write(uVar3);
      return;
    }
  }
  *(uint *)(unaff_A6 + -0x54) = uVar3;
  get_fline();
  if (iVar2 == 4) {
    reg_dest();
    return;
  }
  if (iVar2 == 2) {
    reg_dest();
    return;
  }
  reg_dest();
  return;
}
