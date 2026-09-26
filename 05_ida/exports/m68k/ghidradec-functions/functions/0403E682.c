
undefined4 _ipc_kmsg_copyin_compat(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  bool bVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  uint uStack_48;
  int iStack_34;
  byte *pbStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_1c = *(undefined4 *)(param_1 + 0x14);
  uStack_18 = *(undefined4 *)(param_1 + 0x18);
  uStack_14 = *(undefined4 *)(param_1 + 0x1c);
  iVar8 = *(int *)(param_1 + 0x20);
  uStack_c = *(undefined4 *)(param_1 + 0x24);
  uStack_8 = *(undefined4 *)(param_1 + 0x28);
  iStack_10 = iVar8;
  iVar6 = _ipc_object_copyin_header(param_2,uStack_c,&uStack_20,&uStack_24);
  if (iVar6 == 0) {
    if (iVar8 == 0) {
      uStack_28 = 0;
      iStack_2c = 0;
    }
    else {
      iVar8 = _ipc_object_copyin_header(param_2,iVar8,&uStack_28,&iStack_2c);
      if (iVar8 != 0) {
        _ipc_object_destroy(uStack_20,uStack_24);
        return 0x10000009;
      }
    }
    *(uint *)(param_1 + 0x14) = uStack_24 | iStack_2c << 8;
    *(undefined4 *)(param_1 + 0x18) = uStack_18;
    *(undefined4 *)(param_1 + 0x1c) = uStack_20;
    *(undefined4 *)(param_1 + 0x20) = uStack_28;
    *(undefined4 *)(param_1 + 0x24) = uStack_14;
    *(undefined4 *)(param_1 + 0x28) = uStack_8;
    if ((char)uStack_1c == '\0') {
      bVar4 = false;
      pbVar2 = (byte *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      pbVar14 = (byte *)(param_1 + 0x2c);
      while (pbVar5 = pbVar14, pbVar5 < pbVar2) {
        if ((uint)((int)pbVar2 - (int)pbVar5) < 4) {
loc_403E7EC:
          _ipc_kmsg_clean_partial(param_1,pbVar5,0,0);
          return 0x10000008;
        }
        bVar9 = pbVar5[3] >> 2;
        if (((bVar9 & 1) != 0) && ((uint)((int)pbVar2 - (int)pbVar5) < 0xc)) goto loc_403E7EC;
        bVar1 = pbVar5[3];
        uVar3 = (bVar1 & 3) >> 1;
        if ((bVar9 & 1) == 0) {
          uVar11 = (uint)*pbVar5;
          uVar10 = (uint)pbVar5[1];
          uStack_48 = *(uint *)(pbVar5 + 2) >> 0x14;
          pbVar13 = pbVar5 + 4;
        }
        else {
          uVar11 = (uint)*(word *)(pbVar5 + 4);
          uVar10 = (uint)*(word *)(pbVar5 + 6);
          uStack_48 = *(uint *)(pbVar5 + 8);
          pbVar13 = pbVar5 + 0xc;
        }
        bVar15 = 1 < uVar11 - 5;
        if ((!bVar15) && (uVar10 != 0x20)) {
          _ipc_kmsg_clean_partial(param_1,pbVar5,0,0);
          return 0x1000000f;
        }
        pbVar5[3] = pbVar5[3] & 0xfe;
        if ((bVar9 & 1) != 0) {
          *pbVar5 = 0;
          pbVar5[1] = 0;
          *(word *)(pbVar5 + 2) = *(word *)(pbVar5 + 2) & 0xf;
        }
        uVar10 = uVar10 * uStack_48 + 7 >> 3;
        if ((int)((uint)bVar1 << 0x1c) < 0) {
          uVar10 = uVar10 + 3 & 0xfffffffc;
          if ((uint)((int)pbVar2 - (int)pbVar13) < uVar10) goto loc_403E7EC;
          pbVar14 = pbVar13 + uVar10;
          pbVar12 = pbVar13;
        }
        else {
          if ((uint)((int)pbVar2 - (int)pbVar13) < 4) goto loc_403E7EC;
          iVar8 = *(int *)pbVar13;
          if (uVar10 == 0) {
            pbVar12 = (byte *)0x0;
          }
          else if (bVar15) {
            iVar8 = _vm_move(param_3,iVar8,_ipc_soft_map,uVar10,uVar3,&pbStack_30);
            pbVar12 = pbStack_30;
            if (iVar8 != 0) goto loc_403E930;
          }
          else {
            pbVar12 = (byte *)_kalloc(uVar10);
            if (pbVar12 == (byte *)0x0) {
loc_403E930:
              _ipc_kmsg_clean_partial(param_1,pbVar5,0,0);
              return 0x1000000c;
            }
            iVar6 = _copyinmap(param_3,iVar8,pbVar12,uVar10);
            if ((iVar6 != 0) ||
               ((uVar3 != 0 && (iVar8 = _vm_deallocate(param_3,iVar8,uVar10), iVar8 != 0)))) {
              _kfree(pbVar12,uVar10);
              goto loc_403E930;
            }
          }
          pbVar14 = pbVar13 + 4;
          *(byte **)pbVar13 = pbVar12;
          bVar4 = true;
        }
        if (!bVar15) {
          iVar8 = _ipc_object_copyin_type(uVar11);
          if ((bVar9 & 1) == 0) {
            *pbVar5 = (byte)iVar8;
          }
          else {
            *(sword *)(pbVar5 + 4) = (sword)iVar8;
          }
          uVar10 = 0;
          if (uStack_48 != 0) {
            do {
              iVar6 = *(int *)pbVar12;
              if ((iVar6 != 0) && (iVar6 != -1)) {
                iVar6 = _ipc_object_copyin_compat(param_2,iVar6,uVar11,uVar3,&iStack_34);
                if (iVar6 != 0) {
                  _ipc_kmsg_clean_partial(param_1,pbVar5,1,uVar10);
                  return 0x1000000a;
                }
                if ((iVar8 == 0x10) &&
                   (iVar6 = _ipc_port_check_circularity(iStack_34,uStack_20), iVar6 != 0)) {
                  *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
                }
                *(int *)pbVar12 = iStack_34;
              }
              pbVar12 = pbVar12 + 4;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uStack_48);
          }
          bVar4 = true;
        }
      }
      if (bVar4) {
        *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x80;
      }
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0x10000003;
  }
  return uVar7;
}
