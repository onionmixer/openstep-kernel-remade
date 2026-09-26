
/* WARNING: Removing unreachable block (ram,0xf000d864) */
/* WARNING: Removing unreachable block (ram,0xf000d828) */
/* WARNING: Removing unreachable block (ram,0xf000d7b0) */
/* WARNING: Removing unreachable block (ram,0xf000d798) */
/* WARNING: Removing unreachable block (ram,0xf000d7f4) */
/* WARNING: Removing unreachable block (ram,0xf000d83c) */
/* WARNING: Removing unreachable block (ram,0xf000d888) */
/* WARNING: Removing unreachable block (ram,0xf000d6ec) */

undefined8 _fork1(undefined *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined *puVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar4 = 0;
  puVar2 = param_1;
  _alloc_posix_proc();
  puVar3 = puVar2;
  if (*(sword *)(_active_u[7] + 2) != 0) {
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2c);
      iVar5 = _allproc;
      while( true ) {
        if (sVar1 == *(sword *)(_active_u[7] + 2)) {
          iVar4 = iVar4 + 1;
        }
        iVar5 = *(int *)(iVar5 + 8);
        if (iVar5 == 0) break;
        sVar1 = *(sword *)(iVar5 + 0x2c);
      }
    }
    puVar3 = DAT_f0133c00;
    if (_zombproc != 0) {
      sVar1 = *(sword *)(_zombproc + 0x2c);
      iVar5 = _zombproc;
      while( true ) {
        puVar3 = (undefined *)(int)sVar1;
        if (puVar3 == (undefined *)(int)*(sword *)(_active_u[7] + 2)) {
          iVar4 = iVar4 + 1;
        }
        iVar5 = *(int *)(iVar5 + 8);
        if (iVar5 == 0) break;
        sVar1 = *(sword *)(iVar5 + 0x2c);
      }
    }
  }
  bVar7 = false;
  puVar6 = _freeproc;
  if (_freeproc == (undefined *)0x0) {
    _getproc();
    puVar6 = puVar3;
    if (puVar3 == (undefined *)0x0) {
      _tablefull(&aProc);
      bVar7 = true;
    }
    else {
      *(undefined **)(puVar3 + 8) = _freeproc;
      bVar7 = puVar3 == (undefined *)0x0;
      _freeproc = puVar3;
    }
  }
  if ((bVar7) || ((*(sword *)(_active_u[7] + 2) != 0 && (100 < iVar4)))) {
    _free_posix_proc(puVar2);
    *(undefined *)(dword_F0133DDC + 0x38) = 0xb;
  }
  else {
    iVar5 = *_active_u;
    iVar4 = iVar5;
    _cloneproc(iVar5,param_1,puVar2);
    _thread_dup(_active_threads,iVar4);
    *(int *)(*(int *)(iVar4 + 0x84) + 0x30) = (int)*(sword *)(iVar5 + 0x30);
    *(undefined4 *)(*(int *)(iVar4 + 0x84) + 0x34) = 1;
    _microtime(*(int *)(*(int *)(iVar4 + 0xc) + 0x38) + 0x238);
    *(undefined2 *)(*(int *)(*(int *)(iVar4 + 0xc) + 0x38) + 0x240) = 1;
    *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(puVar6 + 0x30);
    _thread_resume(iVar4);
  }
  *(undefined4 *)(dword_F0133DDC + 0x34) = 0;
  return CONCAT44(param_2,param_1);
}
