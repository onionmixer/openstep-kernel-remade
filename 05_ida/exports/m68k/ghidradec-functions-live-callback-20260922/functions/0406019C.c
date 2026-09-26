
void _vm_object_collapse(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  
  if (_vm_object_collapse_allowed != 0) {
    while ((((param_1 != 0 && (*(sword *)(param_1 + 0x40) == 0)) && (*(int *)(param_1 + 0x24) == 0))
           && (((piVar2 = *(int **)(param_1 + 0x1c), piVar2 != (int *)0x0 &&
                ((piVar2[0x10] & 0xffff0800U) == 0x800)) &&
               ((piVar2[7] == 0 || (*(int *)(piVar2[7] + 0x18) == 0))))))) {
      uVar3 = *(uint *)(param_1 + 0x20);
      uVar4 = *(uint *)(param_1 + 0x10);
      if (*(sword *)(piVar2 + 5) == 1) {
        while (piVar2 != (int *)*piVar2) {
          iVar10 = *piVar2;
          uVar7 = *(uint *)(iVar10 + 0x18) - uVar3;
          if (((*(uint *)(iVar10 + 0x18) < uVar3) || (uVar4 <= uVar7)) ||
             (iVar9 = _vm_page_lookup(param_1,uVar7), iVar9 != 0)) {
            _vm_page_free(iVar10);
          }
          else {
            _vm_page_rename(iVar10,param_1,uVar7);
          }
        }
        *(int *)(param_1 + 0x24) = piVar2[9];
        *(uint *)(param_1 + 0x28) = piVar2[10] + uVar3;
        piVar2[9] = 0;
        piVar2[0xb] = 0;
        piVar2[0xc] = 0;
        *(int *)(param_1 + 0x1c) = piVar2[7];
        *(int *)(param_1 + 0x20) = piVar2[8] + *(int *)(param_1 + 0x20);
        if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(*(int *)(param_1 + 0x1c) + 0x18) != 0)) {
                    /* WARNING: Subroutine does not return */
          _panic(aVmObjectCollap);
        }
        puVar5 = (undefined4 *)piVar2[2];
        puVar6 = (undefined4 *)piVar2[3];
        puVar8 = puVar6;
        if ((undefined4 **)puVar5 != &_vm_object_list) {
          puVar5[3] = puVar6;
          puVar8 = dword_40C31B0;
        }
        dword_40C31B0 = puVar8;
        if ((undefined4 **)puVar6 != &_vm_object_list) {
          puVar6[2] = puVar5;
          puVar5 = _vm_object_list;
        }
        _vm_object_list = puVar5;
        _vm_object_count = _vm_object_count + -1;
        _zfree(_vm_object_zone,piVar2);
        _object_collapses = _object_collapses + 1;
      }
      else {
        if (piVar2[9] != 0) {
          return;
        }
        for (piVar1 = (int *)*piVar2; piVar1 != piVar2; piVar1 = (int *)piVar1[2]) {
          uVar7 = piVar1[6] - uVar3;
          if (((uVar3 <= (uint)piVar1[6]) && (uVar7 <= uVar4)) &&
             (iVar10 = _vm_page_lookup(param_1,uVar7), iVar10 == 0)) {
            return;
          }
        }
        iVar10 = piVar2[7];
        *(int *)(param_1 + 0x1c) = iVar10;
        _vm_object_reference(iVar10);
        *(int *)(param_1 + 0x20) = piVar2[8] + *(int *)(param_1 + 0x20);
        *(sword *)(piVar2 + 5) = *(sword *)(piVar2 + 5) + -1;
        _object_bypasses = _object_bypasses + 1;
      }
    }
  }
  return;
}

