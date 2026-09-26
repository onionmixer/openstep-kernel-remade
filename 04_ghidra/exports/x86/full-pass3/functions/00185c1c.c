/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185c1c */

undefined4
_kdp_machine_read_regs(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = DAT_001f66ac;
  if (param_2 == -2) {
    puVar4 = &DAT_001d1434;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *param_3 = *puVar4;
      puVar4 = puVar4 + 1;
      param_3 = param_3 + 1;
    }
    *param_4 = 0x6c;
    uVar2 = 0;
  }
  else if (param_2 == -1) {
    puVar4 = &DAT_001d13f4;
    puVar5 = param_3;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *param_3 = *(undefined4 *)(puVar1 + 0x16);
    param_3[1] = *(undefined4 *)(puVar1 + 0x10);
    param_3[2] = *(undefined4 *)(puVar1 + 0x14);
    param_3[3] = *(undefined4 *)(puVar1 + 0x12);
    param_3[4] = *(undefined4 *)(puVar1 + 8);
    param_3[5] = *(undefined4 *)(puVar1 + 10);
    param_3[6] = *(undefined4 *)(puVar1 + 0xc);
    param_3[7] = puVar1 + 0x22;
    param_3[8] = (uint)puVar1[0x24];
    param_3[9] = *(undefined4 *)(puVar1 + 0x20);
    param_3[10] = *(undefined4 *)(puVar1 + 0x1c);
    param_3[0xb] = (uint)puVar1[0x1e];
    param_3[0xc] = (uint)puVar1[6];
    param_3[0xd] = (uint)puVar1[4];
    param_3[0xe] = (uint)puVar1[2];
    param_3[0xf] = (uint)*puVar1;
    *param_4 = 0x40;
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

