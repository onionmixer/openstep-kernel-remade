/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001566b0 */

void _ast_check(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  
  iVar4 = _active_threads;
  uVar5 = _splsched();
  iVar1 = *(int *)(_processor_ptr + 0x114);
  if (iVar1 != 1) {
    if (iVar1 < 2) {
      if (iVar1 != 0) {
LAB_001568b8:
                    /* WARNING: Subroutine does not return */
        _panic(s_ast_check__Bad_processor_state_001deb22);
      }
    }
    else if (3 < iVar1) goto LAB_001568b8;
    goto LAB_001568c5;
  }
  iVar1 = *_active_u;
  if ((iVar1 != 0) &&
     ((*(char *)(iVar1 + 0x17) != '\0' ||
      (((iVar4 != 0 &&
        (uVar7 = *(uint *)(iVar1 + 0x18) | *(uint *)(*(int *)(iVar4 + 0x84) + 0x7c), uVar7 != 0)) &&
       (((*(byte *)(iVar1 + 0x28) & 0x10) != 0 ||
        ((~(*(uint *)(iVar1 + 0x20) | *(uint *)(iVar1 + 0x1c)) & uVar7) != 0)))))))) {
    _need_ast = _need_ast | 0x20;
  }
  _need_ast = _need_ast | *(uint *)(iVar4 + 0x17c);
  if (_need_ast != 0) goto LAB_001568c5;
  uVar7 = 0;
  if (((*(byte *)(iVar4 + 0x4c) & 2) == 0) && (*(int *)(_processor_ptr + 0x108) < 1)) {
    iVar1 = *(int *)(_processor_ptr + 300);
    if ((*(byte *)(iVar1 + 0x168) & 2) == 0) {
      if ((*(int *)(_processor_ptr + 0x124) != 0) || (*(int *)(iVar1 + 0x108) < 1))
      goto LAB_001568c5;
      piVar8 = (int *)(iVar1 + *(int *)(iVar1 + 0x104) * 8);
      if ((int *)*piVar8 == piVar8) {
        piVar8 = (int *)(iVar1 + 0x100);
        do {
          do {
          } while (*piVar8 != 0);
          LOCK();
          iVar6 = *piVar8;
          *piVar8 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        iVar6 = *(int *)(iVar1 + 0x104);
        piVar8 = (int *)(iVar1 + iVar6 * 8);
        if (0 < *(int *)(iVar1 + 0x108)) {
          for (; (-1 < iVar6 && ((int *)*piVar8 == piVar8)); piVar8 = piVar8 + -2) {
            iVar6 = iVar6 + -1;
          }
          *(int *)(iVar1 + 0x104) = iVar6;
        }
        LOCK();
        *(undefined4 *)(iVar1 + 0x100) = 0;
        UNLOCK();
      }
      uVar7 = _need_ast;
      if (*(int *)(iVar1 + 0x104) < *(int *)(iVar4 + 0x58)) goto LAB_001568c5;
    }
    else {
      iVar6 = *(int *)(iVar1 + 0x104);
      iVar2 = *(int *)(iVar4 + 0x58);
      iVar3 = *(int *)(iVar4 + 0x60);
      if (((iVar3 == 2) || (2 < iVar3)) || (iVar3 != 1)) {
        if (((*(int *)(iVar1 + 0x108) == 0) || (iVar6 < iVar2)) ||
           ((iVar6 <= iVar2 && (*(int *)(_processor_ptr + 0x124) != 0)))) goto LAB_001567fc;
      }
      else if (((*(int *)(_processor_ptr + 0x124) != 0) || (*(int *)(iVar1 + 0x108) < 1)) ||
              (iVar6 < iVar2)) {
LAB_001567fc:
        if (*(int *)(iVar4 + 0x60) == 2) {
          *(undefined4 *)(_processor_ptr + 0x124) = 1;
        }
        goto LAB_001568c5;
      }
    }
  }
  _need_ast = uVar7;
  _need_ast = _need_ast | 4;
LAB_001568c5:
  _splx(uVar5);
  return;
}

