/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179764. */
__int32 __cdecl vm_object_remove(int a1)
{
  __int32 result; // eax
  _DWORD *v2; // ebx
  _DWORD *v3; // ecx
  _DWORD *v4; // edx
  _DWORD *v5; // eax

  result = 8 * (a1 & 0x7F); /*0x179771*/
  v2 = (int *)((char *)vm_object_hashtable + result); /*0x179774*/
  v3 = *(_DWORD **)((char *)vm_object_hashtable + result); /*0x17977a*/
  if ( (int *)((char *)vm_object_hashtable + result) != v3 ) /*0x179782*/
  {
    while ( 1 ) /*0x179784*/
    {
      result = v3[2]; /*0x179784*/
      if ( *(_DWORD *)(result + 40) == a1 ) /*0x17978a*/
        break; /*0x17978a*/
      v3 = (_DWORD *)*v3; /*0x1797b8*/
      if ( v2 == v3 ) /*0x1797bc*/
        return result; /*0x1797bc*/
    }
    v4 = (_DWORD *)*v3; /*0x17978c*/
    v5 = (_DWORD *)v3[1]; /*0x17978e*/
    if ( v2 == (_DWORD *)*v3 ) /*0x179793*/
      v2[1] = v5; /*0x179795*/
    else
      v4[1] = v5; /*0x17979c*/
    if ( v2 == v5 ) /*0x1797a1*/
      *v2 = v4; /*0x1797b4*/
    else
      *v5 = v4; /*0x1797a3*/
    return zfree(object_hash_zone, v3); /*0x1797ad*/
  }
  return result; /*0x1797c1*/
}
