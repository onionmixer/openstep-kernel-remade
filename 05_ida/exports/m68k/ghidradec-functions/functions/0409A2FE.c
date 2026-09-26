
void _check_for_ast(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar8 = _active_threads;
  iVar1 = *_active_u;
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x48);
  *(int *)(*(int *)(_active_threads + 0x24) + 0x48) = param_1;
  do {
    while( true ) {
      uVar9 = _need_ast;
      if (iVar1 != 0) {
        if (((*(byte *)(iVar1 + 0x29) & 0x20) != 0) && (_active_u[0x94] != 0)) {
          _addupc(*(undefined4 *)(param_1 + 0x42),_active_u + 0x8f,1);
          *(byte *)(iVar1 + 0x29) = *(byte *)(iVar1 + 0x29) & 0xdf;
        }
        _need_ast = _need_ast & 0xffffffdf;
        if (_need_ast == 0) {
          pbVar6 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
          *pbVar6 = *pbVar6 & 0xef;
        }
        *dword_40B57D4 = param_1;
        if (((*(uint *)(iVar8 + 0x177) & 0x3ffffff) >> 0x18 == 0) &&
           ((*(char *)(iVar1 + 0x17) != '\0' ||
            ((uVar7 = *(uint *)(*(int *)(iVar8 + 0x80) + 0x72) | *(uint *)(iVar1 + 0x18), uVar7 != 0
             && ((((*(byte *)(iVar1 + 0x2b) & 0x10) != 0 ||
                  ((uVar7 & ~(*(uint *)(iVar1 + 0x1c) | *(uint *)(iVar1 + 0x20))) != 0)) &&
                 (iVar10 = _issig(0), iVar10 != 0)))))))) {
          _psig();
        }
      }
      _need_ast = ~uVar9 & _need_ast;
      if (_need_ast == 0) {
        pbVar6 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar6 = *pbVar6 & 0xef;
      }
      if ((*(uint *)(iVar8 + 0x177) & 0x3ffffff) >> 0x18 == 0) break;
      _thread_halt_self();
    }
    if ((uVar9 & 4) == 0) {
      iVar10 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104);
      iVar3 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x100);
      iVar4 = *(int *)(iVar8 + 0x54);
      iVar5 = *(int *)(iVar8 + 0x5c);
      if (((*(byte *)(iVar8 + 0x4b) & 2) == 0) && (*(int *)(_processor_ptr + 0x104) < 1)) {
        if ((iVar5 == 2) || ((2 < iVar5 || (iVar5 != 1)))) {
          if ((iVar10 == 0) ||
             ((iVar3 < iVar4 || ((iVar3 <= iVar4 && (*(int *)(_processor_ptr + 0x120) != 0)))))) {
loc_409A498:
            *(undefined4 *)(*(int *)(iVar8 + 0x24) + 0x48) = uVar2;
            return;
          }
        }
        else if ((*(int *)(_processor_ptr + 0x120) != 0) || ((iVar10 < 1 || (iVar3 < iVar4))))
        goto loc_409A498;
      }
    }
    *(int *)((int)_active_u + 0x1aa) = *(int *)((int)_active_u + 0x1aa) + 1;
    _thread_block();
  } while( true );
}
