/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17facc. */
_BOOL4 __cdecl KernBusInterruptDispatch(_DWORD *a1, int a2)
{
  int *v2; // edi
  int v3; // ebx
  int v4; // eax
  bool v5; // bl
  int v7; // [esp-8h] [ebp-18h]
  void (__cdecl *v8)(int, int); // [esp+Ch] [ebp-4h]

  v8 = (void (__cdecl *)(int, int))a1[10]; /*0x17fadb*/
  KernLockAcquire(a1[7]); /*0x17fae2*/
  v2 = *(int **)(a1[5] + 4); /*0x17faea*/
  v3 = a1[6]; /*0x17faed*/
  while ( 1 ) /*0x17fb0a*/
  {
    v4 = v3--; /*0x17fb0a*/
    if ( v4 <= 0 ) /*0x17fb0f*/
      break; /*0x17fb0f*/
    v7 = *v2++; /*0x17fafe*/
    v8(v7, a2); /*0x17fb05*/
  }
  KernLockAcquire(a1[9]); /*0x17fb15*/
  v5 = 0; /*0x17fb1a*/
  if ( (int)a1[6] > 0 ) /*0x17fb23*/
    v5 = a1[8] == 0; /*0x17fb2b*/
  KernLockRelease(a1[9]); /*0x17fb31*/
  KernLockRelease(a1[7]); /*0x17fb3a*/
  return v5; /*0x17fb45*/
}
