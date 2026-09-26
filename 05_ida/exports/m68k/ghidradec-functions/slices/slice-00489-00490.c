/* GHIDRADEC_FUNCTION index=489 start=0x401757e */

int _vfs_getnum(byte *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  if (param_1 < param_1 + param_2) {
    do {
      if (*pbVar2 != 0xff) {
        uVar1 = 0;
        do {
          if (((int)(char)*pbVar2 & 1 << (uVar1 & 0x1f)) == 0) {
            *pbVar2 = (byte)(1 << (uVar1 & 0x3f)) | *pbVar2;
            return uVar1 + ((int)pbVar2 - (int)param_1) * 8;
          }
          uVar1 = uVar1 + 1;
        } while ((int)uVar1 < 8);
      }
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 < param_1 + param_2);
  }
  return -1;
}

