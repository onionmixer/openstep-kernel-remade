/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001929e8 */

void _check_for_ast(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar5 = _active_threads;
  iVar1 = *_active_u;
LAB_00192a04:
  do {
    while( true ) {
      uVar6 = _need_ast;
      if (iVar1 != 0) {
        if (((*(byte *)(iVar1 + 0x2a) & 0x20) != 0) && (_active_u[0x97] != 0)) {
          _addupc(*(undefined4 *)(param_1 + 0x38),_active_u + 0x92,1);
          *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xffdfffff;
        }
        _need_ast = _need_ast & 0xffffffdf;
        if (((*(byte *)(iVar5 + 0x17c) & 3) == 0) &&
           ((*(char *)(iVar1 + 0x17) != '\0' ||
            ((uVar8 = *(uint *)(iVar1 + 0x18) | *(uint *)(*(int *)(iVar5 + 0x84) + 0x7c), uVar8 != 0
             && ((((*(byte *)(iVar1 + 0x28) & 0x10) != 0 ||
                  ((~(*(uint *)(iVar1 + 0x20) | *(uint *)(iVar1 + 0x1c)) & uVar8) != 0)) &&
                 (iVar7 = _issig(0), iVar7 != 0)))))))) {
          _psig();
        }
      }
      _need_ast = _need_ast & ~uVar6;
      if ((*(byte *)(iVar5 + 0x17c) & 3) == 0) break;
      _thread_halt_self();
    }
    if ((uVar6 & 4) == 0) {
      iVar7 = *(int *)(*(int *)(_processor_ptr + 300) + 0x108);
      iVar2 = *(int *)(*(int *)(_processor_ptr + 300) + 0x104);
      iVar3 = *(int *)(iVar5 + 0x58);
      iVar4 = *(int *)(iVar5 + 0x60);
      if (((*(byte *)(iVar5 + 0x4c) & 2) == 0) && (*(int *)(_processor_ptr + 0x108) < 1)) {
        if ((iVar4 == 2) || ((2 < iVar4 || (iVar4 != 1)))) {
          if (((iVar7 != 0) && (iVar3 <= iVar2)) &&
             ((iVar3 < iVar2 || (*(int *)(_processor_ptr + 0x124) == 0)))) goto LAB_00192b58;
        }
        else if ((*(int *)(_processor_ptr + 0x124) == 0) && ((0 < iVar7 && (iVar3 <= iVar2))))
        goto LAB_00192b58;
        if ((uVar6 & 0x40000000) == 0) {
          return;
        }
        _fp_ast(iVar5);
        goto LAB_00192a04;
      }
    }
LAB_00192b58:
    _active_u[0x6d] = _active_u[0x6d] + 1;
    _thread_block_with_continuation(_thread_exception_return);
  } while( true );
}

