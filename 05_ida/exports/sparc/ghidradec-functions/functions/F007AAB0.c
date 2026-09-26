
/* WARNING: Removing unreachable block (ram,0xf007ab80) */
/* WARNING: Removing unreachable block (ram,0xf007ab3c) */
/* WARNING: Removing unreachable block (ram,0xf007aaf8) */
/* WARNING: Removing unreachable block (ram,0xf007ab58) */
/* WARNING: Removing unreachable block (ram,0xf007ab2c) */
/* WARNING: Removing unreachable block (ram,0xf007aadc) */

undefined8
_kern_serv_log(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
  int *piVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined4 unaff_l4;
  undefined4 uVar6;
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
  piVar4 = (int *)*param_1;
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x60);
  if ((param_2 <= piVar4[0xc]) && (iVar1 = piVar4[9], iVar1 != 0)) {
    _splusclock();
    do {
      do {
      } while (*piVar4 != 0);
      piVar2 = piVar4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    puVar3 = (undefined4 *)piVar4[10];
    piVar4[10] = (int)(puVar3 + 8);
    if (puVar3 + 8 == (undefined4 *)piVar4[0xb]) {
      piVar4[10] = (int)puVar3;
      *piVar4 = 0;
      _splx(iVar1);
    }
    else {
      *piVar4 = 0;
      _splx();
      *puVar3 = param_3;
      puVar3[1] = param_4;
      puVar3[2] = param_5;
      puVar3[3] = param_6;
      puVar3[4] = uVar6;
      puVar3[5] = uVar5;
      _event_get();
      puVar3[6] = iVar1;
      puVar3[7] = param_2;
      if (piVar4[6] != 0) {
        _kern_serv_callout(param_1,sub_F007AB90,piVar4);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
