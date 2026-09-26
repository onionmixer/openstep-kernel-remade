
/* WARNING: Removing unreachable block (ram,0xf0087880) */
/* WARNING: Removing unreachable block (ram,0xf00877f0) */
/* WARNING: Removing unreachable block (ram,0xf00877c4) */
/* WARNING: Removing unreachable block (ram,0xf0087784) */
/* WARNING: Removing unreachable block (ram,0xf0087938) */
/* WARNING: Removing unreachable block (ram,0xf0087960) */
/* WARNING: Removing unreachable block (ram,0xf008779c) */
/* WARNING: Removing unreachable block (ram,0xf00877d8) */
/* WARNING: Removing unreachable block (ram,0xf008785c) */
/* WARNING: Removing unreachable block (ram,0xf00878e0) */
/* WARNING: Removing unreachable block (ram,0xf00876ec) */

undefined8 _vm_object_collapse(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  int *piVar7;
  int iVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  uint uVar10;
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
  if (_vm_object_collapse_allowed == 0) {
locret_F008799C:
    return CONCAT44(param_2,param_1);
  }
loc_F00876A0:
  if (((param_1 == 0) || (*(sword *)(param_1 + 0x44) != 0)) || (*(int *)(param_1 + 0x28) != 0))
  goto locret_F008799C;
  piVar7 = *(int **)(param_1 + 0x20);
  if (piVar7 == (int *)0x0) goto locret_F008799C;
  do {
    do {
    } while (piVar7[4] != 0);
    piVar2 = piVar7 + 4;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if ((piVar7[0x11] & 0xffff0800U) == 0x800) {
    if (piVar7[8] == 0) {
      uVar9 = *(uint *)(param_1 + 0x24);
    }
    else {
      if (*(int *)(piVar7[8] + 0x1c) != 0) goto loc_F0087734;
      uVar9 = *(uint *)(param_1 + 0x24);
    }
    uVar10 = *(uint *)(param_1 + 0x14);
    if (*(sword *)(piVar7 + 6) == 1) {
      piVar2 = (int *)*piVar7;
loc_F00877FC:
      do {
        if (piVar7 == piVar2) goto loc_f0087808;
        iVar8 = *piVar7;
        uVar6 = *(uint *)(iVar8 + 0x18) - uVar9;
        if ((*(uint *)(iVar8 + 0x18) < uVar9) || (uVar10 <= uVar6)) {
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar4 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar4 == (undefined4 *)0x0);
        }
        else {
          iVar3 = param_1;
          _vm_page_lookup(param_1,uVar6);
          if (iVar3 == 0) {
            _vm_page_rename(iVar8,param_1,uVar6);
            piVar2 = (int *)*piVar7;
            goto loc_F00877FC;
          }
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar4 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar4 == (undefined4 *)0x0);
        }
        _vm_page_free(iVar8);
        _vm_page_queue_lock = 0;
        piVar2 = (int *)*piVar7;
      } while( true );
    }
    if (piVar7[10] == 0) {
      piVar2 = (int *)*piVar7;
      if (piVar7 == piVar2) {
        iVar8 = piVar7[8];
      }
      else {
        uVar6 = piVar2[6];
        while( true ) {
          if (((uVar9 <= uVar6) && (uVar6 - uVar9 <= uVar10)) &&
             (iVar8 = param_1, _vm_page_lookup(param_1,uVar6 - uVar9), iVar8 == 0))
          goto loc_F0087734;
          piVar2 = (int *)piVar2[2];
          if (piVar7 == piVar2) break;
          uVar6 = piVar2[6];
        }
        iVar8 = piVar7[8];
      }
      *(int *)(param_1 + 0x20) = iVar8;
      _vm_object_reference();
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + piVar7[9];
      piVar7[4] = 0;
      _object_bypasses = _object_bypasses + 1;
      *(sword *)(piVar7 + 6) = *(sword *)(piVar7 + 6) + -1;
      goto loc_F00876A0;
    }
  }
loc_F0087734:
  piVar7[4] = 0;
  goto locret_F008799C;
loc_f0087808:
  *(int *)(param_1 + 0x28) = piVar7[10];
  *(uint *)(param_1 + 0x2c) = piVar7[0xb] + uVar9;
  piVar7[10] = 0;
  piVar7[0xc] = 0;
  piVar7[0xd] = 0;
  *(int *)(param_1 + 0x20) = piVar7[8];
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + piVar7[9];
  if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(*(int *)(param_1 + 0x20) + 0x1c) != 0)) {
    _panic(aVmObjectCollap);
  }
  piVar7[4] = 0;
  do {
    do {
    } while (_vm_object_list_lock != 0);
    puVar4 = &_vm_object_list_lock;
    _simple_lock_try();
  } while (puVar4 == (undefined4 *)0x0);
  puVar4 = (undefined4 *)piVar7[2];
  puVar5 = (undefined4 *)piVar7[3];
  puVar1 = puVar5;
  if ((undefined4 **)puVar4 != &_vm_object_list) {
    puVar4[3] = puVar5;
    puVar1 = dword_F013D834;
  }
  dword_F013D834 = puVar1;
  if ((undefined4 **)puVar5 != &_vm_object_list) {
    puVar5[2] = puVar4;
    puVar4 = _vm_object_list;
  }
  _vm_object_list = puVar4;
  _vm_object_list_lock = 0;
  _vm_object_count = _vm_object_count + -1;
  _zfree(_vm_object_zone,piVar7);
  _object_collapses = _object_collapses + 1;
  goto loc_F00876A0;
}
