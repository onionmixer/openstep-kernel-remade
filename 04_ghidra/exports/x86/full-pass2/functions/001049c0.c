/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001049c0 */

void _free_file(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)param_1[1];
  puVar3 = puVar2;
  if ((undefined4 **)puVar1 != &_file_list) {
    puVar1[1] = puVar2;
    puVar3 = DAT_001e89dc;
  }
  DAT_001e89dc = puVar3;
  if ((undefined4 **)puVar2 != &_file_list) {
    *puVar2 = puVar1;
    puVar1 = _file_list;
  }
  _file_list = puVar1;
  _zfree(_file_zone,param_1);
  return;
}

