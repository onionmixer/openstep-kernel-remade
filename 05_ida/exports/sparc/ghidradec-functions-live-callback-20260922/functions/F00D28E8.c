
/* WARNING: Removing unreachable block (ram,0xf00d2930) */
/* WARNING: Removing unreachable block (ram,0xf00d2968) */
/* WARNING: Removing unreachable block (ram,0xf00d2924) */

undefined8 -[EventDriver evSetScreen:](int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar3 = param_3[1];
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    uVar4 = 0xfffffd3f;
  }
  else {
    if (*(int *)(param_1 + 0x180) == 0) {
      iVar1 = *param_3 * 0x14;
      *(int *)(param_1 + 0x17c) = iVar1;
      _IOMalloc();
      *(int *)(param_1 + 0x180) = iVar1;
      _bzero();
      *(undefined4 *)(param_1 + 0x160) = 0xe18;
      *(undefined4 *)(param_1 + 0x184) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined2 *)(param_1 + 0x19e) = 0;
      *(undefined2 *)(param_1 + 0x19a) = 0;
      *(undefined2 *)(param_1 + 0x19c) = 0;
      *(undefined2 *)(param_1 + 0x198) = 0;
    }
    if ((int)uVar3 < 0) {
      uVar4 = 0xfffffd3e;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x17c);
      udiv(uVar2,0x14);
      if (uVar3 < uVar2) {
        iVar1 = *(int *)(param_1 + 0x180) + uVar3 * 0x14;
        *(sword *)(iVar1 + 0xc) = (sword)param_3[3];
        *(sword *)(iVar1 + 0xe) = (sword)param_3[4];
        *(sword *)(iVar1 + 0x10) = (sword)param_3[5];
        *(sword *)(iVar1 + 0x12) = (sword)param_3[6];
        *(int *)(iVar1 + 8) = param_3[2];
        *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + param_3[2];
        if (*(sword *)(iVar1 + 0xc) < *(sword *)(param_1 + 0x198)) {
          *(undefined2 *)(param_1 + 0x198) = *(undefined2 *)(iVar1 + 0xc);
        }
        if (*(sword *)(iVar1 + 0x10) < *(sword *)(param_1 + 0x19c)) {
          *(undefined2 *)(param_1 + 0x19c) = *(undefined2 *)(iVar1 + 0x10);
        }
        if (*(sword *)(iVar1 + 0xe) < *(sword *)(param_1 + 0x19a)) {
          *(undefined2 *)(param_1 + 0x19a) = *(undefined2 *)(iVar1 + 0xe);
        }
        if (*(sword *)(iVar1 + 0x12) < *(sword *)(param_1 + 0x19e)) {
          *(undefined2 *)(param_1 + 0x19e) = *(undefined2 *)(iVar1 + 0x12);
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0xfffffd3e;
      }
    }
  }
  return CONCAT44(param_2,uVar4);
}

