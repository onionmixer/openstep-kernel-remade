
/* WARNING: Removing unreachable block (ram,0xf0099e88) */
/* WARNING: Removing unreachable block (ram,0xf0099e30) */
/* WARNING: Removing unreachable block (ram,0xf0099e44) */
/* WARNING: Removing unreachable block (ram,0xf0099eb4) */
/* WARNING: Removing unreachable block (ram,0xf0099df0) */

undefined8 _addupc(int param_1,undefined4 *param_2,sword param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l1;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 *puVar8;
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
  piVar4 = (int *)*param_2;
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_2 == (undefined4 *)0x0) {
loc_F0099ED0:
    puVar8 = (undefined4 *)*param_2;
loc_F0099ED4:
    *puVar8 = 0;
    return CONCAT44(param_2,param_1);
  }
  iVar5 = param_2[4];
  puVar8 = param_2;
  do {
    uVar7 = puVar8[5];
    uVar2 = (uint)(param_1 - iVar5) >> 0x10;
    .umul(uVar2,uVar7);
    uVar6 = param_1 - iVar5 & 0xffff;
    .umul(uVar6,uVar7);
    uVar3 = puVar8[2];
    uVar2 = uVar3 + (uVar2 + (uVar6 >> 0x10) & 0xfffffffe);
    if (uVar2 < uVar3) {
      puVar8 = (undefined4 *)puVar8[1];
    }
    else {
      if (uVar2 < puVar8[3] + uVar3) {
        uVar6 = uVar2;
        _copyin(uVar2,(undefined *)((int)register0x00000038 + -10),2);
        if (uVar6 == 0) {
          *(sword *)((int)register0x00000038 + -10) =
               *(sword *)((int)register0x00000038 + -10) + param_3;
          _copyout((undefined *)((int)register0x00000038 + -10),uVar2,2);
          puVar8 = (undefined4 *)*param_2;
          goto loc_F0099ED4;
        }
        param_2[5] = 0;
        goto loc_F0099ED0;
      }
      puVar8 = (undefined4 *)puVar8[1];
    }
    if (puVar8 == (undefined4 *)0x0) goto loc_F0099ED0;
    iVar5 = puVar8[4];
  } while( true );
}
