/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015dc34 */

undefined4 _receive_ip_datagram(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  void *pvVar9;
  undefined4 *puVar10;
  byte *local_24;
  int local_8;
  
  iVar2 = *param_1;
  local_24 = (byte *)(iVar2 + *(int *)(iVar2 + 4));
  if (5 < (*local_24 & 0xf)) {
    _ip_stripoptions(local_24);
  }
  if ((0x7c < *(uint *)(iVar2 + 4)) || (*(ushort *)(iVar2 + 8) < 0x18)) {
    iVar2 = _m_pullup(iVar2);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      return 1;
    }
    local_24 = (byte *)(iVar2 + *(int *)(iVar2 + 4));
  }
  puVar7 = &stack0xffffffcc;
  uVar3 = local_24[9] & 0xf;
  puVar10 = (undefined4 *)(&DAT_001f6404)[uVar3 * 2];
  puVar8 = (undefined4 *)(&DAT_001f6404)[uVar3 * 2];
  do {
    puVar1 = puVar10;
    if (puVar1 == (undefined4 *)0x0) {
      local_8 = 0;
LAB_0015dd40:
      if (local_8 == 0) {
        uVar4 = 0;
      }
      else {
        _spl0();
        iVar5 = _zget();
        if (iVar5 == 0) {
          puVar7 = &stack0xffffffc8;
          _m_freem();
        }
        else {
          *(undefined4 *)(iVar5 + 8) = 0xfffffffd;
          *(undefined4 *)(iVar5 + 0xc) = 0;
          *(undefined4 *)(iVar5 + 0x10) = 0;
          *(ushort *)(local_24 + 2) = *(short *)(local_24 + 2) + (*local_24 & 0xf) * 4;
          *(short *)(local_24 + 6) = *(short *)(local_24 + 6) >> 3;
          pvVar9 = (void *)(iVar5 + 0x2c);
          for (local_24 = (byte *)0x7d4; (iVar2 != 0 && (0 < (int)local_24));
              local_24 = (byte *)((int)local_24 - sVar6)) {
            sVar6 = (int)*(short *)(iVar2 + 8);
            if ((int)local_24 < (int)*(short *)(iVar2 + 8)) {
              sVar6 = (size_t)local_24;
            }
            _bcopy((void *)(iVar2 + *(int *)(iVar2 + 4)),pvVar9,sVar6);
            pvVar9 = (void *)((int)pvVar9 + sVar6);
            iVar2 = _m_free(iVar2);
          }
          *(byte **)(iVar5 + 0x10) = local_24;
          *(uint *)(iVar5 + 0x10) = ((uint)local_24 & 0xfffffffc) - *(int *)(iVar5 + 0x10);
          puVar8 = &DAT_001e5bac;
          puVar10 = (undefined4 *)(iVar5 + 0x14);
          for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) - ((uint)local_24 & 0xfffffffc);
          *(int *)(iVar5 + 0x1c) = local_8;
          _ipc_object_reference();
          _ipc_mqueue_send(iVar5,0x10000,0);
        }
        *(undefined4 *)(puVar7 + -4) = 0x15de59;
        _splnet();
        uVar4 = 1;
      }
      return uVar4;
    }
    if (((((*(short *)((int)puVar1 + 0xe) == 0) ||
          (*(short *)(local_24 + 0x16) == *(short *)((int)puVar1 + 0xe))) &&
         ((*(short *)(puVar1 + 3) == 0 || (*(short *)(local_24 + 0x14) == *(short *)(puVar1 + 3)))))
        && ((puVar1[1] == 0 || (*(int *)(local_24 + 0xc) == puVar1[1])))) &&
       ((puVar1[2] == 0 || (*(int *)(local_24 + 0x10) == puVar1[2])))) {
      if ((undefined4 *)(&DAT_001f6404)[uVar3 * 2] != puVar1) {
        *puVar8 = *puVar1;
        *puVar1 = (&DAT_001f6404)[uVar3 * 2];
        (&DAT_001f6404)[uVar3 * 2] = puVar1;
      }
      local_8 = puVar1[4];
      goto LAB_0015dd40;
    }
    puVar10 = (undefined4 *)*puVar1;
    puVar8 = puVar1;
  } while( true );
}

