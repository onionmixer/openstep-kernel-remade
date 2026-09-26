/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d37c */

void _switch_context(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_3 + 0x28);
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  if (*(int *)(param_3 + 0xc) != *(int *)(param_1 + 0xc)) {
    *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0xc) + 0x24) + 0x18) = 0;
    *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_3 + 0xc) + 0xc) + 0x24) + 0x18) = 1;
  }
  puVar3 = _gdt;
  _active_threads = param_3;
  _active_stacks = *(undefined4 *)(param_3 + 0x2c);
  _stack_pointers = *(int *)(param_3 + 0x2c) + 0xff4;
  iVar6 = piVar1[0x1d];
  if ((puVar2[0x1d] != iVar6) || (piVar1[0x1e] != puVar2[0x1e])) {
    iVar4 = piVar1[0x1e];
    *(short *)(_gdt + 0x22) = (short)iVar6;
    puVar3[0x24] = (char)((uint)iVar6 >> 0x10);
    puVar3[0x27] = (char)((uint)iVar6 >> 0x18);
    puVar3[0x25] = puVar3[0x25] & 0xe0 | 0x82;
    puVar3[0x26] = puVar3[0x26] & 0x7f;
    *(short *)(puVar3 + 0x20) = (short)(iVar4 + -1);
    puVar3[0x26] = puVar3[0x26] & 0xf0 | (byte)((uint)(iVar4 + -1) >> 0x10) & 0xf;
    LocalDescriptorTableRegister(0x20);
  }
  puVar3 = _gdt;
  iVar4 = *piVar1 + -0x40000000;
  iVar6 = piVar1[1];
  *(short *)(_gdt + 0x1a) = (short)iVar4;
  puVar3[0x1c] = (char)((uint)iVar4 >> 0x10);
  puVar3[0x1f] = (char)((uint)iVar4 >> 0x18);
  puVar3[0x1d] = 0x89;
  puVar3[0x1e] = puVar3[0x1e] & 0x7f;
  *(short *)(puVar3 + 0x18) = (short)(iVar6 + -1);
  puVar3[0x1e] = puVar3[0x1e] & 0xf0 | (byte)((uint)(iVar6 + -1) >> 0x10) & 0xf;
  TaskRegister(0x18);
  *(int *)(param_1 + 0x34) = param_2;
  if (param_2 == 0) {
    iVar6 = *piVar1;
    uVar5 = *puVar2;
  }
  else {
    iVar6 = *piVar1;
    uVar5 = 0;
  }
  __switch_tss(uVar5,iVar6,param_1);
  return;
}

