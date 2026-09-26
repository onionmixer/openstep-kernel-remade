
/* WARNING: Removing unreachable block (ram,0xf00f21cc) */
/* WARNING: Removing unreachable block (ram,0xf00f21b4) */
/* WARNING: Removing unreachable block (ram,0xf00f219c) */
/* WARNING: Removing unreachable block (ram,0xf00f21c4) */
/* WARNING: Removing unreachable block (ram,0xf00f21d4) */
/* WARNING: Removing unreachable block (ram,0xf00f20f0) */

undefined8 __objc_add_category(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 *puVar3;
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
  piVar1 = (int *)param_1[1];
  _objc_getClass();
  if (piVar1 == (int *)0x0) {
    __objc_inform(aUnableToAddCat,*param_1);
    puVar2 = aClassSNotLinke_0;
  }
  else {
    if ((int *)param_1[2] == (int *)0x0) {
      puVar3 = (undefined4 *)param_1[3];
    }
    else {
      *(int *)param_1[2] = piVar1[7];
      piVar1[7] = param_1[2];
      puVar3 = (undefined4 *)param_1[3];
    }
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *(undefined4 *)(*piVar1 + 0x1c);
      *(undefined4 *)(*piVar1 + 0x1c) = param_1[3];
    }
    if ((param_2 < 5) || ((int *)param_1[4] == (int *)0x0)) goto loc_F00F21CC;
    if (4 < *(int *)(*piVar1 + 0xc)) {
      *(int *)param_1[4] = piVar1[9];
      piVar1[9] = param_1[4];
      *(undefined4 *)(*piVar1 + 0x24) = param_1[4];
      goto loc_F00F21CC;
    }
    __objc_inform(aUnableToAddPro,*param_1);
    puVar2 = aClassSMustBeRe_0;
  }
  __objc_inform(puVar2,param_1[1]);
loc_F00F21CC:
  _objc_getClass(param_1[1]);
  __objc_flush_caches();
  return CONCAT44(param_2,param_1);
}
