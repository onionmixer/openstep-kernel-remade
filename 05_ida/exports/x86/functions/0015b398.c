/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b398. */
int __cdecl stack_alloc_try(int a1, int a2)
{
  int *v2; // edx
  int *v3; // ebx
  int *v4; // ebx
  int *v5; // eax

  lock_write((int)&stack_queue_lock); /*0x15b3a8*/
  if ( dword_1DED68 ) /*0x15b3b7*/
  {
    v2 = (int *)dword_1E5B98; /*0x15b3b9*/
    if ( (int *)dword_1E5B98 == &dword_1E5B98 ) /*0x15b3c5*/
    {
      v3 = nullptr; /*0x15b3c7*/
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)dword_1E5B98 + 4) = &dword_1E5B98; /*0x15b3ce*/
      dword_1E5B98 = *v2; /*0x15b3d7*/
      v3 = v2; /*0x15b3dd*/
    }
    v3[2] = 2; /*0x15b3df*/
    v4 = v3 + 3; /*0x15b3e6*/
    --dword_1DED68; /*0x15b3e9*/
    --dword_1F63B8; /*0x15b3ef*/
    ++dword_1F63B4; /*0x15b3f5*/
  }
  else
  {
    v4 = nullptr; /*0x15b400*/
  }
  lock_done(&stack_queue_lock); /*0x15b407*/
  v5 = v4; /*0x15b40f*/
  if ( !v4 ) /*0x15b413*/
  {
    v5 = *(int **)(a1 + 48); /*0x15b415*/
    if ( !v5 ) /*0x15b41a*/
      return 0; /*0x15b430*/
  }
  stack_attach(a1, v5, a2); /*0x15b422*/
  return 1; /*0x15b435*/
}
