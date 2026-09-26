/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011fddc */

undefined4 FUN_0011fddc(uint param_1,int param_2,undefined4 param_3,void *param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  byte *pbVar7;
  undefined *puVar8;
  size_t sVar9;
  uint *local_54;
  uint local_48;
  undefined1 local_3c [8];
  uint local_34;
  undefined2 local_30;
  byte local_2e [18];
  uint *local_1c;
  undefined8 local_18;
  uint local_10;
  undefined2 local_c;
  ushort local_6;
  
  iVar3 = _if_private(param_1);
  if (*(int *)(iVar3 + 0x14) != param_2) {
    return 0x2f;
  }
  uVar4 = _nb_size(param_3);
  if ((8 < uVar4) && ((*(byte *)((int)param_4 + 1) & 0xc0) == 0x40)) {
    sVar9 = 6;
    puVar8 = &DAT_001db896;
    pvVar5 = (void *)_nb_map(param_3);
    iVar3 = _bcmp(pvVar5,puVar8,sVar9);
    if (iVar3 == 0) {
      _nb_read(param_3,6,2,&local_6);
      _nb_shrink_top(param_3,8);
      local_6 = local_6 >> 8 | local_6 << 8;
      if ((ushort)(local_6 - 0x1000) < 0x10) {
        uVar6 = _nullsap_input(param_1,param_2,param_3,param_4);
        return uVar6;
      }
      if (local_6 != 0x800) {
        if (local_6 != 0x806) {
          uVar6 = _nullsap_input(param_1,param_2,param_3,param_4);
          return uVar6;
        }
        iVar3 = _if_ipackets(param_1);
        _if_ipackets_set(param_1,iVar3 + 1);
        uVar4 = _if_flags(param_1);
        if ((uVar4 & 0x4000) != 0) {
          _nb_free(param_3);
          return 0;
        }
        pbVar7 = (byte *)_if_private(param_1);
        if ((*pbVar7 & 1) != 0) {
          _bcopy(param_4,local_3c,0x20);
          iVar3 = _nb_map(param_3);
          local_48 = *(uint *)(iVar3 + 0xe);
        }
        _nb_write(param_3,0,2,&DAT_001db89e);
        iVar3 = _if_private(param_1,param_3);
        iVar3 = _if_private(param_1,*(undefined4 *)(iVar3 + 0x10));
        _arpinput(param_1,iVar3 + 8);
        pbVar7 = (byte *)_if_private(param_1);
        if ((*pbVar7 & 1) == 0) {
          return 0;
        }
        iVar3 = _if_private(param_1);
        uVar6 = *(undefined4 *)(iVar3 + 4);
        local_c = local_30;
        local_10._0_1_ = (char)local_34;
        cVar2 = (char)local_10;
        local_10 = local_34 & 0xffffff7f;
        if (-1 < cVar2) {
          return 0;
        }
        if ((local_2e[0] & 0x1f) < 3) {
          return 0;
        }
        if (0x10 < (local_2e[0] & 0x1f) - 2) {
          return 0;
        }
        if ((local_2e[0] & 1) != 0) {
          return 0;
        }
        local_1c = (uint *)_NXHashGet(uVar6,&local_10);
        if (local_1c != (uint *)0x0) {
          _bcopy(local_2e,local_1c + 3,local_2e[0] & 0x1f);
          *(byte *)(local_1c + 3) = (byte)local_1c[3] & 0x1f;
          *(byte *)((int)local_1c + 0xd) =
               *(byte *)((int)local_1c + 0xd) & 0x7f | ~(*(byte *)((int)local_1c + 0xd) >> 7) << 7;
          return 0;
        }
        uVar4 = _NXCountHashTable(uVar6);
        if (499 < uVar4) {
          bVar1 = false;
          local_18 = _NXInitHashState(uVar6);
          do {
            do {
              iVar3 = _NXNextHashState(uVar6,&local_18,&local_1c);
              if (iVar3 == 0) goto LAB_0012039a;
              local_54 = (uint *)(&_arptab + (local_1c[2] % 0x13) * 0xb4);
              iVar3 = 0;
              do {
                if ((*local_54 == local_1c[2]) && ((param_1 == 0 || (local_54[4] == param_1))))
                break;
                iVar3 = iVar3 + 1;
                local_54 = local_54 + 5;
              } while (iVar3 < 9);
              if (8 < iVar3) {
                local_54 = (uint *)0x0;
              }
            } while ((local_54 != (uint *)0x0) && (local_1c[2] != 0));
            local_1c = (uint *)_NXHashRemove(uVar6,local_1c);
          } while (local_1c == (uint *)0x0);
          _kfree(local_1c,0x20);
          bVar1 = true;
LAB_0012039a:
          if (!bVar1) {
            _printf(s_add_sr__source_route_table_overf_001db870);
            return 0;
          }
        }
        local_1c = (uint *)_kalloc(0x20);
        *local_1c = local_10;
        *(undefined2 *)(local_1c + 1) = local_c;
        local_1c[2] = local_48;
        _bcopy(local_2e,local_1c + 3,local_2e[0] & 0x1f);
        *(byte *)(local_1c + 3) = (byte)local_1c[3] & 0x1f;
        local_54._0_1_ = ~(*(byte *)((int)local_1c + 0xd) >> 7);
        *(byte *)((int)local_1c + 0xd) = *(byte *)((int)local_1c + 0xd) & 0x7f | (byte)local_54 << 7
        ;
        local_1c = (uint *)_NXHashInsert(uVar6,local_1c);
        if (local_1c == (uint *)0x0) {
          return 0;
        }
        _kfree(local_1c,0x20);
        return 0;
      }
      iVar3 = _if_ipackets(param_1);
      _if_ipackets_set(param_1,iVar3 + 1);
      uVar4 = _if_flags(param_1);
      local_18 = CONCAT44(local_18._4_4_,(undefined4)local_18);
      if ((uVar4 & 0x4000) == 0) {
        pbVar7 = (byte *)_if_private(param_1);
        local_18 = CONCAT44(local_18._4_4_,(undefined4)local_18);
        if ((*pbVar7 & 1) != 0) {
          iVar3 = _if_private(param_1);
          uVar6 = *(undefined4 *)(iVar3 + 4);
          local_c = *(undefined2 *)((int)param_4 + 0xc);
          local_10 = *(uint *)((int)param_4 + 8) & 0xffffff7f;
          local_18 = CONCAT44(local_18._4_4_,(undefined4)local_18);
          if (*(char *)((int)param_4 + 8) < '\0') {
            uVar4 = *(byte *)((int)param_4 + 0xe) & 0x1f;
            local_18 = CONCAT44(local_18._4_4_,(undefined4)local_18);
            if (2 < uVar4) {
              pbVar7 = (byte *)((int)param_4 + 0xe);
              local_18 = CONCAT44(local_18._4_4_,(undefined4)local_18);
              if ((uVar4 - 2 < 0x11) &&
                 (local_18 = CONCAT44(local_18._4_4_,(undefined4)local_18),
                 (*(byte *)((int)param_4 + 0xe) & 1) == 0)) {
                local_1c = (uint *)_NXHashGet(uVar6,&local_10);
                if (local_1c == (uint *)0x0) {
                  uVar4 = _NXCountHashTable(uVar6);
                  if (499 < uVar4) {
                    bVar1 = false;
                    local_18 = _NXInitHashState(uVar6);
                    do {
                      do {
                        iVar3 = _NXNextHashState(uVar6,&local_18,&local_1c);
                        if (iVar3 == 0) goto LAB_0012009f;
                        local_54 = (uint *)(&_arptab + (local_1c[2] % 0x13) * 0xb4);
                        iVar3 = 0;
                        do {
                          if ((*local_54 == local_1c[2]) &&
                             ((param_1 == 0 || (local_54[4] == param_1)))) break;
                          iVar3 = iVar3 + 1;
                          local_54 = local_54 + 5;
                        } while (iVar3 < 9);
                        if (8 < iVar3) {
                          local_54 = (uint *)0x0;
                        }
                      } while ((local_54 != (uint *)0x0) && (local_1c[2] != 0));
                      local_1c = (uint *)_NXHashRemove(uVar6,local_1c);
                    } while (local_1c == (uint *)0x0);
                    _kfree(local_1c,0x20);
                    bVar1 = true;
LAB_0012009f:
                    if (!bVar1) {
                      _printf(s_add_sr__source_route_table_overf_001db870);
                      goto LAB_0012013d;
                    }
                  }
                  local_1c = (uint *)_kalloc(0x20);
                  *local_1c = local_10;
                  *(undefined2 *)(local_1c + 1) = local_c;
                  local_1c[2] = 0;
                  _bcopy(pbVar7,local_1c + 3,*pbVar7 & 0x1f);
                  *(byte *)(local_1c + 3) = (byte)local_1c[3] & 0x1f;
                  local_54._0_1_ = ~(*(byte *)((int)local_1c + 0xd) >> 7);
                  *(byte *)((int)local_1c + 0xd) =
                       *(byte *)((int)local_1c + 0xd) & 0x7f | (byte)local_54 << 7;
                  local_1c = (uint *)_NXHashInsert(uVar6,local_1c);
                  if (local_1c != (uint *)0x0) {
                    _kfree(local_1c,0x20);
                  }
                }
                else {
                  _bcopy(pbVar7,local_1c + 3,*(byte *)((int)param_4 + 0xe) & 0x1f);
                  *(byte *)(local_1c + 3) = (byte)local_1c[3] & 0x1f;
                  local_54._0_1_ = ~(*(byte *)((int)local_1c + 0xd) >> 7);
                  *(byte *)((int)local_1c + 0xd) =
                       *(byte *)((int)local_1c + 0xd) & 0x7f | (byte)local_54 << 7;
                }
              }
            }
          }
        }
      }
LAB_0012013d:
      _inet_queue(param_1,param_3);
      return 0;
    }
  }
  uVar6 = _nullsap_input(param_1,param_2,param_3,param_4);
  return uVar6;
}

