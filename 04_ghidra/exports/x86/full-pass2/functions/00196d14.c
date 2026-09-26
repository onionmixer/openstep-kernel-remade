/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196d14 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _kmopen(short param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  if ((char)param_1 == '\0') {
    iVar1 = _objc_msgSend(_kmId,PTR_s_kmOpen__001f94c0,param_2);
    if (iVar1 == 0) {
      _DAT_001e9804 = 0;
      _DAT_001e97f4 = FUN_00197134;
      DAT_001e9817 = '\x02';
      if ((DAT_001e9810 & 4) == 0) {
        _ttychars(&_cons);
        _DAT_001e980c = 0x140700d8;
        DAT_001e981d = 0x7f;
        DAT_001e981a = 0xd;
        DAT_001e9819 = 0xd;
        DAT_001e9810 = 0x10;
      }
      else if (((char)DAT_001e9810 < '\0') && (*(short *)(*(int *)(_active_u + 0x1c) + 2) != 0)) {
        _DAT_001e9804 = 0;
        DAT_001e9817 = 2;
        return 0x10;
      }
      iVar1 = (*(code *)(&_linesw)[DAT_001e9817 * 0xc])((int)param_1,&_cons);
      if (iVar1 == 0) {
        _objc_msgSend(_kmId,PTR_s_getScreenSize__001f94c4,&local_c);
        DAT_001e982c = local_c;
        DAT_001e982e = local_a;
        DAT_001e9830 = local_8;
        DAT_001e9832 = local_6;
      }
    }
  }
  else {
    iVar1 = 6;
  }
  return iVar1;
}

