
/* WARNING: Removing unreachable block (ram,0xf004f178) */

undefined8 _iaccess(int param_1,uint param_2)

{
  sword sVar1;
  uint uVar2;
  word wVar3;
  sword *psVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
  uint uVar7;
  undefined4 unaff_i2;
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
  if ((param_2 & 0x80) != 0) {
    if (((*(char *)(*(int *)(param_1 + 0x50) + 0xd2) == '\0') ||
        (wVar3 = *(word *)(param_1 + 100) & 0xf000, wVar3 == 0x2000)) || (wVar3 == 0x6000)) {
      wVar3 = *(word *)(param_1 + 0x10);
    }
    else {
      if (wVar3 != 0x1000) {
        uVar6 = 0x1e;
        goto locret_F004F238;
      }
      wVar3 = *(word *)(param_1 + 0x10);
    }
    if ((wVar3 & 2) == 0) {
      wVar3 = *(word *)(param_1 + 0x10);
    }
    else {
      _vnode_uncache(param_1 + 0xc);
      wVar3 = *(word *)(param_1 + 0x10);
    }
    if ((wVar3 & 2) != 0) {
      uVar6 = 0x1a;
      goto locret_F004F238;
    }
  }
  iVar5 = *(int *)(_active_u + 0x1c);
  if (*(sword *)(iVar5 + 2) == 0) {
    uVar6 = 0;
  }
  else {
    if (*(sword *)(iVar5 + 2) == *(sword *)(param_1 + 0x68)) {
      uVar2 = (uint)*(word *)(param_1 + 100);
      uVar7 = param_2;
    }
    else {
      uVar7 = (int)param_2 >> 3;
      uVar6 = uVar7;
      if (*(sword *)(iVar5 + 4) != *(sword *)(param_1 + 0x6a)) {
        psVar4 = (sword *)(iVar5 + 10);
        uVar6 = (int)param_2 >> 6;
        if (psVar4 < (sword *)(iVar5 + 0x2a)) {
          sVar1 = *psVar4;
          while (sVar1 != -1) {
            if (*(sword *)(param_1 + 0x6a) == sVar1) {
              uVar2 = (uint)*(word *)(param_1 + 100);
              goto loc_F004F228;
            }
            psVar4 = psVar4 + 1;
            if ((sword *)(iVar5 + 0x2a) <= psVar4) break;
            sVar1 = *psVar4;
          }
        }
      }
      uVar2 = (uint)*(word *)(param_1 + 100);
      uVar7 = uVar6;
    }
loc_F004F228:
    uVar6 = -(uint)((uVar7 & ~uVar2) != 0) & 0xd;
    param_2 = uVar7;
  }
locret_F004F238:
  return CONCAT44(param_2,uVar6);
}

