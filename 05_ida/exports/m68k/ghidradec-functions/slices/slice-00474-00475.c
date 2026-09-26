/* GHIDRADEC_FUNCTION index=474 start=0x4016dd0 */

void _fstatfs(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _getvnodefp(*puVar1,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _cstatfs(*(undefined4 *)(*(int *)(iStack_8 + 0x16) + 0x24),puVar1[1]);
  }
  return;
}

