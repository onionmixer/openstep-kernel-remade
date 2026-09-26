
int _ipc_right_dnrequest
              (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uStack_c;
  uint *puStack_8;
  
  do {
    iVar2 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar4 = *puStack_8;
    if ((uVar4 & 0x70000) == 0) {
loc_404196A:
      if ((((uVar4 & 0x100000) == 0) || (param_3 == 0)) || (param_4 == 0)) {
        if ((uVar4 & 0x170000) == 0) {
          return 0x11;
        }
        return 4;
      }
      uVar1 = (uVar4 & 0xffff) + 1;
      if ((uVar1 <= (uVar4 & 0xffff)) || (0xffff < uVar1)) {
        return 0x13;
      }
      *puStack_8 = uVar4 + 1;
      _ipc_notify_dead_name(param_4,param_2);
loc_40418D8:
      uVar3 = 0;
loc_40419BC:
      *param_5 = uVar3;
      return 0;
    }
    uVar1 = puStack_8[1];
    iVar2 = _ipc_right_check(param_1,uVar1,param_2,puStack_8);
    if (iVar2 != 0) {
      if ((uVar4 & 0x400000) != 0) {
        return 0xf;
      }
      uVar4 = *puStack_8;
      goto loc_404196A;
    }
    if (param_4 == 0) {
      if (((uVar4 & 0x400000) == 0) && (puStack_8[2] != 0)) {
        uVar3 = _ipc_right_dncancel(param_1,uVar1,param_2,puStack_8);
        goto loc_40419BC;
      }
      goto loc_40418D8;
    }
    if (puStack_8[2] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = _ipc_right_dncancel(param_1,uVar1,param_2,puStack_8);
    }
    iVar2 = _ipc_port_dnrequest(uVar1,param_2,param_4,&uStack_c);
    if (iVar2 == 0) {
      puStack_8[2] = uStack_c;
      *puStack_8 = uVar4 & 0xffbfffff;
      goto loc_40419BC;
    }
    iVar2 = _ipc_port_dngrow(uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
  } while( true );
}
