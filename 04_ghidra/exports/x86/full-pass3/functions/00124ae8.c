/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124ae8 */

int FUN_00124ae8(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int local_14;
  undefined4 local_8;
  
  local_8 = 1;
  local_14 = 0;
  uVar4 = 0xffffffff;
  pcVar5 = (char *)(param_3 + 0xf4);
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0x37 < ~uVar4 - 1) {
    *(undefined1 *)(param_3 + 299) = 0;
  }
  _printf(&DAT_001dbb59,(char *)(param_3 + 0xf4));
  iVar3 = _kmioctl(0,0x80047410,&local_8,0);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar2 = *(byte *)(param_3 + 0xf2);
  if (bVar2 == 2) {
    local_14 = 1;
  }
  else {
    if (2 < bVar2) {
      if (bVar2 != 3) {
        return 0;
      }
      *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
      *(undefined1 *)(param_2 + 0x10e) = 0;
      *(undefined1 *)(param_2 + 0x10f) = 0;
      return 0;
    }
    if (bVar2 != 1) {
      return 0;
    }
  }
  pcVar5 = (char *)(param_2 + 0x110);
  FUN_00124d1c(pcVar5,pcVar5,local_14);
  if (local_14 != 0) {
    _printf(&DAT_001dbb5c);
  }
  cVar1 = *(char *)(param_2 + 0x110);
  do {
    if (cVar1 == '\0') {
LAB_00124be2:
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x14);
      *(undefined1 *)(param_2 + 0x10e) = *(undefined1 *)(param_3 + 0xf2);
      *(undefined1 *)(param_2 + 0x10f) = *(undefined1 *)(param_3 + 0xf3);
      return 0;
    }
    if ((*pcVar5 == '\n') || (*pcVar5 == '\r')) {
      *pcVar5 = '\0';
      goto LAB_00124be2;
    }
    pcVar5 = pcVar5 + 1;
    cVar1 = *pcVar5;
  } while( true );
}

