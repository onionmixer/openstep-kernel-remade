
/* WARNING: Removing unreachable block (ram,0xf0026968) */
/* WARNING: Removing unreachable block (ram,0xf002693c) */
/* WARNING: Removing unreachable block (ram,0xf00269a8) */
/* WARNING: Removing unreachable block (ram,0xf00268fc) */

undefined8 _vno_bsd_unlock(int param_1,uint param_2)

{
  word wVar1;
  sword sVar3;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
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
  iVar4 = *(int *)(param_1 + 0x18);
  param_2 = param_2 & *(uint *)(param_1 + 8);
  if ((iVar4 != 0) && (param_2 != 0)) {
    wVar1 = *(word *)(iVar4 + 4);
    if ((param_2 & 0x80) != 0) {
      if ((wVar1 & 8) == 0) {
        _panic(aVnoBsdUnlockSh);
        sVar3 = *(sword *)(iVar4 + 8);
      }
      else {
        sVar3 = *(sword *)(iVar4 + 8);
      }
      *(sword *)(iVar4 + 8) = sVar3 + -1;
      if ((sword)(sVar3 + -1) == 0) {
        *(word *)(iVar4 + 4) = *(word *)(iVar4 + 4) & 0xfff7;
        if ((wVar1 & 0x10) != 0) {
          _wakeup(iVar4 + 8);
        }
        uVar2 = *(uint *)(param_1 + 8);
      }
      else {
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(uint *)(param_1 + 8) = uVar2 & 0xffffff7f;
    }
    if ((param_2 & 0x100) != 0) {
      if ((wVar1 & 4) == 0) {
        _panic(aVnoBsdUnlockEx);
        sVar3 = *(sword *)(iVar4 + 10);
      }
      else {
        sVar3 = *(sword *)(iVar4 + 10);
      }
      *(sword *)(iVar4 + 10) = sVar3 + -1;
      if ((sword)(sVar3 + -1) == 0) {
        *(word *)(iVar4 + 4) = *(word *)(iVar4 + 4) & 0xffeb;
        if ((wVar1 & 0x10) != 0) {
          _wakeup(iVar4 + 10);
        }
        uVar2 = *(uint *)(param_1 + 8);
      }
      else {
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(uint *)(param_1 + 8) = uVar2 & 0xfffffeff;
    }
  }
  return CONCAT44(param_2,param_1);
}

