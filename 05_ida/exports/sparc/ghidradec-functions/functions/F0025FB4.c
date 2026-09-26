
/* WARNING: Removing unreachable block (ram,0xf0026070) */
/* WARNING: Removing unreachable block (ram,0xf0025fc4) */

undefined8 _vno_rw(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  byte bVar6;
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
  piVar3 = *(int **)(param_1 + 0x18);
  if (param_2 == 1) {
    piVar5 = piVar3;
    _isrofile();
    if (piVar5 != (int *)0x0) {
      piVar5 = (int *)0x1e;
      goto locret_F00260E8;
    }
    iVar2 = piVar3[10];
  }
  else {
    iVar2 = piVar3[10];
  }
  uVar1 = *(uint *)(param_1 + 8);
  bVar6 = iVar2 == 1;
  iVar4 = *(int *)(param_3 + 0x14);
  if ((uVar1 & 8) != 0) {
    bVar6 = bVar6 | 2;
  }
  if ((uVar1 & 0x40000) != 0) {
    bVar6 = bVar6 | 4;
  }
  if (iVar2 == 8) {
    *(sword *)(param_3 + 0x10) = (sword)uVar1;
  }
  piVar5 = piVar3;
  if (((piVar3[10] == 1) && ((*(uint *)(*piVar3 + 0x38) & 0x8000000) != 0)) &&
     ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0)) {
    _mfs_io(piVar3,param_3,param_2,bVar6,*(undefined4 *)(param_1 + 0x20));
  }
  else {
    (**(code **)(piVar3[7] + 8))(piVar3,param_3,param_2,bVar6,*(undefined4 *)(param_1 + 0x20));
  }
  if (piVar5 == (int *)0x0) {
    if ((*(uint *)(param_1 + 8) & 8) == 0) {
      if (piVar3[10] != 8) {
        piVar5 = (int *)0x0;
        goto locret_F00260E8;
      }
      iVar2 = *(int *)(param_3 + 0x14);
    }
    else {
      iVar2 = *(int *)(param_3 + 0x14);
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_3 + 8) - (iVar4 - iVar2);
    piVar5 = (int *)0x0;
  }
locret_F00260E8:
  return CONCAT44(param_2,piVar5);
}
