
int sub_402A1E8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = param_4;
  while( true ) {
    iVar2 = _pmap_kgetport(param_1,0x186a5,1,0x11);
    if (iVar2 == -1) {
      return 0xf;
    }
    if (iVar2 != 1) break;
    _printf(aMountnfsSSPort,param_2,param_3);
  }
  while (iVar2 = sub_4029FF0(param_1,0x186a5,1,1,_xdr_bp_path_t,&param_3,_xdr_fhstatus,&iStack_28),
        iVar2 == 5) {
    _printf(aMountnfsSSMoun,param_2,param_3);
  }
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined2 *)(param_1 + 2) = 0x801;
  *puVar1 = uStack_24;
  puVar1[1] = uStack_20;
  puVar1[2] = uStack_1c;
  puVar1[3] = uStack_18;
  puVar1[4] = uStack_14;
  puVar1[5] = uStack_10;
  puVar1[6] = uStack_c;
  puVar1[7] = uStack_8;
  return iStack_28;
}

