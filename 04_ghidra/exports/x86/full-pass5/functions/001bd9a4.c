/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bd9a4 */

void _put_disk_label(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  uVar1 = *param_1;
  *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[1];
  param_2[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[2];
  param_2[2] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  _bcopy(param_1 + 3,param_2 + 3,0x18);
  uVar1 = param_1[9];
  param_2[9] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[10];
  param_2[10] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  _put_disktab(param_1 + 0xb,param_2 + 0xb);
  puVar4 = (uint *)((int)param_2 + 0x22e);
  iVar2 = 0;
  puVar3 = param_1 + 0x90;
  do {
    uVar1 = *puVar3;
    *puVar4 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x686);
  *(ushort *)((int)param_2 + 0x1c46) = (ushort)param_1[0x716] >> 8 | (ushort)param_1[0x716] << 8;
  *(ushort *)((int)param_2 + 0x22e) = (ushort)param_1[0x90] >> 8 | (ushort)param_1[0x90] << 8;
  return;
}

