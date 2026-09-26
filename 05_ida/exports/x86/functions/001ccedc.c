/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccedc. */
_DWORD *__cdecl _class_removeProtocols(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // edx

  result = a1; /*0x1ccedf*/
  if ( (_DWORD *)a1[9] == a2 ) /*0x1ccee8*/
  {
    a1[9] = *a2; /*0x1cceec*/
  }
  else
  {
    v3 = (_DWORD *)a1[9]; /*0x1ccef4*/
    result = (_DWORD *)*v3; /*0x1ccef7*/
    if ( *v3 ) /*0x1ccef7*/
    {
      while ( result != a2 ) /*0x1ccf02*/
      {
        v3 = result; /*0x1ccf0c*/
        result = (_DWORD *)*result; /*0x1ccf0e*/
        if ( !result ) /*0x1ccf12*/
          return result; /*0x1ccf12*/
      }
      result = (_DWORD *)*result; /*0x1ccf04*/
      *v3 = result; /*0x1ccf06*/
    }
  }
  return result; /*0x1ccef1*/
}
