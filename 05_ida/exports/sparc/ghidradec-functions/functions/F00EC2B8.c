
/* WARNING: Removing unreachable block (ram,0xf00ec364) */
/* WARNING: Removing unreachable block (ram,0xf00ec330) */
/* WARNING: Removing unreachable block (ram,0xf00ec2fc) */
/* WARNING: Removing unreachable block (ram,0xf00ec2d8) */
/* WARNING: Removing unreachable block (ram,0xf00ec318) */
/* WARNING: Removing unreachable block (ram,0xf00ec338) */
/* WARNING: Removing unreachable block (ram,0xf00ec37c) */
/* WARNING: Removing unreachable block (ram,0xf00ec2d0) */

undefined8 __internal_object_reallocFromZone(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 unaff_l0;
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
  uVar1 = 0;
  if (param_1 == (uint *)0x0) {
    ___objc_error(0,aReallocatingNi,0);
  }
  __objc_getFreedObjectClass();
  if (*param_1 == uVar1) {
    ___objc_error(param_1,aReallocatingFr,0);
    uVar1 = *param_1;
  }
  else {
    uVar1 = *param_1;
  }
  puVar2 = *(uint **)(uVar1 + 0x14);
  if (param_2 < puVar2) {
    puVar3 = param_1;
    _object_getClassName(param_1);
    puVar2 = param_1;
    ___objc_error(param_1,aSURequestedSiz,puVar3,param_2);
  }
  uVar1 = *param_1;
  __objc_getFreedObjectClass();
  *param_1 = (uint)puVar2;
  (*(code *)*param_3)(param_3,param_1,param_2);
  if (param_3 == (uint *)0x0) {
    puVar2 = param_1;
    _object_getClassName(param_1);
    ___objc_error(param_1,aFailedOutOfMem,puVar2,param_2);
    param_3 = (uint *)0x0;
  }
  else {
    *param_3 = uVar1;
  }
  return CONCAT44(param_2,param_3);
}
