/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f30c */

int _ifconf(undefined4 param_1,uint *param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int local_3c;
  undefined4 *local_2c;
  char local_24 [14];
  char local_16 [2];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_2c = _ifnet;
  uVar3 = *param_2;
  local_3c = 0;
  uVar4 = param_2[1];
  if (0x20 < uVar3) {
    do {
      if (local_2c == (undefined4 *)0x0) break;
      _bcopy((void *)*local_2c,local_24,0xe);
      for (pcVar1 = local_24; (pcVar1 < local_16 && (*pcVar1 != '\0')); pcVar1 = pcVar1 + 1) {
      }
      *pcVar1 = *(char *)(local_2c + 2) + '0';
      pcVar1[1] = '\0';
      puVar2 = (undefined4 *)local_2c[6];
      if (puVar2 == (undefined4 *)0x0) {
        _bzero(&local_14,0x10);
        local_3c = _copyout(local_24,uVar4,0x20);
        if (local_3c != 0) break;
        uVar3 = uVar3 - 0x20;
        uVar4 = uVar4 + 0x20;
      }
      else {
        for (; (0x20 < uVar3 && (puVar2 != (undefined4 *)0x0)); puVar2 = (undefined4 *)puVar2[9]) {
          local_14 = *puVar2;
          local_10 = puVar2[1];
          local_c = puVar2[2];
          local_8 = puVar2[3];
          local_3c = _copyout(local_24,uVar4,0x20);
          if (local_3c != 0) break;
          uVar3 = uVar3 - 0x20;
          uVar4 = uVar4 + 0x20;
        }
      }
      local_2c = (undefined4 *)local_2c[0x17];
    } while (0x20 < uVar3);
  }
  *param_2 = *param_2 - uVar3;
  return local_3c;
}

