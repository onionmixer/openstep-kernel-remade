/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6460 */

void FUN_001c6460(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  short sVar2;
  
  iVar1 = param_4[*param_4 + 0xe];
  sVar2 = (short)param_4[7] - (short)iVar1;
  *(short *)(param_4 + 8) = sVar2;
  *(short *)((int)param_4 + 0x22) = sVar2 + 0x10;
  sVar2 = *(short *)((int)param_4 + 0x1e) - (short)((uint)iVar1 >> 0x10);
  *(short *)(param_4 + 9) = sVar2;
  *(short *)((int)param_4 + 0x26) = sVar2 + 0x10;
  _objc_msgSend(param_1,PTR_s__VGADisplayCursor_shmem__001f95b4,param_3,param_4);
  param_4[10] = param_4[8];
  param_4[0xb] = param_4[9];
  return;
}

