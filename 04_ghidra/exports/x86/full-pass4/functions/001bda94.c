/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bda94 */

char * _check_label(uint *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  char *pcVar3;
  uint *puVar4;
  ushort uVar5;
  uint uVar6;
  ushort *puVar7;
  
  uVar2 = *param_1;
  uVar2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  if ((uVar2 == 0x4e655854) || (uVar2 == 0x646c5632)) {
    uVar5 = 0x1c48;
    puVar7 = (ushort *)((int)param_1 + 0x1c46);
  }
  else {
    if (uVar2 != 0x646c5633) {
      return "Bad disk label magic number";
    }
    uVar5 = 0x230;
    puVar7 = (ushort *)((int)param_1 + 0x22e);
  }
  uVar2 = param_1[1];
  if (param_2 == (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18))
  {
    param_1[1] = 0;
    uVar1 = *puVar7;
    *puVar7 = 0;
    uVar2 = (uint)(uVar5 >> 1);
    uVar6 = 0;
    puVar4 = param_1;
    while (uVar2 = uVar2 - 1, uVar2 != 0xffffffff) {
      uVar6 = uVar6 + (ushort)((ushort)*puVar4 >> 8 | (ushort)*puVar4 << 8);
      puVar4 = (uint *)((int)puVar4 + 2);
    }
    uVar2 = (uVar6 & 0xffff) + (uVar6 >> 0x10);
    if (0xffff < uVar2) {
      uVar2 = uVar2 - 0xffff;
    }
    if ((ushort)(uVar1 >> 8 | uVar1 << 8) == (ushort)uVar2) {
      param_1[1] = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
                   param_2 << 0x18;
      *puVar7 = uVar1 & 0xff | (uVar1 >> 8) << 8;
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = "Label checksum error";
    }
  }
  else {
    pcVar3 = "Label in wrong location";
  }
  return pcVar3;
}

