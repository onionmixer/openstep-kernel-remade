
/* WARNING: Removing unreachable block (ram,0xf005a700) */
/* WARNING: Removing unreachable block (ram,0xf005a654) */
/* WARNING: Removing unreachable block (ram,0xf005a5d4) */
/* WARNING: Removing unreachable block (ram,0xf005a6f0) */
/* WARNING: Removing unreachable block (ram,0xf005a5b4) */
/* WARNING: Removing unreachable block (ram,0xf005a5a0) */

undefined8 _ipc_port_dngrow(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint *puVar8;
  undefined4 unaff_l4;
  uint *puVar9;
  undefined4 unaff_l5;
  uint *puVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
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
  puVar8 = (uint *)param_1[0xb];
  puVar10 = _ipc_table_dnrequests;
  if (puVar8 != (uint *)0x0) {
    puVar10 = (uint *)(puVar8[1] + 4);
  }
  param_1[1] = param_1[1] + 1;
  *param_1 = 0;
  if (*puVar10 != 0) {
    puVar1 = (uint *)(*puVar10 << 3);
    _ipc_table_alloc();
    if (puVar1 != (uint *)0x0) {
      do {
        do {
        } while (*param_1 != 0);
        piVar2 = param_1;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      param_1[1] = param_1[1] + -1;
      if (param_1[2] < 0) {
        if ((uint *)param_1[0xb] != puVar8) {
          iVar3 = param_1[1];
          goto loc_F005A6C8;
        }
        puVar9 = (uint *)0x0;
        if (puVar8 == (uint *)0x0) {
loc_F005A664:
          uVar4 = 1;
          uVar7 = 0;
          uVar6 = *puVar10;
        }
        else {
          if ((uint *)(puVar8[1] + 4) != puVar10) {
            iVar3 = param_1[1];
            goto loc_F005A6C8;
          }
          if (puVar8 == (uint *)0x0) goto loc_F005A664;
          puVar9 = (uint *)puVar8[1];
          uVar4 = *puVar9;
          uVar7 = *puVar8;
          _bcopy(puVar8 + 2,puVar1 + 2,(uVar4 - 1) * 8);
          uVar6 = *puVar10;
        }
        if (uVar4 < uVar6) {
          do {
            uVar5 = uVar4;
            puVar1[uVar5 * 2 + 1] = 0;
            puVar1[uVar5 * 2] = uVar7;
            uVar4 = uVar5 + 1;
            uVar7 = uVar5;
          } while (uVar5 + 1 < uVar6);
          *puVar1 = uVar5;
        }
        else {
          *puVar1 = uVar7;
        }
        puVar1[1] = (uint)puVar10;
        param_1[0xb] = (int)puVar1;
        *param_1 = 0;
        if (puVar8 != (uint *)0x0) {
          uVar4 = *puVar9;
          goto loc_F005A700;
        }
      }
      else {
        iVar3 = param_1[1];
loc_F005A6C8:
        *param_1 = 0;
        if (iVar3 == 0) {
          _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffffU) >> 0x10],param_1);
        }
        uVar4 = *puVar10;
        puVar8 = puVar1;
loc_F005A700:
        _ipc_table_free(uVar4 << 3,puVar8);
      }
      uVar11 = 0;
      goto locret_F005A70C;
    }
  }
  _ipc_object_release(param_1);
  uVar11 = 6;
locret_F005A70C:
  return CONCAT44(param_2,uVar11);
}

