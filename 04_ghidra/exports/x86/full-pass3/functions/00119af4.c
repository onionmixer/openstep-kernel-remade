/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119af4 */

int _vfs_getnum(byte *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  do {
    if (param_1 + param_2 <= pbVar2) {
      return -1;
    }
    if (*pbVar2 != 0xff) {
      uVar1 = 0;
      do {
        if (((uint)(int)(char)*pbVar2 >> (uVar1 & 0x1f) & 1) == 0) {
          *pbVar2 = *pbVar2 | (byte)(1 << ((byte)uVar1 & 0x1f));
          return uVar1 + ((int)pbVar2 - (int)param_1) * 8;
        }
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < 8);
    }
    pbVar2 = pbVar2 + 1;
  } while( true );
}

