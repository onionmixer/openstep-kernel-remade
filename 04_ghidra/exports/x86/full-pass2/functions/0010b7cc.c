/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b7cc */

int _ptrace(int _request,pid_t _pid,caddr_t _addr,int _data)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  task_t target_task;
  int iVar4;
  int iVar5;
  uint uVar6;
  int extraout_EAX;
  kern_return_t kVar7;
  
  piVar2 = *(int **)(DAT_001e875c + 0x24);
  if (*piVar2 < 1) {
    *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) | 0x10;
    *(undefined4 *)(*_active_u + 0x7c) = *(undefined4 *)(*_active_u + 0x44);
    iVar3 = *(int *)(*_active_u + 0x44);
    *(int *)(iVar3 + 0x80) = *_active_u;
    return iVar3;
  }
  uVar6 = _pfind(piVar2[1]);
  iVar3 = DAT_001e875c;
  if (uVar6 == 0) {
LAB_0010b829:
    *(undefined1 *)(DAT_001e875c + 0x68) = 3;
    return iVar3;
  }
  target_task = *(task_t *)(uVar6 + 0x68);
  iVar4 = *piVar2;
  if (iVar4 == 10) {
    iVar4 = *_active_u;
    if (((*(short *)(iVar4 + 0x2c) == 0) || (*(short *)(uVar6 + 0x2c) == *(short *)(iVar4 + 0x2c)))
       && (((*(uint *)(uVar6 + 0x28) & 0x10) == 0 && (*(int *)(iVar4 + 0x80) == 0)))) {
      *(uint *)(uVar6 + 0x28) = *(uint *)(uVar6 + 0x28) | 0x10;
      *(int *)(uVar6 + 0x7c) = *_active_u;
      *(uint *)(iVar4 + 0x80) = uVar6;
      _psignal(uVar6,(char *)0x11);
      return extraout_EAX;
    }
    goto LAB_0010b829;
  }
  if ((((*(int *)(target_task + 0x44) == 0) || (*(char *)(uVar6 + 0x13) != '\x06')) ||
      (iVar5 = *(int *)(uVar6 + 0x7c), *_active_u != iVar5)) ||
     ((*(byte *)(uVar6 + 0x28) & 0x10) == 0)) goto LAB_0010b829;
  if (iVar4 == 8) {
    *(char *)(uVar6 + 0x17) = *(char *)(uVar6 + 0x17) + ' ';
  }
  else {
    if (iVar4 < 9) {
      if (iVar4 != 7) goto LAB_0010b9d4;
    }
    else if (iVar4 != 9) {
      if (iVar4 == 0xb) {
        iVar4 = *(int *)(iVar5 + 0x80);
        if (iVar4 == 0) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
          return iVar3;
        }
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xffffffef;
        *(undefined4 *)(iVar4 + 0x7c) = 0;
        *(undefined4 *)(iVar5 + 0x80) = 0;
        goto LAB_0010b9aa;
      }
      goto LAB_0010b9d4;
    }
    iVar3 = *(int *)(target_task + 0x1c);
    iVar4 = **(int **)(iVar3 + 0x84);
    if (piVar2[2] != 1) {
      *(int *)(iVar4 + 0x38) = piVar2[2];
    }
    if (0x20 < (uint)piVar2[3]) {
LAB_0010b9d4:
      iVar3 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = 5;
      return iVar3;
    }
    if ((0x1ef8 >> (*(char *)(uVar6 + 0x17) - 1U & 0x1f) & 1U) != 0) {
      *(undefined1 *)(*(int *)(iVar3 + 0x84) + 0x78) = 0;
    }
    *(char *)(uVar6 + 0x17) = (char)piVar2[3];
    if ((0x1ef8 >> ((char)piVar2[3] - 1U & 0x1f) & 1U) != 0) {
      *(char *)(*(int *)(iVar3 + 0x84) + 0x78) = (char)piVar2[3];
    }
    if (*piVar2 == 9) {
      puVar1 = (uint *)(iVar4 + 0x40);
      *puVar1 = *puVar1 | 0x100;
    }
  }
LAB_0010b9aa:
  *(undefined1 *)(uVar6 + 0x13) = 3;
  if ((*(int *)(uVar6 + 0x6c) != 0) && (*(char *)(uVar6 + 0x17) != '\0')) {
    _clear_wait(*(int *)(uVar6 + 0x6c),2,1);
  }
  kVar7 = _task_resume(target_task);
  return kVar7;
}

