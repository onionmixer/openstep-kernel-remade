
/* WARNING: Removing unreachable block (ram,0xf0085c94) */
/* WARNING: Removing unreachable block (ram,0xf0085be8) */
/* WARNING: Removing unreachable block (ram,0xf0085b34) */
/* WARNING: Removing unreachable block (ram,0xf0085d70) */
/* WARNING: Removing unreachable block (ram,0xf0085ca4) */
/* WARNING: Removing unreachable block (ram,0xf0085ab4) */
/* WARNING: Removing unreachable block (ram,0xf0085aa4) */
/* WARNING: Removing unreachable block (ram,0xf0085af0) */
/* WARNING: Removing unreachable block (ram,0xf0085da0) */
/* WARNING: Removing unreachable block (ram,0xf0085d84) */
/* WARNING: Removing unreachable block (ram,0xf0085b44) */
/* WARNING: Removing unreachable block (ram,0xf0085c4c) */
/* WARNING: Removing unreachable block (ram,0xf0085dc4) */
/* WARNING: Removing unreachable block (ram,0xf0085a90) */

undefined8 _vm_map_fork(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  iVar1 = 0;
  _pmap_create();
  _vm_map_create();
  piVar7 = *(int **)(param_1 + 0x10);
  if (piVar7 == (int *)(param_1 + 0xc)) {
loc_F0085DBC:
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    _lock_done(param_1);
    return CONCAT44(param_2,iVar1);
  }
  uVar4 = piVar7[6];
  do {
    if ((uVar4 & 0x20000000) != 0) {
      _panic(aVmMapForkEncou);
    }
    iVar2 = piVar7[9];
    if (iVar2 == 1) {
      piVar3 = (int *)(iVar1 + 0xc);
      __vm_map_entry_create();
      *piVar3 = *piVar7;
      piVar3[1] = piVar7[1];
      piVar3[2] = piVar7[2];
      piVar3[3] = piVar7[3];
      piVar3[4] = piVar7[4];
      piVar3[5] = piVar7[5];
      piVar3[6] = piVar7[6];
      piVar3[7] = piVar7[7];
      piVar3[8] = piVar7[8];
      piVar3[9] = piVar7[9];
      piVar3[10] = piVar7[10];
      *(undefined2 *)(piVar3 + 10) = 0;
      piVar3[4] = 0;
      piVar3[6] = piVar3[6] & 0x7fffffff;
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
      *piVar3 = *(int *)(iVar1 + 0xc);
      piVar5 = *(int **)(*(int *)(iVar1 + 0xc) + 4);
      iVar2 = *piVar3;
      piVar3[1] = (int)piVar5;
      *piVar5 = (int)piVar3;
      *(int **)(iVar2 + 4) = piVar3;
      if ((piVar7[6] & 0x80000000U) == 0) {
        _vm_map_copy_entry(param_1,iVar1,piVar7,piVar3);
      }
      else {
        iVar2 = iVar1;
        _vm_map_copy(iVar1,piVar7[4],piVar3[2],piVar3[3] - piVar3[2],piVar7[5],0,0);
        if (iVar2 != 0) {
          _printf(aVmMapForkCopyI);
          piVar7 = (int *)piVar7[1];
          goto loc_F0085DAC;
        }
      }
      piVar7 = (int *)piVar7[1];
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        iVar2 = 0;
        if ((piVar7[6] & 0x80000000U) == 0) {
          _vm_map_create(0,piVar7[2],piVar7[3],1);
          *(undefined4 *)(iVar2 + 0x2c) = 0;
          piVar3 = (int *)(iVar2 + 0xc);
          __vm_map_entry_create();
          *piVar3 = *piVar7;
          piVar3[1] = piVar7[1];
          piVar3[2] = piVar7[2];
          piVar3[3] = piVar7[3];
          piVar3[4] = piVar7[4];
          piVar3[5] = piVar7[5];
          piVar3[6] = piVar7[6];
          piVar3[7] = piVar7[7];
          piVar3[8] = piVar7[8];
          piVar3[9] = piVar7[9];
          piVar3[10] = piVar7[10];
          *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + 1;
          *piVar3 = *(int *)(iVar2 + 0xc);
          piVar5 = *(int **)(*(int *)(iVar2 + 0xc) + 4);
          iVar6 = *piVar3;
          piVar3[1] = (int)piVar5;
          *piVar5 = (int)piVar3;
          *(int **)(iVar6 + 4) = piVar3;
          piVar7[6] = piVar7[6] | 0x80000000;
          piVar7[4] = iVar2;
          piVar7[5] = piVar7[2];
        }
        piVar3 = (int *)(iVar1 + 0xc);
        __vm_map_entry_create();
        *piVar3 = *piVar7;
        piVar3[1] = piVar7[1];
        piVar3[2] = piVar7[2];
        piVar3[3] = piVar7[3];
        piVar3[4] = piVar7[4];
        piVar3[5] = piVar7[5];
        piVar3[6] = piVar7[6];
        piVar3[7] = piVar7[7];
        piVar3[8] = piVar7[8];
        piVar3[9] = piVar7[9];
        piVar3[10] = piVar7[10];
        _vm_map_reference(piVar3[4]);
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
        *piVar3 = *(int *)(iVar1 + 0xc);
        piVar5 = *(int **)(*(int *)(iVar1 + 0xc) + 4);
        iVar2 = *piVar3;
        piVar3[1] = (int)piVar5;
        *piVar5 = (int)piVar3;
        *(int **)(iVar2 + 4) = piVar3;
        _pmap_copy(*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(param_1 + 0x24),piVar3[2],
                   piVar7[3] - piVar7[2]);
        piVar7 = (int *)piVar7[1];
      }
      else {
        piVar7 = (int *)piVar7[1];
      }
    }
    else {
      piVar7 = (int *)piVar7[1];
    }
loc_F0085DAC:
    if (piVar7 == (int *)(param_1 + 0xc)) goto loc_F0085DBC;
    uVar4 = piVar7[6];
  } while( true );
}
