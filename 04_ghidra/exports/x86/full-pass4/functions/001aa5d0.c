/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa5d0 */

void FUN_001aa5d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  pbVar2 = (byte *)_nb_map(param_3);
  iVar3 = _nb_size(param_3);
  if ((*pbVar2 & 1) != 0) {
    cVar1 = _objc_msgSend(param_1,PTR_s_isUnwantedMulticastPacket__001f9b44,pbVar2);
    if (cVar1 == '\0') {
      iVar4 = _objc_msgSend(param_1,PTR_s_allocateNetbuf_001f9b70);
      if (iVar4 != 0) {
        uVar5 = _nb_map(param_3);
        _nb_write(iVar4,0,iVar3 + 0xe,uVar5);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x14c),PTR_s_handleInputPacket_extra__001f9b40,iVar4
                      ,0);
      }
    }
  }
  return;
}

