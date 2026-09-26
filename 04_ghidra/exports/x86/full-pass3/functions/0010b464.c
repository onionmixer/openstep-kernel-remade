/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b464 */

int _uname(utsname *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_28 [4];
  char local_24 [32];
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  uVar2 = _copyoutstr(s_NEXTSTEP_001dab89,*piVar1,0x20,local_28);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  uVar2 = _copyoutstr(&_hostname,*piVar1 + 0x20,0x20,local_28);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  _sprintf(local_24,&DAT_001dab92,0);
  uVar2 = _copyoutstr(local_24,*piVar1 + 0x40,0x20,local_28);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  _sprintf(local_24,&DAT_001dab95,4);
  uVar2 = _copyoutstr(local_24,*piVar1 + 0x60,0x20,local_28);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  if (DAT_001e8e08 == 5) {
    iVar3 = *piVar1 + 0x80;
    pcVar4 = s_586_AT_001dabaf;
    goto LAB_0010b5e7;
  }
  if (DAT_001e8e08 < 6) {
    if (DAT_001e8e08 == 3) {
      iVar3 = *piVar1 + 0x80;
      pcVar4 = s_386_AT_001dab98;
      goto LAB_0010b5e7;
    }
    if (DAT_001e8e08 == 4) {
      iVar3 = *piVar1 + 0x80;
      pcVar4 = s_486_AT_001dab9f;
      goto LAB_0010b5e7;
    }
  }
  else {
    if (DAT_001e8e08 == 0x84) {
      iVar3 = *piVar1 + 0x80;
      pcVar4 = s_486SX_AT_001daba6;
      goto LAB_0010b5e7;
    }
    if (DAT_001e8e08 == 0x85) {
      iVar3 = *piVar1 + 0x80;
      pcVar4 = s_586SX_AT_001dabb6;
      goto LAB_0010b5e7;
    }
  }
  iVar3 = *piVar1 + 0x80;
  pcVar4 = s_Unknown_AT_001dabbf;
LAB_0010b5e7:
  uVar2 = _copyoutstr(pcVar4,iVar3,0x20,local_28);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return iVar3;
}

