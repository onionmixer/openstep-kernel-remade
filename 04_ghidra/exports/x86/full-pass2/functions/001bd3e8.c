/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bd3e8 */

void _get_partition(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[1];
  param_2[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(ushort *)(param_2 + 2) = (ushort)param_1[2] >> 8 | (ushort)param_1[2] << 8;
  *(ushort *)((int)param_2 + 10) =
       *(ushort *)((int)param_1 + 10) >> 8 | *(ushort *)((int)param_1 + 10) << 8;
  *(char *)(param_2 + 3) = (char)param_1[3];
  *(ushort *)((int)param_2 + 0xe) =
       *(ushort *)((int)param_1 + 0xe) >> 8 | *(ushort *)((int)param_1 + 0xe) << 8;
  *(ushort *)(param_2 + 4) = (ushort)param_1[4] >> 8 | (ushort)param_1[4] << 8;
  *(undefined1 *)((int)param_2 + 0x12) = *(undefined1 *)((int)param_1 + 0x12);
  *(undefined1 *)((int)param_2 + 0x13) = *(undefined1 *)((int)param_1 + 0x13);
  _bcopy(param_1 + 5,param_2 + 5,0x10);
  *(char *)(param_2 + 9) = (char)param_1[9];
  _bcopy((void *)((int)param_1 + 0x25),(void *)((int)param_2 + 0x25),8);
  return;
}

