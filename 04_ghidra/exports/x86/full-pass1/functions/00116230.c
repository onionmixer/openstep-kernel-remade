/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116230 */

undefined2 * _sonewconn(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  if (((int)(short)param_1[0x10] + (int)(short)param_1[0xc] <= ((short)param_1[0x11] * 3) / 2) &&
     (iVar1 = _m_getclr(0,3), iVar1 != 0)) {
    puVar3 = (undefined2 *)(iVar1 + *(int *)(iVar1 + 4));
    *puVar3 = *param_1;
    puVar3[1] = param_1[1] & 0xfffd;
    puVar3[2] = param_1[2];
    puVar3[3] = param_1[3] | 1;
    *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(param_1 + 6);
    puVar3[0x2a] = param_1[0x2a];
    puVar3[0x2d] = param_1[0x2d];
    _soqinsque(param_1,puVar3,0);
    iVar2 = (**(code **)(*(int *)(puVar3 + 6) + 0x1c))(puVar3,0,0,0,0);
    if (iVar2 == 0) {
      return puVar3;
    }
    if (*(int *)(puVar3 + 8) != 0) {
      _soqremque(puVar3,0);
    }
    _m_free(iVar1);
  }
  return (undefined2 *)0x0;
}

