/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00127280 */

int _ip_output(int param_1,int param_2,int *param_3,uint param_4,int param_5)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  int local_5c;
  int *local_58;
  int local_54;
  int *local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_34;
  uint local_30;
  byte local_2c [2];
  ushort local_2a;
  ushort local_26;
  undefined2 local_22;
  int local_18 [5];
  
  local_34 = 0x14;
  iVar8 = 0;
  local_40 = param_1;
  local_5c = 0;
  if (param_2 != 0) {
    local_40 = _ip_insertoptions(param_1,param_2,&local_30);
    local_34 = local_30;
  }
  pbVar7 = (byte *)(local_40 + *(int *)(local_40 + 4));
  if ((param_4 & 1) == 0) {
    *pbVar7 = *pbVar7 & 0xf | 0x40;
    *(ushort *)(pbVar7 + 6) = *(ushort *)(pbVar7 + 6) & 0x4000;
    uVar2 = _ip_id;
    _ip_id = _ip_id + 1;
    *(ushort *)(pbVar7 + 4) = uVar2 >> 8 | uVar2 << 8;
    *pbVar7 = *pbVar7 & 0xf0 | (byte)((int)local_34 >> 2) & 0xf;
  }
  else {
    local_34 = (*pbVar7 & 0xf) << 2;
  }
  if (param_3 == (int *)0x0) {
    param_3 = local_18;
    _bzero(param_3,0x14);
  }
  local_48 = param_3 + 1;
  iVar6 = *param_3;
  if (iVar6 == 0) {
LAB_00127373:
    *(undefined2 *)local_48 = 2;
    param_3[2] = *(int *)(pbVar7 + 0x10);
  }
  else {
    if (((*(byte *)(iVar6 + 0x24) & 1) == 0) || (param_3[2] != *(int *)(pbVar7 + 0x10))) {
      if (*(short *)(iVar6 + 0x26) == 1) {
        _rtfree(iVar6);
      }
      else {
        *(short *)(iVar6 + 0x26) = *(short *)(iVar6 + 0x26) + -1;
      }
      *param_3 = 0;
    }
    if (*param_3 == 0) goto LAB_00127373;
  }
  iVar6 = param_1;
  if ((param_4 & 0x10) == 0) {
    if ((*param_3 != 0) || (_rtalloc(param_3), *param_3 != 0)) {
      local_3c = *(int *)(*param_3 + 0x2c);
      if (local_3c == 0) goto LAB_001273f0;
      piVar4 = (int *)(*param_3 + 0x28);
      *piVar4 = *piVar4 + 1;
      if ((*(byte *)(*param_3 + 0x24) & 2) != 0) {
        local_48 = (int *)(*param_3 + 0x14);
      }
      goto LAB_0012742c;
    }
LAB_001273f0:
    iVar8 = _in_localaddr(*(undefined4 *)(pbVar7 + 0x10));
    local_5c = 0x33;
    if (iVar8 != 0) {
      local_5c = 0x41;
    }
    goto LAB_0012785c;
  }
  iVar8 = _ifa_ifwithdstaddr(local_48);
  if (iVar8 == 0) {
    uVar3 = _in_netof(*(undefined4 *)(pbVar7 + 0x10));
    iVar8 = _in_iaonnetof(uVar3);
    if (iVar8 == 0) {
      local_5c = 0x33;
      goto LAB_0012785c;
    }
  }
  local_3c = *(int *)(iVar8 + 0x20);
