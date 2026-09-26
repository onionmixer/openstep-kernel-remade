/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa710 */

undefined4 FUN_001aa710(int param_1,undefined4 param_2,char *param_3,void *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  iVar1 = _strcmp(param_3,"setflags");
  if (iVar1 != 0) {
    iVar1 = _strcmp(param_3,"getaddr");
    if (iVar1 == 0) {
      _bcopy((void *)(param_1 + 0x150),param_4,6);
    }
    else {
      iVar1 = _strcmp(param_3,"promiscuous-on");
      if (iVar1 == 0) {
        uVar3 = 5;
      }
      else {
        iVar1 = _strcmp(param_3,"promiscuous-off");
        if (iVar1 != 0) {
          iVar1 = _strcmp(param_3,"add-multicast");
          puVar2 = PTR_s_enableMulticast__001f9b38;
          if ((iVar1 != 0) &&
             (iVar1 = _strcmp(param_3,"rmv-multicast"), puVar2 = PTR_s_disableMulticast__001f9b34,
             iVar1 != 0)) {
            return 0x16;
          }
          _objc_msgSend(param_1,puVar2,param_4);
          return 0;
        }
        uVar3 = 6;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_send__001f9b4c,uVar3);
    }
  }
  return 0;
}

