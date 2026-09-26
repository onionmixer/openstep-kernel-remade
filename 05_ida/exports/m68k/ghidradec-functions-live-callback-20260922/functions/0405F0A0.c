
int _vm_map_fork(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  uVar2 = _pmap_create(0);
  iVar3 = _vm_map_create(uVar2,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                         *(undefined4 *)(param_1 + 0x1c));
  piVar8 = *(int **)(param_1 + 0xc);
  if ((int *)(param_1 + 8) != piVar8) {
    piVar1 = (int *)(iVar3 + 8);
    do {
      if ((*(byte *)(piVar8 + 6) & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmMapForkEncou);
      }
      iVar7 = *(int *)((int)piVar8 + 0x22);
      if (iVar7 == 1) {
        piVar6 = (int *)__vm_map_entry_create(piVar1);
        *piVar6 = *piVar8;
        piVar6[1] = piVar8[1];
        piVar6[2] = piVar8[2];
        piVar6[3] = piVar8[3];
        piVar6[4] = piVar8[4];
        piVar6[5] = piVar8[5];
        piVar6[6] = piVar8[6];
        piVar6[7] = piVar8[7];
        piVar6[8] = piVar8[8];
        piVar6[9] = piVar8[9];
        *(undefined2 *)(piVar6 + 10) = *(undefined2 *)(piVar8 + 10);
        *(undefined2 *)((int)piVar6 + 0x26) = 0;
        piVar6[4] = 0;
        *(byte *)(piVar6 + 6) = *(byte *)(piVar6 + 6) & 0x7f;
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
        *piVar6 = *piVar1;
        piVar6[1] = *(int *)(*piVar1 + 4);
        iVar7 = *piVar6;
        *(int **)piVar6[1] = piVar6;
        *(int **)(iVar7 + 4) = piVar6;
        if (*(char *)(piVar8 + 6) < '\0') {
          iVar7 = _vm_map_copy(iVar3,piVar8[4],piVar6[2],piVar6[3] - piVar6[2],piVar8[5],0,0);
          if (iVar7 != 0) {
            _printf(aVmMapForkCopyI);
          }
        }
        else {
          _vm_map_copy_entry(param_1,iVar3,piVar8,piVar6);
        }
      }
      else if ((iVar7 < 2) && (iVar7 == 0)) {
        if (-1 < *(char *)(piVar8 + 6)) {
          iVar4 = _vm_map_create(0,piVar8[2],piVar8[3],1);
          *(undefined4 *)(iVar4 + 0x28) = 0;
          piVar6 = (int *)(iVar4 + 8);
          piVar5 = (int *)__vm_map_entry_create(piVar6);
          *piVar5 = *piVar8;
          piVar5[1] = piVar8[1];
          piVar5[2] = piVar8[2];
          piVar5[3] = piVar8[3];
          piVar5[4] = piVar8[4];
          piVar5[5] = piVar8[5];
          piVar5[6] = piVar8[6];
          piVar5[7] = piVar8[7];
          piVar5[8] = piVar8[8];
          piVar5[9] = piVar8[9];
          *(undefined2 *)(piVar5 + 10) = *(undefined2 *)(piVar8 + 10);
          *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
          *piVar5 = *piVar6;
          piVar5[1] = *(int *)(*piVar6 + 4);
          iVar7 = *piVar5;
          *(int **)piVar5[1] = piVar5;
          *(int **)(iVar7 + 4) = piVar5;
          *(byte *)(piVar8 + 6) = *(byte *)(piVar8 + 6) | 0x80;
          piVar8[4] = iVar4;
          piVar8[5] = piVar8[2];
        }
        piVar6 = (int *)__vm_map_entry_create(piVar1);
        *piVar6 = *piVar8;
        piVar6[1] = piVar8[1];
        piVar6[2] = piVar8[2];
        piVar6[3] = piVar8[3];
        piVar6[4] = piVar8[4];
        piVar6[5] = piVar8[5];
        piVar6[6] = piVar8[6];
        piVar6[7] = piVar8[7];
        piVar6[8] = piVar8[8];
        piVar6[9] = piVar8[9];
        *(undefined2 *)(piVar6 + 10) = *(undefined2 *)(piVar8 + 10);
        _vm_map_reference(piVar6[4]);
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
        *piVar6 = *piVar1;
        piVar6[1] = *(int *)(*piVar1 + 4);
        iVar7 = *piVar6;
        *(int **)piVar6[1] = piVar6;
        *(int **)(iVar7 + 4) = piVar6;
        _pmap_copy(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(param_1 + 0x20),piVar6[2],
                   piVar8[3] - piVar8[2],piVar8[2]);
      }
      piVar8 = (int *)piVar8[1];
    } while ((int *)(param_1 + 8) != piVar8);
  }
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_1 + 0x24);
  _lock_done(param_1);
  return iVar3;
}

