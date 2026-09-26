
int _ip_output(int param_1,int param_2,int *param_3,byte param_4,int param_5)

{
  word wVar1;
  undefined4 uVar2;
  undefined2 uVar4;
  int iVar3;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  int *piVar13;
  int iVar14;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_1c;
  int aiStack_18 [5];
  
  iVar10 = 0;
  iStack_34 = param_1;
  iVar5 = 0;
  uVar7 = 0x14;
  if (param_2 != 0) {
    iStack_34 = _ip_insertoptions(param_1,param_2,&uStack_30);
    uVar7 = uStack_30;
  }
  puVar12 = (uint *)(*(int *)(iStack_34 + 4) + iStack_34);
  if ((param_4 & 1) == 0) {
    *(byte *)puVar12 = *(byte *)puVar12 & 0x4f | 0x40;
    *(word *)((int)puVar12 + 6) = *(word *)((int)puVar12 + 6) & 0x4000;
    *(sword *)(puVar12 + 1) = _ip_id;
    _ip_id = _ip_id + 1;
    *puVar12 = *puVar12 & 0xf0ffffff | ((uVar7 & 0x3f) >> 2) << 0x18;
  }
  else {
    uVar7 = (*(byte *)puVar12 & 0xf) << 2;
  }
  if (param_3 == (int *)0x0) {
    param_3 = aiStack_18;
    _bzero(param_3,0x14);
  }
  piVar8 = param_3 + 1;
  iVar3 = *param_3;
  if (iVar3 == 0) {
loc_4021B5E:
    *(undefined2 *)piVar8 = 2;
    param_3[2] = puVar12[4];
  }
  else {
    if (((*(byte *)(iVar3 + 0x25) & 1) == 0) || (param_3[2] != puVar12[4])) {
      if (*(sword *)(iVar3 + 0x26) == 1) {
        _rtfree(iVar3);
      }
      else {
        *(sword *)(iVar3 + 0x26) = *(sword *)(iVar3 + 0x26) + -1;
      }
      *param_3 = 0;
    }
    if (*param_3 == 0) goto loc_4021B5E;
  }
  iVar3 = param_1;
  if ((param_4 & 0x10) == 0) {
    if ((*param_3 != 0) || (_rtalloc(param_3), *param_3 != 0)) {
      iVar14 = *(int *)(*param_3 + 0x2c);
      if (iVar14 == 0) goto loc_4021BCA;
      piVar13 = (int *)(*param_3 + 0x28);
      *piVar13 = *piVar13 + 1;
      if ((*(byte *)(*param_3 + 0x25) & 2) != 0) {
        piVar8 = (int *)(*param_3 + 0x14);
      }
      goto loc_4021BF8;
    }
loc_4021BCA:
    iVar10 = _in_localaddr(puVar12[4]);
    iVar5 = 0x33;
    if (iVar10 != 0) {
      iVar5 = 0x41;
    }
    goto loc_4021F5C;
  }
  iVar10 = _ifa_ifwithdstaddr(piVar8);
  if (iVar10 == 0) {
    uVar2 = _in_netof(puVar12[4]);
    iVar10 = _in_iaonnetof(uVar2);
    if (iVar10 == 0) {
      iVar5 = 0x33;
      goto loc_4021F5C;
    }
  }
  iVar14 = *(int *)(iVar10 + 0x20);
loc_4021BF8:
  if ((puVar12[4] & 0xf0000000) == 0xe0000000) {
    piVar8 = param_3 + 1;
    if (((param_4 & 2) == 0) || (param_5 == 0)) {
      piVar13 = (int *)0x0;
      *(byte *)(puVar12 + 2) = 1;
    }
    else {
      piVar13 = (int *)(*(int *)(param_5 + 4) + param_5);
      *(byte *)(puVar12 + 2) = *(byte *)(piVar13 + 1);
      if (*piVar13 != 0) {
        iVar14 = *piVar13;
      }
    }
    iVar3 = iStack_34;
    if (puVar12[3] == 0) {
      iVar10 = _in_ifaddr;
      if (_in_ifaddr != 0) {
        do {
          if (iVar14 == *(int *)(iVar10 + 0x20)) {
            puVar12[3] = *(uint *)(iVar10 + 4);
            break;
          }
          iVar10 = *(int *)(iVar10 + 0x40);
        } while (iVar10 != 0);
        goto loc_4021C5C;
      }
loc_4021C9A:
      if (((_ip_mrouter == 0) || ((param_4 & 1) != 0)) ||
         (iVar10 = _ip_mforward(puVar12,iVar14), iVar10 == 0)) goto loc_4021CC2;
    }
    else {
loc_4021C5C:
      if ((iVar10 == 0) || (puVar9 = *(uint **)(iVar10 + 0x44), puVar9 == (uint *)0x0))
      goto loc_4021C9A;
      do {
        if (puVar12[4] == *puVar9) break;
        puVar9 = (uint *)puVar9[5];
      } while (puVar9 != (uint *)0x0);
      if ((puVar9 == (uint *)0x0) ||
         ((piVar13 != (int *)0x0 && (*(char *)((int)piVar13 + 5) == '\0')))) goto loc_4021C9A;
      _ip_mloopback(iVar14,iStack_34,piVar8);
loc_4021CC2:
      if ((*(byte *)(puVar12 + 2) != 0) && (iVar14 != _loifp)) goto loc_4021D3C;
    }
loc_4021F5C:
    _m_freem(iVar3);
  }
  else {
    iVar10 = _in_ifaddr;
    if (puVar12[3] == 0) {
      for (; iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x40)) {
        if (iVar14 == *(int *)(iVar10 + 0x20)) {
          puVar12[3] = *(uint *)(iVar10 + 4);
          break;
        }
      }
    }
    iVar10 = _in_broadcast(piVar8[1]);
    if (iVar10 == 0) {
loc_4021D3C:
      if (*(sword *)(iVar14 + 10) < (sword)*puVar12) {
        if (((*(byte *)((int)puVar12 + 6) & 0x40) == 0) &&
           (uStack_30 = (int)*(sword *)(iVar14 + 10) - uVar7 & 0xfffffff8, 7 < (int)uStack_30)) {
          iVar10 = (**(code **)(iVar14 + 0x3e))(iVar14);
          if (iVar10 == 0) {
loc_4021F9A:
            iVar5 = 0x37;
            iVar3 = param_1;
          }
          else {
            iVar5 = _nb_map(iVar10);
            _mbuf_read(iStack_34,iVar5,0,uStack_30 + uVar7);
            uStack_20 = puVar12[3];
            uStack_1c = puVar12[4];
            uStack_2c._0_2_ = (undefined2)(*puVar12 >> 0x10);
            uStack_2c = CONCAT22(uStack_2c._0_2_,uStack_30._2_2_ + (sword)uVar7);
            uStack_28._0_2_ = (undefined2)(puVar12[1] >> 0x10);
            uStack_28 = CONCAT22(uStack_28._0_2_,*(undefined2 *)((int)puVar12 + 6)) | 0x2000;
            uStack_24 = puVar12[2] & 0xffff0000;
            _bcopy(&uStack_2c,iVar5,0x14);
            uVar4 = _in_cksum(iVar10,uVar7);
            uStack_24 = CONCAT22(uStack_24._0_2_,uVar4);
            uVar2 = uStack_24;
            uStack_24._2_1_ = (undefined)((word)uVar4 >> 8);
            *(undefined *)(iVar5 + 10) = uStack_24._2_1_;
            uStack_24._3_1_ = (undefined)uVar4;
            *(undefined *)(iVar5 + 0xb) = (undefined)uStack_24;
            uStack_24 = uVar2;
            iVar5 = (**(code **)(iVar14 + 0x32))(iVar14,iVar10,piVar8);
            iVar3 = param_1;
            if (iVar5 == 0) {
              uVar6 = 0x14;
              uVar11 = uVar7;
              do {
                uVar11 = uStack_30 + uVar11;
                iVar3 = param_1;
                if ((int)(sword)*puVar12 <= (int)uVar11) break;
                iVar10 = (**(code **)(iVar14 + 0x3e))(iVar14);
                if (iVar10 == 0) goto loc_4021F9A;
                iVar5 = _nb_map(iVar10);
                uStack_2c = *puVar12;
                uStack_28 = puVar12[1];
                uStack_24 = puVar12[2];
                uStack_20 = puVar12[3];
                uStack_1c = puVar12[4];
                if (0x14 < uVar7) {
                  iVar3 = _ip_optcopy(puVar12,iVar5);
                  uVar6 = iVar3 + 0x14;
                  uStack_2c = uStack_2c & 0xf0ffffff | ((uVar6 & 0x3f) >> 2) << 0x18;
                }
                wVar1 = (sword)((int)(uVar11 - uVar7) >> 3) + (*(word *)((int)puVar12 + 6) & 0xdfff)
                ;
                if ((*(byte *)((int)puVar12 + 6) & 0x20) != 0) {
                  wVar1 = wVar1 | 0x2000;
                }
                uStack_28 = CONCAT22(uStack_28._0_2_,wVar1);
                if ((int)(uStack_30 + uVar11) < (int)(sword)*puVar12) {
                  uStack_28 = CONCAT22(uStack_28._0_2_,wVar1) | 0x2000;
                }
                else {
                  _nb_shrink_bot(iVar10,(uStack_30 + uVar11) - (int)(sword)*puVar12);
                  uStack_30 = (int)(sword)*puVar12 - uVar11;
                }
                uStack_2c = CONCAT22(uStack_2c._0_2_,(sword)uVar6 + (sword)uStack_30);
                _mbuf_read(iStack_34,iVar5 + uVar6,uVar11,uStack_30);
                uStack_24 = uStack_24 & 0xffff0000;
                _bcopy(&uStack_2c,iVar5,0x14);
                uVar4 = _in_cksum(iVar10,uVar6);
                uStack_24 = CONCAT22(uStack_24._0_2_,uVar4);
                uVar2 = uStack_24;
                uStack_24._2_1_ = (undefined)((word)uVar4 >> 8);
                *(undefined *)(iVar5 + 10) = uStack_24._2_1_;
                uStack_24._3_1_ = (undefined)uVar4;
                *(undefined *)(iVar5 + 0xb) = (undefined)uStack_24;
                uStack_24 = uVar2;
                iVar5 = (**(code **)(iVar14 + 0x32))(iVar14,iVar10,piVar8);
                iVar3 = param_1;
              } while (iVar5 == 0);
            }
          }
        }
        else {
loc_4021D36:
          iVar5 = 0x28;
          iVar3 = param_1;
        }
        goto loc_4021F5C;
      }
    }
    else {
      if ((*(byte *)(iVar14 + 0xd) & 2) == 0) {
        iVar5 = 0x31;
        goto loc_4021F5C;
      }
      if ((param_4 & 0x20) == 0) {
        iVar5 = 0xd;
        goto loc_4021F5C;
      }
      if (*(sword *)(iVar14 + 10) < (sword)*puVar12) goto loc_4021D36;
    }
    ((byte *)((int)puVar12 + 10))[0] = 0;
    ((byte *)((int)puVar12 + 10))[1] = 0;
    uVar4 = _in_cksum(iStack_34,uVar7);
    *(undefined2 *)((int)puVar12 + 10) = uVar4;
    iVar5 = _if_output_mbuf(iVar14,iStack_34,piVar8);
  }
  if (((aiStack_18 == param_3) && ((param_4 & 0x10) == 0)) && (iVar10 = *param_3, iVar10 != 0)) {
    if (*(sword *)(iVar10 + 0x26) == 1) {
      _rtfree(iVar10);
    }
    else {
      *(sword *)(iVar10 + 0x26) = *(sword *)(iVar10 + 0x26) + -1;
    }
  }
  return iVar5;
}
