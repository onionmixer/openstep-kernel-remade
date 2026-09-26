/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121300 */

undefined4 _raw_attach(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = _m_getclr(0,4);
  if (iVar1 != 0) {
    iVar2 = _sbreserve(param_1 + 0x3c,0x800);
    if (iVar2 != 0) {
      iVar2 = _sbreserve(param_1 + 0x24,0x824);
      if (iVar2 != 0) {
        piVar3 = (int *)(iVar1 + *(int *)(iVar1 + 4));
        piVar3[2] = param_1;
        *(int **)(param_1 + 8) = piVar3;
        piVar3[0xc] = 0;
        *(undefined2 *)(piVar3 + 0xb) = **(undefined2 **)(*(int *)(param_1 + 0xc) + 4);
        *(undefined2 *)((int)piVar3 + 0x2e) = param_2;
        *piVar3 = (int)_rawcb;
        piVar3[1] = (int)&_rawcb;
        *(int **)((int)_rawcb + 4) = piVar3;
        _rawcb = piVar3;
        return 0;
      }
      _sbrelease(param_1 + 0x3c);
    }
    _m_free(iVar1);
  }
  return 0x37;
}

