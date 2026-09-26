/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019372c */

void _sigreturn(void)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = _active_threads;
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar6 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar6 == 0) {
    puVar5 = (undefined2 *)_thread_user_state(_active_threads);
  }
  else {
    puVar5 = (undefined2 *)(iVar6 + 0x84);
  }
  iVar6 = _copyin(*puVar1,&local_4c,0x48);
  if (iVar6 != 0) {
    return;
  }
  if ((local_20 & 0x20000) == 0) {
    if (local_18 == 0) {
      return;
    }
    if ((local_18 & 4) == 0) {
      uVar7 = local_18 >> 3 & 0x1fff;
      if (0x1f < uVar7) {
        return;
      }
      if (((byte)local_18 & 3) != 3) {
        return;
      }
      if ((_gdt[uVar7 * 8 + 5] & 0x60) != 0x60) {
        return;
      }
    }
    else if (((byte)local_18 & 3) != 3) {
      return;
    }
    if ((local_14 != 0) && ((local_14 & 4) == 0)) {
      uVar7 = local_14 >> 3 & 0x1fff;
      bVar3 = false;
      if ((uVar7 < 0x20) && ((_gdt[uVar7 * 8 + 5] & 0x60) == 0x60)) {
        bVar3 = true;
      }
      if (!bVar3) {
        return;
      }
    }
    if ((local_10 != 0) && ((local_10 & 4) == 0)) {
      uVar7 = local_10 >> 3 & 0x1fff;
      bVar3 = false;
      if ((uVar7 < 0x20) && ((_gdt[uVar7 * 8 + 5] & 0x60) == 0x60)) {
        bVar3 = true;
      }
      if (!bVar3) {
        return;
      }
    }
    if ((local_c != 0) && ((local_c & 4) == 0)) {
      uVar7 = local_c >> 3 & 0x1fff;
      bVar3 = false;
      if ((uVar7 < 0x20) && ((_gdt[uVar7 * 8 + 5] & 0x60) == 0x60)) {
        bVar3 = true;
      }
      if (!bVar3) {
        return;
      }
    }
    if ((local_8 != 0) && ((local_8 & 4) == 0)) {
      uVar7 = local_8 >> 3 & 0x1fff;
      bVar3 = false;
      if ((uVar7 < 0x20) && ((_gdt[uVar7 * 8 + 5] & 0x60) == 0x60)) {
        bVar3 = true;
      }
      if (!bVar3) {
        return;
      }
    }
    if (local_24 == 0) {
      return;
    }
    if ((local_24 & 4) == 0) {
      uVar7 = local_24 >> 3 & 0x1fff;
      if (0x1f < uVar7) {
        return;
      }
      if (((byte)local_24 & 3) != 3) {
        return;
      }
      if ((_gdt[uVar7 * 8 + 5] & 0x60) != 0x60) {
        return;
      }
    }
    else if (((byte)local_24 & 3) != 3) {
      return;
    }
  }
  *(undefined1 *)(DAT_001e875c + 0x69) = 1;
  _active_u[0x53] = local_4c & 1;
  *(uint *)(*_active_u + 0x1c) = local_48 & 0xfffafeff;
  *(undefined4 *)(puVar5 + 0x16) = local_44;
  *(undefined4 *)(puVar5 + 0x10) = local_40;
  *(undefined4 *)(puVar5 + 0x14) = local_3c;
  *(undefined4 *)(puVar5 + 0x12) = local_38;
  *(undefined4 *)(puVar5 + 8) = local_34;
  *(undefined4 *)(puVar5 + 10) = local_30;
  *(undefined4 *)(puVar5 + 0xc) = local_2c;
  *(undefined4 *)(puVar5 + 0x22) = local_28;
  puVar5[0x24] = (undefined2)local_24;
  *(uint *)(puVar5 + 0x20) = local_20;
  *(uint *)(puVar5 + 0x20) = local_20 & 0x50fd7 | 0x202;
  *(undefined4 *)(puVar5 + 0x1c) = local_1c;
  puVar5[0x1e] = (undefined2)local_18;
  if ((local_20 & 0x20000) == 0) {
    puVar5[6] = (undefined2)local_14;
    puVar5[4] = (undefined2)local_10;
    puVar5[2] = (undefined2)local_c;
    *puVar5 = (undefined2)local_8;
  }
  else {
    puVar5[6] = 0;
    puVar5[4] = 0;
    puVar5[2] = 0;
    *puVar5 = 0;
    puVar5[0x28] = (undefined2)local_14;
    puVar5[0x26] = (undefined2)local_10;
    puVar5[0x2a] = (undefined2)local_c;
    puVar5[0x2c] = (undefined2)local_8;
    *(uint *)(puVar5 + 0x20) = *(uint *)(puVar5 + 0x20) | 0x20000;
  }
  if ((local_4c & 2) != 0) {
    piVar2 = *(int **)(*(int *)(iVar4 + 0x28) + 0xec);
    iVar6 = 0;
    if (piVar2 != (int *)0x0) {
      iVar6 = *piVar2;
    }
    if ((iVar6 == 0) || (7 < *(uint *)(iVar6 + 0x84))) {
      iVar6 = 0;
    }
    else {
      iVar6 = iVar6 + 0x88 + *(uint *)(iVar6 + 0x84) * 0x84;
    }
    if (iVar6 != 0) {
      *(undefined4 *)(iVar6 + 0x48) = 1;
    }
  }
  return;
}

