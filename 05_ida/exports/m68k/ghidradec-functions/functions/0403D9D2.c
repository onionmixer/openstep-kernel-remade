
int _ipc_kmsg_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  bool bVar4;
  uint *puVar5;
  int iVar6;
  byte bVar9;
  uint *puVar7;
  int iVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  bool bVar16;
  uint uStack_c;
  uint *puStack_8;
  
  iVar6 = _ipc_kmsg_copyin_header((int *)(param_1 + 0x14),param_2,param_4);
  if (iVar6 == 0) {
    if (*(int *)(param_1 + 0x14) < 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      bVar4 = false;
      puVar3 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      puVar15 = (uint *)(param_1 + 0x2c);
      while (puVar5 = puVar15, puVar5 < puVar3) {
        if ((uint)((int)puVar3 - (int)puVar5) < 4) {
loc_403DA92:
          _ipc_kmsg_clean_partial(param_1,puVar5,0,0);
          return 0x10000008;
        }
        bVar9 = (byte)*puVar5 >> 2;
        if (((bVar9 & 1) != 0) && ((uint)((int)puVar3 - (int)puVar5) < 0xc)) goto loc_403DA92;
        iVar6 = (uint)(byte)*puVar5 << 0x1c;
        uVar10 = ((byte)*puVar5 & 3) >> 1;
        if ((bVar9 & 1) == 0) {
          uVar12 = (uint)*(byte *)puVar5;
          uVar11 = (uint)*(byte *)((int)puVar5 + 1);
          uVar13 = *(uint *)((int)puVar5 + 2) >> 0x14;
          puVar14 = puVar5 + 1;
        }
        else {
          uVar12 = (uint)*(word *)(puVar5 + 1);
          uVar11 = (uint)*(word *)((int)puVar5 + 6);
          uVar13 = puVar5[2];
          puVar14 = puVar5 + 3;
        }
        bVar16 = 5 < uVar12 - 0x10;
        if (((((!bVar16) && (uVar11 != 0x20)) ||
             (((bVar9 & 1) != 0 && ((*puVar5 & 0xfffffff0) != 0)))) || ((*puVar5 & 1) != 0)) ||
           ((uVar10 != 0 && (iVar6 < 0)))) {
          _ipc_kmsg_clean_partial(param_1,puVar5,0,0);
          return 0x1000000f;
        }
        uVar11 = uVar11 * uVar13 + 7 >> 3;
        if (iVar6 < 0) {
          uVar10 = uVar11 + 3 & 0xfffffffc;
          if ((uint)((int)puVar3 - (int)puVar14) < uVar10) goto loc_403DA92;
          puVar15 = (uint *)(uVar10 + (int)puVar14);
          puVar7 = puVar14;
        }
        else {
          if ((uint)((int)puVar3 - (int)puVar14) < 4) goto loc_403DA92;
          uVar1 = *puVar14;
          if (uVar11 == 0) {
            puVar7 = (uint *)0x0;
          }
          else if (bVar16) {
            iVar6 = _vm_move(param_3,uVar1,_ipc_soft_map,uVar11,uVar10,&puStack_8);
            puVar7 = puStack_8;
            if (iVar6 != 0) goto loc_403DBF2;
          }
          else {
            puVar7 = (uint *)_kalloc(uVar11);
            if (puVar7 == (uint *)0x0) {
loc_403DBF2:
              _ipc_kmsg_clean_partial(param_1,puVar5,0,0);
              return 0x1000000c;
            }
            iVar6 = _copyinmap(param_3,uVar1,puVar7,uVar11);
            if ((iVar6 != 0) ||
               ((uVar10 != 0 && (iVar6 = _vm_deallocate(param_3,uVar1,uVar11), iVar6 != 0)))) {
              _kfree(puVar7,uVar11);
              goto loc_403DBF2;
            }
          }
          puVar15 = puVar14 + 1;
          *puVar14 = (uint)puVar7;
          bVar4 = true;
        }
        if (!bVar16) {
          iVar6 = _ipc_object_copyin_type(uVar12);
          if ((bVar9 & 1) == 0) {
            *(char *)puVar5 = (char)iVar6;
          }
          else {
            *(sword *)(puVar5 + 1) = (sword)iVar6;
          }
          uVar10 = 0;
          if (uVar13 != 0) {
            do {
              uVar11 = *puVar7;
              if ((uVar11 != 0) && (uVar11 != 0xffffffff)) {
                iVar8 = _ipc_object_copyin(param_2,uVar11,uVar12,&uStack_c);
                if (iVar8 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar5,1,uVar10);
                  return 0x1000000a;
                }
                if ((iVar6 == 0x10) &&
                   (iVar8 = _ipc_port_check_circularity(uStack_c,uVar2), iVar8 != 0)) {
                  *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
                }
                *puVar7 = uStack_c;
              }
              puVar7 = puVar7 + 1;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar13);
          }
          bVar4 = true;
        }
      }
      if (!bVar4) {
        *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0x7f;
      }
    }
    iVar6 = 0;
  }
  return iVar6;
}
