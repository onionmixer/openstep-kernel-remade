/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197104 */

int _kmgetc_silent(void)

{
  int iVar1;
  
  if (_kmId == 0) {
    return 0;
  }
  iVar1 = _objc_msgSend(_kmId,PTR_s_kmGetc_001f94e0);
  if (iVar1 == 0xd) {
    iVar1 = 10;
  }
  return iVar1;
}

