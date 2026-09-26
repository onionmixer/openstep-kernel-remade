/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106838 */

void _fork1(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  thread_act_t target_act;
  int iVar3;
  
  uVar1 = _alloc_posix_proc();
  iVar3 = 0;
  iVar2 = _allproc;
  if (*(short *)(_active_u[7] + 2) != 0) {
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if (*(short *)(iVar2 + 0x2c) == *(short *)(_active_u[7] + 2)) {
        iVar3 = iVar3 + 1;
      }
    }
    if (_zombproc != 0) {
      iVar2 = _zombproc;
      do {
        if (*(short *)(iVar2 + 0x2c) == *(short *)(_active_u[7] + 2)) {
          iVar3 = iVar3 + 1;
        }
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
    }
  }
  if (_freeproc == 0) {
    iVar2 = _getproc();
    if (iVar2 != 0) {
      *(int *)(iVar2 + 8) = _freeproc;
      _freeproc = iVar2;
      goto LAB_001068d3;
    }
    _tablefull(&DAT_001da864);
  }
  else {
LAB_001068d3:
    iVar2 = _freeproc;
    if ((*(short *)(_active_u[7] + 2) == 0) || (iVar3 < 0x65)) {
      iVar3 = *_active_u;
      target_act = _cloneproc(iVar3,param_1,uVar1);
      _thread_dup(_active_threads,target_act);
      *(int *)(*(int *)(target_act + 0x84) + 0x60) = (int)*(short *)(iVar3 + 0x30);
      *(undefined4 *)(*(int *)(target_act + 0x84) + 100) = 1;
      _microtime(*(int *)(*(int *)(target_act + 0xc) + 0x38) + 0x23c);
      *(undefined2 *)(*(int *)(*(int *)(target_act + 0xc) + 0x38) + 0x244) = 1;
      *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar2 + 0x30);
      _thread_resume(target_act);
      goto LAB_0010696c;
    }
  }
  _free_posix_proc(uVar1);
  *(undefined1 *)(DAT_001e875c + 0x68) = 0xb;
LAB_0010696c:
  *(undefined4 *)(DAT_001e875c + 100) = 0;
  return;
}

