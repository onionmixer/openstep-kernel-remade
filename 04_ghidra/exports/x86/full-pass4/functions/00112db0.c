/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00112db0 */

/* WARNING: Removing unreachable block (ram,0x00112e00) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _getc(FILE *param_1)

{
  byte *pbVar1;
  uchar *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar4 = _spltty();
  if ((int)param_1->_p < 1) {
    uVar7 = 0xffffffff;
    param_1->_p = (uchar *)0x0;
    param_1->_w = 0;
    param_1->_r = 0;
  }
  else {
    pbVar1 = (byte *)param_1->_r;
    uVar7 = (uint)*pbVar1;
    iVar5 = (int)((uint)pbVar1 & 0x3f) >> 3;
    if (((uint)(int)*(char *)(((uint)pbVar1 & 0xffffffc0) + 4 + iVar5) >>
         (((uint)pbVar1 & 0x3f) + iVar5 * -8 & 0x1f) & 1) != 0) {
      uVar7 = uVar7 | 0x100;
    }
    param_1->_r = (int)(pbVar1 + 1);
    puVar2 = param_1->_p;
    param_1->_p = puVar2 + -1;
    if (puVar2 == (uchar *)0x1 || (int)(puVar2 + -1) < 0) {
      puVar6 = (undefined4 *)(param_1->_r - 1U & 0xffffffc0);
      param_1->_r = 0;
      param_1->_w = 0;
      *puVar6 = _cfreelist;
    }
    else {
      uVar3 = param_1->_r;
      if ((uVar3 & 0x3f) != 0) goto LAB_00112e95;
      param_1->_r = *(int *)(uVar3 - 0x40) + 0xc;
      *(undefined4 **)(uVar3 - 0x40) = _cfreelist;
      puVar6 = (undefined4 *)(uVar3 - 0x40);
    }
    __cfreecount = __cfreecount + 0x34;
    _cfreelist = puVar6;
    if (_cwaiting != '\0') {
      _wakeup(&_cwaiting);
      _cwaiting = '\0';
    }
  }
LAB_00112e95:
  _splx(uVar4);
  return uVar7;
}

