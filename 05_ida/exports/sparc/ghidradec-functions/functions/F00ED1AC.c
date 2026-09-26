
/* WARNING: Removing unreachable block (ram,0xf00ed2f0) */
/* WARNING: Removing unreachable block (ram,0xf00ed2d4) */
/* WARNING: Removing unreachable block (ram,0xf00ed298) */
/* WARNING: Removing unreachable block (ram,0xf00ed270) */
/* WARNING: Removing unreachable block (ram,0xf00ed254) */
/* WARNING: Removing unreachable block (ram,0xf00ed268) */
/* WARNING: Removing unreachable block (ram,0xf00ed28c) */
/* WARNING: Removing unreachable block (ram,0xf00ed2a4) */
/* WARNING: Removing unreachable block (ram,0xf00ed2dc) */
/* WARNING: Removing unreachable block (ram,0xf00ed2c0) */
/* WARNING: Removing unreachable block (ram,0xf00ed1d8) */

undefined8 _NXCreateHashTableFromZone(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  piVar4 = param_4;
  (*(code *)param_4[1])(param_4,0x14);
  if (dword_F012F080 == 0) {
    sub_F00ED0E8();
    iVar1 = *param_1;
  }
  else {
    iVar1 = *param_1;
  }
  if (iVar1 == 0) {
    *param_1 = (int)_NXPtrHash;
    iVar1 = param_1[1];
  }
  else {
    iVar1 = param_1[1];
  }
  if (iVar1 == 0) {
    param_1[1] = (int)_NXPtrIsEqual;
    iVar1 = param_1[2];
  }
  else {
    iVar1 = param_1[2];
  }
  if (iVar1 == 0) {
    param_1[2] = (int)_NXNoEffectFree;
    iVar1 = param_1[3];
  }
  else {
    iVar1 = param_1[3];
  }
  if (iVar1 == 0) {
    iVar1 = dword_F012F080;
    _NXHashGet(dword_F012F080,param_1);
    if (iVar1 == 0) {
      _NXDefaultMallocZone();
      iVar3 = iVar1;
      _NXDefaultMallocZone();
      (**(code **)(iVar1 + 4))();
      _memmove();
      _NXHashInsert(dword_F012F080,iVar3);
      iVar1 = dword_F012F080;
      _NXHashGet(dword_F012F080,param_1);
      if (iVar1 == 0) {
        puVar2 = aNxcreatehashta_0;
        goto loc_F00ED2C0;
      }
      *piVar4 = iVar1;
    }
    else {
      *piVar4 = iVar1;
    }
    piVar4[1] = 0;
    piVar4[4] = param_3;
    iVar1 = param_2;
    sub_F00ED010();
    iVar1 = iVar1 + 1;
    sub_F00ED034();
    piVar4[2] = iVar1;
    _NXZoneCalloc(param_4,iVar1,8);
    piVar4[3] = (int)param_4;
  }
  else {
    puVar2 = aNxcreatehashta;
loc_F00ED2C0:
    piVar4 = (int *)0x0;
    __NXLogError(puVar2);
  }
  return CONCAT44(param_2,piVar4);
}
