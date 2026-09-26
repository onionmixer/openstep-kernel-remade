/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001207bc */

undefined4 _nullsap_input(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)_nb_map(param_3);
  uVar2 = _nb_size(param_3);
  if (((uVar2 < 3) || (*pcVar1 != '\0')) || ((*(byte *)(param_4 + 1) & 0xc0) != 0x40)) {
    return 0x2f;
  }
  if (((pcVar1[2] & 0xefU) == 0xaf) && ((pcVar1[1] & 1U) == 0)) {
    iVar3 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar3 + 1);
    _bcopy((void *)(param_4 + 8),(void *)(param_4 + 2),6);
    *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) & 0x7f;
    if (*(char *)(param_4 + 8) < '\0') {
      *(byte *)(param_4 + 0xf) =
           *(byte *)(param_4 + 0xf) & 0x7f | ~(*(byte *)(param_4 + 0xf) >> 7) << 7;
      *(byte *)(param_4 + 0xe) = *(byte *)(param_4 + 0xe) & 0x1f;
    }
    FUN_00120950(pcVar1);
    if ((pcVar1[3] == -0x7f) && (uVar2 = _nb_size(param_3), 5 < uVar2)) {
      pcVar1[4] = '\x01';
      pcVar1[5] = '\0';
    }
    iVar3 = FUN_00120968(param_2,param_3,param_4);
  }
  else {
    if ((pcVar1[2] & 0xefU) != 0xe3) {
      return 0x2f;
    }
    if ((pcVar1[1] & 1U) != 0) {
      return 0x2f;
    }
    iVar3 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar3 + 1);
    _bcopy((void *)(param_4 + 8),(void *)(param_4 + 2),6);
    *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) & 0x7f;
    if (*(char *)(param_4 + 8) < '\0') {
      *(byte *)(param_4 + 0xf) =
           *(byte *)(param_4 + 0xf) & 0x7f | ~(*(byte *)(param_4 + 0xf) >> 7) << 7;
      *(byte *)(param_4 + 0xe) = *(byte *)(param_4 + 0xe) & 0x1f;
    }
    FUN_00120950(pcVar1);
    iVar3 = FUN_00120968(param_2,param_3,param_4);
  }
  if (iVar3 == 0) {
    iVar3 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar3 + 1);
  }
  else {
    iVar3 = _if_oerrors(param_1);
    _if_oerrors_set(param_1,iVar3 + 1);
  }
  return 0;
}

