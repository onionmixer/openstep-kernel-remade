
bool _vnode_has_page(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_8 [4];
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVnodeHasPageFa);
  }
  if (*(char *)(param_1 + 0xc) < '\0') {
    iVar1 = sub_4062AD4(param_1,param_2,1,auStack_8);
    return iVar1 != 5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVnodeHasPageCa);
}
