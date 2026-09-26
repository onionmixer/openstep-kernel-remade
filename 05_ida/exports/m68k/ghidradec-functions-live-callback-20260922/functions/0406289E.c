
undefined4 _vnode_pager_findpage(undefined4 *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  if ((param_1 != (undefined4 *)0x0) ||
     (param_1 = dword_40B4DF4, puVar2 = dword_40B4DF4,
     (undefined4 **)dword_40B4DF4 != &dword_40B4DF4)) {
    do {
      iVar1 = _vnode_pager_allocpage(param_1);
      if (iVar1 != -1) {
        *param_2 = *(undefined *)((int)param_1 + 0x33);
        *(uint *)(param_2 + 1) = *(uint *)(param_2 + 1) & 0xff | iVar1 << 8;
        return 0;
      }
      param_1 = (undefined4 *)*param_1;
    } while (param_1 != puVar2);
  }
  return 5;
}

