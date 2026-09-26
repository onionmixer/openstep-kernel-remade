/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192698 */

/* WARNING: Type propagation algorithm not settling */

void _mach_kernel_trap(int param_1)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int iStack_38;
  int aiStack_34 [2];
  undefined4 uStack_2c;
  
  puVar7 = &stack0xffffffd8;
  bVar1 = *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0);
  if ((bVar1 & 1) != 0) {
    *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0) = bVar1 & 0xfe;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  if ((-iVar2 < 0) || (_mach_trap_count <= -iVar2)) {
    uStack_2c = 0x1926e8;
    uVar4 = _kern_invalid();
    *(undefined4 *)(param_1 + 0x2c) = uVar4;
    uStack_2c = 0x1926f3;
    _thread_exception_return();
  }
  iVar9 = *(int *)(&_mach_trap_table + iVar2 * -0x10);
  if (iVar9 < 1) {
    uStack_2c = 0x192778;
    uVar4 = (*(code *)(&PTR__kern_invalid_001df730)[iVar2 * -4])();
    *(undefined4 *)(param_1 + 0x2c) = uVar4;
  }
  else {
    aiStack_34[2 - iVar9] = iVar9 * 4;
    aiStack_34[1 - iVar9] = (int)(&stack0xffffffd8 + iVar9 * -4);
    aiStack_34[-iVar9] = *(int *)(param_1 + 0x44) + 4;
    (&iStack_38)[-iVar9] = 0x192731;
    iVar5 = _copyin();
    if (iVar5 != 0) {
      aiStack_34[2 - iVar9] = *(int *)(param_1 + 0x44) + 4;
      aiStack_34[1 - iVar9] = 1;
      puVar7 = (undefined1 *)aiStack_34;
      *(undefined4 *)((int)puVar7 + iVar9 * 0xfffffffcU) = 1;
      (&iStack_38)[-iVar9] = 0x192748;
      _exception();
    }
    puVar6 = aiStack_34 + 2;
    puVar7 = puVar7 + iVar9 * 0xfffffffc;
    do {
      puVar8 = puVar7;
      *(undefined4 *)(puVar8 + -4) = *puVar6;
      puVar6 = puVar6 + -1;
      iVar9 = iVar9 + -1;
      puVar7 = puVar8 + -4;
    } while (iVar9 != 0);
    pcVar3 = (code *)(&PTR__kern_invalid_001df730)[iVar2 * -4];
    *(undefined4 *)(puVar8 + -8) = 0x192763;
    uVar4 = (*pcVar3)();
    *(undefined4 *)(param_1 + 0x2c) = uVar4;
  }
  uStack_2c = 0x192783;
  _thread_exception_return();
  return;
}

