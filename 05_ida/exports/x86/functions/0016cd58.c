/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cd58. */
int __cdecl kern_serv_log_level(int *a1, int a2)
{
  int v2; // eax
  int v3; // ecx

  v2 = *a1; /*0x16cd61*/
  v3 = *(_DWORD *)(*a1 + 48); /*0x16cd63*/
  *(_DWORD *)(*a1 + 48) = a2; /*0x16cd66*/
  if ( v3 ) /*0x16cd6b*/
  {
    if ( a2 ) /*0x16cd86*/
      return 0; /*0x16cd86*/
  }
  else if ( a2 ) /*0x16cd6f*/
  {
    sub_16D004(v2 + 36, 500); /*0x16cd7a*/
    return 0; /*0x16cd7f*/
  }
  if ( v3 ) /*0x16cd8a*/
    sub_16D054(v2 + 36); /*0x16cd90*/
  return 0; /*0x16cd99*/
}
