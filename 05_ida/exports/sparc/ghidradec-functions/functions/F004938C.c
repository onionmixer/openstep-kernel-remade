
/* WARNING: Removing unreachable block (ram,0xf004941c) */

undefined8 _hashalloc(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar3 = *(int *)(param_1 + 0x50);
  iVar1 = param_1;
  (*param_5)(param_1,param_2,param_3,param_4);
  iVar2 = param_2;
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar3 + 0x2c);
    iVar4 = 1;
    if (1 < iVar1) {
      iVar2 = param_2 + 1;
      while( true ) {
        if (iVar1 <= iVar2) {
          iVar2 = iVar2 - iVar1;
        }
        iVar1 = param_1;
        (*param_5)(param_1,iVar2,0,param_4);
        iVar4 = iVar4 * 2;
        if (iVar1 != 0) goto locret_F0049474;
        iVar1 = *(int *)(iVar3 + 0x2c);
        if (iVar1 <= iVar4) break;
        iVar2 = iVar2 + iVar4;
      }
    }
    iVar2 = param_2 + 2;
    iVar1 = *(int *)(iVar3 + 0x2c);
    iVar4 = 2;
    .rem(iVar2,iVar1);
    if (2 < iVar1) {
      do {
        iVar1 = param_1;
        (*param_5)(param_1,iVar2,0,param_4);
        iVar2 = iVar2 + 1;
        if (iVar1 != 0) goto locret_F0049474;
        if (iVar2 == *(int *)(iVar3 + 0x2c)) {
          iVar2 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar3 + 0x2c));
    }
    iVar1 = 0;
  }
locret_F0049474:
  return CONCAT44(iVar2,iVar1);
}
