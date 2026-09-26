
undefined4 _xdr_authkern(int *param_1)

{
  int iVar1;
  sword *psVar2;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  undefined *puStack_50;
  undefined auStack_4c [8];
  int aiStack_44 [16];
  
  psVar2 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  iStack_54 = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 2);
  iStack_58 = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 4);
  puStack_50 = _hostname;
  if (*param_1 == 0) {
    iStack_5c = 0;
    do {
      if (*psVar2 == -1) break;
      aiStack_44[iStack_5c] = (int)*psVar2;
      psVar2 = psVar2 + 1;
      iStack_5c = iStack_5c + 1;
    } while (iStack_5c < 0x10);
    _getthetime(auStack_4c);
    iVar1 = _xdr_u_long(param_1,auStack_4c);
    if ((((iVar1 != 0) && (iVar1 = _xdr_string(param_1,&puStack_50,0xff), iVar1 != 0)) &&
        (iVar1 = _xdr_int(param_1,&iStack_54), iVar1 != 0)) &&
       ((iVar1 = _xdr_int(param_1,&iStack_58), iVar1 != 0 &&
        (iVar1 = _xdr_array(param_1,aiStack_44,&iStack_5c,0x10,4,_xdr_int), iVar1 != 0)))) {
      return 1;
    }
  }
  return 0;
}
