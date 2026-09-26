
void _od_canon_label(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  sword *psStack_12;
  undefined auStack_e [2];
  undefined uStack_c;
  undefined auStack_b [2];
  undefined uStack_9;
  undefined auStack_8 [2];
  undefined uStack_6;
  
  uVar1 = _od_errmsg_filter;
  _od_errmsg_filter = 9;
  _kmem_alloc_wired(_kernel_map,&psStack_12,0x400);
  iVar2 = _od_cmd(((param_3 + -0x40c3ec8) * -0x2593f69b >> 1) << 3,2,
                  (0x4d6a - **(int **)(param_3 + 0xba)) *
                  (int)*(sword *)(*(int **)(param_3 + 0xba) + 1),psStack_12,0x400,0,0,0,0,0);
  if ((iVar2 == 0) && (*psStack_12 == -0xff)) {
    _bcopy(psStack_12 + 0x1b,auStack_e,2);
    uStack_c = 0x2f;
    _bcopy(psStack_12 + 0x1c,auStack_b,2);
    uStack_9 = 0x2f;
    _bcopy(psStack_12 + 0x1a,auStack_8,2);
    uStack_6 = 0;
    uVar3 = _od_canon_remap(param_1,param_2,param_3,1);
    _printf(aLotSSerialSDat,psStack_12 + 9,psStack_12 + 0x11,auStack_e,uVar3 & 0xffff,
            (int)(sword)(uVar3 >> 0x10));
  }
  _kmem_free(_kernel_map,psStack_12,0x400);
  _od_errmsg_filter = uVar1;
  return;
}
