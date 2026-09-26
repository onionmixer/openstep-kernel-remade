
/* WARNING: Removing unreachable block (ram,0xf006f4d4) */
/* WARNING: Removing unreachable block (ram,0xf006f48c) */

undefined8 _processor_set_max_priority(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar3 = 4;
  }
  else {
    do {
      do {
      } while (*(int *)(param_1 + 0x158) != 0);
      piVar1 = (int *)(param_1 + 0x158);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(uint *)(param_1 + 0x164) = param_2;
    if (param_3 != 0) {
      iVar4 = *(int *)(param_1 + 0x138);
      if (param_1 + 0x138 != iVar4) {
        iVar2 = *(int *)(iVar4 + 0x54);
        while( true ) {
          if (iVar2 < (int)param_2) {
            _thread_max_priority(iVar4,param_1,param_2);
            iVar4 = *(int *)(iVar4 + 0x18);
          }
          else {
            iVar4 = *(int *)(iVar4 + 0x18);
          }
          if (param_1 + 0x138 == iVar4) break;
          iVar2 = *(int *)(iVar4 + 0x54);
        }
      }
    }
    *(undefined4 *)(param_1 + 0x158) = 0;
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
