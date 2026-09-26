/* GHIDRADEC_FUNCTION index=476 start=0x4016e8c */

void _unmount(void)

{
  int iVar1;
  undefined uVar3;
  int iVar2;
  int iStack_8;
  
  uVar3 = _lookupname(**(undefined4 **)(dword_40B57D4 + 0x24),0,1,0,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*(byte *)(iStack_8 + 5) & 1) == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      _vn_rele(iStack_8);
    }
    else {
      iVar1 = *(int *)(iStack_8 + 0x24);
      _vn_rele(iStack_8);
      if ((*(sword *)(iVar1 + 0x124) != *(sword *)(*(int *)(_active_u + 0x1a) + 2)) &&
         (iVar2 = _suser(), iVar2 == 0)) {
        *(undefined *)(dword_40B57D4 + 100) = 1;
        return;
      }
      _mfs_cache_clear();
      _vm_object_cache_clear();
      uVar3 = _dounmount(iVar1);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
    }
  }
  return;
}

