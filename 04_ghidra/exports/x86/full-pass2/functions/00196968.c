/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196968 */

undefined4 FUN_00196968(int param_1)

{
  int *piVar1;
  
  if (((*(int *)(param_1 + 0x114) == 1) || (*(int *)(param_1 + 0x114) == 3)) &&
     (*_pmsgbuf == 0x63061)) {
    piVar1 = (int *)(_pmsgbuf[1] + 0xc + (int)_pmsgbuf);
    do {
      if ((char)*piVar1 != '\0') {
        if ((char)*piVar1 == '\n') {
          _objc_msgSend(param_1,PTR_s_kmPutc__001f94a0,0xd);
        }
        _objc_msgSend(param_1,PTR_s_kmPutc__001f94a0,(int)(char)*piVar1);
      }
      piVar1 = (int *)((int)piVar1 + 1);
      if (_pmsgbuf + 0x400 <= piVar1) {
        piVar1 = _pmsgbuf + 3;
      }
    } while (piVar1 != (int *)(_pmsgbuf[1] + 0xc + (int)_pmsgbuf));
  }
  return 0;
}

