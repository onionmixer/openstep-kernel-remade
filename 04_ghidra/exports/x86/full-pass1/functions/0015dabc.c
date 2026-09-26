/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015dabc */

undefined4 _find_listener(int param_1,short param_2,int param_3,short param_4,byte param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = param_5 & 0xf;
  puVar3 = (undefined4 *)(&DAT_001f6404)[uVar4 * 2];
  puVar2 = (undefined4 *)(&DAT_001f6404)[uVar4 * 2];
  while( true ) {
    puVar1 = puVar3;
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (((((*(short *)((int)puVar1 + 0xe) == 0) || (param_4 == *(short *)((int)puVar1 + 0xe))) &&
         ((*(short *)(puVar1 + 3) == 0 || (*(short *)(puVar1 + 3) == param_2)))) &&
        ((puVar1[1] == 0 || (param_1 == puVar1[1])))) &&
       ((puVar1[2] == 0 || (param_3 == puVar1[2])))) break;
    puVar3 = (undefined4 *)*puVar1;
    puVar2 = puVar1;
  }
  if ((undefined4 *)(&DAT_001f6404)[uVar4 * 2] != puVar1) {
    *puVar2 = *puVar1;
    *puVar1 = (&DAT_001f6404)[uVar4 * 2];
    (&DAT_001f6404)[uVar4 * 2] = puVar1;
  }
  return puVar1[4];
}

