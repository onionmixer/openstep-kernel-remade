
/* WARNING: Removing unreachable block (ram,0xf00b0c5c) */
/* WARNING: Removing unreachable block (ram,0xf00b0c44) */
/* WARNING: Removing unreachable block (ram,0xf00b0c2c) */
/* WARNING: Removing unreachable block (ram,0xf00b0c18) */
/* WARNING: Removing unreachable block (ram,0xf00b0c38) */
/* WARNING: Removing unreachable block (ram,0xf00b0c54) */
/* WARNING: Removing unreachable block (ram,0xf00b0c74) */
/* WARNING: Removing unreachable block (ram,0xf00b0c04) */

undefined8 _attach_devs(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar4;
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
  iVar1 = *(int *)(param_1 + 0x28);
  piVar4 = (int *)0x0;
  _prom_childnode();
  if (iVar1 != 0) {
    do {
      iVar3 = param_1;
      sub_F00B0A2C(param_1,iVar1);
      if (iVar3 == 0) {
        piVar2 = (int *)0x38;
        _kalloc();
        _bzero();
        sub_F00B0A70(param_1,piVar2);
        piVar2[10] = iVar1;
        *piVar2 = param_1;
        sub_F00B07E4(piVar2);
        iVar3 = piVar2[3];
        sub_F00B09E4();
        piVar2[8] = iVar3;
        if (piVar4 == (int *)0x0) {
          piVar4 = piVar2;
        }
      }
      _prom_nextnode();
    } while (iVar1 != 0);
    while (piVar2 = piVar4, piVar2 != (int *)0x0) {
      piVar4 = (int *)piVar2[1];
      if (piVar2[8] != 0) {
        (**(code **)(piVar2[8] + 8))(piVar2);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
