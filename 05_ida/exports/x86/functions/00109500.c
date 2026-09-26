/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109500. */
int sigstack()
{
  _DWORD *v0; // ebx
  int v1; // edx
  int result; // eax
  int v3; // edx
  _DWORD v4[2]; // [esp+4h] [ebp-8h] BYREF

  v0 = *(_DWORD **)(dword_1E875C + 36); /*0x10950d*/
  v1 = v0[1]; /*0x109510*/
  if ( !v1 || (result = copyout(active_u + 328, v1, 8), (*(_BYTE *)(dword_1E875C + 104) = result) == 0) ) /*0x10953e*/
  {
    if ( *v0 ) /*0x109544*/
    {
      result = copyin(*v0, v4, 8); /*0x109551*/
      *(_BYTE *)(dword_1E875C + 104) = result; /*0x10955c*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x109565*/
      {
        v3 = active_u; /*0x10956b*/
        result = v4[1]; /*0x109574*/
        *(_DWORD *)(active_u + 328) = v4[0]; /*0x109577*/
        *(_DWORD *)(v3 + 332) = result; /*0x10957d*/
      }
    }
  }
  return result; /*0x109583*/
}
