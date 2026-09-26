
/* WARNING: Removing unreachable block (ram,0xf008d1bc) */
/* WARNING: Removing unreachable block (ram,0xf008d1f0) */
/* WARNING: Removing unreachable block (ram,0xf008d158) */
/* WARNING: Removing unreachable block (ram,0xf008d1a8) */

undefined8 -[KernBusRangeResource shareRange:](int param_1,undefined4 param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar4 = *param_3;
  piVar6 = (int *)(param_1 + 0x18);
  uVar3 = param_3[1];
  iVar7 = 0;
  *(uint *)((int)register0x00000038 + -0x18) = uVar4;
  uVar2 = param_3[1];
  *(uint *)((int)register0x00000038 + -0x14) = uVar2;
  uVar2 = uVar4 + uVar2;
  uVar3 = uVar4 + uVar3;
  if ((uVar2 == 0) || (bVar1 = false, uVar4 < uVar2)) {
    bVar1 = true;
  }
  if (bVar1) {
    if (uVar4 < *(uint *)(param_1 + 8)) {
      iVar7 = 0;
    }
    else if ((*(uint *)(param_1 + 0xc) == 0) || (uVar3 <= *(uint *)(param_1 + 0xc))) {
      do {
        iVar5 = *piVar6;
        if (iVar5 == 0) {
          uVar2 = *param_3;
loc_F008D198:
          *(uint *)((int)register0x00000038 + -0x18) = uVar2;
          *(uint *)((int)register0x00000038 + -0x14) = param_3[1];
          iVar7 = *(int *)(param_1 + 0x10);
          _objc_msgSend(iVar7,paAlloc);
          _objc_msgSend();
          if (iVar7 != 0) {
            *(int *)(iVar7 + 4) = iVar5;
            *piVar6 = iVar7;
            iVar5 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar5;
            if (iVar5 == 1) {
              _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceactive);
            }
          }
          break;
        }
        if (uVar3 <= *(uint *)(iVar5 + 0xc)) {
          uVar2 = *param_3;
          goto loc_F008D198;
        }
        if ((*(uint *)(iVar5 + 0xc) <= uVar4) && (uVar3 <= *(uint *)(iVar5 + 0x10))) {
          _objc_msgSend(iVar5,paShare);
          iVar7 = iVar5;
          break;
        }
        piVar6 = (int *)(iVar5 + 4);
      } while (*(uint *)(iVar5 + 0x10) <= uVar4);
    }
    else {
      iVar7 = 0;
    }
  }
  else {
    iVar7 = 0;
  }
  return CONCAT44(param_2,iVar7);
}
