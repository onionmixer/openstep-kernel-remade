/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f5a8 */

undefined4 FUN_0011f5a8(undefined4 param_1,char *param_2,short *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  byte local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  iVar1 = _if_private(param_1);
  uVar2 = *(undefined4 *)(iVar1 + 0xc);
  iVar1 = _strcmp(param_2,"autoaddr");
  if (iVar1 == 0) {
    if (*param_3 == 2) {
      uVar2 = _if_private(param_1);
      uVar2 = _in_bootp(param_1,param_3,uVar2);
      return uVar2;
    }
  }
  else {
    iVar1 = _strcmp(param_2,"setaddr");
    if (iVar1 == 0) {
      if (*param_3 == 2) {
        uVar3 = _splimp();
        uVar4 = _if_flags(param_1);
        _if_flags_set(param_1,uVar4 | 0x41);
        _if_init(uVar2);
        iVar1 = _if_private(param_1);
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_3 + 2);
        uVar4 = _if_flags(param_1);
        if ((uVar4 & 0x4000) == 0) {
          iVar1 = _if_private(param_1,param_3 + 2);
          uVar2 = _if_private(param_1,*(undefined4 *)(iVar1 + 8));
          _arpwhohas(param_1,uVar2);
        }
        _splx(uVar3);
        return 0;
      }
    }
    else {
      iVar1 = _strcmp(param_2,"add-multicast");
      if ((iVar1 != 0) && (iVar1 = _strcmp(param_2,"rmv-multicast"), iVar1 != 0)) {
        uVar2 = _if_control(uVar2,param_2,param_3);
        return uVar2;
      }
      if (param_3[8] == 2) {
        local_c = 1;
        local_b = 0;
        local_a = 0x5e;
        local_9 = *(byte *)((int)param_3 + 0x15) & 0x7f;
        local_8 = (undefined1)param_3[0xb];
        local_7 = *(undefined1 *)((int)param_3 + 0x17);
        uVar2 = _if_control(uVar2,param_2,&local_c);
        return uVar2;
      }
    }
  }
  return 0x2f;
}

