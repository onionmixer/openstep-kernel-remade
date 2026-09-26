/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018b080 */

undefined4 _getval(char *param_1,int *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int local_8;
  
  local_8 = 1;
  if (*param_1 == '=') {
    pcVar2 = param_1 + 1;
    if (*pcVar2 == '-') {
      local_8 = -1;
      pcVar2 = param_1 + 2;
    }
    iVar5 = *pcVar2 + -0x30;
    pbVar3 = (byte *)(pcVar2 + 1);
    uVar6 = 10;
    if (iVar5 != 0) goto LAB_0018b100;
    bVar4 = *pbVar3;
    if ('/' < (char)bVar4) {
      if ((char)bVar4 < '8') {
        iVar5 = (char)bVar4 + -0x30;
        pbVar3 = (byte *)(pcVar2 + 2);
        uVar6 = 8;
        goto LAB_0018b100;
      }
      if (bVar4 == 0x62) {
        uVar6 = 2;
        pbVar3 = (byte *)(pcVar2 + 2);
        goto LAB_0018b100;
      }
      if (bVar4 == 0x78) {
        uVar6 = 0x10;
        pbVar3 = (byte *)(pcVar2 + 2);
        goto LAB_0018b100;
      }
    }
    bVar4 = *pbVar3;
    if ((((bVar4 == 0x20) || (bVar4 == 0)) || (bVar4 == 9)) || (bVar4 == 0x2c)) {
LAB_0018b100:
      do {
        bVar4 = *pbVar3;
        pbVar3 = pbVar3 + 1;
        if ((bVar4 < 0x30) || (0x39 < bVar4)) {
          if ((byte)(bVar4 + 0x9f) < 6) {
            bVar4 = bVar4 + 0xa9;
          }
          else {
            if (5 < (byte)(bVar4 + 0xbf)) {
              if (((bVar4 == 0x20) || (bVar4 == 0)) || ((bVar4 == 9 || (bVar4 == 0x2c)))) {
                *param_2 = iVar5 * local_8;
                goto LAB_0018b175;
              }
              break;
            }
            bVar4 = bVar4 - 0x37;
          }
        }
        else {
          bVar4 = bVar4 - 0x30;
        }
        if (uVar6 <= bVar4) break;
        iVar5 = iVar5 * uVar6 + (uint)bVar4;
      } while( true );
    }
    uVar1 = 1;
  }
  else {
    *param_2 = 1;
LAB_0018b175:
    uVar1 = 0;
  }
  return uVar1;
}

