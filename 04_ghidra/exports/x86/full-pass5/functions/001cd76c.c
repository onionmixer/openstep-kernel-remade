/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd76c */

void FUN_001cd76c(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint local_c;
  
  uVar5 = *param_2;
  puVar4 = *(uint **)(param_1 + 0x20);
  local_c = *puVar4;
  uVar1 = (puVar4[1] + 1) * 4;
  uVar2 = local_c * 3 + 3;
  if (uVar1 < uVar2 || uVar1 - uVar2 == 0) {
    puVar4[1] = puVar4[1] + 1;
  }
  else {
    if ((*(byte *)(param_1 + 0x10) & 0x20) == 0) {
      puVar4 = (uint *)FUN_001cd5b4(param_1);
      local_c = *puVar4;
    }
    else {
      FUN_001cd7ec(param_1);
    }
    puVar4[1] = puVar4[1] + 1;
  }
  while( true ) {
    uVar5 = uVar5 & local_c;
    puVar3 = (uint *)puVar4[uVar5 + 2];
    puVar4[uVar5 + 2] = (uint)param_2;
    if (puVar3 == (uint *)0x0) break;
    uVar5 = uVar5 + 1;
    param_2 = puVar3;
  }
  return;
}

