
void _start_initial_context(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0x28);
  _ldt_init();
  *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0xc) + 0x24) + 0x18) = 1;
  puVar3 = _gdt;
  _active_threads = param_1;
  _active_stacks = *(undefined4 *)(param_1 + 0x2c);
  _stack_pointers = *(int *)(param_1 + 0x2c) + 0xff4;
  iVar2 = piVar1[0x1d];
  iVar4 = piVar1[0x1e];
  *(short *)(_gdt + 0x22) = (short)iVar2;
  puVar3[0x24] = (char)((uint)iVar2 >> 0x10);
  puVar3[0x27] = (char)((uint)iVar2 >> 0x18);
  puVar3[0x25] = puVar3[0x25] & 0xe0 | 0x82;
  puVar3[0x26] = puVar3[0x26] & 0x7f;
  *(short *)(puVar3 + 0x20) = (short)(iVar4 + -1);
  puVar3[0x26] = puVar3[0x26] & 0xf0 | (byte)((uint)(iVar4 + -1) >> 0x10) & 0xf;
  puVar3 = _gdt;
  LocalDescriptorTableRegister(0x20);
  iVar4 = *piVar1 + -0x40000000;
  iVar2 = piVar1[1];
  *(short *)(_gdt + 0x1a) = (short)iVar4;
  puVar3[0x1c] = (char)((uint)iVar4 >> 0x10);
  puVar3[0x1f] = (char)((uint)iVar4 >> 0x18);
  puVar3[0x1d] = 0x89;
  puVar3[0x1e] = puVar3[0x1e] & 0x7f;
  *(short *)(puVar3 + 0x18) = (short)(iVar2 + -1);
  puVar3[0x1e] = puVar3[0x1e] & 0xf0 | (byte)((uint)(iVar2 + -1) >> 0x10) & 0xf;
  TaskRegister(0x18);
  __switch_tss(0,*piVar1,0);
  return;
}

