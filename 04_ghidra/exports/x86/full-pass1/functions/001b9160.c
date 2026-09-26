/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9160 */

void FUN_001b9160(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined4 local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = _IOMalloc(0x28);
  uVar1 = DAT_001e53a4;
  local_1c = 0;
  local_24 = 0;
  _objc_msgSend(DAT_001e53a8,PTR_s_unlock_001f9474);
LAB_001b919e:
  do {
    iVar3 = 0;
    do {
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
      *(undefined4 *)(iVar2 + 4) = 0x28;
      if (iVar3 < 1) {
        iVar3 = 0;
        uVar4 = 0;
      }
      else {
        uVar4 = 0x100;
      }
      iVar3 = _msg_receive(iVar2,uVar4,iVar3);
      if (iVar3 == -0xcb) {
        _objc_msgSend(local_1c,PTR_s_control__001f975c,local_24);
        goto LAB_001b919e;
      }
      if ((iVar3 != 0) || (*(int *)(iVar2 + 0x14) != 0)) {
        _IOExitThread();
        return;
      }
      local_1c = *(undefined4 *)(iVar2 + 0x1c);
      local_24 = *(undefined4 *)(iVar2 + 0x20);
      local_14 = **(int **)(iVar2 + 0x24);
      local_10 = (*(int **)(iVar2 + 0x24))[1];
      _microtime(&local_c);
      local_14 = local_14 - local_c;
      local_10 = local_10 - local_8;
      if (local_10 < 0) {
        local_14 = local_14 + -1;
        local_10 = local_10 + 1000000;
      }
      iVar3 = local_10 / 1000 + local_14 * 1000;
    } while (0 < iVar3);
    _objc_msgSend(local_1c,PTR_s_control__001f975c,local_24);
  } while( true );
}

