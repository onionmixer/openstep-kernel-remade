
void _ttysetspec(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = *param_1;
  uVar6 = *(uint *)(iVar2 + 0x3a);
  uVar3 = param_1[4];
  uVar5 = 0;
  do {
    *(undefined4 *)(iVar2 + 0x62 + uVar5 * 4) = 0;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  if ((uVar6 & 0x20) == 0) {
    if ((uVar3 & 0x10) != 0) {
      bVar4 = *(byte *)(iVar2 + 0x59);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x57);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if ((uVar3 & 8) != 0) {
      bVar4 = *(byte *)(iVar2 + 0x4e);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x4f);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x54);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if ((uVar3 & 0x4000000) != 0) {
      bVar4 = *(byte *)(iVar2 + 0x51);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x50);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if (((uVar6 & 0x10) != 0) || ((uVar3 & 0x3000000) != 0)) {
      *(word *)(iVar2 + 100) = *(word *)(iVar2 + 100) | 0x2000;
    }
    if ((uVar3 & 0x800000) != 0) {
      *(word *)(iVar2 + 100) = *(word *)(iVar2 + 100) | 0x400;
    }
    if ((uVar6 & 2) == 0) {
      bVar4 = *(byte *)(iVar2 + 0x4c);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x4d);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x58);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x56);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if ((uVar6 & 4) != 0) {
      uVar6 = 0;
      do {
        puVar1 = (uint *)(iVar2 + 0x62 + (uVar6 >> 5 & 7) * 4);
        *puVar1 = 1 << (uVar6 & 0x1f) | *puVar1;
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 0x80);
    }
    if ((uVar3 & 0x181000) == 0x101000) {
      *(byte *)(iVar2 + 0x7e) = *(byte *)(iVar2 + 0x7e) | 0x80;
    }
  }
  return;
}

