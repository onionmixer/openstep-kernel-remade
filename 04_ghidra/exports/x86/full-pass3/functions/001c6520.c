/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6520 */

void FUN_001c6520(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined *puVar4;
  
  sVar2 = (short)param_4[7] - (short)param_4[*param_4 + 0xe];
  sVar3 = *(short *)((int)param_4 + 0x1e) - (short)((uint)param_4[*param_4 + 0xe] >> 0x10);
  cVar1 = '\0';
  if ((((sVar2 < *(short *)((int)param_4 + 0x16)) && ((short)param_4[5] < (short)(sVar2 + 0x10))) &&
      (sVar3 < *(short *)((int)param_4 + 0x1a))) && ((short)param_4[6] < (short)(sVar3 + 0x10))) {
    cVar1 = '\x01';
  }
  if (cVar1 != *(char *)((int)param_4 + 0xb)) {
    *(char *)((int)param_4 + 0xb) = cVar1;
    puVar4 = PTR_s__sysShowCursor_shmem__001f95a4;
    if (cVar1 != '\0') {
      puVar4 = PTR_s__sysHideCursor_shmem__001f95a8;
    }
    _objc_msgSend(param_1,puVar4,param_3,param_4);
  }
  return;
}

