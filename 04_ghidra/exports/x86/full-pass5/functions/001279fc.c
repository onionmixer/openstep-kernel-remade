/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001279fc */

undefined1 * _ip_optcopy(byte *param_1,int param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  size_t sVar5;
  
  puVar2 = (undefined1 *)(param_2 + 0x14);
  sVar5 = (*param_1 & 0xf) * 4 - 0x14;
  for (param_1 = param_1 + 0x14; (0 < (int)sVar5 && (bVar1 = *param_1, bVar1 != 0));
      param_1 = param_1 + uVar3) {
    if (bVar1 == 1) {
      uVar3 = 1;
    }
    else {
      uVar3 = (uint)param_1[1];
    }
    if ((int)sVar5 < (int)uVar3) {
      uVar3 = sVar5;
    }
    if ((char)bVar1 < '\0') {
      _bcopy(param_1,puVar2,uVar3);
      puVar2 = puVar2 + uVar3;
    }
    sVar5 = sVar5 - uVar3;
  }
  for (puVar4 = puVar2 + (-0x14 - param_2); ((uint)puVar4 & 3) != 0; puVar4 = puVar4 + 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return puVar4;
}

