/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1079b8. */
int __cdecl delete_posix_proc(int a1)
{
  int *v1; // ecx
  int v2; // edx
  char v4[80]; // [esp+8h] [ebp-50h] BYREF

  v1 = &posix_proc_hash[*(_WORD *)(a1 + 48) & 0x3F]; /*0x1079cd*/
  if ( !*v1 )
  {
LABEL_5:
    sprintf(v4, "delete_posix_proc(): no posix proc struct for pid %d", *(__int16 *)(a1 + 48));
    panic(v4); /*0x107a15*/
  }
  while ( 1 ) /*0x1079dc*/
  {
    v2 = *v1; /*0x1079dc*/
    if ( *(_DWORD *)*v1 == *(__int16 *)(a1 + 48) ) /*0x1079e4*/
      break; /*0x1079e4*/
    v1 = (int *)(v2 + 28); /*0x1079f8*/
    if ( !*(_DWORD *)(v2 + 28) ) /*0x1079fb*/
      goto LABEL_5; /*0x1079ff*/
  }
  *v1 = *(_DWORD *)(v2 + 28); /*0x1079e9*/
  return kfree(v2, 0x20u); /*0x107a1d*/
}
