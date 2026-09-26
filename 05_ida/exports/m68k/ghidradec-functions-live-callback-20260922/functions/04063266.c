
void _vnode_pager_shutdown(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4) {
    do {
      puVar2 = dword_40B4DF4;
      _vn_rele(dword_40B4DF4[2]);
      puVar1 = (undefined4 *)*puVar2;
      puVar2 = (undefined4 *)puVar2[1];
      puVar3 = puVar2;
      if ((undefined4 **)puVar1 != &dword_40B4DF4) {
        puVar1[1] = puVar2;
        puVar3 = dword_40B4DF8;
      }
      dword_40B4DF8 = puVar3;
      *puVar2 = puVar1;
      dword_40B4DFC = dword_40B4DFC + -1;
    } while ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4);
  }
  return;
}

