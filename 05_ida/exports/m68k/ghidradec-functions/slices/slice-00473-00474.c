/* GHIDRADEC_FUNCTION index=473 start=0x4016d6e */

void _statfs(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _lookupname(*puVar1,0,1,0,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _cstatfs(*(undefined4 *)(iStack_8 + 0x24),puVar1[1]);
    _vn_rele(iStack_8);
  }
  return;
}