LAB_0012742c:
  if ((*(uint *)(pbVar7 + 0x10) & 0xf0) == 0xe0) {
    local_48 = param_3 + 1;
    if (((param_4 & 2) == 0) || (param_5 == 0)) {
      local_58 = (int *)0x0;
      pbVar7[8] = 1;
    }
    else {
      local_58 = (int *)(param_5 + *(int *)(param_5 + 4));
      pbVar7[8] = *(byte *)(local_58 + 1);
      if (*local_58 != 0) {
        local_3c = *local_58;
      }
    }
    iVar6 = local_40;
    if (*(int *)(pbVar7 + 0xc) == 0) {
      iVar8 = _in_ifaddr;
      if (_in_ifaddr != 0) {
        do {
          if (*(int *)(iVar8 + 0x20) == local_3c) {
            *(undefined4 *)(pbVar7 + 0xc) = *(undefined4 *)(iVar8 + 4);
            break;
          }
          iVar8 = *(int *)(iVar8 + 0x40);
        } while (iVar8 != 0);
        goto LAB_001274a7;
      }
LAB_001274ec:
      if (((_ip_mrouter == 0) || ((param_4 & 1) != 0)) ||
         (iVar8 = _ip_mforward(pbVar7,local_3c), iVar8 == 0)) goto LAB_0012751c;
    }
    else {
LAB_001274a7:
      if ((iVar8 == 0) || (piVar4 = *(int **)(iVar8 + 0x44), piVar4 == (int *)0x0))
      goto LAB_001274ec;
      do {
        if (*piVar4 == *(int *)(pbVar7 + 0x10)) break;
        piVar4 = (int *)piVar4[5];
      } while (piVar4 != (int *)0x0);
      if ((piVar4 == (int *)0x0) ||
         ((local_58 != (int *)0x0 && (*(char *)((int)local_58 + 5) == '\0')))) goto LAB_001274ec;
      _ip_mloopback(local_3c,local_40,local_48);
LAB_0012751c:
      if ((pbVar7[8] != 0) && (_loifp != local_3c)) goto LAB_001275c0;
    }
LAB_0012785c:
    _m_freem(iVar6);
  }
  else {
    iVar8 = _in_ifaddr;
    if (*(int *)(pbVar7 + 0xc) == 0) {
      for (; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x40)) {
        if (*(int *)(iVar8 + 0x20) == local_3c) {
          *(undefined4 *)(pbVar7 + 0xc) = *(undefined4 *)(iVar8 + 4);
          break;
        }
      }
    }
    iVar8 = _in_broadcast(local_48[1]);
    if (iVar8 == 0) {
LAB_001275c0:
      if (*(short *)(local_3c + 10) < *(short *)(pbVar7 + 2)) {
        if (((pbVar7[7] & 0x40) == 0) &&
           (local_30 = (int)*(short *)(local_3c + 10) - local_34 & 0xfffffff8, 7 < (int)local_30)) {
          iVar8 = (**(code **)(local_3c + 0x40))(local_3c);
          if (iVar8 == 0) {
LAB_0012789c:
            local_5c = 0x37;
            iVar6 = param_1;
          }
          else {
            pvVar5 = (void *)_nb_map(iVar8);
            _mbuf_read(local_40,pvVar5,0,local_34 + local_30);
            pbVar9 = pbVar7;
            pbVar10 = local_2c;
            for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined4 *)pbVar10 = *(undefined4 *)pbVar9;
              pbVar9 = pbVar9 + 4;
              pbVar10 = pbVar10 + 4;
            }
            local_2a = (ushort)((short)local_34 + (short)local_30) >> 8 |
                       ((short)local_34 + (short)local_30) * 0x100;
            local_26 = (*(ushort *)(pbVar7 + 6) | 0x2000) >> 8 | *(ushort *)(pbVar7 + 6) << 8;
            local_22 = 0;
            _bcopy(local_2c,pvVar5,0x14);
            uVar1 = _in_cksum(iVar8,local_34);
            local_22._0_1_ = (undefined1)uVar1;
            *(undefined1 *)((int)pvVar5 + 10) = (undefined1)local_22;
            local_22._1_1_ = (undefined1)((ushort)uVar1 >> 8);
            *(undefined1 *)((int)pvVar5 + 0xb) = local_22._1_1_;
            local_22 = uVar1;
            local_5c = (**(code **)(local_3c + 0x34))(local_3c,iVar8,local_48);
            iVar6 = param_1;
            if (local_5c == 0) {
              local_54 = 0x14;
              local_44 = local_34 + local_30;
              if (local_44 < *(short *)(pbVar7 + 2)) {
                do {
                  iVar8 = (**(code **)(local_3c + 0x40))(local_3c);
                  if (iVar8 == 0) goto LAB_0012789c;
                  pvVar5 = (void *)_nb_map(iVar8);
                  pbVar9 = pbVar7;
                  pbVar10 = local_2c;
                  for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(undefined4 *)pbVar10 = *(undefined4 *)pbVar9;
                    pbVar9 = pbVar9 + 4;
                    pbVar10 = pbVar10 + 4;
                  }
                  if (0x14 < local_34) {
                    local_54 = _ip_optcopy(pbVar7,pvVar5);
                    local_54 = local_54 + 0x14;
                    local_2c[0] = local_2c[0] & 0xf0 | (byte)(local_54 >> 2) & 0xf;
                  }
                  local_26 = (short)((int)(local_44 - local_34) >> 3) +
                             (*(ushort *)(pbVar7 + 6) & 0xdfff);
                  if ((pbVar7[7] & 0x20) != 0) {
                    local_26 = local_26 | 0x2000;
                  }
                  if ((int)(local_44 + local_30) < (int)*(short *)(pbVar7 + 2)) {
                    local_26 = local_26 | 0x2000;
                  }
                  else {
                    _nb_shrink_bot(iVar8,(local_44 + local_30) - (int)*(short *)(pbVar7 + 2));
                    local_30 = *(short *)(pbVar7 + 2) - local_44;
                  }
                  uVar2 = (short)local_54 + (short)local_30;
                  local_2a = uVar2 >> 8 | uVar2 * 0x100;
                  _mbuf_read(local_40,(int)pvVar5 + local_54,local_44,local_30);
                  local_26 = local_26 >> 8 | local_26 << 8;
                  local_22 = 0;
                  _bcopy(local_2c,pvVar5,0x14);
                  uVar1 = _in_cksum(iVar8,local_54);
                  local_22._0_1_ = (undefined1)uVar1;
                  *(undefined1 *)((int)pvVar5 + 10) = (undefined1)local_22;
                  local_22._1_1_ = (undefined1)((ushort)uVar1 >> 8);
                  *(undefined1 *)((int)pvVar5 + 0xb) = local_22._1_1_;
                  local_22 = uVar1;
                  local_5c = (**(code **)(local_3c + 0x34))(local_3c,iVar8,local_48);
                  iVar6 = param_1;
                } while ((local_5c == 0) &&
                        (local_44 = local_44 + local_30, local_44 < *(short *)(pbVar7 + 2)));
              }
            }
          }
        }
        else {
LAB_001275b1:
          local_5c = 0x28;
          iVar6 = param_1;
        }
        goto LAB_0012785c;
      }
    }
    else {
      if ((*(byte *)(local_3c + 0xc) & 2) == 0) {
        local_5c = 0x31;
        goto LAB_0012785c;
      }
      if ((param_4 & 0x20) == 0) {
        local_5c = 0xd;
        goto LAB_0012785c;
      }
      if (*(short *)(local_3c + 10) < *(short *)(pbVar7 + 2)) goto LAB_001275b1;
    }
    *(ushort *)(pbVar7 + 2) = *(ushort *)(pbVar7 + 2) >> 8 | *(ushort *)(pbVar7 + 2) << 8;
    *(ushort *)(pbVar7 + 6) = *(ushort *)(pbVar7 + 6) >> 8 | *(ushort *)(pbVar7 + 6) << 8;
    pbVar7[10] = 0;
    pbVar7[0xb] = 0;
    uVar1 = _in_cksum(local_40,local_34);
    *(undefined2 *)(pbVar7 + 10) = uVar1;
    local_5c = _if_output_mbuf(local_3c,local_40,local_48);
  }
  if (((param_3 == local_18) && ((param_4 & 0x10) == 0)) && (local_18[0] != 0)) {
    if (*(short *)(local_18[0] + 0x26) == 1) {
      _rtfree(local_18[0]);
    }
    else {
      *(short *)(local_18[0] + 0x26) = *(short *)(local_18[0] + 0x26) + -1;
    }
  }
  return local_5c;
}

