
undefined4 _vnode_pager_vget(int param_1)

{
  *(sword *)(param_1 + 0xe) = *(sword *)(param_1 + 0xe) + 1;
  return *(undefined4 *)(param_1 + 0x14);
}
