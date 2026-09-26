/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8938 */

uint FUN_001c8938(char *param_1,byte *param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *param_1;
  if (cVar1 == '*') {
LAB_001c8968:
    if (param_2 == (byte *)0x0) {
      return 0;
    }
    uVar2 = 0;
    for (; *param_2 != 0; param_2 = param_2 + 4) {
      uVar2 = uVar2 ^ *param_2;
      if (param_2[1] == 0) break;
      uVar2 = uVar2 ^ (uint)param_2[1] << 8;
      if (param_2[2] == 0) break;
      uVar2 = uVar2 ^ (uint)param_2[2] << 0x10;
      if (param_2[3] == 0) break;
      uVar2 = uVar2 ^ (uint)param_2[3] << 0x18;
    }
  }
  else {
    if (cVar1 < '+') {
      if (cVar1 == '%') goto LAB_001c8968;
    }
    else if (cVar1 == '@') {
      uVar2 = _objc_msgSend(param_2,PTR_s_hash_001f9d60);
      goto LAB_001c89b7;
    }
    uVar2 = (uint)param_2 >> 0x10 ^ (uint)param_2;
  }
LAB_001c89b7:
  return uVar2 % param_3;
}

