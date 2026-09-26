/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e728 */

undefined4 _get_thread_state(int param_1,undefined4 *param_2,uint *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  
  if (*param_3 < 0x10) {
    uVar2 = 4;
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x28) + 0x70);
    if (iVar4 == 0) {
      iVar4 = _kalloc(0xe0);
      *(int *)(*(int *)(param_1 + 0x28) + 0x70) = iVar4;
      puVar3 = (ushort *)(iVar4 + 0x84);
      puVar6 = &DAT_001d15e0;
      puVar7 = puVar3;
      for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 2;
      }
      *(undefined4 *)(iVar4 + 0xc4) = 0x200;
      *(undefined2 *)(iVar4 + 0xc0) = 99;
      *(undefined2 *)(iVar4 + 0xcc) = 0x6b;
      *(undefined2 *)(iVar4 + 0x90) = 0x6b;
      *(undefined2 *)(iVar4 + 0x8c) = 0x6b;
      *(undefined2 *)(iVar4 + 0x88) = 0;
      *(undefined2 *)(iVar4 + 0x84) = 0;
    }
    else {
      puVar3 = (ushort *)(iVar4 + 0x84);
    }
    *param_2 = *(undefined4 *)(puVar3 + 0x16);
    param_2[1] = *(undefined4 *)(puVar3 + 0x10);
    param_2[2] = *(undefined4 *)(puVar3 + 0x14);
    param_2[3] = *(undefined4 *)(puVar3 + 0x12);
    param_2[4] = *(undefined4 *)(puVar3 + 8);
    param_2[5] = *(undefined4 *)(puVar3 + 10);
    param_2[6] = *(undefined4 *)(puVar3 + 0xc);
    param_2[7] = *(undefined4 *)(puVar3 + 0x22);
    param_2[8] = (uint)puVar3[0x24];
    param_2[9] = *(undefined4 *)(puVar3 + 0x20);
    param_2[10] = *(undefined4 *)(puVar3 + 0x1c);
    param_2[0xb] = (uint)puVar3[0x1e];
    if ((puVar3[0x21] & 2) == 0) {
      param_2[0xc] = (uint)puVar3[6];
      param_2[0xd] = (uint)puVar3[4];
      param_2[0xe] = (uint)puVar3[2];
      uVar1 = *puVar3;
    }
    else {
      param_2[0xc] = (uint)puVar3[0x28];
      param_2[0xd] = (uint)puVar3[0x26];
      param_2[0xe] = (uint)puVar3[0x2a];
      uVar1 = puVar3[0x2c];
    }
    param_2[0xf] = (uint)uVar1;
    *param_3 = 0x10;
    uVar2 = 0;
  }
  return uVar2;
}

