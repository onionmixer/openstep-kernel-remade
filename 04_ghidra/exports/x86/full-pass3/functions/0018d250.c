/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d250 */

uint _stack_handoff(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  uint in_CR0;
  
  piVar1 = *(int **)(param_2 + 0x28);
  iVar2 = *(int *)(param_1 + 0x28);
  iVar5 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(int *)(param_2 + 0x2c) = iVar5;
  iVar3 = **(int **)(param_2 + 0x28);
  iVar5 = iVar5 + 0xff4;
  *(int *)(iVar3 + 0x3c) = iVar5;
  *(int *)(iVar3 + 0x38) = iVar5;
  *(code **)(iVar3 + 0x20) = __stack_attach;
  *(undefined4 *)(iVar3 + 0x34) = 0;
  if (*(int *)(param_2 + 0xc) != *(int *)(param_1 + 0xc)) {
    *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0xc) + 0x24) + 0x18) = 0;
    *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_2 + 0xc) + 0xc) + 0x24) + 0x18) = 1;
  }
  puVar4 = _gdt;
  _active_threads = param_2;
  iVar5 = piVar1[0x1d];
  if ((*(int *)(iVar2 + 0x74) != iVar5) || (piVar1[0x1e] != *(int *)(iVar2 + 0x78))) {
    iVar2 = piVar1[0x1e];
    *(short *)(_gdt + 0x22) = (short)iVar5;
    puVar4[0x24] = (char)((uint)iVar5 >> 0x10);
    puVar4[0x27] = (char)((uint)iVar5 >> 0x18);
    puVar4[0x25] = puVar4[0x25] & 0xe0 | 0x82;
    puVar4[0x26] = puVar4[0x26] & 0x7f;
    *(short *)(puVar4 + 0x20) = (short)(iVar2 + -1);
    puVar4[0x26] = puVar4[0x26] & 0xf0 | (byte)((uint)(iVar2 + -1) >> 0x10) & 0xf;
    LocalDescriptorTableRegister(0x20);
  }
  puVar4 = _gdt;
  iVar5 = *piVar1 + -0x40000000;
  iVar2 = piVar1[1];
  *(short *)(_gdt + 0x1a) = (short)iVar5;
  puVar4[0x1c] = (char)((uint)iVar5 >> 0x10);
  puVar4[0x1f] = (char)((uint)iVar5 >> 0x18);
  puVar4[0x1d] = 0x89;
  puVar4[0x1e] = puVar4[0x1e] & 0x7f;
  *(short *)(puVar4 + 0x18) = (short)(iVar2 + -1);
  puVar4[0x1e] = puVar4[0x1e] & 0xf0 | (byte)((uint)(iVar2 + -1) >> 0x10) & 0xf;
  TaskRegister(0x18);
  return in_CR0 | 8;
}

