/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121db0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _rtrequest(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint local_24;
  undefined4 local_1c;
  undefined4 *local_10;
  uint local_c;
  uint local_8;
  
  puVar8 = (uint *)0x0;
  local_1c = 0;
  uVar6 = (uint)*(ushort *)(param_2 + 4);
  if (0x10 < uVar6) {
    return 0x2f;
  }
  (*(code *)(&_afswitch)[uVar6 * 2])(param_2 + 4,&local_c);
  if ((*(byte *)(param_2 + 0x24) & 4) == 0) {
    local_24 = local_8;
    puVar2 = (undefined4 *)(&_rtnet + (local_8 & 7) * 4);
  }
  else {
    local_24 = local_c;
    puVar2 = (undefined4 *)(&_rthost + (local_c & 7) * 4);
  }
  pcVar1 = (code *)(&PTR__null_netmatch_001db794)[uVar6 * 2];
  uVar3 = _splimp();
  puVar5 = (undefined4 *)*puVar2;
  local_10 = puVar2;
  if (puVar5 != (undefined4 *)0x0) {
    do {
      puVar7 = puVar5;
      puVar8 = (uint *)((int)puVar7 + puVar7[1]);
      if (*puVar8 == local_24) {
        if ((*(byte *)(param_2 + 0x24) & 4) == 0) {
          if (((short)puVar8[1] == *(short *)(param_2 + 4)) &&
             (iVar4 = (*pcVar1)(puVar8 + 1,(void *)(param_2 + 4)), iVar4 != 0)) {
LAB_00121e8f:
            iVar4 = _bcmp(puVar8 + 5,(void *)(param_2 + 0x14),0x10);
            puVar5 = puVar7;
            if (iVar4 == 0) break;
          }
        }
        else {
          iVar4 = _bcmp(puVar8 + 1,(void *)(param_2 + 4),0x10);
          if (iVar4 == 0) goto LAB_00121e8f;
        }
      }
      puVar5 = (undefined4 *)*puVar7;
      local_10 = puVar7;
    } while (puVar5 != (undefined4 *)0x0);
  }
  if (param_1 != -0x7fcf8df6) {
    if (param_1 == -0x7fcf8df5) {
      if (puVar5 == (undefined4 *)0x0) {
        local_1c = 3;
      }
      else {
        *local_10 = *puVar5;
        if (*(short *)((int)puVar8 + 0x26) < 1) {
          _m_free(puVar5);
        }
        else {
          *(byte *)(puVar8 + 9) = (byte)puVar8[9] & 0xfe;
          __rttrash = __rttrash + 1;
          *puVar5 = 0;
        }
      }
    }
    goto LAB_00122037;
  }
  if (puVar5 != (undefined4 *)0x0) {
    local_1c = 0x11;
    goto LAB_00122037;
  }
  if ((*(ushort *)(param_2 + 0x24) & 2) == 0) {
    iVar4 = 0;
    if ((*(ushort *)(param_2 + 0x24) & 4) != 0) {
      iVar4 = _ifa_ifwithdstaddr(param_2 + 4);
    }
    if (iVar4 == 0) {
      iVar4 = _ifa_ifwithaddr(param_2 + 0x14);
      goto LAB_00121f5c;
    }
  }
  else {
    iVar4 = _ifa_ifwithdstaddr(param_2 + 0x14);
LAB_00121f5c:
    if ((iVar4 == 0) && (iVar4 = _ifa_ifwithnet(param_2 + 0x14), iVar4 == 0)) {
      local_1c = 0x33;
      goto LAB_00122037;
    }
  }
  puVar5 = (undefined4 *)_m_get(0,5);
  if (puVar5 == (undefined4 *)0x0) {
    local_1c = 0x37;
  }
  else {
    *puVar5 = *puVar2;
    *puVar2 = puVar5;
    puVar5[1] = 0xc;
    *(undefined2 *)(puVar5 + 2) = 0x30;
    puVar8 = (uint *)((int)puVar5 + puVar5[1]);
    *puVar8 = local_24;
    puVar8[1] = *(uint *)(param_2 + 4);
    puVar8[2] = *(uint *)(param_2 + 8);
    puVar8[3] = *(uint *)(param_2 + 0xc);
    puVar8[4] = *(uint *)(param_2 + 0x10);
    puVar8[5] = *(uint *)(param_2 + 0x14);
    puVar8[6] = *(uint *)(param_2 + 0x18);
    puVar8[7] = *(uint *)(param_2 + 0x1c);
    puVar8[8] = *(uint *)(param_2 + 0x20);
    *(ushort *)(puVar8 + 9) = *(ushort *)(param_2 + 0x24) & 0x16 | 1;
    *(undefined2 *)((int)puVar8 + 0x26) = 0;
    puVar8[10] = 0;
    puVar8[0xb] = *(uint *)(iVar4 + 0x20);
  }
LAB_00122037:
  _splx(uVar3);
  return local_1c;
}

