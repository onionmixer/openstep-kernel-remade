
/* WARNING: Removing unreachable block (ram,0xf00c0228) */
/* WARNING: Removing unreachable block (ram,0xf00c01c8) */
/* WARNING: Removing unreachable block (ram,0xf00c0238) */
/* WARNING: Removing unreachable block (ram,0xf00c01bc) */

undefined8
-[EventSrcPCPointer scalePointerInX:andY:over:atRes:]
          (int param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar6;
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
  iVar6 = *param_3;
  iVar5 = *param_4;
  iVar4 = iVar6;
  if (iVar6 < 0) {
    iVar4 = -iVar6;
  }
  iVar1 = iVar5;
  if (iVar5 < 0) {
    iVar1 = -iVar5;
  }
  if (param_5 == 0) {
    param_5 = 2;
  }
  uVar2 = (iVar4 + iVar1) * 0x3e;
  .umul(param_6,param_5);
  .udiv(uVar2,param_6);
  if ((uint)(int)*(sword *)(param_1 + 0x13c) < uVar2) {
    iVar1 = 1;
    iVar4 = param_1;
    if (*(int *)(param_1 + 0x138) < 2) {
      iVar3 = 0;
    }
    else {
      do {
        iVar3 = iVar1;
        if (uVar2 <= (uint)(int)*(sword *)(iVar4 + 0x13e)) {
          iVar3 = iVar3 + -1;
          break;
        }
        iVar1 = iVar3 + 1;
        iVar4 = iVar4 + 2;
      } while (iVar3 + 1 < *(int *)(param_1 + 0x138));
    }
    iVar4 = iVar3 * 2 + param_1;
    .umul(iVar6,(int)*(sword *)(iVar4 + 0x164));
    *param_3 = iVar6;
    .umul(iVar5,(int)*(sword *)(iVar4 + 0x164));
    *param_4 = iVar5;
  }
  return CONCAT44(param_2,param_1);
}
