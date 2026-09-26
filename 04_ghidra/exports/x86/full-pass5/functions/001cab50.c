/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cab50 */

uint __NXAddAltHandler(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  uint *puVar5;
  
  uVar1 = _current_thread_EXTERNAL();
  puVar2 = &DAT_001e551c;
  do {
    if (puVar2[4] == uVar1) goto LAB_001cab7f;
    puVar2 = (uint *)puVar2[5];
  } while (puVar2 != (uint *)0x0);
  puVar2 = (uint *)FUN_001ca960(uVar1);
LAB_001cab7f:
  if (puVar2[2] == puVar2[3]) {
    if ((undefined *)puVar2[1] == &DAT_001e545c) {
      puVar2[2] = puVar2[2] + 1;
      pvVar3 = _malloc(puVar2[2] * 0xc);
      puVar2[1] = (uint)pvVar3;
      _bcopy(&DAT_001e545c,pvVar3,0xc0);
    }
    else {
      puVar2[2] = puVar2[2] + 1;
      pvVar3 = _realloc((void *)puVar2[1],puVar2[2] * 0xc);
      puVar2[1] = (uint)pvVar3;
    }
  }
  puVar5 = (uint *)(puVar2[3] * 0xc + puVar2[1]);
  puVar2[3] = puVar2[3] + 1;
  *puVar5 = *puVar2;
  iVar4 = ((int)puVar5 - puVar2[1]) * -0x55555555;
  *puVar2 = CONCAT31((int3)(iVar4 >> 9),(char)(iVar4 >> 1)) | 1;
  puVar5[1] = param_1;
  puVar5[2] = param_2;
  return *puVar2;
}

