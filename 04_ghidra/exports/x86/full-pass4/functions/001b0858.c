/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0858 */

void FUN_001b0858(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  uint local_208;
  undefined1 local_204 [512];
  
  uVar5 = 0x200;
  puVar2 = local_204;
  local_208 = 0;
  iVar4 = 0;
  do {
    while( true ) {
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0x148);
      *(uint *)(puVar2 + 4) = uVar5;
      iVar1 = _msg_receive(puVar2,0x1000,0);
      if (iVar1 == -0xca) {
        _IOExitThread();
        return;
      }
      if (-0xca < iVar1) break;
      if (iVar1 == -0xcc) {
        if (0x200 < uVar5) {
          _IOFree(puVar2,uVar5);
        }
        uVar5 = *(uint *)(puVar2 + 4);
        puVar2 = (undefined1 *)_IOMalloc(uVar5);
      }
      else {
LAB_001b08e4:
        uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
        _IOLog("%s: error on msg_receive (%d)\n",uVar3);
      }
    }
    if (iVar1 != 0) goto LAB_001b08e4;
    if (*(int *)(param_1 + 0x13c) == *(int *)(puVar2 + 0xc)) {
      if ((*(int *)(param_1 + 0x144) == *(int *)(puVar2 + 0x1c)) && (*(int *)(puVar2 + 0x1c) != 0))
      {
        _objc_msgSend(param_1,PTR_s_evClose_token__001f9a44,*(undefined4 *)(param_1 + 0x134),
                      *(undefined4 *)(param_1 + 0x114));
      }
    }
    else {
      iVar1 = 0;
      if (*(int *)(puVar2 + 0x14) == 1) {
        if (*(int *)(param_1 + 0x134) == *(int *)(puVar2 + 0xc)) {
          _objc_msgSend(param_1,PTR_s__ioOpHandler__001f99b8,puVar2 + 0x1c);
          iVar1 = 1;
        }
      }
      else {
        if (iVar4 == 0) {
          local_208 = 0x1400;
          iVar4 = _IOMalloc(0x1400);
        }
        iVar1 = _Event_server(puVar2,iVar4);
      }
      if (iVar1 == 0) {
        uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined4 *)(puVar2 + 0x14));
        pcVar6 = "%s: invalid message ID %d\n";
LAB_001b0a51:
        _IOLog(pcVar6,uVar3);
LAB_001b0a59:
        if (iVar4 != 0) {
          _IOFree(iVar4,local_208);
          iVar4 = 0;
          local_208 = 0;
        }
      }
      else {
        if (*(int *)(puVar2 + 0x10) == 0) goto LAB_001b0a59;
        if (iVar4 != 0) {
          if (local_208 < *(uint *)(iVar4 + 4)) {
            uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(uint *)(iVar4 + 4),local_208);
            _IOLog("%s: reply msg overflow (%d > %d)\n",uVar3);
          }
          iVar1 = _msg_send(iVar4,0,0);
          if (iVar1 != 0) {
            uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
            pcVar6 = "%s: error on msg_send (%d)\n";
            goto LAB_001b0a51;
          }
          goto LAB_001b0a59;
        }
      }
      if (0x200 < uVar5) {
        _IOFree(puVar2,uVar5);
        uVar5 = 0x200;
        puVar2 = local_204;
      }
    }
  } while( true );
}

