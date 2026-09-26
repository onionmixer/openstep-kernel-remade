
undefined4
sub_4029C74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
           undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
           undefined4 param_10,int param_11)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_30 [2];
  undefined2 uStack_2e;
  undefined *apuStack_2c [2];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined2 *)(param_1 + 2) = 0x6f;
  iVar1 = _clntkudp_create(param_1,100000,2,5,*(undefined4 *)(_active_u + 0x1a));
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aPmapRmtcallCln);
  }
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  uStack_c = param_6;
  uStack_8 = param_5;
  apuStack_2c[0] = auStack_30;
  uStack_24 = param_8;
  uStack_20 = param_7;
  uVar2 = _clntkudp_callit_addr
                    (iVar1,5,_xdr_rmtcall_args,&uStack_1c,_xdr_rmtcallres,apuStack_2c,param_9,
                     param_10,param_11);
  if (param_11 != 0) {
    *(undefined2 *)(param_11 + 2) = uStack_2e;
  }
  (**(code **)(*(int *)(iVar1 + 4) + 0x10))(iVar1);
  return uVar2;
}
