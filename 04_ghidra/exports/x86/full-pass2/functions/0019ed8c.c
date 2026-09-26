/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019ed8c */

void _VBEModeInfo2IODisplayInfo(ushort *param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  
  *param_2 = (uint)param_1[2];
  param_2[1] = (uint)param_1[3];
  param_2[2] = (uint)param_1[2];
  param_2[3] = (uint)param_1[4];
  param_2[4] = 0;
  param_2[5] = *(uint *)(param_1 + 10);
  switch((char)param_1[5]) {
  case '\x02':
    param_2[6] = 0;
    break;
  default:
    *(byte *)(param_2 + 0x20) = (byte)param_2[0x20] | 0x10;
    return;
  case '\b':
    param_2[6] = 1;
    break;
  case '\f':
    param_2[6] = 2;
    break;
  case '\x0f':
  case '\x10':
    param_2[6] = 3;
    break;
  case '\x18':
  case ' ':
    param_2[6] = 4;
  }
  if ((param_1[1] & 8) == 0) {
    param_2[7] = 1;
    iVar3 = 0;
    if ((char)param_1[5] != '\0') {
      do {
        *(undefined1 *)(iVar3 + 0x20 + (int)param_2) = 0x57;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)(byte)param_1[5]);
    }
  }
  else {
    param_2[7] = 2;
    if (*(char *)((int)param_1 + 0xb) == '\x04') {
      iVar3 = 0;
      if ((char)param_1[5] != '\0') {
        do {
          *(undefined1 *)(iVar3 + 0x20 + (int)param_2) = 0x50;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)(byte)param_1[5]);
      }
    }
    else {
      iVar3 = 0;
      if ((char)param_1[5] != '\0') {
        do {
          *(undefined1 *)(iVar3 + 0x20 + (int)param_2) = 0x2d;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)(byte)param_1[5]);
      }
      uVar2 = param_1[5];
      bVar1 = *(byte *)((int)param_1 + 0xd);
      iVar3 = 0;
      if ((char)param_1[6] != '\0') {
        do {
          *(undefined1 *)((((uint)(byte)uVar2 - (uint)bVar1) - iVar3) + 0x1f + (int)param_2) = 0x52;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)(byte)param_1[6]);
      }
      uVar2 = param_1[5];
      bVar1 = *(byte *)((int)param_1 + 0xf);
      iVar3 = 0;
      if ((char)param_1[7] != '\0') {
        do {
          *(undefined1 *)((((uint)(byte)uVar2 - (uint)bVar1) - iVar3) + 0x1f + (int)param_2) = 0x47;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)(byte)param_1[7]);
      }
      uVar2 = param_1[5];
      bVar1 = *(byte *)((int)param_1 + 0x11);
      iVar3 = 0;
      if ((char)param_1[8] != '\0') {
        do {
          *(undefined1 *)((((uint)(byte)uVar2 - (uint)bVar1) - iVar3) + 0x1f + (int)param_2) = 0x42;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)(byte)param_1[8]);
      }
    }
  }
  param_2[0x18] = 2;
  param_2[0x19] = (uint)*param_1;
  param_2[0x1a] = (uint)param_1[3] * (uint)param_1[4];
  return;
}

