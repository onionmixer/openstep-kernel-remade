
undefined4 _ipc_entry_tree_collision(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uStack_c;
  uint uStack_8;
  
  _ipc_splay_tree_bounds(param_1 + 0x18,param_2,&uStack_8,&uStack_c);
  uVar1 = 0;
  if (((uStack_8 != 0xffffffff) && (param_2 >> 8 == uStack_8 >> 8)) ||
     ((uStack_c != 0 && (param_2 >> 8 == uStack_c >> 8)))) {
    uVar1 = 1;
  }
  return uVar1;
}
