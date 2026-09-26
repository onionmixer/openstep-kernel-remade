/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001925a0 */

void _machdep_call(int param_1)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined1 *puVar9;
  int iVar10;
  int aiStack_38 [2];
  undefined1 auStack_30 [4];
  int iStack_2c;
  
  bVar1 = *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0);
  if ((bVar1 & 1) != 0) {
    *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0) = bVar1 & 0xfe;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  if ((iVar2 < 0) || (_machdep_call_count <= iVar2)) {
    iStack_2c = 0x1925f0;
    uVar6 = _kern_invalid();
    *(undefined4 *)(param_1 + 0x2c) = uVar6;
    iStack_2c = 0x1925fb;
    _thread_exception_return();
  }
  iVar10 = *(int *)(&DAT_001e2428 + iVar2 * 8);
  if (iVar10 < 1) {
    iStack_2c = 0x192680;
    uVar6 = (*(code *)(&_machdep_call_table)[iVar2 * 2])();
    *(undefined4 *)(param_1 + 0x2c) = uVar6;
  }
  else {
    iVar4 = iVar10 * -4;
    (&iStack_2c)[-iVar10] = iVar10 * 4;
    *(undefined1 **)(auStack_30 + iVar4) = &stack0xffffffd8 + iVar4;
    aiStack_38[1 - iVar10] = *(int *)(param_1 + 0x44) + 4;
    aiStack_38[-iVar10] = 0x192638;
    iVar7 = _copyin();
    if (iVar7 != 0) {
      *(undefined4 *)(param_1 + 0x2c) = 1;
      (&iStack_2c)[-iVar10] = 0x19264e;
      _thread_exception_return();
    }
    piVar8 = &iStack_2c;
    puVar5 = &stack0xffffffd8 + iVar4;
    do {
      puVar9 = puVar5;
      *(int *)(puVar9 + -4) = *piVar8;
      piVar8 = piVar8 + -1;
      iVar10 = iVar10 + -1;
      puVar5 = puVar9 + -4;
    } while (iVar10 != 0);
    pcVar3 = (code *)(&_machdep_call_table)[iVar2 * 2];
    *(undefined4 *)(puVar9 + -8) = 0x192668;
    uVar6 = (*pcVar3)();
    *(undefined4 *)(param_1 + 0x2c) = uVar6;
  }
  iStack_2c = 0x19268b;
  _thread_exception_return();
  return;
}

