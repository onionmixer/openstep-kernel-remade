/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1395f0. */
int __cdecl set_blocksize(int a1, __int16 a2)
{
  int result; // eax
  int (__cdecl *v3)(); // edx
  int v4; // edx
  int v5; // edx

  result = HIBYTE(a2); /*0x1395fb*/
  if ( nblkdev <= HIBYTE(a2) /*0x13961e*/
    || (result = 3 * HIBYTE(a2), (v3 = *(&off_1E2D04 + 6 * HIBYTE(a2))) == nullptr)
    || (result = v3(), result == -1) )
  {
    *(_DWORD *)(a1 + 72) = 0; /*0x139638*/
  }
  else
  {
    *(_DWORD *)(a1 + 72) = result; /*0x139620*/
    v4 = *(_DWORD *)(a1 + 60); /*0x139623*/
    if ( v4 ) /*0x139628*/
    {
      v5 = *(_DWORD *)(v4 + 48); /*0x13962a*/
      if ( !*(_DWORD *)(v5 + 72) ) /*0x13962d*/
        *(_DWORD *)(v5 + 72) = result; /*0x139633*/
    }
  }
  return result; /*0x13963f*/
}
