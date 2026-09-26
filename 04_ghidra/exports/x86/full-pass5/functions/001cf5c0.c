/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf5c0 */

void FUN_001cf5c0(undefined4 param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_10;
  uint local_8;
  
  iVar3 = _getsectdatafromheaderinfo(param_1,"__OBJC","__protocol",&local_8);
  if (iVar3 != 0) {
    for (local_10 = 0; local_10 < local_8 / 0x14; local_10 = local_10 + 1) {
      if (*(int *)(iVar3 + 0xc + local_10 * 0x14) != 0) {
        puVar2 = *(uint **)(iVar3 + 0xc + local_10 * 0x14);
        uVar5 = 0;
        if (*puVar2 != 0) {
          do {
            puVar1 = puVar2 + uVar5 * 2 + 1;
            uVar4 = __sel_registerName(*puVar1);
            if (*puVar1 != uVar4) {
              *puVar1 = uVar4;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *puVar2);
        }
      }
      if (*(int *)(iVar3 + 0x10 + local_10 * 0x14) != 0) {
        puVar2 = *(uint **)(iVar3 + 0x10 + local_10 * 0x14);
        uVar5 = 0;
        if (*puVar2 != 0) {
          do {
            puVar1 = puVar2 + uVar5 * 2 + 1;
            uVar4 = __sel_registerName(*puVar1);
            if (*puVar1 != uVar4) {
              *puVar1 = uVar4;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *puVar2);
        }
      }
    }
    _objc_msgSend(PTR_s_Protocol_001f9de0,PTR_s__fixup_numElements__001f9cf4,iVar3,local_8 / 0x14);
  }
  return;
}

