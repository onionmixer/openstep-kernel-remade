
/* WARNING: Removing unreachable block (ram,0xf00781b0) */
/* WARNING: Removing unreachable block (ram,0xf0078114) */
/* WARNING: Removing unreachable block (ram,0xf00780f8) */
/* WARNING: Removing unreachable block (ram,0xf00780e8) */
/* WARNING: Removing unreachable block (ram,0xf00781c0) */
/* WARNING: Removing unreachable block (ram,0xf00780d0) */

undefined8 _zcram(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  if (param_2 == (int *)0x0) {
    _panic(aZcramMemoryAtZ);
    iVar1 = param_1[0xb];
  }
  else {
    iVar1 = param_1[0xb];
  }
  uVar4 = param_1[7];
  if (iVar1 < 0) {
    _lock_write(param_1 + 0xc);
  }
  else {
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[1] = iVar1;
  }
  if (param_3 < uVar4) {
    iVar1 = param_1[0xb];
  }
  else {
    do {
      piVar2 = (int *)param_1[3];
      if ((piVar2 == (int *)0x0) || (param_2 <= piVar2)) {
        piVar2 = param_1 + 4;
      }
      do {
        piVar3 = piVar2;
        piVar2 = (int *)*piVar3;
        if (piVar2 == (int *)0x0) {
          *param_2 = 0;
          goto loc_F0078174;
        }
      } while (piVar2 < param_2);
      *param_2 = (int)piVar2;
loc_F0078174:
      *piVar3 = (int)param_2;
      param_1[3] = (int)param_2;
      param_1[2] = param_1[2];
      param_3 = param_3 - uVar4;
      param_2 = (int *)((int)param_2 + uVar4);
      param_1[5] = param_1[5] + uVar4;
    } while (uVar4 <= param_3);
    iVar1 = param_1[0xb];
  }
  if (iVar1 < 0) {
    _lock_done(param_1 + 0xc);
  }
  else {
    *param_1 = 0;
    _splx(param_1[1]);
  }
  return CONCAT44(param_2,param_1);
}
