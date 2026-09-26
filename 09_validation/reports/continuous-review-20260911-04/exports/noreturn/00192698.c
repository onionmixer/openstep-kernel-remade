
/* WARNING: Type propagation algorithm not settling */

void _mach_kernel_trap(int param_1)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined1 *puVar9;
  int iVar10;
  int aiStack_38 [4];
  
  bVar1 = *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0);
  if ((bVar1 & 1) != 0) {
    *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0) = bVar1 & 0xfe;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  if ((-1 < -iVar2) && (-iVar2 < _mach_trap_count)) {
    iVar10 = *(int *)(&_mach_trap_table + iVar2 * -0x10);
    if (iVar10 < 1) {
      aiStack_38[3] = 0x192778;
      uVar5 = (*(code *)(&PTR__kern_invalid_001df730)[iVar2 * -4])();
      *(undefined4 *)(param_1 + 0x2c) = uVar5;
    }
    else {
      aiStack_38[3 - iVar10] = iVar10 * 4;
      aiStack_38[2 - iVar10] = (int)(&stack0xffffffd8 + iVar10 * -4);
      aiStack_38[1 - iVar10] = *(int *)(param_1 + 0x44) + 4;
      aiStack_38[-iVar10] = 0x192731;
      iVar6 = _copyin();
      piVar8 = (int *)(&stack0xffffffd8 + iVar10 * -4);
      if (iVar6 != 0) {
        aiStack_38[3 - iVar10] = *(int *)(param_1 + 0x44) + 4;
        aiStack_38[2 - iVar10] = 1;
        piVar8 = aiStack_38 + (1 - iVar10);
        aiStack_38[1 - iVar10] = 1;
        aiStack_38[-iVar10] = 0x192748;
        _exception();
      }
      piVar7 = aiStack_38 + 3;
      puVar4 = (undefined1 *)piVar8;
      do {
        puVar9 = puVar4;
        *(int *)(puVar9 + -4) = *piVar7;
        piVar7 = piVar7 + -1;
        iVar10 = iVar10 + -1;
        puVar4 = puVar9 + -4;
      } while (iVar10 != 0);
      pcVar3 = (code *)(&PTR__kern_invalid_001df730)[iVar2 * -4];
      *(undefined4 *)(puVar9 + -8) = 0x192763;
      uVar5 = (*pcVar3)();
      *(undefined4 *)(param_1 + 0x2c) = uVar5;
    }
    aiStack_38[3] = 0x192783;
                    /* WARNING: Subroutine does not return */
    _thread_exception_return();
  }
  aiStack_38[3] = 0x1926e8;
  uVar5 = _kern_invalid();
  *(undefined4 *)(param_1 + 0x2c) = uVar5;
                    /* WARNING: Subroutine does not return */
  aiStack_38[3] = 0x1926f3;
  _thread_exception_return();
}

