/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010daf0 */

void _ttysetspec(int *param_1)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  iVar3 = *param_1;
  uVar4 = *(uint *)(iVar3 + 0x3c);
  uVar5 = param_1[4];
  local_8 = 0;
  do {
    *(undefined4 *)(iVar3 + 100 + local_8 * 4) = 0;
    local_8 = local_8 + 1;
  } while (local_8 < 8);
  if ((uVar4 & 0x20) == 0) {
    if ((uVar5 & 0x10) != 0) {
      bVar2 = *(byte *)(iVar3 + 0x5a);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x58);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
    }
    if ((uVar5 & 8) != 0) {
      bVar2 = *(byte *)(iVar3 + 0x4f);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x50);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x55);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
    }
    if ((uVar5 & 0x4000000) != 0) {
      bVar2 = *(byte *)(iVar3 + 0x52);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x51);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
    }
    if (((uVar4 & 0x10) != 0) || ((uVar5 & 0x3000000) != 0)) {
      *(uint *)(iVar3 + 100) = *(uint *)(iVar3 + 100) | 0x2000;
    }
    if ((uVar5 & 0x800000) != 0) {
      *(uint *)(iVar3 + 100) = *(uint *)(iVar3 + 100) | 0x400;
    }
    if ((uVar4 & 2) == 0) {
      bVar2 = *(byte *)(iVar3 + 0x4d);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x4e);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x59);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
      bVar2 = *(byte *)(iVar3 + 0x57);
      if (bVar2 != 0xff) {
        puVar1 = (uint *)(iVar3 + 100 + (uint)(bVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (bVar2 & 0x1f);
      }
    }
    if ((uVar4 & 4) != 0) {
      local_8 = 0;
      do {
        puVar1 = (uint *)(iVar3 + 100 + (uint)((byte)local_8 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)local_8 & 0x1f);
        local_8 = local_8 + 1;
      } while ((int)local_8 < 0x80);
    }
    if ((undefined *)(uVar5 & 0x181000) == &DAT_00101000) {
      *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) | 0x80000000;
    }
  }
  return;
}

