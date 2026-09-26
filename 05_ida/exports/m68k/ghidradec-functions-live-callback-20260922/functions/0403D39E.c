
undefined4 _ipc_kmsg_copyin_header(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iStack_20;
  int iStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  uint uStack_8;
  
  uVar1 = *param_1;
  uVar10 = param_1[2];
  uVar2 = param_1[3];
  if (param_3 == 0) {
    uVar11 = uVar1 & 0xffff;
    if (uVar11 == 0x13) {
      if ((uVar2 == 0) && (*(int *)(param_2 + 4) != 0)) {
        if ((uVar10 >> 8 < *(uint *)(param_2 + 0x10)) &&
           ((puVar8 = (uint *)((uVar10 >> 8) * 0x10 + *(int *)(param_2 + 0xc)),
            (uVar10 << 0x18 | 0x10000) == (*puVar8 & 0xff010000) &&
            (piVar3 = (int *)puVar8[1], piVar3[1] < 0)))) {
          piVar3[6] = piVar3[6] + 1;
          *piVar3 = *piVar3 + 1;
          *param_1 = uVar1 & 0xbfff0000 | 0x11;
          param_1[2] = (uint)piVar3;
          return 0;
        }
      }
    }
    else if (uVar11 < 0x14) {
      if (((uVar11 == 0x12) && (uVar2 == 0)) && (*(int *)(param_2 + 4) != 0)) {
        iVar7 = *(int *)(param_2 + 0xc);
        uVar11 = uVar10 >> 8;
        if (((uVar11 < *(uint *)(param_2 + 0x10)) &&
            (puVar8 = (uint *)(iVar7 + uVar11 * 0x10),
            (uVar10 << 0x18 | 0x40000) == (*puVar8 & 0xff840000))) &&
           ((puVar8[2] == 0 && (uVar12 = puVar8[1], *(int *)(uVar12 + 4) < 0)))) {
          puVar8[2] = *(uint *)(iVar7 + 8);
          *(uint *)(iVar7 + 8) = uVar11;
          *puVar8 = uVar10 << 0x18;
          puVar8[1] = 0;
          *param_1 = uVar1 & 0xbfff0000 | 0x12;
          param_1[2] = uVar12;
          return 0;
        }
      }
    }
    else if ((uVar11 == 0x1513) && (*(int *)(param_2 + 4) != 0)) {
      if ((uVar10 >> 8 < *(uint *)(param_2 + 0x10)) &&
         (puVar8 = (uint *)(*(int *)(param_2 + 0xc) + (uVar10 >> 8) * 0x10),
         (uVar10 << 0x18 | 0x10000) == (*puVar8 & 0xff010000))) {
        piVar3 = (int *)puVar8[1];
        if (((uVar2 >> 8 < *(uint *)(param_2 + 0x10)) &&
            (puVar8 = (uint *)(*(int *)(param_2 + 0xc) + (uVar2 >> 8) * 0x10),
            (uVar2 << 0x18 | 0x20000) == (*puVar8 & 0xff020000))) &&
           (piVar4 = (int *)puVar8[1], piVar3[1] < 0)) {
          piVar3[6] = piVar3[6] + 1;
          *piVar3 = *piVar3 + 1;
          piVar4[7] = piVar4[7] + 1;
          *piVar4 = *piVar4 + 1;
          *param_1 = CONCAT22((sword)((uVar1 & 0xbfffffff) >> 0x10),0x1211);
          param_1[2] = (uint)piVar3;
          param_1[3] = (uint)piVar4;
          return 0;
        }
      }
    }
  }
  uVar11 = uVar1 & 0xff;
  uVar12 = (uVar1 & 0xbfffffff) >> 8 & 0xff;
  iStack_20 = 0;
  if (4 < uVar11 - 0x11) {
    return 0x10000010;
  }
  if (uVar12 == 0) {
    if (uVar2 != 0) {
      return 0x10000010;
    }
  }
  else if (4 < uVar12 - 0x11) {
    return 0x10000010;
  }
  if (*(int *)(param_2 + 4) != 0) {
    if (param_3 != 0) {
      iVar7 = _ipc_entry_lookup(param_2,param_3);
      if ((iVar7 == 0) || ((*(byte *)(iVar7 + 1) & 2) == 0)) {
        return 0x1000000b;
      }
      iStack_20 = *(int *)(iVar7 + 4);
    }
    if (uVar2 == uVar10) {
      puVar8 = (uint *)_ipc_entry_lookup(param_2,uVar2);
      if (puVar8 != (uint *)0x0) {
        iVar7 = _ipc_right_copyin_check(param_2,uVar2,puVar8,uVar12);
        if (iVar7 == 0) {
          return 0x10000009;
        }
        if ((uVar11 != 0x12) && (uVar12 != 0x12)) {
          if ((uVar11 - 0x14 < 2) || (uVar12 - 0x14 < 2)) {
            iVar7 = _ipc_right_copyin(param_2,uVar2,puVar8,uVar11,0,&uStack_8,&iStack_c);
            if (iVar7 == 0) {
              _ipc_right_copyin(param_2,uVar2,puVar8,uVar12,1,&uStack_10,&iStack_14);
              goto loc_403D950;
            }
          }
          else if ((uVar11 == 0x13) && (uVar12 == 0x13)) {
            iVar7 = _ipc_right_copyin(param_2,uVar2,puVar8,0x13,0,&uStack_8,&iStack_c);
            if (iVar7 == 0) {
              uStack_10 = _ipc_port_copy_send(uStack_8);
              iStack_14 = 0;
              goto loc_403D950;
            }
          }
          else if ((uVar11 == 0x11) && (uVar12 == 0x11)) {
            iVar7 = _ipc_right_copyin_two(param_2,uVar2,puVar8,&uStack_8,&iStack_c);
            if (iVar7 == 0) {
              if ((*puVar8 & 0x1f0000) == 0) {
                _ipc_entry_dealloc(param_2,uVar2,puVar8);
              }
              uStack_10 = uStack_8;
              iStack_14 = 0;
loc_403D950:
              if ((param_3 != 0) && (iStack_c == iStack_20)) {
                _ipc_port_release_sonce(iStack_c);
                iStack_c = 0;
              }
              if (iStack_c != 0) {
                _ipc_notify_port_deleted(iStack_c,uVar10);
              }
              if (iStack_14 != 0) {
                _ipc_notify_port_deleted(iStack_14,uVar2);
              }
              uVar10 = _ipc_object_copyin_type(uVar11);
              iVar7 = _ipc_object_copyin_type(uVar12);
              *param_1 = uVar10 | iVar7 << 8 | uVar1 & 0xbfff0000;
              param_1[2] = uStack_8;
              param_1[3] = uStack_10;
              return 0;
            }
          }
          else {
            iVar7 = _ipc_right_copyin(param_2,uVar2,puVar8,0x11,0,&uStack_8,&iStack_18);
            if (iVar7 == 0) {
              if ((*puVar8 & 0x1f0000) == 0) {
                _ipc_entry_dealloc(param_2,uVar2,puVar8);
              }
              uStack_10 = _ipc_port_copy_send(uStack_8);
              if (uVar11 == 0x11) {
                iStack_c = iStack_18;
                iStack_14 = 0;
              }
              else {
                iStack_c = 0;
                iStack_14 = iStack_18;
              }
              goto loc_403D950;
            }
          }
        }
      }
    }
    else if ((uVar2 == 0) || (uVar2 == 0xffffffff)) {
      puVar8 = (uint *)_ipc_entry_lookup(param_2,uVar10);
      if ((puVar8 != (uint *)0x0) &&
         (iVar7 = _ipc_right_copyin(param_2,uVar10,puVar8,uVar11,0,&uStack_8,&iStack_c), iVar7 == 0)
         ) {
        if ((*puVar8 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar10,puVar8);
        }
        iStack_14 = 0;
        uStack_10 = uVar2;
        goto loc_403D950;
      }
    }
    else {
      puVar8 = (uint *)_ipc_entry_lookup(param_2,uVar10);
      if (puVar8 != (uint *)0x0) {
        puVar9 = (uint *)_ipc_entry_lookup(param_2,uVar2);
        if (puVar9 == (uint *)0x0) {
          return 0x10000009;
        }
        iVar7 = _ipc_right_copyin_check(param_2,uVar2,puVar9,uVar12);
        if (iVar7 == 0) {
          return 0x10000009;
        }
        iVar7 = _ipc_right_copyin(param_2,uVar10,puVar8,uVar11,0,&uStack_8,&iStack_c);
        if (iVar7 == 0) {
          uVar5 = puVar9[1];
          if (uVar5 != 0) {
            _ipc_object_reference(uVar5);
          }
          iVar7 = _ipc_right_copyin(param_2,uVar2,puVar9,uVar12,1,&uStack_10,&iStack_14);
          if (iVar7 == 0) {
            if ((uVar5 != 0) && (uStack_10 == 0xffffffff)) {
              bVar6 = false;
              if ((-1 < *(int *)(uStack_8 + 4)) &&
                 (*(int *)(uStack_8 + 8) - *(int *)(uVar5 + 8) < 0)) {
                bVar6 = true;
              }
              if (bVar6) {
                _ipc_right_copyin_undo(param_2,uVar10,puVar8,uVar11,uStack_8,iStack_c);
                _ipc_right_copyin_undo(param_2,uVar2,puVar9,uVar12,uStack_10,iStack_14);
                if (iStack_c != 0) {
                  _ipc_notify_dead_name(iStack_c,uVar10);
                }
                _ipc_object_release(uVar5);
                return 0x10000003;
              }
            }
            if ((*puVar9 & 0x1f0000) == 0) {
              _ipc_entry_dealloc(param_2,uVar2,puVar9);
            }
          }
          else {
            uStack_10 = 0xffffffff;
            iStack_14 = 0;
          }
          if ((*puVar8 & 0x1f0000) == 0) {
            _ipc_entry_dealloc(param_2,uVar10,puVar8);
          }
          if (uVar5 != 0) {
            _ipc_object_release(uVar5);
          }
          goto loc_403D950;
        }
      }
    }
  }
  return 0x10000003;
}

