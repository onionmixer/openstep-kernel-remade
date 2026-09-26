
/* WARNING: Removing unreachable block (ram,0xf007ae14) */
/* WARNING: Removing unreachable block (ram,0xf007ad80) */
/* WARNING: Removing unreachable block (ram,0xf007ad3c) */
/* WARNING: Removing unreachable block (ram,0xf007ad64) */
/* WARNING: Removing unreachable block (ram,0xf007ae04) */
/* WARNING: Removing unreachable block (ram,0xf007ada8) */
/* WARNING: Removing unreachable block (ram,0xf007ad28) */

undefined8 _kern_serv_callout(undefined4 *param_1,code *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 uVar5;
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
  piVar4 = (int *)*param_1;
  _curipl();
  if ((param_1 == (undefined4 *)0x0) && (_task_self(), param_1 == (undefined4 *)piVar4[2])) {
    (*param_2)(param_3);
    uVar5 = 0;
  }
  else {
    _splusclock();
    do {
      do {
      } while (*piVar4 != 0);
      piVar1 = piVar4;
      _simple_lock_try();
      piVar3 = piVar4 + 0xf;
    } while (piVar1 == (int *)0x0);
    piVar1 = (int *)piVar4[0xf];
    if (piVar3 == piVar1) {
      *piVar4 = 0;
      _splx(param_1);
      uVar5 = 6;
    }
    else {
      piVar2 = (int *)piVar1[2];
      if (piVar3 == piVar2) {
        piVar4[0x10] = (int)piVar2;
      }
      else {
        piVar2[3] = (int)piVar3;
      }
      piVar4[0xf] = (int)piVar2;
      *piVar1 = (int)param_2;
      piVar1[1] = param_3;
      piVar3 = (int *)piVar4[0xe];
      if (piVar4 + 0xd == piVar3) {
        piVar4[0xd] = (int)piVar1;
      }
      else {
        piVar3[2] = (int)piVar1;
      }
      piVar1[3] = (int)piVar3;
      piVar1[2] = (int)(piVar4 + 0xd);
      piVar4[0xe] = (int)piVar1;
      *piVar4 = 0;
      _splx(param_1);
      _calloutDispatchUnique(sub_F007AE28,piVar4[3]);
      uVar5 = 0;
    }
  }
  return CONCAT44(param_2,uVar5);
}
